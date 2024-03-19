#include "semanticAnalysis.h"
#include "assert.h"
extern int is_in_struct;
//define a tree node represent the whole syntax.y
void _Promgram(Node * root)
{
  if(root==NULL)return;
  _ExtDefList(root->child[0]);
}

void _ExtDefList(Node * root)
{
  //printf("Expected ExtDefLIst | %s\n",root->name);
//empty//
if(root->is_terminal==0&&root->child_num==0)
    return;
else
{
   _ExtDef(root->child[0]);
   _ExtDefList(root->child[1]);
}
}

/*
ExtDef → Specifier ExtDecList SEMI
| Specifier SEMI
| Specifier FunDec CompSt
*/
void _ExtDef(Node *root)
{
  //printf("Expected _ExtDef | %s\n",root->name);
  //Get Specifier
  Node * node_1=root->child[1];
  Type *_type=(Type *)malloc(sizeof(Type));  //acquire type
  initial_type(_type);

  if(strcmp(node_1->name,"ExtDecList")==0)
  {
    _Specifier(root->child[0],_type);
    _ExtDecList(root->child[1],_type);
    _SEMI(root->child[2]);
  }
  else if(strcmp(node_1->name,"SEMI")==0)
  {
    _Specifier(root->child[0],_type);
    _SEMI(root->child[2]);
  }
  else if(strcmp(node_1->name,"FunDec")==0)
  {
    _Specifier(root->child[0],_type);
    _FunDec(root->child[1],_type);
    _CompSt(root->child[2]);
    Delete_current_table();

  }
}

/*
ExtDecList → VarDec
| VarDec COMMA ExtDecList
*/
void _ExtDecList(Node*root,Type *_type)
{
  if(root->child_num==1)//1
  {
      _VarDec(root->child[0],_type);
  }
  else//3
  {
      _VarDec(root->child[0],_type);
      _ExtDecList(root->child[2],_type);
  }
}















/*
Specifier → TYPE
    | StructSpecifier
*/
void _Specifier(Node *root,Type *_type)
{
  //printf("Expected Specifier | %s\n",root->name);
  Node *node_one=root->child[0];
  if(strcmp(node_one->name,"TYPE")==0)
  { 
     _TYPE(root->child[0],_type);
  }
  else
  {
    _StructSpecifier(root->child[0],_type);
  }
}
void _TYPE(Node *root,Type *_type)
{
  //printf("Expected _TYPE | %s\n",root->name);
  if(root->is_terminal==1&&root->child_num==0)
  {
    if(strcmp(root->value.s,"int")==0)
    {
      _type->type=Variables;
      _type->val_type=Type_Int;
    }
    else if(strcmp(root->value.s,"float")==0)
    {
      _type->type=Variables;
      _type->val_type=Type_Float;
    }
  }
}

/*
StructSpecifier → STRUCT OptTag LC DefList RC
| STRUCT Tag
*/
void _StructSpecifier(Node * root,Type * _type)
{
  //printf("this is_StructSpecifier\n");
  if(root->child_num==5)
  { 
    //set type
    _type->type=Struct;
    //get struct's name
    _OptTag(root->child[1],_type);// acquire name
    check_struct_re_defined(_type);

    //create new field
    Add_symbol_table(_type);
    
    //get into field
    set_in_struct();
    _DefList(root->child[3]);
    set_out_struct();

    //create struct variable
    Symbol * new_struct=create_struct_symbol(_type);

    //get out of field
    Delete_current_table();

    //add symbol
    insert_table(new_struct);
  }
  else //2
  {
    _type->type=Struct_variable;
    _Tag(root->child[1],_type);
  }
}
/*
OptTag → ID
| empty
*/
void _OptTag(Node * root,Type * _type)
{
  //printf("Expected _OptTag | %s\n",root->name);
  if(root->child_num==0)//no name
  {
    char* temp = (char*)malloc(sizeof(char) * (strlen("xuchang") + 1));
	  strcpy(temp,"xuchang");
    _type->struct_name = temp;
    _type->id_name = temp;
    _type->line=root->line;
  }
  else//1
  {
    _ID(root->child[0],_type);
  }
}
/*
Tag → ID
*/
void _Tag(Node * root,Type *_type)
{
  _ID(root->child[0],_type);
}



















