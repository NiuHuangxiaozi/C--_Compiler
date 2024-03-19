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
li $t0, 0
sw $t0, -4($fp)
addi $sp, $sp, -4
lw $t0, -4($fp)
sw $t0, -8($fp)
addi $sp, $sp, -4
li $t0, 369
sw $t0, -12($fp)
addi $sp, $sp, -4
lw $t0, -12($fp)
sw $t0, -16($fp)
addi $sp, $sp, -4
li $t0, 258
sw $t0, -20($fp)
addi $sp, $sp, -4
lw $t0, -20($fp)
sw $t0, -24($fp)
addi $sp, $sp, -4
li $t0, 147
sw $t0, -28($fp)
addi $sp, $sp, -4
lw $t0, -28($fp)
sw $t0, -32($fp)
addi $sp, $sp, -4
lw $t0, -16($fp)
lw $t1, -24($fp)
add $t2, $t0, $t1
sw $t2, -36($fp)
addi $sp, $sp, -4
lw $t0, -36($fp)
lw $t1, -32($fp)
add $t2, $t0, $t1
sw $t2, -40($fp)
addi $sp, $sp, -4
lw $t0, -16($fp)
lw $t1, -24($fp)
sub $t2, $t0, $t1
sw $t2, -44($fp)
addi $sp, $sp, -4
lw $t1, -44($fp)
lw $t0, -40($fp)
mul $t2, $t0, $t1
sw $t2, -48($fp)
addi $sp, $sp, -4
lw $t0, -16($fp)
lw $t1, -32($fp)
sub $t2, $t0, $t1
sw $t2, -52($fp)
addi $sp, $sp, -4
lw $t1, -52($fp)
lw $t0, -48($fp)
div $t0, $t1
mflo $t2
sw $t2, -56($fp)
addi $sp, $sp, -4
lw $t0, -56($fp)
sw $t0, -60($fp)
lw $a0, -60($fp)
move $sp, $fp
addi $sp, $sp, -60
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 2
sw $t0, -64($fp)
addi $sp, $sp, -4
lw $t1, -64($fp)
lw $t0, -60($fp)
mul $t2, $t0, $t1
sw $t2, -68($fp)
addi $sp, $sp, -4
li $t0, 3
sw $t0, -72($fp)
addi $sp, $sp, -4
lw $t1, -72($fp)
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -76($fp)
addi $sp, $sp, -4
lw $t1, -76($fp)
lw $t0, -68($fp)
div $t0, $t1
mflo $t2
sw $t2, -80($fp)
addi $sp, $sp, -4
lw $t0, -60($fp)
lw $t1, -80($fp)
add $t2, $t0, $t1
sw $t2, -84($fp)
lw $t0, -84($fp)
sw $t0, -60($fp)
lw $a0, -60($fp)
move $sp, $fp
addi $sp, $sp, -84
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
lw $t1, -24($fp)
lw $t0, -16($fp)
mul $t2, $t0, $t1
sw $t2, -88($fp)
addi $sp, $sp, -4
lw $t1, -32($fp)
lw $t0, -24($fp)
mul $t2, $t0, $t1
sw $t2, -92($fp)
addi $sp, $sp, -4
lw $t0, -88($fp)
lw $t1, -92($fp)
add $t2, $t0, $t1
sw $t2, -96($fp)
addi $sp, $sp, -4
lw $t1, -16($fp)
lw $t0, -32($fp)
mul $t2, $t0, $t1
sw $t2, -100($fp)
addi $sp, $sp, -4
lw $t0, -96($fp)
lw $t1, -100($fp)
add $t2, $t0, $t1
sw $t2, -104($fp)
addi $sp, $sp, -4
lw $t0, -104($fp)
lw $t1, -60($fp)
add $t2, $t0, $t1
sw $t2, -108($fp)
lw $t0, -108($fp)
sw $t0, -8($fp)
lw $a0, -8($fp)
move $sp, $fp
addi $sp, $sp, -108
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -112($fp)
lw $v0, -112($fp)
move $sp, $fp
jr $ra
