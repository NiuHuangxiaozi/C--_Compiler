#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "tree.h"
#include "symbolTable.h"


// high level
void _Program(TreeNode * root);
void _ExtDef(TreeNode *root);
void _ExtDefList(TreeNode  *root);
void _ExtDecList(TreeNode*root,Type *_type);

//
void _Specifier(TreeNode *root,Type *_type);
void _StructSpecifier(TreeNode * root,Type * _type);
void _OptTag(TreeNode* root, Type* _type);
void _Tag(TreeNode* root, Type* _type);
void _TYPE(TreeNode *root,Type *_type);
void _FunDec(TreeNode *root,Type *_type);
void _VarDec(TreeNode *root,Type *_type);
void _ParamDec(TreeNode *root,Type *_type);
void _VarList(TreeNode * root,Type *_type);
void _CompSt(TreeNode *root);
void _COMMA(TreeNode *root);
void _SEMI(TreeNode *root);

void _ID(TreeNode *root,Type *_type);
void _DefList(TreeNode *root);
void _Def(TreeNode * root);
void _Dec(TreeNode *root,Type * _type);
void _DecList(TreeNode *root,Type *_type);
void _StmtList(TreeNode *root);
void _Exp(TreeNode*root,Type * _type);
void _Stmt(TreeNode * root);
void  _INT(TreeNode * root,Type *_type);
void  _FLOAT(TreeNode * root,Type *_type);
void  _Args(TreeNode * root,Type *_type);


#endif