/*
FunDec → ID LP VarList RP
| ID LP RP
*/
void _FunDec(Node*root,Type *_type)
{
  //printf("Expected FunDec | %s\n",root->name);
  Type *function_type=(Type *)malloc(sizeof(Type));
  initial_type(function_type);
  //
  function_type->return_type=_type;
  function_type->type=Functions;
  //
  if(root->child_num==4)
  {
    _ID(root->child[0],function_type);
    _VarList(root->child[2],function_type);
    inverse_parameters(function_type);
  }
  else if(root->child_num==3)
  {
    _ID(root->child[0],function_type);
  }
  //
  check_re_defined(function_type);
  Symbol *sym=create_symbol(function_type);
  insert_table(sym); 
  //create a namespace
  Add_symbol_table(function_type);

}
/*
VarList → ParamDec COMMA VarList
| ParamDec
*/
void _VarList(Node * root,Type *_type)
{
  Type para_type;
  initial_type(&para_type);
  para_type.is_parameter=1;
  if(root->child_num==1)
  {
    _ParamDec(root->child[0],&para_type);
    add_function_parameters(_type,&para_type);
  }
  else 
  {
    _ParamDec(root->child[0],&para_type);//paramDec
    add_function_parameters(_type,&para_type);
    _VarList(root->child[2],_type);//Varlist
  }
}
/*
ParamDec → Specifier VarDec
*/
void _ParamDec(Node * root,Type *_type)
{ 

  _Specifier(root->child[0],_type);
  _VarDec(root->child[1],_type);
}

/*
CompSt → LC DefList StmtList R
*/
void _CompSt(Node*root)
{
  //printf("Expected CompSt | %s\n",root->name);
  _DefList(root->child[1]);
  _StmtList(root->child[2]);
}
/*
DefList → Def DefList
| empty
*/
void _DefList(Node*root)
{
  //printf("Expected DefList | %s\n",root->name);
  if(root->is_terminal==0 &&root->child_num==0)
  return;
  else
  {
    assert(root!=NULL);
    _Def(root->child[0]);
    _DefList(root->child[1]);
  }
}
/*
Def → Specifier DecList SEMI
*/
void _Def(Node * root)
{
    //printf("Expected Def | %s\n",root->name);
    fflush(stdout);
    Type _type;
    initial_type(&_type);
    _Specifier(root->child[0],&_type);
    _DecList(root->child[1],&_type);
    _SEMI(root->child[2]);
}
/*
DecList → Dec
| Dec COMMA DecList
*/
void _DecList(Node *root,Type *_type)
{
    //printf("Expected DecLIst | %s\n",root->name);
    if(root->child_num==1)
    {
          _Dec(root->child[0],_type);
    }
    else //3
    {
          _Dec(root->child[0],_type);
          _DecList(root->child[2],_type);

    }
}
/*
Dec → VarDec
| VarDec ASSIGNOP Exp
*/
void _Dec(Node *root,Type * _type)
{
  //printf("Expected Dec | %s\n",root->name);
  if(root->child_num==1)
  {
    _VarDec(root->child[0],_type);
  }
  else
  {
    _VarDec(root->child[0],_type);
    if(is_in_struct==0)
    {
      //Symbol * sym=create_symbol(_type);
      //insert_table(sym);
      Type * exp_type=(Type *)malloc(sizeof(Type));
      _Exp(root->child[2],exp_type);
      whether_same_type(_type,exp_type);
    }
    else
    {
      printf("Error type 15 at Line %d: Redefined field %s\n",_type->line,_type->id_name);
      return;
    }
  }
}
/*
VarDec → ID
| VarDec LB INT RB
*/
void _VarDec(Node * root,Type * _type)
{
  //printf("Expected VarDec | %s\n",root->name);
  if(root->child_num==1)
  {
    
    if(_type->is_parameter)
    {
      _ID(root->child[0],_type);
      return;
    }
    if(_type->type==Struct_variable)
    {
        //get id
        Type * variable_name=(Type*)malloc(sizeof(Type));
        initial_type(variable_name);
        _ID(root->child[0],variable_name);

        _type->id_name=(char *)malloc(sizeof(variable_name->id_name)+1);
        strcpy(_type->id_name,variable_name->id_name);
        free(variable_name);

        if(whether_struct_defined(_type))
        {
          
          if(check_re_defined(_type))
          {
              Symbol * sym=create_symbol(_type);
              insert_table(sym);
          }
        }
    }
    else
    {
      _ID(root->child[0],_type);
      if(check_re_defined(_type))
      {
        Symbol * sym=create_symbol(_type);
        insert_table(sym);
      }
    }
  }
  else //4 IS array
  {
    _type->type=Array;
    _type->array_size++;
    _VarDec(root->child[0],_type);
    
    //todo
  }

}

