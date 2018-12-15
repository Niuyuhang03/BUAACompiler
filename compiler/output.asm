.data
	$string_0: .asciiz "\n"
	$string_1: .asciiz "success!"
	$string_2: .asciiz "fail!"
	$string_3: .asciiz "success1!"
	$string_4: .asciiz "success2!"
	$string_5: .asciiz "fail1!"
	$string_6: .asciiz "success!"
	$string_7: .asciiz "fail!"
	$string_8: .asciiz "success!"
	$string_9: .asciiz "fail!"
	$string_10: .asciiz "Input is:"
	$string_11: .asciiz " x==y:true"
	$string_12: .asciiz " x>y:true"
	$string_13: .asciiz " x<y:true"
	$string_14: .asciiz " x>=y:true"
	$string_15: .asciiz " x<=y:true"
	$string_16: .asciiz " x!=y:true"
	$string_17: .asciiz "success!"
	$string_18: .asciiz "fail!"
	$string_19: .asciiz "fail1!"
	$string_20: .asciiz "success!"
	$string_21: .asciiz "fail2!"
	$string_22: .asciiz "the local scope_var = "
	$string_23: .asciiz "the global scope_var = "
	$string_24: .asciiz "the global scope_var = "
	$string_25: .asciiz "success!"
	$string_26: .asciiz "fail!"
	$string_27: .asciiz "test_recursion begin:"
	$string_28: .asciiz "test_if begin:"
	$string_29: .asciiz "test_while begin:"
	$string_30: .asciiz "test_switch begin:"
	$string_31: .asciiz "test_scanf_printf begin:"
	$string_32: .asciiz "test_expression begin:"
	$string_33: .asciiz "test_symbol begin:"
	$string_34: .asciiz "test_relation_operator begin:"
	$string_35: .asciiz "test_scope begin:"
	$string_36: .asciiz "*********************"
	$string_37: .asciiz "ch="
	$string_38: .asciiz "@#$$&*^^^^test end"
	con1: .word 1
	con2: .word 2
	ch1: .word 95
	i: .word 0
	j: .word 0
	array: .word 0:100
	scope_var: .word 0
	ch: .word 0
.text
	move $fp, $sp
	addiu $sp, $fp, -4
	j label_0
label_1:
	lw $t0, -0($fp)
	sw $t0, -12($fp)
	li $t0, 1
	sw $t0, -16($fp)
	lw $t0, -12($fp)
	lw $t1, -16($fp)
	bne $t0, $t1, label_2
	li $t0, 1
	sw $t0, -20($fp)
	lw $v0, -20($fp)
	jr $ra
label_2:
	lw $t0, -0($fp)
	sw $t0, -24($fp)
	li $t0, 2
	sw $t0, -28($fp)
	lw $t0, -24($fp)
	lw $t1, -28($fp)
	bne $t0, $t1, label_3
	li $t0, 1
	sw $t0, -32($fp)
	lw $v0, -32($fp)
	jr $ra
