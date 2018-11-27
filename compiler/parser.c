#include "stdafx.h"
#include "lexer.h"
#include "parser.h"
#include "error.h"

struct symtable *symTable;

void init();
void enter(char *name, int kind, int type, int value, int number);
void updateParaNumber(char* name, int value);
void updateIdentValue(char* name, int type, int index, int value);
struct node findIdentInSymTable(char* name);
int isInteger();
void constdef();
void condecl();
void vardef();
void vardecl();
void vardecl();
void para();
int paratable();
void factor();
void term();
void expression();
void conditionsentence();
void whilesentence();
void ifsentence();
void funccall();
void assignsentence();
void scanfsentence();
void printfsentence();
void switchsentence();
void returnsentence();
void sentence();
void sentenceslist();
void complexsentence();
void funcdef();
void mainprog();
void complexsentence();
void program();
void valueparatable();
void casesentence();
void casetable();
void defau();

/*
* Summary: initial symbol table
*/
void init() {
	symTable = (struct symtable*)malloc(sizeof(struct symtable));
	symTable->top = 0;
	symTable->subprogramNumber = 0;
	symTable->subprogramTable[0] = 0;
}

/*
* Summary: enter into symbol table
* name: name of identifier
* kind: 1:constant,2:variable,3:function,4:para
* type: 1:void,2:int,3:char,4:int arrays,5:char arrays
* value: value of variable
* number: number of parameters in function
*/
void enter(char *name, int kind, int type, int value, int number) {
	strcpy(symTable->table[symTable->top].name, name);
	symTable->table[symTable->top].kind = kind;
	symTable->table[symTable->top].type = type;
	symTable->table[symTable->top].value = value;
	symTable->table[symTable->top].number = number;
	if (kind == 3 || symTable->subprogramNumber == 0) {
		symTable->subprogramTable[symTable->subprogramNumber] = symTable->top;
		symTable->subprogramNumber++;
	}
	symTable->top++;
}

/*
* Summary: update para number of function
* name: name of function
* value: number of parameters in function
*/
void updateParaNumber(char* name, int value) {
	int i;
	for (i = symList_index - 1; i >= symTable->subprogramTable[symTable->subprogramNumber - 1]; i--) {
		if (strcmp(symTable->table[i].name, name) == 0 && symTable->table[i].kind == 3) {
			symTable->table[i].number = value;
			break;
		}
	}
	if (i < symTable->subprogramTable[symTable->subprogramNumber - 1]) {
		error(FUNC_NO_DEFINED);
	}
}

/*
* Summary: update value of identifier
* name: name of identifier
* type: type of identifier,1:variable,2:variable array
* index: index of array if identifier is array
* value: value to be update
*/
void updateIdentValue(char* name, int type, int index, int value) {
	int i;
	for (i = symList_index - 1; i >= symTable->subprogramTable[symTable->subprogramNumber - 1]; i--) {
		if (strcmp(symTable->table[i].name, name) == 0) {
			symTable->table[i].value = value;
			break;
		}
	}
	if (i < symTable->subprogramTable[symTable->subprogramNumber - 1]) {
		if (symTable->table[0].kind != 3) {         // 存在全局变量
			for (i = symTable->subprogramTable[1]; i >= 0; i--) {
				if (strcmp(symTable->table[i].name, name) == 0) {
					if (type == 2) {
						// 处理数组
					}
					else {
						symTable->table[i].value = value;
						break;
					}
				}
			}
			if (i == -1)
				error(UNDEF_ID);
		}
		else {
			error(UNDEF_ID);
		}
	}
}

/*
* Summary: find ident in symTable and return it
*/
struct node findIdentInSymTable(char* name) {
	int i;
	for (i = symList_index - 1; i >= symTable->subprogramTable[symTable->subprogramNumber - 1]; i--) {
		if (strcmp(symTable->table[i].name, name) == 0)
			return (symTable->table[i]);
	}
	if (symTable->table[0].kind != 3) {         // 存在全局变量
		for (i = symTable->subprogramTable[1]; i >= 0; i--) {
			if (strcmp(symTable->table[i].name, name) == 0)
				return (symTable->table[i]);
		}
		error(UNDEF_ID);
	}
	else
		error(UNDEF_ID);
}

