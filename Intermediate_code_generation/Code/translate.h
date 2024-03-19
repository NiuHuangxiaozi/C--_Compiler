//
// Created by hbd on 2023/4/14.
//

#ifndef CODE_TRANSLATE_H
#define CODE_TRANSLATE_H
#include "ir.h"
#include "tree.h"
#include <string.h>

void translate_Program(TreeNode *root, char* filename);
void translate_ExtDefList(TreeNode *root);
void translate_ExtDef(TreeNode *root);
void translate_ExtDecList(TreeNode *root);

void translate_Specifier(TreeNode *root, struct PlainType* plain_type);
void translate_StructSpecifier(TreeNode *root);
void translate_OptTag(TreeNode *root);
void translate_Tag(TreeNode *root);

void translate_VarDec(TreeNode *root, struct PlainType* plain_type);
void translate_FunDec(TreeNode *root);
void translate_VarList(TreeNode *root);
void translate_ParamDec(TreeNode *root);

void translate_CompSt(TreeNode *root);
void translate_StmtList(TreeNode *root);
void translate_Stmt(TreeNode *root);
void translate_Cond(TreeNode *root);

void translate_DefList(TreeNode *root);
void translate_Def(TreeNode *root);
void translate_DecList(TreeNode *root, struct PlainType* plain_type);
void translate_Dec(TreeNode *root, struct PlainType* plain_type);

struct GlobalSymbol* translate_Exp(TreeNode *root, struct PlainType* plain_type, struct GlobalSymbol* place);
struct GlobalSymbol* translate_Args(TreeNode *root, struct Argument* arg_list);

struct GlobalSymbol*  translate_ID(TreeNode* root, struct PlainType* plain_type);
void translate_TYPE(TreeNode* root, struct PlainType* plain_type);

#endif //CODE_TRANSLATE_H
