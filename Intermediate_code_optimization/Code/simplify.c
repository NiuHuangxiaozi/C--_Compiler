//
// Created by HBD on 2023/5/19.
//

#include "simplify.h"
#include "graph.h"
#include "liveVariableAnalysis.h"
#include "constProp.h"
#include "availableExp.h"

#include "string.h"
#include "stdlib.h"

extern struct GraphNode* graph;
extern int ir_cnt;
extern int v_cnt;
extern struct IR** ir_array;
extern struct ExpNode** exp_array;
extern int exp_cnt;
extern char** v_array;
extern int b_cnt;
extern int* isLeader;
int* visited; // for blocks

int compute_cond(int op1, int op2, int operator) {
    if (operator == 0)
        return op1 > op2;
    else if (operator == 1)
        return op1 < op2;
    else if (operator == 2)
        return op1 >= op2;
    else if (operator == 3)
        return op1 <= op2;
    else if (operator == 4)
        return op1 == op2;
    else if (operator == 5)
        return op1 != op2;
    return -1;
}

void search(int exp_id, int line, int var_no, int src) {

    /*
    if (ir_array[line]->kind == ADD_T || ir_array[line]->kind == SUB_T ||
        ir_array[line]->kind == MUL_T || ir_array[line]->kind == MUL_T)
        if (same_exp(exp_array[exp_id], line)) {
            struct IR* copy = (struct IR *) malloc(sizeof (struct IR));
            copy->kind = ASSIGN_T;
            copy->info.assign.left.kind = VARIABLE;
            copy->info.assign.left.prefix = NONE;
            copy->info.assign.left.val.var_no = var_no;
            copy->info.assign.right.kind = VARIABLE;
            copy->info.assign.right.prefix = NONE;
            copy->info.assign.right.val.var_no = ir_array[line]->info.binop.result.val.var_no;
            copy->next = ir_array[line]->next;
            copy->prev = ir_array[line];
            copy->next->prev = copy;
            ir_array[line]->next = copy;
            return;
        }
    for (struct IntNode* prev = graph[line].prev; prev != NULL; prev = prev->next) {
        if (ir_array[prev->num]->prev)
        search(exp_id, prev->num, var_no);
    }
    */

    /*
    for (int i = 0; i <= line; ++i) {
        if (same_exp(exp_array[exp_id], i)) {
            if (ir_array[i]->next != ir_array[i + 1])
                continue;
            struct IR* copy = (struct IR *) malloc(sizeof (struct IR));
            copy->should_print = 1;
            copy->kind = ASSIGN_T;
            copy->info.assign.left.kind = VARIABLE;
            copy->info.assign.left.prefix = NONE;
            copy->info.assign.left.val.var_no = var_no;
            copy->info.assign.right.kind = VARIABLE;
            copy->info.assign.right.prefix = ir_array[i]->info.binop.result.prefix;
            copy->info.assign.right.val.var_no = ir_array[i]->info.binop.result.val.var_no;
            copy->next = ir_array[i]->next;
            copy->prev = ir_array[i];
            copy->next->prev = copy;
            ir_array[i]->next = copy;
        }
    }*/
    if (line == src) {
        for (struct IntNode* prev = graph[line].prev; prev != NULL; prev = prev->next)
            search(exp_id, prev->num, var_no, src);
        return;
    }
    if (visited[ir_array[line]->block])
        return;
    visited[ir_array[line]->block] = 1;
    int cur_block = ir_array[line]->block;
    int find = 0;
    int i = line;
    for (; i >= 0 && ir_array[i]->block == cur_block; i--) {
        if (same_exp(exp_array[exp_id], i)) {
            find = 1;
            if (ir_array[i]->next != ir_array[i + 1])
                break;
            struct IR* copy = (struct IR *) malloc(sizeof (struct IR));
            copy->should_print = 1;
            copy->kind = ASSIGN_T;
            copy->info.assign.left.kind = VARIABLE;
            copy->info.assign.left.prefix = NONE;
            copy->info.assign.left.val.var_no = var_no;
            copy->info.assign.right.kind = VARIABLE;
            copy->info.assign.right.prefix = ir_array[i]->info.binop.result.prefix;
            copy->info.assign.right.val.var_no = ir_array[i]->info.binop.result.val.var_no;
            copy->next = ir_array[i]->next;
            copy->prev = ir_array[i];
            copy->next->prev = copy;
            ir_array[i]->next = copy;
        }
    }
    if (!find) {
        ++i;
        for (struct IntNode* prev = graph[i].prev; prev != NULL; prev = prev->next)
            search(exp_id, prev->num, var_no, src);
    }
}

