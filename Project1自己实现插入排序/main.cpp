#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int ElemType;
typedef struct {
	ElemType* elem;                      //����ָ��
	int TableLen;
}SSTable;