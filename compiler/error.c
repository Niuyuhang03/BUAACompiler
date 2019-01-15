#include "stdafx.h"
#include "lexer.h"
#include "error.h"

int errorflag = 0;

void error(enum errorType errorNum) {
	errorflag = 1;
	switch (errorNum) {
		case(UNDEF_ID): {							// 标识符未定义
			printf("row:%d column:%d <the identifier is not defined!>\n", row, column);
			break;
		}
		case(MULTI_DEF): {							// 标识符重定义
			printf("row:%d column:%d <this identifier was defined before!>\n", row, column);
			break;
		}
		case(PROGRAM_ERROR): {						// 程序中主函数后仍有代码
			printf("row:%d column:%d <program doesn't finish after main or without main!>\n", row, column);
			break;
		}
		case(STR_EMPTY): {							// 空字符串，不保存空字符串，跳到右引号后
			printf("row:%d column:%d <the string shouldn't be empty!>\n", startRow, startColumn + 1);
			break;
		}
		case(STR_CONTENT_ERROR): {					// 字符串内有非法字符，不保存当前字符串，跳读到本行下一个右双引号，若本行没有右双引号则跳过本行
			printf("row:%d column:%d <the string in printf has illegel character!>\n", row, column);
			break;
		}
		case(STR_MISSINT_RPARENT): {				// 字符串在该行没有右双引号，容错，在行尾补一个右双引号，保存之前的字符串
			printf("row:%d column:%d <missing right parentheses in string!>\n", startRow, maxColumn + 1);
			break;
		}
		case(ZERO_HEAD_NUM): {						// 数字开头有前导零，容错，去掉前导零
			printf("row:%d column:%d <number can't start with extra zero!>\n", row, column);
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
		case(NEQUAL_MISS): {						// 感叹号后不是等号，容错，强行补一个，保存!=
			printf("row:%d column:%d <missing a \'=\' after \'!\'!>\n", row, column);
			break;
		}
		case(MISSING_SEMICOLON): {					// 丢失分号，容错，补一个分号
			printf("row:%d column:%d <missing a \';\'!>\n", row, -1);
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
		case(ERROR_PARA_NUM): {						// 参数数目错误
			printf("row:%d column:%d <the number of parameter is wrong!>\n", row, column);
			break;
		}
		case(MISSING_LPARENT): {					// 丢失左小括号
			printf("row:%d column:%d <missing a left parentheses!>\n", row, column);
			break;
		}
		case(MISSING_LBRACE): {						// 丢失左大括号
			printf("row:%d column:%d <missing a left brace!>\n", row, column);
			break;
		}
		case(MISSING_INTEGER): {					// 丢失整数
			printf("row:%d column:%d <missing integer!>\n", row, column);
			break;
		}
		case(MISSING_NUMBER): {						// 丢失无符号整数
			printf("row:%d column:%d <missing Non-sign number!>\n", row, column);
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
		case(RETURN_ERROR): {						// 返回值类型错误或缺少返回值
			printf("row:%d column:%d <error occurs in return!>\n", row, column);
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
		case(WRONG_ASSIGN_TYPE): {					// 赋值类型错误
			printf("row:%d column:%d <wrong type when assign!>\n", row, column);
			break;
		}
		case(CASE_CONTENT_WRONG): {					// case内容错误
			printf("row:%d column:%d <wrong occurs in case!>\n", row, column);
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
		case(OUT_OF_ARRAY): {						// 数组越界
			printf("row:%d column:%d <the index is out of array range!>\n", row, column);
			break;
		}
		case(WRONG_TYPE): {							// 声明类型错误
			printf("row:%d column:%d <wrong type when declear!>\n", row, column);
			break;
		}
		case(FILE_NOT_EXIST): {						// 源文件不存在
			printf("<file doesn't exist！>\n");
			break;
		}
		case(ILLEGAL_WORD): {						// 非法字符（如汉字），跳过该字符
			printf("row:%d column:%d <the word is not in ascii [-1, 255]!>\n", row, column);
			break;
		}
		case(FUNC_NO_DEFINED): {					// 函数未定义
			printf("row:%d column:%d <the function wasn't defined!>\n", row, column);
			break;
		}
		case(FUNC_NO_RET): {						// 无返回值函数当做表达式使用
			printf("row:%d column:%d <Non-return function can't be in experision!>\n", row, column);
			break;
		}
		case(ERROR_PARA_TYPE): {					// 参数类型错误
			printf("row:%d column:%d <error occurs in parameters' type!>\n", row, column);
			break;
		}
		case(ASSIG2CONST): {						// 给常量赋值
			printf("row:%d column:%d <constant can't be assigned!>\n", row, column);
			break;
		}
		case(CONDITION_TYPE_ERROR): {				// 条件中类型不匹配或类型不为整型
			printf("row:%d column:%d <condition type error!>\n", row, column);
			break;
		}
		case(ARRAY_INDEX_NOT_INT): {				// 数组下标不是int
			printf("row:%d column:%d <index in array should be int!>\n", row, column);
			break;
		}
		case(SWITCH_TYPE_ERROR): {					// switch中类型不匹配
			printf("row:%d column:%d <type in switch-case doesn't match!>\n", row, column);
			break;
		}
		default: {
			break;
		}
	}
}