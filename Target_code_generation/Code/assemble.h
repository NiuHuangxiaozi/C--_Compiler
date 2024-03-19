//
// Created by niu on 23-5-22.
//
#ifndef LAB4_ASSEMBLE_H
#define LAB4_ASSEMBLE_H
#include "ir.h"
#include "stdbool.h"
#define ESTIMATE_MAX_LABEL 10001
#define MAX_depth 1000

//-1说明变量的offset还没有分配
typedef struct Global_offset  // t1-t1001
{
    int arg_num;//当前函数的实参个数
    int cur_activity_offset;//相比于fp
    int param_offset;//解析函数参数的时候输入函数的参数相对于fp的偏移量，第一个参数是+8
    int offsets[ESTIMATE_MAX_LABEL];
} GOset;

typedef struct Offset_stack
{
    int s[MAX_depth];//栈
    int top;//栈顶
}off_stack;

void initial_Offset_stack();//初始化相应的栈
bool is_empty();//栈是否为空
bool fppush(int old_offset);
int fppop();



void initialize_Goset();//初始化全局偏移量
bool has_offset(int var_label);//判断对应的偏移量存不存在

void set_offset(int var_label,int new_offset);//设置对应的偏移量
int get_offset(int var_label);//获得相应的偏移量
void cur_offset_dec(int offset);//当前偏移量再减offset
void cur_offset_reset();//当前偏移量重置为0
void arg_num_inc();//实参个数增加
void arg_num_reset();//实参重置为0

void print_initial_message(FILE* dest);//打印开始的辅助函数和段的分配

//assemble analysis one ir
void print_single_assemble(struct IR* ir, FILE* dest);

//all assemble analysis
void output_all_assemble(char * filename);

void Assign_offset_and_renew_offset(FILE *dest,struct IR* ir,int label_index);




#endif //LAB4_ASSEMBLE_H
