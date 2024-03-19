//
// Created by HBD on 2023/5/11.
//

#include "ir.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

#define new(T) (struct T *)malloc(sizeof(struct T))

struct IR* ir_head;
struct IR* ir_tail;
int l_cnt;
int v_cnt;
int b_lnt; // blocks
int follow_jump; // flag
struct NameNode* variable_list;
struct NameNode* label_list;

extern int ir_cnt;
extern struct IR** ir_array;
extern char** v_array;

void init() {
    ir_head = (struct IR*) malloc(sizeof(struct IR));
    ir_tail = (struct IR*) malloc(sizeof(struct IR));
    ir_head->kind = HEAD_T;
    ir_tail->kind = TAIL_T;
    ir_head->next = ir_tail;
    ir_head->prev = ir_tail;
    ir_tail->prev = ir_head;
    ir_tail->next = ir_head;

    variable_list = NULL;
    label_list = NULL;
}

struct IR* insert_ir() {
    struct IR* ir = new(IR);
    ir->prev = ir_tail->prev;
    ir_tail->prev->next = ir;
    ir->next = ir_tail;
    ir_tail->prev = ir;
    ir->should_print = 1;
    return ir;
}

void insert_label(struct NameNode* label) {
    label->next = label_list;
    label_list = label;
}

int insert_variable(char* name) {
    struct NameNode* cur = variable_list;
    struct NameNode* tail = NULL;
    int i = 0;
    while (cur) {
        if (strcmp(name, cur->name) == 0)
            return i;
        if (!cur->next)
            tail = cur;
        ++i;
        cur = cur->next;
    }
    struct NameNode* node = new(NameNode);
    node->name = name;
    node->next = NULL;

    if (tail)
        tail->next = node;
    else
        variable_list = node;

    return v_cnt++;
}

int match_pattern(const char* pattern, char* buffer) {
    regex_t re;
    regcomp(&re, pattern, 0);
    int res = !regexec(&re, buffer, 0, NULL, 0);
    regfree(&re);
    return res;
}

char* get_token(char* str, int loc) {
    int i = 0, j = 0, blank = 0;
    for(; blank < loc; ++i)
        if (str[i] == ' ')
            ++blank;
    j = i;
    for(; str[j] != ' ' && str[j] != '\0'; ++j);
    int len = j - i;
    char* cp = (char *) malloc(j - i + 1);
    strncpy(cp, str + i, len);
    cp[j - i] = '\0';
    return cp;
}

void set_operand(struct Operand *op, char* description) {
    if (description[0] == '#') {
        op->kind = CONSTANT;
        op->val.value = atoi(description + 1);
    } else if (description[0] == '&') {
        op->kind = VARIABLE;
        op->val.var_no = insert_variable(description + 1);
        op->prefix = AND;
    } else if (description[0] == '*') {
        op->kind = VARIABLE;
        op->val.var_no = insert_variable(description + 1);
        op->prefix = STAR;
    } else {
        op->kind = VARIABLE;
        op->val.var_no = insert_variable(description);
        op->prefix = NONE;
    }
}

