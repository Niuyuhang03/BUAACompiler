#include "stdafx.h"
#include "IR.h"

struct IR IRlist[MAX_IR_NUMBER];
int IRtop = 0;

char IRlistName[IR_NUMBER][10] = { "varop", "arrop", "conop", "assop", "stoaop", "getaop", "callop",
	"paraop", "gtop", "geop", "ltop", "leop", "eqop", "neop", "addop", "subop", "multop", "divop", 
	"jop" };

void insertIntoIRlist(enum OP op, char* op1, char* op2, char* res) {
	IRlist[IRtop].op = op;
	strcpy(IRlist[IRtop].op1, op1);
	strcpy(IRlist[IRtop].op2, op2);
	strcpy(IRlist[IRtop].res, res);
	IRtop++;
}