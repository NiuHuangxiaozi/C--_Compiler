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

initW:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -8($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -8($fp)
mul $t2, $t0, $t1
sw $t2, -12($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -12($fp)
add $t2, $t0, $t1
sw $t2, -16($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -20($fp)
lw $t0, -20($fp)
lw $t1, -16($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -24($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -24($fp)
mul $t2, $t0, $t1
sw $t2, -28($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -28($fp)
add $t2, $t0, $t1
sw $t2, -32($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -36($fp)
lw $t0, -36($fp)
lw $t1, -32($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -40($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -40($fp)
mul $t2, $t0, $t1
sw $t2, -44($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -44($fp)
add $t2, $t0, $t1
sw $t2, -48($fp)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -52($fp)
lw $t0, -52($fp)
lw $t1, -48($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -56($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -60($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -60($fp)
add $t2, $t0, $t1
sw $t2, -64($fp)
addi $sp, $sp, -4
li $t0, 5
sw $t0, -68($fp)
lw $t0, -68($fp)
lw $t1, -64($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 4
sw $t0, -72($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -76($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -76($fp)
add $t2, $t0, $t1
sw $t2, -80($fp)
addi $sp, $sp, -4
li $t0, 6
sw $t0, -84($fp)
lw $t0, -84($fp)
lw $t1, -80($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 5
sw $t0, -88($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -88($fp)
mul $t2, $t0, $t1
sw $t2, -92($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -96($fp)
addi $sp, $sp, -4
li $t0, 7
sw $t0, -100($fp)
lw $t0, -100($fp)
lw $t1, -96($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -104($fp)
lw $v0, -104($fp)
move $sp, $fp
jr $ra

initV:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -8($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -8($fp)
mul $t2, $t0, $t1
sw $t2, -12($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -12($fp)
add $t2, $t0, $t1
sw $t2, -16($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -20($fp)
lw $t0, -20($fp)
lw $t1, -16($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -24($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -24($fp)
mul $t2, $t0, $t1
sw $t2, -28($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -28($fp)
add $t2, $t0, $t1
sw $t2, -32($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -36($fp)
lw $t0, -36($fp)
lw $t1, -32($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 2
sw $t0, -40($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -40($fp)
mul $t2, $t0, $t1
sw $t2, -44($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -44($fp)
add $t2, $t0, $t1
sw $t2, -48($fp)
addi $sp, $sp, -4
li $t0, 6
sw $t0, -52($fp)
lw $t0, -52($fp)
lw $t1, -48($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -56($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -56($fp)
mul $t2, $t0, $t1
sw $t2, -60($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -60($fp)
add $t2, $t0, $t1
sw $t2, -64($fp)
addi $sp, $sp, -4
li $t0, 18
sw $t0, -68($fp)
lw $t0, -68($fp)
lw $t1, -64($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 4
sw $t0, -72($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -72($fp)
mul $t2, $t0, $t1
sw $t2, -76($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -76($fp)
add $t2, $t0, $t1
sw $t2, -80($fp)
addi $sp, $sp, -4
li $t0, 22
sw $t0, -84($fp)
lw $t0, -84($fp)
lw $t1, -80($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 5
sw $t0, -88($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -88($fp)
mul $t2, $t0, $t1
sw $t2, -92($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -96($fp)
addi $sp, $sp, -4
li $t0, 28
sw $t0, -100($fp)
lw $t0, -100($fp)
lw $t1, -96($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -104($fp)
lw $v0, -104($fp)
move $sp, $fp
jr $ra

main:
move $fp, $sp
addi $sp, $sp, -24
addi $sp, $sp, -24
addi $sp, $sp, -288
move $t0, $fp
addi $t0, $t0, -24
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal initW
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
move $t0, $fp
addi $t0, $t0, -48
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal initV
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -340($fp)
addi $sp, $sp, -4
lw $t0, -340($fp)
sw $t0, -344($fp)
label1:
addi $sp, $sp, -4
li $t0, 6
sw $t0, -348($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -352($fp)
addi $sp, $sp, -4
lw $t0, -344($fp)
lw $t1, -348($fp)
sub $t2, $t0, $t1
sw $t2, -356($fp)
lw $t0, -356($fp)
li $t1, 0
blt $t0, $t1, label3
li $t0, 0
sw $t0, -352($fp)
label3:
lw $t0, -352($fp)
li $t1, 0
beq $t0, $t1, label2
addi $sp, $sp, -4
li $t0, 0
sw $t0, -360($fp)
addi $sp, $sp, -4
lw $t0, -360($fp)
sw $t0, -364($fp)
label4:
addi $sp, $sp, -4
li $t0, 12
sw $t0, -368($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -372($fp)
addi $sp, $sp, -4
lw $t0, -364($fp)
lw $t1, -368($fp)
sub $t2, $t0, $t1
sw $t2, -376($fp)
lw $t0, -376($fp)
li $t1, 0
blt $t0, $t1, label6
li $t0, 0
sw $t0, -372($fp)
label6:
lw $t0, -372($fp)
li $t1, 0
beq $t0, $t1, label5
addi $sp, $sp, -4
li $t1, 48
lw $t0, -344($fp)
mul $t2, $t0, $t1
sw $t2, -380($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -380($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -384($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -364($fp)
mul $t2, $t0, $t1
sw $t2, -388($fp)
addi $sp, $sp, -4
lw $t0, -384($fp)
lw $t1, -388($fp)
add $t2, $t0, $t1
sw $t2, -392($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -396($fp)
lw $t0, -396($fp)
lw $t1, -392($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -400($fp)
addi $sp, $sp, -4
lw $t0, -364($fp)
lw $t1, -400($fp)
add $t2, $t0, $t1
sw $t2, -404($fp)
lw $t0, -404($fp)
sw $t0, -364($fp)
j label4
label5:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -408($fp)
addi $sp, $sp, -4
lw $t0, -344($fp)
lw $t1, -408($fp)
add $t2, $t0, $t1
sw $t2, -412($fp)
lw $t0, -412($fp)
sw $t0, -344($fp)
j label1
label2:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -416($fp)
addi $sp, $sp, -4
lw $t0, -416($fp)
sw $t0, -420($fp)
label7:
addi $sp, $sp, -4
li $t0, 6
sw $t0, -424($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -428($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, -424($fp)
sub $t2, $t0, $t1
sw $t2, -432($fp)
lw $t0, -432($fp)
li $t1, 0
blt $t0, $t1, label9
li $t0, 0
sw $t0, -428($fp)
label9:
lw $t0, -428($fp)
li $t1, 0
beq $t0, $t1, label8
addi $sp, $sp, -4
li $t0, 1
sw $t0, -436($fp)
addi $sp, $sp, -4
lw $t0, -436($fp)
sw $t0, -440($fp)
label10:
addi $sp, $sp, -4
li $t0, 12
sw $t0, -444($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -448($fp)
addi $sp, $sp, -4
lw $t0, -440($fp)
lw $t1, -444($fp)
sub $t2, $t0, $t1
sw $t2, -452($fp)
lw $t0, -452($fp)
li $t1, 0
blt $t0, $t1, label12
li $t0, 0
sw $t0, -448($fp)
label12:
lw $t0, -448($fp)
li $t1, 0
beq $t0, $t1, label11
addi $sp, $sp, -4
li $t1, 4
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -456($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -24  #t0 := &t1 + t2
lw $t1, -456($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -460($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -460($fp)
lw $t1, 0($t0)
sw $t1, -464($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -468($fp)
addi $sp, $sp, -4
lw $t0, -440($fp)
lw $t1, -464($fp)
sub $t2, $t0, $t1
sw $t2, -472($fp)
lw $t0, -472($fp)
li $t1, 0
blt $t0, $t1, label14
li $t0, 0
sw $t0, -468($fp)
label14:
lw $t0, -468($fp)
li $t1, 0
beq $t0, $t1, label13
addi $sp, $sp, -4
li $t1, 48
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -476($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -476($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -480($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -440($fp)
mul $t2, $t0, $t1
sw $t2, -484($fp)
addi $sp, $sp, -4
lw $t0, -480($fp)
lw $t1, -484($fp)
add $t2, $t0, $t1
sw $t2, -488($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -492($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, -492($fp)
sub $t2, $t0, $t1
sw $t2, -496($fp)
addi $sp, $sp, -4
li $t1, 48
lw $t0, -496($fp)
mul $t2, $t0, $t1
sw $t2, -500($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -500($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -504($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -440($fp)
mul $t2, $t0, $t1
sw $t2, -508($fp)
addi $sp, $sp, -4
lw $t0, -504($fp)
lw $t1, -508($fp)
add $t2, $t0, $t1
sw $t2, -512($fp)
addi $sp, $sp, -4
lw $t0, -512($fp)
addi $t2, $t0, 0
sw $t2, -516($fp)
addi $sp, $sp, -4
lw $t0, -516($fp)
lw $t1, 0($t0)
sw $t1, -520($fp)
addi $sp, $sp, -4
lw $t0, -488($fp)
addi $t2, $t0, 0
sw $t2, -524($fp)
lw $t0, -520($fp)
lw $t1, -524($fp)
sw $t0, 0($t1)
j label15
label13:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -528($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, -528($fp)
sub $t2, $t0, $t1
sw $t2, -532($fp)
addi $sp, $sp, -4
li $t1, 48
lw $t0, -532($fp)
mul $t2, $t0, $t1
sw $t2, -536($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -536($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -540($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -440($fp)
mul $t2, $t0, $t1
sw $t2, -544($fp)
addi $sp, $sp, -4
lw $t0, -540($fp)
lw $t1, -544($fp)
add $t2, $t0, $t1
sw $t2, -548($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -552($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -552($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -556($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -560($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -24  #t0 := &t1 + t2
lw $t1, -560($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -564($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -564($fp)
lw $t1, 0($t0)
sw $t1, -568($fp)
addi $sp, $sp, -4
lw $t0, -440($fp)
lw $t1, -568($fp)
sub $t2, $t0, $t1
sw $t2, -572($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -576($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, -576($fp)
sub $t2, $t0, $t1
sw $t2, -580($fp)
addi $sp, $sp, -4
li $t1, 48
lw $t0, -580($fp)
mul $t2, $t0, $t1
sw $t2, -584($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -584($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -588($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -572($fp)
mul $t2, $t0, $t1
sw $t2, -592($fp)
addi $sp, $sp, -4
lw $t0, -588($fp)
lw $t1, -592($fp)
add $t2, $t0, $t1
sw $t2, -596($fp)
addi $sp, $sp, -4
lw $t0, -596($fp)
lw $t1, 0($t0)
sw $t1, -600($fp)
addi $sp, $sp, -4
lw $t0, -556($fp)
lw $t1, 0($t0)
sw $t1, -604($fp)
addi $sp, $sp, -4
lw $t0, -604($fp)
lw $t1, -600($fp)
add $t2, $t0, $t1
sw $t2, -608($fp)
addi $sp, $sp, -4
lw $t0, -548($fp)
lw $t1, 0($t0)
sw $t1, -612($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -616($fp)
addi $sp, $sp, -4
lw $t0, -612($fp)
lw $t1, -608($fp)
sub $t2, $t0, $t1
sw $t2, -620($fp)
lw $t0, -620($fp)
li $t1, 0
bgt $t0, $t1, label17
li $t0, 0
sw $t0, -616($fp)
label17:
lw $t0, -616($fp)
li $t1, 0
beq $t0, $t1, label16
addi $sp, $sp, -4
li $t1, 48
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -624($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -624($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -628($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -440($fp)
mul $t2, $t0, $t1
sw $t2, -632($fp)
addi $sp, $sp, -4
lw $t0, -628($fp)
lw $t1, -632($fp)
add $t2, $t0, $t1
sw $t2, -636($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -640($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, -640($fp)
sub $t2, $t0, $t1
sw $t2, -644($fp)
addi $sp, $sp, -4
li $t1, 48
lw $t0, -644($fp)
mul $t2, $t0, $t1
sw $t2, -648($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -648($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -652($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -440($fp)
mul $t2, $t0, $t1
sw $t2, -656($fp)
addi $sp, $sp, -4
lw $t0, -652($fp)
lw $t1, -656($fp)
add $t2, $t0, $t1
sw $t2, -660($fp)
addi $sp, $sp, -4
lw $t0, -660($fp)
addi $t2, $t0, 0
sw $t2, -664($fp)
addi $sp, $sp, -4
lw $t0, -664($fp)
lw $t1, 0($t0)
sw $t1, -668($fp)
addi $sp, $sp, -4
lw $t0, -636($fp)
addi $t2, $t0, 0
sw $t2, -672($fp)
lw $t0, -668($fp)
lw $t1, -672($fp)
sw $t0, 0($t1)
j label18
label16:
addi $sp, $sp, -4
li $t1, 48
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -676($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -676($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -680($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -440($fp)
mul $t2, $t0, $t1
sw $t2, -684($fp)
addi $sp, $sp, -4
lw $t0, -680($fp)
lw $t1, -684($fp)
add $t2, $t0, $t1
sw $t2, -688($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -692($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -48  #t0 := &t1 + t2
lw $t1, -692($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -696($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -420($fp)
mul $t2, $t0, $t1
sw $t2, -700($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -24  #t0 := &t1 + t2
lw $t1, -700($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -704($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -704($fp)
lw $t1, 0($t0)
sw $t1, -708($fp)
addi $sp, $sp, -4
lw $t0, -440($fp)
lw $t1, -708($fp)
sub $t2, $t0, $t1
sw $t2, -712($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -716($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, -716($fp)
sub $t2, $t0, $t1
sw $t2, -720($fp)
addi $sp, $sp, -4
li $t1, 48
lw $t0, -720($fp)
mul $t2, $t0, $t1
sw $t2, -724($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -724($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -728($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -712($fp)
mul $t2, $t0, $t1
sw $t2, -732($fp)
addi $sp, $sp, -4
lw $t0, -728($fp)
lw $t1, -732($fp)
add $t2, $t0, $t1
sw $t2, -736($fp)
addi $sp, $sp, -4
lw $t0, -736($fp)
lw $t1, 0($t0)
sw $t1, -740($fp)
addi $sp, $sp, -4
lw $t0, -696($fp)
lw $t1, 0($t0)
sw $t1, -744($fp)
addi $sp, $sp, -4
lw $t0, -744($fp)
lw $t1, -740($fp)
add $t2, $t0, $t1
sw $t2, -748($fp)
lw $t0, -748($fp)
lw $t1, -688($fp)
sw $t0, 0($t1)
label18:
label15:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -752($fp)
addi $sp, $sp, -4
lw $t0, -440($fp)
lw $t1, -752($fp)
add $t2, $t0, $t1
sw $t2, -756($fp)
lw $t0, -756($fp)
sw $t0, -440($fp)
j label10
label11:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -760($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
lw $t1, -760($fp)
add $t2, $t0, $t1
sw $t2, -764($fp)
lw $t0, -764($fp)
sw $t0, -420($fp)
j label7
label8:
addi $sp, $sp, -4
li $t0, 11
sw $t0, -768($fp)
addi $sp, $sp, -4
li $t0, 5
sw $t0, -772($fp)
addi $sp, $sp, -4
li $t1, 48
lw $t0, -772($fp)
mul $t2, $t0, $t1
sw $t2, -776($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -336  #t0 := &t1 + t2
lw $t1, -776($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -780($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -768($fp)
mul $t2, $t0, $t1
sw $t2, -784($fp)
addi $sp, $sp, -4
lw $t0, -780($fp)
lw $t1, -784($fp)
add $t2, $t0, $t1
sw $t2, -788($fp)
addi $sp, $sp, -4
lw $t0, -788($fp)
lw $t1, 0($t0)
sw $t1, -792($fp)
lw $a0, -792($fp)
move $sp, $fp
addi $sp, $sp, -792
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -796($fp)
lw $v0, -796($fp)
move $sp, $fp
jr $ra
