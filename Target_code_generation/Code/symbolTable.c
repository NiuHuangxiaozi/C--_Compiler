#include "symbolTable.h"

//current symbol table instance
Sym_table * current_symtable;

//All symbols
static struct Symbol * all_symbols = NULL;

//symbol tables stack
Table_Stack tables;

//aux
int is_in_struct=0;
void set_in_struct(){is_in_struct=1;}
void set_out_struct(){is_in_struct=0;}

void print_current_table(int index)
{
      Sym_table * pt=&(tables.tables[index]);
      Symbol * ps=pt->symbols;
      printf("The current namspace :  %s\n",pt->namespace);
      printf("================\n");
      while(ps!=NULL)
      {
        printf("Element | Type :%d |Struct's name : %s | Name :%s | Var_type : %d | Dim : %d \n",\
            ps->type,ps->struct_name,ps->name,ps->var_type,ps->array_dim);
        
        ps= (Symbol *) (Symbol *) ps->next;
      }
      printf("================\n");
}

void copy_type(Type *answer,Type * _type)
{
  initial_type(answer);
  Type * pt = NULL;
  Type * tar_pt = NULL;
  Fieldlist * ft = NULL;
  switch(_type->type)
  {
    case Variables:
      if(_type->id_name!=NULL)
      {
        answer->id_name=(char *)malloc(sizeof(_type->id_name)+1);
        assert(_type->id_name!=NULL);
        strcpy(answer->id_name,_type->id_name);
      }

      answer->type=_type->type;
      answer->val_type=_type->val_type;
      answer->line=_type->line;
      break;
    case Normal:
      answer->type=_type->type; 
      answer->line=_type->line;
      break;
    case Functions:
      answer->id_name=(char *)malloc(sizeof(_type->id_name)+1);
      assert(_type->id_name!=NULL);
      strcpy(answer->id_name,_type->id_name);

      answer->type=_type->type;
      answer->line=_type->line;
      answer->return_type=(Type *)malloc(sizeof(Type));
      copy_type(answer->return_type,_type->return_type);//return type

      //parameters
      answer->func_paras_num=_type->func_paras_num;//numbers
      pt=_type->paras;
      tar_pt=answer->paras;
      while(pt!=NULL)
      {
          Type * elem_one=(Type *)malloc(sizeof(Type));
          copy_type(elem_one,pt);
          if(answer->paras==NULL)
          {
            answer->paras=elem_one;
            tar_pt=elem_one;
          }
          else
          {
            tar_pt->paras=elem_one;
            tar_pt=tar_pt->paras;
          }
          pt=pt->paras;
      }
      break;
    case Struct:
      answer->type=_type->type;
      answer->line=_type->line;
      answer->struct_name=(char *)malloc(sizeof(_type->struct_name)+1);
      assert(_type->struct_name!=NULL);
      strcpy(answer->struct_name,_type->struct_name);

      // field
      Fieldlist * ft=_type->head;
      while(ft!=NULL)
      {
        Fieldlist * elem=(Fieldlist* )malloc(sizeof(Fieldlist));
        elem->element=(Type*)malloc(sizeof(Type));
        copy_type(elem->element,ft->element);
        elem->next=NULL;
        if(_type->head==NULL)
        {
            _type->head=elem;
        }
        else
        {
            elem->next=_type->head;
            _type->head=elem;
        }
        ft=ft->next;
      }
      break;
    case Struct_variable:
      answer->type=_type->type;
      answer->line=_type->line;
      // struct name
      answer->struct_name=(char *)malloc(sizeof(_type->struct_name)+1);
      assert(_type->struct_name!=NULL);
      strcpy(answer->struct_name,_type->struct_name);
      // name
      answer->id_name=(char *)malloc(sizeof(_type->id_name)+1);
      assert(_type->id_name!=NULL);
      strcpy(answer->id_name,_type->id_name);
      break;
    default:
      break;
  }
}

void print_func_arguments(Type *_type)
{
  printf("Function name %s \n",_type->id_name);
  printf("===============================\n");
  Type * para=_type->paras;
  while(para!=NULL)
  {
    printf("Name : %s | Type %d | var Type %d\n",para->id_name,para->type,para->val_type);
    para=para->paras;
  }
  printf("===============================\n");
}

