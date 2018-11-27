#pragma once

#define	MAX_KEY_NUM	13
#define KEY_LENGTH	9
#define MAX_SPEC_SYMBOL_NUM	20
#define SPEC_SYMBOL_LENGTH	2
#define MAX_SYMBOL_NUM	6+MAX_KEY_NUM+MAX_SPEC_SYMBOL_NUM
#define SYMBOL_LENGTH	KEY_LENGTH>SPEC_SYMBOL_LENGTH?KEY_LENGTH:SPEC_SYMBOL_LENGTH
#define MAX_SYMLIST_NUM	1000000

enum symbol {
	IDENT = 0, NUMBER, CHAR, STRING, ERROR, NOTHING, CASESY, CHARSY, CONSTSY, DEFAULTSY, IFSY, INTSY, MAINSY, PRINTFSY, RETURNSY, SCANFSY, SWITCHSY, VOIDSY, WHILESY, NEQ, LPAR, RPAR, MULT, PLUS, COMMA, MINUS, DIV, COLON, SEMICOLON, LT, LE, IS, EQ, GT, GE, LBRACK, RBRACK, LBRACE, RBRACE
};

struct symInfo {
	enum symbol sym;
	char name[100];
	int value;
	int row;
	int column;
	int assignFlag;											// 标识符是否被赋值过，0:未赋值,1:赋值
};

void getch();
int isinkey(char *string);
void getsym();
void push_in_symList(enum symbol temp_sym);

extern FILE *fp;
extern char ch;												// 刚读到的一个字符
extern enum symbol sym;										// 刚读到的符号类型
extern struct symInfo *symList[MAX_SYMLIST_NUM];			// sym的列表
extern int symList_index;									// symList的下标
extern int symList_max_index;								// symList队尾的下标
extern int startRow, maxColumn, startColumn;				// 错误输出相关信息
extern int iValue;											// int型的值
extern char cValue[100];									// char型的值
extern int row, column;										// 行列的位置信息