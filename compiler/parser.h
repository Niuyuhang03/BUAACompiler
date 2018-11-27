#pragma once
#define MAX_SYMTABLE_SIZE	1000000	// 最多标识符个数
#define MAX_LAYER	10000			// 最大嵌套层数

struct node {
	char name[100];		// 标识符名称
	int kind;			// 标识符类型，1:constant,2:variable,3:function,4:para
	int type;			// 函数的返回值类型或其他标识符的小类型，1:void,2:int,3:char,4:int arrays,5:char arrays
	int value;			// 符号的值
	int number;			// 函数参数或数组元素个数
};

struct symtable {
	struct node table[MAX_SYMTABLE_SIZE];			// 程序所有标识符信息数组
	int top;										// 符号表顶的位置
	int subprogramNumber;							// 分程序总数
	int subprogramTable[MAX_LAYER];					// 分程序索引
};

void init();
void program();

extern struct symtable *symTable;
