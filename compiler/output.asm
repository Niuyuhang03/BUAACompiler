.data
	$string_0: .asciiz "\n"
	max: .word 100
	min: .word 0
	fail: .word 110
	num: .word 0
.text
	j label_0
label_1:
	sw $a0, 4($sp)
	sw $a1, 8($sp)
	lw $t0, 4($sp)
	sw $t0, 12($sp)
	lw $a0, 12($sp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, 8($sp)
	sw $t0, 16($sp)
	lw $a0, 16($sp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, 4($sp)
	sw $t0, 20($sp)
	li $t0, 1
	sw $t0, 24($sp)
	lw $t0, 20($sp)
	lw $t1, 24($sp)
	add $t0, $t0, $t1
	sw $t0, 28($sp)
	lw $v0, 28($sp)
	jr $ra
	jr $ra
label_0:
	li $v0, 5
	syscall
	la $t1, num
	sw $v0, ($t1)
	li $v0, 12
	syscall
	sw $v0, 32($sp)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 40($sp)
	lw $a0, 40($sp)
	lw $t0, 32($sp)
	sw $t0, 44($sp)
	lw $a1, 44($sp)
	addiu, $sp, $sp, -32
	jal label_1
	addiu, $sp, $sp, 32
	sw $v0, 48($sp)
	lw $t0, 48($sp)
	sw $t0, 36($sp)
	lw $t0, 36($sp)
	sw $t0, 52($sp)
	lw $a0, 52($sp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $v0, 10
	syscall
