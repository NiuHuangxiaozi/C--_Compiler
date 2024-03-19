#include "tree.h"
#include <stdio.h>
#include <string.h>


TreeNode* create_node(const char* name, void* value, int child_num,
                      TreeNode** child, int is_terminal, int line) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	char* temp = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(temp, name);
    node->name = temp;
    if (strcmp(name, "ID") == 0 || strcmp(name, "TYPE") == 0 || strcmp(name, "RELOP") == 0)
        node->value.s = (char*)value;
    else if (strcmp(name, "INT") == 0)
        node->value.i = *((int*)value);
    else if (strcmp(name, "FLOAT") == 0)
        node->value.f = *((float*)value);
    else
        node->value.s = (char*)value;
    node->child_num = child_num;
    node->child = (struct Node **) child;
    node->is_terminal = is_terminal;
    node->line = line;

    return node;
}

void print_ast(TreeNode* root, int depth) {
    if (root == NULL)
        return;
    if (!root->is_terminal && !root->child_num)
        return;
    for (int i = 0; i < depth; ++i)
        printf("  ");
    printf("%s", root->name);
    if (strcmp(root->name, "TYPE") == 0) {
        printf(": %s", root->value.s);
    }
    if (strcmp(root->name, "INT") == 0) {
        printf(": %d", root->value.i);
    }
    if (strcmp(root->name, "FLOAT") == 0) {
        printf(": %f", root->value.f);
    }
    if (strcmp(root->name, "ID") == 0) {
        printf(": %s", root->value.s);
    }
    if (!root->is_terminal) {
            printf(" (%d)", root->line);
    }
    printf("\n");
    for (int i = 0; i < root->child_num; ++i)
        print_ast(root->child[i], depth + 1);
}