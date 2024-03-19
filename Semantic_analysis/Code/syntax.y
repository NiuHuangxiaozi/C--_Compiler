%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
int legal = 1;
extern Node* Root;

%}
/* declared types */
%union {
    int type_int;
    float type_float;
    char* type_str;
    Node* type_node;
}

/* declared associativity and precedence */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

/* declared tokens */
%token <type_node> INT
%token <type_node> FLOAT
%token <type_node> ID
%token <type_node> SEMI COMMA
%token <type_node> RELOP
%token <type_node> ASSIGNOP PLUS MINUS STAR DIV AND OR DOT NOT
%token <type_node> TYPE
%token <type_node> LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE

%type <type_node> Program ExtDefList ExtDef Specifier FunDec
%type <type_node> CompSt VarDec StructSpecifier OptTag DefList
%type <type_node> Tag VarList ParamDec StmtList Stmt Exp Def Dec
%type <type_node> DecList Args ExtDecList
%%
//High-level Definitions

Program: ExtDefList {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Program",NULL,1,child, 0, @$.first_line);
                //if (legal)
                    //print_ast($$, 0);
                Root=$$;
                }
    ;
ExtDefList: ExtDef ExtDefList {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("ExtDefList",NULL,2,child, 0, @$.first_line);
                }
    | /* empty */ {
                $$=create_node("ExtDefList",NULL,0,NULL, 0, @$.first_line); }
    ;
ExtDef: Specifier ExtDecList SEMI {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("ExtDef",NULL,3,child, 0, @$.first_line);
                }
    | Specifier ExtDecList error { yyerror("Missing \';\'", @1.first_line); legal = 0; }
    | Specifier SEMI {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("ExtDef",NULL,2,child, 0, @$.first_line);
                }
    | Specifier error { yyerror("Missing \';\'", @1.last_line); legal = 0; }
    | error SEMI { yyerror("Error in declarations", @2.last_line); legal = 0; }
    | Specifier FunDec CompSt {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("ExtDef",NULL,3,child, 0, @$.first_line);
                }
    | Specifier FunDec error SEMI { yyerror("Error in declarations", @3.first_line); legal = 0; }
    | Specifier FunDec error DefList StmtList RC { yyerror("Missing \'{\'", @1.first_line); legal = 0; }
    | Specifier ID LP error CompSt { yyerror("Missing \')\'", @1.first_line); legal = 0; }
    ;
ExtDecList: VarDec {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("ExtDecList",NULL,1,child, 0, @$.first_line);
                }
    //| VarDec error ExtDecList { yyerror("Missing \',\'", @1.first_line); legal = 0; }
    | VarDec COMMA ExtDecList {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("ExtDecList",NULL,3,child, 0, @$.first_line);
                }
    ;

//Specifiers

Specifier: TYPE {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Specifier",NULL,1,child, 0, @$.first_line);
                }
    | StructSpecifier {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Specifier",NULL,1,child, 0, @$.first_line);
                }
    ;