/*
* judge if sym and next sym form integer
*/
int isInteger() {
	int coefficient = 1;
	if (sym == PLUS) {
		getsym();
	}
	else if (sym == MINUS) {
		coefficient = -1;
		getsym();
	}
	if (sym == NUMBER) {
		iValue = coefficient * iValue;
		getsym();
		return 1;
	}
	else
		return 0;
}

/*
* Summary: constant define
*/
void constdef() {
	if (sym == INTSY) {
		getsym();
		while (1) {
			if (sym != IDENT) {
				// error
				// return;
				error(MISSING_IDENT);
			}
			getsym();
			if (sym != IS) {
				// error
				// return;
				error(MISSING_IS);
			}
			getsym();
			if (!isInteger()) {
				// error
				// return;
				error(MISSING_INTEGER);
			}
			printf("This is a constant int define!\n");
			if (sym == SEMICOLON) {
				getsym();
				break;
			}
			else if (sym == COMMA) {
				getsym();
			}
			else {
				// error
				// return;
				error(MISSING_SEMICOLON);
			}
		}
		printf("This is a constant int declear!\n");
	}
	else if (sym == CHARSY) {
		getsym();
		while (1) {
			if (sym != IDENT) {
				// error
				// return;
				error(MISSING_IDENT);
			}
			getsym();
			if (sym != IS) {
				// error
				// return;
				error(MISSING_IS);
			}
			getsym();
			if (sym != CHAR) {
				// error
				// return
				error(MISSING_CHAR);
			}
			printf("This is a constant char define!\n");
			getsym();
			if (sym == SEMICOLON) {
				getsym();
				break;
			}
			else if (sym == COMMA) {
				getsym();
			}
			else {
				// error
				// return;
				error(MISSING_SEMICOLON);
			}
		}
		printf("This is a constant char declear!\n");
	}
	else {
		// error
		// return
		error(WRONG_TYPE);
	}
}

/*
* Summary: constant declare
*/
void condecl() {
	do {
		getsym();
		constdef();
	} while (sym == CONSTSY);
}

/*
* Summary: variable define
*/
void vardef() {
	if (sym == INTSY) {
		getsym();
		while (1) {
			char name[100];
			int kind = 2, type = 2, number = NULL, value = NULL;
			if (sym != IDENT) {
				// error
				// return;
				error(MISSING_IDENT);
			}
			strcpy(name, cValue);
			getsym();
			if (sym == LBRACK) {
				type = 4;
				getsym();
				if (sym != NUMBER) {
					// error
					// return;
					error(MISSING_NUMBER);
				}
				number = iValue;
				getsym();
				if (sym != RBRACK) {
					// error
					// return;
					error(MISSING_RBRACK);
				}
				getsym();
			}
			if (sym == SEMICOLON) {
				printf("This is a variable int define!\n");
				enter(name, kind, type, value, number);
				getsym();
				break;
			}
			else if (sym == COMMA) {
				printf("This is a variable int define!\n");
				enter(name, kind, type, value, number);
				getsym();
			}
			else {
				// error
				// return;
				error(MISSING_SEMICOLON);
			}
		}
		printf("This is a variable int declear!\n");
	}
	else if (sym == CHARSY) {
		getsym();
		while (1) {
			char name[100];
			int kind = 2, type = 3, number = NULL, value = NULL;
			if (sym != IDENT) {
				// error
				// return;
				error(MISSING_IDENT);
			}
			strcpy(name, cValue);
			getsym();
			if (sym == LBRACK) {
				type = 5;
				getsym();
				if (sym != NUMBER) {
					// error
					// return;
					error(MISSING_NUMBER);
				}
				number = iValue;
				getsym();
				if (sym != RBRACK) {
					// error
					// return;
					error(MISSING_RBRACK);
				}
				getsym();
			}
			if (sym == SEMICOLON) {
				printf("This is a variable char define!\n");
				enter(name, kind, type, value, number);
				getsym();
				break;
			}
			else if (sym == COMMA) {
				printf("This is a variable char define!\n");
				enter(name, kind, type, value, number);
				getsym();
			}
			else {
				// error
				// return;
				error(MISSING_SEMICOLON);
			}
		}
		printf("This is a variable char declear!\n");
	}
	else {
		// error
		// return
		error(WRONG_TYPE);
	}
}

