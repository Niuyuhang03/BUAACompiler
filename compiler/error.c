#include "stdafx.h"
#include "lexer.h"
#include "error.h"

void error(enum errorType errorNum) {
	switch (errorNum) {
		case(UNDEF_ID): {
			printf("row:%d column:%d <the identifier is not defined!>\n", row, column);
			break;
		}
		case(MULTI_DEF): {
			printf("this identifier was defined before!\n");
			break;
		}
		case(IDENT_TOO_LONG): {
			printf("this identifier is too long!\n");
			break;
		}
		case(PROGRAM_ERROR): {						// �����������������д���
			printf("row:%d column:%d <program doesn't finish after main!>\n", row, column);
			break;
		}
		case(STR_EMPTY): {							// ���ַ�������������ַ��������������ź�
			printf("row:%d column:%d <the string shouldn't be empty!>\n", startRow, startColumn + 1);
			break;
		}
		case(STR_CONTENT_ERROR): {					// �ַ������зǷ��ַ��������浱ǰ�ַ�����������������һ����˫���ţ�������û����˫��������������
			printf("row:%d column:%d <the string in printf has illegel character!>\n", startRow, startColumn + 1);
			break;
		}
		case(STR_MISSINT_RPARENT): {				// �ַ����ڸ���û����˫���ţ��ݴ�����β��һ����˫���ţ�����֮ǰ���ַ���
			printf("row:%d column:%d <missing right parentheses in string!>\n", startRow, maxColumn + 1);
			break;
		}
		case(ZERO_HEAD_NUM): {						// �����ַ����㿪ͷ���ݴ�ȥ��ǰ����
			printf("row:%d column:%d <non-zero number can't start with zero!>\n", row, column);
			break;
		}
		case(NUM_HEAD_IDENT): {
			printf("the identifier can't start with number!\n");
			break;
		}
		case(NUM_TOO_LARGE): {
			printf("the number is too large!\n");
			break;
		}
		case(UNDEF_INPUT): {
			printf("the input word is illegal!\n");
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
		case(NEQUAL_MISS): {						// ���Ⱥź��ǵȺţ��ݴ�ǿ�в�һ��������!=
			printf("row:%d column:%d <missing a \'=\' after \'!\'!>\n", row, column);
			break;
		}
		case(MISSING_SEMICOLON): {					// ��ʧ�ֺ�
			printf("row:%d column:%d <missing a \';\'!>\n", row, column);
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
		case(ERROR_PARA_NUM): {
			printf("the number of parameter is wrong!\n");
			break;
		}
		case(MISSING_LPARENT): {					// ��ʧ��С����
			printf("row:%d column:%d <missing a left parentheses!>\n", row, column);
			break;
		}
		case(MISSING_LBRACK): {
			printf("missing a left bracket!\n");
			break;
		}
		case(MISSING_LBRACE): {						// ��ʧ�������
			printf("row:%d column:%d <missing a left brace!>\n", row, column);
			break;
		}
		case(MISSING_PLUS): {
			printf("missing a plus or a minus!\n");
			break;
		}
		case(MISSING_MULTI): {
			printf("missing a multiply or a divide!\n");
			break;
		}
		case(MISSING_INTEGER): {					// ��ʧ����
			printf("row:%d column:%d <missing integer!>\n", row, column);
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
		case(MISSING_NUMBER): {						// ��ʧ�޷�������
			printf("row:%d column:%d <missing Non-sign number!>\n", row, column);
			break;
		}
		case(RETURN_ERROR): {
			printf("error occurs in return!\n");
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
		case(MISSING_RETURN): {
			printf("missing a return!\n");
			break;
		}
		case(EXPRESSION_ERROR): {
			printf("error occurs in expression!\n");
			break;
		}
		case(CONST_NOT_INIT): {
			printf("constant isn't assigned!\n");
			break;
		}
		case(VAR_NOT_INIT): {
			printf("variable isn't assigned!\n");
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
		case(CASE_CONTENT_WRONG): {					// case���ݴ���
			printf("row:%d column:%d <wrong occurs in case!>\n", row, column);
			break;
		}
		case(FUNC_NO_RET): {
			printf("Non-return function can't be in experision!\n");
			break;
		}
		case(OUT_OF_TABLE): {
			printf("symbol table is full!\n");
			break;
		}
		case(OUT_OF_ARRAY): {
			printf("the index is out of array range!\n");
			break;
		}
		case(WRONG_TYPE): {							// �������ʹ���
			printf("row:%d column:%d <wrong type when declear!>\n", row, column);
			break;
		}
		case(FILE_NOT_EXIST): {
			printf("file doesn't exist��\n");
			break;
		}
		case(ILLEGAL_WORD): {						// �Ƿ��ַ����纺�֣�������ascii��Χ��������������������
			printf("row:%d column:%d <the word is not in ascii [-1, 255]!>\n", row, column);
			break;
		}
		case(FUNC_NO_DEFINED): {
			printf("row:%d column:%d <the function wasn't defined!>\n", row, column);
			break;
		}
		default: {
			break;
		}
	}
}