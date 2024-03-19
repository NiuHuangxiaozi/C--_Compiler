//
// Created by hbd on 2023/4/14.
//

#include "translate.h"
#include "symbolTable.h"
#include <stdlib.h>
#define new(T) (struct T *)malloc(sizeof(struct T))

int v_cnt = 1;
int l_cnt = 1;

int able_to_translate = 1;
int defining_param = 0;
int first_definition = 0;
int writing = 0;

static struct GlobalSymbol* all_symbols;

struct GlobalSymbol* insert_symbol(const char* name) {
	struct GlobalSymbol* symbol = new(GlobalSymbol);
	symbol->alias = (v_cnt++);
	if (name != NULL) {
		symbol->name = (char *) malloc(strlen(name) + 1);
		strcpy(symbol->name, name);
	} else {
		int len = 0, base = 1;
		for (int start = symbol->alias; start != 0; start /= 10)
			len++, base *= 10;
		base /= 10;
		symbol->name = (char *) malloc(len + 1 + 1);
		symbol->name[0] = 'v';
        int i = 0;
		for (int start = symbol->alias; i < len; ++i, start %= base, base /= 10)
			symbol->name[i + 1] = (char)('0' + start / base);
        symbol->name[i + 1] = '\0';
        symbol->type = new(PlainType);
        symbol->type->kind = BASIC;
	}
	symbol->next = all_symbols;
	all_symbols = symbol;
	return symbol;
}

void translate_Program(TreeNode * root, char* filename) {
	init_ir_list();
	if (root == NULL)
		return;
	translate_ExtDefList((TreeNode*)root->child[0]);
    if (able_to_translate) {
        FILE *dest = fopen(filename, "w");
        output_all_ir(dest);
    }
    else {
        printf("Cannot translate: Code contains variables or parameters of structure type.\n");
    }
}

void translate_ExtDefList(TreeNode *root) {
	if (root->child_num == 0)
		return;
	translate_ExtDef((TreeNode *) root->child[0]);
	translate_ExtDefList((TreeNode *) root->child[1]);
}

void translate_ExtDef(TreeNode *root) {
	if (strcmp(((TreeNode *) root->child[1])->name, "FunDec") == 0) {
		translate_FunDec((TreeNode *) root->child[1]);
		translate_CompSt((TreeNode *) root->child[2]);
	}
}

void translate_ExtDecList(TreeNode *root) {

}

void translate_Specifier(TreeNode *root, struct PlainType* plain_type) {
	char* name = ((TreeNode *)root->child[0])->name;
	if (strcmp(name, "StructSpecifier") == 0) {
		able_to_translate = 0;
		//printf("Can't translate\n");
	} else {
		translate_TYPE((TreeNode *)root->child[0], plain_type);
	}
}

void translate_StructSpecifier(TreeNode * root) {

}

void translate_OptTag(TreeNode* root) {

}

void translate_Tag(TreeNode* root) {

}

void translate_VarDec(TreeNode *root, struct PlainType* plain_type) {
	if (root->child_num == 1)
		translate_ID((TreeNode *)root->child[0], plain_type);
	else {
		if (plain_type->kind != ARRAY && plain_type->kind != ADDR) {
			if (defining_param) {
                plain_type->kind = ADDR;
            } else
                plain_type->kind = ARRAY;
			plain_type->info.array.data_type = plain_type->info.basic;
		}
		struct Location* head = new(Location);
		head->next = plain_type->info.array.width;
		plain_type->info.array.width = head;
		//plain_type->info.array.data_type = plain_type->info.basic;
		plain_type->info.array.width->offset = ((TreeNode *)root->child[2])->value.i;
		translate_VarDec((TreeNode *) root->child[0], plain_type);
	}
}

void translate_FunDec(TreeNode *root) {
	struct IR* ir = new(IR);
	ir->kind = FUNC_T;
	ir->info.id = ((TreeNode*)root->child[0])->value.s;
	insert_ir(ir);
	if (root->child_num == 4) {
		defining_param = 1;
		first_definition = 1;
		translate_VarList((TreeNode *) root->child[2]);
		first_definition = 0;
		defining_param = 0;
	}
}

void translate_VarList(TreeNode * root) {
	translate_ParamDec((TreeNode *)root->child[0]);
	if (root->child_num == 3)
		translate_VarList((TreeNode *)root->child[2]);
}

void translate_ParamDec(TreeNode *root) {
	struct PlainType* plain_type = new(PlainType);
	plain_type->info.array.width = NULL;
	translate_Specifier((TreeNode *)root->child[0], plain_type);
	translate_VarDec((TreeNode *)root->child[1], plain_type);
}

void translate_CompSt(TreeNode *root) {
	translate_DefList((TreeNode *)root->child[1]);
	translate_StmtList((TreeNode *)root->child[2]);
}

void translate_StmtList(TreeNode *root) {
	if (root->child_num == 0)
		return;
	translate_Stmt((TreeNode *)root->child[0]);
	translate_StmtList((TreeNode *)root->child[1]);
}

