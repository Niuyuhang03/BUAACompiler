#include "stdafx.h"
#include "parser.h"
#include "IR.h"
#include "gencode.h"

FILE *outputfp;
char line[100];				// 写入文件的一行
int getParaIndex = 0;		// 取出参数（getpop）时寄存器a下标
int setParaIndex = 0;		// 存入参数（para）时寄存器a下标
int layer[10000];			// 运行栈中的分程序信息
int layerTop = 0;			// 运行栈中的分程序信息的顶部

/*
* Summary: gen .word code, include global variable and STRING.
*/
void gendata() {
	fprintf(outputfp, ".data\n");
	fprintf(outputfp, "\t$string_0: .asciiz \"\\n\"\n");
	int i;
	for (i = 0; i < symTable->top; i++) {
		if (symTable->table[i].kind == 6)
			fprintf(outputfp, "\t%s: .asciiz \"%s\"\n", symTable->table[i].name, symTable->table[i].STRING);
	}
	for (i = 0; i < IRtop; i++) {
		if (IRlist[i].op != conop && IRlist[i].op != varop)
			break;
		if (IRlist[i].op == conop)
			fprintf(outputfp, "\t%s: .word %s\n", IRlist[i].res, IRlist[i].op2);
		else {
			if (strcmp(IRlist[i].op2, "0") != 0)
				fprintf(outputfp, "\t%s: .word 0:%s\n", IRlist[i].res, IRlist[i].op2);
			else
				fprintf(outputfp, "\t%s: .word 0\n", IRlist[i].res);
		}
	}
}