void inverse_parameters(Type *_type)
{
  if(_type->paras==NULL)return;
  if(_type->paras->paras==NULL)return;
  Type * node_one=_type->paras;
  Type * node_two=_type->paras->paras;
  node_one->paras=NULL;
  while(node_two!=NULL)
  {
      Type * next_node=node_two->paras;
      node_two->paras=node_one;
      node_one=node_two;
      node_two=next_node;
  }
  _type->paras=node_one;
}

//type
void initial_type(Type * _type)
{
  _type->type=0;
  _type->id_name=NULL;
  _type->array_size=0;
  _type->array_dims=NULL;
  _type->paras=NULL;
  
  _type->is_parameter=0;
  _type->func_paras_num=0;
  _type->paras=NULL; //parameters
  _type->return_type=NULL; //function's return 

  _type->struct_name=NULL;
}

void add_function_parameters(Type*_type,Type*para_type)
{
   //printf("add_function_parameters\n");
  Type * new_para=(Type *)malloc(sizeof(Type));
  initial_type(new_para);
  if(para_type->type==Variables)
  {
     new_para->id_name=para_type->id_name;
     new_para->line=para_type->line;
     new_para->type=para_type->type;
     new_para->val_type=para_type->val_type;
  }
  else if(para_type->type==Normal)
  {
     new_para->line=para_type->line;
     new_para->type=para_type->type;
     new_para->val_type=para_type->val_type;
  }
  else if(para_type->type==Array)
  {
    

  }
  if(_type->paras!=NULL){
    Type * head=_type->paras;
    new_para->paras=head;
    _type->paras=new_para;
    _type->func_paras_num++;
  }
  else
  {
    _type->paras=new_para;
    _type->func_paras_num=1;
  }
}

//initial
void initial_symbol_tables()
{
    tables.top=-1;
    tables.max_num=10;
    push(&tables);
    tables.tables[tables.top].symbols=NULL;
    tables.tables[tables.top].symbol_num=0;
    tables.tables[tables.top].namespace=(char *)malloc(sizeof(char)*4);
    strcpy(tables.tables[tables.top].namespace,"NJU");
    current_symtable=&(tables.tables[tables.top]);
    //
    current_symtable=top(&tables);
    // Phase3
    Symbol * read = (Symbol *) malloc(sizeof(Symbol));
	Symbol * write = (Symbol *) malloc(sizeof(Symbol));
	read->type = Functions;
	write->type = Functions;
	read->name = (char *) malloc(strlen("read") + 1);
	strcpy(read->name, "read");
	write->name = (char *) malloc(strlen("write") + 1);
	strcpy(write->name, "write");
	read->line = 0;
	write->line = 0;
	read->function_return_type = (Type *) malloc(sizeof(Type));
	write->function_return_type = (Type *) malloc(sizeof(Type));
	read->function_return_type->type = Variables;
	write->function_return_type->type = Variables;
	read->function_return_type->val_type = 0;
	write->function_return_type->val_type = 0;
	read->function_parameters_number = 0;
	write->function_parameters_number = 1;
	read->function_parameters_type = NULL;
	write->function_parameters_type = (Type *) malloc(sizeof(Type));
	write->function_parameters_type->type = Variables;
	write->function_parameters_type->type = Variables;
	write->function_parameters_type->paras = NULL;

	insert_table(read);
	insert_table(write);
}

// table
Symbol * create_symbol(Type *_type)
{
  //printf("create symbol\n");
  Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
  char* temp = (char*)malloc(sizeof(char) * (strlen(_type->id_name) + 1));
    strcpy(temp, _type->id_name);
  sym->name= temp;
  switch(_type->type)
  {
    case Variables:
      sym->type=Variables;
      sym->line=_type->line;
      sym->var_type=_type->val_type;
      break;
    case Functions:
      sym->type=Functions;
      sym->function_return_type=_type->return_type;
      sym->function_parameters_number=_type->func_paras_num;
      sym->function_parameters_type=_type->paras;
      sym->line=_type->line;
      break;
    case Array:
      sym->type=Array;
      sym->line=_type->line;
      sym->var_type=_type->val_type;
      sym->array_dim=_type->array_size;
      if(_type->struct_name!=NULL)
      {
         sym->struct_name=(char*)malloc(sizeof(_type->struct_name)+1);
         strcpy(sym->struct_name,_type->struct_name);
      }
      break;
    case Struct_variable: //only use for struct pos i
      sym->type=Struct_variable;
      sym->line=_type->line;
      sym->struct_name=(char*)malloc(sizeof(_type->struct_name)+1);
      strcpy(sym->struct_name,_type->struct_name);
      break;
    default:break;
  }
  return sym;
}

