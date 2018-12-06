.data
	$string_0: .asciiz "\n"
.text
	j label_0
label_1:
	sw $a0, 4($sp)
	sw $a1, 8($sp)
	lw $t0, 4($sp)
	sw $t0, 12($sp)
	lw $t0, 8($sp)
	sw $t0, 16($sp)
	lw $t0, 12($sp)
	lw $t1, 16($sp)
	add $t0, $t0, $t1
	sw $t0, 20($sp)
	lw $v0, 20($sp)
	jr $ra
	jr $ra
label_2:
	sw $a0, 28($sp)
	sw $a1, 32($sp)
	lw $t0, 28($sp)
	sw $t0, 36($sp)
	lw $t0, 32($sp)
	sw $t0, 40($sp)
	lw $t0, 36($sp)
	lw $t1, 40($sp)
	add $t0, $t0, $t1
	sw $t0, 44($sp)
	lw $a0, 44($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -24
	jal label_1
	addiu $sp, $sp, 24
	lw $ra, ($sp)
	jr $ra
label_0:
	li $t0, 3
	sw $t0, 4($sp)
	lw $a0, 4($sp)
	li $t0, 1
	sw $t0, 8($sp)
	lw $a1, 8($sp)
	li $t0, 2
	sw $t0, 12($sp)
	lw $a2, 12($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -24
	jal label_1
	addiu $sp, $sp, 24
	lw $ra, ($sp)
	sw $v0, 16($sp)
	lw $a0, 16($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -48
	jal label_2
	addiu $sp, $sp, 48
	lw $ra, ($sp)
	li $v0, 10
	syscall
