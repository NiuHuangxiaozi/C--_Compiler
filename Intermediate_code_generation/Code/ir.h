//
// Created by hbd on 2023/4/14.
//

#ifndef CODE_IR_H
#define CODE_IR_H
#include <stdio.h>

struct Operand {
	enum { VARIABLE, CONSTANT, ADDRESS } kind;
	union {
		int var_no;
		int value;
		int unit;
	} val;
    int need_get_addr;
};

struct IR {
	enum {  ASSIGN_T,

			AND_T, OR_T, GT_T, LT_T, GE_T, LE_T, EQ_T, UE_T, NOT_T,

			ADD_T, SUB_T, MUL_T, DIV_T, NEG_T,
			GET_ADDR_T, GET_VAL_T, STORE_T,
			JMP_T, JMPC_T, LABEL_T, HEAD_T, TAIL_T,
			FUNC_T, PARAM_T, ARG_T, ARG_ARRAY_T, CALL_T, RETURN_T, WRITE_T, READ_T,
			DEC_T
	} kind;
	union {
		struct { struct Operand right, left; } assign;
		struct { struct Operand result, op1, op2; } binop;
		struct { struct Operand result, op1; } unaryop;
		struct { char* func; int receive; } call;
		struct { int label; } jump;
		struct { int cond, label, expect, operator; } jumpc;
		char* id;
		int var_no;
		int label_no;
		struct {int target; int size;} dec;
	} info;
	struct IR* prev;
	struct IR* next;
};

struct Location {
	int offset;
	struct Location* next;
};

struct PlainType
{
	enum { BASIC, ARRAY, ADDR, STRUCTURE } kind;
	union
	{
// basic type, 0 is 'int' and 1 is 'float'
		int basic;
// array, size and type
		struct { struct Location* width; int data_type; } array;
// struct, unused in phase3
		struct Field* structure;
	} info;
};

struct Field {
	char* name; // name of field
	struct PlainType* type; // type of field
	struct Field* tail;
};

struct GlobalSymbol {
	char* name;
	int alias;
	struct PlainType* type;
	struct GlobalSymbol* next;
};

struct Argument {
	struct GlobalSymbol* arg;
	struct Argument* next;
};

//struct IR* ir_head;
//struct IR* ir_tail;
void init_ir_list();
int match_op(const char* name, const char* value);
void insert_ir(struct IR* ir);
void print_single_ir(struct IR* ir, FILE* dest);
void output_all_ir(FILE* dest);

#endif //CODE_IR_H
