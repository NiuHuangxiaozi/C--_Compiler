//
// Created by HBD on 2023/5/13.
//

#ifndef CODE_GRAPH_H
#define CODE_GRAPH_H

#include "ir.h"

struct IntNode {
    int num;
    enum { common, call, ret, call_to_return } kind;
    int activated;
    struct IntNode* next;
};

struct ExpNode {
    int kind;
    struct Operand op1;
    struct Operand op2;
    int hold_var_no;
    int available;
    struct ExpNode* next;
};

struct Value {
    enum {NAC, UNDEF, CONST} kind;
    int val;
};

struct GraphNode {
    int *in_lv;
    int *out_lv;

    struct Value* in_cp;
    struct Value* out_cp;

    struct ExpNode *in_ae;
    struct ExpNode *out_ae;

    struct IntNode* prev;
    struct IntNode* succ;
};

struct VarAttr {
    int is_addr;
    int cluster;
};

void build();
void print_succ();
void print_prev();
void add_prev_to(int src, int target, int kind);
void add_succ_to(int src, int target, int kind);
void simplify();

#endif //CODE_GRAPH_H
