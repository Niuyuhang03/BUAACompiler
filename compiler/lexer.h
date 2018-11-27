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
	int assignFlag;											// ��ʶ���Ƿ񱻸�ֵ����0:δ��ֵ,1:��ֵ
};

void getch();
int isinkey(char *string);
void getsym();
void push_in_symList(enum symbol temp_sym);

extern FILE *fp;
extern char ch;												// �ն�����һ���ַ�
extern enum symbol sym;										// �ն����ķ�������
extern struct symInfo *symList[MAX_SYMLIST_NUM];			// sym���б�
extern int symList_index;									// symList���±�
extern int symList_max_index;								// symList��β���±�
extern int startRow, maxColumn, startColumn;				// ������������Ϣ
extern int iValue;											// int�͵�ֵ
extern char cValue[100];									// char�͵�ֵ
extern int row, column;										// ���е�λ����Ϣ