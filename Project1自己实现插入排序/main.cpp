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

void ST_print(SSTable ST) {
	for (int i = 1; i < ST.TableLen; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

void InsertSort(SSTable &ST, int n) {
	int i, j;
	for (i = 2; i <= n; i++) {
		if (ST.elem[i] < ST.elem[i-1]) {
			ST.elem[0] = ST.elem[i];
			for (j = i - 1; ST.elem[j] > ST.elem[0]; --j) {
				ST.elem[j + 1] = ST.elem[j];
			}
			ST.elem[j + 1] = ST.elem[0];
		}
	}
}


void MidInsertSort(SSTable &ST, int n) {

}

int main()
{
	SSTable ST;
	ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	ST_Init(ST, 10);//实际申请了11个元素空间
	memcpy(ST.elem + 1, A, sizeof(A));
	ST_print(ST);
	InsertSort(ST,10);
	MidInsertSort(ST.elem,10);
	//ShellSort(ST.elem, 10);
	ST_print(ST);
	
}