void ir_from_str(char* buffer, int line) {
    struct IR* ir = insert_ir();
    ir->line = line;
    if (match_pattern("LABEL .* :", buffer)) {
        char* label_name = get_token(buffer, 1);
        struct NameNode* node = new(NameNode);
        node->name = label_name;
        insert_label(node);
        ir->kind = LABEL_T;
        ir->info.label.label_name = label_name;
        b_lnt++;
    } else if (match_pattern("FUNCTION .* :", buffer)) {
        ir->kind = FUNC_T;
        ir->info.function.name = get_token(buffer, 1);
        b_lnt++;
    } else if (match_pattern("IF .* > .* GOTO .*", buffer)) {
        ir->kind = JMPC_T;
        ir->info.jumpc.label = get_token(buffer, 5);
        ir->info.jumpc.operator = 0;
        set_operand(&(ir->info.jumpc.op1), get_token(buffer, 1));
        set_operand(&(ir->info.jumpc.op2), get_token(buffer, 3));
        follow_jump = 1;

        ir->block = b_lnt;
        return;
    } else if (match_pattern("IF .* < .* GOTO .*", buffer)) {
        ir->kind = JMPC_T;
        ir->info.jumpc.label = get_token(buffer, 5);
        ir->info.jumpc.operator = 1;
        set_operand(&(ir->info.jumpc.op1), get_token(buffer, 1));
        set_operand(&(ir->info.jumpc.op2), get_token(buffer, 3));
        follow_jump = 1;

        ir->block = b_lnt;
        return;
    }  else if (match_pattern("IF .* >= .* GOTO .*", buffer)) {
        ir->kind = JMPC_T;
        ir->info.jumpc.label = get_token(buffer, 5);
        ir->info.jumpc.operator = 2;
        set_operand(&(ir->info.jumpc.op1), get_token(buffer, 1));
        set_operand(&(ir->info.jumpc.op2), get_token(buffer, 3));
        follow_jump = 1;

        ir->block = b_lnt;
        return;
    } else if (match_pattern("IF .* <= .* GOTO .*", buffer)) {;
        ir->kind = JMPC_T;
        ir->info.jumpc.label = get_token(buffer, 5);
        ir->info.jumpc.operator = 3;
        set_operand(&(ir->info.jumpc.op1), get_token(buffer, 1));
        set_operand(&(ir->info.jumpc.op2), get_token(buffer, 3));
        follow_jump = 1;

        ir->block = b_lnt;
        return;
    } else if (match_pattern("IF .* == .* GOTO .*", buffer)) {
        ir->kind = JMPC_T;
        ir->info.jumpc.label = get_token(buffer, 5);
        ir->info.jumpc.operator = 4;
        set_operand(&(ir->info.jumpc.op1), get_token(buffer, 1));
        set_operand(&(ir->info.jumpc.op2), get_token(buffer, 3));
        follow_jump = 1;

        ir->block = b_lnt;
        return;
    } else if (match_pattern("IF .* != .* GOTO .*", buffer)) {
        ir->kind = JMPC_T;
        ir->info.jumpc.label = get_token(buffer, 5);
        ir->info.jumpc.operator = 5;
        set_operand(&(ir->info.jumpc.op1), get_token(buffer, 1));
        set_operand(&(ir->info.jumpc.op2), get_token(buffer, 3));
        follow_jump = 1;

        ir->block = b_lnt;
        return;
    }  else if (match_pattern("GOTO .*", buffer)) {
        ir->kind = JMP_T;
        ir->info.jump.label = get_token(buffer, 1);
        follow_jump = 1;

        ir->block = b_lnt;
        return;
    } else if (match_pattern("RETURN .*", buffer)) {
        ir->kind = RETURN_T;
        set_operand(&(ir->info.ret.value), get_token(buffer, 1));
    } else if (match_pattern("DEC .* .*", buffer)) {
        ir->kind = DEC_T;
        set_operand(&(ir->info.dec.target), get_token(buffer, 1));
        ir->info.dec.size = atoi(get_token(buffer, 2));
    } else if (match_pattern("ARG .*", buffer)) {
        ir->kind = ARG_T;
        set_operand(&(ir->info.arg.value), get_token(buffer, 1));
    } else if (match_pattern(".* := CALL .*", buffer)) {
        ir->kind = CALL_T;
        ir->info.call.receive = insert_variable(get_token(buffer, 0));
        ir->info.call.func = get_token(buffer, 3);
    } else if (match_pattern("PARAM .*", buffer)) {
        ir->kind = PARAM_T;
        set_operand(&(ir->info.param.value), get_token(buffer, 1));
    } else if (match_pattern("READ .*", buffer)) {
        ir->kind = READ_T;
        set_operand(&(ir->info.read.value), get_token(buffer, 1));
    } else if (match_pattern("WRITE .*", buffer)) {
        ir->kind = WRITE_T;
        set_operand(&(ir->info.write.value), get_token(buffer, 1));
    } else if (match_pattern(".* := .* .* .*", buffer)) {
        char* op = get_token(buffer, 3);
        if (strcmp(op, "+") == 0)
            ir->kind = ADD_T;
        if (strcmp(op, "-") == 0)
            ir->kind = SUB_T;
        if (strcmp(op, "*") == 0)
            ir->kind = MUL_T;
        if (strcmp(op, "/") == 0)
            ir->kind = DIV_T;
        set_operand(&(ir->info.binop.result), get_token(buffer, 0));
        set_operand(&(ir->info.binop.op1), get_token(buffer, 2));
        set_operand(&(ir->info.binop.op2), get_token(buffer, 4));
    } else if (match_pattern(".* := .*", buffer)) {
        ir->kind = ASSIGN_T;
        set_operand(&(ir->info.assign.left), get_token(buffer, 0));
        set_operand(&(ir->info.assign.right), get_token(buffer, 2));
    } else {
        ir->kind = ERROR_T;
    }

    if (follow_jump) {
        follow_jump = 0;
        b_lnt++;
    }
    ir->block = b_lnt;
}

