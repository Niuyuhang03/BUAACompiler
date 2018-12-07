#pragma once
#define MAX_SYMTABLE_SIZE	1000000	// 最多标识符个数
#define MAX_LAYER	10000			// 最大嵌套层数
#define MAX_TEMP_NUMBER	100			// 最大四元式临时变量位数
#define MAX_LABEL_NUMBER	100		// 最大label位数

struct node {
	char name[100];		// 标识符名称
	int kind;			// 标识符类型，1:constant,2:variable,3:function,4:para,5:tempVar,6:STRING
	int type;			// 函数的返回值类型或其他标识符的小类型，1:void,2:int,3:char,4:int arrays,5:char arrays
	int value;			// 常量的值或ascii码，其他类型此处为0
	int number;			// 函数参数个数或数组元素个数，其他类型此处为0
	int addr;			// 内存中标识符相对于所在AR首地址的偏移量，数组为数组首地址的偏移量
	char STRING[100];	// 字符串的内容
	char label[100];	// 函数的label
	int sum;			// 一个函数中变量、常量、临时变量、参数的内存大小总和+4(包括4个ra的位置和4个fp位置)
	int level;			// 该node所在分程序下标
};

struct symtable {
	struct node table[MAX_SYMTABLE_SIZE];			// 程序所有标识符信息数组
	int top;										// 符号表栈顶的位置
	int subprogramNumber;							// 分程序总数
	int subprogramTable[MAX_LAYER];					// 分程序索引
};

void init();
void program();
struct node findIdentInSymTable(char* name);
void updateFuncVarNum();
struct node findFunction(char* name);
struct node findLabel(char* name);

struct symtable *symTable;