/*
* Summary: variable declare
*/
void vardecl() {
	vardef();
	while (1) {
		if (sym != INTSY && sym != CHARSY)
			break;
		getsym();
		if (sym != IDENT) {
			// error
			// return;
			error(MISSING_IDENT);
		}
		getsym();
		if (sym != COMMA && sym != SEMICOLON && sym != LBRACK) {
			symList_index -= 3;
			getsym();
			break;
		}
		symList_index -= 3;
		getsym();
		vardef();
	}
}

/*
* Summary: parameter
*/
void para() {
	char name[100];
	int kind = 4, type, value = NULL, number = NULL;
	if (sym == INTSY) {
		type = 2;
		getsym();
		if (sym != IDENT) {
			// error
			// return;
			error(MISSING_IDENT);
		}
		strcpy(name, cValue);
		printf("This is a int parameter!\n");
		getsym();
		if (sym == COMMA) {
			getsym();
		}
		else if (sym != RPAR) {
			// error
			// return;
			error(MISSING_RPARENT);
		}
		enter(name, kind, type, value, number);
	}
	else if (sym == CHARSY) {
		type = 3;
		getsym();
		if (sym != IDENT) {
			// error
			// return;
			error(MISSING_IDENT);
		}
		strcpy(name, cValue);
		getsym();
		printf("This is a char parameter!\n");
		if (sym == COMMA) {
			getsym();
		}
		else if (sym != RPAR) {
			// error
			// return;
			error(MISSING_RPARENT);
		}
		enter(name, kind, type, value, number);
	}
	else {
		// error
		// return
		error(WRONG_TYPE);
	}
}

/*
* Summary: parameter table
*/
int paratable() {
	int sum = 0;
	do {
		para();
		sum++;
	} while (sym == INTSY || sym == CHARSY);
	printf("This is a parameter list!\n");
	return sum;
}

/*
* Summary: expression
*/
void expression() {
	// int coefficient = 1;
	if (sym == PLUS) {
		getsym();
	}
	else if (sym == MINUS) {
		// coefficient = -1;
		getsym();
	}
	term();
	while (sym == PLUS || sym == MINUS) {
		getsym();
		term();
	}
	printf("This is an expression!\n");
}

/*
* Summary: factor
*/
void factor() {
	if (sym == IDENT) {
		getsym();
		if (sym == LBRACK) {
			getsym();
			expression();
			if (sym != RBRACK) {
				// error
				// return;
				error(MISSING_RBRACK);
			}
			getsym();
		}
		else if (sym == LPAR) {
			symList_index -= 2;
			getsym();
			funccall();
		}
	}
	else if (sym == LPAR) {
		getsym();
		expression();
		if (sym != RPAR) {
			// error
			// return;
			error(MISSING_RPARENT);
		}
		getsym();
	}
	else if (sym == CHAR) {
		getsym();
	}
	else if (isInteger()) {

	}
	else {
		// error
		// return;
		error(FACTOR_CONTENT_WRONG);
	}
	printf("This is a factor!\n");
}

/*
* Summary: term
*/
void term() {
	factor();
	while (sym == MULT || sym == DIV) {
		getsym();
		factor();
	}
	printf("This is a term!\n");
}

/*
* Summary: condition sentence
*/
void conditionsentence() {
	expression();
	if (sym == LT || sym == LE || sym == GE || sym == GT || sym == EQ || sym == NEQ) {
		getsym();
		expression();
	}
	printf("This is a condition sentence!\n");
}

