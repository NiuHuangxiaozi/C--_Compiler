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

Swap:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
lw $t0, 16($fp)
addi $sp, $sp, -4
sw $t0, -12($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -8($fp)
mul $t2, $t0, $t1
sw $t2, -16($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -16($fp)
add $t2, $t0, $t1
sw $t2, -20($fp)
addi $sp, $sp, -4
lw $t0, -20($fp)
lw $t1, 0($t0)
sw $t1, -24($fp)
addi $sp, $sp, -4
lw $t0, -24($fp)
sw $t0, -28($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -8($fp)
mul $t2, $t0, $t1
sw $t2, -32($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -32($fp)
add $t2, $t0, $t1
sw $t2, -36($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -12($fp)
mul $t2, $t0, $t1
sw $t2, -40($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -40($fp)
add $t2, $t0, $t1
sw $t2, -44($fp)
addi $sp, $sp, -4
lw $t0, -44($fp)
addi $t2, $t0, 0
sw $t2, -48($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, 0($t0)
sw $t1, -52($fp)
addi $sp, $sp, -4
lw $t0, -36($fp)
addi $t2, $t0, 0
sw $t2, -56($fp)
lw $t0, -52($fp)
lw $t1, -56($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -12($fp)
mul $t2, $t0, $t1
sw $t2, -60($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -60($fp)
add $t2, $t0, $t1
sw $t2, -64($fp)
lw $t0, -28($fp)
lw $t1, -64($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -68($fp)
lw $v0, -68($fp)
move $sp, $fp
jr $ra

Partition:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
lw $t0, 16($fp)
addi $sp, $sp, -4
sw $t0, -12($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -8($fp)
mul $t2, $t0, $t1
sw $t2, -16($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -16($fp)
add $t2, $t0, $t1
sw $t2, -20($fp)
addi $sp, $sp, -4
lw $t0, -20($fp)
lw $t1, 0($t0)
sw $t1, -24($fp)
addi $sp, $sp, -4
lw $t0, -24($fp)
sw $t0, -28($fp)
label1:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -12($fp)
sub $t2, $t0, $t1
sw $t2, -36($fp)
lw $t0, -36($fp)
li $t1, 0
blt $t0, $t1, label3
li $t0, 0
sw $t0, -32($fp)
label3:
lw $t0, -32($fp)
li $t1, 0
beq $t0, $t1, label2
label4:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -40($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -44($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -12($fp)
sub $t2, $t0, $t1
sw $t2, -48($fp)
lw $t0, -48($fp)
li $t1, 0
blt $t0, $t1, label7
li $t0, 0
sw $t0, -44($fp)
label7:
lw $t0, -44($fp)
li $t1, 0
bne $t0, $t1, label6
li $t0, 0
sw $t0, -40($fp)
j label8
label6:
addi $sp, $sp, -4
li $t1, 4
lw $t0, -12($fp)
mul $t2, $t0, $t1
sw $t2, -52($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -52($fp)
add $t2, $t0, $t1
sw $t2, -56($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, 0($t0)
sw $t1, -60($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -64($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -28($fp)
sub $t2, $t0, $t1
sw $t2, -68($fp)
lw $t0, -68($fp)
li $t1, 0
bge $t0, $t1, label9
li $t0, 0
sw $t0, -64($fp)
label9:
lw $t0, -64($fp)
li $t1, 0
bne $t0, $t1, label8
li $t0, 0
sw $t0, -40($fp)
label8:
lw $t0, -40($fp)
li $t1, 0
beq $t0, $t1, label5
addi $sp, $sp, -4
li $t0, 1
sw $t0, -72($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
lw $t1, -72($fp)
sub $t2, $t0, $t1
sw $t2, -76($fp)
lw $t0, -76($fp)
sw $t0, -12($fp)
j label4
label5:
move $sp, $fp
addi $sp, $sp, -76
lw $t0, -12($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal Swap
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 12
label10:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -80($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -84($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -12($fp)
sub $t2, $t0, $t1
sw $t2, -88($fp)
lw $t0, -88($fp)
li $t1, 0
blt $t0, $t1, label13
li $t0, 0
sw $t0, -84($fp)
label13:
lw $t0, -84($fp)
li $t1, 0
bne $t0, $t1, label12
li $t0, 0
sw $t0, -80($fp)
j label14
label12:
addi $sp, $sp, -4
li $t1, 4
lw $t0, -8($fp)
mul $t2, $t0, $t1
sw $t2, -92($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -96($fp)
addi $sp, $sp, -4
lw $t0, -96($fp)
lw $t1, 0($t0)
sw $t1, -100($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -104($fp)
addi $sp, $sp, -4
lw $t0, -100($fp)
lw $t1, -28($fp)
sub $t2, $t0, $t1
sw $t2, -108($fp)
lw $t0, -108($fp)
li $t1, 0
ble $t0, $t1, label15
li $t0, 0
sw $t0, -104($fp)
label15:
lw $t0, -104($fp)
li $t1, 0
bne $t0, $t1, label14
li $t0, 0
sw $t0, -80($fp)
label14:
lw $t0, -80($fp)
li $t1, 0
beq $t0, $t1, label11
addi $sp, $sp, -4
li $t0, 1
sw $t0, -112($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -112($fp)
add $t2, $t0, $t1
sw $t2, -116($fp)
lw $t0, -116($fp)
sw $t0, -8($fp)
j label10
label11:
move $sp, $fp
addi $sp, $sp, -116
lw $t0, -12($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal Swap
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 12
j label1
label2:
lw $v0, -8($fp)
move $sp, $fp
jr $ra

QuickSort:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
lw $t0, 16($fp)
addi $sp, $sp, -4
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
blt $t0, $t1, label17
li $t0, 0
sw $t0, -16($fp)
label17:
lw $t0, -16($fp)
li $t1, 0
beq $t0, $t1, label16
move $sp, $fp
addi $sp, $sp, -20
lw $t0, -12($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal Partition
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 12
addi $sp, $sp, -4
sw $v0, -24($fp)
addi $sp, $sp, -4
lw $t0, -24($fp)
sw $t0, -28($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
lw $t1, -32($fp)
sub $t2, $t0, $t1
sw $t2, -36($fp)
move $sp, $fp
addi $sp, $sp, -36
lw $t0, -36($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal QuickSort
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 12
addi $sp, $sp, -4
li $t0, 1
sw $t0, -40($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
lw $t1, -40($fp)
add $t2, $t0, $t1
sw $t2, -44($fp)
move $sp, $fp
addi $sp, $sp, -44
lw $t0, -12($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -44($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal QuickSort
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 12
label16:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -48($fp)
lw $v0, -48($fp)
move $sp, $fp
jr $ra

main:
move $fp, $sp
addi $sp, $sp, -4
li $t0, 8
sw $t0, -4($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
sw $t0, -8($fp)
addi $sp, $sp, -32
addi $sp, $sp, -4
li $t0, 0
sw $t0, -44($fp)
addi $sp, $sp, -4
lw $t0, -44($fp)
sw $t0, -48($fp)
label18:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -52($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -56($fp)
lw $t0, -56($fp)
li $t1, 0
blt $t0, $t1, label20
li $t0, 0
sw $t0, -52($fp)
label20:
lw $t0, -52($fp)
li $t1, 0
beq $t0, $t1, label19
addi $sp, $sp, -4
li $t1, 4
lw $t0, -48($fp)
mul $t2, $t0, $t1
sw $t2, -60($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -40  #t0 := &t1 + t2
lw $t1, -60($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -64($fp) #t0 := &t1 + t2
move $sp, $fp
addi $sp, $sp, -64
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -68($fp)
lw $t0, -68($fp)
lw $t1, -64($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -72($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, -72($fp)
add $t2, $t0, $t1
sw $t2, -76($fp)
lw $t0, -76($fp)
sw $t0, -48($fp)
j label18
label19:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -80($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -84($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -84($fp)
sub $t2, $t0, $t1
sw $t2, -88($fp)
move $sp, $fp
addi $sp, $sp, -88
lw $t0, -88($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -80($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
move $t0, $fp
addi $t0, $t0, -40
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal QuickSort
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 12
addi $sp, $sp, -4
li $t0, 0
sw $t0, -92($fp)
lw $t0, -92($fp)
sw $t0, -48($fp)
label21:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -96($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -100($fp)
lw $t0, -100($fp)
li $t1, 0
blt $t0, $t1, label23
li $t0, 0
sw $t0, -96($fp)
label23:
lw $t0, -96($fp)
li $t1, 0
beq $t0, $t1, label22
addi $sp, $sp, -4
li $t1, 4
lw $t0, -48($fp)
mul $t2, $t0, $t1
sw $t2, -104($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -40  #t0 := &t1 + t2
lw $t1, -104($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -108($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -108($fp)
lw $t1, 0($t0)
sw $t1, -112($fp)
lw $a0, -112($fp)
move $sp, $fp
addi $sp, $sp, -112
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 1
sw $t0, -116($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, -116($fp)
add $t2, $t0, $t1
sw $t2, -120($fp)
lw $t0, -120($fp)
sw $t0, -48($fp)
j label21
label22:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -124($fp)
lw $v0, -124($fp)
move $sp, $fp
jr $ra
