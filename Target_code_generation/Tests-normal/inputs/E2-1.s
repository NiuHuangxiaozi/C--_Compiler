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
addi $sp, $sp, -64
addi $sp, $sp, -4
li $t0, 0
sw $t0, -68($fp)
addi $sp, $sp, -4
lw $t0, -68($fp)
sw $t0, -72($fp)
label1:
addi $sp, $sp, -4
li $t0, 4
sw $t0, -76($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -80($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -76($fp)
sub $t2, $t0, $t1
sw $t2, -84($fp)
lw $t0, -84($fp)
li $t1, 0
blt $t0, $t1, label3
li $t0, 0
sw $t0, -80($fp)
label3:
lw $t0, -80($fp)
li $t1, 0
beq $t0, $t1, label2
addi $sp, $sp, -4
li $t0, 0
sw $t0, -88($fp)
addi $sp, $sp, -4
lw $t0, -88($fp)
sw $t0, -92($fp)
label4:
addi $sp, $sp, -4
li $t0, 4
sw $t0, -96($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -100($fp)
addi $sp, $sp, -4
lw $t0, -92($fp)
lw $t1, -96($fp)
sub $t2, $t0, $t1
sw $t2, -104($fp)
lw $t0, -104($fp)
li $t1, 0
blt $t0, $t1, label6
li $t0, 0
sw $t0, -100($fp)
label6:
lw $t0, -100($fp)
li $t1, 0
beq $t0, $t1, label5
addi $sp, $sp, -4
li $t1, 16
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -108($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -108($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -112($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -92($fp)
mul $t2, $t0, $t1
sw $t2, -116($fp)
addi $sp, $sp, -4
lw $t0, -112($fp)
lw $t1, -116($fp)
add $t2, $t0, $t1
sw $t2, -120($fp)
addi $sp, $sp, -4
li $t0, 999
sw $t0, -124($fp)
lw $t0, -124($fp)
lw $t1, -120($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -128($fp)
addi $sp, $sp, -4
lw $t0, -92($fp)
lw $t1, -128($fp)
add $t2, $t0, $t1
sw $t2, -132($fp)
lw $t0, -132($fp)
sw $t0, -92($fp)
j label4
label5:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -136($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -136($fp)
add $t2, $t0, $t1
sw $t2, -140($fp)
lw $t0, -140($fp)
sw $t0, -72($fp)
j label1
label2:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -144($fp)
lw $t0, -144($fp)
sw $t0, -72($fp)
label7:
addi $sp, $sp, -4
li $t0, 4
sw $t0, -148($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -152($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -148($fp)
sub $t2, $t0, $t1
sw $t2, -156($fp)
lw $t0, -156($fp)
li $t1, 0
blt $t0, $t1, label9
li $t0, 0
sw $t0, -152($fp)
label9:
lw $t0, -152($fp)
li $t1, 0
beq $t0, $t1, label8
addi $sp, $sp, -4
li $t1, 16
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -160($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -160($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -164($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -168($fp)
addi $sp, $sp, -4
lw $t0, -164($fp)
lw $t1, -168($fp)
add $t2, $t0, $t1
sw $t2, -172($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -176($fp)
lw $t0, -176($fp)
lw $t1, -172($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -180($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -180($fp)
add $t2, $t0, $t1
sw $t2, -184($fp)
lw $t0, -184($fp)
sw $t0, -72($fp)
j label7
label8:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -188($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -192($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -192($fp)
mul $t2, $t0, $t1
sw $t2, -196($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -196($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -200($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -188($fp)
mul $t2, $t0, $t1
sw $t2, -204($fp)
addi $sp, $sp, -4
lw $t0, -200($fp)
lw $t1, -204($fp)
add $t2, $t0, $t1
sw $t2, -208($fp)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -212($fp)
lw $t0, -212($fp)
lw $t1, -208($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -216($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -220($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -220($fp)
mul $t2, $t0, $t1
sw $t2, -224($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -224($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -228($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -216($fp)
mul $t2, $t0, $t1
sw $t2, -232($fp)
addi $sp, $sp, -4
lw $t0, -228($fp)
lw $t1, -232($fp)
add $t2, $t0, $t1
sw $t2, -236($fp)
addi $sp, $sp, -4
li $t0, 5
sw $t0, -240($fp)
lw $t0, -240($fp)
lw $t1, -236($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -244($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -248($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -248($fp)
mul $t2, $t0, $t1
sw $t2, -252($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -252($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -256($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -244($fp)
mul $t2, $t0, $t1
sw $t2, -260($fp)
addi $sp, $sp, -4
lw $t0, -256($fp)
lw $t1, -260($fp)
add $t2, $t0, $t1
sw $t2, -264($fp)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -268($fp)
lw $t0, -268($fp)
lw $t1, -264($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -272($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -276($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -276($fp)
mul $t2, $t0, $t1
sw $t2, -280($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -280($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -284($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -272($fp)
mul $t2, $t0, $t1
sw $t2, -288($fp)
addi $sp, $sp, -4
lw $t0, -284($fp)
lw $t1, -288($fp)
add $t2, $t0, $t1
sw $t2, -292($fp)
addi $sp, $sp, -4
li $t0, 4
sw $t0, -296($fp)
lw $t0, -296($fp)
lw $t1, -292($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -300($fp)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -304($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -304($fp)
mul $t2, $t0, $t1
sw $t2, -308($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -308($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -312($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -300($fp)
mul $t2, $t0, $t1
sw $t2, -316($fp)
addi $sp, $sp, -4
lw $t0, -312($fp)
lw $t1, -316($fp)
add $t2, $t0, $t1
sw $t2, -320($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -324($fp)
lw $t0, -324($fp)
lw $t1, -320($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -328($fp)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -332($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -332($fp)
mul $t2, $t0, $t1
sw $t2, -336($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -336($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -340($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -328($fp)
mul $t2, $t0, $t1
sw $t2, -344($fp)
addi $sp, $sp, -4
lw $t0, -340($fp)
lw $t1, -344($fp)
add $t2, $t0, $t1
sw $t2, -348($fp)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -352($fp)
lw $t0, -352($fp)
lw $t1, -348($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -356($fp)
addi $sp, $sp, -4
lw $t0, -356($fp)
sw $t0, -360($fp)
label10:
addi $sp, $sp, -4
li $t0, 4
sw $t0, -364($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -368($fp)
addi $sp, $sp, -4
lw $t0, -360($fp)
lw $t1, -364($fp)
sub $t2, $t0, $t1
sw $t2, -372($fp)
lw $t0, -372($fp)
li $t1, 0
blt $t0, $t1, label12
li $t0, 0
sw $t0, -368($fp)
label12:
lw $t0, -368($fp)
li $t1, 0
beq $t0, $t1, label11
addi $sp, $sp, -4
li $t0, 0
sw $t0, -376($fp)
lw $t0, -376($fp)
sw $t0, -72($fp)
label13:
addi $sp, $sp, -4
li $t0, 4
sw $t0, -380($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -384($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -380($fp)
sub $t2, $t0, $t1
sw $t2, -388($fp)
lw $t0, -388($fp)
li $t1, 0
blt $t0, $t1, label15
li $t0, 0
sw $t0, -384($fp)
label15:
lw $t0, -384($fp)
li $t1, 0
beq $t0, $t1, label14
addi $sp, $sp, -4
li $t0, 0
sw $t0, -392($fp)
lw $t0, -392($fp)
sw $t0, -92($fp)
label16:
addi $sp, $sp, -4
li $t0, 4
sw $t0, -396($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -400($fp)
addi $sp, $sp, -4
lw $t0, -92($fp)
lw $t1, -396($fp)
sub $t2, $t0, $t1
sw $t2, -404($fp)
lw $t0, -404($fp)
li $t1, 0
blt $t0, $t1, label18
li $t0, 0
sw $t0, -400($fp)
label18:
lw $t0, -400($fp)
li $t1, 0
beq $t0, $t1, label17
addi $sp, $sp, -4
li $t1, 16
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -408($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -408($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -412($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -360($fp)
mul $t2, $t0, $t1
sw $t2, -416($fp)
addi $sp, $sp, -4
lw $t0, -412($fp)
lw $t1, -416($fp)
add $t2, $t0, $t1
sw $t2, -420($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -360($fp)
mul $t2, $t0, $t1
sw $t2, -424($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -424($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -428($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -92($fp)
mul $t2, $t0, $t1
sw $t2, -432($fp)
addi $sp, $sp, -4
lw $t0, -428($fp)
lw $t1, -432($fp)
add $t2, $t0, $t1
sw $t2, -436($fp)
addi $sp, $sp, -4
lw $t0, -436($fp)
lw $t1, 0($t0)
sw $t1, -440($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, 0($t0)
sw $t1, -444($fp)
addi $sp, $sp, -4
lw $t0, -444($fp)
lw $t1, -440($fp)
add $t2, $t0, $t1
sw $t2, -448($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -452($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -452($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -456($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -92($fp)
mul $t2, $t0, $t1
sw $t2, -460($fp)
addi $sp, $sp, -4
lw $t0, -456($fp)
lw $t1, -460($fp)
add $t2, $t0, $t1
sw $t2, -464($fp)
addi $sp, $sp, -4
lw $t0, -464($fp)
lw $t1, 0($t0)
sw $t1, -468($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -472($fp)
addi $sp, $sp, -4
lw $t0, -448($fp)
lw $t1, -468($fp)
sub $t2, $t0, $t1
sw $t2, -476($fp)
lw $t0, -476($fp)
li $t1, 0
blt $t0, $t1, label20
li $t0, 0
sw $t0, -472($fp)
label20:
lw $t0, -472($fp)
li $t1, 0
beq $t0, $t1, label19
addi $sp, $sp, -4
li $t1, 16
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -480($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -480($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -484($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -92($fp)
mul $t2, $t0, $t1
sw $t2, -488($fp)
addi $sp, $sp, -4
lw $t0, -484($fp)
lw $t1, -488($fp)
add $t2, $t0, $t1
sw $t2, -492($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -496($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -496($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -500($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -360($fp)
mul $t2, $t0, $t1
sw $t2, -504($fp)
addi $sp, $sp, -4
lw $t0, -500($fp)
lw $t1, -504($fp)
add $t2, $t0, $t1
sw $t2, -508($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -360($fp)
mul $t2, $t0, $t1
sw $t2, -512($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -512($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -516($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -92($fp)
mul $t2, $t0, $t1
sw $t2, -520($fp)
addi $sp, $sp, -4
lw $t0, -516($fp)
lw $t1, -520($fp)
add $t2, $t0, $t1
sw $t2, -524($fp)
addi $sp, $sp, -4
lw $t0, -524($fp)
lw $t1, 0($t0)
sw $t1, -528($fp)
addi $sp, $sp, -4
lw $t0, -508($fp)
lw $t1, 0($t0)
sw $t1, -532($fp)
addi $sp, $sp, -4
lw $t0, -532($fp)
lw $t1, -528($fp)
add $t2, $t0, $t1
sw $t2, -536($fp)
lw $t0, -536($fp)
lw $t1, -492($fp)
sw $t0, 0($t1)
label19:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -540($fp)
addi $sp, $sp, -4
lw $t0, -92($fp)
lw $t1, -540($fp)
add $t2, $t0, $t1
sw $t2, -544($fp)
lw $t0, -544($fp)
sw $t0, -92($fp)
j label16
label17:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -548($fp)
addi $sp, $sp, -4
lw $t0, -72($fp)
lw $t1, -548($fp)
add $t2, $t0, $t1
sw $t2, -552($fp)
lw $t0, -552($fp)
sw $t0, -72($fp)
j label13
label14:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -556($fp)
addi $sp, $sp, -4
lw $t0, -360($fp)
lw $t1, -556($fp)
add $t2, $t0, $t1
sw $t2, -560($fp)
lw $t0, -560($fp)
sw $t0, -360($fp)
j label10
label11:
addi $sp, $sp, -4
li $t0, 3
sw $t0, -564($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -568($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -568($fp)
mul $t2, $t0, $t1
sw $t2, -572($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -572($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -576($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -564($fp)
mul $t2, $t0, $t1
sw $t2, -580($fp)
addi $sp, $sp, -4
lw $t0, -576($fp)
lw $t1, -580($fp)
add $t2, $t0, $t1
sw $t2, -584($fp)
addi $sp, $sp, -4
lw $t0, -584($fp)
lw $t1, 0($t0)
sw $t1, -588($fp)
lw $a0, -588($fp)
move $sp, $fp
addi $sp, $sp, -588
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 2
sw $t0, -592($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -596($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -596($fp)
mul $t2, $t0, $t1
sw $t2, -600($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -600($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -604($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -592($fp)
mul $t2, $t0, $t1
sw $t2, -608($fp)
addi $sp, $sp, -4
lw $t0, -604($fp)
lw $t1, -608($fp)
add $t2, $t0, $t1
sw $t2, -612($fp)
addi $sp, $sp, -4
lw $t0, -612($fp)
lw $t1, 0($t0)
sw $t1, -616($fp)
lw $a0, -616($fp)
move $sp, $fp
addi $sp, $sp, -616
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 1
sw $t0, -620($fp)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -624($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -624($fp)
mul $t2, $t0, $t1
sw $t2, -628($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -628($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -632($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -620($fp)
mul $t2, $t0, $t1
sw $t2, -636($fp)
addi $sp, $sp, -4
lw $t0, -632($fp)
lw $t1, -636($fp)
add $t2, $t0, $t1
sw $t2, -640($fp)
addi $sp, $sp, -4
lw $t0, -640($fp)
lw $t1, 0($t0)
sw $t1, -644($fp)
lw $a0, -644($fp)
move $sp, $fp
addi $sp, $sp, -644
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -648($fp)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -652($fp)
addi $sp, $sp, -4
li $t1, 16
lw $t0, -652($fp)
mul $t2, $t0, $t1
sw $t2, -656($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -64  #t0 := &t1 + t2
lw $t1, -656($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -660($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -648($fp)
mul $t2, $t0, $t1
sw $t2, -664($fp)
addi $sp, $sp, -4
lw $t0, -660($fp)
lw $t1, -664($fp)
add $t2, $t0, $t1
sw $t2, -668($fp)
addi $sp, $sp, -4
lw $t0, -668($fp)
lw $t1, 0($t0)
sw $t1, -672($fp)
lw $a0, -672($fp)
move $sp, $fp
addi $sp, $sp, -672
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -676($fp)
lw $v0, -676($fp)
move $sp, $fp
jr $ra
