#pragma once
#define MAX_SYMTABLE_SIZE	1000000	// ����ʶ������
#define MAX_LAYER	10000			// ���Ƕ�ײ���
#define MAX_TEMP_NUMBER	100			// �����Ԫʽ��ʱ����λ��
#define MAX_LABEL_NUMBER	100		// ���labelλ��

struct node {
	char name[100];		// ��ʶ������
	int kind;			// ��ʶ�����ͣ�1:constant,2:variable,3:function,4:para,5:tempVar,6:STRING
	int type;			// �����ķ���ֵ���ͻ�������ʶ����С���ͣ�1:void,2:int,3:char,4:int arrays,5:char arrays
	int value;			// ������ֵ��ascii�룬�������ʹ˴�Ϊ0
	int number;			// ������������������Ԫ�ظ������������ʹ˴�Ϊ0
	int addr;			// �ڴ��б�ʶ�����������AR�׵�ַ��ƫ����������Ϊ�����׵�ַ��ƫ����
	char STRING[100];	// �ַ���������
	char label[100];	// ������label
	int sum;			// һ�������б�������������ʱ�������������ڴ��С�ܺ�+4(����4��ra��λ�ú�4��fpλ��)
	int level;			// ��node���ڷֳ����±�
};

struct symtable {
	struct node table[MAX_SYMTABLE_SIZE];			// �������б�ʶ����Ϣ����
	int top;										// ���ű�ջ����λ��
	int subprogramNumber;							// �ֳ�������
	int subprogramTable[MAX_LAYER];					// �ֳ�������
};

void init();
void program();
struct node findIdentInSymTable(char* name);
void updateFuncVarNum();
struct node findFunction(char* name);
struct node findLabel(char* name);

struct symtable *symTable;
