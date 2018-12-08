.data
	$string_0: .asciiz "\n"
	$string_1: .asciiz "result:"
	$string_2: .asciiz "above max"
	$string_3: .asciiz "below min"
	$string_4: .asciiz "num=1"
	$string_5: .asciiz "num=-1"
	$string_6: .asciiz "num=1"
	$string_7: .asciiz "num=1"
	$string_8: .asciiz "error"
	$string_9: .asciiz "<"
	$string_10: .asciiz "<="
	$string_11: .asciiz "=="
	$string_12: .asciiz ">"
	$string_13: .asciiz ">="
	$string_14: .asciiz "!="
	$string_15: .asciiz " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
	$string_16: .asciiz "+"
	$string_17: .asciiz "error"
	$string_18: .asciiz "result:"
	max: .word 100
	min: .word 0
	fail: .word 110
	num: .word 0
	array: .word 0:100
	result: .word 0
	id: .word 0
	pwd: .word 0:20
	_a2: .word 0
.text
	move $fp, $sp
	addiu $sp, $fp, -668
	j label_0
label_1:
	lw $t0, -0($fp)
	sw $t0, -16($fp)
	lw $t0, -4($fp)
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	add $t0, $t0, $t1
	sw $t0, -24($fp)
	lw $v0, -24($fp)
	jr $ra
	jr $ra
label_2:
	lw $t0, -0($fp)
	sw $t0, -16($fp)
	lw $t0, -4($fp)
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	add $t0, $t0, $t1
	sw $t0, -24($fp)
	lw $v0, -24($fp)
	jr $ra
	jr $ra
