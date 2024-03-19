//
// Created by HBD on 2023/5/18.
//

#ifndef CODE_AVAILABLEEXP_H
#define CODE_AVAILABLEEXP_H

#include "ir.h"
#include "graph.h"

int same_exp(struct ExpNode* cur, int line);
void insert_exp(int line);
int exp_id(int line);
void init_available_exp();
int transferNode_available_exp(int line);
void solve_available_exp();


#endif //CODE_AVAILABLEEXP_H
