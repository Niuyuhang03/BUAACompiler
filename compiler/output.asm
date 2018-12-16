.data
	$string_0: .asciiz "\n"
	$string_1: .asciiz "empty parameter list & condition is a single expression"
	$string_2: .asciiz "as plain as daylight 1"
	$string_3: .asciiz "as plain as daylight 2"
	$string_4: .asciiz "Print an expression alone & print string with expression & all the <zi fu>"
	$string_5: .asciiz "apples[0] is"
	$string_6: .asciiz " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
	$string_7: .asciiz "Some empty sentences"
	$string_8: .asciiz "if & switch & condition is a relation expression & all valid string & valid char,num"
	$string_9: .asciiz "A valid <zi fu>"
	$string_10: .asciiz "char 34 is not included!"
	$string_11: .asciiz "Input two numbers to calculate GCD"
	$string_12: .asciiz "Two input for GCD "
	$string_13: .asciiz "Greatest Common Division of "
	$string_14: .asciiz "is "
	$string_15: .asciiz "100"
	$string_16: .asciiz "Hello Worl"
	$string_17: .asciiz "Empty Default Case"
	_a: .word 97
	b: .word 10
	d: .word 97
	apples: .word 0:100
	str: .word 0:100
.text
	move $fp, $sp
	addiu $sp, $fp, -72
	j label_0
label_1:
	li $t0, -1
	sw $t0, -8($fp)
	li $t0, 2
	sw $t0, -16($fp)
	lw $t0, -16($fp)
	sw $t0, -12($fp)
