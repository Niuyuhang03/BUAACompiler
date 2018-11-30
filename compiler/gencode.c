#include "stdafx.h"
#include "parser.h"
#include "IR.h"
#include "gencode.h"

FILE *outputfp;
char line[100];				// 写入文件的一行

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
		strcat(line, ": .word ");
		if (strcmp(IRlist[i].op2, "0") == 0)
			strcat(line, "1\n");
		else {
			strcat(line, IRlist[i].op2);
			strcat(line, "\n");
		}
		fputs(line, outputfp);
	}
}

/*
* Summary: gen .text code.
*/
void gentext() {

}