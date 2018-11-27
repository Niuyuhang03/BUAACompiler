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
		case(PROGRAM_ERROR): {						// 程序中主函数后仍有代码
			printf("row:%d column:%d <program doesn't finish after main!>\n", row, column);
			break;
		}
		case(STR_EMPTY): {							// 空字符串，不保存空字符串，跳到右引号后
			printf("row:%d column:%d <the string shouldn't be empty!>\n", startRow, startColumn + 1);
			break;
		}
		case(STR_CONTENT_ERROR): {					// 字符串内有非法字符，不保存当前字符串，跳读到本行下一个右双引号，若本行没有右双引号则跳过本行
			printf("row:%d column:%d <the string in printf has illegel character!>\n", startRow, startColumn + 1);
			break;
		}
		case(STR_MISSINT_RPARENT): {				// 字符串在该行没有右双引号，容错，在行尾补一个右双引号，保存之前的字符串
			printf("row:%d column:%d <missing right parentheses in string!>\n", startRow, maxColumn + 1);
			break;
		}
		case(ZERO_HEAD_NUM): {						// 非零字符以零开头，容错，去掉前导零
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
		case(CHAR_MISS_QUOTE): {					// 字符类型中字符后不紧跟单引号，容错，补一个单引号
			printf("row:%d column:%d <missing a apostrophe in char!>\n", startRow, startColumn + 2);
			break;
		}
		case(CHAR_CONTENT_ERROR): {					// 左单引号后符号不合法，容错，不保存该符号，跳到该符号后一个的右单引号后，若无右单引号，仅跳到符号后
			printf("row:%d column:%d <the word in char is illegal!>\n", startRow, startColumn + 1);
			break;
		}
		case(NEQUAL_MISS): {						// 不等号后不是等号，容错，强行补一个，保存!=
			printf("row:%d column:%d <missing a \'=\' after \'!\'!>\n", row, column);
			break;
		}
		case(MISSING_SEMICOLON): {					// 丢失分号
			printf("row:%d column:%d <missing a \';\'!>\n", row, column);
			break;
		}
		case(MISSING_COLON): {						// 丢失冒号
			printf("row:%d column:%d <missing a \':\'!>\n", row, column);
			break;
		}
		case(MISSING_RPARENT): {					// 缺失右小括号
			printf("row:%d column:%d <missing a right parentheses!>\n", row, column);
			break;
		}
		case(MISSING_RBRACK): {						// 丢失右中括号
			printf("row:%d column:%d <missing a right bracket!>\n", row, column);
			break;
		}
		case(MISSING_RBRACE): {						// 丢失右大括号
			printf("row:%d column:%d <missing a right brace!>\n", row, column);
			break;
		}
		case(MISSING_IDENT): {						// 缺失标识符
			printf("row:%d column:%d <missing a identifier!>\n", row, column);
			break;
		}
		case(ERROR_PARA_NUM): {
			printf("the number of parameter is wrong!\n");
			break;
		}
		case(MISSING_LPARENT): {					// 丢失左小括号
			printf("row:%d column:%d <missing a left parentheses!>\n", row, column);
			break;
		}
		case(MISSING_LBRACK): {
			printf("missing a left bracket!\n");
			break;
		}
		case(MISSING_LBRACE): {						// 丢失左大括号
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
		case(MISSING_INTEGER): {					// 丢失整数
			printf("row:%d column:%d <missing integer!>\n", row, column);
			break;
		}
		case(MISSING_IS): {							// 丢失一个等号（赋值符号）
			printf("row:%d column:%d <missing =!>\n", row, column);
			break;
		}
		case(MISSING_CHAR): {						// 丢失字符类型（'a'）
			printf("row:%d column:%d <missing CHAR!>\n", row, column);
			break;
		}
		case(MISSING_NUMBER): {						// 丢失无符号整数
			printf("row:%d column:%d <missing Non-sign number!>\n", row, column);
			break;
		}
		case(RETURN_ERROR): {
			printf("error occurs in return!\n");
			break;
		}
		case(MISSING_MAIN): {						// 丢失主函数
			printf("row:%d column:%d <missing main function!>\n", row, column);
			break;
		}
		case(MISSING_CASE_KEYWORD): {				// 丢失case关键字
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
		case(FACTOR_CONTENT_WRONG): {				// 因子内容错误
			printf("row:%d column:%d <wrong occurs in factor!>\n", row, column);
			break;
		}
		case(SENTENCE_CONTENT_WRONG): {				// 语句内容错误
			printf("row:%d column:%d <wrong occurs in sentence!>\n", row, column);
			break;
		}
		case(CASE_CONTENT_WRONG): {					// case内容错误
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
		case(WRONG_TYPE): {							// 声明类型错误
			printf("row:%d column:%d <wrong type when declear!>\n", row, column);
			break;
		}
		case(FILE_NOT_EXIST): {
			printf("file doesn't exist！\n");
			break;
		}
		case(ILLEGAL_WORD): {						// 非法字符（如汉字），若在ascii范围内则跳过，否则程序结束
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