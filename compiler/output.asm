.data
	$string_0: .asciiz "\n"
	a: .word 1000
	c: .word 99
	array1: .word 0:500
.text
	move $fp, $sp
	addiu $sp, $fp, -1736
	j label_0
label_0:
	li $t0, 9000
	sw $t0, -0($fp)
	la $t0, a
	lw $t0, ($t0)
	sw $t0, -1608($fp)
	li $t0, 1
	sw $t0, -1612($fp)
	lw $t0, -1612($fp)
	la $t1, array1
	lw $t2, -1608($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	addu $t1, $t1, $t2
	sw $t0, ($t1)
	lw $t0, -0($fp)
	sw $t0, -1616($fp)
	li $t0, 1
	sw $t0, -1620($fp)
	lw $t0, -1620($fp)
	la $t1, array1
	lw $t2, -1616($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	addu $t1, $t1, $t2
	sw $t0, ($t1)
	li $t0, 10000
	sw $t0, -1624($fp)
	li $t0, 1
	sw $t0, -1628($fp)
	lw $t0, -1628($fp)
	la $t1, array1
	lw $t2, -1624($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	addu $t1, $t1, $t2
	sw $t0, ($t1)
	la $t0, c
	lw $t0, ($t0)
	sw $t0, -1632($fp)
	li $t0, 1
	sw $t0, -1636($fp)
	lw $t0, -1636($fp)
	la $t1, array1
	lw $t2, -1632($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	addu $t1, $t1, $t2
	sw $t0, ($t1)
	la $t0, a
	lw $t0, ($t0)
	sw $t0, -1640($fp)
	li $t0, 1
	sw $t0, -1644($fp)
	lw $t0, -1644($fp)
	addiu $t1, $fp, -4
	lw $t2, -1640($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	subu $t1, $t1, $t2
	sw $t0, ($t1)
	lw $t0, -0($fp)
	sw $t0, -1648($fp)
	li $t0, 1
	sw $t0, -1652($fp)
	lw $t0, -1652($fp)
	addiu $t1, $fp, -4
	lw $t2, -1648($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	subu $t1, $t1, $t2
	sw $t0, ($t1)
	li $t0, 10000
	sw $t0, -1656($fp)
	li $t0, 1
	sw $t0, -1660($fp)
	lw $t0, -1660($fp)
	addiu $t1, $fp, -4
	lw $t2, -1656($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	subu $t1, $t1, $t2
	sw $t0, ($t1)
	la $t0, c
	lw $t0, ($t0)
	sw $t0, -1664($fp)
	li $t0, 1
	sw $t0, -1668($fp)
	lw $t0, -1668($fp)
	addiu $t1, $fp, -4
	lw $t2, -1664($fp)
	li $t3, 4
	mult $t2, $t3
	mflo $t2
	subu $t1, $t1, $t2
	sw $t0, ($t1)
	la $t0, a
	lw $t0, ($t0)
	sw $t0, -1672($fp)
	la $t0, array1
	lw $t1, -1672($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	addu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1676($fp)
	lw $t0, -1676($fp)
	sw $t0, -1604($fp)
	lw $t0, -0($fp)
	sw $t0, -1680($fp)
	la $t0, array1
	lw $t1, -1680($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	addu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1684($fp)
	lw $t0, -1684($fp)
	sw $t0, -1604($fp)
	li $t0, 10000
	sw $t0, -1688($fp)
	la $t0, array1
	lw $t1, -1688($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	addu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1692($fp)
	lw $t0, -1692($fp)
	sw $t0, -1604($fp)
	la $t0, c
	lw $t0, ($t0)
	sw $t0, -1696($fp)
	la $t0, array1
	lw $t1, -1696($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	addu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1700($fp)
	lw $t0, -1700($fp)
	sw $t0, -1604($fp)
	la $t0, a
	lw $t0, ($t0)
	sw $t0, -1704($fp)
	addiu $t0, $fp, -4
	lw $t1, -1704($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	subu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1708($fp)
	lw $t0, -1708($fp)
	sw $t0, -1604($fp)
	lw $t0, -0($fp)
	sw $t0, -1712($fp)
	addiu $t0, $fp, -4
	lw $t1, -1712($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	subu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1716($fp)
	lw $t0, -1716($fp)
	sw $t0, -1604($fp)
	li $t0, 10000
	sw $t0, -1720($fp)
	addiu $t0, $fp, -4
	lw $t1, -1720($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	subu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1724($fp)
	lw $t0, -1724($fp)
	sw $t0, -1604($fp)
	la $t0, c
	lw $t0, ($t0)
	sw $t0, -1728($fp)
	addiu $t0, $fp, -4
	lw $t1, -1728($fp)
	li $t2, 4
	mult $t1, $t2
	mflo $t1
	subu $t0, $t0, $t1
	lw $t0, ($t0)
	sw $t0, -1732($fp)
	lw $t0, -1732($fp)
	sw $t0, -1604($fp)
	li $v0, 10
	syscall