int insert_table(Symbol * sym)
{
    //printf("insert table\n");
    struct Symbol * head=(struct Symbol *)current_symtable->symbols;
    sym->next=head;
    current_symtable->symbols=sym;
    current_symtable->symbol_num++;
}

Symbol * create_struct_symbol(Type*_type)
{
  Symbol * pt=current_symtable->symbols;
  //printf("create struct\n");
  //1 name
  assert(_type!=NULL);
  Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
  char* temp = (char*)malloc(sizeof(char) * (strlen(_type->id_name) + 1));
	strcpy(temp, _type->id_name);
  sym->struct_name= temp;
  //struct name
  sym->name=(char *)malloc(sizeof(_type->id_name)+1);
  strcpy(sym->name,temp);

  //2 type
  sym->type=Struct;
  //3 parameters
  while(pt!=NULL)
  {
      Fieldlist * new_field=(Fieldlist *)malloc(sizeof(Fieldlist));
      new_field->next=NULL;
      new_field->element=(Type*)malloc(sizeof(Type));
      initial_type(new_field->element);

      //
      Type *elem=new_field->element;

      //
      char* t = (char*)malloc(sizeof(char) * (strlen(pt->name) + 1));
	    strcpy(t, pt->name);
      elem->id_name= t;
      
      switch(pt->type)
      {
          case Variables:
            elem->type=Variables;
            elem->val_type=pt->var_type;
            elem->line=pt->line;
            break;
          case Array:
            elem->type=Array;
            elem->val_type=pt->var_type;
            elem->line=pt->line;
            elem->array_size=pt->array_dim;
            break;
          case Struct_variable:// no probability
            elem->type=Struct_variable;
            elem->line=pt->line;
            //
            char* struct_name = (char*)malloc(sizeof(char) * (strlen(pt->struct_name) + 1));
	          strcpy(struct_name, pt->struct_name);
            elem->struct_name= struct_name;
            //char* struct_name = (char*)malloc(sizeof(char) * (strlen(pt->struct_name) + 1));
	          char* name = (char*)malloc(sizeof(char) * (strlen(pt->name) + 1));
	          strcpy(name, pt->name);
            elem->id_name= name;
            //copy field (always null)
            elem->head=pt->head;
            break;
      }

      if(sym->head==NULL)
      {
          sym->head=new_field;
      }
      else
      {
          new_field->next=sym->head;
          sym->head=new_field;
      }
      pt=(Symbol *)pt->next;
  }
  return sym;
}

void array_insert_dim(int dim,Type *_type) // add a dim to a array
{
  int * new_dim=(int*)malloc(sizeof(int)*(_type->array_size+1));
  for(int i=0;i<_type->array_size;i++)
  {
    new_dim[i]=_type->array_dims[i];
  }
  new_dim[_type->array_size]=dim;
  free(_type->array_dims);
  _type->array_dims=new_dim;
  _type->array_size++;
}

//TABLE (val not defined)
int whether_struct_defined(Type *_type)
{
  for(int index=tables.top;index>=0;index--)
  {
      Sym_table * pt=&(tables.tables[index]);
      Symbol * ps=pt->symbols;
      while(ps!=NULL)
      {
         if(ps->type==Struct &&strcmp(ps->struct_name,_type->struct_name)==0)
         {
            return 1;
         }
         ps=ps->next;
      }
  }
  printf("Error type 17 at Line %d: Undefined structure %s.\n",_type->line,_type->struct_name);
  return 0;
}