label_3:
	lw $t0, -0($fp)
	sw $t0, -28($fp)
	lw $t0, -4($fp)
	sw $t0, -32($fp)
	lw $t0, -28($fp)
	lw $t1, -32($fp)
	add $t0, $t0, $t1
	sw $t0, -36($fp)
	lw $t0, -8($fp)
	sw $t0, -40($fp)
	lw $t0, -36($fp)
	lw $t1, -40($fp)
	add $t0, $t0, $t1
	sw $t0, -44($fp)
	lw $t0, -12($fp)
	sw $t0, -48($fp)
	lw $t0, -44($fp)
	lw $t1, -48($fp)
	add $t0, $t0, $t1
	sw $t0, -52($fp)
	lw $t0, -16($fp)
	sw $t0, -56($fp)
	lw $t0, -52($fp)
	lw $t1, -56($fp)
	add $t0, $t0, $t1
	sw $t0, -60($fp)
	lw $a0, -60($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_4:
	la $t0, result
	lw $t0, ($t0)
	sw $t0, -8($fp)
	la $a0, $string_1
	li $v0, 4
	syscall
	lw $a0, -8($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_5:
	lw $t0, -0($fp)
	sw $t0, -16($fp)
	lw $t0, -0($fp)
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -24($fp)
	li $t0, 0
	sw $t0, -28($fp)
	lw $t0, -28($fp)
	lw $t1, -24($fp)
	sub $t0, $t0, $t1
	sw $t0, -32($fp)
	lw $t0, -0($fp)
	sw $t0, -36($fp)
	lw $t0, -32($fp)
	lw $t1, -36($fp)
	add $t0, $t0, $t1
	sw $t0, -40($fp)
	lw $t0, -0($fp)
	sw $t0, -44($fp)
	lw $t0, -40($fp)
	lw $t1, -44($fp)
	sub $t0, $t0, $t1
	sw $t0, -48($fp)
	li $t0, -1
	sw $t0, -52($fp)
	lw $t0, -48($fp)
	lw $t1, -52($fp)
	add $t0, $t0, $t1
	sw $t0, -56($fp)
	lw $t0, -56($fp)
	sw $t0, -12($fp)
	lw $t0, -0($fp)
	sw $t0, -60($fp)
	lw $t0, -0($fp)
	sw $t0, -64($fp)
	lw $t0, -60($fp)
	lw $t1, -64($fp)
	div $t0, $t1
	mflo $t0
	sw $t0, -68($fp)
	li $t0, 1
	sw $t0, -72($fp)
	lw $t0, -68($fp)
	lw $t1, -72($fp)
	add $t0, $t0, $t1
	sw $t0, -76($fp)
	li $t0, 99
	sw $t0, -80($fp)
	lw $t0, -76($fp)
	lw $t1, -80($fp)
	add $t0, $t0, $t1
	sw $t0, -84($fp)
	li $t0, 97
	sw $t0, -88($fp)
	lw $t0, -88($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 99
	sw $t0, -92($fp)
	lw $t0, -92($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 100
	sw $t0, -96($fp)
	lw $t0, -96($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_1
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -100($fp)
	lw $t0, -100($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_1
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -104($fp)
	lw $t0, -84($fp)
	lw $t1, -104($fp)
	add $t0, $t0, $t1
	sw $t0, -108($fp)
	lw $t0, -108($fp)
	sw $t0, -12($fp)
	lw $t0, -0($fp)
	sw $t0, -112($fp)
	li $t0, 1
	sw $t0, -116($fp)
	lw $t0, -112($fp)
	lw $t1, -116($fp)
	bne $t0, $t1, label_8
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -12
	jal label_4
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
label_8:
	lw $t0, -0($fp)
	sw $t0, -120($fp)
	la $t0, max
	lw $t0, ($t0)
	sw $t0, -124($fp)
	lw $t0, -120($fp)
	lw $t1, -124($fp)
	sub $t0, $t0, $t1
	blez $t0, label_10
	la $a0, $string_2
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 1
	sw $t0, -128($fp)
	li $t0, 0
	sw $t0, -132($fp)
	lw $t0, -132($fp)
	lw $t1, -128($fp)
	sub $t0, $t0, $t1
	sw $t0, -136($fp)
	lw $v0, -136($fp)
	jr $ra
label_10:
	lw $t0, -0($fp)
	sw $t0, -140($fp)
	la $t0, min
	lw $t0, ($t0)
	sw $t0, -144($fp)
	lw $t0, -140($fp)
	lw $t1, -144($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_11
	la $a0, $string_3
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 1
	sw $t0, -148($fp)
	li $t0, 0
	sw $t0, -152($fp)
	lw $t0, -152($fp)
	lw $t1, -148($fp)
	sub $t0, $t0, $t1
	sw $t0, -156($fp)
	lw $v0, -156($fp)
	jr $ra
label_11:
	lw $t0, -0($fp)
	sw $t0, -160($fp)
	li $t0, 1
	sw $t0, -164($fp)
	lw $t0, -160($fp)
	lw $t1, -164($fp)
	sub $t0, $t0, $t1
	blez $t0, label_12
	la $t0, result
	lw $t0, ($t0)
	sw $t0, -168($fp)
	lw $t0, -0($fp)
	sw $t0, -172($fp)
	lw $t0, -168($fp)
	lw $t1, -172($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -176($fp)
	lw $t0, -176($fp)
	la $t1, result
	sw $t0, ($t1)
	lw $t0, -0($fp)
	sw $t0, -180($fp)
	li $t0, 1
	sw $t0, -184($fp)
	lw $t0, -180($fp)
	lw $t1, -184($fp)
	sub $t0, $t0, $t1
	sw $t0, -188($fp)
	lw $t0, -188($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 4
	move $fp, $sp
	addiu $sp, $fp, -196
	jal label_5
	move $sp, $fp
	lw $fp, -8($sp)
	lw $ra, -4($sp)
label_12:
	li $t0, 0
	sw $t0, -192($fp)
	lw $v0, -192($fp)
	jr $ra
	jr $ra
label_14:
label_15:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -8($fp)
	li $t0, 1
	sw $t0, -12($fp)
	lw $t0, -8($fp)
	lw $t1, -12($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_16
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -16($fp)
	li $t0, 1
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	bne $t0, $t1, label_18
	la $a0, $string_4
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_17
label_18:
label_17:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -24($fp)
	li $t0, -1
	sw $t0, -28($fp)
	lw $t0, -24($fp)
	lw $t1, -28($fp)
	bne $t0, $t1, label_20
	la $a0, $string_5
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_19
label_20:
	li $t0, 1
	sw $t0, -32($fp)
	lw $t0, -24($fp)
	lw $t1, -32($fp)
	bne $t0, $t1, label_21
	la $a0, $string_6
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_19
label_21:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -36($fp)
	lw $t0, -36($fp)
	la $t1, num
	sw $t0, ($t1)
label_19:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -40($fp)
	li $t0, 1
	sw $t0, -44($fp)
	lw $t0, -40($fp)
	lw $t1, -44($fp)
	bne $t0, $t1, label_23
	la $a0, $string_7
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_22
label_23:
label_22:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -48($fp)
	li $t0, 1
	sw $t0, -52($fp)
	lw $t0, -48($fp)
	lw $t1, -52($fp)
	sub $t0, $t0, $t1
	sw $t0, -56($fp)
	lw $t0, -56($fp)
	la $t1, num
	sw $t0, ($t1)
	j label_15
label_16:
label_24:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -60($fp)
	li $t0, 1
	sw $t0, -64($fp)
	lw $t0, -60($fp)
	lw $t1, -64($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_25
	la $a0, $string_8
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, -68($fp)
	lw $t0, -68($fp)
	la $t1, num
	sw $t0, ($t1)
	j label_24
label_25:
	jr $ra
label_26:
	lw $t0, -0($fp)
	sw $t0, -12($fp)
	li $t0, 98
	sw $t0, -16($fp)
	lw $t0, -12($fp)
	lw $t1, -16($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_27
	la $a0, $string_9
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_27:
	lw $t0, -0($fp)
	sw $t0, -20($fp)
	li $t0, 98
	sw $t0, -24($fp)
	lw $t0, -20($fp)
	lw $t1, -24($fp)
	sub $t0, $t0, $t1
	bgtz $t0, label_28
	la $a0, $string_10
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_28:
	lw $t0, -0($fp)
	sw $t0, -28($fp)
	li $t0, 98
	sw $t0, -32($fp)
	lw $t0, -28($fp)
	lw $t1, -32($fp)
	bne $t0, $t1, label_29
	la $a0, $string_11
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_29:
	lw $t0, -0($fp)
	sw $t0, -36($fp)
	li $t0, 98
	sw $t0, -40($fp)
	lw $t0, -36($fp)
	lw $t1, -40($fp)
	sub $t0, $t0, $t1
	blez $t0, label_30
	la $a0, $string_12
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_30:
	lw $t0, -0($fp)
	sw $t0, -44($fp)
	li $t0, 98
	sw $t0, -48($fp)
	lw $t0, -44($fp)
	lw $t1, -48($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_31
	la $a0, $string_13
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_31:
	lw $t0, -0($fp)
	sw $t0, -52($fp)
	li $t0, 98
	sw $t0, -56($fp)
	lw $t0, -52($fp)
	lw $t1, -56($fp)
	beq $t0, $t1, label_32
	la $a0, $string_14
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_32:
	jr $ra
label_33:
	li $t0, 43
	sw $t0, -8($fp)
	li $t0, 45
	sw $t0, -12($fp)
	li $t0, 42
	sw $t0, -16($fp)
	li $t0, 47
	sw $t0, -20($fp)
	li $t0, 95
	sw $t0, -24($fp)
	li $t0, 97
	sw $t0, -28($fp)
	li $t0, 48
	sw $t0, -32($fp)
	li $t0, 49
	sw $t0, -36($fp)
	la $a0, $string_15
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -12($fp)
	sw $t0, -40($fp)
	li $t0, 43
	sw $t0, -44($fp)
	lw $t0, -40($fp)
	lw $t1, -44($fp)
	bne $t0, $t1, label_35
	la $a0, $string_16
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_34
label_35:
	la $a0, $string_17
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_34:
	jr $ra
label_0:
	li $t0, 49
	sw $t0, -0($fp)
	li $t0, 0
	sw $t0, -424($fp)
	lw $t0, -424($fp)
	sw $t0, -4($fp)
	li $t0, 1
	sw $t0, -428($fp)
	lw $t0, -428($fp)
	la $t1, result
	sw $t0, ($t1)
	li $v0, 5
	syscall
	la $t1, num
	sw $v0, ($t1)
	li $v0, 5
	syscall
	sw $v0, -408($fp)
	li $v0, 12
	syscall
	sw $v0, -420($fp)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -432($fp)
	li $t0, 0
	sw $t0, -436($fp)
	lw $t0, -432($fp)
	lw $t1, -436($fp)
	bne $t0, $t1, label_36
	li $t0, 1
	sw $t0, -440($fp)
	lw $t0, -440($fp)
	sw $t0, -4($fp)
label_36:
	lw $t0, -4($fp)
	sw $t0, -444($fp)
	li $t0, 0
	sw $t0, -448($fp)
	lw $t0, -444($fp)
	lw $t1, -448($fp)
	beq $t0, $t1, label_37
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -452($fp)
	li $t0, 1
	sw $t0, -456($fp)
	lw $t0, -452($fp)
	lw $t1, -456($fp)
	add $t0, $t0, $t1
	sw $t0, -460($fp)
	la $a0, $string_18
	li $v0, 4
	syscall
	lw $a0, -460($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_37:
	lw $t0, -4($fp)
	sw $t0, -464($fp)
	li $t0, 0
	sw $t0, -468($fp)
	lw $t0, -464($fp)
	lw $t1, -468($fp)
	bne $t0, $t1, label_38
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -472($fp)
	lw $t0, -472($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 4
	move $fp, $sp
	addiu $sp, $fp, -196
	jal label_5
	move $sp, $fp
	lw $fp, -8($sp)
	lw $ra, -4($sp)
	sw $v0, -476($fp)
	lw $t0, -476($fp)
	sw $t0, -412($fp)
	lw $t0, -412($fp)
	sw $t0, -480($fp)
	lw $a0, -480($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_38:
	lw $t0, -408($fp)
	sw $t0, -484($fp)
	li $t0, 1
	sw $t0, -488($fp)
	lw $t0, -484($fp)
	lw $t1, -488($fp)
	bne $t0, $t1, label_40
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -72
	jal label_14
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
label_40:
	lw $t0, -408($fp)
	sw $t0, -492($fp)
	li $t0, 2
	sw $t0, -496($fp)
	lw $t0, -492($fp)
	lw $t1, -496($fp)
	bne $t0, $t1, label_42
	lw $t0, -420($fp)
	sw $t0, -500($fp)
	lw $t0, -500($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 4
	move $fp, $sp
	addiu $sp, $fp, -60
	jal label_26
	move $sp, $fp
	lw $fp, -8($sp)
	lw $ra, -4($sp)
label_42:
	lw $t0, -408($fp)
	sw $t0, -504($fp)
	li $t0, 3
	sw $t0, -508($fp)
	lw $t0, -504($fp)
	lw $t1, -508($fp)
	bne $t0, $t1, label_44
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -48
	jal label_33
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
label_44:
	lw $t0, -408($fp)
	sw $t0, -512($fp)
	li $t0, 4
	sw $t0, -516($fp)
	lw $t0, -512($fp)
	lw $t1, -516($fp)
	bne $t0, $t1, label_46
	li $t0, 1
	sw $t0, -520($fp)
	li $t0, 3
	sw $t0, -524($fp)
	lw $t0, -524($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 7
	sw $t0, -528($fp)
	lw $t0, -528($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_2
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -532($fp)
	lw $t0, -520($fp)
	lw $t1, -532($fp)
	add $t0, $t0, $t1
	sw $t0, -536($fp)
	lw $t0, -536($fp)
	sw $t0, -416($fp)
	lw $t0, -416($fp)
	sw $t0, -540($fp)
	lw $a0, -540($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 1
	sw $t0, -544($fp)
	li $t0, 3
	sw $t0, -548($fp)
	lw $t0, -548($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 5
	sw $t0, -552($fp)
	lw $t0, -552($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 2
	sw $t0, -556($fp)
	lw $t0, -556($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_1
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -560($fp)
	lw $t0, -560($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -28
	jal label_2
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -564($fp)
	lw $t0, -544($fp)
	lw $t1, -564($fp)
	add $t0, $t0, $t1
	sw $t0, -568($fp)
	lw $t0, -568($fp)
	sw $t0, -416($fp)
	lw $t0, -416($fp)
	sw $t0, -572($fp)
	lw $a0, -572($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 1
	sw $t0, -576($fp)
	lw $t0, -576($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 2
	sw $t0, -580($fp)
	lw $t0, -580($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 3
	sw $t0, -584($fp)
	lw $t0, -584($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 4
	sw $t0, -588($fp)
	lw $t0, -588($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 5
	sw $t0, -592($fp)
	lw $t0, -592($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 20
	move $fp, $sp
	addiu $sp, $fp, -64
	jal label_3
	move $sp, $fp
	lw $fp, -24($sp)
	lw $ra, -20($sp)
label_46:
	lw $t0, -408($fp)
	sw $t0, -596($fp)
	li $t0, 5
	sw $t0, -600($fp)
	lw $t0, -596($fp)
	lw $t1, -600($fp)
	bne $t0, $t1, label_51
	li $t0, 1
	sw $t0, -604($fp)
	lw $t0, -604($fp)
	sw $t0, -416($fp)
	lw $t0, -416($fp)
	sw $t0, -608($fp)
	lw $a0, -608($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 2
	sw $t0, -612($fp)
	lw $t0, -612($fp)
	la $t1, num
	sw $t0, ($t1)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -616($fp)
	lw $a0, -616($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -620($fp)
	lw $t0, -620($fp)
	sw $t0, -416($fp)
	lw $t0, -416($fp)
	sw $t0, -624($fp)
	lw $a0, -624($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 3
	sw $t0, -628($fp)
	lw $t0, -628($fp)
	la $t1, num
	sw $t0, ($t1)
	lw $t0, -416($fp)
	sw $t0, -632($fp)
	lw $t0, -632($fp)
	la $t1, num
	sw $t0, ($t1)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -636($fp)
	lw $a0, -636($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, -640($fp)
	li $t0, 3
	sw $t0, -644($fp)
	lw $t0, -644($fp)
	la $t1, array
	lw $t2, -640($fp)
	add $t1, $t1, $t2
	sw $t0, ($t1)
	li $t0, 0
	sw $t0, -648($fp)
	la $t0, array
	lw $t1, -648($fp)
	add $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -652($fp)
	lw $a0, -652($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, -656($fp)
	la $t0, array
	lw $t1, -656($fp)
	add $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -660($fp)
	lw $t0, -660($fp)
	la $t1, num
	sw $t0, ($t1)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, -664($fp)
	lw $a0, -664($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_51:
	li $v0, 10
	syscall
