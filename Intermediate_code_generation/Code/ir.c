//
// Created by hbd on 2023/4/14.
//
#include "ir.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct IR* ir_head;
struct IR* ir_tail;

void init_ir_list() {
	ir_head = (struct IR*) malloc(sizeof(struct IR));
	ir_tail = (struct IR*) malloc(sizeof(struct IR));
	ir_head->kind = HEAD_T;
	ir_tail->kind = TAIL_T;
	ir_head->next = ir_tail;
	ir_head->prev = ir_tail;
	ir_tail->prev = ir_head;
	ir_tail->next = ir_head;
}

int match_op(const char* name, const char* value) {
	if (strcmp(name, "AND") == 0)
		return AND_T;
	if (strcmp(name, "OR") == 0)
		return OR_T;
	if (strcmp(name, "PLUS") == 0)
		return ADD_T;
	if (strcmp(name, "MINUS") == 0)
		return SUB_T;
	if (strcmp(name, "STAR") == 0)
		return MUL_T;
	if (strcmp(name, "DIV") == 0)
		return DIV_T;
	if (strcmp(name, "PLUS") == 0)
		return ADD_T;
	if (strcmp(name, "RELOP") == 0) {
		if (strcmp(value, ">") == 0)
			return GT_T;
		if (strcmp(value, "<") == 0)
			return LT_T;
		if (strcmp(value, ">=") == 0)
			return GE_T;
		if (strcmp(value, "<=") == 0)
			return LE_T;
		if (strcmp(value, "==") == 0)
			return EQ_T;
		if (strcmp(value, "!=") == 0)
			return UE_T;
	}
	return 0;
}

void insert_ir(struct IR* node) {
	node->prev = ir_tail->prev;
	ir_tail->prev->next = node;
	node->next = ir_tail;
	ir_tail->prev = node;
}

