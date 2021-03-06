#include "stdafx.h"
#include "lexer.h"
#include "parser.h"
#include "error.h"
#include "IR.h"
#include "gencode.h"

struct symtable *symTable;

int addrIndex = 0;						// 内存中下一变量、常量或参数的addr
int tempResIndex = 0;					// 生成四元式的中间变量名称下标，如$temp_0
char tempRes[MAX_TEMP_NUMBER + 7];		// 生成四元式的中间变量名
int labelIndex = 0;						// 生成四元式的label名称下标，如label_0
char label[MAX_LABEL_NUMBER + 7];		// 生成四元式的label名
int stringIndex = 1;					// 生成四元式的STRING名称下标，如$string_0
char tempString[MAX_LABEL_NUMBER + 7];	// 生成四元式的STRING名
int retflag;							// 判断是否有返回值标志

void init();
void nameATempVarByIndex(int number);
void nameATempVar();
void nameALabel();
void nameAString();
void enter(char *name, int kind, int type, int value, int number, int addr, char* STRING, char* label);
void updateParaNumber(char* name, int value);
struct node findIdentInSymTable(char* name);
struct node findIdentInLastSymTable(char* name);
struct node findFunction(char* name);
struct node findPara(char* name, int offset);
struct node findFunctionByLayer(int cur_layer);
struct node findLabel(char* name);
void updateFuncVarNum();
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
void conditionsentence(char* elselabel);
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
void mainprog(char *mainlabel);
void complexsentence();
void program();
void valueparatable(char* name);
void casesentence(char* temp1, char *endlabel);
void casetable(char* switchVar, char *endlabel);
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
* Summary: update all function's parameters,variables and constants number, sum up and save
*/
void updateFuncVarNum() {
	int j, sum;
	for (j = 0; j < symTable->subprogramNumber; j++) {
		if (symTable->table[symTable->subprogramTable[j]].kind == 3) {
			sum = 0;
			if (j == symTable->subprogramNumber - 1) {
				if (symTable->table[symTable->top - 1].number == 0)
					symTable->table[symTable->subprogramTable[j]].sum = symTable->table[symTable->top - 1].addr + 4;
				else
					symTable->table[symTable->subprogramTable[j]].sum = symTable->table[symTable->top - 1].addr + symTable->table[symTable->top - 1].number * 4;
			}
			else {
				if (symTable->table[symTable->subprogramTable[j + 1] - 1].number == 0)
					symTable->table[symTable->subprogramTable[j]].sum = symTable->table[symTable->subprogramTable[j + 1] - 1].addr + 4;
				else
					symTable->table[symTable->subprogramTable[j]].sum = symTable->table[symTable->subprogramTable[j + 1] - 1].addr + symTable->table[symTable->subprogramTable[j + 1] - 1].number * 4;
			}
		}
	}
}

/*
* Summary: set tempRes by index, such as "$temp_0"
*/
void nameATempVarByIndex(int number) {
	strcpy(tempRes, "$temp_");
	char tempIndex[MAX_TEMP_NUMBER];
	_itoa(number, tempIndex, 10);
	strcat(tempRes, tempIndex);
}

/*
* Summary: set tempRes by tempResIndex, such as "$temp_0"
*/
void nameATempVar() {
	strcpy(tempRes, "$temp_");
	char tempIndex[MAX_TEMP_NUMBER];
	_itoa(tempResIndex, tempIndex, 10);
	strcat(tempRes, tempIndex);
	tempResIndex++;
}

/*
* Summary: set label by tempLabelIndex, such as "label_0"
*/
void nameALabel() {
	strcpy(label, "label_");
	char tempIndex[MAX_TEMP_NUMBER];
	_itoa(labelIndex, tempIndex, 10);
	strcat(label, tempIndex);
	labelIndex++;
}

/*
* Summary: set string name by stringIndex, such as "$string_0"
*/
void nameAString() {
	strcpy(tempString, "$string_");
	char temp[MAX_TEMP_NUMBER];
	_itoa(stringIndex, temp, 10);
	strcat(tempString, temp);
	stringIndex++;
}