void simplify() {
    int changed = 1;
    while (changed) {
        build();
        visited = (int*)malloc(sizeof *visited * b_cnt);
        //print_succ();
        //print_prev();
        changed = 0;
        //todo: 1.better search algorithm 2.unreachable branch 3.DAG?

        // eliminate redundant expressions
        init_available_exp();
        solve_available_exp();
        for (int i = 0; i < ir_cnt; ++i) {
            struct IR* ir = ir_array[i];
            if (ir->kind == ADD_T || ir->kind == SUB_T || ir->kind == MUL_T || ir->kind == DIV_T)
                if (ir->info.binop.op1.kind == CONSTANT || (ir->info.binop.op1.kind == VARIABLE && ir->info.binop.op1.prefix != STAR))
                    if (ir->info.binop.op2.kind == CONSTANT || (ir->info.binop.op2.kind == VARIABLE && ir->info.binop.op2.prefix != STAR)){
                int id = exp_id(i);
                // printf("%d", graph[i].in_ae[id].available);
                if (graph[i].in_ae[id].available) {

                    int right_var_no;

                    if (exp_array[id]->hold_var_no != -1) {
                        right_var_no = exp_array[id]->hold_var_no;

                        memset(visited, 0, b_cnt * sizeof(int));
                        search(id, i, right_var_no, i);
                    } else {

                        right_var_no = v_cnt;

                        if (right_var_no == 160) {
                            int w = 1;
                        }

                        exp_array[id]->hold_var_no = right_var_no;
                        char **new_v_array = (char **) malloc((v_cnt + 1) * sizeof(char *));
                        for (int j = 0; j < v_cnt; ++j)
                            new_v_array[j] = v_array[j];

                        int num_len = 0;
                        for (int j = right_var_no; j > 0; j /= 10, num_len++);

                        new_v_array[v_cnt] = (char *) malloc(num_len + 2);
                        new_v_array[v_cnt][0] = 'e';
                        for (int j = right_var_no, k = num_len;
                             j > 0; new_v_array[v_cnt][k--] = '0' + (j % 10), j /= 10);
                        new_v_array[v_cnt][num_len + 1] = '\0';
                        //free(v_array);

                        v_array = new_v_array;
                        insert_variable(v_array[v_cnt]);
                        memset(visited, 0, b_cnt * sizeof(int));
                        search(id, i, right_var_no, i);
                    }

                    ir->kind = ASSIGN_T;
                    //ir->info.assign.right.prefix = NONE;
                    //ir->info.assign.right.kind = VARIABLE;
                    //struct Operand right = ir_array[graph[i].in_ae[id].hold_line]->info.binop.result;
                    int var_no = ir->info.binop.result.val.var_no;
                    //int var_no = v_cnt++;
                    ir->info.assign.left.prefix = NONE;
                    ir->info.assign.left.kind = VARIABLE;
                    ir->info.assign.left.val.var_no = var_no;
                    ir->info.assign.right.prefix = NONE;
                    ir->info.assign.right.kind = VARIABLE;
                    ir->info.assign.right.val.var_no = right_var_no;
                    changed = 1;
                }
            }
        }

        // constant propagation
        build();

        init_const_prop();
        solve_const_prop();
        // fold
        for (int i = 0; i < ir_cnt; ++i) {
            struct IR* ir = ir_array[i];
            struct Value *in_cp = graph[i].in_cp;
            if (ir->kind == ASSIGN_T) {
                if (ir->info.assign.right.kind == VARIABLE)
                    if (ir->info.assign.right.prefix == NONE)
                        if (in_cp[ir->info.assign.right.val.value].kind == CONST) {
                            ir->info.assign.right.kind = CONSTANT;
                            ir->info.assign.right.val.value = in_cp[ir->info.assign.right.val.value].val;
                            changed = 1;
                        }
            } else if (ir->kind == ADD_T || ir->kind == SUB_T || ir->kind == MUL_T || ir->kind == DIV_T) {
                if (ir->info.binop.op1.kind == VARIABLE)
                    if (ir->info.binop.op1.prefix == NONE)
                        if (in_cp[ir->info.binop.op1.val.var_no].kind == CONST) {
                            ir->info.binop.op1.kind = CONSTANT;
                            ir->info.binop.op1.val.value = in_cp[ir->info.binop.op1.val.var_no].val;
                            changed = 1;
                        }
                if (ir->info.binop.op2.kind == VARIABLE)
                    if (ir->info.binop.op2.prefix == NONE)
                        if (in_cp[ir->info.binop.op2.val.var_no].kind == CONST) {
                            ir->info.binop.op2.kind = CONSTANT;
                            ir->info.binop.op2.val.value = in_cp[ir->info.binop.op2.val.var_no].val;
                            changed = 1;
                        }
            } else if (ir->kind == JMPC_T) {
                if (ir->info.jumpc.op1.kind == VARIABLE)
                    if (ir->info.jumpc.op1.prefix == NONE)
                        if (in_cp[ir->info.jumpc.op1.val.var_no].kind == CONST) {
                            ir->info.jumpc.op1.kind = CONSTANT;
                            ir->info.jumpc.op1.val.value = in_cp[ir->info.jumpc.op1.val.var_no].val;
                            changed = 1;
                        }
                if (ir->info.jumpc.op2.kind == VARIABLE)
                    if (ir->info.jumpc.op2.prefix == NONE)
                        if (in_cp[ir->info.jumpc.op2.val.var_no].kind == CONST) {
                            ir->info.jumpc.op2.kind = CONSTANT;
                            ir->info.jumpc.op2.val.value = in_cp[ir->info.jumpc.op2.val.var_no].val;
                            changed = 1;
                        }
            } else if (ir->kind == ARG_T) {
                if (ir->info.arg.value.kind == VARIABLE)
                    if (ir->info.arg.value.prefix == NONE)
                        if (in_cp[ir->info.arg.value.val.var_no].kind == CONST) {
                            ir->info.arg.value.kind = CONSTANT;
                            ir->info.arg.value.val.value = in_cp[ir->info.arg.value.val.var_no].val;
                            changed = 1;
                        }
            } else if (ir->kind == WRITE_T) {
                if (ir->info.write.value.kind == VARIABLE)
                    if (ir->info.write.value.prefix == NONE)
                        if (in_cp[ir->info.write.value.val.var_no].kind == CONST) {
                            ir->info.write.value.kind = CONSTANT;
                            ir->info.write.value.val.value = in_cp[ir->info.write.value.val.var_no].val;
                            changed = 1;
                        }
            }
        }

        // eliminate useless assign

        init_live_variable();
        solve_live_variable();
        for (int i = 0; i < ir_cnt; ++i) {
            if (ir_array[i]->should_print == 0)
                continue;
            if (ir_array[i]->kind == ASSIGN_T) {
                if (ir_array[i]->info.assign.left.prefix == NONE) {
                    if (graph[i].out_lv[ir_array[i]->info.assign.left.val.var_no] == 0) {
                        ir_array[i]->should_print = 0;
                        changed = 1;
                    }
                }
            } else if (ir_array[i]->kind == ADD_T
                       || ir_array[i]->kind == SUB_T
                       || ir_array[i]->kind == MUL_T
                       || ir_array[i]->kind == MUL_T) {
                if (ir_array[i]->info.binop.result.prefix == NONE) {
                    if (graph[i].out_lv[ir_array[i]->info.binop.result.val.var_no] == 0) {
                        ir_array[i]->should_print = 0;
                        changed = 1;
                    }
                }
            }
        }



        // eliminate unreachable branch


        for (int i = 0; i < ir_cnt; ++i) {
            struct IR* ir = ir_array[i];
            if (!ir->should_print)
                continue;
            if (ir->kind == JMPC_T) {
                struct Value* in_cp = graph[i].in_cp;
                int kind1 = ir->info.jumpc.op1.kind, kind2 = ir->info.jumpc.op2.kind;
                int res = -1;
                if (kind1 == CONSTANT && kind2 == CONSTANT) {
                    res = compute_cond(ir->info.jumpc.op1.val.value, ir->info.jumpc.op2.val.value, ir->info.jumpc.operator);
                } else if (kind1 == CONSTANT && kind2 == VARIABLE) {
                    if (in_cp[ir->info.jumpc.op2.val.var_no].kind == CONST) {
                        res = compute_cond(ir->info.jumpc.op1.val.value, in_cp[ir->info.jumpc.op2.val.var_no].val, ir->info.jumpc.operator);
                    }
                } else if (kind1 == VARIABLE && kind2 == CONSTANT) {
                    if (in_cp[ir->info.jumpc.op1.val.var_no].kind == CONST) {
                        res = compute_cond(in_cp[ir->info.jumpc.op1.val.var_no].val, ir->info.jumpc.op2.val.value, ir->info.jumpc.operator);
                    }
                } else if (kind1 == VARIABLE && kind2 == VARIABLE) {
                    if (in_cp[ir->info.jumpc.op1.val.var_no].kind == CONST && in_cp[ir->info.jumpc.op2.val.var_no].kind == CONST) {
                        res = compute_cond(in_cp[ir->info.jumpc.op1.val.var_no].val, in_cp[ir->info.jumpc.op2.val.var_no].val, ir->info.jumpc.operator);
                    }
                }
                if (res == 0) {
                    int target = -1;
                    for (int j = 0; j < ir_cnt; ++j) {
                        if (ir_array[j]->kind == LABEL_T &&
                        strcmp(ir_array[j]->info.label.label_name, ir->info.jumpc.label) == 0) {
                            target = j;
                            break;
                        }
                    }
                    for (struct IntNode* prev = graph[target].prev; prev != NULL; prev = prev->next) {
                        if (prev->num == i)
                            prev->activated = 0;
                    }
                    ir->should_print = 0;
                    changed = 1;
                } else if (res == 1) { // res = 1
                    int target = i + 1;
                    for (struct IntNode* prev = graph[target].prev; prev != NULL; prev = prev->next) {
                        if (prev->num == i)
                            prev->activated = 0;
                    }
                    ir->kind = JMP_T;
                    ir->info.jump.label = ir->info.jumpc.label;
                    changed = 1;
                }
            }

        }

        for (int i = 0; i < ir_cnt; ++i) {
            if (ir_array[i]->should_print == 0)
                continue;
            if (isLeader[i]) {
                if (ir_array[i]->kind == FUNC_T)
                    continue;
                int reachable = 0;
                for (struct IntNode* prev = graph[i].prev; prev != NULL; prev = prev->next)
                    reachable |= prev->activated;
                if (!reachable) {
                    int block = ir_array[i]->block;
                    int j = i;
                    for (; j < ir_cnt && ir_array[j]->block == block; ++j) {
                        ir_array[j]->should_print = 0;
                        changed = 1;
                    }
                    j--;
                    for (struct IntNode* succ = graph[j].succ; succ != NULL; succ = succ->next) {
                        for (struct IntNode* prev = graph[succ->num].prev; prev != NULL; prev = prev->next) {
                            if (prev->num == j)
                                prev->activated = 0;
                        }
                    }
                }
            }
        }

        // eliminate useless function

    }
}