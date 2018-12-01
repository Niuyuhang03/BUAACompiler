#include "stdafx.h"
#include "parser.h"
#include "IR.h"
#include "gencode.h"

FILE *outputfp;
char line[100];				// 写入文件的一行
int getParaIndex = 0;		// 取出参数getpop时寄存器a下标
int curLayer = 0;			// 当前函数在分程序表的下标

/*
* Summary: gen .word code, include global variable and STRING.
*/
void gendata() {
	strcpy(line, ".data\n");
	fputs(line, outputfp);
	int i;
	for (i = 0; i < symTable->top; i++) {
		if (symTable->table[i].kind == 6) {
			strcpy(line, "        ");
			strcat(line, symTable->table[i].name);
			strcat(line, ": .asciiz \"");
			strcat(line, symTable->table[i].STRING);
			strcat(line, "\"\n");
			fputs(line, outputfp);
		}
	}
	for (i = 0; i < IRtop; i++) {
		if (IRlist[i].op != conop && IRlist[i].op != varop)
			break;
		strcpy(line, "        ");
		strcat(line, IRlist[i].res);
		if (IRlist[i].op == conop) {
			strcat(line, ": .word ");
			strcat(line, IRlist[i].op2);
		}
		else {
			strcat(line, ": .word 0");
			if (strcmp(IRlist[i].op2, "0") != 0) {
				strcat(line, ":");
				strcat(line, IRlist[i].op2);
			}
		}
		strcat(line, "\n");
		fputs(line, outputfp);
	}
}

/*
* Summary: gen .text code.
*/
void gentext() {
	int i;
	for (i = 0; i < IRtop; i++) {
		if (i == 0 && (IRlist[i].op == conop || IRlist[i].op == varop)) {
			i = symTable->subprogramTable[1] - 1;
			continue;
		}
		switch (IRlist[i].op) {
		case(setop): {
			strcpy(line, IRlist[i].res);
			strcat(line, ":\n");
			fputs(line, outputfp);
			break;
		}
		case(getpop): {
			strcpy(line, "        ");
			strcat(line, "sw $a");
			char tempIndex[100];
			_itoa(getParaIndex, tempIndex, 10);
			strcat(line, tempIndex);
			getParaIndex++;
			struct node curNode = findIdentInSymTable(IRlist[i].res);
			strcat(line, ", ");
			char addr[100];
			_itoa(curNode.addr, addr, 10);
			strcat(line, addr);
			strcat(line, "($sp)\n");
			fputs(line, outputfp);
			break;
		}
		case(jrop): {
			strcpy(line, "        ");
			strcat(line, "jr $ra\n");
			fputs(line, outputfp);
			break;
		}
		case(getiop): {
			strcpy(line, "        ");
			strcat(line, "li $t0, ");
			strcat(line, IRlist[i].op1);
			strcat(line, "\n");
			fputs(line, outputfp);
			strcpy(line, "        ");
			strcat(line, "sw $t0, ");
			struct node curNode = findIdentInSymTable(IRlist[i].res);
			char addr[100];
			_itoa(curNode.addr, addr, 10);
			strcat(line, addr);
			strcat(line, "($sp)\n");
			fputs(line, outputfp);
			break;
		}
		case()
		}
	}
}