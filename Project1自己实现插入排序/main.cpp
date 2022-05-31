#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct {
	ElemType* elem;                      //����ָ��
	int TableLen;
}SSTable;

void ST_Init(SSTable& ST, int len) {
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLen; i++)
	{
		ST.elem[i] = rand() % 100;//�����11���������ǵ�һ��Ԫ����û���õ���
	}
}

int main()
{
	SSTable ST;
	ElemType A[10] = { 64, 94, 95, 79, 69, 84, 18, 22, 12 ,78 };
	ST_Init(ST, 10);//ʵ��������11��Ԫ�ؿռ�
	memcpy(ST.elem + 1, A, sizeof(A));
	ST_print(ST);
	//InsertSort(ST.elem,10);
	//MidInsertSort(ST.elem,10);
	ShellSort(ST.elem, 10);
	ST_print(ST);
	
}