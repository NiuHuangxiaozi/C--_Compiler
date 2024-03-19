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

isqrt:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -8($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
sw $t0, -12($fp)
label4:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -16($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
lw $t1, -4($fp)
sub $t2, $t0, $t1
sw $t2, -20($fp)
lw $t0, -20($fp)
li $t1, 0
blt $t0, $t1, label6
li $t0, 0
sw $t0, -16($fp)
label6:
lw $t0, -16($fp)
li $t1, 0
beq $t0, $t1, label5
addi $sp, $sp, -4
li $t0, 1
sw $t0, -24($fp)
addi $sp, $sp, -4
lw $t1, -12($fp)
lw $t0, -12($fp)
mul $t2, $t0, $t1
sw $t2, -28($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
lw $t1, -4($fp)
sub $t2, $t0, $t1
sw $t2, -36($fp)
lw $t0, -36($fp)
li $t1, 0
ble $t0, $t1, label9
li $t0, 0
sw $t0, -32($fp)
label9:
lw $t0, -32($fp)
li $t1, 0
bne $t0, $t1, label8
li $t0, 0
sw $t0, -24($fp)
j label10
label8:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -40($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
lw $t1, -40($fp)
add $t2, $t0, $t1
sw $t2, -44($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -48($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
lw $t1, -48($fp)
add $t2, $t0, $t1
sw $t2, -52($fp)
addi $sp, $sp, -4
lw $t1, -52($fp)
lw $t0, -44($fp)
mul $t2, $t0, $t1
sw $t2, -56($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -60($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -4($fp)
sub $t2, $t0, $t1
sw $t2, -64($fp)
lw $t0, -64($fp)
li $t1, 0
bgt $t0, $t1, label11
li $t0, 0
sw $t0, -60($fp)
label11:
lw $t0, -60($fp)
li $t1, 0
bne $t0, $t1, label10
li $t0, 0
sw $t0, -24($fp)
label10:
lw $t0, -24($fp)
li $t1, 0
beq $t0, $t1, label7
lw $v0, -12($fp)
move $sp, $fp
jr $ra
label7:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -68($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
lw $t1, -68($fp)
add $t2, $t0, $t1
sw $t2, -72($fp)
lw $t0, -72($fp)
sw $t0, -12($fp)
j label4
label5:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -76($fp)
addi $sp, $sp, -4
li $t0, 0
lw $t1, -76($fp)
sub $t2, $t0, $t1
sw $t2, -80($fp)
lw $v0, -80($fp)
move $sp, $fp
jr $ra

mod:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -12($fp)
addi $sp, $sp, -4
li $t0, 0
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
blt $t0, $t1, label14
li $t0, 0
sw $t0, -20($fp)
label14:
lw $t0, -20($fp)
li $t1, 0
beq $t0, $t1, label13
li $t0, 1
sw $t0, -12($fp)
j label15
label13:
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
ble $t0, $t1, label16
li $t0, 0
sw $t0, -32($fp)
label16:
lw $t0, -32($fp)
li $t1, 0
beq $t0, $t1, label15
li $t0, 1
sw $t0, -12($fp)
label15:
lw $t0, -12($fp)
li $t1, 0
beq $t0, $t1, label12
addi $sp, $sp, -4
li $t0, 1
sw $t0, -40($fp)
addi $sp, $sp, -4
li $t0, 0
lw $t1, -40($fp)
sub $t2, $t0, $t1
sw $t2, -44($fp)
lw $v0, -44($fp)
move $sp, $fp
jr $ra
j label17
label12:
addi $sp, $sp, -4
lw $t1, -8($fp)
lw $t0, -4($fp)
div $t0, $t1
mflo $t2
sw $t2, -48($fp)
addi $sp, $sp, -4
lw $t1, -8($fp)
lw $t0, -48($fp)
mul $t2, $t0, $t1
sw $t2, -52($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -52($fp)
sub $t2, $t0, $t1
sw $t2, -56($fp)
lw $v0, -56($fp)
move $sp, $fp
jr $ra
label17:

is_prime:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -8($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
sw $t0, -12($fp)
move $sp, $fp
addi $sp, $sp, -12
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal isqrt
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -16($fp)
addi $sp, $sp, -4
lw $t0, -16($fp)
sw $t0, -20($fp)
label18:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -24($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
lw $t1, -20($fp)
sub $t2, $t0, $t1
sw $t2, -28($fp)
lw $t0, -28($fp)
li $t1, 0
ble $t0, $t1, label20
li $t0, 0
sw $t0, -24($fp)
label20:
lw $t0, -24($fp)
li $t1, 0
beq $t0, $t1, label19
move $sp, $fp
addi $sp, $sp, -28
lw $t0, -12($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal mod
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 8
addi $sp, $sp, -4
sw $v0, -32($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -36($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -40($fp)
addi $sp, $sp, -4
lw $t0, -32($fp)
lw $t1, -36($fp)
sub $t2, $t0, $t1
sw $t2, -44($fp)
lw $t0, -44($fp)
li $t1, 0
beq $t0, $t1, label22
li $t0, 0
sw $t0, -40($fp)
label22:
lw $t0, -40($fp)
li $t1, 0
beq $t0, $t1, label21
addi $sp, $sp, -4
li $t0, 0
sw $t0, -48($fp)
lw $v0, -48($fp)
move $sp, $fp
jr $ra
label21:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -52($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
lw $t1, -52($fp)
add $t2, $t0, $t1
sw $t2, -56($fp)
lw $t0, -56($fp)
sw $t0, -12($fp)
j label18
label19:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -60($fp)
lw $v0, -60($fp)
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
addi $sp, $sp, -4
lw $t0, -20($fp)
sw $t0, -24($fp)
move $sp, $fp
addi $sp, $sp, -24
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
sw $v0, -28($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
sw $t0, -32($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -36($fp)
addi $sp, $sp, -4
lw $t0, -36($fp)
sw $t0, -40($fp)
label23:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -44($fp)
addi $sp, $sp, -4
lw $t0, -40($fp)
lw $t1, -24($fp)
sub $t2, $t0, $t1
sw $t2, -48($fp)
lw $t0, -48($fp)
li $t1, 0
ble $t0, $t1, label25
li $t0, 0
sw $t0, -44($fp)
label25:
lw $t0, -44($fp)
li $t1, 0
beq $t0, $t1, label24
move $sp, $fp
addi $sp, $sp, -48
lw $t0, -40($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal is_prime
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -52($fp)
lw $t0, -52($fp)
li $t1, 0
beq $t0, $t1, label26
lw $a0, -40($fp)
move $sp, $fp
addi $sp, $sp, -52
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
label26:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -56($fp)
addi $sp, $sp, -4
lw $t0, -40($fp)
lw $t1, -56($fp)
add $t2, $t0, $t1
sw $t2, -60($fp)
lw $t0, -60($fp)
sw $t0, -40($fp)
j label23
label24:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -64($fp)
lw $t0, -64($fp)
sw $t0, -40($fp)
label27:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -68($fp)
addi $sp, $sp, -4
lw $t0, -40($fp)
lw $t1, -32($fp)
sub $t2, $t0, $t1
sw $t2, -72($fp)
lw $t0, -72($fp)
li $t1, 0
ble $t0, $t1, label29
li $t0, 0
sw $t0, -68($fp)
label29:
lw $t0, -68($fp)
li $t1, 0
beq $t0, $t1, label28
move $sp, $fp
addi $sp, $sp, -72
lw $t0, -40($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal is_prime
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -76($fp)
lw $t0, -76($fp)
li $t1, 0
beq $t0, $t1, label30
lw $a0, -40($fp)
move $sp, $fp
addi $sp, $sp, -76
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
label30:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -80($fp)
addi $sp, $sp, -4
lw $t0, -40($fp)
lw $t1, -80($fp)
add $t2, $t0, $t1
sw $t2, -84($fp)
lw $t0, -84($fp)
sw $t0, -40($fp)
j label27
label28:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -88($fp)
lw $v0, -88($fp)
move $sp, $fp
jr $ra
