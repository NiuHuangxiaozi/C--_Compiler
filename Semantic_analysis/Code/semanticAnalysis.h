#include "tree.h"
#include "symbolTable.h"


// high level
void _Promgram(Node * root);
void _ExtDef(Node *root);
void _ExtDefList(Node  *root);
void _ExtDecList(Node*root,Type *_type);

//
void _Specifier(Node *root,Type *_type);
void _StructSpecifier(Node * root,Type * _type);
void _TYPE(Node *root,Type *_type);
void _FunDec(Node *root,Type *_type);
void _VarList(Node * root,Type *__type);
void _CompSt(Node *root);
void _COMMA(Node *root);
void _SEMI(Node *root);

void _ID(Node *root,Type *_type); 
void _DefList(Node *root);
void _Def(Node * root);
void _Dec(Node *root,Type * _type);
void _DecList(Node *root,Type *_type);
void _StmtList(Node *root);
void _Exp(Node*root,Type * _type);
void _Stmt(Node * root);
void  _INT(Node * root,Type *_type);
void  _FLOAT(Node * root,Type *_type);
void  _Args(Node * root,Type *_type);




