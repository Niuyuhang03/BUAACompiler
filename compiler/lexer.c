#include "stdafx.h"
#include "lexer.h"
#include "parser.h"
#include "error.h"

enum symbol key_sy[MAX_KEY_NUM] = { CASESY, CHARSY, CONSTSY, DEFAULTSY, IFSY, INTSY, MAINSY, PRINTFSY, RETURNSY, SCANFSY, SWITCHSY, VOIDSY, WHILESY };
// enum symbol spec_symbol_sy[MAX_SPEC_SYMBOL_NUM] = { NEQ, LPAR, RPAR, MULT, PLUS, COMMA, MINUS, DIV, COLON, SEMICOLON, LT, LE, IS, EQ, GT, GE, LBRACK, RBRACK, LBRACE, RBRACE };
const char key[MAX_KEY_NUM][KEY_LENGTH + 1] = { "case", "char", "const", "default", "if", "int", "main", "printf", "return", "scanf", "switch", "void", "while" };
// const char spec_symbol[MAX_SPEC_SYMBOL_NUM][SPEC_SYMBOL_LENGTH + 1] = { "!=", "(", ")", "*", "+", ",", "-", "/", ":", ";", "<", "<=", "=", "==", ">", ">=", "[", "]", "{", "}" };
const char symbol_name[MAX_SYMBOL_NUM][SYMBOL_LENGTH + 1] = { "IDENT", "NUMBER", "CHAR", "STRING", "ERROR", "CASESY", "CHARSY", "CONSTSY", "DEFAULTSY", "IFSY", "INTSY", "MAINSY", "PRINTFSY", "RETURNSY", "SCANFSY", "SWITCHSY", "VOIDSY", "WHILESY", "NEQ", "LPAR", "RPAR", "MULT", "PLUS", "COMMA", "MINUS", "DIV", "COLON", "SEMICOLON", "LT", "LE", "IS", "EQ", "GT", "GE", "LBRACK", "RBRACK", "LBRACE", "RBRACE" };

FILE *fp;
char ch;												// 刚读到的一个字符
enum symbol sym;										// 刚读到的符号类型
struct symInfo *symList[MAX_SYMLIST_NUM];				// sym的列表
int symList_index = 0;									// symList的下标
int symList_max_index = -1;								// symList队尾的下标
int outputLine = 1;										// 文法分析行数
int startRow, maxColumn, startColumn;					// 错误输出相关信息
int iValue;												// int型的值
char cValue[100];										// char型的值
int row, column;										// 行列的位置信息

/*
* Summary: get next char, do while ch is not '\n'.
*/
void getch() {
	ch = fgetc(fp);
	column++;
	while (ch == '\n' || ch == '\t') {
		ch = fgetc(fp);
		row++;
		column = 1;
	}
}

/*
* Summary: push sym into symlist
*/
void push_in_symList(enum symbol temp_sym, char *name, int value, int row, int column) {
	sym = temp_sym;
	symList[symList_index] = (struct symInfo*)malloc(sizeof(struct symInfo));
	symList[symList_index]->sym = temp_sym;
	strcpy(symList[symList_index]->name, name);
	symList[symList_index]->value = value;
	symList[symList_index]->row = row;
	symList[symList_index]->column = column;
	symList[symList_index]->assignFlag = 0;
	symList_index++;
	symList_max_index++;
}

/*
* Summary: find string in key list, if found, return index. if not found, return -1.
*/
int isinkey(char *string) {								// 在保留字表key中查找string，找到则返回下标，否则返回-1
	int start = 0, end = MAX_KEY_NUM, mid, result;
	while (1) {
		if (start > end)
			return -1;
		mid = (start + end) / 2;
		result = strcmp(key[mid], string);
		if (result == 0)
			return mid;
		else if (result > 0)
			end = mid - 1;
		else
			start = mid + 1;
	}
}