int check_whether_defined(Type * temp_type,int thought_type)
{
  //from top to bottom
 // printf("check_not_defined\n");
  if(temp_type->type==Functions&&strcmp(temp_type->id_name,"main")==0)
  {
      return 1;
  }
  /////////////////////////
  int read_paramete_once=0;
  char * local_namespace=(char *)malloc(sizeof(top(&tables)->namespace)+1);
  strcpy(local_namespace,tables.tables[tables.top].namespace);
  //////////////
  for(int index=tables.top;index>=0;index--)
  {
      Sym_table * pt=&(tables.tables[index]);
      Symbol * ps=pt->symbols;
      while(ps!=NULL)
      {
          if(strcmp(ps->name,temp_type->id_name)==0)
          {
              temp_type->type=ps->type;
              temp_type->val_type=ps->var_type;
              // temp_type->line=ps->line;// we don't need define line
              //for struct variable
              if(ps->type==Struct ||ps->type==Struct_variable)
              {
                temp_type->struct_name=(char*)malloc(sizeof(ps->struct_name)+1);
                strcpy(temp_type->struct_name,ps->struct_name);
              }
              else if(ps->type==Functions)//parameters
              {
                //return type
                temp_type->return_type=(Type*)malloc(sizeof(Type));
                copy_type(temp_type->return_type,ps->function_return_type);
                /*
                Type * pt=ps->function_parameters_type;
                while(pt!=NULL)
                {
                    Type * new_para=copy_type(pt);
                    if(temp_type->paras==NULL)
                    {
                      temp_type->paras=new_para;
                    }
                    else
                    {
                       new_para->paras=temp_type->paras;
                       temp_type->paras=new_para;
                    }
                  pt=pt->paras;
                } */
              }
              else if(ps->type==Array)
              {
                if(ps->struct_name!=NULL)
                {
                  temp_type->struct_name=(char*)malloc(sizeof(ps->struct_name)+1);
                  strcpy(temp_type->struct_name,ps->struct_name);
                }
                if(temp_type->array_size==0)
                           temp_type->array_size=ps->array_dim;
              }

              return 1;
          }
          if(strcmp(ps->name,"main")!=0&&
              ps->type==Functions&&
              read_paramete_once==0
            )
          {
            read_paramete_once=1;
            Type * fun_pt=ps->function_parameters_type;
            while(fun_pt!=NULL)
            {
              if(strcmp(fun_pt->id_name,temp_type->id_name)==0)
              {    
                  temp_type->type=fun_pt->type;
                  temp_type->val_type=fun_pt->val_type;
                  temp_type->array_size=fun_pt->array_size;
                  if(fun_pt->type==Struct_variable)
                  {
                    temp_type->struct_name=(char *)malloc(sizeof(fun_pt->struct_name)+1);
                    strcmp(temp_type->struct_name,fun_pt->struct_name);
                  }
                  return 1; 
              }
              fun_pt=fun_pt->paras;
            }
          }
          ps=ps->next;
      }
  }
  if(thought_type==Variables)
  {
    printf("Error type 1 at Line %d: Undefined variable %s.\n",temp_type->line,temp_type->id_name);
  }
  else if(thought_type==Functions)
    printf("Error type 2 at Line %d: Undefined function %s.\n",temp_type->line,temp_type->id_name);
  else if(thought_type==Array)
    printf("Error type 2 at Line %d: Undefined Array %s.\n",temp_type->line,temp_type->id_name);
  free(local_namespace);
  return 0;
}

int check_whether_arr(Type*_type)
{
    if(_type->type!=Array)
    {
      printf("Error type 10 at Line %d: %s is not an array.\n",_type->line,_type->id_name);
      return 0;
    }
    return 1;
}

int check_whether_func(Type*_type)
{
  if(_type->type!=Functions)
    {
      printf("Error type 11 at Line %d: %s  is not a function.\n",_type->line,_type->id_name);
      return 0;
    }
    return 1;
}

int check_whether_index(Type *index)
{
  if(index->type==Variables&&index->val_type==Type_Int)
        return 1;
  if(index->type==Normal&&index->val_type==Type_Int)
        return 1;
  printf("Error type 12 at Line %d: %f is not an integer.\n",index->line,index->value.float_val);
  return 0;
}