/*
* Summary: enter into symbol table
* name: name of identifier
* kind: 1:constant,2:variable,3:function,4:para,5:tempVar,6:STRING
* type: 1:void,2:int,3:char,4:int arrays,5:char arrays
* value: value of variable
* number: number of parameters in function
* addr: offsite by its function
* STRING: value of STRING in printf
* label: label of function
*/
void enter(char *name, int kind, int type, int value, int number, int addr, char* STRING, char* label) {
	strcpy(symTable->table[symTable->top].name, name);
	symTable->table[symTable->top].kind = kind;
	symTable->table[symTable->top].type = type;
	symTable->table[symTable->top].value = value;
	symTable->table[symTable->top].number = number;
	symTable->table[symTable->top].addr = addr;
	strcpy(symTable->table[symTable->top].STRING, STRING);
	strcpy(symTable->table[symTable->top].label, label);
	if (kind == 3 || symTable->subprogramNumber == 0) {
		symTable->subprogramTable[symTable->subprogramNumber] = symTable->top;
		symTable->subprogramNumber++;
	}
	symTable->table[symTable->top].level = symTable->subprogramNumber - 1;
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
* Summary: find identidier in current layer of symTable or global area and return its whole struct
*/
struct node findIdentInSymTable(char* name) {
	int i;
	if (layer[layerTop - 1] < symTable->subprogramNumber - 1) {
		for (i = symTable->subprogramTable[layer[layerTop - 1] + 1] - 1; i >= symTable->subprogramTable[layer[layerTop - 1]]; i--) {
			if (strcmp(symTable->table[i].name, name) == 0)
				return (symTable->table[i]);
		}
	}
	else {
		for (i = symTable->top - 1; i >= symTable->subprogramTable[layer[layerTop - 1]]; i--) {
			if (strcmp(symTable->table[i].name, name) == 0)
				return (symTable->table[i]);
		}
	}
	if (symTable->table[0].kind != 3) {         // 存在全局变量
		for (i = symTable->subprogramTable[1] - 1; i >= 0; i--) {
			if (strcmp(symTable->table[i].name, name) == 0)
				return (symTable->table[i]);
		}
		struct node error_node;
		error_node.addr = 0;
		error_node.kind = 5;
		error_node.level = 0;
		strcpy(error_node.name, "$error");
		error_node.number = 0;
		error_node.type = 2;
		error_node.value = 0;
		return error_node;
	}
	else {
		struct node error_node;
		error_node.addr = 0;
		error_node.kind = 5;
		error_node.level = 0;
		strcpy(error_node.name, "$error");
		error_node.number = 0;
		error_node.type = 2;
		error_node.value = 0;
		return error_node;
	}
}

/*
* Summary: find identidier in last layer of symTable or global area, and return its whole struct
*/
struct node findIdentInLastSymTable(char* name) {
	int i;
	for (i = symTable->top - 1; i >= symTable->subprogramTable[symTable->subprogramNumber - 1]; i--) {
		if (strcmp(symTable->table[i].name, name) == 0)
			return (symTable->table[i]);
	}
	if (symTable->table[0].kind != 3) {         // 存在全局变量
		for (i = symTable->subprogramTable[1] - 1; i >= 0; i--) {
			if (strcmp(symTable->table[i].name, name) == 0)
				return (symTable->table[i]);
		}
		struct node error_node;
		error_node.addr = 0;
		error_node.kind = 5;
		error_node.level = 0;
		strcpy(error_node.name, "$error");
		error_node.number = 0;
		error_node.type = 2;
		error_node.value = 0;
		return error_node;
	}
	else {
		struct node error_node;
		error_node.addr = 0;
		error_node.kind = 5;
		error_node.level = 0;
		strcpy(error_node.name, "$error");
		error_node.number = 0;
		error_node.type = 2;
		error_node.value = 0;
		return error_node;
	}
}

/*
* Summary: find a label and return the whole node
*/
struct node findLabel(char* name) {
	int i;
	for (i = 0; i < symTable->subprogramNumber; i++) {
		if (symTable->table[symTable->subprogramTable[i]].kind != 3)
			continue;
		if (strcmp(symTable->table[symTable->subprogramTable[i]].label, name) == 0) {
			return symTable->table[symTable->subprogramTable[i]];
		}
	}
}

/*
* Summary: find a function and return the whole node
*/
struct node findFunction(char* name) {
	int i;
	for (i = 0; i < symTable->subprogramNumber; i++) {
		if (symTable->table[symTable->subprogramTable[i]].kind != 3)
			continue;
		if (strcmp(symTable->table[symTable->subprogramTable[i]].name, name) == 0) {
			return symTable->table[symTable->subprogramTable[i]];
		}
	}
}

/*
* Summary: find a para by function name and offset, and return the whole node
*/
struct node findPara(char* name, int offset) {
	int i;
	for (i = 0; i < symTable->subprogramNumber; i++) {
		if (symTable->table[symTable->subprogramTable[i]].kind != 3)
			continue;
		if (strcmp(symTable->table[symTable->subprogramTable[i]].name, name) == 0) {
			return symTable->table[symTable->subprogramTable[i] + offset];
		}
	}
}

/*
* Summary: find a function by layer and return the whole node
*/
struct node findFunctionByLayer(int cur_layer) {
	int i;
	for (i = 0; i < symTable->subprogramNumber; i++) {
		if (symTable->table[symTable->subprogramTable[i]].kind != 3)
			continue;
		if (symTable->table[symTable->subprogramTable[i]].level == cur_layer) {
			return symTable->table[symTable->subprogramTable[i]];
		}
	}
}

/*
* judge if sym and next sym form integer. if form, set iValue with the whole integer and return 1
* if return 1, need to do getsym() after use the iValue
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
			char name[100];
			int kind = 1, type = 2, value = 0;
			if (sym != IDENT)
				error(MISSING_IDENT);
			strcpy(name, cValue);
			getsym();
			if (sym != IS)
				error(MISSING_IS);
			getsym();
			if (!isInteger())
				error(MISSING_INTEGER);
			else {
				value = iValue;
				getsym();
			}
			if (sym == SEMICOLON) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, value, 0, addrIndex, "", "");
				addrIndex += 4;
				char op1[100];
				_itoa(value, op1, 10);
				insertIntoIRlist(conop, "int", op1, name);
				getsym();
				break;
			}
			else if (sym == COMMA) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, value, 0, addrIndex, "", "");
				addrIndex += 4;
				char op1[100];
				_itoa(value, op1, 10);
				insertIntoIRlist(conop, "int", op1, name);
				getsym();
			}
			else
				error(MISSING_SEMICOLON);
		}
	}
	else if (sym == CHARSY) {
		getsym();
		while (1) {
			char name[100];
			int kind = 1, type = 3, value = 0;
			if (sym != IDENT)
				error(MISSING_IDENT);
			strcpy(name, cValue);
			getsym();
			if (sym != IS)
				error(MISSING_IS);
			getsym();
			if (sym != CHAR)
				error(MISSING_CHAR);
			value = (int)(cValue[0]);
			getsym();
			if (sym == SEMICOLON) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, value, 0, addrIndex, "", "");
				addrIndex += 4;
				char op1[100];
				_itoa(value, op1, 10);
				insertIntoIRlist(conop, "char", op1, name);
				getsym();
				break;
			}
			else if (sym == COMMA) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, value, 0, addrIndex, "", "");
				addrIndex += 4;
				char op1[100];
				_itoa(value, op1, 10);
				insertIntoIRlist(conop, "char", op1, name);
				getsym();
			}
			else
				error(MISSING_SEMICOLON);
		}
	}
	else
		error(WRONG_TYPE);
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
			int kind = 2, type = 2, number = 0;
			if (sym != IDENT)
				error(MISSING_IDENT);
			strcpy(name, cValue);
			getsym();
			if (sym == LBRACK) {
				type = 4;
				getsym();
				if (sym != NUMBER)
					error(MISSING_NUMBER);
				number = iValue;
				getsym();
				if (sym != RBRACK)
					error(MISSING_RBRACK);
				getsym();
			}
			if (sym == SEMICOLON) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, 0, number, addrIndex, "", "");
				if (number == 0)
					addrIndex += 4;
				else
					addrIndex += 4 * number;
				char temp[100];
				_itoa(number, temp, 10);
				insertIntoIRlist(varop, "int", temp, name);
				getsym();
				break;
			}
			else if (sym == COMMA) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, 0, number, addrIndex, "", "");
				if (number == 0)
					addrIndex += 4;
				else
					addrIndex += 4 * number;
				char temp[100];
				_itoa(number, temp, 10);
				insertIntoIRlist(varop, "int", temp, name);
				getsym();
			}
			else
				error(MISSING_SEMICOLON);
		}
	}
	else if (sym == CHARSY) {
		getsym();
		while (1) {
			char name[100];
			int kind = 2, type = 3, number = 0;
			if (sym != IDENT)
				error(MISSING_IDENT);
			strcpy(name, cValue);
			getsym();
			if (sym == LBRACK) {
				type = 5;
				getsym();
				if (sym != NUMBER)
					error(MISSING_NUMBER);
				number = iValue;
				getsym();
				if (sym != RBRACK)
					error(MISSING_RBRACK);
				getsym();
			}
			if (sym == SEMICOLON) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, 0, number, addrIndex, "", "");
				if (number == 0)
					addrIndex += 4;
				else
					addrIndex += 4 * number;
				char temp[100];
				_itoa(number, temp, 10);
				insertIntoIRlist(varop, "char", temp, name);
				getsym();
				break;
			}
			else if (sym == COMMA) {
				struct node curNode = findIdentInLastSymTable(name);
				if (strcmp(curNode.name, "$error") != 0 && curNode.level == symTable->subprogramNumber - 1)
					error(MULTI_DEF);
				enter(name, kind, type, 0, number, addrIndex, "", "");
				if (number == 0)
					addrIndex += 4;
				else
					addrIndex += 4 * number;
				char temp[100];
				_itoa(number, temp, 10);
				insertIntoIRlist(varop, "char", temp, name);
				getsym();
			}
			else
				error(MISSING_SEMICOLON);
		}
	}
	else
		error(WRONG_TYPE);
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
		if (sym != IDENT)
			error(MISSING_IDENT);
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
	int kind = 4, type = 0;
	if (sym == INTSY) {
		type = 2;
		getsym();
		if (sym != IDENT)
			error(MISSING_IDENT);
		strcpy(name, cValue);
		getsym();
		if (sym == COMMA) {
			getsym();
		}
		else if (sym != RPAR)
			error(MISSING_RPARENT);
		enter(name, kind, type, 0, 0, addrIndex, "", "");
		addrIndex += 4;
	}
	else if (sym == CHARSY) {
		type = 3;
		getsym();
		if (sym != IDENT)
			error(MISSING_IDENT);
		strcpy(name, cValue);
		getsym();
		if (sym == COMMA) {
			getsym();
		}
		else if (sym != RPAR)
			error(MISSING_RPARENT);
		enter(name, kind, type, 0, 0, addrIndex, "", "");
		addrIndex += 4;
	}
	else
		error(WRONG_TYPE);
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
	return sum;
}

/*
* Summary: expression
*/
void expression() {
	int coefficient = 1, type = 0;
	if (sym == PLUS) {
		getsym();
		type = 2;
	}
	else if (sym == MINUS) {
		coefficient = -1;
		getsym();
		type = 2;
	}
	term();
	if (coefficient == -1) {
		char temp1[100], temp2[100], temp3[100], temp4[100];
		nameATempVarByIndex(tempResIndex - 1);
		strcpy(temp2, tempRes);
		nameATempVar();
		strcpy(temp4, tempRes);
		_itoa(0, temp1, 10);
		insertIntoIRlist(getiop, temp1, "", temp4);
		enter(temp4, 5, 2, 0, 0, addrIndex, "", "");
		addrIndex += 4;
		nameATempVar();
		strcpy(temp3, tempRes);
		insertIntoIRlist(subop, temp4, temp2, temp3);
		enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
		addrIndex += 4;
	}
	else if (type == 2) {
		char temp1[100], temp2[100], temp3[100], temp4[100];
		nameATempVarByIndex(tempResIndex - 1);
		strcpy(temp2, tempRes);
		nameATempVar();
		strcpy(temp4, tempRes);
		_itoa(0, temp1, 10);
		insertIntoIRlist(getiop, temp1, "", temp4);
		enter(temp4, 5, 2, 0, 0, addrIndex, "", "");
		addrIndex += 4;
		nameATempVar();
		strcpy(temp3, tempRes);
		insertIntoIRlist(addop, temp4, temp2, temp3);
		enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
		addrIndex += 4;
	}
	while (sym == PLUS || sym == MINUS) {
		int lastIndex = tempResIndex - 1;
		if (sym == PLUS) {
			getsym();
			term();
			nameATempVarByIndex(lastIndex);
			char temp1[100];
			strcpy(temp1, tempRes);
			nameATempVarByIndex(tempResIndex - 1);
			char temp2[100];
			strcpy(temp2, tempRes);
			nameATempVar();
			char temp3[100];
			strcpy(temp3, tempRes);
			insertIntoIRlist(addop, temp1, temp2, temp3);
			enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
			addrIndex += 4;
		}
		else {
			getsym();
			term();
			nameATempVarByIndex(lastIndex);
			char temp1[100];
			strcpy(temp1, tempRes);
			nameATempVarByIndex(tempResIndex - 1);
			char temp2[100];
			strcpy(temp2, tempRes);
			nameATempVar();
			char temp3[100];
			strcpy(temp3, tempRes);
			insertIntoIRlist(subop, temp1, temp2, temp3);
			enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
			addrIndex += 4;
		}
	}
}

/*
* Summary: factor
*/
void factor() {
	char name[100];
	if (sym == IDENT) {
		strcpy(name, cValue);
		getsym();
		if (sym == LBRACK) {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			char temp1[100];
			strcpy(temp1, tempRes);
			nameATempVar();
			char temp2[100];
			strcpy(temp2, tempRes);
			insertIntoIRlist(getaop, name, temp1, temp2);
			struct node curNode = findIdentInLastSymTable(name);
			if (strcmp(curNode.name, "$error") == 0)
				error(UNDEF_ID);
			enter(temp2, 5, curNode.type - 2, 0, 0, addrIndex, "", "");
			addrIndex += 4;
			if (sym != RBRACK)
				error(MISSING_RBRACK);
			getsym();
		}
		else if (sym == LPAR) {
			struct node curNode = findFunction(name);
			if (curNode.type == 1)
				error(FUNC_NO_RET);
			symList_index -= 2;
			getsym();
			funccall();
			char temp3[100];
			nameATempVar();
			strcpy(temp3, tempRes);
			insertIntoIRlist(getrop, temp3, "", name);
			curNode = findFunction(name);
			enter(temp3, 5, curNode.type, 0, 0, addrIndex, "", "");
			addrIndex += 4;
		}
		else {
			nameATempVar();
			char temp1[100];
			strcpy(temp1, tempRes);
			insertIntoIRlist(getop, name, "", temp1);
			struct node curNode = findIdentInLastSymTable(name);
			if (strcmp(curNode.name, "$error") == 0)
				error(UNDEF_ID);
			enter(temp1, 5, curNode.type, curNode.value, 0, addrIndex, "", "");
			addrIndex += 4;
		}
	}
	else if (sym == LPAR) {
		getsym();
		expression();
		if (sym != RPAR)
			error(MISSING_RPARENT);
		getsym();
	}
	else if (sym == CHAR) {
		char temp1[100];
		_itoa((int)cValue[0], temp1, 10);
		nameATempVar();
		char temp2[100];
		strcpy(temp2, tempRes);
		insertIntoIRlist(getiop, temp1, "", temp2);
		enter(temp2, 5, 3, 0, 0, addrIndex, "", "");
		addrIndex += 4;
		getsym();
	}
	else if (isInteger()) {
		char temp1[100];
		_itoa(iValue, temp1, 10);
		nameATempVar();
		char temp2[100];
		strcpy(temp2, tempRes);
		insertIntoIRlist(getiop, temp1, "", temp2);
		enter(temp2, 5, 2, iValue, 0, addrIndex, "", "");
		addrIndex += 4;
		getsym();
	}
	else
		error(FACTOR_CONTENT_WRONG);
}

/*
* Summary: term
*/
void term() {
	factor();
	while (sym == MULT || sym == DIV) {
		int lastIndex = tempResIndex - 1;
		if (sym == MULT) {
			getsym();
			factor();
			nameATempVarByIndex(lastIndex);
			char temp1[100];
			strcpy(temp1, tempRes);
			nameATempVarByIndex(tempResIndex - 1);
			char temp2[100];
			strcpy(temp2, tempRes);
			nameATempVar();
			char temp3[100];
			strcpy(temp3, tempRes);
			insertIntoIRlist(multop, temp1, temp2, temp3);
			enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
			addrIndex += 4;
		}else{
			getsym();
			factor();
			nameATempVarByIndex(lastIndex);
			char temp1[100];
			strcpy(temp1, tempRes);
			nameATempVarByIndex(tempResIndex - 1);
			char temp2[100];
			strcpy(temp2, tempRes);
			nameATempVar();
			char temp3[100];
			strcpy(temp3, tempRes);
			insertIntoIRlist(divop, temp1, temp2, temp3);
			enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
			addrIndex += 4;
		}
	}
}

/*
* Summary: condition sentence
*/
void conditionsentence(char *elselabel) {
	expression();
	char temp1[100];
	nameATempVarByIndex(tempResIndex - 1);
	strcpy(temp1, tempRes);
	struct node curNode = findIdentInLastSymTable(temp1);
	char type1 = curNode.type;
	if (type1 != 2)
		error(CONDITION_TYPE_ERROR);
	if (sym == LT || sym == LE || sym == GE || sym == GT || sym == EQ || sym == NEQ) {
		char temp2[100];
		if (sym == LT) {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			strcpy(temp2, tempRes);
			insertIntoIRlist(bgezop, temp1, temp2, elselabel);
		}
		else if (sym == LE) {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			strcpy(temp2, tempRes);
			insertIntoIRlist(bgtzop, temp1, temp2, elselabel);
		}
		else if (sym == GE) {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			strcpy(temp2, tempRes);
			insertIntoIRlist(bltzop, temp1, temp2, elselabel);
		}
		else if (sym == GT) {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			strcpy(temp2, tempRes);
			insertIntoIRlist(blezop, temp1, temp2, elselabel);
		}
		else if (sym == EQ) {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			strcpy(temp2, tempRes);
			insertIntoIRlist(bneop, temp1, temp2, elselabel);
		}
		else {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			strcpy(temp2, tempRes);
			insertIntoIRlist(beqop, temp1, temp2, elselabel);
		}
		struct node curNode = findIdentInLastSymTable(temp2);
		char type2 = curNode.type;
		if (type2 != 2)
			error(CONDITION_TYPE_ERROR);
	}
	else {
		nameATempVar();
		char temp2[100], temp3[100];
		strcpy(temp3, tempRes);
		_itoa(0, temp2, 10);
		insertIntoIRlist(getiop, temp2, "", temp3);
		enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
		addrIndex += 4;
		insertIntoIRlist(beqop, temp1, temp3, elselabel);
	}
}

/*
* Summary: while sentence
*/
void whilesentence() {
	nameALabel();
	char temp1[100];
	strcpy(temp1, label);
	insertIntoIRlist(setop, "", "", temp1);
	getsym();
	if (sym != LPAR)
		error(MISSING_LPARENT);
	getsym();
	nameALabel();
	char temp2[100];
	strcpy(temp2, label);
	conditionsentence(temp2);
	if (sym != RPAR)
		error(MISSING_RPARENT);
	getsym();
	sentence();
	insertIntoIRlist(jop, "", "", temp1);
	insertIntoIRlist(setop, "", "", temp2);
}

/*
* Summary: if sentence
*/
void ifsentence() {
	getsym();
	if (sym != LPAR)
		error(MISSING_LPARENT);
	getsym();
	char temp1[100];
	nameALabel();
	strcpy(temp1, label);
	conditionsentence(temp1);
	if (sym != RPAR)
		error(MISSING_RPARENT);
	getsym();
	sentence();
	insertIntoIRlist(setop, "", "", temp1);
}

/*
* Summary: value parameter table
*/
void valueparatable(char* name) {
	int sum = 0;
	expression();
	nameATempVarByIndex(tempResIndex - 1);
	char temp1[100];
	strcpy(temp1, tempRes);
	insertIntoIRlist(paraop, "", "", temp1);
	sum++;
	struct node curNode = findPara(name, sum);
	if (curNode.kind == 4 && curNode.type != findIdentInLastSymTable(temp1).type) {
		error(ERROR_PARA_TYPE);
	}
	while (sym == COMMA) {
		getsym();
		expression();
		nameATempVarByIndex(tempResIndex - 1);
		strcpy(temp1, tempRes);
		insertIntoIRlist(paraop, "", "", temp1);
		sum++;
	}
	curNode = findFunction(name);
	if (curNode.number != sum)
		error(ERROR_PARA_NUM);
}

/*
* Summary: function call
*/
void funccall() {
	char name[100], returnlabel[100];
	nameALabel();
	strcpy(returnlabel, label);
	if (sym != IDENT)
		error(MISSING_IDENT);
	strcpy(name, cValue);
	getsym();
	if (sym != LPAR)
		error(MISSING_LPARENT);
	getsym();
	if (sym != RPAR) {
		valueparatable(name);
	}
	insertIntoIRlist(callop, "", "", name);
	if (sym != RPAR)
		error(MISSING_RPARENT);
	getsym();
}

/*
* Summary: assign sentence
*/
void assignsentence() {
	char name[100], temp1[100] = "";
	if (sym != IDENT)
		error(MISSING_IDENT);
	strcpy(name, cValue);
	getsym();
	if (sym == LBRACK) {
		getsym();
		expression();
		nameATempVarByIndex(tempResIndex - 1);
		strcpy(temp1, tempRes);
		if (sym != RBRACK) {
			error(MISSING_RBRACK);
		}
		getsym();
	}
	if (sym != IS)
		error(MISSING_IS);
	getsym();
	expression();
	nameATempVarByIndex(tempResIndex - 1);
	char temp2[100];
	strcpy(temp2, tempRes);
	insertIntoIRlist(stoop, temp2, temp1, name);
	struct node curNode = findIdentInLastSymTable(name);
	if (curNode.kind == 1)
		error(ASSIG2CONST);
}
/*
* Summary: scanf sentence
*/
void scanfsentence() {
	char name[100];
	getsym();
	if (sym != LPAR)
		error(MISSING_LPARENT);
	getsym();
	if (sym != IDENT)
		error(MISSING_IDENT);
	strcpy(name, cValue);
	insertIntoIRlist(scaop, "", "", name);
	getsym();
	while (sym == COMMA) {
		getsym();
		if (sym != IDENT)
			error(MISSING_IDENT);
		strcpy(name, cValue);
		insertIntoIRlist(scaop, "", "", name);
		getsym();
	}
	if (sym != RPAR)
		error(MISSING_RPARENT);
	getsym();
	struct node curNode = findIdentInLastSymTable(name);
	if (curNode.kind == 1)
		error(ASSIG2CONST);
}

/*
* Summary: printf sentence
*/
void printfsentence() {
	char string[100], stringName[100];
	getsym();
	if (sym != LPAR)
		error(MISSING_LPARENT);
	getsym();
	if (sym == STRING) {
		strcpy(string, cValue);
		nameAString();
		strcpy(stringName, tempString);
		getsym();
		enter(stringName, 6, 5, 0, 0, addrIndex - 4, string, "");
		if (sym == COMMA) {
			getsym();
			expression();
			nameATempVarByIndex(tempResIndex - 1);
			char temp1[100];
			strcpy(temp1, tempRes);
			insertIntoIRlist(priop, stringName, "", temp1);
		}
		else {
			insertIntoIRlist(priop, stringName, "", "");
		}
	}
	else {
		expression();
		nameATempVarByIndex(tempResIndex - 1);
		char temp1[100];
		strcpy(temp1, tempRes);
		insertIntoIRlist(priop, "", "", temp1);
	}
	if (sym != RPAR)
		error(MISSING_RPARENT);
	getsym();
}

/*
Summary: case substatement*/
void casesentence(char* switchVar, char *endlabel) {
	if (sym != CASESY)
		error(MISSING_CASE_KEYWORD);
	getsym();
	char endOfThisCase[100];
	nameALabel();
	strcpy(endOfThisCase, label);
	if (sym == CHAR) {
		char temp2[100], temp3[100];
		_itoa((int)cValue[0], temp2, 10);
		nameATempVar();
		strcpy(temp3, tempRes);
		insertIntoIRlist(getiop, temp2, "", temp3);
		enter(temp3, 5, 2, 0, 0, addrIndex, "", "");
		addrIndex += 4;
		insertIntoIRlist(bneop, switchVar, temp3, endOfThisCase);
		if (findIdentInLastSymTable(switchVar).type != 3)
			error(SWITCH_TYPE_ERROR);
		getsym();
	}
	else if (isInteger()) {
		char temp2[100], temp3[100];
		_itoa(iValue, temp2, 10);
		nameATempVar();
		strcpy(temp3, tempRes);
		insertIntoIRlist(getiop, temp2, "", temp3);
		enter(temp3, 5, 2, iValue, 0, addrIndex, "", "");
		addrIndex += 4;
		insertIntoIRlist(bneop, switchVar, temp3, endOfThisCase);
		if (findIdentInLastSymTable(switchVar).type != 2)
			error(SWITCH_TYPE_ERROR);
		getsym();
	}
	else
		error(CASE_CONTENT_WRONG);
	if (sym != COLON)
		error(MISSING_COLON);
	getsym();
	sentence();
	insertIntoIRlist(jop, "", "", endlabel);
	insertIntoIRlist(setop, "", "", endOfThisCase);
}

/*
* Summary: case table
*/
void casetable(char* switchVar, char* endlabel) {
	if (sym != CASESY)
		error(MISSING_CASE_KEYWORD);
	do {
		casesentence(switchVar, endlabel);
	} while (sym == CASESY);
}

/*
* Summary: default
*/
void defau() {
	getsym();
	if (sym == SEMICOLON)
		getsym();
	else if (sym == COLON) {
		getsym();
		sentence();
	}
	else
		error(MISSING_SEMICOLON);
}

/*
* Summary: switch sentence
*/
void switchsentence() {
	getsym();
	if (sym != LPAR)
		error(MISSING_LPARENT);
	getsym();
	expression();
	char switchVar[100];
	nameATempVarByIndex(tempResIndex - 1);
	strcpy(switchVar, tempRes);
	if (sym != RPAR)
		error(MISSING_RPARENT);
	getsym();
	if (sym != LBRACE)
		error(MISSING_LBRACE);
	getsym();
	char endlabel[100];
	nameALabel();
	strcpy(endlabel, label);
	casetable(switchVar, endlabel);
	if (sym == DEFAULTSY)
		defau();
	if (sym != RBRACE)
		error(MISSING_RBRACE);
	insertIntoIRlist(setop, "", "", endlabel);
	getsym();
}

/*
* Summary: return sentence
*/
void returnsentence() {
	retflag = 1;
	getsym();
	if (sym == LPAR) {
		getsym();
		expression();
		char temp1[100];
		nameATempVarByIndex(tempResIndex - 1);
		strcpy(temp1, tempRes);
		insertIntoIRlist(retop, "", "", temp1);
		if (sym != RPAR)
			error(MISSING_RPARENT);
		getsym();
	}
	else
		insertIntoIRlist(retop, "", "", "");
}

/*
* Summary: sentence
*/
void sentence() {
	if (sym == IFSY)
		ifsentence();
	else if (sym == WHILESY)
		whilesentence();
	else if (sym == LBRACE) {
		getsym();
		sentenceslist();
		if (sym != RBRACE)
			error(MISSING_RBRACE);
		getsym();
	}
	else if (sym == IDENT) {
		getsym();
		if (sym == LPAR) {
			symList_index -= 2;
			getsym();
			funccall();
			if (sym != SEMICOLON)
				error(MISSING_SEMICOLON);
			getsym();
		}
		else if (sym == IS || sym == LBRACK) {
			symList_index -= 2;
			getsym();
			assignsentence();
			if (sym != SEMICOLON)
				error(MISSING_SEMICOLON);
			getsym();
		}
		else
			error(SENTENCE_CONTENT_WRONG);
	}
	else if (sym == SCANFSY) {
		scanfsentence();
		if (sym != SEMICOLON)
			error(MISSING_SEMICOLON);
		getsym();
	}
	else if (sym == PRINTFSY) {
		printfsentence();
		if (sym != SEMICOLON)
			error(MISSING_SEMICOLON);
		getsym();
	}
	else if (sym == SEMICOLON)
		getsym();
	else if (sym == SWITCHSY)
		switchsentence();
	else if (sym == RETURNSY) {
		returnsentence();
		if (sym != SEMICOLON)
			error(MISSING_SEMICOLON);
		getsym();
	}
	else
		error(SENTENCE_CONTENT_WRONG);
}

/*
* Summary: sentences list
*/
void sentenceslist() {
	if (sym != IFSY && sym != WHILESY && sym != LBRACE && sym != IDENT && sym != SCANFSY && sym != PRINTFSY && sym != SEMICOLON && sym != SWITCHSY && sym != RETURNSY)
		return;
	while (sym == IFSY || sym == WHILESY || sym == LBRACE || sym == IDENT || sym == SCANFSY || sym == PRINTFSY || sym == SEMICOLON || sym == SWITCHSY || sym == RETURNSY)
		sentence();
}

/*
* Summary: complex sentence
*/
void complexsentence() {
	if (sym == CONSTSY)
		condecl();
	if (sym == INTSY || sym == CHARSY)
		vardecl();
	sentenceslist();
}

/*
* Summary: function define
*/
void funcdef() {
	addrIndex = 0;
	while (1) {
		retflag = 0;
		char temp1[100];
		nameALabel();
		strcpy(temp1, label);
		char name[100];
		int kind = 3, type = 0, number = 0;
		if (sym == VOIDSY)
			type = 1;
		else if (sym == INTSY)
			type = 2;
		else
			type = 3;
		getsym();
		if (sym != IDENT)
			error(MISSING_IDENT);
		strcpy(name, cValue);
		insertIntoIRlist(fstaop, "", "", name);
		insertIntoIRlist(setop, "", "", temp1);
		enter(name, kind, type, 0, number, 0, "", temp1);
		getsym();
		if (sym != LPAR)
			error(MISSING_LPARENT);
		getsym();
		if (sym != RPAR) {
			number = paratable();
			updateParaNumber(name, number);
		}
		addrIndex += 8;
		if (sym != RPAR)
			error(MISSING_RPARENT);
		getsym();
		if (sym != LBRACE)
			error(MISSING_LBRACE);
		getsym();
		complexsentence();
		if (retflag == 0 && type != 1)
			error(RETURN_ERROR);
		retflag = 1;
		if (sym != RBRACE)
			error(MISSING_RBRACE);
		insertIntoIRlist(jrop, "", "", "");
		getsym();

		if (sym == INTSY || sym == CHARSY || sym == VOIDSY) {
			getsym();
			if (sym == MAINSY && symList[symList_index - 2]->sym == VOIDSY) {
				symList_index -= 2;
				getsym();
				break;
			}
			else {
				addrIndex = 0;
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
void mainprog(char *mainlabel) {
	addrIndex = 0;
	getsym();
	if (sym != MAINSY)
		error(MISSING_MAIN);
	enter("main", 3, 1, 0, 0, 0, "", mainlabel);
	getsym();
	if (sym != LPAR)
		error(MISSING_LPARENT);
	getsym();
	if (sym != RPAR)
		error(MISSING_RPARENT);
	getsym();
	if (sym != LBRACE)
		error(MISSING_LBRACE);
	getsym();
	complexsentence();
	if (sym != RBRACE)
		error(MISSING_RBRACE);
	getsym();
}

/*
* Summary: program
*/
void program() {
	char mainlabel[100];
	nameALabel();
	strcpy(mainlabel, label);
	if (sym == CONSTSY)
		condecl();
	if (sym == INTSY || sym == CHARSY) {
		getsym();
		if (sym != IDENT)
			error(MISSING_IDENT);
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
		else
			error(MISSING_SEMICOLON);
	}
	insertIntoIRlist(callop, "", "", "main");
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
		insertIntoIRlist(fstaop, "", "", "main");
		insertIntoIRlist(setop, "", "", mainlabel);
		mainprog(mainlabel);
		insertIntoIRlist(endop, "", "", "");
	}
	else
		error(PROGRAM_ERROR);
}