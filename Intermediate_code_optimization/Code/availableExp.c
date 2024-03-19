//
// Created by HBD on 2023/5/18.
//

#include "availableExp.h"
#include "ir.h"
#include "graph.h"
#include "stdlib.h"
#include "memory.h"

extern struct GraphNode* graph;
extern int ir_cnt;
extern struct IR** ir_array;
extern int v_cnt;

struct ExpNode* exp_list;
struct ExpNode** exp_array;
int exp_cnt = 0;
int cluster_cnt = 0;
struct VarAttr* varAttrs;


int same_exp(struct ExpNode* cur, int line) { // only for binary exp now
    struct IR* ir = ir_array[line];
    int res = 1;
    res &= ir->kind == cur->kind;

    res &= ir->info.binop.op1.kind == cur->op1.kind;

    if (ir->info.binop.op1.kind == CONSTANT && cur->op1.kind == CONSTANT)
        res &= ir->info.binop.op1.val.value == cur->op1.val.value;
    if (ir->info.binop.op1.kind == VARIABLE && cur->op1.kind == VARIABLE)
        res &= ir->info.binop.op1.prefix == cur->op1.prefix && ir->info.binop.op1.val.var_no == cur->op1.val.var_no;

    res &= ir->info.binop.op2.kind == cur->op2.kind;

    if (ir->info.binop.op2.kind == CONSTANT && cur->op2.kind == CONSTANT)
        res &= ir->info.binop.op2.val.value == cur->op2.val.value;
    if (ir->info.binop.op2.kind == VARIABLE && cur->op2.kind == VARIABLE)
        res &= ir->info.binop.op2.prefix == cur->op2.prefix && ir->info.binop.op2.val.var_no == cur->op2.val.var_no;

    return res;
}

void insert_exp(int line) {
    struct IR* ir = ir_array[line];
    for (struct ExpNode* cur = exp_list; cur != NULL; cur = cur->next) {
        if (same_exp(cur, line))
            return;
    }
    ++exp_cnt;
    struct ExpNode* new_exp = (struct ExpNode*) malloc(sizeof (struct ExpNode));
    new_exp->kind = ir->kind;
    new_exp->hold_var_no = -1;
    new_exp->op1 = ir->info.binop.op1;
    new_exp->op2 = ir->info.binop.op2;
    new_exp->next = exp_list;
    exp_list = new_exp;
}

int exp_id(int line) {
    for (int i = 0; i < exp_cnt; ++i)
        if (same_exp(exp_array[i], line))
            return i;
    return -1;
}

void init_available_exp() {
    //cluster_cnt = 0;
    //varAttrs = (struct VarAttr*) malloc(sizeof (struct VarAttr) * v_cnt);
    //for (int i = 0; i < v_cnt; ++i) {
    //    varAttrs[i].is_addr = 0;
    //    varAttrs[i].cluster = -1;
    //}

    exp_cnt = 0;
    exp_list = NULL;
    for (int i = 0; i < ir_cnt; ++i) {
        struct IR* ir = ir_array[i];
        if (ir->kind == ADD_T || ir->kind == SUB_T || ir->kind == MUL_T || ir->kind == DIV_T) {
            if (ir->info.binop.op1.kind == CONSTANT || (ir->info.binop.op1.kind == VARIABLE && ir->info.binop.op1.prefix != STAR))
                if (ir->info.binop.op2.kind == CONSTANT || (ir->info.binop.op2.kind == VARIABLE && ir->info.binop.op2.prefix != STAR))
                    insert_exp(i);
        }
    }
    exp_array = (struct ExpNode **) malloc(sizeof(struct ExpNode *) * exp_cnt);
    struct ExpNode* cur = exp_list;
    for (int i = exp_cnt - 1 ;i >= 0; i--, cur = cur->next) {
        exp_array[i] = cur;
    }
    for (int i = 0; i < ir_cnt; ++i) {
        graph[i].in_ae = (struct ExpNode *) malloc(sizeof(struct ExpNode) * exp_cnt);
        memset(graph[i].in_ae, 0, sizeof(struct ExpNode) * exp_cnt);
        graph[i].out_ae = (struct ExpNode *) malloc(sizeof(struct ExpNode) * exp_cnt);
        if (ir_array[i]->kind == FUNC_T)
            for (int j = 0; j < exp_cnt; ++j) {
                graph[i].out_ae[j].available = 0;
                graph[i].out_ae[j].hold_var_no = -1;
            }
        else
            for (int j = 0; j < exp_cnt; ++j) {
                graph[i].out_ae[j].available = 1;
                graph[i].out_ae[j].hold_var_no = -1;
            }
    }
}

