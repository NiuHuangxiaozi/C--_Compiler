.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text

read:
li $v0, 4
la $a0, _prompt
syscall
li $v0, 5
syscall
jr $ra

write:
li $v0, 1
syscall
li $v0, 4
la $a0, _ret
syscall
move $v0, $0
jr $ra

factorial:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -8($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
sw $t0, -12($fp)
label1:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -16($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -20($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -16($fp)
sub $t2, $t0, $t1
sw $t2, -24($fp)
lw $t0, -24($fp)
li $t1, 0
bgt $t0, $t1, label3
li $t0, 0
sw $t0, -20($fp)
label3:
lw $t0, -20($fp)
li $t1, 0
beq $t0, $t1, label2
addi $sp, $sp, -4
lw $t1, -4($fp)
lw $t0, -12($fp)
mul $t2, $t0, $t1
sw $t2, -28($fp)
lw $t0, -28($fp)
sw $t0, -12($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -32($fp)
sub $t2, $t0, $t1
sw $t2, -36($fp)
lw $t0, -36($fp)
sw $t0, -4($fp)
j label1
label2:
lw $v0, -12($fp)
move $sp, $fp
jr $ra

cal_combiniation:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
move $sp, $fp
addi $sp, $sp, -8
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal factorial
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -12($fp)
move $sp, $fp
addi $sp, $sp, -12
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal factorial
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -16($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -20($fp)
move $sp, $fp
addi $sp, $sp, -20
lw $t0, -20($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal factorial
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -24($fp)
addi $sp, $sp, -4
lw $t1, -24($fp)
lw $t0, -16($fp)
mul $t2, $t0, $t1
sw $t2, -28($fp)
addi $sp, $sp, -4
lw $t1, -28($fp)
lw $t0, -12($fp)
div $t0, $t1
mflo $t2
sw $t2, -32($fp)
lw $v0, -32($fp)
move $sp, $fp
jr $ra

cal_permutation:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
move $sp, $fp
addi $sp, $sp, -8
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal factorial
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -12($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -16($fp)
move $sp, $fp
addi $sp, $sp, -16
lw $t0, -16($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal factorial
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -20($fp)
addi $sp, $sp, -4
lw $t1, -20($fp)
lw $t0, -12($fp)
div $t0, $t1
mflo $t2
sw $t2, -24($fp)
lw $v0, -24($fp)
move $sp, $fp
jr $ra

main:
move $fp, $sp
move $sp, $fp
addi $sp, $sp, 0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -4($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
sw $t0, -8($fp)
move $sp, $fp
addi $sp, $sp, -8
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -12($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
sw $t0, -16($fp)
move $sp, $fp
addi $sp, $sp, -16
lw $t0, -16($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal cal_combiniation
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 8
addi $sp, $sp, -4
sw $v0, -20($fp)
lw $a0, -20($fp)
move $sp, $fp
addi $sp, $sp, -20
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
move $sp, $fp
addi $sp, $sp, -20
lw $t0, -16($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal cal_permutation
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 8
addi $sp, $sp, -4
sw $v0, -24($fp)
lw $a0, -24($fp)
move $sp, $fp
addi $sp, $sp, -24
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -28($fp)
lw $v0, -28($fp)
move $sp, $fp
jr $ra
