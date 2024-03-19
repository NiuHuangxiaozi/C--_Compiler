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
addi $sp, $sp, -40
addi $sp, $sp, -4
li $t0, 0
sw $t0, -56($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
sw $t0, -60($fp)
addi $sp, $sp, -20
label1:
addi $sp, $sp, -4
li $t0, 5
sw $t0, -84($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -88($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -84($fp)
sub $t2, $t0, $t1
sw $t2, -92($fp)
lw $t0, -92($fp)
li $t1, 0
blt $t0, $t1, label3
li $t0, 0
sw $t0, -88($fp)
label3:
lw $t0, -88($fp)
li $t1, 0
beq $t0, $t1, label2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -96($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -96($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -100($fp) #t0 := &t1 + t2
move $sp, $fp
addi $sp, $sp, -100
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -104($fp)
lw $t0, -104($fp)
lw $t1, -100($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -108($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -108($fp)
add $t2, $t0, $t1
sw $t2, -112($fp)
lw $t0, -112($fp)
sw $t0, -60($fp)
j label1
label2:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -116($fp)
lw $t0, -116($fp)
sw $t0, -60($fp)
label4:
addi $sp, $sp, -4
li $t0, 4
sw $t0, -120($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -124($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -120($fp)
sub $t2, $t0, $t1
sw $t2, -128($fp)
lw $t0, -128($fp)
li $t1, 0
blt $t0, $t1, label6
li $t0, 0
sw $t0, -124($fp)
label6:
lw $t0, -124($fp)
li $t1, 0
beq $t0, $t1, label5
addi $sp, $sp, -4
li $t0, 1
sw $t0, -132($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -132($fp)
add $t2, $t0, $t1
sw $t2, -136($fp)
addi $sp, $sp, -4
lw $t0, -136($fp)
sw $t0, -140($fp)
label7:
addi $sp, $sp, -4
li $t0, 5
sw $t0, -144($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -148($fp)
addi $sp, $sp, -4
lw $t0, -140($fp)
lw $t1, -144($fp)
sub $t2, $t0, $t1
sw $t2, -152($fp)
lw $t0, -152($fp)
li $t1, 0
blt $t0, $t1, label9
li $t0, 0
sw $t0, -148($fp)
label9:
lw $t0, -148($fp)
li $t1, 0
beq $t0, $t1, label8
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -156($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -156($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -160($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -164($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -164($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -168($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -168($fp)
lw $t1, 0($t0)
sw $t1, -172($fp)
addi $sp, $sp, -4
lw $t0, -160($fp)
lw $t1, 0($t0)
sw $t1, -176($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -180($fp)
addi $sp, $sp, -4
lw $t0, -176($fp)
lw $t1, -172($fp)
sub $t2, $t0, $t1
sw $t2, -184($fp)
lw $t0, -184($fp)
li $t1, 0
bgt $t0, $t1, label11
li $t0, 0
sw $t0, -180($fp)
label11:
lw $t0, -180($fp)
li $t1, 0
beq $t0, $t1, label10
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -188($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -188($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -192($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -192($fp)
lw $t1, 0($t0)
sw $t1, -196($fp)
addi $sp, $sp, -4
lw $t0, -196($fp)
sw $t0, -200($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -204($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -204($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -208($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -212($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -212($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -216($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -216($fp)
addi $t2, $t0, 0
sw $t2, -220($fp)
addi $sp, $sp, -4
lw $t0, -220($fp)
lw $t1, 0($t0)
sw $t1, -224($fp)
addi $sp, $sp, -4
lw $t0, -208($fp)
addi $t2, $t0, 0
sw $t2, -228($fp)
lw $t0, -224($fp)
lw $t1, -228($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -140($fp)
mul $t2, $t0, $t1
sw $t2, -232($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -232($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -236($fp) #t0 := &t1 + t2
lw $t0, -200($fp)
lw $t1, -236($fp)
sw $t0, 0($t1)
label10:
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
j label7
label8:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -248($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -248($fp)
add $t2, $t0, $t1
sw $t2, -252($fp)
lw $t0, -252($fp)
sw $t0, -60($fp)
j label4
label5:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -256($fp)
lw $t0, -256($fp)
sw $t0, -60($fp)
label12:
addi $sp, $sp, -4
li $t0, 5
sw $t0, -260($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -264($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -260($fp)
sub $t2, $t0, $t1
sw $t2, -268($fp)
lw $t0, -268($fp)
li $t1, 0
blt $t0, $t1, label14
li $t0, 0
sw $t0, -264($fp)
label14:
lw $t0, -264($fp)
li $t1, 0
beq $t0, $t1, label13
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -272($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -80  #t0 := &t1 + t2
lw $t1, -272($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -276($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -276($fp)
lw $t1, 0($t0)
sw $t1, -280($fp)
lw $a0, -280($fp)
move $sp, $fp
addi $sp, $sp, -280
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 1
sw $t0, -284($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -284($fp)
add $t2, $t0, $t1
sw $t2, -288($fp)
lw $t0, -288($fp)
sw $t0, -60($fp)
j label12
label13:
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 0
sw $t2, -292($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -292($fp)
lw $t1, 0($t0)
sw $t1, -296($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -12
addi $t2, $t0, 0
sw $t2, -300($fp)  #t0 := &t1 + #d
lw $t0, -296($fp)
lw $t1, -300($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 4
sw $t2, -304($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -304($fp)
lw $t1, 0($t0)
sw $t1, -308($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -12
addi $t2, $t0, 4
sw $t2, -312($fp)  #t0 := &t1 + #d
lw $t0, -308($fp)
lw $t1, -312($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 8
sw $t2, -316($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -316($fp)
lw $t1, 0($t0)
sw $t1, -320($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -12
addi $t2, $t0, 8
sw $t2, -324($fp)  #t0 := &t1 + #d
lw $t0, -320($fp)
lw $t1, -324($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 12
sw $t2, -328($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -328($fp)
lw $t1, 0($t0)
sw $t1, -332($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -12
addi $t2, $t0, 12
sw $t2, -336($fp)  #t0 := &t1 + #d
lw $t0, -332($fp)
lw $t1, -336($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 16
sw $t2, -340($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -340($fp)
lw $t1, 0($t0)
sw $t1, -344($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -12
addi $t2, $t0, 16
sw $t2, -348($fp)  #t0 := &t1 + #d
lw $t0, -344($fp)
lw $t1, -348($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 0
sw $t2, -352($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -352($fp)
lw $t1, 0($t0)
sw $t1, -356($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -52
addi $t2, $t0, 0
sw $t2, -360($fp)  #t0 := &t1 + #d
lw $t0, -356($fp)
lw $t1, -360($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 4
sw $t2, -364($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -364($fp)
lw $t1, 0($t0)
sw $t1, -368($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -52
addi $t2, $t0, 4
sw $t2, -372($fp)  #t0 := &t1 + #d
lw $t0, -368($fp)
lw $t1, -372($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 8
sw $t2, -376($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -376($fp)
lw $t1, 0($t0)
sw $t1, -380($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -52
addi $t2, $t0, 8
sw $t2, -384($fp)  #t0 := &t1 + #d
lw $t0, -380($fp)
lw $t1, -384($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 12
sw $t2, -388($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -388($fp)
lw $t1, 0($t0)
sw $t1, -392($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -52
addi $t2, $t0, 12
sw $t2, -396($fp)  #t0 := &t1 + #d
lw $t0, -392($fp)
lw $t1, -396($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -80
addi $t2, $t0, 16
sw $t2, -400($fp)  #t0 := &t1 + #d
addi $sp, $sp, -4
lw $t0, -400($fp)
lw $t1, 0($t0)
sw $t1, -404($fp)
addi $sp, $sp, -4
move $t0, $fp  #t0 := &t1 + #d
addi $t0, $t0, -52
addi $t2, $t0, 16
sw $t2, -408($fp)  #t0 := &t1 + #d
lw $t0, -404($fp)
lw $t1, -408($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -412($fp)
lw $t0, -412($fp)
sw $t0, -60($fp)
label15:
addi $sp, $sp, -4
li $t0, 5
sw $t0, -416($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -420($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -416($fp)
sub $t2, $t0, $t1
sw $t2, -424($fp)
lw $t0, -424($fp)
li $t1, 0
blt $t0, $t1, label17
li $t0, 0
sw $t0, -420($fp)
label17:
lw $t0, -420($fp)
li $t1, 0
beq $t0, $t1, label16
addi $sp, $sp, -4
li $t0, 3
sw $t0, -428($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -432($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -428($fp)
sub $t2, $t0, $t1
sw $t2, -436($fp)
lw $t0, -436($fp)
li $t1, 0
blt $t0, $t1, label19
li $t0, 0
sw $t0, -432($fp)
label19:
lw $t0, -432($fp)
li $t1, 0
beq $t0, $t1, label18
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -440($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -12  #t0 := &t1 + t2
lw $t1, -440($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -444($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -444($fp)
lw $t1, 0($t0)
sw $t1, -448($fp)
lw $a0, -448($fp)
move $sp, $fp
addi $sp, $sp, -448
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -452($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -52  #t0 := &t1 + t2
lw $t1, -452($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -456($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -456($fp)
lw $t1, 0($t0)
sw $t1, -460($fp)
lw $a0, -460($fp)
move $sp, $fp
addi $sp, $sp, -460
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
j label20
label18:
addi $sp, $sp, -4
li $t1, 4
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -464($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -52  #t0 := &t1 + t2
lw $t1, -464($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -468($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -468($fp)
lw $t1, 0($t0)
sw $t1, -472($fp)
lw $a0, -472($fp)
move $sp, $fp
addi $sp, $sp, -472
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
label20:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -476($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -476($fp)
add $t2, $t0, $t1
sw $t2, -480($fp)
lw $t0, -480($fp)
sw $t0, -60($fp)
j label15
label16:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -484($fp)
lw $v0, -484($fp)
move $sp, $fp
jr $ra