int transferNode_available_exp(int line) {
    //if (line == 20) {
    //    int a = 1;
    //}
    int changed = 0;
    if (ir_array[line]->should_print == 0) {
        for (int i = 0; i < exp_cnt; ++i)
            graph[line].out_ae[i] = graph[line].in_ae[i];
        return 0;
    }
    struct IR* cur = ir_array[line];
    struct ExpNode* newOut = (struct ExpNode *) malloc(sizeof(struct ExpNode) * exp_cnt);
    for (int i = 0; i < exp_cnt; ++i)
        newOut[i] = graph[line].in_ae[i];

    /*
    if (cur->kind == DEC_T) {
        varAttrs[cur->info.dec.target.val.var_no].is_addr = 1;
        varAttrs[cur->info.dec.target.val.var_no].cluster = cluster_cnt++;
    }*/

    // gen right
    if (cur->kind == ADD_T || cur->kind == SUB_T || cur->kind == MUL_T || cur->kind == DIV_T) {
        if (cur->info.binop.op1.kind == CONSTANT || (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op1.prefix != STAR))
            if (cur->info.binop.op2.kind == CONSTANT || (cur->info.binop.op2.kind == VARIABLE && cur->info.binop.op2.prefix != STAR))
                for (int i = 0; i < exp_cnt; ++i) {
                    if (same_exp(exp_array[i], line)) {
                        newOut[i].available = 1;
                        //newOut[i].hold_var_no = line;
                        //exp_array[i]->hold_line = line;
                    }
                }
    }
    // kill left
    if (cur->kind == ASSIGN_T) {
        if (cur->info.assign.left.prefix == NONE)
            for (int i = 0; i < exp_cnt; ++i) {
                if (exp_array[i]->op1.kind == VARIABLE)
                    if (exp_array[i]->op1.val.var_no == cur->info.assign.left.val.var_no)
                        newOut[i].available = 0;
                if (exp_array[i]->op2.kind == VARIABLE)
                    if (exp_array[i]->op2.val.var_no == cur->info.assign.left.val.var_no)
                        newOut[i].available = 0;
            }
    } else if (cur->kind == ADD_T || cur->kind == SUB_T
               || cur->kind == MUL_T ||cur->kind == DIV_T) {
        if (cur->info.binop.result.prefix == NONE)
            for (int i = 0; i < exp_cnt; ++i) {
                if (exp_array[i]->op1.kind == VARIABLE)
                    if (exp_array[i]->op1.val.var_no == cur->info.binop.result.val.var_no)
                        newOut[i].available = 0;
                if (exp_array[i]->op2.kind == VARIABLE)
                    if (exp_array[i]->op2.val.var_no == cur->info.binop.result.val.var_no)
                        newOut[i].available = 0;
            }
    } else if (cur->kind == CALL_T) {
        for (int i = 0; i < exp_cnt; ++i) {
            if (exp_array[i]->op1.kind == VARIABLE)
                if (exp_array[i]->op1.val.var_no == cur->info.call.receive)
                    newOut[i].available = 0;
            if (exp_array[i]->op2.kind == VARIABLE)
                if (exp_array[i]->op2.val.var_no == cur->info.call.receive)
                    newOut[i].available = 0;
        }
    } else if (cur->kind == READ_T) {
        for (int i = 0; i < exp_cnt; ++i) {
            if (exp_array[i]->op1.kind == VARIABLE)
                if (exp_array[i]->op1.val.var_no == cur->info.read.value.val.var_no)
                    newOut[i].available = 0;
            if (exp_array[i]->op2.kind == VARIABLE)
                if (exp_array[i]->op2.val.var_no == cur->info.read.value.val.var_no)
                    newOut[i].available = 0;
        }
    }

    for (int i = 0; i < exp_cnt; ++i)
        if (newOut[i].available != graph[line].out_ae[i].available)
            changed = 1;
    for (int i = 0; i < exp_cnt; ++i)
        graph[line].out_ae[i] = newOut[i];
    return changed;
}

void solve_available_exp() {
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < ir_cnt; ++i) {
            if (ir_array[i]->kind == FUNC_T)
                continue;
            struct GraphNode cur = graph[i];
            for (int j = 0; j < exp_cnt; ++j)
                graph[i].in_ae[j].available = 1;
            for (int j = 0; j < exp_cnt; ++j) {
                for (struct IntNode* prev = cur.prev; prev != NULL; prev = prev->next) {
                    graph[i].in_ae[j].available &= graph[prev->num].out_ae[j].available;
                }
            }
            changed |= transferNode_available_exp(i);
        }
    }
}
