#pragma once
#define	MAX_IR_NUMBER	100000
#define IR_NUMBER	29

enum OP {
	varop = 0, arrop, conop, stoop, getaop, callop, paraop, addop, subop, multop, divop, 
	jop, setop, scaop, priop, retop, getop, getiop, getrop, getpop, jrop, endop, fstaop, 
	bltzop, blezop, bgezop, bgtzop, beqop, bneop
};

struct IR {
	enum OP op;
	char op1[100];
	char op2[100];
	char res[100];
};

struct IR IRlist[MAX_IR_NUMBER];
char IRlistName[IR_NUMBER][10];
int IRtop;

void insertIntoIRlist(enum OP op, char* op1, char* op2, char* res);