/*
* Summary: get next symbol and assign to sym.
*/
void getsym() {
	iValue = 0;
	memset(cValue, 0, strlen(cValue));
	int cCnt = 0;					// cValue内指针
	if (symList_index <= symList_max_index) {
		sym = symList[symList_index]->sym;
		iValue = symList[symList_index]->value;
		strcpy(cValue, symList[symList_index]->name);
		row = symList[symList_index]->row;
		column = symList[symList_index]->column;
		symList_index++;
	}
	else {
		if (ch == EOF) {
			push_in_symList(NOTHING, "", 0, row, column);
			return;
		}
		else if (ch < -1 || ch > 255) {
			error(ILLEGAL_WORD);
			exit(0);
		}
		if (isdigit(ch)) {
			int startWithZero = 0, len = 0;
			iValue = ch - '0';
			if (iValue == 0)
				startWithZero = 1;
			len++;
			getch();
			while (isdigit(ch)) {
				len++;
				iValue = iValue * 10 + ch - '0';
				getch();
			}
			while (ch == ' ')
				getch();
			if (iValue != 0 && startWithZero && len > 1) {
				error(ZERO_HEAD_NUM);
				push_in_symList(NUMBER, "", iValue, row, column);
			}
			else {
				// printf("%d %s %d\n", outputLine, symbol_name[NUMBER], iValue);
				push_in_symList(NUMBER, "", iValue, row, column);
			}
			outputLine++;
		}
		else if (isalpha(ch) || ch == '_') {
			cValue[cCnt++] = ch;
			getch();
			while (isalpha(ch) || isdigit(ch) || ch == '_') {
				cValue[cCnt++] = ch;
				getch();
			}
			cValue[cCnt] = '\0';
			while (ch == ' ')
				getch();
			int site;
			if ((site = isinkey(cValue)) >= 0) {
				// printf("%d %s %s\n", outputLine, symbol_name[key_sy[site]], cValue);
				outputLine++;
				push_in_symList(key_sy[site], "", 0, row, column);
			}
			else {
				// printf("%d %s %s\n", outputLine, symbol_name[IDENT], cValue);
				outputLine++;
				push_in_symList(IDENT, cValue, 0, row, column, 0);
			}
		}
		else if (ch == '\'') {
			startRow = row, maxColumn = column, startColumn = column;
			getch();
			if (isdigit(ch) || isalpha(ch) || ch == '_' || ch == '*' || ch == '/' || ch == '+' || ch == '-' && row == startRow) {
				cValue[cCnt++] = ch;
				cValue[cCnt] = '\0';
				getch();
				if (ch == '\'') {
					getch();
					// printf("%d %s %s\n", outputLine, symbol_name[CHAR], cValue);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(CHAR, cValue, 0, row, column);
				}
				else {
					// printf("%d %s %s\n", outputLine, symbol_name[CHAR], cValue);
					outputLine++;
					error(CHAR_MISS_QUOTE);
					while (ch == ' ')
						getch();
					push_in_symList(CHAR, cValue, 0, row, column);
				}
			}
			else {												// 若左单引号后符号不合法，跳到该符号后一个的右单引号后，若无右单引号，仅跳到符号后
				if (row == startRow)
					getch();
				if (ch == '\'' && row == startRow)
					getch();
				while (ch == ' ')
					getch();
				error(CHAR_CONTENT_ERROR);
				push_in_symList(ERROR, "", 0, row, column);
			}
		}
		else if (ch == '\"') {
			startRow = row, maxColumn = column, startColumn = column;
			getch();
			if (ch == ' ' || ch == '!' || (ch >= '#' && ch <= '~')) {
				while (ch != '\"' && ch >= ' ' && ch <= '~' && startRow == row) {
					cValue[cCnt++] = ch;
					getch();
					maxColumn = column > maxColumn ? column : maxColumn;
				}
				cValue[cCnt] = '\0';
				if (startRow != row) {
					// printf("%d %s %s\n", outputLine, symbol_name[STRING], cValue);
					outputLine++;			// 容错，该行没有右双引号时，强行补一个右双引号，保存之前的字符串
					error(STR_MISSINT_RPARENT);
					while (ch == ' ')
						getch();
					push_in_symList(STRING, cValue, 0, row, column);
				}
				else if (ch == '\"') {
					getch();
					// printf("%d %s %s\n", outputLine, symbol_name[STRING], cValue);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(STRING, cValue, 0, row, column);
				}
				else {						// 字符串内有非法字符，不保存当前字符串，跳读到本行下一个右双引号，若本行没有右双引号则跳过本行
					while (row == startRow && ch != '\"' && ch != EOF) {
						getch();
					}
					if (row == startRow && ch == '\"') {
						getch();
						while (ch == ' ')
							getch();
					}
					error(STR_CONTENT_ERROR);
					push_in_symList(ERROR, "", 0, row, column);
				}
			}
			else if (row == startRow && ch == '\"') {  // 空字符串，不保存空字符串，跳到右引号后
				getch();
				while (ch == ' ')
					getch();
				error(STR_EMPTY);
				push_in_symList(ERROR, "", 0, row, column);
			}
			else {
				error(STR_CONTENT_ERROR);				// 字符串内有非法字符，不保存当前字符串，跳读到本行下一个右双引号，若本行没有右双引号则跳过本行
				while (row == startRow) {
					getch();
					if (ch == '\"') {
						getch();
						while (ch == ' ')
							getch();
						break;
					}
				}
				push_in_symList(ERROR, "", 0, row, column);
			}
		}
		else {
			if (ch == '!') {
				getch();
				while (ch == ' ')
					getch();
				if (ch == '=') {
					getch();
					// printf("%d %s !=\n", outputLine, symbol_name[NEQ]);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(NEQ, "", 0, row, column);
				}
				else {
					// printf("%d %s !=\n", outputLine, symbol_name[NEQ]);
					outputLine++;				// 不等号后不是等号，容错，强行补一个，保存!=
					error(NEQUAL_MISS);
					push_in_symList(NEQ, "", 0, row, column);
				}
			}
			else if (ch == '(') {
				getch();
				// printf("%d %s (\n", outputLine, symbol_name[LPAR]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(LPAR, "", 0, row, column);
			}
			else if (ch == ')') {
				getch();
				// printf("%d %s )\n", outputLine, symbol_name[RPAR]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(RPAR, "", 0, row, column);
			}
			else if (ch == '*') {
				getch();
				// printf("%d %s *\n", outputLine, symbol_name[MULT]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(MULT, "", 0, row, column);
			}
			else if (ch == '+') {
				getch();
				// printf("%d %s +\n", outputLine, symbol_name[PLUS]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(PLUS, "", 0, row, column);
			}
			else if (ch == ',') {
				getch();
				// printf("%d %s ,\n", outputLine, symbol_name[COMMA]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(COMMA, "", 0, row, column);
			}
			else if (ch == '-') {
				getch();
				// printf("%d %s -\n", outputLine, symbol_name[MINUS]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(MINUS, "", 0, row, column);
			}
			else if (ch == '/') {
				getch();
				// printf("%d %s /\n", outputLine, symbol_name[DIV]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(DIV, "", 0, row, column);
			}
			else if (ch == ':') {
				getch();
				// printf("%d %s :\n", outputLine, symbol_name[COLON]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(COLON, "", 0, row, column);
			}
			else if (ch == ';') {
				getch();
				// printf("%d %s ;\n", outputLine, symbol_name[SEMICOLON]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(SEMICOLON, "", 0, row, column);
			}
			else if (ch == '<') {
				getch();
				if (ch == '=') {
					getch();
					// printf("%d %s <=\n", outputLine, symbol_name[LE]);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(LE, "", 0, row, column);
				}
				else {
					// printf("%d %s <\n", outputLine, symbol_name[LT]);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(LT, "", 0, row, column);
				}
			}
			else if (ch == '=') {
				getch();
				if (ch == '=') {
					getch();
					// printf("%d %s ==\n", outputLine, symbol_name[EQ]);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(EQ, "", 0, row, column);
				}
				else {
					// printf("%d %s =\n", outputLine, symbol_name[IS]);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(IS, "", 0, row, column);
				}
			}
			else if (ch == '>') {
				getch();
				if (ch == '=') {
					getch();
					// printf("%d %s >=\n", outputLine, symbol_name[GE]);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(GE, "", 0, row, column);
				}
				else {
					// printf("%d %s >\n", outputLine, symbol_name[GT]);
					outputLine++;
					while (ch == ' ')
						getch();
					push_in_symList(GT, "", 0, row, column);
				}
			}
			else if (ch == '[') {
				getch();
				// printf("%d %s [\n", outputLine, symbol_name[LBRACK]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(LBRACK, "", 0, row, column);
			}
			else if (ch == ']') {
				getch();
				// printf("%d %s ]\n", outputLine, symbol_name[RBRACK]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(RBRACK, "", 0, row, column);
			}
			else if (ch == '{') {
				getch();
				// printf("%d %s {\n", outputLine, symbol_name[LBRACE]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(LBRACE, "", 0, row, column);
			}
			else if (ch == '}') {
				getch();
				// printf("%d %s }\n", outputLine, symbol_name[RBRACE]);
				outputLine++;
				while (ch == ' ')
					getch();
				push_in_symList(RBRACE, "", 0, row, column);
			}
			else {
				error(ILLEGAL_WORD);			// ascii范围内的非法字符
				getch();
				while (ch == ' ')
					getch();
				push_in_symList(ERROR, "", 0, row, column);
			}
		}
	}
}
