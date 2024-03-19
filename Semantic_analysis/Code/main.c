#include <stdio.h>
#include "semanticAnalysis.h"
#include "syntax.tab.h"
extern void yyrestart(FILE*F);
extern int yyparse();
extern void initial_symbol_tables();
Node *Root = NULL;
extern int legal;
int main(int argc, char** argv)
{
    //initial symbol table
    initial_symbol_tables();

    //
    if (argc <= 1)
        return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    //printf("syntax analyse\n");
    yyrestart(f);
    //printf("syntax processing\n");
    //yydebug = 1;
    yyparse();
    //printf("syntax analyse over \n");
    //{lab2-Niu} sematic analyze 
    if(legal)
        _Promgram(Root);
    return 0;
}