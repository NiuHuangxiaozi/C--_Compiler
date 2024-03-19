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
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -20($fp)
addi $sp, $sp, -4
lw $t0, -20($fp)
sw $t0, -24($fp)
addi $sp, $sp, -4
lw $t1, -16($fp)
lw $t0, -16($fp)
mul $t2, $t0, $t1
sw $t2, -28($fp)
addi $sp, $sp, -4
li $t0, 4
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t1, -8($fp)
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -36($fp)
addi $sp, $sp, -4
lw $t1, -24($fp)
lw $t0, -36($fp)
mul $t2, $t0, $t1
sw $t2, -40($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
lw $t1, -40($fp)
sub $t2, $t0, $t1
sw $t2, -44($fp)
addi $sp, $sp, -4
lw $t0, -44($fp)
sw $t0, -48($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -52($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -56($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, -52($fp)
sub $t2, $t0, $t1
sw $t2, -60($fp)
lw $t0, -60($fp)
li $t1, 0
bgt $t0, $t1, label2
li $t0, 0
sw $t0, -56($fp)
label2:
lw $t0, -56($fp)
li $t1, 0
beq $t0, $t1, label1
addi $sp, $sp, -4
li $t0, 2
sw $t0, -64($fp)
lw $a0, -64($fp)
move $sp, $fp
addi $sp, $sp, -64
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
j label3
label1:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -68($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -72($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, -68($fp)
sub $t2, $t0, $t1
sw $t2, -76($fp)
lw $t0, -76($fp)
li $t1, 0
beq $t0, $t1, label5
li $t0, 0
sw $t0, -72($fp)
label5:
lw $t0, -72($fp)
li $t1, 0
beq $t0, $t1, label4
addi $sp, $sp, -4
li $t0, 1
sw $t0, -80($fp)
lw $a0, -80($fp)
move $sp, $fp
addi $sp, $sp, -80
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
j label6
label4:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -84($fp)
lw $a0, -84($fp)
move $sp, $fp
addi $sp, $sp, -84
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
label6:
label3:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -88($fp)
lw $v0, -88($fp)
move $sp, $fp
jr $ra
