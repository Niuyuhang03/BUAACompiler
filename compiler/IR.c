#include "stdafx.h"
#include "IR.h"

struct IR IRlist[MAX_IR_NUMBER];
int IRtop = 0;

char IRlistName[IR_NUMBER][10] = { "varop", "arrop", "conop", "stoop", "getaop", "callop",
	"paraop", "addop", "subop", "multop", "divop", "jop", "setop", "scaop", 
	"priop", "retop", "getop", "getiop", "getrop", "jrop", "endop", "fstaop", 
	"bltzop", "blezop", "bgezop", "bgtzop", "beqop", "bneop" };

void insertIntoIRlist(enum OP op, char* op1, char* op2, char* res) {
	IRlist[IRtop].op = op;
	strcpy(IRlist[IRtop].op1, op1);
	strcpy(IRlist[IRtop].op2, op2);
	strcpy(IRlist[IRtop].res, res);
	IRtop++;
}