/*
Exp →
  | INT
  | Exp PLUS Exp
  | Exp MINUS Exp
  | Exp STAR Exp
  | Exp DIV Exp
  | Exp ASSIGNOP Exp
  | Exp RELOP Exp
  | ID LP Args RP
  | ID LP RP
  | ID
  | LP Exp RP
  | Exp LB Exp RB


*/
void _Exp(Node*root,Type * _type)
{
  //printf("Expected Exp | %s\n",root->name);
  
  Node * first_child=root->child[0];
  if(strcmp(first_child->name,"INT")==0)
  {
    _INT(root->child[0],_type);
    return;
  }
  else if(strcmp(first_child->name,"FLOAT")==0)
  {
    _FLOAT(root->child[0],_type);
    return;
  }
  else if(strcmp(first_child->name,"Exp")==0)
  {
      Node * second_child=root->child[1];
      if(strcmp(second_child->name,"ASSIGNOP")==0)
      {
        Type * before=(Type *)malloc(sizeof(Type));
        initial_type(before);
        Type * after=(Type *)malloc(sizeof(Type));
        initial_type(after);
        _Exp(root->child[0],before);
        _Exp(root->child[2],after);
        whether_same_type(before,after);

      }
      else if(strcmp(second_child->name,"PLUS")==0||
              strcmp(second_child->name,"MINUS")==0||
              strcmp(second_child->name,"STAR")==0||
              strcmp(second_child->name,"DIV")==0)
      {
        Type * before=(Type *)malloc(sizeof(Type));
        initial_type(before);
        Type * after=(Type *)malloc(sizeof(Type));
        initial_type(after);
        _Exp(root->child[0],before);
        _Exp(root->child[2],after);

        if(operands_whether_same_type(before,after))
        {  
          if(before->type==Variables||before->type==Normal)
          {   
               copy_type(_type,before);
               return;
          }
            else if(before->type==Functions)
            {
              copy_type(_type,before->return_type);
              _type->line=before->line;
            }
            else if(before->type==Array)
            {
              _type->type=Normal;_type->array_size=0;
              _type->line=before->line;
            }
        }
        else
          initial_type(_type);
      }
      else if(strcmp(second_child->name,"LB")==0)
      {
          _Exp(root->child[0],_type);
          int is_right=0;
          if(check_whether_defined(_type,Array))
          {
                int test1=check_whether_arr(_type);      
                Type index;
                initial_type(&index);
                _Exp(root->child[2],&index);
                int test2=check_whether_index(&index);
                if(test1&&test2)
                {
                  _type->array_size--;
                  if(_type->array_size==0)
                  {
                  _type->type=Variables;_type->array_size=0;//change to Variables
                  _type->line=_type->line;
                  }
                }
                else
                {
                  initial_type(_type);//change to unknown
                }
          }
          else
            initial_type(_type);//change to unknown
      }
      else if(strcmp(second_child->name,"DOT")==0)//| Exp DOT ID
      {
          Type * before=(Type *)malloc(sizeof(Type));
          initial_type(before);
          Type * after=(Type *)malloc(sizeof(Type));
          initial_type(after);

          _Exp(root->child[0],before);

          _ID(root->child[2],after);
          int cur_line=after->line;//reserve line

          if(check_dot_match(before,after))
          {
             copy_type(_type,after);
             _type->line=cur_line;
          }
          else
          {
              initial_type(_type);
          }
      }
      /*
      | Exp AND Exp
      | Exp OR Exp
      | Exp RELOP Exp     
      */
      else if(strcmp(second_child->name,"RELOP")==0||
              strcmp(second_child->name,"OR")==0||
              strcmp(second_child->name,"AND")==0)
      {
          Type * before=(Type *)malloc(sizeof(Type));
          initial_type(before);
          Type * after=(Type *)malloc(sizeof(Type));
          initial_type(after);
          _Exp(root->child[0],before);
          _Exp(root->child[2],after);
          operands_whether_same_type(before,after);
          //check
      }
  }
  else if(strcmp(first_child->name,"ID")==0)
  {

    if(root->child_num==1)//ID
    {
      //
      _ID(root->child[0],_type);
      check_whether_defined(_type,Variables);
      assert(_type!=NULL);
      
    }
    else if(root->child_num==3)//ID LP RP
    {
      //1
      _ID(root->child[0],_type);
      int cur_line=_type->line;
      if(check_whether_defined(_type,Functions))
      {
          if(check_whether_func(_type))
          {
              copy_type(_type,_type->return_type); //assign return type
              _type->line=cur_line;
              return;
          }
          else
            initial_type(_type); //unknown
      }
      else
        initial_type(_type); //unknown
      
      //
    }
    else if(root->child_num==4)//ID LP Args RP
    {
      //1
      _ID(root->child[0],_type);
      int cur_line=_type->line;

      if(check_whether_defined(_type,Functions))
      {
          if(check_whether_func(_type))
          {
            _Args(root->child[2],_type);
            inverse_parameters(_type);
            if(check_function_match(_type))
            {  
              
              copy_type(_type,_type->return_type); //assign return type
              _type->line=cur_line;
              return;
            }
            else
              initial_type(_type); //unknown
          }
          else
            initial_type(_type); //unknown
      }
      else
        initial_type(_type); //unknown
    }

  }
  else if(strcmp(first_child->name,"LP")==0) // LP EXP RP
  {
    _Exp(root->child[1],_type);
  }
  else if(strcmp(first_child->name,"MINUS"))
  {
    _Exp(root->child[1],_type);
    if(whether_is_variable_or_normal(_type))
        return;
    else
        initial_type(_type);
  }
  else if(strcmp(first_child->name,"NOT"))
  {
    _Exp(root->child[1],_type);
    if(whether_is_variable_or_normal(_type))
        return;
    else
        initial_type(_type);
  }
}


