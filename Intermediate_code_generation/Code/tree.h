#ifndef CODE_TREE_H
#define CODE_TREE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char* name;
    union {
        char* s;
        int i;
        float f;
    } value;
    int child_num;
    struct TreeNode** child;
    int is_terminal;
    int line;
} TreeNode;
//create a node
TreeNode* create_node(const char* name, void* value, int child_num,
                      TreeNode** child, int is_terminal, int line);

//print tree to
void print_ast(TreeNode* root, int depth);

#endif