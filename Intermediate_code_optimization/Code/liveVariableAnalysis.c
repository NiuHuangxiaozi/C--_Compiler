//
// Created by HBD on 2023/5/13.
//

#include "ir.h"
#include "graph.h"
#include "stdlib.h"
#include "memory.h"
#include "liveVariableAnalysis.h"

extern struct GraphNode* graph;
extern int ir_cnt;
extern int v_cnt;
extern struct IR** ir_array;

void init_live_variable() {
    for (int i = 0; i < ir_cnt; ++i) {
        graph[i].in_lv = (int *) malloc(sizeof(int) * v_cnt);
        memset(graph[i].in_lv, 0, sizeof(int) * v_cnt);
        graph[i].out_lv = (int *) malloc(sizeof(int) * v_cnt);
        memset(graph[i].out_lv, 0, sizeof(int) * v_cnt);
    }
}

int transferNode_live_variable(int line) {
    int changed = 0;
    if (ir_array[line]->should_print == 0) {
        for (int i = 0; i < v_cnt; ++i)
            graph[line].in_lv[i] = graph[line].out_lv[i];
        return 0;
    }
    struct IR* cur = ir_array[line];
    int* newIn = (int *) malloc(sizeof(int) * v_cnt);
    for (int i = 0; i < v_cnt; ++i)
        newIn[i] = graph[line].out_lv[i];
    // process left
    if (cur->kind == ASSIGN_T) {
        if (cur->info.assign.left.prefix == NONE)
            newIn[cur->info.assign.left.val.var_no] = 0;
    } else if (cur->kind == ADD_T || cur->kind == SUB_T
        || cur->kind == MUL_T ||cur->kind == DIV_T) {
        if (cur->info.binop.result.prefix == NONE)
            newIn[cur->info.binop.result.val.var_no] = 0;
    } else if (cur->kind == CALL_T) {
        newIn[cur->info.call.receive] = 0;
    } else if (cur->kind == READ_T) {
        newIn[cur->info.read.value.val.var_no] = 0;
    }
    // process right
    if (cur->kind == ASSIGN_T) {
        if (cur->info.assign.right.kind == VARIABLE)
            newIn[cur->info.assign.right.val.var_no] = 1;
        if (cur->info.assign.left.kind == VARIABLE)
            if (cur->info.assign.left.prefix == STAR)
                newIn[cur->info.assign.left.val.var_no] = 1;
    } else if (cur->kind == ADD_T || cur->kind == SUB_T ||
               cur->kind == MUL_T ||cur->kind == DIV_T) {
        if (cur->info.binop.op1.kind == VARIABLE)
            newIn[cur->info.binop.op1.val.var_no] = 1;
        if (cur->info.binop.op2.kind == VARIABLE)
            newIn[cur->info.binop.op2.val.var_no] = 1;
    } else if (cur->kind == ARG_T) {
        if (cur->info.arg.value.kind == VARIABLE)
            newIn[cur->info.arg.value.val.var_no] = 1;
    } else if (cur->kind == PARAM_T) {
        //if (cur->info.param.value.kind == VARIABLE)
          //  newIn[cur->info.param.value.val.var_no] = 1;
    } else if (cur->kind == RETURN_T) {
        if (cur->info.ret.value.kind == VARIABLE)
            newIn[cur->info.ret.value.val.var_no] = 1;
    } else if (cur->kind == WRITE_T) {
        if (cur->info.write.value.kind == VARIABLE)
            newIn[cur->info.write.value.val.var_no] = 1;
    } else if (cur->kind == JMPC_T) {
        if (cur->info.jumpc.op1.kind == VARIABLE)
            newIn[cur->info.jumpc.op1.val.var_no] = 1;
        if (cur->info.jumpc.op2.kind == VARIABLE)
            newIn[cur->info.jumpc.op2.val.var_no] = 1;
    }
    for (int i = 0; i < v_cnt; ++i)
        if (newIn[i] != graph[line].in_lv[i])
            changed = 1;
    for (int i = 0; i < v_cnt; ++i)
        graph[line].in_lv[i] = newIn[i];
    return changed;
}

void solve_live_variable() {
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = ir_cnt - 1; i >= 0; --i) {
            struct GraphNode cur = graph[i];
            memset(graph[i].out_lv, 0, sizeof(int) * v_cnt);
            for (struct IntNode* succ = cur.succ; succ != NULL; succ = succ->next) {
                for (int j = 0; j < v_cnt; ++j)
                    graph[i].out_lv[j] |= graph[succ->num].in_lv[j];
            }
            changed |= transferNode_live_variable(i);
        }
    }
}