label_2:
	lw $t0, -12($fp)
	sw $t0, -20($fp)
	li $t0, 1
	sw $t0, -24($fp)
	lw $t0, -20($fp)
	lw $t1, -24($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -28($fp)
	li $t0, 1
	sw $t0, -32($fp)
	lw $t0, -28($fp)
	lw $t1, -32($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -36($fp)
	li $t0, 1
	sw $t0, -40($fp)
	lw $t0, -36($fp)
	lw $t1, -40($fp)
	div $t0, $t1
	mflo $t0
	sw $t0, -44($fp)
	li $t0, 0
	sw $t0, -48($fp)
	lw $t0, -44($fp)
	lw $t1, -48($fp)
	beq $t0, $t1, label_3
	lw $t0, -12($fp)
	sw $t0, -52($fp)
	la $a0, $string_1
	li $v0, 4
	syscall
	lw $a0, -52($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -12($fp)
	sw $t0, -56($fp)
	li $t0, 1
	sw $t0, -60($fp)
	lw $t0, -56($fp)
	lw $t1, -60($fp)
	sub $t0, $t0, $t1
	sw $t0, -64($fp)
	lw $t0, -64($fp)
	sw $t0, -12($fp)
	j label_2
label_3:
	li $t0, 1
	sw $t0, -68($fp)
	li $t0, 1
	sw $t0, -72($fp)
	lw $t0, -68($fp)
	lw $t1, -72($fp)
	add $t0, $t0, $t1
	sw $t0, -76($fp)
	li $t0, 3
	sw $t0, -80($fp)
	lw $t0, -76($fp)
	lw $t1, -80($fp)
	sub $t0, $t0, $t1
	bgez $t0, label_4
	la $a0, $string_2
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_4:
	li $t0, 1
	sw $t0, -84($fp)
	li $t0, 1
	sw $t0, -88($fp)
	lw $t0, -84($fp)
	lw $t1, -88($fp)
	add $t0, $t0, $t1
	sw $t0, -92($fp)
	li $t0, 1
	sw $t0, -96($fp)
	lw $t0, -92($fp)
	lw $t1, -96($fp)
	sub $t0, $t0, $t1
	blez $t0, label_5
	la $a0, $string_3
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_5:
	la $a0, $string_4
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, -100($fp)
	li $t0, 1
	sw $t0, -104($fp)
	lw $t0, -104($fp)
	la $t1, apples
	lw $t2, -100($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	add $t1, $t1, $t2
	sw $t0, ($t1)
	li $t0, 1
	sw $t0, -108($fp)
	li $t0, 12340
	sw $t0, -112($fp)
	lw $t0, -112($fp)
	la $t1, apples
	lw $t2, -108($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	add $t1, $t1, $t2
	sw $t0, ($t1)
	li $t0, 2
	sw $t0, -116($fp)
	li $t0, 56789
	sw $t0, -120($fp)
	lw $t0, -120($fp)
	la $t1, apples
	lw $t2, -116($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	add $t1, $t1, $t2
	sw $t0, ($t1)
	la $t0, _a
	lw $t0, ($t0)
	sw $t0, -124($fp)
	li $t0, 97
	sw $t0, -128($fp)
	lw $t0, -124($fp)
	lw $t1, -128($fp)
	bne $t0, $t1, label_6
	li $t0, 0
	sw $t0, -132($fp)
	la $t0, apples
	lw $t1, -132($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	add $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -136($fp)
	la $a0, $string_5
	li $v0, 4
	syscall
	lw $a0, -136($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_6:
	lw $t0, -8($fp)
	sw $t0, -140($fp)
	li $t0, 0
	sw $t0, -144($fp)
	lw $t0, -144($fp)
	lw $t1, -140($fp)
	sub $t0, $t0, $t1
	sw $t0, -148($fp)
	li $t0, 10
	sw $t0, -152($fp)
	lw $t0, -148($fp)
	lw $t1, -152($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -156($fp)
	li $t0, 10
	sw $t0, -160($fp)
	lw $t0, -156($fp)
	lw $t1, -160($fp)
	div $t0, $t1
	mflo $t0
	sw $t0, -164($fp)
	la $t0, _a
	lw $t0, ($t0)
	sw $t0, -168($fp)
	lw $t0, -164($fp)
	lw $t1, -168($fp)
	add $t0, $t0, $t1
	sw $t0, -172($fp)
	la $t0, b
	lw $t0, ($t0)
	sw $t0, -176($fp)
	lw $t0, -172($fp)
	lw $t1, -176($fp)
	add $t0, $t0, $t1
	sw $t0, -180($fp)
	la $t0, d
	lw $t0, ($t0)
	sw $t0, -184($fp)
	lw $t0, -180($fp)
	lw $t1, -184($fp)
	sub $t0, $t0, $t1
	sw $t0, -188($fp)
	li $t0, 0
	sw $t0, -192($fp)
	la $t0, apples
	lw $t1, -192($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	add $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -196($fp)
	lw $t0, -188($fp)
	lw $t1, -196($fp)
	add $t0, $t0, $t1
	sw $t0, -200($fp)
	li $t0, 95
	sw $t0, -204($fp)
	lw $t0, -200($fp)
	lw $t1, -204($fp)
	add $t0, $t0, $t1
	sw $t0, -208($fp)
	li $t0, 43
	sw $t0, -212($fp)
	lw $t0, -208($fp)
	lw $t1, -212($fp)
	add $t0, $t0, $t1
	sw $t0, -216($fp)
	li $t0, 45
	sw $t0, -220($fp)
	lw $t0, -216($fp)
	lw $t1, -220($fp)
	add $t0, $t0, $t1
	sw $t0, -224($fp)
	li $t0, 42
	sw $t0, -228($fp)
	lw $t0, -224($fp)
	lw $t1, -228($fp)
	add $t0, $t0, $t1
	sw $t0, -232($fp)
	li $t0, 47
	sw $t0, -236($fp)
	lw $t0, -232($fp)
	lw $t1, -236($fp)
	add $t0, $t0, $t1
	sw $t0, -240($fp)
	li $t0, 65
	sw $t0, -244($fp)
	lw $t0, -240($fp)
	lw $t1, -244($fp)
	add $t0, $t0, $t1
	sw $t0, -248($fp)
	li $t0, 66
	sw $t0, -252($fp)
	lw $t0, -248($fp)
	lw $t1, -252($fp)
	add $t0, $t0, $t1
	sw $t0, -256($fp)
	li $t0, 67
	sw $t0, -260($fp)
	lw $t0, -256($fp)
	lw $t1, -260($fp)
	add $t0, $t0, $t1
	sw $t0, -264($fp)
	li $t0, 68
	sw $t0, -268($fp)
	lw $t0, -264($fp)
	lw $t1, -268($fp)
	add $t0, $t0, $t1
	sw $t0, -272($fp)
	li $t0, 69
	sw $t0, -276($fp)
	lw $t0, -272($fp)
	lw $t1, -276($fp)
	add $t0, $t0, $t1
	sw $t0, -280($fp)
	li $t0, 70
	sw $t0, -284($fp)
	lw $t0, -280($fp)
	lw $t1, -284($fp)
	add $t0, $t0, $t1
	sw $t0, -288($fp)
	li $t0, 71
	sw $t0, -292($fp)
	lw $t0, -288($fp)
	lw $t1, -292($fp)
	add $t0, $t0, $t1
	sw $t0, -296($fp)
	li $t0, 72
	sw $t0, -300($fp)
	lw $t0, -296($fp)
	lw $t1, -300($fp)
	add $t0, $t0, $t1
	sw $t0, -304($fp)
	li $t0, 73
	sw $t0, -308($fp)
	lw $t0, -304($fp)
	lw $t1, -308($fp)
	add $t0, $t0, $t1
	sw $t0, -312($fp)
	li $t0, 74
	sw $t0, -316($fp)
	lw $t0, -312($fp)
	lw $t1, -316($fp)
	add $t0, $t0, $t1
	sw $t0, -320($fp)
	li $t0, 75
	sw $t0, -324($fp)
	lw $t0, -320($fp)
	lw $t1, -324($fp)
	add $t0, $t0, $t1
	sw $t0, -328($fp)
	li $t0, 76
	sw $t0, -332($fp)
	lw $t0, -328($fp)
	lw $t1, -332($fp)
	add $t0, $t0, $t1
	sw $t0, -336($fp)
	li $t0, 77
	sw $t0, -340($fp)
	lw $t0, -336($fp)
	lw $t1, -340($fp)
	add $t0, $t0, $t1
	sw $t0, -344($fp)
	li $t0, 78
	sw $t0, -348($fp)
	lw $t0, -344($fp)
	lw $t1, -348($fp)
	add $t0, $t0, $t1
	sw $t0, -352($fp)
	li $t0, 79
	sw $t0, -356($fp)
	lw $t0, -352($fp)
	lw $t1, -356($fp)
	add $t0, $t0, $t1
	sw $t0, -360($fp)
	li $t0, 80
	sw $t0, -364($fp)
	lw $t0, -360($fp)
	lw $t1, -364($fp)
	add $t0, $t0, $t1
	sw $t0, -368($fp)
	li $t0, 81
	sw $t0, -372($fp)
	lw $t0, -368($fp)
	lw $t1, -372($fp)
	add $t0, $t0, $t1
	sw $t0, -376($fp)
	li $t0, 82
	sw $t0, -380($fp)
	lw $t0, -376($fp)
	lw $t1, -380($fp)
	add $t0, $t0, $t1
	sw $t0, -384($fp)
	li $t0, 83
	sw $t0, -388($fp)
	lw $t0, -384($fp)
	lw $t1, -388($fp)
	add $t0, $t0, $t1
	sw $t0, -392($fp)
	li $t0, 84
	sw $t0, -396($fp)
	lw $t0, -392($fp)
	lw $t1, -396($fp)
	add $t0, $t0, $t1
	sw $t0, -400($fp)
	li $t0, 85
	sw $t0, -404($fp)
	lw $t0, -400($fp)
	lw $t1, -404($fp)
	add $t0, $t0, $t1
	sw $t0, -408($fp)
	li $t0, 86
	sw $t0, -412($fp)
	lw $t0, -408($fp)
	lw $t1, -412($fp)
	add $t0, $t0, $t1
	sw $t0, -416($fp)
	li $t0, 87
	sw $t0, -420($fp)
	lw $t0, -416($fp)
	lw $t1, -420($fp)
	add $t0, $t0, $t1
	sw $t0, -424($fp)
	li $t0, 88
	sw $t0, -428($fp)
	lw $t0, -424($fp)
	lw $t1, -428($fp)
	add $t0, $t0, $t1
	sw $t0, -432($fp)
	li $t0, 89
	sw $t0, -436($fp)
	lw $t0, -432($fp)
	lw $t1, -436($fp)
	add $t0, $t0, $t1
	sw $t0, -440($fp)
	li $t0, 90
	sw $t0, -444($fp)
	lw $t0, -440($fp)
	lw $t1, -444($fp)
	add $t0, $t0, $t1
	sw $t0, -448($fp)
	li $t0, 97
	sw $t0, -452($fp)
	lw $t0, -448($fp)
	lw $t1, -452($fp)
	add $t0, $t0, $t1
	sw $t0, -456($fp)
	li $t0, 98
	sw $t0, -460($fp)
	lw $t0, -456($fp)
	lw $t1, -460($fp)
	add $t0, $t0, $t1
	sw $t0, -464($fp)
	li $t0, 99
	sw $t0, -468($fp)
	lw $t0, -464($fp)
	lw $t1, -468($fp)
	add $t0, $t0, $t1
	sw $t0, -472($fp)
	li $t0, 100
	sw $t0, -476($fp)
	lw $t0, -472($fp)
	lw $t1, -476($fp)
	add $t0, $t0, $t1
	sw $t0, -480($fp)
	li $t0, 101
	sw $t0, -484($fp)
	lw $t0, -480($fp)
	lw $t1, -484($fp)
	add $t0, $t0, $t1
	sw $t0, -488($fp)
	li $t0, 102
	sw $t0, -492($fp)
	lw $t0, -488($fp)
	lw $t1, -492($fp)
	add $t0, $t0, $t1
	sw $t0, -496($fp)
	li $t0, 103
	sw $t0, -500($fp)
	lw $t0, -496($fp)
	lw $t1, -500($fp)
	add $t0, $t0, $t1
	sw $t0, -504($fp)
	li $t0, 104
	sw $t0, -508($fp)
	lw $t0, -504($fp)
	lw $t1, -508($fp)
	add $t0, $t0, $t1
	sw $t0, -512($fp)
	li $t0, 105
	sw $t0, -516($fp)
	lw $t0, -512($fp)
	lw $t1, -516($fp)
	add $t0, $t0, $t1
	sw $t0, -520($fp)
	li $t0, 106
	sw $t0, -524($fp)
	lw $t0, -520($fp)
	lw $t1, -524($fp)
	add $t0, $t0, $t1
	sw $t0, -528($fp)
	li $t0, 107
	sw $t0, -532($fp)
	lw $t0, -528($fp)
	lw $t1, -532($fp)
	add $t0, $t0, $t1
	sw $t0, -536($fp)
	li $t0, 108
	sw $t0, -540($fp)
	lw $t0, -536($fp)
	lw $t1, -540($fp)
	add $t0, $t0, $t1
	sw $t0, -544($fp)
	li $t0, 109
	sw $t0, -548($fp)
	lw $t0, -544($fp)
	lw $t1, -548($fp)
	add $t0, $t0, $t1
	sw $t0, -552($fp)
	li $t0, 110
	sw $t0, -556($fp)
	lw $t0, -552($fp)
	lw $t1, -556($fp)
	add $t0, $t0, $t1
	sw $t0, -560($fp)
	li $t0, 111
	sw $t0, -564($fp)
	lw $t0, -560($fp)
	lw $t1, -564($fp)
	add $t0, $t0, $t1
	sw $t0, -568($fp)
	li $t0, 112
	sw $t0, -572($fp)
	lw $t0, -568($fp)
	lw $t1, -572($fp)
	add $t0, $t0, $t1
	sw $t0, -576($fp)
	li $t0, 113
	sw $t0, -580($fp)
	lw $t0, -576($fp)
	lw $t1, -580($fp)
	add $t0, $t0, $t1
	sw $t0, -584($fp)
	li $t0, 114
	sw $t0, -588($fp)
	lw $t0, -584($fp)
	lw $t1, -588($fp)
	add $t0, $t0, $t1
	sw $t0, -592($fp)
	li $t0, 115
	sw $t0, -596($fp)
	lw $t0, -592($fp)
	lw $t1, -596($fp)
	add $t0, $t0, $t1
	sw $t0, -600($fp)
	li $t0, 116
	sw $t0, -604($fp)
	lw $t0, -600($fp)
	lw $t1, -604($fp)
	add $t0, $t0, $t1
	sw $t0, -608($fp)
	li $t0, 117
	sw $t0, -612($fp)
	lw $t0, -608($fp)
	lw $t1, -612($fp)
	add $t0, $t0, $t1
	sw $t0, -616($fp)
	li $t0, 118
	sw $t0, -620($fp)
	lw $t0, -616($fp)
	lw $t1, -620($fp)
	add $t0, $t0, $t1
	sw $t0, -624($fp)
	li $t0, 119
	sw $t0, -628($fp)
	lw $t0, -624($fp)
	lw $t1, -628($fp)
	add $t0, $t0, $t1
	sw $t0, -632($fp)
	li $t0, 120
	sw $t0, -636($fp)
	lw $t0, -632($fp)
	lw $t1, -636($fp)
	add $t0, $t0, $t1
	sw $t0, -640($fp)
	li $t0, 121
	sw $t0, -644($fp)
	lw $t0, -640($fp)
	lw $t1, -644($fp)
	add $t0, $t0, $t1
	sw $t0, -648($fp)
	lw $a0, -648($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	la $a0, $string_6
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	jr $ra
label_7:
	la $a0, $string_7
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 100
	sw $t0, -8($fp)
	lw $v0, -8($fp)
	jr $ra
	jr $ra
label_8:
	li $t0, 0
	sw $t0, -24($fp)
	lw $t0, -24($fp)
	sw $t0, -20($fp)
	lw $t0, -0($fp)
	sw $t0, -28($fp)
	lw $t0, -28($fp)
	sw $t0, -16($fp)
	la $a0, $string_8
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_9:
	lw $t0, -16($fp)
	sw $t0, -32($fp)
	lw $t0, -4($fp)
	sw $t0, -36($fp)
	lw $t0, -32($fp)
	lw $t1, -36($fp)
	sub $t0, $t0, $t1
	bgtz $t0, label_10
	lw $t0, -16($fp)
	sw $t0, -40($fp)
	li $t0, 34
	sw $t0, -44($fp)
	lw $t0, -40($fp)
	lw $t1, -44($fp)
	beq $t0, $t1, label_11
	lw $t0, -16($fp)
	sw $t0, -48($fp)
	li $t0, 32
	sw $t0, -52($fp)
	lw $t0, -48($fp)
	lw $t1, -52($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_12
	lw $t0, -16($fp)
	sw $t0, -56($fp)
	li $t0, 95
	sw $t0, -60($fp)
	lw $t0, -56($fp)
	lw $t1, -60($fp)
	sub $t0, $t0, $t1
	sw $t0, -64($fp)
	li $t0, 95
	sw $t0, -68($fp)
	lw $t0, -64($fp)
	lw $t1, -68($fp)
	add $t0, $t0, $t1
	sw $t0, -72($fp)
	li $t0, 95
	sw $t0, -76($fp)
	lw $t0, -72($fp)
	lw $t1, -76($fp)
	bne $t0, $t1, label_14
	li $t0, 1
	sw $t0, -80($fp)
	lw $t0, -80($fp)
	sw $t0, -20($fp)
	j label_13
label_14:
	li $t0, 43
	sw $t0, -84($fp)
	lw $t0, -72($fp)
	lw $t1, -84($fp)
	bne $t0, $t1, label_15
	li $t0, 1
	sw $t0, -88($fp)
	lw $t0, -88($fp)
	sw $t0, -20($fp)
	j label_13
label_15:
	li $t0, 45
	sw $t0, -92($fp)
	lw $t0, -72($fp)
	lw $t1, -92($fp)
	bne $t0, $t1, label_16
	li $t0, 1
	sw $t0, -96($fp)
	lw $t0, -96($fp)
	sw $t0, -20($fp)
	j label_13
label_16:
	li $t0, 42
	sw $t0, -100($fp)
	lw $t0, -72($fp)
	lw $t1, -100($fp)
	bne $t0, $t1, label_17
	li $t0, 1
	sw $t0, -104($fp)
	lw $t0, -104($fp)
	sw $t0, -20($fp)
	j label_13
label_17:
	li $t0, 47
	sw $t0, -108($fp)
	lw $t0, -72($fp)
	lw $t1, -108($fp)
	bne $t0, $t1, label_18
	li $t0, 1
	sw $t0, -112($fp)
	lw $t0, -112($fp)
	sw $t0, -20($fp)
	j label_13
label_18:
	lw $t0, -16($fp)
	sw $t0, -116($fp)
	li $t0, 48
	sw $t0, -120($fp)
	lw $t0, -116($fp)
	lw $t1, -120($fp)
	sub $t0, $t0, $t1
	sw $t0, -124($fp)
	li $t0, 0
	sw $t0, -128($fp)
	lw $t0, -124($fp)
	lw $t1, -128($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_19
	lw $t0, -16($fp)
	sw $t0, -132($fp)
	li $t0, 57
	sw $t0, -136($fp)
	lw $t0, -132($fp)
	lw $t1, -136($fp)
	sub $t0, $t0, $t1
	sw $t0, -140($fp)
	li $t0, 0
	sw $t0, -144($fp)
	lw $t0, -140($fp)
	lw $t1, -144($fp)
	sub $t0, $t0, $t1
	bgtz $t0, label_20
	li $t0, 1
	sw $t0, -148($fp)
	lw $t0, -148($fp)
	sw $t0, -20($fp)
label_20:
label_19:
	lw $t0, -16($fp)
	sw $t0, -152($fp)
	li $t0, 65
	sw $t0, -156($fp)
	lw $t0, -152($fp)
	lw $t1, -156($fp)
	sub $t0, $t0, $t1
	sw $t0, -160($fp)
	li $t0, 0
	sw $t0, -164($fp)
	lw $t0, -160($fp)
	lw $t1, -164($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_21
	lw $t0, -16($fp)
	sw $t0, -168($fp)
	li $t0, 90
	sw $t0, -172($fp)
	lw $t0, -168($fp)
	lw $t1, -172($fp)
	sub $t0, $t0, $t1
	sw $t0, -176($fp)
	li $t0, 0
	sw $t0, -180($fp)
	lw $t0, -176($fp)
	lw $t1, -180($fp)
	sub $t0, $t0, $t1
	bgtz $t0, label_22
	li $t0, 1
	sw $t0, -184($fp)
	lw $t0, -184($fp)
	sw $t0, -20($fp)
label_22:
label_21:
	lw $t0, -16($fp)
	sw $t0, -188($fp)
	li $t0, 97
	sw $t0, -192($fp)
	lw $t0, -188($fp)
	lw $t1, -192($fp)
	sub $t0, $t0, $t1
	sw $t0, -196($fp)
	li $t0, 0
	sw $t0, -200($fp)
	lw $t0, -196($fp)
	lw $t1, -200($fp)
	sub $t0, $t0, $t1
	bltz $t0, label_23
	lw $t0, -16($fp)
	sw $t0, -204($fp)
	li $t0, 122
	sw $t0, -208($fp)
	lw $t0, -204($fp)
	lw $t1, -208($fp)
	sub $t0, $t0, $t1
	sw $t0, -212($fp)
	li $t0, 0
	sw $t0, -216($fp)
	lw $t0, -212($fp)
	lw $t1, -216($fp)
	sub $t0, $t0, $t1
	bgtz $t0, label_24
	li $t0, 1
	sw $t0, -220($fp)
	lw $t0, -220($fp)
	sw $t0, -20($fp)
label_24:
label_23:
label_13:
label_12:
	lw $t0, -16($fp)
	sw $t0, -224($fp)
	lw $t0, -0($fp)
	sw $t0, -228($fp)
	lw $t0, -224($fp)
	lw $t1, -228($fp)
	sub $t0, $t0, $t1
	sw $t0, -232($fp)
	lw $t0, -16($fp)
	sw $t0, -236($fp)
	lw $t0, -236($fp)
	la $t1, str
	lw $t2, -232($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	add $t1, $t1, $t2
	sw $t0, ($t1)
	lw $t0, -20($fp)
	sw $t0, -240($fp)
	li $t0, 1
	sw $t0, -244($fp)
	lw $t0, -240($fp)
	lw $t1, -244($fp)
	bne $t0, $t1, label_25
	lw $t0, -16($fp)
	sw $t0, -248($fp)
	lw $t0, -0($fp)
	sw $t0, -252($fp)
	lw $t0, -248($fp)
	lw $t1, -252($fp)
	sub $t0, $t0, $t1
	sw $t0, -256($fp)
	la $t0, str
	lw $t1, -256($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	add $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -260($fp)
	la $a0, $string_9
	li $v0, 4
	syscall
	lw $a0, -260($fp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 0
	sw $t0, -264($fp)
	lw $t0, -264($fp)
	sw $t0, -20($fp)
label_25:
label_11:
	lw $t0, -16($fp)
	sw $t0, -268($fp)
	li $t0, 34
	sw $t0, -272($fp)
	li $t0, -34
	sw $t0, -276($fp)
	lw $t0, -272($fp)
	lw $t1, -276($fp)
	add $t0, $t0, $t1
	sw $t0, -280($fp)
	li $t0, 34
	sw $t0, -284($fp)
	lw $t0, -280($fp)
	lw $t1, -284($fp)
	add $t0, $t0, $t1
	sw $t0, -288($fp)
	lw $t0, -268($fp)
	lw $t1, -288($fp)
	bne $t0, $t1, label_26
	la $a0, $string_10
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
label_26:
	lw $t0, -16($fp)
	sw $t0, -292($fp)
	li $t0, 1
	sw $t0, -296($fp)
	lw $t0, -292($fp)
	lw $t1, -296($fp)
	add $t0, $t0, $t1
	sw $t0, -300($fp)
	lw $t0, -300($fp)
	sw $t0, -16($fp)
	j label_9
label_10:
	jr $ra
	jr $ra
label_27:
	lw $t0, -4($fp)
	sw $t0, -16($fp)
	li $t0, 0
	sw $t0, -20($fp)
	lw $t0, -16($fp)
	lw $t1, -20($fp)
	bne $t0, $t1, label_28
	lw $t0, -0($fp)
	sw $t0, -24($fp)
	lw $v0, -24($fp)
	jr $ra
label_28:
	lw $t0, -4($fp)
	sw $t0, -28($fp)
	li $t0, 0
	sw $t0, -32($fp)
	lw $t0, -28($fp)
	lw $t1, -32($fp)
	beq $t0, $t1, label_29
	lw $t0, -4($fp)
	sw $t0, -36($fp)
	lw $t0, -36($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	lw $t0, -0($fp)
	sw $t0, -40($fp)
	lw $t0, -0($fp)
	sw $t0, -44($fp)
	lw $t0, -4($fp)
	sw $t0, -48($fp)
	lw $t0, -44($fp)
	lw $t1, -48($fp)
	div $t0, $t1
	mflo $t0
	sw $t0, -52($fp)
	lw $t0, -4($fp)
	sw $t0, -56($fp)
	lw $t0, -52($fp)
	lw $t1, -56($fp)
	mult $t0, $t1
	mflo $t0
	sw $t0, -60($fp)
	lw $t0, -40($fp)
	lw $t1, -60($fp)
	sub $t0, $t0, $t1
	sw $t0, -64($fp)
	lw $t0, -64($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -72
	jal label_27
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -68($fp)
	lw $v0, -68($fp)
	jr $ra
label_29:
	jr $ra
label_0:
	li $t0, 110
	sw $t0, -0($fp)
	la $a0, $string_11
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $v0, 5
	syscall
	sw $v0, -4($fp)
	li $v0, 5
	syscall
	sw $v0, -8($fp)
	lw $t0, -4($fp)
	sw $t0, -16($fp)
	la $a0, $string_12
	li $v0, 4
	syscall
	lw $a0, -16($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -8($fp)
	sw $t0, -20($fp)
	lw $a0, -20($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -4($fp)
	sw $t0, -24($fp)
	lw $t0, -24($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	lw $t0, -8($fp)
	sw $t0, -28($fp)
	lw $t0, -28($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -72
	jal label_27
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	sw $v0, -32($fp)
	lw $t0, -32($fp)
	sw $t0, -12($fp)
	lw $t0, -4($fp)
	sw $t0, -36($fp)
	la $a0, $string_13
	li $v0, 4
	syscall
	lw $a0, -36($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -8($fp)
	sw $t0, -40($fp)
	lw $a0, -40($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -12($fp)
	sw $t0, -44($fp)
	la $a0, $string_14
	li $v0, 4
	syscall
	lw $a0, -44($fp)
	li $v0, 1
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	lw $t0, -4($fp)
	sw $t0, -48($fp)
	li $t0, 100
	sw $t0, -52($fp)
	lw $t0, -48($fp)
	lw $t1, -52($fp)
	bne $t0, $t1, label_33
	la $a0, $string_15
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -652
	jal label_1
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 0
	move $fp, $sp
	addiu $sp, $fp, -12
	jal label_7
	move $sp, $fp
	lw $fp, -4($sp)
	lw $ra, -0($sp)
	sw $v0, -56($fp)
	la $a0, $string_16
	li $v0, 4
	syscall
	lw $a0, -56($fp)
	li $v0, 11
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	li $t0, 32
	sw $t0, -60($fp)
	lw $t0, -60($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	li $t0, 126
	sw $t0, -64($fp)
	lw $t0, -64($fp)
	sw $t0, ($sp)
	addiu $sp, $sp, -4
	sw $ra, ($sp)
	sw $fp, -4($sp)
	addiu $sp, $sp, 8
	move $fp, $sp
	addiu $sp, $fp, -304
	jal label_8
	move $sp, $fp
	lw $fp, -12($sp)
	lw $ra, -8($sp)
	j label_32
label_33:
	li $t0, -1
	sw $t0, -68($fp)
	lw $t0, -48($fp)
	lw $t1, -68($fp)
	bne $t0, $t1, label_37
	la $a0, $string_17
	li $v0, 4
	syscall
	la $a0, $string_0
	li $v0, 4
	syscall
	j label_32
label_37:
label_32:
	li $v0, 10
	syscall
	li $v0, 10
	syscall