void translate_Stmt(TreeNode * root) {
    char* name = ((TreeNode *)root->child[0])->name;
	if (root->child_num == 1) {
		translate_CompSt((TreeNode *)root->child[0]);
	} else if (root->child_num == 2) {
		struct PlainType* plain_type = new(PlainType);
		plain_type->info.array.width = NULL;
		translate_Exp((TreeNode *)root->child[0], plain_type, NULL);
	} else if (root->child_num == 3) {
		// TODO: RETURN
		struct GlobalSymbol* symbol = insert_symbol(NULL);
		symbol = translate_Exp((TreeNode *)root->child[1], NULL, symbol);

        if (symbol->type->kind == ADDR) {
            struct GlobalSymbol* temp = insert_symbol(NULL);
            struct IR* ir = new(IR);
            ir->kind = GET_VAL_T;
            ir->info.unaryop.op1.val.var_no = symbol->alias;
            ir->info.unaryop.op1.kind = ADDRESS;
            ir->info.unaryop.result.kind = VARIABLE;
            ir->info.unaryop.result.val.var_no = temp->alias;
            insert_ir(ir);
            symbol = temp;
        }

		struct IR* ir = new(IR);
		ir->kind = RETURN_T;
		ir->info.var_no = symbol->alias;
		insert_ir(ir);
	} else if (root->child_num == 5 && strcmp(name, "IF") == 0) {
		// TODO: IF
		int label = (l_cnt++);
		struct GlobalSymbol* symbol = insert_symbol(NULL);
		symbol = translate_Exp((TreeNode *)root->child[2], NULL, symbol);
		struct IR* test = new(IR);
		test->kind = JMPC_T;
		test->info.jumpc.cond = symbol->alias;
		test->info.jumpc.expect = 0;
		test->info.jumpc.label = label;
        test->info.jumpc.operator = 4;
		insert_ir(test);
		translate_Stmt((TreeNode*)root->child[4]);
		struct IR* target = new(IR);
		target->kind = LABEL_T;
		target->info.label_no = label;
		insert_ir(target);
	} else if (root->child_num == 7) {
		// TODO: IF ELSE
		int label = (l_cnt++);
		struct GlobalSymbol* symbol = insert_symbol(NULL);
		symbol = translate_Exp((TreeNode *)root->child[2], NULL, symbol);

		struct IR* test = new(IR);
		test->kind = JMPC_T;
		test->info.jumpc.cond = symbol->alias;
		test->info.jumpc.expect = 0;
		test->info.jumpc.label = label;
        test->info.jumpc.operator = 4;
		insert_ir(test);

		translate_Stmt((TreeNode*)root->child[4]);

        int out_label = l_cnt++;

        struct IR* end = new(IR);
        end->kind = JMP_T;
        end->info.jump.label = out_label;
        insert_ir(end);

		struct IR* target = new(IR);
		target->kind = LABEL_T;
		target->info.label_no = label;
		insert_ir(target);

		translate_Stmt((TreeNode *)root->child[6]);

        struct IR* out = new(IR);
        out->kind = LABEL_T;
        out->info.label_no = out_label;
        insert_ir(out);
	} else if (root->child_num == 5) {
		// TODO: WHILE
		int start_label = (l_cnt++);
		struct IR* start = new(IR);
		start->kind = LABEL_T;
		start->info.label_no = start_label;
		insert_ir(start);

		int out_label = (l_cnt++);

		struct GlobalSymbol* symbol = insert_symbol(NULL);
		symbol = translate_Exp((TreeNode *)root->child[2], NULL, symbol);
		struct IR* test = new(IR);
		test->kind = JMPC_T;
		test->info.jumpc.cond = symbol->alias;
		test->info.jumpc.expect = 0;
		test->info.jumpc.label = out_label;
        test->info.jumpc.operator = 4;
		insert_ir(test);

		translate_Stmt((TreeNode *)root->child[4]);

		struct IR* force_to = new(IR);
		force_to->kind = JMP_T;
		force_to->info.jump.label = start_label;
		insert_ir(force_to);

		struct IR* out = new(IR);
		out->kind = LABEL_T;
		out->info.jump.label = out_label;
		insert_ir(out);
	}
}

void translate_Cond(TreeNode * root) {

}

void translate_DefList(TreeNode *root) {
	if (root->child_num == 0)
		return;
	translate_Def((TreeNode *)root->child[0]);
	translate_DefList((TreeNode *)root->child[1]);
}

void translate_Def(TreeNode * root) {
	struct PlainType* plain_type = new(PlainType);
	translate_Specifier((TreeNode*)root->child[0], plain_type);
	translate_DecList((TreeNode *)root->child[1], plain_type);
}

void translate_DecList(TreeNode *root, struct PlainType* plain_type) {
	struct PlainType* new_type = new(PlainType);
	new_type->info.basic = plain_type->info.basic;
	new_type->info.array.width = NULL;
	translate_Dec((TreeNode *)root->child[0], new_type);
	if (root->child_num > 1)
		translate_DecList((TreeNode *)root->child[2], plain_type);
}

