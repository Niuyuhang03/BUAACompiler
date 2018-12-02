.data
	$string_0: .asciiz "\n"
	$string_1: .asciiz "result:"
	$string_2: .asciiz "y"
	$string_3: .asciiz "result:"
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
	la $t0, result
	lw $t0, ($t0)
	sw $t0, 28($sp)
	la $a0, $string_1
	li $v0, 4
	syscall
	lw $a0, 28($sp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_3:
	sw $a2, 36($sp)
	lw $t0, 36($sp)
	sw $t0, 44($sp)
	li $t0, 1
	sw $t0, 48($sp)
	lw $t0, 44($sp)
	lw $t1, 48($sp)
	bne $t0, $t1, label_4
	addiu, $sp, $sp, -8
	sw $ra, ($sp)
	jal label_2
	lw $ra, ($sp)
	addiu, $sp, $sp, 8
label_4:
	lw $t0, 36($sp)
	sw $t0, 52($sp)
	li $t0, 1
	sw $t0, 56($sp)
	lw $t0, 52($sp)
	lw $t1, 56($sp)
	sub $t0, $t0, $t1
	blez $t0, label_6
	la $t0, result
	lw $t0, ($t0)
	sw $t0, 60($sp)
	lw $t0, 36($sp)
	sw $t0, 64($sp)
	lw $t0, 60($sp)
	lw $t1, 64($sp)
	mult $t0, $t1
	mflo $t0
	sw $t0, 68($sp)
	lw $t0, 68($sp)
	la $t1, result
	sw $t0, ($t1)
	lw $t0, 36($sp)
	sw $t0, 72($sp)
	li $t0, 1
	sw $t0, 76($sp)
	lw $t0, 72($sp)
	lw $t1, 76($sp)
	sub $t0, $t0, $t1
	sw $t0, 80($sp)
	lw $a0, 80($sp)
	addiu, $sp, $sp, -56
	sw $ra, ($sp)
	jal label_3
	lw $ra, ($sp)
	addiu, $sp, $sp, 56
label_6:
	li $t0, 0
	sw $t0, 84($sp)
	lw $v0, 84($sp)
	jr $ra
	jr $ra
label_0:
	li $t0, 49
	sw $t0, 88($sp)
	li $t0, 0
	sw $t0, 104($sp)
	lw $t0, 104($sp)
	sw $t0, 92($sp)
	li $t0, 1
	sw $t0, 108($sp)
	lw $t0, 108($sp)
	la $t1, result
	sw $t0, ($t1)
	li $v0, 5
	syscall
	la $t1, num
	sw $v0, ($t1)
	li $v0, 5
	syscall
	sw $v0, 96($sp)
	li $v0, 12
	syscall
	sw $v0, 100($sp)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 112($sp)
	la $t0, max
	lw $t0, ($t0)
	sw $t0, 116($sp)
	lw $t0, 112($sp)
	lw $t1, 116($sp)
	sub $t0, $t0, $t1
	blez $t0, label_8
	la $t0, fail
	lw $t0, ($t0)
	sw $t0, 120($sp)
	lw $a0, 120($sp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_8:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 124($sp)
	la $t0, min
	lw $t0, ($t0)
	sw $t0, 128($sp)
	lw $t0, 124($sp)
	lw $t1, 128($sp)
	sub $t0, $t0, $t1
	bgez $t0, label_9
	la $a0, $string_2
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_9:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 132($sp)
	li $t0, 0
	sw $t0, 136($sp)
	lw $t0, 132($sp)
	lw $t1, 136($sp)
	bne $t0, $t1, label_10
	li $t0, 1
	sw $t0, 140($sp)
	lw $t0, 140($sp)
	sw $t0, 92($sp)
label_10:
	lw $t0, 92($sp)
	sw $t0, 144($sp)
	li $t0, 0
	sw $t0, 148($sp)
	lw $t0, 144($sp)
	lw $t1, 148($sp)
	beq $t0, $t1, label_11
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 152($sp)
	li $t0, 1
	sw $t0, 156($sp)
	lw $t0, 152($sp)
	lw $t1, 156($sp)
	add $t0, $t0, $t1
	sw $t0, 160($sp)
	la $a0, $string_3
	li $v0, 4
	syscall
	lw $a0, 160($sp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_11:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 164($sp)
	lw $a0, 164($sp)
	addiu, $sp, $sp, -56
	sw $ra, ($sp)
	jal label_3
	lw $ra, ($sp)
	addiu, $sp, $sp, 56
	li $v0, 10
	syscall