/*
* Summary: gen .text code.
*/
void gentext() {
	fprintf(outputfp, ".text\n");
	int i;
	for (i = 0; i < IRtop; i++) {
		if (i == 0 && (IRlist[i].op == conop || IRlist[i].op == varop)) {
			i = symTable->subprogramTable[1] - 1;
			continue;
		}
		switch (IRlist[i].op) {
			case(setop): {
				fprintf(outputfp, "%s:\n", IRlist[i].res);
				break;
			}
			case(fstaop): {
				struct node curNode = findFunction(IRlist[i].res);
				layer[layerTop++] = curNode.level;
				break;
			}
			case(getpop): {
				struct node curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $a%d, %d($sp)\n", getParaIndex, curNode.addr);
				getParaIndex++;
				break;
			}
			case(jrop): {
				fprintf(outputfp, "\tjr $ra\n");
				layerTop--;
				break;
			}
			case(getiop): {
				fprintf(outputfp, "\tli $t0, %s\n", IRlist[i].op1);
				struct node curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(conop): {
				fprintf(outputfp, "\tli $t0, %s\n", IRlist[i].op2);
				struct node curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(getop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				if (curNode.level == 0 && symTable->table[0].kind != 3) {
					fprintf(outputfp, "\tla $t0, %s\n", curNode.name);
					fprintf(outputfp, "\tlw $t0, ($t0)\n");
				}
				else
					fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(getaop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", atoi(IRlist[i].op2) * 4 + curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(stoop): {
				if (strcmp(IRlist[i].op2, "") == 0) {
					struct node curNode = findIdentInSymTable(IRlist[i].op1);
					fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
					curNode = findIdentInSymTable(IRlist[i].res);
					if (curNode.level == 0 && symTable->table[0].kind != 3) {
						fprintf(outputfp, "\tla $t1, %s\n", curNode.name);
						fprintf(outputfp, "\tsw $t0, ($t1)\n");
					}
					else {
						fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
					}
				}
				else {
					struct node curNode = findIdentInSymTable(IRlist[i].op1);
					fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
					curNode = findIdentInSymTable(IRlist[i].res);
					if (curNode.level == 0 && symTable->table[0].kind != 3) {
						fprintf(outputfp, "\tla $t1, %s\n", curNode.name);
						fprintf(outputfp, "\tsw $t0, %d($t1)\n", atoi(IRlist[i].op2) * 4);
					}
					else {
						fprintf(outputfp, "\tsw $t0, %d($sp)\n", atoi(IRlist[i].op2) * 4 + curNode.addr);
					}
				}
				break;
			}
			case(paraop): {
				struct node curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tlw $a%d, %d($sp)\n", setParaIndex, curNode.addr);
				setParaIndex++;
				break;
			}
			case(bgezop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tsub $t0, $t0, $t1\n");
				fprintf(outputfp, "\tbgez $t0, %s\n", IRlist[i].res);
				break;
			}
			case(bgtzop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tsub $t0, $t0, $t1\n");
				fprintf(outputfp, "\tbgtz $t0, %s\n", IRlist[i].res);
				break;
			}
			case(bltzop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tsub $t0, $t0, $t1\n");
				fprintf(outputfp, "\tbltz $t0, %s\n", IRlist[i].res);
				break;
			}
			case(blezop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tsub $t0, $t0, $t1\n");
				fprintf(outputfp, "\tblez $t0, %s\n", IRlist[i].res);
				break;
			}
			case(bneop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tbne $t0, $t1, %s\n", IRlist[i].res);
				break;
			}
			case(beqop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tbeq $t0, $t1, %s\n", IRlist[i].res);
				break;
			}
			case(retop): {
				if (strcmp("", IRlist[i].res) == 0)
					fprintf(outputfp, "\tjr $ra\n");
				else {
					struct node curNode = findIdentInSymTable(IRlist[i].res);
					fprintf(outputfp, "\tlw $v0, %d($sp)\n", curNode.addr);
					fprintf(outputfp, "\tjr $ra\n");
				}
				break;
			}
			case(sraop): {
				fprintf(outputfp, "\tsw $ra, ($sp)\n");
				break;
			}
			case(scaop): {
				struct node curNode = findIdentInSymTable(IRlist[i].res);
				if (curNode.type == 2) {
					fprintf(outputfp, "\tli $v0, 5\n");
					fprintf(outputfp, "\tsyscall\n");
					if (curNode.level == 0 && symTable->table[0].kind != 3) {
						fprintf(outputfp, "\tla $t1, %s\n", curNode.name);
						fprintf(outputfp, "\tsw $v0, ($t1)\n");
					}
					else {
						fprintf(outputfp, "\tsw $v0, %d($sp)\n", curNode.addr);
					}
				}
				else if (curNode.type == 3) {
					fprintf(outputfp, "\tli $v0, 12\n");
					fprintf(outputfp, "\tsyscall\n");
					if (curNode.level == 0 && symTable->table[0].kind != 3) {
						fprintf(outputfp, "\tla $t1, %s\n", curNode.name);
						fprintf(outputfp, "\tsw $v0, %d($t1)\n", atoi(IRlist[i].op2) * 4);
					}
					else {
						fprintf(outputfp, "\tsw $v0, %d($sp)\n", atoi(IRlist[i].op2) * 4 + curNode.addr);
					}
				}
				break;
			}
			case(priop): {
				if (strcmp(IRlist[i].op1, "") != 0) {
					fprintf(outputfp, "\tla $a0, %s\n", IRlist[i].op1);
					fprintf(outputfp, "\tli $v0, 4\n");
					fprintf(outputfp, "\tsyscall\n");
				}
				if (strcmp(IRlist[i].res, "") != 0) {
					struct node curNode = findIdentInSymTable(IRlist[i].res);
					if (curNode.type == 2) {
						fprintf(outputfp, "\tlw $a0, %d($sp)\n", curNode.addr);
						fprintf(outputfp, "\tli $v0, 1\n");
						fprintf(outputfp, "\tsyscall\n");
					}
					else if (curNode.type == 3) {
						fprintf(outputfp, "\tlw $a0, %d($sp)\n", curNode.addr);
						fprintf(outputfp, "\tli $v0, 11\n");
						fprintf(outputfp, "\tsyscall\n");
					}
				}
				fprintf(outputfp, "\tla $a0, $string_0\n");
				fprintf(outputfp, "\tli $v0, 4\n");
				fprintf(outputfp, "\tsyscall\n");
				break;
			}
			case(endop): {
				fprintf(outputfp, "\tli $v0, 10\n");
				fprintf(outputfp, "\tsyscall\n");
				break;
			}
			case(addop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tadd $t0, $t0, $t1\n");
				curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(subop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tsub $t0, $t0, $t1\n");
				curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(multop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tmult $t0, $t1\n");
				fprintf(outputfp, "\tmflo $t0\n");
				curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(divop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tlw $t0, %d($sp)\n", curNode.addr);
				curNode = findIdentInSymTable(IRlist[i].op2);
				fprintf(outputfp, "\tlw $t1, %d($sp)\n", curNode.addr);
				fprintf(outputfp, "\tdiv $t0, $t1\n");
				fprintf(outputfp, "\tmflo $t0\n");
				curNode = findIdentInSymTable(IRlist[i].res);
				fprintf(outputfp, "\tsw $t0, %d($sp)\n", curNode.addr);
				break;
			}
			case(jop): {
				fprintf(outputfp, "\tj %s\n", IRlist[i].res);
				break;
			}
			case(getrop): {
				struct node curNode = findIdentInSymTable(IRlist[i].op1);
				fprintf(outputfp, "\tsw $v0, %d($sp)\n", curNode.addr);
				break;
			}
			case(callop): {
				getParaIndex = 0;
				setParaIndex = 0;
				struct node curNode = findFunction(IRlist[i].res);
				int sum = (curNode.sum + 1) * 4;
				if (strcmp(IRlist[i].res, "main") != 0) {
					fprintf(outputfp, "\taddiu, $sp, $sp, -%d\n", sum);
					fprintf(outputfp, "\tsw $ra, ($sp)\n");
					fprintf(outputfp, "\tjal %s\n", curNode.label);
					fprintf(outputfp, "\tlw $ra, ($sp)\n");
					fprintf(outputfp, "\taddiu, $sp, $sp, %d\n", sum);
				}
				else
					fprintf(outputfp, "\tj %s\n", curNode.label);
				break;
			}
		}
	}
}