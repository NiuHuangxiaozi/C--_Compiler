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
addi $sp, $sp, -4
li $t0, 0
sw $t0, -4($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
sw $t0, -8($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -12($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
sw $t0, -16($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -20($fp)
addi $sp, $sp, -4
lw $t0, -20($fp)
sw $t0, -24($fp)
move $sp, $fp
addi $sp, $sp, -24
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -28($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
sw $t0, -32($fp)
label1:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -36($fp)
addi $sp, $sp, -4
lw $t0, -24($fp)
lw $t1, -32($fp)
sub $t2, $t0, $t1
sw $t2, -40($fp)
lw $t0, -40($fp)
li $t1, 0
blt $t0, $t1, label3
li $t0, 0
sw $t0, -36($fp)
label3:
lw $t0, -36($fp)
li $t1, 0
beq $t0, $t1, label2
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -16($fp)
add $t2, $t0, $t1
sw $t2, -44($fp)
addi $sp, $sp, -4
lw $t0, -44($fp)
sw $t0, -48($fp)
lw $a0, -16($fp)
move $sp, $fp
addi $sp, $sp, -48
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
lw $t0, -16($fp)
sw $t0, -8($fp)
lw $t0, -48($fp)
sw $t0, -16($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -52($fp)
addi $sp, $sp, -4
lw $t0, -24($fp)
lw $t1, -52($fp)
add $t2, $t0, $t1
sw $t2, -56($fp)
lw $t0, -56($fp)
sw $t0, -24($fp)
j label1
label2:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -60($fp)
lw $v0, -60($fp)
move $sp, $fp
jr $ra
