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
li $t0, 5
sw $t0, -4($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
sw $t0, -8($fp)
addi $sp, $sp, -20
addi $sp, $sp, -20
addi $sp, $sp, -4
li $t0, 0
sw $t0, -52($fp)
addi $sp, $sp, -4
lw $t0, -52($fp)
sw $t0, -56($fp)
label1:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -60($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -64($fp)
lw $t0, -64($fp)
li $t1, 0
blt $t0, $t1, label3
li $t0, 0
sw $t0, -60($fp)
label3:
lw $t0, -60($fp)
li $t1, 0
beq $t0, $t1, label2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -68($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -68($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -72($fp) #t0 := &t1 + t2
move $sp, $fp
addi $sp, $sp, -72
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -76($fp)
lw $t0, -76($fp)
lw $t1, -72($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -80($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -80($fp)
add $t2, $t0, $t1
sw $t2, -84($fp)
lw $t0, -84($fp)
sw $t0, -56($fp)
j label1
label2:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -88($fp)
addi $sp, $sp, -4
lw $t0, -88($fp)
sw $t0, -92($fp)
label4:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -96($fp)
addi $sp, $sp, -4
lw $t0, -92($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -100($fp)
lw $t0, -100($fp)
li $t1, 0
blt $t0, $t1, label6
li $t0, 0
sw $t0, -96($fp)
label6:
lw $t0, -96($fp)
li $t1, 0
beq $t0, $t1, label5
addi $sp, $sp, -4
li $t0, 0
sw $t0, -104($fp)
lw $t0, -104($fp)
sw $t0, -56($fp)
label7:
addi $sp, $sp, -4
li $t0, 2
sw $t0, -108($fp)
addi $sp, $sp, -4
lw $t1, -92($fp)
lw $t0, -108($fp)
mul $t2, $t0, $t1
sw $t2, -112($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -112($fp)
sub $t2, $t0, $t1
sw $t2, -116($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -120($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -116($fp)
sub $t2, $t0, $t1
sw $t2, -124($fp)
lw $t0, -124($fp)
li $t1, 0
ble $t0, $t1, label9
li $t0, 0
sw $t0, -120($fp)
label9:
lw $t0, -120($fp)
li $t1, 0
beq $t0, $t1, label8
addi $sp, $sp, -4
lw $t0, -56($fp)
sw $t0, -128($fp)
addi $sp, $sp, -4
lw $t0, -128($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -132($fp)
addi $sp, $sp, -4
lw $t0, -132($fp)
sw $t0, -136($fp)
addi $sp, $sp, -4
lw $t0, -128($fp)
sw $t0, -140($fp)
addi $sp, $sp, -4
lw $t0, -136($fp)
sw $t0, -144($fp)
addi $sp, $sp, -4
lw $t0, -144($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -148($fp)
addi $sp, $sp, -4
lw $t0, -148($fp)
sw $t0, -152($fp)
addi $sp, $sp, -4
lw $t0, -144($fp)
sw $t0, -156($fp)
label10:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -160($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -164($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -136($fp)
sub $t2, $t0, $t1
sw $t2, -168($fp)
lw $t0, -168($fp)
li $t1, 0
blt $t0, $t1, label13
li $t0, 0
sw $t0, -164($fp)
label13:
lw $t0, -164($fp)
li $t1, 0
bne $t0, $t1, label12
li $t0, 0
sw $t0, -160($fp)
j label14
label12:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -172($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -152($fp)
sub $t2, $t0, $t1
sw $t2, -176($fp)
lw $t0, -176($fp)
li $t1, 0
blt $t0, $t1, label15
li $t0, 0
sw $t0, -172($fp)
label15:
lw $t0, -172($fp)
li $t1, 0
bne $t0, $t1, label14
li $t0, 0
sw $t0, -160($fp)
label14:
lw $t0, -160($fp)
li $t1, 0
beq $t0, $t1, label11
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -180($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -180($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -184($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -156($fp)
mul $t2, $t0, $t1
sw $t2, -188($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -188($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -192($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -192($fp)
lw $t1, 0($t0)
sw $t1, -196($fp)
addi $sp, $sp, -4
lw $t0, -184($fp)
lw $t1, 0($t0)
sw $t1, -200($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -204($fp)
addi $sp, $sp, -4
lw $t0, -200($fp)
lw $t1, -196($fp)
sub $t2, $t0, $t1
sw $t2, -208($fp)
lw $t0, -208($fp)
li $t1, 0
blt $t0, $t1, label17
li $t0, 0
sw $t0, -204($fp)
label17:
lw $t0, -204($fp)
li $t1, 0
beq $t0, $t1, label16
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -212($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -212($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -216($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -220($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -220($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -224($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -224($fp)
addi $t2, $t0, 0
sw $t2, -228($fp)
addi $sp, $sp, -4
lw $t0, -228($fp)
lw $t1, 0($t0)
sw $t1, -232($fp)
addi $sp, $sp, -4
lw $t0, -216($fp)
addi $t2, $t0, 0
sw $t2, -236($fp)
lw $t0, -232($fp)
lw $t1, -236($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -240($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -240($fp)
add $t2, $t0, $t1
sw $t2, -244($fp)
lw $t0, -244($fp)
sw $t0, -140($fp)
j label18
label16:
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -248($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -248($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -252($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -156($fp)
mul $t2, $t0, $t1
sw $t2, -256($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -256($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -260($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -260($fp)
addi $t2, $t0, 0
sw $t2, -264($fp)
addi $sp, $sp, -4
lw $t0, -264($fp)
lw $t1, 0($t0)
sw $t1, -268($fp)
addi $sp, $sp, -4
lw $t0, -252($fp)
addi $t2, $t0, 0
sw $t2, -272($fp)
lw $t0, -268($fp)
lw $t1, -272($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -276($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -276($fp)
add $t2, $t0, $t1
sw $t2, -280($fp)
lw $t0, -280($fp)
sw $t0, -156($fp)
label18:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -284($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -284($fp)
add $t2, $t0, $t1
sw $t2, -288($fp)
lw $t0, -288($fp)
sw $t0, -56($fp)
j label10
label11:
label19:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -292($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -136($fp)
sub $t2, $t0, $t1
sw $t2, -296($fp)
lw $t0, -296($fp)
li $t1, 0
blt $t0, $t1, label21
li $t0, 0
sw $t0, -292($fp)
label21:
lw $t0, -292($fp)
li $t1, 0
beq $t0, $t1, label20
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -300($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -300($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -304($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -308($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -308($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -312($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -312($fp)
addi $t2, $t0, 0
sw $t2, -316($fp)
addi $sp, $sp, -4
lw $t0, -316($fp)
lw $t1, 0($t0)
sw $t1, -320($fp)
addi $sp, $sp, -4
lw $t0, -304($fp)
addi $t2, $t0, 0
sw $t2, -324($fp)
lw $t0, -320($fp)
lw $t1, -324($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -328($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -328($fp)
add $t2, $t0, $t1
sw $t2, -332($fp)
lw $t0, -332($fp)
sw $t0, -140($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -336($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -336($fp)
add $t2, $t0, $t1
sw $t2, -340($fp)
lw $t0, -340($fp)
sw $t0, -56($fp)
j label19
label20:
label22:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -344($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -152($fp)
sub $t2, $t0, $t1
sw $t2, -348($fp)
lw $t0, -348($fp)
li $t1, 0
blt $t0, $t1, label24
li $t0, 0
sw $t0, -344($fp)
label24:
lw $t0, -344($fp)
li $t1, 0
beq $t0, $t1, label23
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -352($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -352($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -356($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -156($fp)
mul $t2, $t0, $t1
sw $t2, -360($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -360($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -364($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -364($fp)
addi $t2, $t0, 0
sw $t2, -368($fp)
addi $sp, $sp, -4
lw $t0, -368($fp)
lw $t1, 0($t0)
sw $t1, -372($fp)
addi $sp, $sp, -4
lw $t0, -356($fp)
addi $t2, $t0, 0
sw $t2, -376($fp)
lw $t0, -372($fp)
lw $t1, -376($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -380($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -380($fp)
add $t2, $t0, $t1
sw $t2, -384($fp)
lw $t0, -384($fp)
sw $t0, -156($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -388($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -388($fp)
add $t2, $t0, $t1
sw $t2, -392($fp)
lw $t0, -392($fp)
sw $t0, -56($fp)
j label22
label23:
j label7
label8:
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -396($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -400($fp)
addi $sp, $sp, -4
lw $t0, -396($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -404($fp)
lw $t0, -404($fp)
li $t1, 0
blt $t0, $t1, label26
li $t0, 0
sw $t0, -400($fp)
label26:
lw $t0, -400($fp)
li $t1, 0
beq $t0, $t1, label25
lw $t0, -56($fp)
sw $t0, -128($fp)
addi $sp, $sp, -4
lw $t0, -128($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -408($fp)
lw $t0, -408($fp)
sw $t0, -136($fp)
lw $t0, -128($fp)
sw $t0, -140($fp)
lw $t0, -136($fp)
sw $t0, -144($fp)
lw $t0, -8($fp)
sw $t0, -152($fp)
lw $t0, -144($fp)
sw $t0, -156($fp)
label27:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -412($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -416($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -136($fp)
sub $t2, $t0, $t1
sw $t2, -420($fp)
lw $t0, -420($fp)
li $t1, 0
blt $t0, $t1, label30
li $t0, 0
sw $t0, -416($fp)
label30:
lw $t0, -416($fp)
li $t1, 0
bne $t0, $t1, label29
li $t0, 0
sw $t0, -412($fp)
j label31
label29:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -424($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -152($fp)
sub $t2, $t0, $t1
sw $t2, -428($fp)
lw $t0, -428($fp)
li $t1, 0
blt $t0, $t1, label32
li $t0, 0
sw $t0, -424($fp)
label32:
lw $t0, -424($fp)
li $t1, 0
bne $t0, $t1, label31
li $t0, 0
sw $t0, -412($fp)
label31:
lw $t0, -412($fp)
li $t1, 0
beq $t0, $t1, label28
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -432($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -432($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -436($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -156($fp)
mul $t2, $t0, $t1
sw $t2, -440($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -440($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -444($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -444($fp)
lw $t1, 0($t0)
sw $t1, -448($fp)
addi $sp, $sp, -4
lw $t0, -436($fp)
lw $t1, 0($t0)
sw $t1, -452($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -456($fp)
addi $sp, $sp, -4
lw $t0, -452($fp)
lw $t1, -448($fp)
sub $t2, $t0, $t1
sw $t2, -460($fp)
lw $t0, -460($fp)
li $t1, 0
blt $t0, $t1, label34
li $t0, 0
sw $t0, -456($fp)
label34:
lw $t0, -456($fp)
li $t1, 0
beq $t0, $t1, label33
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -464($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -464($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -468($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -472($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -472($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -476($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -476($fp)
addi $t2, $t0, 0
sw $t2, -480($fp)
addi $sp, $sp, -4
lw $t0, -480($fp)
lw $t1, 0($t0)
sw $t1, -484($fp)
addi $sp, $sp, -4
lw $t0, -468($fp)
addi $t2, $t0, 0
sw $t2, -488($fp)
lw $t0, -484($fp)
lw $t1, -488($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -492($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -492($fp)
add $t2, $t0, $t1
sw $t2, -496($fp)
lw $t0, -496($fp)
sw $t0, -140($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -500($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -500($fp)
add $t2, $t0, $t1
sw $t2, -504($fp)
lw $t0, -504($fp)
sw $t0, -56($fp)
j label35
label33:
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -508($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -508($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -512($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -156($fp)
mul $t2, $t0, $t1
sw $t2, -516($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -516($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -520($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -520($fp)
addi $t2, $t0, 0
sw $t2, -524($fp)
addi $sp, $sp, -4
lw $t0, -524($fp)
lw $t1, 0($t0)
sw $t1, -528($fp)
addi $sp, $sp, -4
lw $t0, -512($fp)
addi $t2, $t0, 0
sw $t2, -532($fp)
lw $t0, -528($fp)
lw $t1, -532($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -536($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -536($fp)
add $t2, $t0, $t1
sw $t2, -540($fp)
lw $t0, -540($fp)
sw $t0, -156($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -544($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -544($fp)
add $t2, $t0, $t1
sw $t2, -548($fp)
lw $t0, -548($fp)
sw $t0, -56($fp)
label35:
j label27
label28:
label36:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -552($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -136($fp)
sub $t2, $t0, $t1
sw $t2, -556($fp)
lw $t0, -556($fp)
li $t1, 0
blt $t0, $t1, label38
li $t0, 0
sw $t0, -552($fp)
label38:
lw $t0, -552($fp)
li $t1, 0
beq $t0, $t1, label37
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -560($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -560($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -564($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -568($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -568($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -572($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -572($fp)
addi $t2, $t0, 0
sw $t2, -576($fp)
addi $sp, $sp, -4
lw $t0, -576($fp)
lw $t1, 0($t0)
sw $t1, -580($fp)
addi $sp, $sp, -4
lw $t0, -564($fp)
addi $t2, $t0, 0
sw $t2, -584($fp)
lw $t0, -580($fp)
lw $t1, -584($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -588($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -588($fp)
add $t2, $t0, $t1
sw $t2, -592($fp)
lw $t0, -592($fp)
sw $t0, -140($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -596($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -596($fp)
add $t2, $t0, $t1
sw $t2, -600($fp)
lw $t0, -600($fp)
sw $t0, -56($fp)
j label36
label37:
label39:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -604($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -152($fp)
sub $t2, $t0, $t1
sw $t2, -608($fp)
lw $t0, -608($fp)
li $t1, 0
blt $t0, $t1, label41
li $t0, 0
sw $t0, -604($fp)
label41:
lw $t0, -604($fp)
li $t1, 0
beq $t0, $t1, label40
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -612($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -612($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -616($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -156($fp)
mul $t2, $t0, $t1
sw $t2, -620($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -620($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -624($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -624($fp)
addi $t2, $t0, 0
sw $t2, -628($fp)
addi $sp, $sp, -4
lw $t0, -628($fp)
lw $t1, 0($t0)
sw $t1, -632($fp)
addi $sp, $sp, -4
lw $t0, -616($fp)
addi $t2, $t0, 0
sw $t2, -636($fp)
lw $t0, -632($fp)
lw $t1, -636($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -640($fp)
addi $sp, $sp, -4
lw $t0, -156($fp)
lw $t1, -640($fp)
add $t2, $t0, $t1
sw $t2, -644($fp)
lw $t0, -644($fp)
sw $t0, -156($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -648($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -648($fp)
add $t2, $t0, $t1
sw $t2, -652($fp)
lw $t0, -652($fp)
sw $t0, -56($fp)
j label39
label40:
j label42
label25:
label43:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -656($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -660($fp)
lw $t0, -660($fp)
li $t1, 0
blt $t0, $t1, label45
li $t0, 0
sw $t0, -656($fp)
label45:
lw $t0, -656($fp)
li $t1, 0
beq $t0, $t1, label44
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -664($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -664($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -668($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -672($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -672($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -676($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -676($fp)
addi $t2, $t0, 0
sw $t2, -680($fp)
addi $sp, $sp, -4
lw $t0, -680($fp)
lw $t1, 0($t0)
sw $t1, -684($fp)
addi $sp, $sp, -4
lw $t0, -668($fp)
addi $t2, $t0, 0
sw $t2, -688($fp)
lw $t0, -684($fp)
lw $t1, -688($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -692($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -692($fp)
add $t2, $t0, $t1
sw $t2, -696($fp)
lw $t0, -696($fp)
sw $t0, -56($fp)
j label43
label44:
label42:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -700($fp)
lw $t0, -700($fp)
sw $t0, -56($fp)
label46:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -704($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -708($fp)
lw $t0, -708($fp)
li $t1, 0
blt $t0, $t1, label48
li $t0, 0
sw $t0, -704($fp)
label48:
lw $t0, -704($fp)
li $t1, 0
beq $t0, $t1, label47
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -712($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -712($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -716($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -720($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -720($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -724($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -724($fp)
addi $t2, $t0, 0
sw $t2, -728($fp)
addi $sp, $sp, -4
lw $t0, -728($fp)
lw $t1, 0($t0)
sw $t1, -732($fp)
addi $sp, $sp, -4
lw $t0, -716($fp)
addi $t2, $t0, 0
sw $t2, -736($fp)
lw $t0, -732($fp)
lw $t1, -736($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -740($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -740($fp)
add $t2, $t0, $t1
sw $t2, -744($fp)
lw $t0, -744($fp)
sw $t0, -56($fp)
j label46
label47:
addi $sp, $sp, -4
li $t0, 2
sw $t0, -748($fp)
addi $sp, $sp, -4
lw $t1, -748($fp)
lw $t0, -92($fp)
mul $t2, $t0, $t1
sw $t2, -752($fp)
lw $t0, -752($fp)
sw $t0, -92($fp)
j label4
label5:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -756($fp)
lw $t0, -756($fp)
sw $t0, -56($fp)
label49:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -760($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -8($fp)
sub $t2, $t0, $t1
sw $t2, -764($fp)
lw $t0, -764($fp)
li $t1, 0
blt $t0, $t1, label51
li $t0, 0
sw $t0, -760($fp)
label51:
lw $t0, -760($fp)
li $t1, 0
beq $t0, $t1, label50
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -768($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -28  #t0 := &t1 + t2
lw $t1, -768($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -772($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -772($fp)
lw $t1, 0($t0)
sw $t1, -776($fp)
lw $a0, -776($fp)
move $sp, $fp
addi $sp, $sp, -776
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 1
sw $t0, -780($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
lw $t1, -780($fp)
add $t2, $t0, $t1
sw $t2, -784($fp)
lw $t0, -784($fp)
sw $t0, -56($fp)
j label49
label50:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -788($fp)
lw $v0, -788($fp)
move $sp, $fp
jr $ra
