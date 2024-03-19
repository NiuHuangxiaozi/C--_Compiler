//
// Created by HBD on 2023/5/13.
//

#include "graph.h"
#include "ir.h"
#include "stdlib.h"
#include "memory.h"

#define new(T) (struct T *)malloc(sizeof(struct T))

extern struct IR* ir_head;
extern struct NameNode* variable_list;
extern struct NameNode* label_list;
extern int v_cnt;

struct GraphNode* graph;
int* isLeader;
char* scope;
int ir_cnt;
struct IR** ir_array;
char** v_array;
int b_cnt;

void add_prev_to(int src, int target, int kind) {
    struct IntNode* prev = new(IntNode);
    prev->num = target;
    prev->activated = 1;
    prev->kind = kind;
    prev->next = graph[src].prev;
    graph[src].prev = prev;
}

void add_succ_to(int src, int target, int kind) {
    struct IntNode* succ = new(IntNode);
    succ->num = target;
    succ->activated = 1;
    succ->kind = kind;
    succ->next = graph[src].succ;
    graph[src].succ = succ;
}

void build() {
    ir_cnt = 0;
    for (struct IR* ir = ir_head->next; ir->kind != TAIL_T; ir = ir->next) {
        ir->line = ir_cnt;
        ++ir_cnt;
    }
    //ir_cnt = ir_head->prev->prev->line + 1;
    graph = (struct GraphNode *) malloc(sizeof(struct GraphNode) * ir_cnt);
    for (int i = 0; i < ir_cnt; ++i) {
        graph[i].succ = NULL, graph[i].prev = NULL;
    }
    isLeader = (int *) malloc(sizeof(int) * ir_cnt);
    memset(isLeader, 0, sizeof(int) * ir_cnt);

    v_array = (char **) malloc(sizeof(char *) * v_cnt);
    struct NameNode* v_cur = variable_list;
    for (int i = 0; i < v_cnt; ++i, v_cur = v_cur->next) {
        v_array[i] = v_cur->name;
    }

    ir_array = (struct IR **) malloc(sizeof(struct IR *) * ir_cnt);
    int count = 0;
    for (struct IR* cur = ir_head->next; cur->kind != TAIL_T; cur = cur->next) {
        ir_array[count++] = cur;

        if (cur->kind == LABEL_T) {
            isLeader[cur->line] = 1;
            /*
            for (struct IR* tmp = ir_head->next; tmp->kind != TAIL_T; tmp = tmp->next) {
                if (tmp->kind == JMPC_T && strcmp(tmp->info.jumpc.label, cur->info.label.label_name) == 0) {

                }
                if (tmp->kind == JMP_T) {

                }
            }*/
            add_succ_to(cur->line, cur->next->line, common);
        } else if (cur->kind == FUNC_T) {
            scope = cur->info.call.func;
            isLeader[cur->line] = 1;
            add_succ_to(cur->line, cur->next->line, common);
        } else if (cur->kind == JMPC_T || cur->kind == JMP_T) {
            isLeader[cur->next->line] = 1;
            char* target = cur->kind == JMPC_T? cur->info.jumpc.label: cur->info.jump.label;
            for (struct IR* label = ir_head->next; label->kind != TAIL_T; label = label->next) {
                if (label->kind == LABEL_T && strcmp(target, label->info.label.label_name) == 0)
                    add_succ_to(cur->line, label->line, common);
            }
            if (cur->kind == JMPC_T)
                add_succ_to(cur->line, cur->next->line, common);
        } else if (cur->kind == RETURN_T) {
            /*for (struct IR* call = ir_head->next; call->kind != TAIL_T; call = call->next) {
                if (call->kind == CALL_T && strcmp(call->info.call.func, scope) == 0)
                    add_succ_to(cur->line, call->next->line, ret);
            }*/
        } else if (cur->kind == CALL_T) {
            add_succ_to(cur->line, cur->next->line, common);
            /*
            for (struct IR* func = ir_head->next; func->kind != TAIL_T; func = func->next) {
                if (func->kind == FUNC_T && strcmp(func->info.function.name, cur->info.call.func) == 0)
                    add_succ_to(cur->line, func->line, call);
            }*/
        } else {
            add_succ_to(cur->line, cur->next->line, common);
        }
    }
    for (int i = 0; i < ir_cnt; ++i) {
        struct IntNode* succ = graph[i].succ;
        while (succ) {
            add_prev_to(succ->num, i, succ->kind);
            succ = succ->next;
        }
    }

    b_cnt = 0;
    for (int i = 0; i < ir_cnt; ++i) {
        if(isLeader[i]) {
            ++b_cnt;
        }
        ir_array[i]->block = b_cnt - 1;
    }
    //printf("%d\n", b_cnt);

}

void print_succ() {
    printf("succ:\n\n");
    for (int i = 0; i < ir_cnt; ++i) {
        printf("%d: ", i + 1);
        struct IntNode* succ = graph[i].succ;
        while (succ) {
            printf("[%d  %s] ", succ->num + 1, succ->kind == 0? "common": "other");
            succ = succ->next;
        }
        printf("\n");
    }
}

void print_prev() {
    printf("prev:\n\n");
    for (int i = 0; i < ir_cnt; ++i) {
        printf("%d: ", i + 1);
        struct IntNode* prev = graph[i].prev;
        while (prev) {
            printf("[%d  %s] ", prev->num + 1, prev->kind == 0? "common": "other");
            prev = prev->next;
        }
        printf("\n");
    }
}