int check_function_match(Type * _type)
{
  //printf("check_function_match\n");
  if(_type->type==Functions&&strcmp(_type->id_name,"main")==0)
  {
      return 0;
  }
  Symbol *tar=NULL;int is_found=0;
  for(int index=tables.top;index>=0;index--)
  {
      Sym_table * pt=&(tables.tables[index]);
      Symbol * ps=pt->symbols;
      while(ps!=NULL)
      {
          if(strcmp(ps->name,_type->id_name)==0&&_type->type==ps->type)
          {
              is_found=1;
              tar=ps;
              break;
          }
          ps=ps->next;
      }
      if(is_found)break;
  }
  if(tar->function_parameters_number!=_type->func_paras_num)
  {
    //printf("number not match\n");
    print_func_meter_error(tar,_type);

    return 0;
  }
  Type * standard_para=tar->function_parameters_type;
  Type * real_para=_type->paras;
  while(standard_para!=NULL) //only have var and struct
  { 
      if(standard_para->type==Variables)
      { 
        if(standard_para->val_type==Type_Float)
        {
              if(!((real_para->type==Variables||real_para->type==Normal)&&real_para->val_type==Type_Float))
              {
                print_func_meter_error(tar,_type);
                return 0;
              }

        }
        else if(standard_para->val_type==Type_Int)
        {
              if(!((real_para->type==Variables||real_para->type==Normal)&&real_para->val_type==Type_Int))
              {
                print_func_meter_error(tar,_type);
                return 0;
              }
        }
      }
      else if(standard_para->type==Struct_variable)
      {
          if(!(real_para->type==Struct_variable&&strcmp(real_para->struct_name,standard_para->struct_name)==0))
          {
            print_func_meter_error(tar,_type);
            return 0;
          }
      }
      standard_para=standard_para->paras;
      real_para=real_para->paras;
  }
  return 1;
}
/*
Error type 9 at Line 8: Function "func(int)" is not applicable for arguments 
"(int, int)".
*/
void print_func_meter_error(Symbol * tar,Type *type2)
{
  printf("Error type 9 at Line %d:Function %s(",type2->line,tar->name);
  //print standard para
  Type * pt=tar->function_parameters_type;
  while(pt!=NULL)
  {

      if(pt->type==Variables&&pt->val_type==Type_Int)
      {
          printf("int,");
      }
      else if(pt->type==Variables&&pt->val_type==Type_Float)
      {
          printf("float,");
      }
      else if(pt->type==Struct)
      {
        printf("Struct %s,",pt->id_name);
      }
      pt=pt->paras;
  }
  printf(") is not applicable for arguments (");
  pt=type2->paras;
  while(pt!=NULL)
  {
      if((pt->type==Variables||pt->type==Normal)&&pt->val_type==Type_Int)
      {
          printf("int,");
      }
      else if((pt->type==Variables||pt->type==Normal)&&pt->val_type==Type_Float)
      {
          printf("float,");
      }
      else if(pt->type==Struct)
      {
        printf("Struct %s,",pt->id_name);
      }
      pt=pt->paras;
  }
  printf(").\n");
}

int check_struct_re_defined(Type * _type)
{
      //printf("check_struct_re_defined\n");
      //printf("THe struct's name %s\n",_type->struct_name);
      Sym_table * pt=&(tables.tables[tables.top]);
      Symbol * ps=pt->symbols;
      while(ps!=NULL)
      {
        if((ps->type==Variables)&&strcmp(ps->name,_type->struct_name)==0)
        { 
            printf("Error type 16 at Line %d: Duplicated name %s.\n",_type->line,_type->struct_name);
            return 0;
        }
        else if((ps->type==Struct)&&strcmp(ps->struct_name,_type->struct_name)==0)
        {
          printf("Error type 16 at Line %d: Duplicated name %s.\n",_type->line,_type->struct_name);
          return 0;
        }
        ps=ps->next;
      }
      return 1;
}

