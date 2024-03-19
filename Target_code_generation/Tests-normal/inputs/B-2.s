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
addi $sp, $sp, -40
move $sp, $fp
addi $sp, $sp, -40
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -44($fp)
addi $sp, $sp, -4
lw $t0, -44($fp)
sw $t0, -48($fp)
addi $sp, $sp, -4
li $t0, 10
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
li $t0, 10
sw $t0, -64($fp)
lw $t0, -64($fp)
sw $t0, -48($fp)
label1:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -68($fp)
addi $sp, $sp, -4
lw $t0, -68($fp)
sw $t0, -72($fp)
label3:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -76($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -48($fp)
sub $t2, $t0, $t1
sw $t2, -80($fp)
lw $t0, -80($fp)
li $t1, 0
blt $t0, $t1, label5
li $t0, 0
sw $t0, -76($fp)
label5:
lw $t0, -76($fp)
li $t1, 0
beq $t0, $t1, label4
addi $sp, $sp, -4
li $t1, 4
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -84($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -40  #t0 := &t1 + t2
lw $t1, -84($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -88($fp) #t0 := &t1 + t2
move $sp, $fp
addi $sp, $sp, -88
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -92($fp)
lw $t0, -92($fp)
lw $t1, -88($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -96($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -96($fp)
add $t2, $t0, $t1
sw $t2, -100($fp)
lw $t0, -100($fp)
sw $t0, -72($fp)
j label3
label4:
move $sp, $fp
addi $sp, $sp, -100
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -104($fp)
addi $sp, $sp, -4
lw $t0, -104($fp)
sw $t0, -108($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -112($fp)
addi $sp, $sp, -4
lw $t0, -112($fp)
sw $t0, -116($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -120($fp)
addi $sp, $sp, -4
lw $t0, -48($fp)
lw $t1, -120($fp)
sub $t2, $t0, $t1
sw $t2, -124($fp)
addi $sp, $sp, -4
lw $t0, -124($fp)
sw $t0, -128($fp)
label6:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -132($fp)
addi $sp, $sp, -4
lw $t0, -116($fp)
lw $t1, -128($fp)
sub $t2, $t0, $t1
sw $t2, -136($fp)
lw $t0, -136($fp)
li $t1, 0
blt $t0, $t1, label8
li $t0, 0
sw $t0, -132($fp)
label8:
lw $t0, -132($fp)
li $t1, 0
beq $t0, $t1, label7
addi $sp, $sp, -4
lw $t0, -116($fp)
lw $t1, -128($fp)
add $t2, $t0, $t1
sw $t2, -140($fp)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -144($fp)
addi $sp, $sp, -4
lw $t1, -144($fp)
lw $t0, -140($fp)
div $t0, $t1
mflo $t2
sw $t2, -148($fp)
lw $t0, -148($fp)
sw $t0, -72($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -152($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -40  #t0 := &t1 + t2
lw $t1, -152($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -156($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, 0($t0)
sw $t1, -160($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -164($fp)
addi $sp, $sp, -4
lw $t0, -160($fp)
lw $t1, -108($fp)
sub $t2, $t0, $t1
sw $t2, -168($fp)
lw $t0, -168($fp)
li $t1, 0
beq $t0, $t1, label10
li $t0, 0
sw $t0, -164($fp)
label10:
lw $t0, -164($fp)
li $t1, 0
beq $t0, $t1, label9
lw $a0, -72($fp)
move $sp, $fp
addi $sp, $sp, -168
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -172($fp)
lw $v0, -172($fp)
move $sp, $fp
jr $ra
j label11
label9:
addi $sp, $sp, -4
li $t1, 4
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -176($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -40  #t0 := &t1 + t2
lw $t1, -176($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -180($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -180($fp)
lw $t1, 0($t0)
sw $t1, -184($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -188($fp)
addi $sp, $sp, -4
lw $t0, -184($fp)
lw $t1, -108($fp)
sub $t2, $t0, $t1
sw $t2, -192($fp)
lw $t0, -192($fp)
li $t1, 0
bgt $t0, $t1, label13
li $t0, 0
sw $t0, -188($fp)
label13:
lw $t0, -188($fp)
li $t1, 0
beq $t0, $t1, label12
addi $sp, $sp, -4
li $t0, 1
sw $t0, -196($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -196($fp)
sub $t2, $t0, $t1
sw $t2, -200($fp)
lw $t0, -200($fp)
sw $t0, -128($fp)
j label14
label12:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -204($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -204($fp)
add $t2, $t0, $t1
sw $t2, -208($fp)
lw $t0, -208($fp)
sw $t0, -116($fp)
label14:
label11:
j label6
label7:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -212($fp)
lw $v0, -212($fp)
move $sp, $fp
jr $ra
