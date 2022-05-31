#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct {
	ElemType* elem;                      //整型指针
	int TableLen;
}SSTable;

void ST_Init(SSTable& ST, int len) {
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//随机了11个数，但是第一个元素是没有用到的
	}
}

int main()
{
	SSTable ST;
	ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	ST_Init(ST, 10);//实际申请了11个元素空间
	memcpy(ST.elem + 1, A, sizeof(A));
	ST_print(ST);
	//InsertSort(ST.elem,10);
	//MidInsertSort(ST.elem,10);
	ShellSort(ST.elem, 10);
	ST_print(ST);
	
}