#pragma once

FILE *outputfp;

void gendata();
void gentext();

int layer[10000];			// 运行栈中的分程序信息
int layerTop;			// 运行栈中的分程序信息的顶部