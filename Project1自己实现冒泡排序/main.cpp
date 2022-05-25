#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef int Elemtype;
typedef struct {
	Elemtype* elem;
	int TableLenth;
}SSTable;


//初始化表
void ST_Init(SSTable &ST, int len) {
	ST.TableLenth = len;
	ST.elem = (Elemtype*)malloc(sizeof(Elemtype) * ST.TableLenth);      //动态数组
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLenth; i++) {
		ST.elem[i] = rand() % 100;
	}
} 

//打印数组
void ST_Print(SSTable ST) {
	for (int i = 0; i < ST.TableLenth; i++) {
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
//交换函数
void swap(Elemtype &i, Elemtype &j) {
	Elemtype temp;
	temp = i;
	i = j;
	j = temp;
};
//泡沫排序
void BubbleSort (SSTable ST, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (ST.elem[i] > ST.elem[j]) {                      //递减排序
				swap(ST.elem[i], ST.elem[j]);
			}
		}
	}
}

//改进泡沫排序
void BubbleSort_1(SSTable ST, int n) {
	int i, j, flag;                                            //哨兵
	for (i = 0; i < ST.TableLenth; i++) {
		flag = 0;                                             //下一轮循环开始时置零
		for (j = 0; j < ST.TableLenth; j++) {
			if (ST.elem[i] > ST.elem[j]) {
				swap(ST.elem[i], ST.elem[j]);
			}flag = 1;                                        //flag = 1，说明产生交换
		}
		if (0 == flag) {
			break;                                           //当下一轮没有进入交换，说明已经顺序
		}                                                   // 可以减少一部分比较
	}
	
}
int main() {
	SSTable ST;
	Elemtype A[10] = { 64,94,95,79,69,84,18,22,12,78 };
	ST_Init(ST, 10);
	memcpy(ST.elem, A, sizeof(A));
	ST_Print(ST);
	BubbleSort(ST, ST.TableLenth);
	ST_Print(ST);

}