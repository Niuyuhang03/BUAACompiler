#pragma once
#define	MAX_IR_NUMBER	100000

enum OP {
	varop, arrop, conop, assop, stoaop, getaop, callop, paraop, gtop, geop, ltop, leop, eqop, neop,
	addop, subop, multop, divop, jop
};

struct IR {
	enum OP op;
	char op1[100];
	char op2[100];
	char res[100];
};

struct IR IRlist[MAX_IR_NUMBER];
int IRtop;