#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define Unknown 0
#define Functions 1
#define Variables 2
#define Array 3
#define Struct 4
#define Struct_variable 5
#define Normal 6

#define Type_Int 0
#define Type_Float 1

typedef struct mytype  Type;

typedef struct fieldlist
{
  Type * element;
  struct fieldlist *next;
}Fieldlist;


struct mytype
{
  int type;  // function or variable or array
  int val_type; //0 means int 1 means float [ val: value ,array:element's type] 
  char* id_name; // if function ,function's name if var ,var's name
  int * array_dims; //use for array
  int array_size; //array's dim
  union val
  {
    int int_val;
    float float_val;
  }value;
  int line; // hanghao

  int is_parameter; //analyze whether a parameter
  int func_paras_num; //parameter's num
  struct mytype  *paras; //parameters
  struct mytype  *return_type; //function's return 

  //STRUCT
  char * struct_name;
  Fieldlist * head; 
};
//semantic analyze

//define symbol
typedef struct
{
  char* name;// symbol'name
  int type;
  int var_type; //int or float
  int array_dim; // array's dim
  union sym_val {
        int i;
        float f;
  }value;

  Type *function_return_type;
  int function_parameters_number;
  Type * function_parameters_type;
  int line;

  //STRUCT
  char * struct_name;
  Fieldlist * head; 

  struct Symbol * next; //next symbol
} Symbol;

//define symbol table
typedef struct 
{
  char * namespace;// like std
  int symbol_num;
  Symbol * symbols;
}Sym_table;


typedef struct
{
  int max_num;
  int top;
  Sym_table tables[10];
}Table_Stack;





//aux func
void set_in_struct();
void set_out_struct();
void copy_type(Type *answer,Type * _type);
void print_func_arguments(Type *_type);
void inverse_parameters(Type *_type);

//type 
void initial_type(Type * _type);
void add_function_parameters(Type*_type,Type*para_type); //function add a parameter
//initial
void initial_symbol_tables();

//table
Symbol * create_symbol(Type *_type);
int insert_table(Symbol * sym);
void array_insert_dim(int dim,Type *_type);
Symbol * create_struct_symbol(Type*_type);





//table check
int check_whether_defined(Type * temp_type,int thought_type);
int check_re_defined(Type * temp_type);
int check_struct_re_defined(Type * _type);
void is_return_type_match(Type *temp_type);
void whether_same_type(Type * before,Type * after);
int operands_whether_same_type(Type* before,Type*after);
int check_function_match(Type * _type);
void print_func_meter_error(Symbol * tar,Type *type2);
int check_whether_arr(Type*_type);
int check_whether_func(Type *_type);
int check_whether_index(Type *index);
int whether_struct_defined(Type *_type);
int check_dot_match(Type*before,Type *after);
int whether_is_variable_or_normal(Type * _type);




//tables
void push(Table_Stack * ts);
void pop(Table_Stack * ts);
Sym_table* top(Table_Stack * ts);
void Add_symbol_table(Type *_type);
void Delete_current_table();


//
void print_current_table(int index);



