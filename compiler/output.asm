.data
	$string_0: .asciiz "\n"
	$string_1: .asciiz "result:"
	max: .word 100
	min: .word 0
	fail: .word 110
	num: .word 0
	result: .word 0
	id: .word 0
	_a2: .word 0
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
	lw $t0, 28($sp)
	sw $t0, 36($sp)
	li $t0, 1
	sw $t0, 40($sp)
	lw $t0, 36($sp)
	lw $t1, 40($sp)
	bne $t0, $t1, label_3
	la $t0, result
	lw $t0, ($t0)
	sw $t0, 44($sp)
	la $a0, $string_1
	li $v0, 4
	syscall
	lw $a0, 44($sp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_3:
	lw $t0, 28($sp)
	sw $t0, 48($sp)
	li $t0, 1
	sw $t0, 52($sp)
	lw $t0, 48($sp)
	lw $t1, 52($sp)
	sub $t0, $t0, $t1
	blez $t0, label_4
	la $t0, result
	lw $t0, ($t0)
	sw $t0, 56($sp)
	lw $t0, 28($sp)
	sw $t0, 60($sp)
	lw $t0, 56($sp)
	lw $t1, 60($sp)
	mult $t0, $t1
	mflo $t0
	sw $t0, 64($sp)
	lw $t0, 64($sp)
	la $t1, result
	sw $t0, ($t1)
	lw $t0, 28($sp)
	sw $t0, 68($sp)
	li $t0, 1
	sw $t0, 72($sp)
	lw $t0, 68($sp)
	lw $t1, 72($sp)
	sub $t0, $t0, $t1
	sw $t0, 76($sp)
	lw $a0, 76($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -340
	jal label_2
	addiu $sp, $sp, 340
	lw $ra, ($sp)
label_4:
	li $t0, 0
	sw $t0, 80($sp)
	lw $v0, 80($sp)
	jr $ra
	jr $ra
label_0:
	li $t0, 49
	sw $t0, 4($sp)
	li $t0, 0
	sw $t0, 20($sp)
	lw $t0, 20($sp)
	sw $t0, 8($sp)
	li $t0, 1
	sw $t0, 24($sp)
	lw $t0, 24($sp)
	la $t1, result
	sw $t0, ($t1)
	li $v0, 5
	syscall
	la $t1, num
	sw $v0, ($t1)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 28($sp)
	lw $a0, 28($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -340
	jal label_2
	addiu $sp, $sp, 340
	lw $ra, ($sp)
	li $v0, 10
	syscall