void translate_Dec(TreeNode *root, struct PlainType* plain_type) {
	first_definition = 1;
	translate_VarDec((TreeNode *)root->child[0], plain_type);
    struct GlobalSymbol* left = all_symbols;
	if (root->child_num == 1) {
		struct GlobalSymbol* cur = all_symbols;
		if (plain_type->kind == ARRAY) { // Create space
			int size = 4;
			struct Location* loc = plain_type->info.array.width;
			while (loc) {
				size *= loc->offset;
				loc = loc->next;
			}
			struct IR* ir = new(IR);
			ir->kind = DEC_T;
			ir->info.dec.size = size;
            ir->info.dec.target = cur->alias;
			insert_ir(ir);
			/*
			struct Location* suffix = new(Location);
			suffix->offset = 1;
			suffix->next = plain_type->info.array.list;
			plain_type->info.array.list = suffix;
			 */
		}
	}
	first_definition = 0;
	if (root->child_num == 3) {// TODO: Procedure for Array-Assign
		int left_seq = all_symbols->alias;
		struct GlobalSymbol* right = insert_symbol(NULL);
		int right_seq = right->alias;
		right = translate_Exp((TreeNode *)root->child[2], plain_type, right);


        if (right->type->kind == BASIC) {
            struct IR *ir = new(IR);
            ir->kind = ASSIGN_T;
            ir->info.assign.right.kind = VARIABLE;
            ir->info.assign.right.val.var_no = right_seq;
            ir->info.assign.left.kind = VARIABLE;
            ir->info.assign.left.val.var_no = left_seq;
            insert_ir(ir);
        } else if (left->type->kind == BASIC) {
            struct GlobalSymbol* temp = insert_symbol(NULL);
            struct IR* ir1 = new(IR);
            ir1->kind = GET_VAL_T;
            ir1->info.unaryop.op1.val.var_no = right->alias;
            ir1->info.unaryop.op1.kind = ADDRESS;
            ir1->info.unaryop.result.kind = VARIABLE;
            ir1->info.unaryop.result.val.var_no = temp->alias;
            insert_ir(ir1);
            right = temp;

            struct IR* ir2 = new(IR);
            ir2->kind = ASSIGN_T;
            ir2->info.assign.left.kind = VARIABLE;
            ir2->info.assign.left.val.var_no = left->alias;
            ir2->info.assign.right.kind = VARIABLE;
            ir2->info.assign.right.val.var_no = right->alias;
            insert_ir(ir2);
        } else {
            // struct GlobalSymbol* left = all_symbols;
            int total = 1;
            struct Location* cur = right->type->info.array.width;
            while (cur) {
                total *= cur->offset;
                cur = cur->next;
            }
            for (int i = 0; i < total; ++i) {
                struct IR *get_right_addr = new(IR);
                get_right_addr->kind = GET_ADDR_T;
                get_right_addr->info.binop.op1.kind = ADDRESS;
                get_right_addr->info.binop.op1.val.var_no = right->alias;
                get_right_addr->info.binop.op1.need_get_addr = (right->type->kind == ARRAY) ? 1 : 0;
                get_right_addr->info.binop.op2.kind = CONSTANT;
                get_right_addr->info.binop.op2.val.value = i * 4;
                struct GlobalSymbol* hold_right = insert_symbol(NULL);
                hold_right->type->kind = ADDR;
                get_right_addr->info.binop.result.kind = ADDRESS;
                get_right_addr->info.binop.result.val.var_no = hold_right->alias;
                hold_right->type->info.array.width = right->type->info.array.width? right->type->info.array.width->next: NULL;
                insert_ir(get_right_addr);

                struct IR *get_right_value = new(IR);
                struct GlobalSymbol * temp = insert_symbol(NULL);
                get_right_value->kind = GET_VAL_T;
                get_right_value->info.unaryop.op1.val.var_no = hold_right->alias;
                get_right_value->info.unaryop.op1.kind = ADDRESS;
                get_right_value->info.unaryop.result.kind = VARIABLE;
                get_right_value->info.unaryop.result.val.var_no = temp->alias;
                insert_ir(get_right_value);


                struct IR *get_left_addr = new(IR);
                get_left_addr->kind = GET_ADDR_T;
                get_left_addr->info.binop.op1.kind = ADDRESS;
                get_left_addr->info.binop.op1.val.var_no = left->alias;
                get_left_addr->info.binop.op1.need_get_addr = (left->type->kind == ARRAY) ? 1 : 0;
                get_left_addr->info.binop.op2.kind = CONSTANT;
                get_left_addr->info.binop.op2.val.value = i * 4;
                struct GlobalSymbol* hold_left = insert_symbol(NULL);
                hold_left->type->kind = ADDR;
                get_left_addr->info.binop.result.kind = ADDRESS;
                get_left_addr->info.binop.result.val.var_no = hold_left->alias;
                hold_left->type->info.array.width = left->type->info.array.width? left->type->info.array.width->next: NULL;
                insert_ir(get_left_addr);

                struct IR* save = new(IR);
                save->kind = STORE_T;
                save->info.unaryop.result.kind = ADDRESS;
                save->info.unaryop.result.val.var_no = hold_left->alias;
                save->info.unaryop.op1.kind = VARIABLE;
                save->info.unaryop.op1.val.var_no = temp->alias;
                insert_ir(save);
            }
        }
	}

}

struct GlobalSymbol* translate_Exp(TreeNode *root, struct PlainType* plain_type, struct GlobalSymbol* place) {
	if (root == NULL) {
        struct IR* ir = new(IR);
        ir->kind = ASSIGN_T;
        ir->info.assign.left.kind = VARIABLE;
        ir->info.assign.left.val.var_no = place->alias;
        ir->info.assign.right.kind = CONSTANT;
        ir->info.assign.right.val.value = 0;
        insert_ir(ir);
        return place;
    }