//table Redefined
int check_re_defined(Type * temp_type)
{
      //printf("check_re_defined\n");
      //printf("The search is %s\n",temp_type->id_name);
      Sym_table * pt=&(tables.tables[tables.top]);
      Symbol * ps=pt->symbols;
      while(ps!=NULL)
      {
          if(temp_type->type==Variables)
          {
            if(((ps->type==Variables)||(ps->type==Struct))&&strcmp(ps->name,temp_type->id_name)==0)
            {
              if(is_in_struct)
              {
                printf("Error type 15 at Line %d: Redefined field %s.\n",temp_type->line,temp_type->id_name);
              }
              else
              {
                printf("Error type 3 at Line %d: Redefined variable %s\n",temp_type->line,temp_type->id_name);
              }
              return 0;
            }
          }
          else if(temp_type->type==Functions)
          {
            if(ps->type==Functions&&strcmp(ps->name,temp_type->id_name)==0)
            {
              if(is_in_struct)
              {
                printf("Error type 15 at Line %d: Redefined field %s.\n",temp_type->line,temp_type->id_name);
              }
              else
              {
                printf("Error type 4 at Line %d: Redefined function %s\n",temp_type->line,temp_type->id_name);
              }
              return 0;
            }
          }
          else if(temp_type->type==Struct_variable)
          {
              if((ps->type==Variables)&&strcmp(ps->name,temp_type->id_name)==0)
              {
                if(is_in_struct)
                {
                  printf("Error type 15 at Line %d: Redefined field %s.\n",temp_type->line,temp_type->id_name);
                }
                else
                {
                  printf("Error type 3 at Line %d: Redefined variable %s\n",temp_type->line,temp_type->id_name);
                }       
                return 0;
              }
              if((ps->type==Struct)&&strcmp(ps->struct_name,temp_type->id_name)==0)
              {
                if(is_in_struct)
                {
                  printf("Error type 15 at Line %d: Redefined field %s.\n",temp_type->line,temp_type->id_name);
                }
                else
                {
                  printf("Error type 3 at Line %d: Redefined variable %s\n",temp_type->line,temp_type->id_name);
                } 
                  return 0;
              }
          }
          ps=ps->next;
      }
  return 1;
}

void is_return_type_match(Type *temp_type)
{
  //printf("is_return_type_match\n");
  for(int index=tables.top;index>=0;index--)
  {
        Sym_table * pt=&(tables.tables[index]);
        Symbol * ps=pt->symbols;
        while(ps!=NULL)
        {
          if(ps->type==Functions)
          {
            if(ps->function_return_type->type==Variables)
            {
              if(temp_type->type==Variables&&temp_type->val_type==ps->function_return_type->val_type)
                  return;
              else if(temp_type->type==Normal&&ps->function_return_type->val_type==Type_Int)
                  return;
              else
              {
                  printf("Error type 8 at Line %d: Type mismatched for return.\n",temp_type->line);
                  return; 
              } 
            }
            else if(ps->function_return_type->type==Struct)
            {

            }
            break;
          }
          ps=ps->next;
        }
    }
  return;
}

int operands_whether_same_type(Type* before,Type*after)
{
  //printf("operands_whether_same_type\n");
  if(before->type==Unknown||after->type==Unknown)
    return 0;
  else if((before->type==Variables||before->type==Normal)&&(after->type==Variables||after->type==Normal))
  {
      if(before->val_type!=after->val_type)
      {
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",before->line);
        return 0;
      }
  }
  else if(before->type!=after->type)
  {
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",before->line);
        return 0;
  }
  else if(before->type==Array||after->type==Array)
  {
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",before->line);
        return 0;
  }
  else if(before->type==Struct_variable||after->type==Struct_variable)
  {
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",before->line);
        return 0;
  }
  else if(before->type==Functions||after->type==Functions)
  {
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",before->line);
        return 0;
  }
   else if(before->type==Struct||after->type==Struct)
  {
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",before->line);
        return 0;
  }
  return 1;
}

int check_dot_match(Type*before,Type *after)
{
  if(before->type!=Struct_variable)
  {
    printf("Error type 13 at Line %d: Illegal use of . .\n",before->line);
    return 0;
  }
  
  //whether has the field
  for(int index=tables.top;index>=0;index--)
  {
      Sym_table * pt=&(tables.tables[index]);
      Symbol * ps=pt->symbols;
      while(ps!=NULL)
      {
         if(ps->type==Struct &&strcmp(ps->struct_name,before->struct_name)==0)
         {
            Fieldlist *begin=ps->head;
            while(begin!=NULL)
            {
               Type * elem=begin->element;
               if(strcmp(elem->id_name,after->id_name)==0)
               {
                  after->type=elem->type;
                  after->val_type=elem->val_type;
                  after->line=elem->line;
                  if(elem->type==Array)
                  {
                    after->array_size=elem->array_size;
                  }
                  else if(elem->type==Struct_variable)
                  {
                    after->struct_name=(char *)malloc(sizeof(elem->struct_name)+1);
                    assert(elem->struct_name!=NULL);
                    strcpy(after->struct_name,elem->struct_name);
                  }
                  return 1;
               }
               begin=begin->next;
            }
         }
         ps=ps->next;
      }
  }
  printf("Error type 14 at Line %d: Non-existent field %s.\n",before->line,after->id_name);
  return 0 ;


}

