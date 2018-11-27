#pragma once
#define MAX_SYMTABLE_SIZE	1000000	// ����ʶ������
#define MAX_LAYER	10000			// ���Ƕ�ײ���

struct node {
	char name[100];		// ��ʶ������
	int kind;			// ��ʶ�����ͣ�1:constant,2:variable,3:function,4:para
	int type;			// �����ķ���ֵ���ͻ�������ʶ����С���ͣ�1:void,2:int,3:char,4:int arrays,5:char arrays
	int value;			// ���ŵ�ֵ
	int number;			// ��������������Ԫ�ظ���
};

struct symtable {
	struct node table[MAX_SYMTABLE_SIZE];			// �������б�ʶ����Ϣ����
	int top;										// ���ű���λ��
	int subprogramNumber;							// �ֳ�������
	int subprogramTable[MAX_LAYER];					// �ֳ�������
};

void init();
void program();

extern struct symtable *symTable;