void print_operand(struct Operand* op, FILE* dest) {
    if (op->kind == CONSTANT) {
        fprintf(dest, "#%d", op->val.value);
    } else if (op->kind == VARIABLE) {
        if (op->prefix == STAR)
            fprintf(dest, "*");
        if (op->prefix == AND)
            fprintf(dest, "&");
        fprintf(dest, "%s", v_array[op->val.var_no]);
    }
}

void print_single_ir(struct IR* ir, FILE* dest) {
    // printf("It's a ir\n");

    switch (ir->kind) {
        case FUNC_T:
            fprintf(dest, "FUNCTION %s :\n", ir->info.function.name);
            break;
        case LABEL_T:
            fprintf(dest, "LABEL %s :\n", ir->info.label.label_name);
            break;
        case ASSIGN_T:
            print_operand(&ir->info.assign.left, dest);
            fprintf(dest, " := ");
            print_operand(&ir->info.assign.right, dest);
            fprintf(dest, "\n");
            break;
        case ADD_T:
            print_operand(&ir->info.binop.result, dest);
            fprintf(dest, " := ");
            print_operand(&ir->info.binop.op1, dest);
            fprintf(dest, " + ");
            print_operand(&ir->info.binop.op2, dest);
            fprintf(dest, "\n");
            break;
        case SUB_T:
            print_operand(&ir->info.binop.result, dest);
            fprintf(dest, " := ");
            print_operand(&ir->info.binop.op1, dest);
            fprintf(dest, " - ");
            print_operand(&ir->info.binop.op2, dest);
            fprintf(dest, "\n");
            break;
        case MUL_T:
            print_operand(&ir->info.binop.result, dest);
            fprintf(dest, " := ");
            print_operand(&ir->info.binop.op1, dest);
            fprintf(dest, " * ");
            print_operand(&ir->info.binop.op2, dest);
            fprintf(dest, "\n");
            break;
        case DIV_T:
            print_operand(&ir->info.binop.result, dest);
            fprintf(dest, " := ");
            print_operand(&ir->info.binop.op1, dest);
            fprintf(dest, " / ");
            print_operand(&ir->info.binop.op2, dest);
            fprintf(dest, "\n");
            break;
        case JMP_T:
            fprintf(dest, "GOTO %s\n", ir->info.jump.label);
            break;
        case JMPC_T:
            fprintf(dest, "IF ");
            print_operand(&ir->info.jumpc.op1, dest);
            if (ir->info.jumpc.operator == 0)
                fprintf(dest, " > ");
            if (ir->info.jumpc.operator == 1)
                fprintf(dest, " < ");
            if (ir->info.jumpc.operator == 2)
                fprintf(dest, " >= ");
            if (ir->info.jumpc.operator == 3)
                fprintf(dest, " <= ");
            if (ir->info.jumpc.operator == 4)
                fprintf(dest, " == ");
            if (ir->info.jumpc.operator == 5)
                fprintf(dest, " != ");
            print_operand(&ir->info.jumpc.op2, dest);
            fprintf(dest, " GOTO %s\n", ir->info.jumpc.label);
            break;
        case RETURN_T:
            fprintf(dest, "RETURN ");
            print_operand(&ir->info.ret.value, dest);
            fprintf(dest, "\n");
            break;
        case DEC_T:
            fprintf(dest, "DEC %s %d\n", v_array[ir->info.dec.target.val.var_no], ir->info.dec.size);
            break;
        case ARG_T:
            fprintf(dest, "ARG ");
            print_operand(&ir->info.arg.value, dest);
            fprintf(dest, "\n");
            break;
        case CALL_T:
            fprintf(dest, "%s := CALL %s\n", v_array[ir->info.call.receive], ir->info.call.func);
            break;
        case READ_T:
            fprintf(dest, "READ ");
            print_operand(&ir->info.read.value, dest);
            fprintf(dest, "\n");
            break;
        case WRITE_T:
            fprintf(dest, "WRITE ");
            print_operand(&ir->info.write.value, dest);
            fprintf(dest, "\n");
            break;
        case PARAM_T:
            fprintf(dest, "PARAM ");
            print_operand(&ir->info.param.value, dest);
            fprintf(dest, "\n");
            break;
        default:
            fprintf(dest, "mysterious instruction\n");
    }
}

void output_all_ir(FILE* dest) {
    struct IR* cur = ir_head->next;
    while (cur->kind != TAIL_T) {
        if (cur->should_print)
            print_single_ir(cur, dest);
        cur = cur->next;
    }
    fclose(dest);
}