int whether_is_variable_or_normal(Type * _type)
{
  if(_type->type==Variables||_type->type==Normal)
  {
      return 1;
  }
  printf("Error type 7 at Line %d: Type mismatched for operands.\n",_type->line);
  return 0;
}

void whether_same_type(Type* before,Type*after)
{
  //printf("whether_same_type and before normal\n");
  //1
  if(before->type==Normal)
  {
    printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n",before->line);
    return;
  }
  //2
  if(before->type==Unknown||after->type==Unknown)
    return;

  //3
  if(before->type==Variables&&after->type==Variables)
  {
    if(before->val_type!=after->val_type)
    {
      printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
      return;
    }
  }
  else if(before->type==Variables&&after->type==Functions)
  {
    whether_same_type(before,after->return_type);
    return;
  }
  else if(before->type==Variables&&after->type==Array)
  {
    if(before->val_type==after->val_type&&after->array_size==0)
    {
      
      return;
    }
    printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
    return;
  }
  else if(before->type==Variables&&after->type==Normal)
  {
    if(before->val_type!=after->val_type)
    {
      printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
      return;
    }
    return;
  }
  else if(before->type==Struct_variable&&after->type==Struct_variable)
  {
    if(strcmp(before->struct_name,after->struct_name)!=0)
    {
      printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
    }
    return;
  }
  else if(before->type==Struct_variable&&after->type==Functions)
  {
    whether_same_type(before,after->return_type);
    return;
  }
  else if(before->type==Array&&after->type==Array)
  {
    if(before->array_size!=after->array_size)
    {
        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
        return;
    }
    else if(before->struct_name!=NULL&&after->struct_name!=NULL)
    {
      
      if(strcmp(before->struct_name,after->struct_name)==0)
        return;
      else
      {
        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
        return;
      }
    }
    else if(before->struct_name!=NULL||after->struct_name!=NULL)
    {
      printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
      return;
    }
    else
    {
      if(before->val_type!=after->val_type)
      {
        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
        return;
      }
    }
    return;
  }
  else if(before->type==Array&&after->type==Variables)
  {

    if(before->val_type!=after->val_type||before->array_size!=0)
    {
      printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
      return;
    }
    return;
  }
  else if(before->type==Array&&after->type==Normal)
  {
    if(before->val_type!=after->val_type||before->array_size!=0)
    {
      printf("Error type 5 at Line %d: Type mismatched for assignment.\n",before->line);
      return;
    }
    return;
  }
  else if(before->type==Array&&after->type==Functions)
  {
     whether_same_type(before,after->return_type);
     return;
  }
  //continue add
}

//table stack
void push(Table_Stack * ts)
{
    if(ts->top+1<ts->max_num)
    {
        ts->top++;
    }
}
void pop(Table_Stack * ts)
{
  //printf("begin pop\n");
  if(ts->top>0)
  {
    Symbol *pt=ts->tables[ts->top].symbols;
    while(pt!=NULL)
    {
      Symbol *free_temp=pt;
      pt=pt->next;
      free(free_temp);
    }
    ts->tables[ts->top].symbols=NULL;

    ts->tables[ts->top].symbol_num=0;

    free(ts->tables[ts->top].namespace);
    ts->tables[ts->top].namespace=NULL;

    ts->top--;
  }
  //printf("end pop\n");
}
Sym_table* top(Table_Stack * ts)
{
  return &(ts->tables[ts->top]);
}

void Add_symbol_table(Type *_type)
{
  push(&tables);
  tables.tables[tables.top].symbols=NULL;
  tables.tables[tables.top].symbol_num=0;
  tables.tables[tables.top].namespace=(char *)malloc(sizeof(_type->id_name)+1);
  strcpy(tables.tables[tables.top].namespace,_type->id_name);
  current_symtable=&(tables.tables[tables.top]);
}
void Delete_current_table()
{
  //printf("Delete_current_table\n");
  pop(&tables);
  current_symtable=&(tables.tables[tables.top]);
}