/*
* Summary: while sentence
*/
void whilesentence() {
	getsym();
	if (sym != LPAR) {
		// error
		// return;
		error(MISSING_LPARENT);
	}
	getsym();
	conditionsentence();
	if (sym != RPAR) {
		// error
		// return;
		error(MISSING_RPARENT);
	}
	getsym();
	sentence();
	printf("This is a while sentence!\n");
}

/*
* Summary: if sentence
*/
void ifsentence() {
	getsym();
	if (sym != LPAR) {
		// error
		// return;
		error(MISSING_LPARENT);
	}
	getsym();
	conditionsentence();
	if (sym != RPAR) {
		// error
		// return;
		error(MISSING_RPARENT);
	}
	getsym();
	sentence();
	printf("This is a if sentence!\n");
}

/*
* Summary: value parameter table
*/
void valueparatable() {
	expression();
	while (sym == COMMA) {
		getsym();
		expression();
	}
	printf("This is a value parameter table!\n");
}

/*
* Summary: function call
*/
void funccall() {
	if (sym != IDENT) {
		// error
		// return;
		error(MISSING_IDENT);
	}
	getsym();
	if (sym != LPAR) {
		// error
		// return;
		error(MISSING_LPARENT);
	}
	getsym();
	if (sym == RPAR) {
		printf("This is an empty value parameter table!\n");
	}
	else {
		valueparatable();
	}
	if (sym != RPAR) {
		// error
		// return;
		error(MISSING_RPARENT);
	}
	printf("This is a function call!\n");
	getsym();
}

/*
* Summary: assign sentence
*/
void assignsentence() {
	if (sym != IDENT) {
		// error
		// return;
		error(MISSING_IDENT);
	}
	getsym();
	if (sym == LBRACK) {
		getsym();
		expression();
		if (sym != RBRACK) {
			// error
			// return;
			error(MISSING_RBRACK);
		}
		getsym();
	}
	if (sym != IS) {
		// error
		// return;
		error(MISSING_IS);
	}
	getsym();
	expression();
	printf("This is an assign sentence!\n");
}
/*
* Summary: scanf sentence
*/
void scanfsentence() {
	getsym();
	if (sym != LPAR) {
		// error
		// return;
		error(MISSING_LPARENT);
	}
	getsym();
	if (sym != IDENT) {
		// error
		// return;
		error(MISSING_IDENT);
	}
	getsym();
	while (sym == COMMA) {
		getsym();
		if (sym != IDENT) {
			// error
			// return;
			error(MISSING_IDENT);
		}
		getsym();
	}
	if (sym != RPAR) {
		// error
		// return;
		error(MISSING_RPARENT);
	}
	printf("This is a scanf sentence!\n");
	getsym();
}

/*
* Summary: printf sentence
*/
void printfsentence() {
	getsym();
	if (sym != LPAR) {
		// error
		// return;
		error(MISSING_LPARENT);
	}
	getsym();
	if (sym == STRING) {
		getsym();
		if (sym == COMMA) {
			getsym();
			expression();
		}
	}
	else {
		expression();
	}
	if (sym != RPAR) {
		// error
		// return;
		error(MISSING_RPARENT);
	}
	getsym();
	printf("This is a scanf sentence!\n");
}

/*
Summary: case substatement*/
void casesentence() {
	if (sym != CASESY) {
		// error
		// return;
		error(MISSING_CASE_KEYWORD);
	}
	getsym();
	if (sym == CHAR) {
		getsym();
	}
	else if (isInteger()) {

	}
	else {
		// error
		// return;
		error(CASE_CONTENT_WRONG);
	}
	if (sym != COLON) {
		// error
		// return;
		error(MISSING_COLON);
	}
	getsym();
	sentence();
	printf("This is a case sentence!\n");
}

