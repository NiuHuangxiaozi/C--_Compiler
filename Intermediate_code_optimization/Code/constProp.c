//
// Created by HBD on 2023/5/18.
//

#include "constProp.h"
#include "ir.h"
#include "graph.h"
#include "stdlib.h"
#include "memory.h"

extern struct GraphNode* graph;
extern int ir_cnt;
extern int v_cnt;
extern struct IR** ir_array;


void init_const_prop() {
    for (int i = 0; i < ir_cnt; ++i) {
        graph[i].in_cp = (struct Value *) malloc(sizeof(struct Value) * v_cnt);
        for (int j = 0; j < v_cnt; ++j)
            graph[i].in_cp[j].kind = UNDEF;
        graph[i].out_cp = (struct Value *) malloc(sizeof(struct Value) * v_cnt);
        for (int j = 0; j < v_cnt; ++j)
            graph[i].out_cp[j].kind = UNDEF;
    }
}

int transferNode_const_prop(int line) {
    int changed = 0;
    if (ir_array[line]->should_print == 0) {
        for (int i = 0; i < v_cnt; ++i)
            graph[line].out_cp[i] = graph[line].in_cp[i];
        return 0;
    }
    struct IR* cur = ir_array[line];
    struct Value* newIn = (struct Value *) malloc(sizeof(struct Value) * v_cnt);
    struct Value* newOut = (struct Value *) malloc(sizeof(struct Value) * v_cnt);
    for (int i = 0; i < v_cnt; ++i)
        newIn[i] = graph[line].in_cp[i];
    // kill left
    if (cur->kind == ASSIGN_T) {
        if (cur->info.assign.left.prefix == NONE)
            newIn[cur->info.assign.left.val.var_no].kind = UNDEF;
    } else if (cur->kind == ADD_T || cur->kind == SUB_T
               || cur->kind == MUL_T ||cur->kind == DIV_T) {
        if (cur->info.binop.result.prefix == NONE)
            newIn[cur->info.binop.result.val.var_no].kind = UNDEF;
    } else if (cur->kind == CALL_T) {
        newIn[cur->info.call.receive].kind = UNDEF;
    } else if (cur->kind == READ_T) {
        newIn[cur->info.read.value.val.var_no].kind = UNDEF;
    }

    for (int i = 0; i < v_cnt; ++i)
        newOut[i] = newIn[i];

    // generate left

    if (cur->kind == ASSIGN_T) {
        if (cur->info.assign.left.prefix == NONE) {
            if (cur->info.assign.right.kind == CONSTANT) {
                newOut[cur->info.assign.left.val.var_no].kind = CONST;
                newOut[cur->info.assign.left.val.var_no].val = cur->info.assign.right.val.value;
            } else if (cur->info.assign.right.kind == VARIABLE && cur->info.assign.right.prefix == NONE) {
                int kind = graph[line].in_cp[cur->info.assign.right.val.var_no].kind;
                int value = graph[line].in_cp[cur->info.assign.right.val.var_no].val;
                if (kind == CONST) {
                    newOut[cur->info.assign.left.val.var_no].kind = CONST;
                    newOut[cur->info.assign.left.val.var_no].val = value;
                }
                else
                    newOut[cur->info.assign.left.val.var_no].kind = kind;
            } else
                newOut[cur->info.assign.left.val.var_no].kind = NAC;
        }
    } else if (cur->kind == ADD_T) {
        if (cur->info.binop.result.prefix == NONE) {
            if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == CONSTANT) {
                newOut[cur->info.binop.result.val.var_no].kind = CONST;
                newOut[cur->info.binop.result.val.var_no].val =
                        cur->info.binop.op1.val.value + cur->info.binop.op2.val.value;
            } else if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == VARIABLE
                && cur->info.binop.op2.prefix == NONE) {
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;
                if (kind2 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            cur->info.binop.op1.val.value + value2;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == CONSTANT
                && cur->info.binop.op1.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                if (kind1 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind1 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            cur->info.binop.op2.val.value + value1;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == VARIABLE
                && cur->info.binop.op1.prefix == NONE && cur->info.binop.op2.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;
                if (kind1 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                if (kind1 == NAC || kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else if (kind1 == CONST && kind2 == CONST) {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            value2 + value1;
                } else
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
            } else {
                newOut[cur->info.binop.result.val.var_no].kind = NAC;
            }
        }
    } else if (cur->kind == SUB_T) {
        if (cur->info.binop.result.prefix == NONE) {
            if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == CONSTANT) {
                newOut[cur->info.binop.result.val.var_no].kind = CONST;
                newOut[cur->info.binop.result.val.var_no].val =
                        cur->info.binop.op1.val.value - cur->info.binop.op2.val.value;
            } else if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == VARIABLE
                       && cur->info.binop.op2.prefix == NONE) {
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;
                if (kind2 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            cur->info.binop.op1.val.value - value2;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == CONSTANT
                       && cur->info.binop.op1.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                if (kind1 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind1 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            value1 - cur->info.binop.op2.val.value;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == VARIABLE
                       && cur->info.binop.op1.prefix == NONE && cur->info.binop.op2.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;
                if (kind1 == NAC || kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else if (kind1 == CONST && kind2 == CONST) {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            value1 - value2;
                } else
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
            } else {
                newOut[cur->info.binop.result.val.var_no].kind = NAC;
            }
        }
    } else if (cur->kind == MUL_T) {
        if (cur->info.binop.result.prefix == NONE) {
            if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == CONSTANT) {
                newOut[cur->info.binop.result.val.var_no].kind = CONST;
                newOut[cur->info.binop.result.val.var_no].val =
                        cur->info.binop.op1.val.value * cur->info.binop.op2.val.value;
            } else if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == VARIABLE
                       && cur->info.binop.op2.prefix == NONE) {
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;
                if (kind2 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            cur->info.binop.op1.val.value * value2;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == CONSTANT
                       && cur->info.binop.op1.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                if (kind1 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind1 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            value1 * cur->info.binop.op2.val.value;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == VARIABLE
                       && cur->info.binop.op1.prefix == NONE && cur->info.binop.op2.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;
                if (kind1 == NAC || kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else if (kind1 == CONST && kind2 == CONST) {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            value1 * value2;
                } else
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
            } else {
                newOut[cur->info.binop.result.val.var_no].kind = NAC;
            }
        }
    } else if (cur->kind == DIV_T) {
        if (cur->info.binop.result.prefix == NONE) {
            if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == CONSTANT) {
                if (cur->info.binop.op2.val.value == 0)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            cur->info.binop.op1.val.value / cur->info.binop.op2.val.value;
                }
            } else if (cur->info.binop.op1.kind == CONSTANT && cur->info.binop.op2.kind == VARIABLE
                       && cur->info.binop.op2.prefix == NONE) {
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;

                if (kind2 == UNDEF || (kind2 == CONST && value2 == 0))
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            cur->info.binop.op1.val.value / value2;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == CONSTANT
                       && cur->info.binop.op1.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                if (kind1 == UNDEF)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind1 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            value1 / cur->info.binop.op2.val.value;
                }
            } else if (cur->info.binop.op1.kind == VARIABLE && cur->info.binop.op2.kind == VARIABLE
                       && cur->info.binop.op1.prefix == NONE && cur->info.binop.op2.prefix == NONE) {
                int kind1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].kind;
                int value1 = graph[line].in_cp[cur->info.binop.op1.val.var_no].val;
                int kind2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].kind;
                int value2 = graph[line].in_cp[cur->info.binop.op2.val.var_no].val;
                if (kind2 == CONST && value2 == 0)
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
                else if (kind1 == NAC || kind2 == NAC)
                    newOut[cur->info.binop.result.val.var_no].kind = NAC;
                else if (kind1 == CONST && kind2 == CONST) {
                    newOut[cur->info.binop.result.val.var_no].kind = CONST;
                    newOut[cur->info.binop.result.val.var_no].val =
                            value1 / value2;
                } else
                    newOut[cur->info.binop.result.val.var_no].kind = UNDEF;
            } else {
                newOut[cur->info.binop.result.val.var_no].kind = NAC;
            }
        }
    } else if (cur->kind == CALL_T) {
        newOut[cur->info.call.receive].kind = NAC;
    } else if (cur->kind == READ_T) {
        newOut[cur->info.read.value.val.var_no].kind = NAC;
    } else if (cur->kind == PARAM_T) {
        newOut[cur->info.param.value.val.var_no].kind = NAC;
    }

    for (int i = 0; i < v_cnt; ++i) {
        if ((newOut[i].kind != graph[line].out_cp[i].kind) ||
            (newOut[i].kind == CONST && graph[line].out_cp[i].kind == CONST && graph[line].out_cp[i].val != newOut[i].val))
            changed = 1;
        graph[line].out_cp[i] = newOut[i];
    }
    return changed;
}

