#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char* name;
    union data {
        char* s;
        int i;
        float f;
    } value;
    int child_num;
    struct Node** child;
    int is_terminal;
    int line;
} Node;
//create a node
Node* create_node(const char* name, void* value, int child_num,
                        Node** child, int is_terminal, int line);

//print tree to
void print_ast(Node* root, int depth);

