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
void push_in_symList(enum symbol temp_sym, char *name, int value, int row, int column);

FILE *fp;
char ch;												// �ն�����һ���ַ�
enum symbol sym;										// �ն����ķ�������
struct symInfo *symList[MAX_SYMLIST_NUM];				// sym���б�
int symList_index;										// symList���±�
int symList_max_index;									// symList��β���±�
int startRow, maxColumn, startColumn;					// ������������Ϣ
int iValue;												// int�͵�ֵ
char cValue[100];										// char�͵�ֵ
int row, column;										// ���е�λ����Ϣ