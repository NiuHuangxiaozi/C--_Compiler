//
// Created by niu on 23-5-22.
//
#include <stdio.h>
#include "assemble.h"
#include "assert.h"
//IR的线性表示
extern struct IR* ir_head;
extern struct IR* ir_tail;

//全局符号的偏移量
GOset var_offsets;
off_stack fp_offset;

//初始化全局偏移量
void initialize_Goset()
{
    //-1说明变量的offset还没有分配
    for(int index=1;index<ESTIMATE_MAX_LABEL;index++)
    {
        var_offsets.offsets[index]=-1;
    }
    var_offsets.cur_activity_offset=0;
    var_offsets.arg_num=0;
    var_offsets.param_offset=4;
}


void Assign_offset_and_renew_offset(FILE *dest,struct IR* ir,int label_index)
{;
    if(!has_offset(label_index))//保存了
    {
        if(ir->kind==DEC_T)
        {
            fprintf(dest, "addi $sp, $sp, %d\n",-ir->info.dec.size);
            cur_offset_dec(ir->info.dec.size);
            set_offset(label_index, var_offsets.cur_activity_offset);
        }
        else
        {
            fprintf(dest, "addi $sp, $sp, -4\n");
            cur_offset_dec(4);
            set_offset(label_index, var_offsets.cur_activity_offset);
        }
    }
}
void cur_offset_dec(int offset)
{
    assert(offset%4==0);
    var_offsets.cur_activity_offset=var_offsets.cur_activity_offset-offset;
}
void cur_offset_reset()
{
    var_offsets.cur_activity_offset=0;
}
void arg_num_inc()
{
    var_offsets.arg_num=var_offsets.arg_num+1;
}
void arg_num_reset()
{
    var_offsets.arg_num=0;
}
//判断对应的偏移量存不存在
bool has_offset(int var_label)
{
    if(var_label<1 ||var_label>1000)
    {
        printf("varable label out of max label : %d\n",var_label);
        assert(false);
    }
    if(var_offsets.offsets[var_label]==-1)
        return false;
    else
        return true;
}
void set_offset(int var_label,int new_offset)//设置对应的偏移量
{
    var_offsets.offsets[var_label]=new_offset;
}
int get_offset(int var_label)//获得相应的偏移量
{
    if(var_label<1 ||var_label>1000)
    {
        printf("varable label out of max label\n");
        assert(false);
    }
    return var_offsets.offsets[var_label];
}



//offset 的栈
void initial_Offset_stack()
{
    for(int i=0;i<MAX_depth;i++)
        fp_offset.s[i]=0;
    fp_offset.top=-1;
};
bool is_empty()//栈是否为空
{
    return fp_offset.top==-1;
}

bool fppush(int old_offset)
{
    assert(fp_offset.top<MAX_depth-1);
    assert(fp_offset.top>-2);
    fp_offset.top++;
    fp_offset.s[fp_offset.top]=old_offset;
    return true;
}
int fppop()
{
    if(is_empty())
    {
        assert(false);
        return 0;
    }
    else
    {
        fp_offset.top--;
        return fp_offset.s[fp_offset.top+1];
    }
}






















void print_initial_message(FILE* dest)
{
    fprintf(dest, ".data\n");
    fprintf(dest, "_prompt: .asciiz \"Enter an integer:\"\n");
    fprintf(dest, "_ret: .asciiz \"\\n\"\n");
    fprintf(dest, ".globl main\n");
    fprintf(dest, ".text\n");

    fprintf(dest, "\n");
    fprintf(dest, "read:\n");
    fprintf(dest, "li $v0, 4\n");
    fprintf(dest, "la $a0, _prompt\n");
    fprintf(dest, "syscall\n");
    fprintf(dest, "li $v0, 5\n");
    fprintf(dest, "syscall\n");
    fprintf(dest, "jr $ra\n");

    fprintf(dest, "\n");
    fprintf(dest, "write:\n");
    fprintf(dest, "li $v0, 1\n");
    fprintf(dest, "syscall\n");
    fprintf(dest, "li $v0, 4\n");
    fprintf(dest, "la $a0, _ret\n");
    fprintf(dest, "syscall\n");
    fprintf(dest, "move $v0, $0\n");
    fprintf(dest, "jr $ra\n");
}