    if (root->child_num == 1) {
		char* child_name = ((TreeNode *)root->child[0])->name;
		if (strcmp(child_name, "ID") == 0) {
			struct GlobalSymbol* target = translate_ID((TreeNode *)root->child[0], plain_type);
			return target;
			/*
			struct IR* ir = new(IR);
			ir->kind = ASSIGN_T;
			ir->info.assign.right.kind = VARIABLE;
			ir->info.assign.right.val.var_no = right->alias;
			ir->info.assign.left.kind = VARIABLE;
			ir->info.assign.left.val.var_no = place->alias;
			insert_ir(ir);
			 */
		} else if (strcmp(child_name, "INT") == 0) {
			int val = ((TreeNode *)root->child[0])->value.i;
			struct IR* ir = new(IR);
			ir->kind = ASSIGN_T;
			ir->info.assign.right.kind = CONSTANT;
			ir->info.assign.right.val.value = val;
			ir->info.assign.left.kind = VARIABLE;
			ir->info.assign.left.val.var_no = place->alias;
			insert_ir(ir);
			return place;
		} else if (strcmp(child_name, "FLOAT") == 0) {
			return place;
		} else
			return NULL;
	} else if(root->child_num == 2) {
		char* child_name = ((TreeNode *)root->child[0])->name;
		if (strcmp(child_name, "MINUS") == 0) {
			struct GlobalSymbol* right = insert_symbol(NULL);
			right = translate_Exp((TreeNode *)root->child[1], plain_type, right);

            if (right->type->kind == ADDR) {
                struct GlobalSymbol* temp = insert_symbol(NULL);
                struct IR* ir = new(IR);
                ir->kind = GET_VAL_T;
                ir->info.unaryop.op1.val.var_no = right->alias;
                ir->info.unaryop.op1.kind = ADDRESS;
                ir->info.unaryop.result.kind = VARIABLE;
                ir->info.unaryop.result.val.var_no = temp->alias;
                insert_ir(ir);
                right = temp;
            }

			struct IR* ir = new(IR);
			ir->kind = SUB_T;
			ir->info.binop.op1.kind = CONSTANT;
			ir->info.binop.op1.val.value = 0;
            ir->info.binop.op2.kind = VARIABLE;
            ir->info.binop.op2.val.var_no = right->alias;
            ir->info.binop.result.kind = VARIABLE;
            ir->info.binop.result.val.var_no = place->alias;
			insert_ir(ir);
			return place;

		} else if (strcmp(child_name, "NOT") == 0) {
			struct GlobalSymbol* right = insert_symbol(NULL);
			right = translate_Exp((TreeNode *)root->child[1], plain_type, right);

            if (right->type->kind == ADDR) {
                struct GlobalSymbol* temp = insert_symbol(NULL);
                struct IR* ir = new(IR);
                ir->kind = GET_VAL_T;
                ir->info.unaryop.op1.val.var_no = right->alias;
                ir->info.unaryop.op1.kind = ADDRESS;
                ir->info.unaryop.result.kind = VARIABLE;
                ir->info.unaryop.result.val.var_no = temp->alias;
                insert_ir(ir);
                right = temp;
            }

            struct GlobalSymbol *result = place;

            struct IR *init = new(IR);
            init->kind = ASSIGN_T;
            init->info.assign.left.kind = VARIABLE;
            init->info.assign.left.val.var_no = result->alias;
            init->info.assign.right.kind = CONSTANT;
            init->info.assign.right.val.value = 1;
            insert_ir(init);

            int label = l_cnt++;

            struct IR *test = new(IR);
            test->kind = JMPC_T;
            test->info.jumpc.operator = EQ_T - GT_T;
            test->info.jumpc.expect = 0;
            test->info.jumpc.cond = right->alias;
            test->info.jumpc.label = label;
            insert_ir(test);

            struct IR *set = new(IR);
            set->kind = ASSIGN_T;
            set->info.assign.left.kind = VARIABLE;
            set->info.assign.left.val.var_no = result->alias;
            set->info.assign.right.kind = CONSTANT;
            set->info.assign.right.val.value = 0;
            insert_ir(set);

            struct IR *set_label = new(IR);
            set_label->kind = LABEL_T;
            set_label->info.label_no = label;
            insert_ir(set_label);

			return result;
		} else
			return NULL;
	} else if (root->child_num == 3) {
		char* name0 = ((TreeNode *)root->child[0])->name;
		char* name1 = ((TreeNode *)root->child[1])->name;
		//char* name2 = ((TreeNode *)root->child[2])->name;
		if (strcmp(name1, "ASSIGNOP") == 0) {
			// struct GlobalSymbol* left = insert_symbol(NULL);
			// translate_Exp((TreeNode *)root->child[0], plain_type, left);
			struct GlobalSymbol* left = translate_Exp((TreeNode *)root->child[0], plain_type, NULL);
			struct GlobalSymbol* right = insert_symbol(NULL);
			right = translate_Exp((TreeNode *)root->child[2], plain_type, right);

            /*
            if (right->type->kind == ADDR) {
                struct GlobalSymbol* temp = insert_symbol(NULL);
                struct IR* ir = new(IR);
                ir->kind = GET_VAL_T;
                ir->info.unaryop.op1.val.var_no = right->alias;
                ir->info.unaryop.op1.kind = ADDRESS;
                ir->info.unaryop.result.kind = VARIABLE;
                ir->info.unaryop.result.val.var_no = temp->alias;
                insert_ir(ir);
                right = temp;
            }*/
            if (left->type->kind == BASIC && right->type->kind == BASIC) {
                struct IR* ir = new(IR);
                ir->kind = ASSIGN_T; // todo: other situations
                ir->info.assign.left.kind = VARIABLE;
                ir->info.assign.left.val.var_no = left->alias;
                ir->info.assign.right.kind = VARIABLE;
                ir->info.assign.right.val.var_no = right->alias;
                insert_ir(ir);
            } else if (left->type->kind == BASIC && right->type->kind != BASIC) {
                struct GlobalSymbol* temp = insert_symbol(NULL);
                struct IR* ir1 = new(IR);
                ir1->kind = GET_VAL_T;
                ir1->info.unaryop.op1.val.var_no = right->alias;
                ir1->info.unaryop.op1.kind = ADDRESS;
                ir1->info.unaryop.result.kind = VARIABLE;
                ir1->info.unaryop.result.val.var_no = temp->alias;
                insert_ir(ir1);
                right = temp;

                struct IR* ir2 = new(IR);
                ir2->kind = ASSIGN_T;
                ir2->info.assign.left.kind = VARIABLE;
                ir2->info.assign.left.val.var_no = left->alias;
                ir2->info.assign.right.kind = VARIABLE;
                ir2->info.assign.right.val.var_no = right->alias;
                insert_ir(ir2);
            } else if(right->type->kind == BASIC){
                struct IR* save = new(IR);
                save->kind = STORE_T;
                save->info.unaryop.result.kind = ADDRESS;
                save->info.unaryop.result.val.var_no = left->alias;
                save->info.unaryop.op1.kind = VARIABLE;
                save->info.unaryop.op1.val.var_no = right->alias;
                insert_ir(save);
            } else {
                int total  = 1;
                struct Location* cur = right->type->info.array.width;
                while (cur) {
                    total *= cur->offset;
                    cur = cur->next;
                }
                for (int i = 0; i < total; ++i) {
                    struct IR *get_right_addr = new(IR);
                    get_right_addr->kind = GET_ADDR_T;
                    get_right_addr->info.binop.op1.kind = ADDRESS;
                    get_right_addr->info.binop.op1.val.var_no = right->alias;
                    get_right_addr->info.binop.op1.need_get_addr = (right->type->kind == ARRAY) ? 1 : 0;
                    get_right_addr->info.binop.op2.kind = CONSTANT;
                    get_right_addr->info.binop.op2.val.value = i * 4;
                    struct GlobalSymbol* hold_right = insert_symbol(NULL);
                    hold_right->type->kind = ADDR;
                    get_right_addr->info.binop.result.kind = ADDRESS;
                    get_right_addr->info.binop.result.val.var_no = hold_right->alias;
                    hold_right->type->info.array.width = right->type->info.array.width? right->type->info.array.width->next: NULL;
                    insert_ir(get_right_addr);

                    struct IR *get_right_value = new(IR);
                    struct GlobalSymbol * temp = insert_symbol(NULL);
                    get_right_value->kind = GET_VAL_T;
                    get_right_value->info.unaryop.op1.val.var_no = hold_right->alias;
                    get_right_value->info.unaryop.op1.kind = ADDRESS;
                    get_right_value->info.unaryop.result.kind = VARIABLE;
                    get_right_value->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(get_right_value);


                    struct IR *get_left_addr = new(IR);
                    get_left_addr->kind = GET_ADDR_T;
                    get_left_addr->info.binop.op1.kind = ADDRESS;
                    get_left_addr->info.binop.op1.val.var_no = left->alias;
                    get_left_addr->info.binop.op1.need_get_addr = (left->type->kind == ARRAY) ? 1 : 0;
                    get_left_addr->info.binop.op2.kind = CONSTANT;
                    get_left_addr->info.binop.op2.val.value = i * 4;
                    struct GlobalSymbol* hold_left = insert_symbol(NULL);
                    hold_left->type->kind = ADDR;
                    get_left_addr->info.binop.result.kind = ADDRESS;
                    get_left_addr->info.binop.result.val.var_no = hold_left->alias;
                    hold_left->type->info.array.width = left->type->info.array.width? left->type->info.array.width->next: NULL;
                    insert_ir(get_left_addr);

                    struct IR* save = new(IR);
                    save->kind = STORE_T;
                    save->info.unaryop.result.kind = ADDRESS;
                    save->info.unaryop.result.val.var_no = hold_left->alias;
                    save->info.unaryop.op1.kind = VARIABLE;
                    save->info.unaryop.op1.val.var_no = temp->alias;
                    insert_ir(save);
                }

            }
			return NULL;
		} else if (strcmp(name1, "DOT") == 0) {
			if (able_to_translate == 1) {
				able_to_translate = 0;
				//printf("Can't translate");
			}
			return NULL;
		} else if (strcmp(name0, "ID") == 0) {
			// TODO: CALL EXPRESSION
            if (strcmp(((TreeNode *)root->child[0])->value.s, "read") == 0) {
                struct IR *ir = new(IR);
                ir->kind = READ_T;
                if (place != NULL)
                    ir->info.call.receive = place->alias;
                else
                    ir->info.call.receive = -1;
                insert_ir(ir);
            } else {
                struct IR *ir = new(IR);
                ir->kind = CALL_T;
                ir->info.call.func = ((TreeNode *) root->child[0])->value.s;
                if (place != NULL)
                    ir->info.call.receive = place->alias;
                else
                    ir->info.call.receive = -1;
                insert_ir(ir);
            }
			return place;
		} else if (strcmp(name0, "LP") == 0) {
			place = translate_Exp((TreeNode *)root->child[1], plain_type, place);
			return place;
		} else {

            int operator;
			if (strcmp(name1, "RELOP") == 0)
				operator = match_op(name1, ((TreeNode *)root->child[1])->value.s);
			else
				operator = match_op(name1, NULL);

            if (operator == GT_T || operator == GE_T || operator == LT_T ||
                operator == LE_T || operator == EQ_T || operator == UE_T) {
                
                
                struct GlobalSymbol* left = insert_symbol(NULL);
                left = translate_Exp((TreeNode *)root->child[0], plain_type, left);
                struct GlobalSymbol* right = insert_symbol(NULL);
                right = translate_Exp((TreeNode *)root->child[2], plain_type, right);
                
                if (right->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = right->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    right = temp;
                }

                if (left->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = left->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    left = temp;
                }
                
                struct GlobalSymbol *result = place;
                struct IR *init = new(IR);
                init->kind = ASSIGN_T;
                init->info.assign.left.kind = VARIABLE;
                init->info.assign.left.val.var_no = result->alias;
                init->info.assign.right.kind = CONSTANT;
                init->info.assign.right.val.value = 1;
                insert_ir(init);

                struct IR *sub = new(IR);
                struct GlobalSymbol* diff = insert_symbol(NULL);
                sub->kind = SUB_T;
                sub->info.binop.op1.kind = VARIABLE;
                sub->info.binop.op1.val.var_no = left->alias;
                sub->info.binop.op2.kind = VARIABLE;
                sub->info.binop.op2.val.var_no = right->alias;
                sub->info.binop.result.kind = VARIABLE;
                sub->info.binop.result.val.var_no = diff->alias;
                insert_ir(sub);

                int label = l_cnt++;

                struct IR *test = new(IR);
                test->kind = JMPC_T;
                test->info.jumpc.operator = operator - GT_T;
                test->info.jumpc.expect = 0;
                test->info.jumpc.cond = diff->alias;
                test->info.jumpc.label = label;
                insert_ir(test);

                struct IR *set = new(IR);
                set->kind = ASSIGN_T;
                set->info.assign.left.kind = VARIABLE;
                set->info.assign.left.val.var_no = result->alias;
                set->info.assign.right.kind = CONSTANT;
                set->info.assign.right.val.value = 0;
                insert_ir(set);

                struct IR *set_label = new(IR);
                set_label->kind = LABEL_T;
                set_label->info.label_no = label;
                insert_ir(set_label);

            } else if (operator == AND_T) {
                struct GlobalSymbol *result = place;

                struct IR *init = new(IR);
                init->kind = ASSIGN_T;
                init->info.assign.left.kind = VARIABLE;
                init->info.assign.left.val.var_no = result->alias;
                init->info.assign.right.kind = CONSTANT;
                init->info.assign.right.val.value = 1;
                insert_ir(init);

                int label1 = l_cnt++;

                struct GlobalSymbol* left = insert_symbol(NULL);
                left = translate_Exp((TreeNode *)root->child[0], plain_type, left);

                if (left->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = left->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    left = temp;
                }

                struct IR *test_left = new(IR);
                test_left->kind = JMPC_T;
                test_left->info.jumpc.operator = UE_T - GT_T;
                test_left->info.jumpc.expect = 0;
                test_left->info.jumpc.cond = left->alias;
                test_left->info.jumpc.label = label1;
                insert_ir(test_left);

                struct IR *short_set = new(IR);
                short_set->kind = ASSIGN_T;
                short_set->info.assign.left.kind = VARIABLE;
                short_set->info.assign.left.val.var_no = result->alias;
                short_set->info.assign.right.kind = CONSTANT;
                short_set->info.assign.right.val.value = 0;
                insert_ir(short_set);

                int label2 = l_cnt++;

                struct IR *short_end = new(IR);
                short_end->kind = JMP_T;
                short_end->info.jump.label = label2;
                insert_ir(short_end);

                struct IR *set_label1 = new(IR);
                set_label1->kind = LABEL_T;
                set_label1->info.label_no = label1;
                insert_ir(set_label1);

                struct GlobalSymbol* right = insert_symbol(NULL);
                right = translate_Exp((TreeNode *)root->child[2], plain_type, right);


if (right->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = right->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    right = temp;
                }


                struct IR *test_right = new(IR);
                test_right->kind = JMPC_T;
                test_right->info.jumpc.operator = UE_T - GT_T;
                test_right->info.jumpc.expect = 0;
                test_right->info.jumpc.cond = right->alias;
                test_right->info.jumpc.label = label2;
                insert_ir(test_right);

                struct IR *long_set = new(IR);
                long_set->kind = ASSIGN_T;
                long_set->info.assign.left.kind = VARIABLE;
                long_set->info.assign.left.val.var_no = result->alias;
                long_set->info.assign.right.kind = CONSTANT;
                long_set->info.assign.right.val.value = 0;
                insert_ir(long_set);

                struct IR *set_label2 = new(IR);
                set_label2->kind = LABEL_T;
                set_label2->info.label_no = label2;
                insert_ir(set_label2);


            } else if (operator == OR_T) {
                struct GlobalSymbol *result = place;

                struct IR *init = new(IR);
                init->kind = ASSIGN_T;
                init->info.assign.left.kind = VARIABLE;
                init->info.assign.left.val.var_no = result->alias;
                init->info.assign.right.kind = CONSTANT;
                init->info.assign.right.val.value = 0;
                insert_ir(init);

                int label1 = l_cnt++;

                struct GlobalSymbol* left = insert_symbol(NULL);
                left = translate_Exp((TreeNode *)root->child[0], plain_type, left);

if (left->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = left->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    left = temp;
                }

                struct IR *test_left = new(IR);
                test_left->kind = JMPC_T;
                test_left->info.jumpc.operator = EQ_T - GT_T;
                test_left->info.jumpc.expect = 0;
                test_left->info.jumpc.cond = left->alias;
                test_left->info.jumpc.label = label1;
                insert_ir(test_left);

                struct IR *short_set = new(IR);
                short_set->kind = ASSIGN_T;
                short_set->info.assign.left.kind = VARIABLE;
                short_set->info.assign.left.val.var_no = result->alias;
                short_set->info.assign.right.kind = CONSTANT;
                short_set->info.assign.right.val.value = 1;
                insert_ir(short_set);

                int label2 = l_cnt++;

                struct IR *short_end = new(IR);
                short_end->kind = JMP_T;
                short_end->info.jump.label = label2;
                insert_ir(short_end);

                struct IR *set_label1 = new(IR);
                set_label1->kind = LABEL_T;
                set_label1->info.label_no = label1;
                insert_ir(set_label1);

struct GlobalSymbol* right = insert_symbol(NULL);
                right = translate_Exp((TreeNode *)root->child[2], plain_type, right);


if (right->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = right->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    right = temp;
                }


                struct IR *test_right = new(IR);
                test_right->kind = JMPC_T;
                test_right->info.jumpc.operator = EQ_T - GT_T;
                test_right->info.jumpc.expect = 0;
                test_right->info.jumpc.cond = right->alias;
                test_right->info.jumpc.label = label2;
                insert_ir(test_right);

                struct IR *long_set = new(IR);
                long_set->kind = ASSIGN_T;
                long_set->info.assign.left.kind = VARIABLE;
                long_set->info.assign.left.val.var_no = result->alias;
                long_set->info.assign.right.kind = CONSTANT;
                long_set->info.assign.right.val.value = 1;
                insert_ir(long_set);

                struct IR *set_label2 = new(IR);
                set_label2->kind = LABEL_T;
                set_label2->info.label_no = label2;
                insert_ir(set_label2);

            } else {

                struct GlobalSymbol* left = insert_symbol(NULL);
                left = translate_Exp((TreeNode *)root->child[0], plain_type, left);
                struct GlobalSymbol* right = insert_symbol(NULL);
                right = translate_Exp((TreeNode *)root->child[2], plain_type, right);
                
                if (right->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = right->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    right = temp;
                }

                if (left->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* ir = new(IR);
                    ir->kind = GET_VAL_T;
                    ir->info.unaryop.op1.val.var_no = left->alias;
                    ir->info.unaryop.op1.kind = ADDRESS;
                    ir->info.unaryop.result.kind = VARIABLE;
                    ir->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(ir);
                    left = temp;
                }

                struct IR *ir = new(IR);
                ir->kind = operator;
                ir->info.binop.op1.kind = VARIABLE;
                ir->info.binop.op1.val.var_no = left->alias;
                ir->info.binop.op2.kind = VARIABLE;
                ir->info.binop.op2.val.var_no = right->alias;
                ir->info.binop.result.kind = VARIABLE;
                ir->info.binop.result.val.var_no = place->alias;
                insert_ir(ir);
            }

			return place;
		}
	} else if (root->child_num == 4) {
		char* name0 = ((TreeNode *)root->child[0])->name;
		if (strcmp(name0, "ID") == 0) {
            char *func = ((TreeNode *)root->child[0])->value.s;
            if (strcmp(func, "write") == 0)
                writing = 1;
			struct GlobalSymbol* first = translate_Args((TreeNode *)root->child[2], NULL);
			if (strcmp(func, "write") == 0) {
                struct IR *ir = new(IR);
                ir->kind = WRITE_T;
                //if (place != NULL)
                if (first->type->kind == ADDR) {
                    struct GlobalSymbol* temp = insert_symbol(NULL);
                    struct IR* save = new(IR);
                    save->kind = GET_VAL_T;
                    save->info.unaryop.op1.val.var_no = first->alias;
                    save->info.unaryop.op1.kind = ADDRESS;
                    save->info.unaryop.result.kind = VARIABLE;
                    save->info.unaryop.result.val.var_no = temp->alias;
                    insert_ir(save);
                    first = temp;
                }

                    ir->info.call.receive = first->alias;
                //else
                    //ir->info.call.receive = -1;
                insert_ir(ir);

                writing = 0;

                if (place != NULL) {
                    struct IR *assign= new(IR);
                    assign->kind = ASSIGN_T;
                    assign->info.assign.right.kind = CONSTANT;
                    assign->info.assign.right.val.value = 0;
                    assign->info.assign.left.kind = VARIABLE;
                    assign->info.assign.left.val.var_no = place->alias;
                    insert_ir(ir);
                }
            } else {
                struct IR *ir = new(IR);
                ir->kind = CALL_T;
                ir->info.call.func = func;
                if (place != NULL)
                    ir->info.call.receive = place->alias;
                else
                    ir->info.call.receive = -1;
                insert_ir(ir);
            }
			return place;
		} else {
            struct GlobalSymbol* offset = insert_symbol(NULL);
			offset = translate_Exp((TreeNode *)root->child[2], plain_type, offset);
			struct GlobalSymbol* base = translate_Exp((TreeNode *)root->child[0], plain_type, NULL);
            struct GlobalSymbol* temp = insert_symbol(NULL);
            struct IR* ir1 = new(IR);
            ir1->kind = MUL_T;
            ir1->info.binop.op1.kind = VARIABLE;
            ir1->info.binop.op1.val.var_no = offset->alias;
            ir1->info.binop.op2.kind = CONSTANT;
            int width = 4;
            struct Location* loc = base->type->info.array.width->next;
            while (loc != NULL) {
                width *= loc->offset;
                loc = loc->next;
            }
            ir1->info.binop.op2.val.value = width;
            ir1->info.binop.result.kind = VARIABLE;
            ir1->info.binop.result.val.var_no = temp->alias;
            insert_ir(ir1);
            struct IR* ir2 = new(IR);
            ir2->kind = GET_ADDR_T;
            ir2->info.binop.op1.kind = ADDRESS;
            ir2->info.binop.op1.val.var_no = base->alias;
            ir2->info.binop.op1.need_get_addr = (base->type->kind == ARRAY)? 1: 0;
            ir2->info.binop.op2.kind = VARIABLE;
            ir2->info.binop.op2.val.var_no = temp->alias;
            struct GlobalSymbol* hold = insert_symbol(NULL);
            hold->type->kind = ADDR;
            ir2->info.binop.result.kind = ADDRESS;
            ir2->info.binop.result.val.var_no = hold->alias;
            insert_ir(ir2);
            hold->type->info.array.width = base->type->info.array.width->next;
            return hold;
		}
	} else
		return NULL;
}

