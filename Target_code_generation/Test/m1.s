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
addi $sp, $sp, -4
li $t0, 0
sw $t0, -12($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -16($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -12($fp)
sub $t2, $t0, $t1
sw $t2, -20($fp)
lw $t0, -20($fp)
li $t1, 0
bgt $t0, $t1, label2
li $t0, 0
sw $t0, -16($fp)
label2:
lw $t0, -16($fp)
li $t1, 0
beq $t0, $t1, label1
addi $sp, $sp, -4
li $t0, 1
sw $t0, -24($fp)
lw $a0, -24($fp)
move $sp, $fp
addi $sp, $sp, -24
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
j label3
label1:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -28($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -28($fp)
sub $t2, $t0, $t1
sw $t2, -36($fp)
lw $t0, -36($fp)
li $t1, 0
blt $t0, $t1, label5
li $t0, 0
sw $t0, -32($fp)
label5:
lw $t0, -32($fp)
li $t1, 0
beq $t0, $t1, label4
addi $sp, $sp, -4
li $t0, 1
sw $t0, -40($fp)
addi $sp, $sp, -4
li $t0, 0
lw $t1, -40($fp)
sub $t2, $t0, $t1
sw $t2, -44($fp)
lw $a0, -44($fp)
move $sp, $fp
addi $sp, $sp, -44
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
j label6
label4:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -48($fp)
lw $a0, -48($fp)
move $sp, $fp
addi $sp, $sp, -48
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
label6:
label3:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -52($fp)
lw $v0, -52($fp)
move $sp, $fp
jr $ra
