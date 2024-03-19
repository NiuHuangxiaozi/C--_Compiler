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

mod:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
addi $sp, $sp, -4
lw $t1, -8($fp)
lw $t0, -4($fp)
div $t0, $t1
mflo $t2
sw $t2, -12($fp)
addi $sp, $sp, -4
lw $t1, -8($fp)
lw $t0, -12($fp)
mul $t2, $t0, $t1
sw $t2, -16($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -16($fp)
sub $t2, $t0, $t1
sw $t2, -20($fp)
lw $v0, -20($fp)
move $sp, $fp
jr $ra

gcd:
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
li $t0, 1
sw $t0, -16($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
lw $t1, -12($fp)
sub $t2, $t0, $t1
sw $t2, -20($fp)
lw $t0, -20($fp)
li $t1, 0
beq $t0, $t1, label2
li $t0, 0
sw $t0, -16($fp)
label2:
lw $t0, -16($fp)
li $t1, 0
beq $t0, $t1, label1
lw $v0, -8($fp)
move $sp, $fp
jr $ra
label1:
move $sp, $fp
addi $sp, $sp, -20
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
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
sw $v0, -24($fp)
move $sp, $fp
addi $sp, $sp, -24
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -24($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal gcd
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 8
addi $sp, $sp, -4
sw $v0, -28($fp)
lw $v0, -28($fp)
move $sp, $fp
jr $ra

lcm:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $t0, 12($fp)
addi $sp, $sp, -4
sw $t0, -8($fp)
addi $sp, $sp, -4
lw $t1, -8($fp)
lw $t0, -4($fp)
mul $t2, $t0, $t1
sw $t2, -12($fp)
move $sp, $fp
addi $sp, $sp, -12
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -4($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal gcd
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 8
addi $sp, $sp, -4
sw $v0, -16($fp)
addi $sp, $sp, -4
lw $t1, -16($fp)
lw $t0, -12($fp)
div $t0, $t1
mflo $t2
sw $t2, -20($fp)
lw $v0, -20($fp)
move $sp, $fp
jr $ra

main:
move $fp, $sp
addi $sp, $sp, -4
li $t0, 0
sw $t0, -4($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
sw $t0, -8($fp)
addi $sp, $sp, -200
addi $sp, $sp, -200
move $sp, $fp
addi $sp, $sp, -408
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -412($fp)
addi $sp, $sp, -4
lw $t0, -412($fp)
sw $t0, -416($fp)
addi $sp, $sp, -4
li $t0, 0
sw $t0, -420($fp)
addi $sp, $sp, -4
lw $t0, -420($fp)
sw $t0, -424($fp)
label3:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -428($fp)
addi $sp, $sp, -4
lw $t0, -424($fp)
lw $t1, -416($fp)
sub $t2, $t0, $t1
sw $t2, -432($fp)
lw $t0, -432($fp)
li $t1, 0
blt $t0, $t1, label5
li $t0, 0
sw $t0, -428($fp)
label5:
lw $t0, -428($fp)
li $t1, 0
beq $t0, $t1, label4
addi $sp, $sp, -4
li $t1, 4
lw $t0, -424($fp)
mul $t2, $t0, $t1
sw $t2, -436($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -208  #t0 := &t1 + t2
lw $t1, -436($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -440($fp) #t0 := &t1 + t2
move $sp, $fp
addi $sp, $sp, -440
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -444($fp)
lw $t0, -444($fp)
lw $t1, -440($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -424($fp)
mul $t2, $t0, $t1
sw $t2, -448($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -408  #t0 := &t1 + t2
lw $t1, -448($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -452($fp) #t0 := &t1 + t2
move $sp, $fp
addi $sp, $sp, -452
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
sw $v0, -456($fp)
lw $t0, -456($fp)
lw $t1, -452($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -460($fp)
addi $sp, $sp, -4
lw $t0, -424($fp)
lw $t1, -460($fp)
add $t2, $t0, $t1
sw $t2, -464($fp)
lw $t0, -464($fp)
sw $t0, -424($fp)
j label3
label4:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -468($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -468($fp)
mul $t2, $t0, $t1
sw $t2, -472($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -408  #t0 := &t1 + t2
lw $t1, -472($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -476($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -476($fp)
lw $t1, 0($t0)
sw $t1, -480($fp)
addi $sp, $sp, -4
lw $t0, -480($fp)
sw $t0, -484($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -488($fp)
lw $t0, -488($fp)
sw $t0, -424($fp)
label6:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -492($fp)
addi $sp, $sp, -4
lw $t0, -424($fp)
lw $t1, -416($fp)
sub $t2, $t0, $t1
sw $t2, -496($fp)
lw $t0, -496($fp)
li $t1, 0
blt $t0, $t1, label8
li $t0, 0
sw $t0, -492($fp)
label8:
lw $t0, -492($fp)
li $t1, 0
beq $t0, $t1, label7
addi $sp, $sp, -4
li $t1, 4
lw $t0, -424($fp)
mul $t2, $t0, $t1
sw $t2, -500($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -408  #t0 := &t1 + t2
lw $t1, -500($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -504($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -504($fp)
lw $t1, 0($t0)
sw $t1, -508($fp)
move $sp, $fp
addi $sp, $sp, -508
lw $t0, -508($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -484($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal lcm
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 8
addi $sp, $sp, -4
sw $v0, -512($fp)
lw $t0, -512($fp)
sw $t0, -484($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -516($fp)
addi $sp, $sp, -4
lw $t0, -424($fp)
lw $t1, -516($fp)
add $t2, $t0, $t1
sw $t2, -520($fp)
lw $t0, -520($fp)
sw $t0, -424($fp)
j label6
label7:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -524($fp)
lw $t0, -524($fp)
sw $t0, -424($fp)
label9:
addi $sp, $sp, -4
li $t0, 1
sw $t0, -528($fp)
addi $sp, $sp, -4
lw $t0, -424($fp)
lw $t1, -416($fp)
sub $t2, $t0, $t1
sw $t2, -532($fp)
lw $t0, -532($fp)
li $t1, 0
blt $t0, $t1, label11
li $t0, 0
sw $t0, -528($fp)
label11:
lw $t0, -528($fp)
li $t1, 0
beq $t0, $t1, label10
addi $sp, $sp, -4
li $t1, 4
lw $t0, -424($fp)
mul $t2, $t0, $t1
sw $t2, -536($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -208  #t0 := &t1 + t2
lw $t1, -536($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -540($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t1, 4
lw $t0, -424($fp)
mul $t2, $t0, $t1
sw $t2, -544($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -408  #t0 := &t1 + t2
lw $t1, -544($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -548($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -548($fp)
lw $t1, 0($t0)
sw $t1, -552($fp)
addi $sp, $sp, -4
lw $t1, -552($fp)
lw $t0, -484($fp)
div $t0, $t1
mflo $t2
sw $t2, -556($fp)
addi $sp, $sp, -4
lw $t0, -540($fp)
lw $t1, 0($t0)
sw $t1, -560($fp)
addi $sp, $sp, -4
lw $t1, -556($fp)
lw $t0, -560($fp)
mul $t2, $t0, $t1
sw $t2, -564($fp)
addi $sp, $sp, -4
lw $t0, -8($fp)
lw $t1, -564($fp)
add $t2, $t0, $t1
sw $t2, -568($fp)
lw $t0, -568($fp)
sw $t0, -8($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -572($fp)
addi $sp, $sp, -4
lw $t0, -424($fp)
lw $t1, -572($fp)
add $t2, $t0, $t1
sw $t2, -576($fp)
lw $t0, -576($fp)
sw $t0, -424($fp)
j label9
label10:
move $sp, $fp
addi $sp, $sp, -576
lw $t0, -484($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
lw $t0, -8($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal gcd
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 8
addi $sp, $sp, -4
sw $v0, -580($fp)
addi $sp, $sp, -4
lw $t0, -580($fp)
sw $t0, -584($fp)
addi $sp, $sp, -4
lw $t1, -584($fp)
lw $t0, -8($fp)
div $t0, $t1
mflo $t2
sw $t2, -588($fp)
lw $t0, -588($fp)
sw $t0, -8($fp)
addi $sp, $sp, -4
lw $t1, -584($fp)
lw $t0, -484($fp)
div $t0, $t1
mflo $t2
sw $t2, -592($fp)
lw $t0, -592($fp)
sw $t0, -484($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -596($fp)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -600($fp)
addi $sp, $sp, -4
lw $t0, -484($fp)
lw $t1, -596($fp)
sub $t2, $t0, $t1
sw $t2, -604($fp)
lw $t0, -604($fp)
li $t1, 0
beq $t0, $t1, label13
li $t0, 0
sw $t0, -600($fp)
label13:
lw $t0, -600($fp)
li $t1, 0
beq $t0, $t1, label12
lw $a0, -8($fp)
move $sp, $fp
addi $sp, $sp, -604
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
j label14
label12:
lw $a0, -8($fp)
move $sp, $fp
addi $sp, $sp, -604
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
lw $a0, -484($fp)
move $sp, $fp
addi $sp, $sp, -604
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
label14:
addi $sp, $sp, -4
li $t0, 0
sw $t0, -608($fp)
lw $v0, -608($fp)
move $sp, $fp
jr $ra