/*
* Summary: case table
*/
void casetable() {
	if (sym != CASESY) {
		// error
		// return;
		error(MISSING_CASE_KEYWORD);
	}
	do {
		casesentence();
	} while (sym == CASESY);
	printf("This is a case table!\n");
}

/*
* Summary: default
*/
void defau() {
	getsym();
	if (sym == SEMICOLON) {
		printf("This is an empty default sentence!\n");
		getsym();
	}
	else if (sym == COLON) {
		getsym();
		sentence();
		printf("This is a default sentence!\n");
	}
	else {
		// error
		// return;
		error(MISSING_SEMICOLON);
	}
}

/*
* Summary: switch sentence
*/
void switchsentence() {
	getsym();
	if (sym != LPAR) {
		// error
		// return;
		error(MISSING_LPARENT);
	}
	getsym();
	expression();
	if (sym != RPAR) {
		// error
		// return;
		error(MISSING_RPARENT);
	}
	getsym();
	if (sym != LBRACE) {
		// error
		// return;
		error(MISSING_LBRACE);
	}
	getsym();
	casetable();
	if (sym == DEFAULTSY) {
		defau();
	}
	if (sym != RBRACE) {
		// error
		// return;
		error(MISSING_RBRACE);
	}
	printf("This is a switch sentence!\n");
	getsym();
}

/*
* Summary: return sentence
*/
void returnsentence() {
	getsym();
	if (sym == LPAR) {
		getsym();
		expression();
		if (sym != RPAR) {
			// error
			// return;
			error(MISSING_RPARENT);
		}
		getsym();
	}
	printf("This is a return sentence!\n");
}

/*
* Summary: sentence
*/
void sentence() {
	if (sym == IFSY) {
		ifsentence();
	}
	else if (sym == WHILESY) {
		whilesentence();
	}
	else if (sym == LBRACE) {
		getsym();
		sentenceslist();
		if (sym != RBRACE) {
			// error
			// return;
			error(MISSING_RBRACE);
		}
		getsym();
	}
	else if (sym == IDENT) {
		getsym();
		if (sym == LPAR) {
			symList_index -= 2;
			getsym();
			funccall();
			if (sym != SEMICOLON) {
				// error
				// return;
				error(MISSING_SEMICOLON);
			}
			getsym();
		}
		else if (sym == IS || sym == LBRACK) {
			symList_index -= 2;
			getsym();
			assignsentence();
			if (sym != SEMICOLON) {
				// error
				// return;
				error(MISSING_SEMICOLON);
			}
			getsym();
		}
		else {
			// error
			// return;
			error(SENTENCE_CONTENT_WRONG);
		}
	}
	else if (sym == SCANFSY) {
		scanfsentence();
		if (sym != SEMICOLON) {
			// error
			// return;
			error(MISSING_SEMICOLON);
		}
		getsym();
	}
	else if (sym == PRINTFSY) {
		printfsentence();
		if (sym != SEMICOLON) {
			// error
			// return;
			error(MISSING_SEMICOLON);
		}
		getsym();
	}
	else if (sym == SEMICOLON) {
		printf("This is an empty sentence!\n");
		getsym();
	}
	else if (sym == SWITCHSY) {
		switchsentence();
	}
	else if (sym == RETURNSY) {
		returnsentence();
		if (sym != SEMICOLON) {
			// error
			// return;
			error(MISSING_SEMICOLON);
		}
		getsym();
	}
	else {
		// error
		// return;
		error(SENTENCE_CONTENT_WRONG);
	}
}

/*
* Summary: sentences list
*/
void sentenceslist() {
	if (sym != IFSY && sym != WHILESY && sym != LBRACE && sym != IDENT && sym != SCANFSY && sym != PRINTFSY && sym != SEMICOLON && sym != SWITCHSY && sym != RETURNSY) {
		printf("This is an empty sentences list!\n");
		return;
	}
	while (sym == IFSY || sym == WHILESY || sym == LBRACE || sym == IDENT || sym == SCANFSY || sym == PRINTFSY || sym == SEMICOLON || sym == SWITCHSY || sym == RETURNSY) {
		sentence();
	}
	printf("This is a sentences list!\n");
}

