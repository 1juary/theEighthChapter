#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int ElemType;

typedef struct {
	ElemType* elem;
	int TableLen;
}SSTable;

void ST_Init(SSTable& ST, int len) {
	ST.TableLen = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;
	}
}


//打印数组
void ST_print(SSTable ST) {
	
	for (int i = 0; i < ST.TableLen; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

//交换函数
void swap(ElemType& a, ElemType& b)
{
	ElemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}

//简单选择排序
void SelectSort(ElemType A[], int n) {
	int i, j, min;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (A[min] > A[j])
				min = j;
		}
		if (min != i) {
			swap(A[i], A[min]);
		}
	}
}

int main() {
	SSTable ST;
	ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,99 };
	ST_Init(ST, 10);//初始化
	memcpy(ST.elem, A, sizeof(A));
	ST_print(ST);
	SelectSort(ST.elem, 10);
	ST_print(ST);
}