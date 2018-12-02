.data
	$string_0: .asciiz "\n"
	num: .word 0
	array: .word 0:100
.text
	j label_0
label_1:
	sw $a0, 4($sp)
	li $t0, 3
	sw $t0, 12($sp)
	li $t0, 2
	sw $t0, 16($sp)
	lw $t0, 12($sp)
	lw $t1, 16($sp)
	add $t0, $t0, $t1
	sw $t0, 20($sp)
	lw $t0, 20($sp)
	sw $t0, 8($sp)
	jr $ra
label_0:
	li $t0, 0
	sw $t0, 28($sp)
	lw $t0, 28($sp)
	sw $t0, 24($sp)
	lw $t0, 24($sp)
	sw $t0, 32($sp)
	lw $t0, 32($sp)
	move $a0, $t0
	addiu, $sp, $sp, -24
	jal label_1
	addiu, $sp, $sp, 24
	li $v0, 10
	syscall