label_3:
	lw $t0, -0($fp)
	sw $t0, -36($fp)
	li $t0, 1
	sw $t0, -40($fp)
	lw $t0, -36($fp)
	lw $t1, -40($fp)
	sub $t0, $t0, $t1
	sw $t0, -44($fp)
	lw $t0, -44($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 4
	move $fp, $sp
	addiu $sp, $fp, -72
	jal label_1
	move $sp, $fp
	lw $fp, -8($sp)
	lw $ra, -4($sp)
	sw $v0, -48($fp)
	lw $t0, -0($fp)
	sw $t0, -52($fp)
	li $t0, 2
	sw $t0, -56($fp)
	lw $t0, -52($fp)
	lw $t1, -56($fp)
	sub $t0, $t0, $t1
	sw $t0, -60($fp)
	lw $t0, -60($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 4
	move $fp, $sp
	addiu $sp, $fp, -72
	jal label_1
	move $sp, $fp
	lw $fp, -8($sp)
	lw $ra, -4($sp)
	sw $v0, -64($fp)
	lw $t0, -48($fp)
	lw $t1, -64($fp)
	add $t0, $t0, $t1
	sw $t0, -68($fp)
	lw $v0, -68($fp)
	jr $ra
	jr $ra
label_6:
	li $t0, 8
	sw $t0, -8($fp)
	lw $t0, -8($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 4
	move $fp, $sp
	addiu $sp, $fp, -72
	jal label_1
	move $sp, $fp
	lw $fp, -8($sp)
	lw $ra, -4($sp)
	sw $v0, -12($fp)
	li $t0, 21
	sw $t0, -16($fp)
	lw $t0, -12($fp)
	lw $t1, -16($fp)
	bne $t0, $t1, label_7
	la $a0, $string_1
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, -20($fp)
	lw $v0, -20($fp)
	jr $ra
label_7:
	la $a0, $string_2
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, -24($fp)
	lw $v0, -24($fp)
	jr $ra
	jr $ra
label_9:
	li $t0, 103
	sw $t0, -12($fp)
	li $t0, 97
	sw $t0, -20($fp)
	lw $t0, -20($fp)
	sw $t0, -16($fp)
	lw $t0, -16($fp)
	sw $t0, -24($fp)
	lw $t0, -0($fp)
	sw $t0, -28($fp)
	lw $t0, -24($fp)
	lw $t1, -28($fp)
	add $t0, $t0, $t1
	sw $t0, -32($fp)
	lw $t0, -12($fp)
	sw $t0, -36($fp)
	lw $t0, -32($fp)
	lw $t1, -36($fp)
	sub $t0, $t0, $t1
	blez $t0, label_10
	la $a0, $string_3
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_10:
	li $t0, 97
	sw $t0, -40($fp)
	li $t0, 0
	sw $t0, -44($fp)
	lw $t0, -40($fp)
	lw $t1, -44($fp)
	beq $t0, $t1, label_11
	la $a0, $string_4
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_11:
	li $t0, 0
	sw $t0, -48($fp)
	li $t0, 0
	sw $t0, -52($fp)
	lw $t0, -48($fp)
	lw $t1, -52($fp)
	beq $t0, $t1, label_12
	la $a0, $string_5
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_12:
	li $t0, 0
	sw $t0, -56($fp)
	lw $v0, -56($fp)
	jr $ra
	jr $ra
label_13:
	li $t0, 100
	sw $t0, -8($fp)
	li $t0, 0
	sw $t0, -16($fp)
	lw $t0, -16($fp)
	sw $t0, -12($fp)
	li $t0, 0
	sw $t0, -20($fp)
	lw $t0, -20($fp)
	la $t1, i
	sw $t0, ($t1)
label_14:
	la $t0, i
	lw $t0, ($t0)
	sw $t0, -24($fp)
	lw $t0, -8($fp)
	sw $t0, -28($fp)
	lw $t0, -24($fp)
	lw $t1, -28($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_15
	la $t0, i
	lw $t0, ($t0)
	sw $t0, -32($fp)
	la $t0, i
	lw $t0, ($t0)
	sw $t0, -36($fp)
	lw $t0, -36($fp)
	la $t1, array
	lw $t2, -32($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	add $t1, $t1, $t2
	sw $t0, ($t1)
	la $t0, i
	lw $t0, ($t0)
	sw $t0, -40($fp)
	li $t0, 1
	sw $t0, -44($fp)
	lw $t0, -40($fp)
	lw $t1, -44($fp)
	add $t0, $t0, $t1
	sw $t0, -48($fp)
	lw $t0, -48($fp)
	la $t1, i
	sw $t0, ($t1)
	j label_14
label_15:
	li $t0, 0
	sw $t0, -52($fp)
	lw $t0, -52($fp)
	la $t1, i
	sw $t0, ($t1)
label_16:
	la $t0, i
	lw $t0, ($t0)
	sw $t0, -56($fp)
	lw $t0, -8($fp)
	sw $t0, -60($fp)
	lw $t0, -56($fp)
	lw $t1, -60($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_17
	lw $t0, -12($fp)
	sw $t0, -64($fp)
	la $t0, i
	lw $t0, ($t0)
	sw $t0, -68($fp)
	lw $t0, -64($fp)
	lw $t1, -68($fp)
	add $t0, $t0, $t1
	sw $t0, -72($fp)
	lw $t0, -72($fp)
	sw $t0, -12($fp)
	la $t0, i
	lw $t0, ($t0)
	sw $t0, -76($fp)
	li $t0, 1
	sw $t0, -80($fp)
	lw $t0, -76($fp)
	lw $t1, -80($fp)
	add $t0, $t0, $t1
	sw $t0, -84($fp)
	lw $t0, -84($fp)
	la $t1, i
	sw $t0, ($t1)
	j label_16
label_17:
	lw $t0, -12($fp)
	sw $t0, -88($fp)
	li $t0, 4950
	sw $t0, -92($fp)
	lw $t0, -88($fp)
	lw $t1, -92($fp)
	bne $t0, $t1, label_18
	la $a0, $string_6
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_18:
	la $a0, $string_7
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
	jr $ra
label_19:
	li $t0, 97
	sw $t0, -12($fp)
	lw $t0, -12($fp)
	sw $t0, -8($fp)
	lw $t0, -8($fp)
	sw $t0, -16($fp)
	li $t0, 97
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	bne $t0, $t1, label_21
	la $a0, $string_8
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_20
label_21:
	la $a0, $string_9
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_20:
	jr $ra
label_22:
	lw $t0, -0($fp)
	sw $t0, -16($fp)
	lw $t0, -4($fp)
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	sub $t0, $t0, $t1
	sw $t0, -24($fp)
	lw $v0, -24($fp)
	jr $ra
	jr $ra
label_23:
	li $v0, 12
	syscall
	sw $v0, -8($fp)
	li $v0, 12
	syscall
	sw $v0, -12($fp)
	li $v0, 12
	syscall
	sw $v0, -16($fp)
	la $a0, $string_10
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -8($fp)
	sw $t0, -20($fp)
	lw $a0, -20($fp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -12($fp)
	sw $t0, -24($fp)
	lw $a0, -24($fp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -16($fp)
	sw $t0, -28($fp)
	lw $a0, -28($fp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -8($fp)
	sw $t0, -32($fp)
	lw $t0, -32($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 32
	sw $t0, -36($fp)
	lw $t0, -36($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_22
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -40($fp)
	lw $a0, -40($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -12($fp)
	sw $t0, -44($fp)
	lw $t0, -44($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 32
	sw $t0, -48($fp)
	lw $t0, -48($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_22
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -52($fp)
	lw $a0, -52($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -16($fp)
	sw $t0, -56($fp)
	lw $t0, -56($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 32
	sw $t0, -60($fp)
	lw $t0, -60($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_22
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -64($fp)
	lw $a0, -64($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_27:
	lw $t0, -0($fp)
	sw $t0, -16($fp)
	lw $t0, -4($fp)
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	bne $t0, $t1, label_28
	la $a0, $string_11
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_28:
	lw $t0, -0($fp)
	sw $t0, -24($fp)
	lw $t0, -4($fp)
	sw $t0, -28($fp)
	lw $t0, -24($fp)
	lw $t1, -28($fp)
	sub $t0, $t0, $t1
	blez $t0, label_29
	la $a0, $string_12
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_29:
	lw $t0, -0($fp)
	sw $t0, -32($fp)
	lw $t0, -4($fp)
	sw $t0, -36($fp)
	lw $t0, -32($fp)
	lw $t1, -36($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_30
	la $a0, $string_13
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_30:
	lw $t0, -0($fp)
	sw $t0, -40($fp)
	lw $t0, -4($fp)
	sw $t0, -44($fp)
	lw $t0, -40($fp)
	lw $t1, -44($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_31
	la $a0, $string_14
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_31:
	lw $t0, -0($fp)
	sw $t0, -48($fp)
	lw $t0, -4($fp)
	sw $t0, -52($fp)
	lw $t0, -48($fp)
	lw $t1, -52($fp)
	sub $t0, $t0, $t1
	bgtz $t0, label_32
	la $a0, $string_15
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_32:
	lw $t0, -0($fp)
	sw $t0, -56($fp)
	lw $t0, -4($fp)
	sw $t0, -60($fp)
	lw $t0, -56($fp)
	lw $t1, -60($fp)
	beq $t0, $t1, label_33
	la $a0, $string_16
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_33:
	jr $ra
label_34:
	li $t0, 10
	sw $t0, -24($fp)
	lw $t0, -24($fp)
	sw $t0, -8($fp)
	li $t0, 1
	sw $t0, -28($fp)
	lw $t0, -28($fp)
	sw $t0, -12($fp)
	li $t0, 0
	sw $t0, -32($fp)
	li $t0, 2
	sw $t0, -36($fp)
	lw $t0, -32($fp)
	lw $t1, -36($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -40($fp)
	li $t0, 2
	sw $t0, -44($fp)
	lw $t0, -44($fp)
	addi $t1, $fp, -20
	lw $t2, -40($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	sub $t1, $t1, $t2
	sw $t0, ($t1)
	lw $t0, -8($fp)
	sw $t0, -48($fp)
	li $t0, 1
	sw $t0, -52($fp)
	lw $t0, -8($fp)
	sw $t0, -56($fp)
	lw $t0, -52($fp)
	lw $t1, -56($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -60($fp)
	li $t0, 0
	sw $t0, -64($fp)
	addi $t0, $fp, -20
	lw $t1, -64($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	sub $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -68($fp)
	lw $t0, -60($fp)
	lw $t1, -68($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -72($fp)
	lw $t0, -12($fp)
	sw $t0, -76($fp)
	li $t0, 0
	sw $t0, -80($fp)
	lw $t0, -80($fp)
	lw $t1, -76($fp)
	sub $t0, $t0, $t1
	sw $t0, -84($fp)
	lw $t0, -72($fp)
	lw $t1, -84($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -88($fp)
	lw $t0, -12($fp)
	sw $t0, -92($fp)
	lw $t0, -88($fp)
	lw $t1, -92($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -96($fp)
	li $t0, 2
	sw $t0, -100($fp)
	lw $t0, -96($fp)
	lw $t1, -100($fp)
	div $t0, $t1
	mflo $t0
	sw $t0, -104($fp)
	li $t0, 0
	sw $t0, -108($fp)
	lw $t0, -108($fp)
	lw $t1, -104($fp)
	sub $t0, $t0, $t1
	sw $t0, -112($fp)
	li $t0, 42
	sw $t0, -116($fp)
	lw $t0, -112($fp)
	lw $t1, -116($fp)
	add $t0, $t0, $t1
	sw $t0, -120($fp)
	li $t0, 97
	sw $t0, -124($fp)
	lw $t0, -124($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, -32
	sw $t0, -128($fp)
	li $t0, 0
	sw $t0, -132($fp)
	lw $t0, -132($fp)
	lw $t1, -128($fp)
	sub $t0, $t0, $t1
	sw $t0, -136($fp)
	lw $t0, -136($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_22
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -140($fp)
	lw $t0, -120($fp)
	lw $t1, -140($fp)
	add $t0, $t0, $t1
	sw $t0, -144($fp)
	li $t0, 65
	sw $t0, -148($fp)
	lw $t0, -144($fp)
	lw $t1, -148($fp)
	sub $t0, $t0, $t1
	sw $t0, -152($fp)
	lw $t0, -48($fp)
	lw $t1, -152($fp)
	add $t0, $t0, $t1
	sw $t0, -156($fp)
	lw $t0, -156($fp)
	sw $t0, -16($fp)
	lw $t0, -16($fp)
	sw $t0, -160($fp)
	li $t0, 62
	sw $t0, -164($fp)
	lw $t0, -160($fp)
	lw $t1, -164($fp)
	bne $t0, $t1, label_36
	la $a0, $string_17
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_36:
	la $a0, $string_18
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
	jr $ra
label_37:
	li $t0, 42
	sw $t0, -164($fp)
	lw $t0, -164($fp)
	sw $t0, -8($fp)
	li $t0, 47
	sw $t0, -168($fp)
	lw $t0, -168($fp)
	sw $t0, -12($fp)
	li $t0, 43
	sw $t0, -172($fp)
	lw $t0, -172($fp)
	sw $t0, -16($fp)
	li $t0, 45
	sw $t0, -176($fp)
	lw $t0, -176($fp)
	sw $t0, -20($fp)
	li $t0, 95
	sw $t0, -180($fp)
	lw $t0, -180($fp)
	sw $t0, -24($fp)
	li $t0, 1
	sw $t0, -184($fp)
	lw $t0, -184($fp)
	sw $t0, -28($fp)
	li $t0, 0
	sw $t0, -188($fp)
	lw $t0, -188($fp)
	sw $t0, -32($fp)
	lw $t0, -28($fp)
	sw $t0, -192($fp)
	li $t0, 0
	sw $t0, -196($fp)
	lw $t0, -192($fp)
	lw $t1, -196($fp)
	bne $t0, $t1, label_38
	la $a0, $string_19
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_38:
	li $t0, 0
	sw $t0, -200($fp)
	lw $t0, -200($fp)
	sw $t0, -156($fp)
	lw $t0, -8($fp)
	sw $t0, -204($fp)
	lw $t0, -12($fp)
	sw $t0, -208($fp)
	lw $t0, -204($fp)
	lw $t1, -208($fp)
	add $t0, $t0, $t1
	sw $t0, -212($fp)
	lw $t0, -16($fp)
	sw $t0, -216($fp)
	lw $t0, -212($fp)
	lw $t1, -216($fp)
	add $t0, $t0, $t1
	sw $t0, -220($fp)
	lw $t0, -20($fp)
	sw $t0, -224($fp)
	lw $t0, -220($fp)
	lw $t1, -224($fp)
	add $t0, $t0, $t1
	sw $t0, -228($fp)
	lw $t0, -24($fp)
	sw $t0, -232($fp)
	lw $t0, -228($fp)
	lw $t1, -232($fp)
	add $t0, $t0, $t1
	sw $t0, -236($fp)
	lw $t0, -236($fp)
	sw $t0, -160($fp)
label_39:
	lw $t0, -156($fp)
	sw $t0, -240($fp)
	li $t0, 10
	sw $t0, -244($fp)
	lw $t0, -240($fp)
	lw $t1, -244($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_40
	lw $t0, -156($fp)
	sw $t0, -248($fp)
	lw $t0, -156($fp)
	sw $t0, -252($fp)
	lw $t0, -252($fp)
	addi $t1, $fp, -36
	lw $t2, -248($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	sub $t1, $t1, $t2
	sw $t0, ($t1)
	lw $t0, -156($fp)
	sw $t0, -256($fp)
	li $t0, 1
	sw $t0, -260($fp)
	lw $t0, -256($fp)
	lw $t1, -260($fp)
	add $t0, $t0, $t1
	sw $t0, -264($fp)
	lw $t0, -264($fp)
	sw $t0, -156($fp)
	j label_39
label_40:
label_41:
	lw $t0, -156($fp)
	sw $t0, -268($fp)
	li $t0, 20
	sw $t0, -272($fp)
	lw $t0, -268($fp)
	lw $t1, -272($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_42
	lw $t0, -156($fp)
	sw $t0, -276($fp)
	li $t0, 97
	sw $t0, -280($fp)
	lw $t0, -156($fp)
	sw $t0, -284($fp)
	lw $t0, -280($fp)
	lw $t1, -284($fp)
	add $t0, $t0, $t1
	sw $t0, -288($fp)
	li $t0, 10
	sw $t0, -292($fp)
	lw $t0, -288($fp)
	lw $t1, -292($fp)
	sub $t0, $t0, $t1
	sw $t0, -296($fp)
	lw $t0, -296($fp)
	addi $t1, $fp, -36
	lw $t2, -276($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	sub $t1, $t1, $t2
	sw $t0, ($t1)
	lw $t0, -156($fp)
	sw $t0, -300($fp)
	li $t0, 1
	sw $t0, -304($fp)
	lw $t0, -300($fp)
	lw $t1, -304($fp)
	add $t0, $t0, $t1
	sw $t0, -308($fp)
	lw $t0, -308($fp)
	sw $t0, -156($fp)
	j label_41
label_42:
label_43:
	lw $t0, -156($fp)
	sw $t0, -312($fp)
	li $t0, 30
	sw $t0, -316($fp)
	lw $t0, -312($fp)
	lw $t1, -316($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_44
	lw $t0, -156($fp)
	sw $t0, -320($fp)
	li $t0, 65
	sw $t0, -324($fp)
	lw $t0, -156($fp)
	sw $t0, -328($fp)
	lw $t0, -324($fp)
	lw $t1, -328($fp)
	add $t0, $t0, $t1
	sw $t0, -332($fp)
	li $t0, 20
	sw $t0, -336($fp)
	lw $t0, -332($fp)
	lw $t1, -336($fp)
	sub $t0, $t0, $t1
	sw $t0, -340($fp)
	lw $t0, -340($fp)
	addi $t1, $fp, -36
	lw $t2, -320($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	sub $t1, $t1, $t2
	sw $t0, ($t1)
	lw $t0, -156($fp)
	sw $t0, -344($fp)
	li $t0, 1
	sw $t0, -348($fp)
	lw $t0, -344($fp)
	lw $t1, -348($fp)
	add $t0, $t0, $t1
	sw $t0, -352($fp)
	lw $t0, -352($fp)
	sw $t0, -156($fp)
	j label_43
label_44:
	li $t0, 0
	sw $t0, -356($fp)
	lw $t0, -356($fp)
	sw $t0, -156($fp)
label_45:
	lw $t0, -156($fp)
	sw $t0, -360($fp)
	li $t0, 30
	sw $t0, -364($fp)
	lw $t0, -360($fp)
	lw $t1, -364($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_46
	lw $t0, -160($fp)
	sw $t0, -368($fp)
	lw $t0, -156($fp)
	sw $t0, -372($fp)
	addi $t0, $fp, -36
	lw $t1, -372($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	sub $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -376($fp)
	lw $t0, -368($fp)
	lw $t1, -376($fp)
	add $t0, $t0, $t1
	sw $t0, -380($fp)
	lw $t0, -380($fp)
	sw $t0, -160($fp)
	lw $t0, -156($fp)
	sw $t0, -384($fp)
	li $t0, 1
	sw $t0, -388($fp)
	lw $t0, -384($fp)
	lw $t1, -388($fp)
	add $t0, $t0, $t1
	sw $t0, -392($fp)
	lw $t0, -392($fp)
	sw $t0, -156($fp)
	j label_45
label_46:
	lw $t0, -160($fp)
	sw $t0, -396($fp)
	li $t0, 2027
	sw $t0, -400($fp)
	lw $t0, -396($fp)
	lw $t1, -400($fp)
	bne $t0, $t1, label_47
	la $a0, $string_20
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_47:
	la $a0, $string_21
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
	jr $ra
label_48:
	li $t0, 10
	sw $t0, -12($fp)
	lw $t0, -12($fp)
	sw $t0, -8($fp)
	lw $t0, -8($fp)
	sw $t0, -16($fp)
	la $a0, $string_22
	li $v0, 4
	syscall
	lw $a0, -16($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_49:
	li $t0, 20
	sw $t0, -12($fp)
	lw $t0, -12($fp)
	la $t1, scope_var
	sw $t0, ($t1)
	la $t0, scope_var
	lw $t0, ($t0)
	sw $t0, -16($fp)
	lw $t0, -16($fp)
	sw $t0, -8($fp)
	la $t0, scope_var
	lw $t0, ($t0)
	sw $t0, -20($fp)
	la $a0, $string_23
	li $v0, 4
	syscall
	lw $a0, -20($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -20
	jal label_48
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	la $t0, scope_var
	lw $t0, ($t0)
	sw $t0, -24($fp)
	la $a0, $string_24
	li $v0, 4
	syscall
	lw $a0, -24($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -8($fp)
	sw $t0, -28($fp)
	la $t0, scope_var
	lw $t0, ($t0)
	sw $t0, -32($fp)
	lw $t0, -28($fp)
	lw $t1, -32($fp)
	bne $t0, $t1, label_51
	la $a0, $string_25
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_51:
	la $a0, $string_26
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
	jr $ra
label_52:
	li $t0, 0
	sw $t0, -20($fp)
	lw $t0, -20($fp)
	sw $t0, -12($fp)
	li $t0, 9
	sw $t0, -24($fp)
	lw $t0, -24($fp)
	sw $t0, -16($fp)
label_53:
	lw $t0, -12($fp)
	sw $t0, -28($fp)
	lw $t0, -16($fp)
	sw $t0, -32($fp)
	lw $t0, -28($fp)
	lw $t1, -32($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_54
	li $v0, 5
	syscall
	sw $v0, -8($fp)
	lw $t0, -8($fp)
	sw $t0, -36($fp)
	li $t0, 0
	sw $t0, -40($fp)
	lw $t0, -36($fp)
	lw $t1, -40($fp)
	bne $t0, $t1, label_56
	la $a0, $string_27
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_6
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	j label_55
label_56:
	li $t0, 1
	sw $t0, -44($fp)
	lw $t0, -36($fp)
	lw $t1, -44($fp)
	bne $t0, $t1, label_58
	la $a0, $string_28
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 20
	sw $t0, -48($fp)
	lw $t0, -48($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 4
	move $fp, $sp
	addiu $sp, $fp, -60
	jal label_9
	move $sp, $fp
	lw $fp, -8($sp)
	lw $ra, -4($sp)
	j label_55
label_58:
	li $t0, 2
	sw $t0, -52($fp)
	lw $t0, -36($fp)
	lw $t1, -52($fp)
	bne $t0, $t1, label_60
	la $a0, $string_29
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -96
	jal label_13
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	j label_55
label_60:
	li $t0, 3
	sw $t0, -56($fp)
	lw $t0, -36($fp)
	lw $t1, -56($fp)
	bne $t0, $t1, label_62
	la $a0, $string_30
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -24
	jal label_19
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	j label_55
label_62:
	li $t0, 4
	sw $t0, -60($fp)
	lw $t0, -36($fp)
	lw $t1, -60($fp)
	bne $t0, $t1, label_64
	la $a0, $string_31
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -68
	jal label_23
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	j label_55
label_64:
	li $t0, 5
	sw $t0, -64($fp)
	lw $t0, -36($fp)
	lw $t1, -64($fp)
	bne $t0, $t1, label_66
	la $a0, $string_32
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -168
	jal label_34
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	j label_55
label_66:
	li $t0, 6
	sw $t0, -68($fp)
	lw $t0, -36($fp)
	lw $t1, -68($fp)
	bne $t0, $t1, label_68
	la $a0, $string_33
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -404
	jal label_37
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	j label_55
label_68:
	li $t0, 7
	sw $t0, -72($fp)
	lw $t0, -36($fp)
	lw $t1, -72($fp)
	bne $t0, $t1, label_70
	la $a0, $string_34
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	la $t0, con1
	lw $t0, ($t0)
	sw $t0, -76($fp)
	li $t0, 2
	sw $t0, -80($fp)
	lw $t0, -76($fp)
	lw $t1, -80($fp)
	add $t0, $t0, $t1
	sw $t0, -84($fp)
	lw $t0, -84($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	la $t0, con2
	lw $t0, ($t0)
	sw $t0, -88($fp)
	li $t0, 4
	sw $t0, -92($fp)
	lw $t0, -88($fp)
	lw $t1, -92($fp)
	add $t0, $t0, $t1
	sw $t0, -96($fp)
	lw $t0, -96($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -64
	jal label_27
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	la $t0, con1
	lw $t0, ($t0)
	sw $t0, -100($fp)
	li $t0, 6
	sw $t0, -104($fp)
	lw $t0, -100($fp)
	lw $t1, -104($fp)
	add $t0, $t0, $t1
	sw $t0, -108($fp)
	lw $t0, -108($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	la $t0, con2
	lw $t0, ($t0)
	sw $t0, -112($fp)
	li $t0, 3
	sw $t0, -116($fp)
	lw $t0, -112($fp)
	lw $t1, -116($fp)
	add $t0, $t0, $t1
	sw $t0, -120($fp)
	lw $t0, -120($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -64
	jal label_27
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	la $t0, con1
	lw $t0, ($t0)
	sw $t0, -124($fp)
	li $t0, 1
	sw $t0, -128($fp)
	lw $t0, -124($fp)
	lw $t1, -128($fp)
	add $t0, $t0, $t1
	sw $t0, -132($fp)
	lw $t0, -132($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	la $t0, con2
	lw $t0, ($t0)
	sw $t0, -136($fp)
	lw $t0, -136($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -64
	jal label_27
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	j label_55
label_70:
	li $t0, 8
	sw $t0, -140($fp)
	lw $t0, -36($fp)
	lw $t1, -140($fp)
	bne $t0, $t1, label_74
	la $a0, $string_35
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -36
	jal label_49
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	j label_55
label_74:
label_55:
	la $a0, $string_36
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -12($fp)
	sw $t0, -144($fp)
	li $t0, 1
	sw $t0, -148($fp)
	lw $t0, -144($fp)
	lw $t1, -148($fp)
	add $t0, $t0, $t1
	sw $t0, -152($fp)
	lw $t0, -152($fp)
	sw $t0, -12($fp)
	j label_53
label_54:
	la $t0, ch1
	lw $t0, ($t0)
	sw $t0, -156($fp)
	lw $t0, -156($fp)
	la $t1, ch
	sw $t0, ($t1)
	la $t0, ch
	lw $t0, ($t0)
	sw $t0, -160($fp)
	la $a0, $string_37
	li $v0, 4
	syscall
	lw $a0, -160($fp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	la $a0, $string_38
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_0:
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -164
	jal label_52
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	li $v0, 10
	syscall
