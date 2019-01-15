#include "stdafx.h"
#include "lexer.h"
#include "error.h"

int errorflag = 0;

void error(enum errorType errorNum) {
	errorflag = 1;
	switch (errorNum) {
		case(UNDEF_ID): {							// ��ʶ��δ����
			printf("row:%d column:%d <the identifier is not defined!>\n", row, column);
			break;
		}
		case(MULTI_DEF): {							// ��ʶ���ض���
			printf("row:%d column:%d <this identifier was defined before!>\n", row, column);
			break;
		}
		case(PROGRAM_ERROR): {						// �����������������д���
			printf("row:%d column:%d <program doesn't finish after main or without main!>\n", row, column);
			break;
		}
		case(STR_EMPTY): {							// ���ַ�������������ַ��������������ź�
			printf("row:%d column:%d <the string shouldn't be empty!>\n", startRow, startColumn + 1);
			break;
		}
		case(STR_CONTENT_ERROR): {					// �ַ������зǷ��ַ��������浱ǰ�ַ�����������������һ����˫���ţ�������û����˫��������������
			printf("row:%d column:%d <the string in printf has illegel character!>\n", row, column);
			break;
		}
		case(STR_MISSINT_RPARENT): {				// �ַ����ڸ���û����˫���ţ��ݴ�����β��һ����˫���ţ�����֮ǰ���ַ���
			printf("row:%d column:%d <missing right parentheses in string!>\n", startRow, maxColumn + 1);
			break;
		}
		case(ZERO_HEAD_NUM): {						// ���ֿ�ͷ��ǰ���㣬�ݴ�ȥ��ǰ����
			printf("row:%d column:%d <number can't start with extra zero!>\n", row, column);
			break;
		}
		case(CHAR_MISS_QUOTE): {					// �ַ��������ַ��󲻽��������ţ��ݴ���һ��������
			printf("row:%d column:%d <missing a apostrophe in char!>\n", startRow, startColumn + 2);
			break;
		}
		case(CHAR_CONTENT_ERROR): {					// �����ź���Ų��Ϸ����ݴ�������÷��ţ������÷��ź�һ�����ҵ����ź������ҵ����ţ����������ź�
			printf("row:%d column:%d <the word in char is illegal!>\n", startRow, startColumn + 1);
			break;
		}
		case(NEQUAL_MISS): {						// ��̾�ź��ǵȺţ��ݴ�ǿ�в�һ��������!=
			printf("row:%d column:%d <missing a \'=\' after \'!\'!>\n", row, column);
			break;
		}
		case(MISSING_SEMICOLON): {					// ��ʧ�ֺţ��ݴ���һ���ֺ�
			printf("row:%d column:%d <missing a \';\'!>\n", row, -1);
			break;
		}
		case(MISSING_COLON): {						// ��ʧð��
			printf("row:%d column:%d <missing a \':\'!>\n", row, column);
			break;
		}
		case(MISSING_RPARENT): {					// ȱʧ��С����
			printf("row:%d column:%d <missing a right parentheses!>\n", row, column);
			break;
		}
		case(MISSING_RBRACK): {						// ��ʧ��������
			printf("row:%d column:%d <missing a right bracket!>\n", row, column);
			break;
		}
		case(MISSING_RBRACE): {						// ��ʧ�Ҵ�����
			printf("row:%d column:%d <missing a right brace!>\n", row, column);
			break;
		}
		case(MISSING_IDENT): {						// ȱʧ��ʶ��
			printf("row:%d column:%d <missing a identifier!>\n", row, column);
			break;
		}
		case(ERROR_PARA_NUM): {						// ������Ŀ����
			printf("row:%d column:%d <the number of parameter is wrong!>\n", row, column);
			break;
		}
		case(MISSING_LPARENT): {					// ��ʧ��С����
			printf("row:%d column:%d <missing a left parentheses!>\n", row, column);
			break;
		}
		case(MISSING_LBRACE): {						// ��ʧ�������
			printf("row:%d column:%d <missing a left brace!>\n", row, column);
			break;
		}
		case(MISSING_INTEGER): {					// ��ʧ����
			printf("row:%d column:%d <missing integer!>\n", row, column);
			break;
		}
		case(MISSING_NUMBER): {						// ��ʧ�޷�������
			printf("row:%d column:%d <missing Non-sign number!>\n", row, column);
			break;
		}
		case(MISSING_IS): {							// ��ʧһ���Ⱥţ���ֵ���ţ�
			printf("row:%d column:%d <missing =!>\n", row, column);
			break;
		}
		case(MISSING_CHAR): {						// ��ʧ�ַ����ͣ�'a'��
			printf("row:%d column:%d <missing CHAR!>\n", row, column);
			break;
		}
		case(RETURN_ERROR): {						// ����ֵ���ʹ����ȱ�ٷ���ֵ
			printf("row:%d column:%d <error occurs in return!>\n", row, column);
			break;
		}
		case(MISSING_MAIN): {						// ��ʧ������
			printf("row:%d column:%d <missing main function!>\n", row, column);
			break;
		}
		case(MISSING_CASE_KEYWORD): {				// ��ʧcase�ؼ���
			printf("row:%d column:%d <missing case key word!>\n", row, column);
			break;
		}
		case(WRONG_ASSIGN_TYPE): {					// ��ֵ���ʹ���
			printf("row:%d column:%d <wrong type when assign!>\n", row, column);
			break;
		}
		case(CASE_CONTENT_WRONG): {					// case���ݴ���
			printf("row:%d column:%d <wrong occurs in case!>\n", row, column);
			break;
		}
		case(FACTOR_CONTENT_WRONG): {				// �������ݴ���
			printf("row:%d column:%d <wrong occurs in factor!>\n", row, column);
			break;
		}
		case(SENTENCE_CONTENT_WRONG): {				// ������ݴ���
			printf("row:%d column:%d <wrong occurs in sentence!>\n", row, column);
			break;
		}
		case(OUT_OF_ARRAY): {						// ����Խ��
			printf("row:%d column:%d <the index is out of array range!>\n", row, column);
			break;
		}
		case(WRONG_TYPE): {							// �������ʹ���
			printf("row:%d column:%d <wrong type when declear!>\n", row, column);
			break;
		}
		case(FILE_NOT_EXIST): {						// Դ�ļ�������
			printf("<file doesn't exist��>\n");
			break;
		}
		case(ILLEGAL_WORD): {						// �Ƿ��ַ����纺�֣����������ַ�
			printf("row:%d column:%d <the word is not in ascii [-1, 255]!>\n", row, column);
			break;
		}
		case(FUNC_NO_DEFINED): {					// ����δ����
			printf("row:%d column:%d <the function wasn't defined!>\n", row, column);
			break;
		}
		case(FUNC_NO_RET): {						// �޷���ֵ�����������ʽʹ��
			printf("row:%d column:%d <Non-return function can't be in experision!>\n", row, column);
			break;
		}
		case(ERROR_PARA_TYPE): {					// �������ʹ���
			printf("row:%d column:%d <error occurs in parameters' type!>\n", row, column);
			break;
		}
		case(ASSIG2CONST): {						// ��������ֵ
			printf("row:%d column:%d <constant can't be assigned!>\n", row, column);
			break;
		}
		case(CONDITION_TYPE_ERROR): {				// ���������Ͳ�ƥ������Ͳ�Ϊ����
			printf("row:%d column:%d <condition type error!>\n", row, column);
			break;
		}
		case(ARRAY_INDEX_NOT_INT): {				// �����±겻��int
			printf("row:%d column:%d <index in array should be int!>\n", row, column);
			break;
		}
		case(SWITCH_TYPE_ERROR): {					// switch�����Ͳ�ƥ��
			printf("row:%d column:%d <type in switch-case doesn't match!>\n", row, column);
			break;
		}
		default: {
			break;
		}
	}
}