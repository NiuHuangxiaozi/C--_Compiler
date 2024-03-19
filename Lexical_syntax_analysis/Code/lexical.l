%{
#include "syntax.tab.h"
#define process_token(name) char* str = strdup(yytext); yylval.type_node = create_node(#name, str, 0, NULL, 1, yylloc.first_line); return name;
#define process_val_token(name) return name;

int yycolumn = 1;
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

%}
digit [0-9]
nonzero [1-9]
letter [_a-zA-Z]

%option yylineno
%%
({nonzero}{digit}*)|0 {
    // |(0[0-7]+)|(0[Xx][0-9a-fA-F]+)
    //yylval.type_int = atoi(yytext);
    int value = atoi(yytext);
    yylval.type_node = create_node("INT", &value, 0, NULL, 1, yylloc.first_line);
    //process_val_token(INT)
    return INT;
}
({digit}+\.{digit}+)|(\.{digit}+)|({digit}+\.)|({digit}*\.{digit}+[Ee][\+-]?{digit}+)|({digit}+\.{digit}*[Ee][\+-]?{digit}+) {
    // |({digit}*\.{digit}*[Ee][+-]?{digit}+)
    float value = (float)atof(yytext);
    yylval.type_node = create_node("FLOAT", &value, 0, NULL, 1, yylloc.first_line);
    //process_val_token(FLOAT)
    return FLOAT;
}
int|float {
    /*int value;
    if (strcmp(yytext, "int") == 0)
        value = 0;
    else if (strcmp(yytext, "float") == 0)
        value = 1;*/
    char* str = strdup(yytext);
    yylval.type_node = create_node("TYPE", str, 0, NULL, 1, yylloc.first_line);
    process_val_token(TYPE)
}
struct {
    process_token(STRUCT)
}
return {
    process_token(RETURN)
}
if {
    process_token(IF)
}
else {
    process_token(ELSE)
}
while {
    process_token(WHILE)
}
\n {
    yycolumn = 1;
}
{letter}({letter}|{digit})* {
    char* str = strdup(yytext);
    yylval.type_node = create_node("ID", str, 0, NULL, 1, yylloc.first_line);
    process_val_token(ID)
}
";" {
    process_token(SEMI)
}
"," {
    process_token(COMMA)
}
"=" {
    process_token(ASSIGNOP)
}
>|<|>=|<=|==|!= {
    int value; /*
    if (strcmp(yytext, ">") == 0)
        value = 0;
    if (strcmp(yytext, "<") == 0)
        value = 1;
    if (strcmp(yytext, ">=") == 0)
        value = 2;
    if (strcmp(yytext, "<=") == 0)
        value = 3;
    if (strcmp(yytext, "==") == 0)
        value = 4;
    if (strcmp(yytext, "!=") == 0)
        value = 5;
    */
    char* str = strdup(yytext);
    yylval.type_node = create_node("RELOP", str, 0, NULL, 1, yylloc.first_line);
    process_val_token(RELOP)
}
"+" {
    process_token(PLUS)
}
"-" {
    process_token(MINUS)
}
"*" {
    process_token(STAR)
}
"/" {
    process_token(DIV)
}
"&&" {
    process_token(AND)
}
"||" {
    process_token(OR)
}
"." {
    process_token(DOT)
}
"!" {
    process_token(NOT)
}
"(" {
    process_token(LP)
}
")" {
    process_token(RP)
}
"[" {
    process_token(LB)
}
"]" {
    process_token(RB)
}
"{" {
    process_token(LC)
}
"}" {
    process_token(RC)
}
" "|"\t"|"\r" {

}
. {
    printf("Error type A at Line %d: Mysterious characters \'%s\'\n",
        yylineno, yytext);
    legal = 0;
}
%%