struct GlobalSymbol* translate_Args(TreeNode * root, struct Argument* arg_list) {
	struct GlobalSymbol* symbol = insert_symbol(NULL);
	struct PlainType* plain_type = new(PlainType);
	struct Argument* new_arg = new(Argument);
    if (writing) {
        writing = 0;
        new_arg->arg = translate_Exp((TreeNode *) root->child[0], plain_type, symbol);
        writing = 1;
    } else
        new_arg->arg = translate_Exp((TreeNode *) root->child[0], plain_type, symbol);


    if (new_arg->arg->type->kind == ADDR && new_arg->arg->type->info.array.width == NULL) {
        struct GlobalSymbol* temp = insert_symbol(NULL);
        struct IR* ir = new(IR);
        ir->kind = GET_VAL_T;
        ir->info.unaryop.op1.val.var_no = new_arg->arg->alias;
        ir->info.unaryop.op1.kind = ADDRESS;
        ir->info.unaryop.result.kind = VARIABLE;
        ir->info.unaryop.result.val.var_no = temp->alias;
        insert_ir(ir);
        new_arg->arg = temp;
    }

    new_arg->next = arg_list;
	arg_list = new_arg;
	symbol = new_arg->arg;
	if (root->child_num == 3)
		translate_Args((TreeNode *)root->child[2], arg_list);
	else {
		struct Argument* cur = arg_list;
		while (cur != NULL) {
			struct IR* ir = new(IR);
			ir->kind = ARG_T;
            if (cur->arg->type->kind == ARRAY)
                ir->kind = ARG_ARRAY_T;
			ir->info.var_no = cur->arg->alias;

            //if (cur->arg->type->kind == ADDR && cur->arg->type->info.array.width == NULL)
               // printf("0\n");
            //else if (cur->arg->type->kind == ADDR && cur->arg->type->info.array.width != NULL)
               // printf("%d\n", cur->arg->type->info.array.width->offset);

            if (!writing) {
                insert_ir(ir);
                //if (cur->arg->type->kind == ADDR && cur->arg->type->info.array.width != NULL)
                //    printf("0\n");
                //else if (cur->arg->type->kind == ADDR && cur->arg->type->info.array.width != NULL)
                // printf("%d\n", cur->arg->type->info.array.width->offset);
            }
			cur = cur->next;
		}
	}
    return symbol;
}

struct GlobalSymbol* translate_ID(TreeNode* root, struct PlainType* plain_type) {
	if (first_definition == 1) { // in definition
		struct GlobalSymbol *symbol = insert_symbol(root->value.s);
		symbol->type = plain_type;
		if (plain_type->kind != ARRAY && plain_type->kind != ADDR)
			plain_type->kind = BASIC;

		if (defining_param == 1) { // define parameters
			struct IR* ir = new(IR);
			ir->kind = PARAM_T;
			ir->info.var_no = symbol->alias;
			insert_ir(ir);
		}
		return symbol;
	} else {
		struct GlobalSymbol* cur = all_symbols;
		while (cur != NULL && strcmp(cur->name, root->value.s) != 0)
			cur = cur->next;
		return cur;
	}
}

void translate_TYPE(TreeNode* root, struct PlainType* plain_type) {
	if (strcmp(root->value.s, "int") == 0)
		plain_type->info.basic = 0;
	else
		plain_type->info.basic = 1;
}