//打印目标代码
void print_single_assemble(struct IR* ir, FILE* dest)
        {
    //printf("It's a ir\n");
    int left_offset;
    int var_offset;
    int right_offset;
    int result_offset;
    int op1_offset;
    int op2_offset;
    int arg_offset;
    int receive_offset;
    int para_offset;

    switch (ir->kind) {
        case FUNC_T://
            fprintf(dest, "\n");//新的函数
            fprintf(dest, "%s:\n", ir->info.id);//打印函数标号
            fprintf(dest, "move $fp, $sp\n");//新的帧
            fppush(var_offsets.cur_activity_offset);
            cur_offset_reset();
            break;
        case LABEL_T://
            fprintf(dest, "label%d:\n", ir->info.label_no);
            break;
        case ASSIGN_T://
            if (ir->info.assign.right.kind == CONSTANT)
            {
                //看一下全局数组有无保存,没保存先分配偏移量
                Assign_offset_and_renew_offset(dest,ir,ir->info.assign.left.val.var_no);
                //获取偏移
                int var_offset=get_offset(ir->info.assign.left.val.var_no);
                //将常数存进t0寄存器
                fprintf(dest, "li $t0, %d\n",ir->info.assign.right.val.value);
                //将t0寄存器的值存进内存
                fprintf(dest, "sw $t0, %d($fp)\n",var_offset);
            }
            else
            {
                Assign_offset_and_renew_offset(dest,ir,ir->info.assign.left.val.var_no);
                Assign_offset_and_renew_offset(dest,ir,ir->info.assign.right.val.var_no);

                left_offset=get_offset(ir->info.assign.left.val.var_no);
                right_offset=get_offset(ir->info.assign.right.val.var_no);
                //将t1存进t0寄存器对应内存
                fprintf(dest, "lw $t0, %d($fp)\n",right_offset);
                //将t0寄存器的值存进内存
                fprintf(dest, "sw $t0, %d($fp)\n",left_offset);
            }
            break;
        case ADD_T://
            Assign_offset_and_renew_offset(dest,ir,ir->info.binop.result.val.var_no);
            Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op1.val.var_no);
            Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op2.val.var_no);

            result_offset=get_offset(ir->info.binop.result.val.var_no);
            op1_offset=get_offset(ir->info.binop.op1.val.var_no);
            op2_offset=get_offset(ir->info.binop.op2.val.var_no);

            fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
            fprintf(dest, "lw $t1, %d($fp)\n",op2_offset);
            fprintf(dest, "add $t2, $t0, $t1\n");
            fprintf(dest, "sw $t2, %d($fp)\n",result_offset);

            break;
        case SUB_T://
            if (ir->info.binop.op1.kind != CONSTANT)
            {
                Assign_offset_and_renew_offset(dest,ir,ir->info.binop.result.val.var_no);
                Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op1.val.var_no);
                Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op2.val.var_no);

                result_offset=get_offset(ir->info.binop.result.val.var_no);
                op1_offset=get_offset(ir->info.binop.op1.val.var_no);
                op2_offset=get_offset(ir->info.binop.op2.val.var_no);

                fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
                fprintf(dest, "lw $t1, %d($fp)\n",op2_offset);
                fprintf(dest, "sub $t2, $t0, $t1\n");
                fprintf(dest, "sw $t2, %d($fp)\n",result_offset);
            }
            else
            {

                Assign_offset_and_renew_offset(dest,ir,ir->info.binop.result.val.var_no);
                Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op2.val.var_no);

                result_offset=get_offset(ir->info.binop.result.val.var_no);
                op2_offset=get_offset(ir->info.binop.op2.val.var_no);

                fprintf(dest, "li $t0, %d\n",ir->info.binop.op1.val.value);
                fprintf(dest, "lw $t1, %d($fp)\n",op2_offset);
                fprintf(dest, "sub $t2, $t0, $t1\n");
                fprintf(dest, "sw $t2, %d($fp)\n",result_offset);
            }
            break;
        case MUL_T://
            if (ir->info.binop.op2.kind == CONSTANT)
            {
                Assign_offset_and_renew_offset(dest,ir,ir->info.binop.result.val.var_no);
                Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op1.val.var_no);

                result_offset=get_offset(ir->info.binop.result.val.var_no);
                op1_offset=get_offset(ir->info.binop.op1.val.var_no);

                fprintf(dest, "li $t1, %d\n",ir->info.binop.op2.val.value);
                fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
                fprintf(dest, "mul $t2, $t0, $t1\n");
                fprintf(dest, "sw $t2, %d($fp)\n",result_offset);
            }
            else {
                Assign_offset_and_renew_offset(dest,ir, ir->info.binop.result.val.var_no);
                Assign_offset_and_renew_offset(dest,ir, ir->info.binop.op1.val.var_no);
                Assign_offset_and_renew_offset(dest,ir, ir->info.binop.op2.val.var_no);

                result_offset = get_offset(ir->info.binop.result.val.var_no);
                op1_offset = get_offset(ir->info.binop.op1.val.var_no);
                op2_offset = get_offset(ir->info.binop.op2.val.var_no);

                fprintf(dest, "lw $t1, %d($fp)\n", op2_offset);
                fprintf(dest, "lw $t0, %d($fp)\n", op1_offset);
                fprintf(dest, "mul $t2, $t0, $t1\n");
                fprintf(dest, "sw $t2, %d($fp)\n", result_offset);
            }
            break;
        case DIV_T://
            Assign_offset_and_renew_offset(dest,ir, ir->info.binop.result.val.var_no);
            Assign_offset_and_renew_offset(dest,ir, ir->info.binop.op1.val.var_no);
            Assign_offset_and_renew_offset(dest,ir, ir->info.binop.op2.val.var_no);

            result_offset = get_offset(ir->info.binop.result.val.var_no);
            op1_offset = get_offset(ir->info.binop.op1.val.var_no);
            op2_offset = get_offset(ir->info.binop.op2.val.var_no);

            fprintf(dest, "lw $t1, %d($fp)\n", op2_offset);
            fprintf(dest, "lw $t0, %d($fp)\n", op1_offset);
            fprintf(dest, "div $t0, $t1\n");
            fprintf(dest, "mflo $t2\n");
            fprintf(dest, "sw $t2, %d($fp)\n", result_offset);
            break;
            //not used
        case AND_T:
            fprintf(dest, "t%d := t%d && t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
            //not used
        case OR_T:
            fprintf(dest, "t%d := t%d || t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
            //not used
        case GT_T:
            fprintf(dest, "t%d := t%d > t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
        case LT_T:
            fprintf(dest, "t%d := t%d < t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
            //not used
        case GE_T:
            fprintf(dest, "t%d := t%d >= t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
            //not used
        case LE_T:
            fprintf(dest, "t%d := t%d <= t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
            //not used
        case EQ_T:
            fprintf(dest, "t%d := t%d == t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
            //not used
        case UE_T:
            fprintf(dest, "t%d := t%d != t%d\n", ir->info.binop.result.val.var_no,
                    ir->info.binop.op1.val.var_no, ir->info.binop.op2.val.var_no);
            break;
            //not used
        case NOT_T:
            fprintf(dest, "t%d := ! t%d\n", ir->info.unaryop.result.val.var_no,
                    ir->info.unaryop.op1.val.var_no);
            break;
            //not used
        case NEG_T:
            fprintf(dest, "t%d := - t%d\n", ir->info.unaryop.result.val.var_no,
                    ir->info.unaryop.op1.val.var_no);
            break;

        case GET_ADDR_T://
            if (ir->info.binop.op1.need_get_addr)
            {
                if (ir->info.binop.op2.kind == VARIABLE)
                {
                    Assign_offset_and_renew_offset(dest,ir, ir->info.binop.result.val.var_no);
                    Assign_offset_and_renew_offset(dest,ir, ir->info.binop.op1.val.var_no);
                    Assign_offset_and_renew_offset(dest,ir, ir->info.binop.op2.val.var_no);

                    result_offset = get_offset(ir->info.binop.result.val.var_no);
                    op1_offset = get_offset(ir->info.binop.op1.val.var_no);
                    op2_offset = get_offset(ir->info.binop.op2.val.var_no);

                    fprintf(dest, "move $t0, $fp #t0 := &t1 + t2\n");
                    fprintf(dest, "addi $t0, $t0, %d  #t0 := &t1 + t2\n",op1_offset);
                    fprintf(dest, "lw $t1, %d($fp)  #t0 := &t1 + t2\n", op2_offset);
                    fprintf(dest, "add $t2, $t0, $t1  #t0 := &t1 + t2\n");
                    fprintf(dest, "sw $t2, %d($fp) #t0 := &t1 + t2\n", result_offset);
                }
                else
                {
                    Assign_offset_and_renew_offset(dest,ir, ir->info.binop.result.val.var_no);
                    Assign_offset_and_renew_offset(dest,ir, ir->info.binop.op1.val.var_no);

                    result_offset = get_offset(ir->info.binop.result.val.var_no);
                    op1_offset = get_offset(ir->info.binop.op1.val.var_no);

                    fprintf(dest, "move $t0, $fp  #t0 := &t1 + #d\n");
                    fprintf(dest, "addi $t0, $t0, %d\n",op1_offset);
                    fprintf(dest, "addi $t2, $t0, %d\n",ir->info.binop.op2.val.value);
                    fprintf(dest, "sw $t2, %d($fp)  #t0 := &t1 + #d\n", result_offset);
                }
            }
            else
            {
                if (ir->info.binop.op2.kind == VARIABLE)
                {
                    Assign_offset_and_renew_offset(dest,ir,ir->info.binop.result.val.var_no);
                    Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op1.val.var_no);
                    Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op2.val.var_no);

                    result_offset=get_offset(ir->info.binop.result.val.var_no);
                    op1_offset=get_offset(ir->info.binop.op1.val.var_no);
                    op2_offset=get_offset(ir->info.binop.op2.val.var_no);

                    fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
                    fprintf(dest, "lw $t1, %d($fp)\n",op2_offset);
                    fprintf(dest, "add $t2, $t0, $t1\n");
                    fprintf(dest, "sw $t2, %d($fp)\n",result_offset);
                }
                else
                {
                    Assign_offset_and_renew_offset(dest,ir,ir->info.binop.result.val.var_no);
                    Assign_offset_and_renew_offset(dest,ir,ir->info.binop.op1.val.var_no);

                    result_offset=get_offset(ir->info.binop.result.val.var_no);
                    op1_offset=get_offset(ir->info.binop.op1.val.var_no);

                    fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
                    fprintf(dest, "addi $t2, $t0, %d\n",ir->info.binop.op2.val.value);
                    fprintf(dest, "sw $t2, %d($fp)\n",result_offset);
                }
            }
            break;
        case GET_VAL_T://

            Assign_offset_and_renew_offset(dest,ir,ir->info.unaryop.result.val.var_no);
            Assign_offset_and_renew_offset(dest,ir,ir->info.unaryop.op1.val.var_no);

            result_offset=get_offset(ir->info.unaryop.result.val.var_no);
            op1_offset=get_offset(ir->info.unaryop.op1.val.var_no);

            fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
            fprintf(dest, "lw $t1, 0($t0)\n");
            fprintf(dest, "sw $t1, %d($fp)\n",result_offset);
            break;
        case STORE_T://

            Assign_offset_and_renew_offset(dest,ir,ir->info.unaryop.result.val.var_no);
            Assign_offset_and_renew_offset(dest,ir,ir->info.unaryop.op1.val.var_no);

            result_offset=get_offset(ir->info.unaryop.result.val.var_no);
            op1_offset=get_offset(ir->info.unaryop.op1.val.var_no);

            fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
            fprintf(dest, "lw $t1, %d($fp)\n",result_offset);
            fprintf(dest, "sw $t0, 0($t1)\n");
           break;
        case JMP_T://
            fprintf(dest, "j label%d\n",ir->info.jump.label);
            break;
        case JMPC_T://
            // TODO: different kinds of operators
            //从内存里面加载比较的第一个条件
            Assign_offset_and_renew_offset(dest,ir,ir->info.jumpc.cond);
            op1_offset=get_offset(ir->info.jumpc.cond);
            fprintf(dest, "lw $t0, %d($fp)\n",op1_offset);
            fprintf(dest, "li $t1, %d\n",ir->info.jumpc.expect);

            if (ir->info.jumpc.operator == 0)
                fprintf(dest,"bgt $t0, $t1, label%d\n",ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 1)
                fprintf(dest, "blt $t0, $t1, label%d\n",ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 2)
                fprintf(dest, "bge $t0, $t1, label%d\n",ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 3)
                fprintf(dest, "ble $t0, $t1, label%d\n",ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 4)
                fprintf(dest, "beq $t0, $t1, label%d\n",ir->info.jumpc.label);
            if (ir->info.jumpc.operator == 5)
                fprintf(dest, "bne $t0, $t1, label%d\n",ir->info.jumpc.label);
            break;
        case RETURN_T://
            Assign_offset_and_renew_offset(dest,ir,ir->info.var_no);
            result_offset= get_offset(ir->info.var_no);
            fprintf(dest, "lw $v0, %d($fp)\n",result_offset);
            fprintf(dest, "move $sp, $fp\n");//回收新的帧

            fprintf(dest, "jr $ra\n");
            break;
        case DEC_T://
            Assign_offset_and_renew_offset(dest,ir,ir->info.dec.target);
            break;
        case ARG_T://
            if(var_offsets.arg_num==0)
            {
                fprintf(dest, "move $sp, $fp\n");
                fprintf(dest, "addi $sp, $sp, %d\n",var_offsets.cur_activity_offset);
            }
            arg_num_inc();
            Assign_offset_and_renew_offset(dest,ir,ir->info.var_no);
            arg_offset = get_offset(ir->info.var_no);
            fprintf(dest, "lw $t0, %d($fp)\n", arg_offset);
            fprintf(dest, "addi $sp, $sp, -4\n");
            fprintf(dest, "sw $t0, 0($sp)\n");
            break;
        case ARG_ARRAY_T://存数组首地址在栈中
            arg_num_inc();
            Assign_offset_and_renew_offset(dest,ir,ir->info.var_no);
            arg_offset = get_offset(ir->info.var_no);
            fprintf(dest, "move $t0, $fp\n");
            fprintf(dest, "addi $t0, $t0, %d\n",arg_offset);
            fprintf(dest, "addi $sp, $sp, -4\n");
            fprintf(dest, "sw $t0, 0($sp)\n");                                         
            break;
        case CALL_T://
            //spec
            //fprintf(dest, "move $sp, $fp\n");
            //fprintf(dest, "addi $sp, $sp, %d\n",
                   // var_offsets.cur_activity_offset-var_offsets.arg_num*4);

            fprintf(dest, "addi $sp, $sp, -8\n");
            fprintf(dest, "sw $ra, 0($sp)\n");
            fprintf(dest, "sw $fp, 4($sp)\n");
            fprintf(dest, "jal %s\n",ir->info.call.func);
            fprintf(dest, "lw $ra, 0($sp)\n");
            fprintf(dest, "lw $fp, 4($sp)\n");
            fprintf(dest, "addi $sp, $sp, 8\n");

            //回退所有的实参占用的栈空间
            //cur_offset_dec(-var_offsets.arg_num*4);
            fprintf(dest, "addi $sp, $sp, %d\n",var_offsets.arg_num*4);
            arg_num_reset();

            //将函数的返回值保存进内存
            if(ir->info.call.receive>=1)
            {
                Assign_offset_and_renew_offset(dest, ir, ir->info.call.receive);
                receive_offset = get_offset(ir->info.call.receive);
                fprintf(dest, "sw $v0, %d($fp)\n", receive_offset);
            }
            break;
        case READ_T://
            //spec
            fprintf(dest, "move $sp, $fp\n");
            fprintf(dest, "addi $sp, $sp, %d\n",var_offsets.cur_activity_offset);

            fprintf(dest, "addi $sp, $sp, -4\n");
            fprintf(dest, "sw $ra, 0($sp)\n");
            fprintf(dest, "jal read\n");
            fprintf(dest, "lw $ra, 0($sp)\n");
            fprintf(dest, "addi $sp, $sp, 4\n");

            //将读取的值保存进内存
            Assign_offset_and_renew_offset(dest,ir,ir->info.call.receive);
            receive_offset = get_offset(ir->info.call.receive);
            fprintf(dest, "sw $v0, %d($fp)\n",receive_offset);
            break;
        case WRITE_T://
            //将要写的东西从内存拿到$a0寄存器
            Assign_offset_and_renew_offset(dest,ir,ir->info.call.receive);
            receive_offset = get_offset(ir->info.call.receive);
            fprintf(dest, "lw $a0, %d($fp)\n",receive_offset);

            //spec
            fprintf(dest, "move $sp, $fp\n");
            fprintf(dest, "addi $sp, $sp, %d\n",var_offsets.cur_activity_offset);

            fprintf(dest, "addi $sp, $sp, -4\n");
            fprintf(dest, "sw $ra, 0($sp)\n");
            fprintf(dest, "jal write\n");
            fprintf(dest, "lw $ra, 0($sp)\n");
            fprintf(dest, "addi $sp, $sp, 4\n");

            break;
        case PARAM_T://
            var_offsets.param_offset+=4;
            fprintf(dest, "lw $t0, %d($fp)\n",var_offsets.param_offset);
            Assign_offset_and_renew_offset(dest,ir,ir->info.var_no);
            para_offset = get_offset(ir->info.var_no);
            fprintf(dest, "sw $t0, %d($fp)\n",para_offset);
            if(ir->next->kind!=PARAM_T)//这表明这是最后一个参数
                var_offsets.param_offset=4;
            break;
        default:
            fprintf(dest, "\n");
    }
}

//这个函数循环遍历Irlist，逐句进行翻译
void output_all_assemble(char * filename)
{
    //打开文件
    FILE *dest = fopen(filename, "w");

    initialize_Goset();
    //分段，打印辅助函数
    print_initial_message(dest);

    //获得第一条IR的指针
    struct IR* cur = ir_head->next;
    //循环遍历
    while (cur->kind != TAIL_T)
    {
        //单句进行翻译
        print_single_assemble(cur, dest);
        cur = cur->next;
    }
    fclose(dest);
}