/*
Args → Exp COMMA Args
| Exp

*/
void _Args(Node * root,Type *_type)
{
  //printf("Expected _Args | %s\n",root->name);
  
  Type para;
  initial_type(&para);
  if(root->child_num==1)
  {
      _Exp(root->child[0],&para);
      add_function_parameters(_type,&para);
  }
  else
  {
      _Exp(root->child[0],&para);
      add_function_parameters(_type,&para);
      _Args(root->child[2],_type);
  }
}








/*
StmtList → Stmt StmtList
| empty
*/
void _StmtList(Node*root)
{
  //printf("Expected _StmtList | %s\n",root->name);
  if(root->is_terminal==0 &&root->child_num==0)
    return;
  else
  {
      _Stmt(root->child[0]);
      _StmtList(root->child[1]);
  }
}
/*
Stmt → Exp SEMI
| CompSt
| RETURN Exp SEMI
| IF LP Exp RP Stmt
| IF LP Exp RP Stmt ELSE Stmt
| WHILE LP Exp RP Stmt
*/
void _Stmt(Node * root)
{
  //printf("Expected _Stmt | %s\n",root->name);
  Node * first_node=root->child[0];
  Type * temp_type=(Type *)malloc(sizeof(Type));
  initial_type(temp_type);
  if(strcmp(first_node->name,"Exp")==0)
  {
      _Exp(root->child[0],temp_type);
      _SEMI(root->child[1]);
  }
  else if(strcmp(first_node->name,"RETURN")==0)
  {
      _Exp(root->child[1],temp_type);
      is_return_type_match(temp_type);
      _SEMI(root->child[2]);
  }
  //todo
  else if(strcmp(first_node->name,"CompSt")==0)//CompSt
  {
    temp_type->id_name=(char *)malloc(sizeof("CompSt")+1);
    strcmp(temp_type->id_name,"CompSt");
    Add_symbol_table(temp_type);
    _CompSt(root->child[0]);
    Delete_current_table();
  }
  else if(strcmp(first_node->name,"IF")==0)//IF
  {
      if(root->child_num==5)//| IF LP Exp RP Stmt
      {
          _Exp(root->child[2],temp_type);
          _Stmt(root->child[4]);
      }
      else//| IF LP Exp RP Stmt ELSE Stmt
      {
          _Exp(root->child[2],temp_type);
          _Stmt(root->child[4]);
          _Stmt(root->child[6]);
      }
  }
  else if(strcmp(first_node->name,"WHILE")==0)//| WHILE LP Exp RP Stmt
  {
          _Exp(root->child[2],temp_type);
          _Stmt(root->child[4]);
  }
}
void _ID(Node* root,Type *_type)
{
  //printf("Expected ID | %s\n",root->name);
  if(root->is_terminal==1&&root->child_num==0)
  { 
    char* temp = (char*)malloc(sizeof(char) * (strlen(root->value.s) + 1));
    strcpy(temp, root->value.s);
    if(_type->type==Struct||_type->type==Struct_variable)
    {
      _type->struct_name = temp; //for struct means struct;s name
      _type->id_name = temp; //only use for signal namespace's name for add_namespace
      _type->line=root->line;
      return;
    }
    else
    {
      _type->id_name = temp; //for normal variable it is like i,j,k
      _type->line=root->line;
      return;
    }
  }
}
void _INT(Node * root,Type *_type)
{
  if(root->is_terminal==1&&root->child_num==0)
  {
    _type->type=Normal;
    _type->val_type=Type_Int;
    _type->line=root->line;
    _type->value.int_val=root->value.i;
    //printf("_INT\n");
  }
}
void  _FLOAT(Node * root,Type *_type)
{
  if(root->is_terminal==1&&root->child_num==0)
  {
    _type->type=Normal;
    _type->val_type=Type_Float;
    _type->line=root->line;
    _type->value.float_val=root->value.f;
    //printf("_FLOAT\n");
  }
}
void _COMMA(Node*root)
{
  //if(root!=NULL)
    //printf("%s\n",root->name);
}
void _SEMI(Node *root)
{
  //if(root!=NULL)
    //printf("%s\n",root->name);
}