void print_single_ir(struct IR* ir, FILE* dest) {
	//printf("It's a ir\n");
    switch (ir->kind) {
        case FUNC_T:
            fprintf(dest, "FUNCTION %s :\n", ir->info.id);
            break;
        case LABEL_T:
            fprintf(dest, "LABEL label%d :\n", ir->info.label_no);
            break;
        case ASSIGN_T:
            if (ir->info.assign.right.kind == CONSTANT)
                fprintf(dest, "t%d := #%d\n", ir->info.assign.left.val.var_no,
                        ir->info.assign.right.val.value);
            else
                fprintf(dest, "t%d := t%d\n", ir->info.assign.left.val.var_no,
                    ir->info.assign.right.val.var_no);
            break;
        case ADD_T:
            fprintf(dest, "t%d := t%d + t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case SUB_T:
            if (ir->info.binop.op1.kind != CONSTANT)
                fprintf(dest, "t%d := t%d - t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            else
                fprintf(dest, "t%d := #%d - t%d\n", ir->info.binop.result.val.value,
                        ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case MUL_T:
            if (ir->info.binop.op2.kind == CONSTANT)
                fprintf(dest, "t%d := t%d * #%d\n", ir->info.binop.result.val.var_no,
                        ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.value);
            else
                fprintf(dest, "t%d := t%d * t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case DIV_T:
            fprintf(dest, "t%d := t%d / t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case AND_T:
            fprintf(dest, "t%d := t%d && t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case OR_T:
            fprintf(dest, "t%d := t%d || t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case GT_T:
            fprintf(dest, "t%d := t%d > t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case LT_T:
            fprintf(dest, "t%d := t%d < t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case GE_T:
            fprintf(dest, "t%d := t%d >= t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case LE_T:
            fprintf(dest, "t%d := t%d <= t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case EQ_T:
            fprintf(dest, "t%d := t%d == t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case UE_T:
            fprintf(dest, "t%d := t%d != t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case NOT_T:
            fprintf(dest, "t%d := ! t%d\n", ir->info.unaryop.result.val.var_no,
                    ir->info.unaryop.op1.val.var_no);
            break;
        case NEG_T:
            fprintf(dest, "t%d := - t%d\n", ir->info.unaryop.result.val.var_no,
                    ir->info.unaryop.op1.val.var_no);
            break;
        case GET_ADDR_T:
            if (ir->info.binop.op1.need_get_addr) {
                if (ir->info.binop.op2.kind == VARIABLE)
                    fprintf(dest, "t%d := &t%d + t%d\n", ir->info.binop.result.val.var_no,
                        ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
                else
                    fprintf(dest, "t%d := &t%d + #%d\n", ir->info.binop.result.val.var_no,
                            ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.value);
            } else {
                if (ir->info.binop.op2.kind == VARIABLE)
                    fprintf(dest, "t%d := t%d + t%d\n", ir->info.binop.result.val.var_no,
                        ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
                else
                    fprintf(dest, "t%d := t%d + #%d\n", ir->info.binop.result.val.var_no,
                            ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.value);
            }
            break;
        case GET_VAL_T:
            fprintf(dest, "t%d := *t%d\n", ir->info.unaryop.result.val.var_no,
                    ir->info.unaryop.op1.val.var_no);
            break;
        case STORE_T:
            fprintf(dest, "*t%d := t%d\n", ir->info.unaryop.result.val.var_no,
                    ir->info.unaryop.op1.val.var_no);
            break;
        case JMP_T:
            fprintf(dest, "GOTO label%d\n", ir->info.jump.label);
            break;
        case JMPC_T:
            // TODO: different kinds of operators
            if (ir->info.jumpc.operator == 0)
                fprintf(dest, "IF t%d > #%d GOTO label%d\n",
                        ir->info.jumpc.cond, ir->info.jumpc.expect, ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 1)
                fprintf(dest, "IF t%d < #%d GOTO label%d\n",
                        ir->info.jumpc.cond, ir->info.jumpc.expect, ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 2)
                fprintf(dest, "IF t%d >= #%d GOTO label%d\n",
                        ir->info.jumpc.cond, ir->info.jumpc.expect, ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 3)
                fprintf(dest, "IF t%d <= #%d GOTO label%d\n",
                        ir->info.jumpc.cond, ir->info.jumpc.expect, ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 4)
                fprintf(dest, "IF t%d == #%d GOTO label%d\n",
                        ir->info.jumpc.cond, ir->info.jumpc.expect, ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 5)
                fprintf(dest, "IF t%d != #%d GOTO label%d\n",
                        ir->info.jumpc.cond, ir->info.jumpc.expect, ir->info.jumpc.label);
            break;
        case RETURN_T:
            fprintf(dest, "RETURN t%d\n", ir->info.var_no);
            break;
        case DEC_T:
            fprintf(dest, "DEC t%d %d\n", ir->info.dec.target, ir->info.dec.size);
            break;
        case ARG_T:
            // TODO: Check Argument
            fprintf(dest, "ARG t%d\n", ir->info.var_no);
            break;
        case ARG_ARRAY_T:
            fprintf(dest, "ARG &t%d\n", ir->info.var_no);
            break;
        case CALL_T:
            fprintf(dest, "t%d := CALL %s\n", ir->info.call.receive, ir->info.call.func); // TODO: Special Process for WRITE & READ
            break;
        case READ_T:
            fprintf(dest, "READ t%d\n", ir->info.call.receive);
            break;
        case WRITE_T:
            fprintf(dest, "WRITE t%d\n", ir->info.call.receive);
            break;
        case PARAM_T:
            fprintf(dest, "PARAM t%d\n", ir->info.var_no);
            break;
        default:
            fprintf(dest, "\n");
    }
}

void output_all_ir(FILE* dest) {
	struct IR* cur = ir_head->next;
	while (cur->kind != TAIL_T) {
		print_single_ir(cur, dest);
		cur = cur->next;
	}
    fclose(dest);
}
