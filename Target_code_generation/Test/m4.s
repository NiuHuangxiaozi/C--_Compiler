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

see:
move $fp, $sp
lw $t0, 8($fp)
addi $sp, $sp, -4
sw $t0, -4($fp)
lw $a0, -4($fp)
move $sp, $fp
addi $sp, $sp, -4
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -8($fp)
lw $v0, -8($fp)
move $sp, $fp
jr $ra

main:
move $fp, $sp
addi $sp, $sp, -8
addi $sp, $sp, -4
li $t0, 1
sw $t0, -12($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -12($fp)
mul $t2, $t0, $t1
sw $t2, -16($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -8  #t0 := &t1 + t2
lw $t1, -16($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -20($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
li $t0, 3
sw $t0, -24($fp)
lw $t0, -24($fp)
lw $t1, -20($fp)
sw $t0, 0($t1)
addi $sp, $sp, -4
li $t0, 1
sw $t0, -28($fp)
addi $sp, $sp, -4
li $t1, 4
lw $t0, -28($fp)
mul $t2, $t0, $t1
sw $t2, -32($fp)
addi $sp, $sp, -4
move $t0, $fp #t0 := &t1 + t2
addi $t0, $t0, -8  #t0 := &t1 + t2
lw $t1, -32($fp)  #t0 := &t1 + t2
add $t2, $t0, $t1  #t0 := &t1 + t2
sw $t2, -36($fp) #t0 := &t1 + t2
addi $sp, $sp, -4
lw $t0, -36($fp)
lw $t1, 0($t0)
sw $t1, -40($fp)
move $sp, $fp
addi $sp, $sp, -40
lw $t0, -40($fp)
addi $sp, $sp, -4
sw $t0, 0($sp)
addi $sp, $sp, -8
sw $ra, 0($sp)
sw $fp, 4($sp)
jal see
lw $ra, 0($sp)
lw $fp, 4($sp)
addi $sp, $sp, 8
addi $sp, $sp, 4
addi $sp, $sp, -4
li $t0, 0
sw $t0, -44($fp)
lw $v0, -44($fp)
move $sp, $fp
jr $ra
