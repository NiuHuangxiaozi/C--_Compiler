#include <stdio.h>
#include "semanticAnalysis.h"
#include "translate.h"
#include "syntax.tab.h"

extern void yyrestart(FILE*F);
extern int yyparse();
extern void initial_symbol_tables();
TreeNode *Root = NULL;
extern int legal;
/*
typedef struct {
	int f;
} node;
node x;
x.f = 1;*/
int main(int argc, char** argv)
{
    if (argc <= 1)
        return 1;
    FILE* src = fopen(argv[1], "r");
    if (!src)
    {
        perror(argv[1]);
        return 1;
    }
    //printf("syntax analyse\n");
    yyrestart(src);
    //printf("syntax processing\n");
    //yydebug = 1;
    yyparse();
    //printf("syntax analyse over \n");
    //{lab2-Niu} sematic analyze
    if(legal) {
	    //initial_symbol_tables();
	    //_Program(Root);
    }
    // IR generation
	translate_Program(Root, argv[2]);

    return 0;
}