StructSpecifier: STRUCT OptTag LC DefList RC {
                Node** child=(Node**)malloc(5*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;child[4]=$5;
                $$=create_node("StructSpecifier",NULL,5,child, 0, @$.first_line);
                }
    | STRUCT OptTag error DefList RC { yyerror("Missing \'{\'", @1.first_line); legal = 0; }
    | STRUCT OptTag LC DefList error { yyerror("Missing \'}\'", @5.first_line); legal = 0; }
    | STRUCT OptTag LC error RC { yyerror("Invalid struct definition", @4.first_line); legal = 0; }
    | STRUCT Tag {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("StructSpecifier",NULL,2,child, 0, @$.first_line);
                }
    ;
OptTag: ID {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("OptTag",NULL,1,child, 0, @$.first_line);
                }
    | /* empty */ { $$=create_node("OptTag",NULL,0,NULL, 0, @$.first_line); }
    ;
Tag: ID {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Tag",NULL,1,child, 0, @$.first_line);
                }
    ;

//Declarators

VarDec: ID {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("VarDec",NULL,1,child, 0, @$.first_line);
                }
    | VarDec LB INT RB {
                Node** child=(Node**)malloc(4*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;
                $$=create_node("VarDec",NULL,4,child, 0, @$.first_line);
                }
    //| VarDec error INT RB { yyerror("Missing \'[\'", @1.first_line); legal = 0; }
    //| VarDec LB INT error { yyerror("Missing \']\'", @1.first_line); legal = 0; }
    ;
FunDec: ID LP VarList RP {
                Node** child=(Node**)malloc(4*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;
                $$=create_node("FunDec",NULL,4,child, 0, @$.first_line);
                }
    //| ID LP error DefList RP { yyerror("Invalid function", @1.first_line); legal = 0; }
    //| ID error RP { yyerror("Missing \'(\'", @1.first_line); legal = 0; }
    | error RP { yyerror("Invalid function declaration", @2.first_line); legal = 0; }
    | ID LP VarList error { yyerror("Missing \')\'", @1.first_line); legal = 0; }
    | ID LP RP {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("FunDec",NULL,3,child, 0, @$.first_line);
                }
    | ID LP error { yyerror("Missing \')\'", @1.first_line); legal = 0; }
    ;
VarList: ParamDec COMMA VarList {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("VarList",NULL,3,child, 0, @$.first_line);
                }
    | ParamDec {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("VarList",NULL,1,child, 0, @$.first_line);
                }
    ;
ParamDec: Specifier VarDec {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("ParamDec",NULL,2,child, 0, @$.first_line);
                }
    ;

//Statements

CompSt: LC DefList StmtList RC {
                Node** child=(Node**)malloc(4*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;
                $$=create_node("CompSt",NULL,4,child, 0, @$.first_line);
                }
    //| error StmtList RC { yyerror("Missing \'{\'", @1.first_line); legal = 0; }
    | LC error StmtList RC { yyerror("Invalid definitions", @2.first_line); legal = 0; }
    | LC DefList error RC { yyerror("Invalid statements", @3.first_line); legal = 0; }
    | LC DefList StmtList error { yyerror("Missing \'}\'", @4.first_line); legal = 0; }
    ;
StmtList: Stmt StmtList {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("StmtList",NULL,2,child, 0, @$.first_line);
                }
    | /* empty */ { $$=create_node("StmtList",NULL,0,NULL, 0, @$.first_line); }
    ;
Stmt: Exp SEMI {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("Stmt",NULL,2,child, 0, @$.first_line);
                }
    | error SEMI { yyerror("Error in expressions", @2.first_line); legal = 0; }
    //| Exp error { yyerror("Missing \';\'", @1.first_line); legal = 0; }
    //| Exp LB error SEMI { yyerror("Missing \']\'", @1.first_line); legal = 0; }
    //| Exp error RB SEMI { yyerror("Missing \'[\'", @1.first_line); legal = 0; }
    | CompSt {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Stmt",NULL,1,child, 0, @$.first_line);
                }
    | RETURN Exp SEMI {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Stmt",NULL,3,child, 0, @$.first_line);
                }
    | RETURN Exp error { yyerror("Missing \';\'", @1.first_line); legal = 0; }
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {
                Node** child=(Node**)malloc(5*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;child[4]=$5;
                $$=create_node("Stmt",NULL,5,child, 0, @$.first_line);
                }
    | IF error Exp RP Stmt { yyerror("Missing \'(\'", @1.first_line); legal = 0; }
    | IF LP Exp error Stmt  { yyerror("Missing \')\'", @1.first_line); legal = 0; }
    | IF LP error RP Stmt { yyerror("Error in condition", @1.first_line); legal = 0; }
    | IF LP Exp RP Stmt ELSE Stmt {
                Node** child=(Node**)malloc(7*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;child[4]=$5;child[5]=$6;child[6]=$7;
                $$=create_node("Stmt",NULL,7,child, 0, @$.first_line);
                }
    | IF error Exp RP Stmt ELSE Stmt { yyerror("Missing \'(\'", @1.first_line); legal = 0; }
    | IF LP Exp error Stmt ELSE Stmt { yyerror("Missing \')\'", @1.first_line); legal = 0; }
    | IF LP error RP Stmt ELSE Stmt { yyerror("Missing \';\' or \',\'", @1.first_line); legal = 0; }
    | WHILE LP Exp RP Stmt {
                Node** child=(Node**)malloc(5*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;child[4]=$5;
                $$=create_node("Stmt",NULL,5,child, 0, @$.first_line);
                }
    | WHILE error Exp RP Stmt { yyerror("Missing \'(\'", @1.first_line); legal = 0; }
    | WHILE LP Exp error Stmt { yyerror("Missing \')\'", @1.first_line); legal = 0; }
    | WHILE LP error RP Stmt { yyerror("Error in condition", @1.first_line); legal = 0; }
    ;

//Local Definitions

DefList: Def DefList {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("DefList",NULL,2,child, 0, @$.first_line);
                }
    | /* empty */ { $$=create_node("DefList",NULL,0,NULL, 0, @$.first_line); }
    ;
Def: Specifier DecList SEMI {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Def",NULL,3,child, 0, @$.first_line);
                }
    | Specifier DecList error { yyerror("Missing \';\' or \',\'", @1.first_line); legal = 0; }
    //| Specifier error SEMI { yyerror("Error in declarations", @1.first_line); legal = 0; }
    |  error SEMI { yyerror("Error in declarations", @1.first_line); legal = 0; }
    ;
DecList: Dec {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("DecList",NULL,1,child, 0, @$.first_line);
                }
    | Dec COMMA DecList {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("DecList",NULL,3,child, 0, @$.first_line);
                }
    | Dec error DecList { yyerror("Missing \',\' or \';\'", @1.first_line); legal = 0; }
    ;
Dec: VarDec {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Dec",NULL,1,child, 0, @$.first_line);
                }
    | VarDec ASSIGNOP Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Dec",NULL,3,child, 0, @$.first_line);
                }
    | VarDec ASSIGNOP error { yyerror("Expect expression", @1.first_line); legal = 0; }
    ;

//Expressions

Exp: Exp ASSIGNOP Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp ASSIGNOP error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | Exp AND Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp AND error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | Exp OR Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp OR error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | Exp RELOP Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp RELOP error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | Exp PLUS Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp PLUS error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | Exp MINUS Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp MINUS error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | Exp STAR Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp STAR error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | Exp DIV Exp {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp DIV error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | LP Exp RP {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| LP Exp error { yyerror("Missing \')\'", @1.first_line); legal = 0; }
    | MINUS Exp {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| MINUS error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | NOT Exp {
                Node** child=(Node**)malloc(2*sizeof(Node*));
                child[0]=$1;child[1]=$2;
                $$=create_node("Exp",NULL,2,child, 0, @$.first_line);
                }
    //| NOT error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | ID LP Args RP {
                Node** child=(Node**)malloc(4*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;
                $$=create_node("Exp",NULL,4,child, 0, @$.first_line);
                }
    | ID LP RP {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| ID error Args RP { yyerror("Missing \'(\'", @1.first_line); legal = 0; }
    //| ID error RP { yyerror("Missing \'(\'", @1.first_line); legal = 0; }

    | Exp LB Exp RB {
                Node** child=(Node**)malloc(4*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;child[3]=$4;
                $$=create_node("Exp",NULL,4,child, 0, @$.first_line);
                }
    //| Exp LB Exp error { yyerror("Missing \']\'", @1.first_line); legal = 0; }
    //| Exp error RB { yyerror("Missing \'[\'", @1.first_line); legal = 0; }
    | Exp DOT ID {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Exp",NULL,3,child, 0, @$.first_line);
                }
    //| Exp DOT error { yyerror("Expect expression", @1.first_line); legal = 0; }
    | ID {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Exp",NULL,1,child, 0, @$.first_line);
                }
    | INT {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Exp",NULL,1,child, 0, @$.first_line);
                }
    | FLOAT {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Exp",NULL,1,child, 0, @$.first_line);
                }
    ;
Args: Exp COMMA Args {
                Node** child=(Node**)malloc(3*sizeof(Node*));
                child[0]=$1;child[1]=$2;child[2]=$3;
                $$=create_node("Args",NULL,3,child, 0, @$.first_line);
                }
    | Exp {
                Node** child=(Node**)malloc(sizeof(Node*));
                child[0]=$1;
                $$=create_node("Args",NULL,1,child, 0, @$.first_line);
                }
    ;
%%
#include "lex.yy.c"

yyerror(const char* s, int line) {
    if (strcmp(s, "syntax error") != 0)
        printf("Error type B at Line %d: %s\n", line, s);
}
