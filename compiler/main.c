#include "stdafx.h"
#include "lexer.h"
#include "parser.h"
#include "error.h"
#include "gencode.h"
#include "IR.h"

int main(void) {
	char filename[100], outfilename[100];
	scanf_s("%s", filename, 100);
	fopen_s(&fp, filename, "r");
	if (fp == NULL) {
		error(FILE_NOT_EXIST);
		system("pause");
		return 0;
	}
	else {
		getch();
		while (ch == ' ')
			getch();
		if (ch != EOF) {
			init();
			getsym();
			program();
		}
	}
	updateFuncVarNum();

	// printf symTable and subTable
	int i, cnt = 0;
	for (i = 0; i < symTable->top; i++) {
		printf("%d name:%s kind:%d type:%d value:%d number:%d addr:%d ", cnt, symTable->table[i].name, symTable->table[i].kind, symTable->table[i].type, symTable->table[i].value, symTable->table[i].number, symTable->table[i].addr);
		if (symTable->table[i].kind == 3)
			printf("sum:%d", symTable->table[i].sum);
		printf("\n");
		cnt++;
	}
	for (i = 0; i < symTable->subprogramNumber; i++) {
		printf("%d\n", symTable->subprogramTable[i]);
	}

	// printf IRlist
	printf("\n");
	for (i = 0; i < IRtop; i++) {
		printf("%s,%s,%s,%s\n", IRlistName[IRlist[i].op], IRlist[i].op1, IRlist[i].op2, IRlist[i].res);
	}

	fclose(fp);
	strcpy(outfilename, "output.asm");
	fopen_s(&outputfp, outfilename, "w");
	gendata();
	gentext();
	fclose(outputfp);
	system("pause");
	return 0;
}