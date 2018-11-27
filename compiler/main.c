#include "stdafx.h"
#include "lexer.h"
#include "parser.h"
#include "error.h"

int main(void) {
	char filename[100];
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

	// printf symTable and subTable
	int i, cnt = 0;
	for (i = 0; i < symTable->top; i++) {
		printf("%d name:%s kind:%d type:%d value:%d number:%d\n", cnt, symTable->table[i].name, symTable->table[i].kind, symTable->table[i].type, symTable->table[i].value, symTable->table[i].number);
		cnt++;
	}
	for (i = 0; i < symTable->subprogramNumber; i++) {
		printf("%d\n", symTable->subprogramTable[i]);
	}

	fclose(fp);
	system("pause");
	return 0;
}