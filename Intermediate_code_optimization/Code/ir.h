//
// Created by HBD on 2023/5/11.
//

#ifndef CODE_IR_H
#define CODE_IR_H

#include <stdio.h>

struct Operand {
    enum { VARIABLE, CONSTANT } kind;
    union {
        int var_no;
        int value;
    } val;
    enum { STAR, AND, NONE } prefix;
};

struct IR {
    int line;
    int should_print;
    int block;
    enum {
        ASSIGN_T,

        ADD_T, SUB_T, MUL_T, DIV_T,

        JMP_T, JMPC_T, LABEL_T,

        HEAD_T, TAIL_T, ERROR_T,

        FUNC_T, PARAM_T, ARG_T, CALL_T, RETURN_T, WRITE_T, READ_T,

        DEC_T
    } kind;
    union {
        struct { struct Operand right, left; } assign;
        struct { struct Operand result, op1, op2; } binop;
        struct { struct Operand result, op1; } unaryop;
        struct { char* func; int receive; } call;
        struct { char* label; } jump;
        struct { char* label; int operator; struct Operand op1, op2; } jumpc;
        struct { char* name; } function;
        struct { struct Operand value; } ret;
        struct { struct Operand value; } arg;
        struct { struct Operand value; } param;
        struct { struct Operand value; } read;
        struct { struct Operand value; } write;
        struct  { char* label_name; } label;
        struct { struct Operand target; int size; } dec;
    } info;
    struct IR* prev;
    struct IR* next;
};

struct NameNode {
    char* name;
    struct NameNode* next;
};

void init();
struct IR* insert_ir();
void insert_label(struct NameNode* label);
int insert_variable(char* name);
int match_pattern(const char* pattern, char* buffer);
void ir_from_str(char* buffer, int count);
void print_operand(struct Operand* op, FILE* dest);
void print_single_ir(struct IR* ir, FILE* dest);
void output_all_ir(FILE* dest);

char* get_token(char* str, int loc);
void set_operand(struct Operand *op, char* description);


#endif //CODE_IR_H
