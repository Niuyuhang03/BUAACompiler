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
	sw $a0, 36($sp)
	lw $t0, 36($sp)
	sw $t0, 44($sp)
	lw $t0, 36($sp)
	sw $t0, 48($sp)
	lw $t0, 44($sp)
	lw $t1, 48($sp)
	mult $t0, $t1
	mflo $t0
	sw $t0, 52($sp)
	li $t0, 0
	sw $t0, 56($sp)
	lw $t0, 56($sp)
	lw $t1, 52($sp)
	sub $t0, $t0, $t1
	sw $t0, 60($sp)
	lw $t0, 36($sp)
	sw $t0, 64($sp)
	lw $t0, 60($sp)
	lw $t1, 64($sp)
	add $t0, $t0, $t1
	sw $t0, 68($sp)
	lw $t0, 36($sp)
	sw $t0, 72($sp)
	lw $t0, 68($sp)
	lw $t1, 72($sp)
	sub $t0, $t0, $t1
	sw $t0, 76($sp)
	li $t0, -1
	sw $t0, 80($sp)
	lw $t0, 76($sp)
	lw $t1, 80($sp)
	add $t0, $t0, $t1
	sw $t0, 84($sp)
	lw $t0, 84($sp)
	sw $t0, 40($sp)
	lw $t0, 36($sp)
	sw $t0, 88($sp)
	lw $t0, 36($sp)
	sw $t0, 92($sp)
	lw $t0, 88($sp)
	lw $t1, 92($sp)
	div $t0, $t1
	mflo $t0
	sw $t0, 96($sp)
	li $t0, 0
	sw $t0, 100($sp)
	lw $t0, 16($sp)
	sw $t0, 104($sp)
	lw $t0, 96($sp)
	lw $t1, 104($sp)
	mult $t0, $t1
	mflo $t0
	sw $t0, 108($sp)
	li $t0, 0
	sw $t0, 112($sp)
	lw $t0, 16($sp)
	sw $t0, 116($sp)
	lw $t0, 108($sp)
	lw $t1, 116($sp)
	div $t0, $t1
	mflo $t0
	sw $t0, 120($sp)
	li $t0, 1
	sw $t0, 124($sp)
	lw $t0, 120($sp)
	lw $t1, 124($sp)
	add $t0, $t0, $t1
	sw $t0, 128($sp)
	li $t0, 99
	sw $t0, 132($sp)
	lw $t0, 128($sp)
	lw $t1, 132($sp)
	add $t0, $t0, $t1
	sw $t0, 136($sp)
	li $t0, 97
	sw $t0, 140($sp)
	lw $a0, 140($sp)
	li $t0, 98
	sw $t0, 144($sp)
	lw $a1, 144($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -24
	jal label_1
	addiu $sp, $sp, 24
	lw $ra, ($sp)
	sw $v0, 148($sp)
	lw $t0, 136($sp)
	lw $t1, 148($sp)
	add $t0, $t0, $t1
	sw $t0, 152($sp)
	lw $t0, 152($sp)
	sw $t0, 40($sp)
	lw $t0, 36($sp)
	sw $t0, 156($sp)
	li $t0, 1
	sw $t0, 160($sp)
	lw $t0, 156($sp)
	lw $t1, 160($sp)
	bne $t0, $t1, label_5
	sw $ra, ($sp)
	addiu $sp, $sp, -32
	jal label_2
	addiu $sp, $sp, 32
	lw $ra, ($sp)
label_5:
	lw $t0, 36($sp)
	sw $t0, 164($sp)
	la $t0, max
	lw $t0, ($t0)
	sw $t0, 168($sp)
	lw $t0, 164($sp)
	lw $t1, 168($sp)
	sub $t0, $t0, $t1
	blez $t0, label_7
	la $a0, $string_2
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 1
	sw $t0, 172($sp)
	li $t0, 0
	sw $t0, 176($sp)
	lw $t0, 176($sp)
	lw $t1, 172($sp)
	sub $t0, $t0, $t1
	sw $t0, 180($sp)
	lw $v0, 180($sp)
	jr $ra
label_7:
	lw $t0, 36($sp)
	sw $t0, 184($sp)
	la $t0, min
	lw $t0, ($t0)
	sw $t0, 188($sp)
	lw $t0, 184($sp)
	lw $t1, 188($sp)
	sub $t0, $t0, $t1
	bgez $t0, label_8
	la $a0, $string_3
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 1
	sw $t0, 192($sp)
	li $t0, 0
	sw $t0, 196($sp)
	lw $t0, 196($sp)
	lw $t1, 192($sp)
	sub $t0, $t0, $t1
	sw $t0, 200($sp)
	lw $v0, 200($sp)
	jr $ra
label_8:
	lw $t0, 36($sp)
	sw $t0, 204($sp)
	li $t0, 1
	sw $t0, 208($sp)
	lw $t0, 204($sp)
	lw $t1, 208($sp)
	sub $t0, $t0, $t1
	blez $t0, label_9
	la $t0, result
	lw $t0, ($t0)
	sw $t0, 212($sp)
	lw $t0, 36($sp)
	sw $t0, 216($sp)
	lw $t0, 212($sp)
	lw $t1, 216($sp)
	mult $t0, $t1
	mflo $t0
	sw $t0, 220($sp)
	lw $t0, 220($sp)
	la $t1, result
	sw $t0, ($t1)
	lw $t0, 36($sp)
	sw $t0, 224($sp)
	li $t0, 1
	sw $t0, 228($sp)
	lw $t0, 224($sp)
	lw $t1, 228($sp)
	sub $t0, $t0, $t1
	sw $t0, 232($sp)
	lw $a0, 232($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -240
	jal label_3
	addiu $sp, $sp, 240
	lw $ra, ($sp)
label_9:
	li $t0, 0
	sw $t0, 236($sp)
	lw $v0, 236($sp)
	jr $ra
	jr $ra
label_11:
label_12:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 244($sp)
	li $t0, 1
	sw $t0, 248($sp)
	lw $t0, 244($sp)
	lw $t1, 248($sp)
	sub $t0, $t0, $t1
	bltz $t0, label_13
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 252($sp)
	li $t0, 1
	sw $t0, 256($sp)
	lw $t0, 252($sp)
	lw $t1, 256($sp)
	bne $t0, $t1, label_15
	la $a0, $string_4
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_14
label_15:
label_14:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 260($sp)
	li $t0, -1
	sw $t0, 264($sp)
	lw $t0, 260($sp)
	lw $t1, 264($sp)
	bne $t0, $t1, label_17
	la $a0, $string_5
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_16
label_17:
	li $t0, 1
	sw $t0, 268($sp)
	lw $t0, 260($sp)
	lw $t1, 268($sp)
	bne $t0, $t1, label_18
	la $a0, $string_6
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_16
label_18:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 272($sp)
	lw $t0, 272($sp)
	la $t1, num
	sw $t0, ($t1)
label_16:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 276($sp)
	li $t0, 1
	sw $t0, 280($sp)
	lw $t0, 276($sp)
	lw $t1, 280($sp)
	bne $t0, $t1, label_20
	la $a0, $string_7
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_19
label_20:
label_19:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 284($sp)
	li $t0, 1
	sw $t0, 288($sp)
	lw $t0, 284($sp)
	lw $t1, 288($sp)
	sub $t0, $t0, $t1
	sw $t0, 292($sp)
	lw $t0, 292($sp)
	la $t1, num
	sw $t0, ($t1)
	j label_12
label_13:
label_21:
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 296($sp)
	li $t0, 1
	sw $t0, 300($sp)
	lw $t0, 296($sp)
	lw $t1, 300($sp)
	sub $t0, $t0, $t1
	bltz $t0, label_22
	la $a0, $string_8
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, 304($sp)
	lw $t0, 304($sp)
	la $t1, num
	sw $t0, ($t1)
	j label_21
label_22:
	jr $ra
label_23:
	sw $a0, 312($sp)
	lw $t0, 312($sp)
	sw $t0, 316($sp)
	li $t0, 98
	sw $t0, 320($sp)
	lw $t0, 316($sp)
	lw $t1, 320($sp)
	sub $t0, $t0, $t1
	bgez $t0, label_24
	la $a0, $string_9
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_24:
	lw $t0, 312($sp)
	sw $t0, 324($sp)
	li $t0, 98
	sw $t0, 328($sp)
	lw $t0, 324($sp)
	lw $t1, 328($sp)
	sub $t0, $t0, $t1
	bgtz $t0, label_25
	la $a0, $string_10
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_25:
	lw $t0, 312($sp)
	sw $t0, 332($sp)
	li $t0, 98
	sw $t0, 336($sp)
	lw $t0, 332($sp)
	lw $t1, 336($sp)
	bne $t0, $t1, label_26
	la $a0, $string_11
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_26:
	lw $t0, 312($sp)
	sw $t0, 340($sp)
	li $t0, 98
	sw $t0, 344($sp)
	lw $t0, 340($sp)
	lw $t1, 344($sp)
	sub $t0, $t0, $t1
	blez $t0, label_27
	la $a0, $string_12
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_27:
	lw $t0, 312($sp)
	sw $t0, 348($sp)
	li $t0, 98
	sw $t0, 352($sp)
	lw $t0, 348($sp)
	lw $t1, 352($sp)
	sub $t0, $t0, $t1
	bltz $t0, label_28
	la $a0, $string_13
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_28:
	lw $t0, 312($sp)
	sw $t0, 356($sp)
	li $t0, 98
	sw $t0, 360($sp)
	lw $t0, 356($sp)
	lw $t1, 360($sp)
	beq $t0, $t1, label_29
	la $a0, $string_14
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_29:
	jr $ra
label_30:
	li $t0, 43
	sw $t0, 368($sp)
	li $t0, 45
	sw $t0, 372($sp)
	li $t0, 42
	sw $t0, 376($sp)
	li $t0, 47
	sw $t0, 380($sp)
	li $t0, 95
	sw $t0, 384($sp)
	li $t0, 97
	sw $t0, 388($sp)
	li $t0, 48
	sw $t0, 392($sp)
	li $t0, 49
	sw $t0, 396($sp)
	la $a0, $string_15
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, 372($sp)
	sw $t0, 400($sp)
	li $t0, 43
	sw $t0, 404($sp)
	lw $t0, 400($sp)
	lw $t1, 404($sp)
	bne $t0, $t1, label_32
	la $a0, $string_16
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_31
label_32:
	la $a0, $string_17
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_31:
	jr $ra
label_0:
	li $t0, 49
	sw $t0, 4($sp)
	li $t0, 0
	sw $t0, 424($sp)
	lw $t0, 424($sp)
	sw $t0, 8($sp)
	li $t0, 1
	sw $t0, 428($sp)
	lw $t0, 428($sp)
	la $t1, result
	sw $t0, ($t1)
	li $t0, 0
	sw $t0, 432($sp)
	li $t0, 1
	sw $t0, 436($sp)
	lw $t0, 436($sp)
	la $t1, array
	sw $t0, 0($t1)
	li $v0, 5
	syscall
	la $t1, num
	sw $v0, ($t1)
	li $v0, 5
	syscall
	sw $v0, 412($sp)
	li $v0, 12
	syscall
	sw $v0, 420($sp)
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 440($sp)
	li $t0, 0
	sw $t0, 444($sp)
	lw $t0, 440($sp)
	lw $t1, 444($sp)
	bne $t0, $t1, label_33
	li $t0, 1
	sw $t0, 448($sp)
	lw $t0, 448($sp)
	sw $t0, 8($sp)
label_33:
	lw $t0, 8($sp)
	sw $t0, 452($sp)
	li $t0, 0
	sw $t0, 456($sp)
	lw $t0, 452($sp)
	lw $t1, 456($sp)
	beq $t0, $t1, label_34
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 460($sp)
	li $t0, 1
	sw $t0, 464($sp)
	lw $t0, 460($sp)
	lw $t1, 464($sp)
	add $t0, $t0, $t1
	sw $t0, 468($sp)
	la $a0, $string_18
	li $v0, 4
	syscall
	lw $a0, 468($sp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_34:
	lw $t0, 8($sp)
	sw $t0, 472($sp)
	li $t0, 0
	sw $t0, 476($sp)
	lw $t0, 472($sp)
	lw $t1, 476($sp)
	bne $t0, $t1, label_35
	la $t0, num
	lw $t0, ($t0)
	sw $t0, 480($sp)
	lw $a0, 480($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -240
	jal label_3
	addiu $sp, $sp, 240
	lw $ra, ($sp)
	sw $v0, 484($sp)
	lw $t0, 484($sp)
	sw $t0, 416($sp)
	lw $t0, 416($sp)
	sw $t0, 488($sp)
	lw $a0, 488($sp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_35:
	lw $t0, 412($sp)
	sw $t0, 492($sp)
	li $t0, 1
	sw $t0, 496($sp)
	lw $t0, 492($sp)
	lw $t1, 496($sp)
	bne $t0, $t1, label_37
	sw $ra, ($sp)
	addiu $sp, $sp, -308
	jal label_11
	addiu $sp, $sp, 308
	lw $ra, ($sp)
label_37:
	lw $t0, 412($sp)
	sw $t0, 500($sp)
	li $t0, 2
	sw $t0, 504($sp)
	lw $t0, 500($sp)
	lw $t1, 504($sp)
	bne $t0, $t1, label_39
	lw $t0, 420($sp)
	sw $t0, 508($sp)
	lw $a0, 508($sp)
	sw $ra, ($sp)
	addiu $sp, $sp, -4
	jal label_23
	addiu $sp, $sp, 4
	lw $ra, ($sp)
label_39:
	lw $t0, 412($sp)
	sw $t0, 512($sp)
	li $t0, 3
	sw $t0, 516($sp)
	lw $t0, 512($sp)
	lw $t1, 516($sp)
	bne $t0, $t1, label_41
	sw $ra, ($sp)
	addiu $sp, $sp, -4
	jal label_30
	addiu $sp, $sp, 4
	lw $ra, ($sp)
label_41:
	li $v0, 10
	syscall