/*
* Summary: complex sentence
*/
void complexsentence() {
	if (sym == CONSTSY)
		condecl();
	if (sym == INTSY || sym == CHARSY) {
		vardecl();
	}
	sentenceslist();
	printf("This is a complex sentence!\n");
}

/*
* Summary: function define
*/
void funcdef() {
	while (1) {
		char name[100];
		int kind = 3, type = 0, value = NULL, number = NULL;
		if (sym == VOIDSY) {
			type = 1;
		}
		else if (sym == INTSY) {
			type = 2;
		}
		else {
			type = 3;
		}
		getsym();
		if (sym != IDENT) {
			// error
			// return;
			error(MISSING_IDENT);
		}
		strcpy(name, cValue);
		getsym();
		if (sym != LPAR) {
			// error
			// return;
			error(MISSING_LPARENT);
		}
		enter(name, kind, type, value, 0);
		getsym();
		if (sym != RPAR) {
			int sum = paratable();
			updateParaNumber(name, sum);
		}
		else {
			printf("This is a empty parameter list!\n");
		}
		if (sym != RPAR) {
			// error
			// return;
			error(MISSING_RPARENT);
		}
		getsym();
		if (sym != LBRACE) {
			// error
			// return;
			error(MISSING_LBRACE);
		}
		getsym();
		complexsentence();
		if (sym != RBRACE) {
			// error
			// return;
			error(MISSING_RBRACE);
		}
		if (type == 1)
			printf("This is a Non-return function!\n");
		else if (type == 3)
			printf("This is a char-return function!\n");
		else if (type == 2)
			printf("This is a int-return function!\n");
		getsym();

		if (sym == INTSY || sym == CHARSY || sym == VOIDSY) {
			getsym();
			if (sym == MAINSY && symList[symList_index - 2]->sym == VOIDSY) {
				symList_index -= 2;
				getsym();
				break;
			}
			else {
				symList_index -= 2;
				getsym();
			}
		}
		else if (sym == NOTHING) {
			break;
		}
	}
}

/*
* Summary: main program
*/
void mainprog() {
	getsym();
	if (sym != MAINSY) {
		// error
		// return;
		error(MISSING_MAIN);
	}
	enter("main", 3, 1, 0, 0);
	getsym();
	if (sym != LPAR) {
		// error
		// return;
		error(MISSING_LPARENT);
	}
	getsym();
	if (sym != RPAR) {
		// error
		// return;
		error(MISSING_RPARENT);
	}
	getsym();
	if (sym != LBRACE) {
		// error
		// return;
		error(MISSING_LBRACE);
	}
	getsym();
	complexsentence();
	if (sym != RBRACE) {
		// error
		// return;
		error(MISSING_RBRACE);
	}
	printf("This is main function!\n");
	getsym();
}

/*
* Summary: program
*/
void program() {
	if (sym == CONSTSY)
		condecl();
	if (sym == INTSY || sym == CHARSY) {
		getsym();
		if (sym != IDENT) {
			// error
			// return;
			error(MISSING_IDENT);
		}
		getsym();
		if (sym == LPAR) {
			symList_index -= 3;
			getsym();
		}
		else if (sym == COMMA || sym == SEMICOLON || sym == LBRACK) {
			symList_index -= 3;
			getsym();
			vardecl();
		}
		else {
			// error
			// return;
			error(MISSING_SEMICOLON);
		}
	}
	if (sym == INTSY || sym == CHARSY || sym == VOIDSY) {
		getsym();
		if (sym == MAINSY && symList[symList_index - 2]->sym == VOIDSY) {
			symList_index -= 2;
			getsym();
		}
		else {
			symList_index -= 2;
			getsym();
			funcdef();
		}
	}
	if (sym == VOIDSY) {
		mainprog();
		printf("This is a program!\n");
	}
	else {
		// error
		// return;
		error(PROGRAM_ERROR);
	}
}