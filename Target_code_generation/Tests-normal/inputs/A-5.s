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
addi $sp, $sp, -12
addi $sp, $sp, -12
addi $sp, $sp, -4
li $t0, 0
sw $t0, -28($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
sw $t0, -32($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -36($fp)
addi $sp, $sp, -4
lw $t0, -36($fp)
sw $t0, -40($fp)
label1:
addi $sp, $sp, -4
li $t0, 3
sw $t0, -44($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -48($fp)
addi $sp, $sp, -4
lw $t0, -32($fp)
lw $t1, -44($fp)
sub $t2, $t0, $t1
sw $t2, -52($fp)
lw $t0, -52($fp)
li $t1, 0
blt $t0, $t1, label3
li $t0, 0
sw $t0, -48($fp)
label3:
lw $t0, -48($fp)
li $t1, 0
beq $t0, $t1, label2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -56($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -12  #t0 := &t1 + t2
lw $t1, -56($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -60($fp) #t0 := &t1 + t2
move $sp, $fp
addi $sp, $sp, -60
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -64($fp)
lw $t0, -64($fp)
lw $t1, -60($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -68($fp)
addi $sp, $sp, -4
lw $t0, -32($fp)
lw $t1, -68($fp)
add $t2, $t0, $t1
sw $t2, -72($fp)
lw $t0, -72($fp)
sw $t0, -32($fp)
j label1
label2:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -76($fp)
lw $t0, -76($fp)
sw $t0, -32($fp)
label4:
addi $sp, $sp, -4
li $t0, 3
sw $t0, -80($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -84($fp)
addi $sp, $sp, -4
lw $t0, -32($fp)
lw $t1, -80($fp)
sub $t2, $t0, $t1
sw $t2, -88($fp)
lw $t0, -88($fp)
li $t1, 0
blt $t0, $t1, label6
li $t0, 0
sw $t0, -84($fp)
label6:
lw $t0, -84($fp)
li $t1, 0
beq $t0, $t1, label5
addi $sp, $sp, -4
li $t1, 4
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -92($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -24  #t0 := &t1 + t2
lw $t1, -92($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -96($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -100($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -12  #t0 := &t1 + t2
lw $t1, -100($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -104($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t0, 2
sw $t0, -108($fp)
addi $sp, $sp, -4
lw $t0, -104($fp)
lw $t1, 0($t0)
sw $t1, -112($fp)
addi $sp, $sp, -4
lw $t1, -108($fp)
lw $t0, -112($fp)
mul $t2, $t0, $t1
sw $t2, -116($fp)
lw $t0, -116($fp)
lw $t1, -96($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -120($fp)
addi $sp, $sp, -4
lw $t0, -32($fp)
lw $t1, -120($fp)
add $t2, $t0, $t1
sw $t2, -124($fp)
lw $t0, -124($fp)
sw $t0, -32($fp)
j label4
label5:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -128($fp)
lw $t0, -128($fp)
sw $t0, -32($fp)
label7:
addi $sp, $sp, -4
li $t0, 3
sw $t0, -132($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -136($fp)
addi $sp, $sp, -4
lw $t0, -32($fp)
lw $t1, -132($fp)
sub $t2, $t0, $t1
sw $t2, -140($fp)
lw $t0, -140($fp)
li $t1, 0
blt $t0, $t1, label9
li $t0, 0
sw $t0, -136($fp)
label9:
lw $t0, -136($fp)
li $t1, 0
beq $t0, $t1, label8
addi $sp, $sp, -4
li $t1, 4
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -144($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -12  #t0 := &t1 + t2
lw $t1, -144($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -148($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -148($fp)
lw $t1, 0($t0)
sw $t1, -152($fp)
addi $sp, $sp, -4
lw $t0, -40($fp)
lw $t1, -152($fp)
add $t2, $t0, $t1
sw $t2, -156($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -160($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -24  #t0 := &t1 + t2
lw $t1, -160($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -164($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -164($fp)
lw $t1, 0($t0)
sw $t1, -168($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -168($fp)
add $t2, $t0, $t1
sw $t2, -172($fp)
lw $t0, -172($fp)
sw $t0, -40($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -176($fp)
addi $sp, $sp, -4
lw $t0, -32($fp)
lw $t1, -176($fp)
add $t2, $t0, $t1
sw $t2, -180($fp)
lw $t0, -180($fp)
sw $t0, -32($fp)
j label7
label8:
lw $a0, -40($fp)
move $sp, $fp
addi $sp, $sp, -180
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -184($fp)
lw $v0, -184($fp)
move $sp, $fp
jr $ra