void solve_const_prop() {
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < ir_cnt; ++i) {
            struct GraphNode* cur = &graph[i];

            int set = 0;
            for (struct IntNode* prev = cur->prev; prev != NULL; prev = prev->next) {
                if (set == 0) {
                    for (int j = 0; j < v_cnt; ++j) {
                        graph[i].in_cp[j].kind = graph[prev->num].out_cp[j].kind;
                        graph[i].in_cp[j].val = graph[prev->num].out_cp[j].val;
                    }
                    set = 1;
                }
                for (int j = 0; j < v_cnt; ++j) {
                    int v1 = graph[i].in_cp[j].kind, v2 = graph[prev->num].out_cp[j].kind;
                    int val1 = graph[i].in_cp[j].val, val2 = graph[prev->num].out_cp[j].val;

                    if (v1 == UNDEF && v2 == CONST) {
                        graph[i].in_cp[j].kind = CONST;
                        graph[i].in_cp[j].val = val2;
                    }
                    else if (v2 == UNDEF && v1 == CONST) {
                        graph[i].in_cp[j].kind = CONST;
                        graph[i].in_cp[j].val = val1;
                    }
                    else if (v1 == UNDEF && v2 == UNDEF)
                        graph[i].in_cp[j].kind = UNDEF;
                    else if (v1 == CONST && v2 == CONST && val1 == val2)
                        graph[i].in_cp[j].val = val1;
                    else
                        graph[i].in_cp[j].kind = NAC;
                }
            }
            changed |= transferNode_const_prop(i);
        }
    }
}

