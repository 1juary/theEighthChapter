#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef int ElemType;
typedef struct {
	ElemType* elem;
	int TableLenth;
}SSTable;

//数组初始化
void ElemType_Init(SSTable& ST, int len) {
	ST.TableLenth = len;
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLenth);
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLenth; i++) {
		ST.elem[i] = rand() % 100;
	}
}
//打印数组
void ST_Print(SSTable ST) {
	for (int i = 0; i < ST.TableLenth; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}

void swap(ElemType& i, ElemType& j) {
	ElemType temp;
	temp = i;
	i = j;
	j = temp;
};


//返回k下标
int partition(ElemType* elem, int left,int right) {
	int k, i;
	k = i = left;
	for (k, i; i < right; i++) {
		if (elem[i] < elem[right]) {
			swap(elem[k], elem[i]);
			k++;
		}
	}
	swap(elem[k], elem[right]);
	return k;
}


//挖坑法，partition
int partition_1(ElemType *elem,int low,int high) {
	ElemType pivot = elem[low];
	while (low < high) {
		while (low < high && elem[high] >= pivot) {
			--high;
			elem[low] = elem[high];
		}
		while (low < high && elem[low] <= pivot) {
			++low;
			elem[high] = elem[low];
		}
	}
	elem[low] = pivot;
	return low;
}
//快排函数
void QuickSort(ElemType *elem, int low, int high) {
	if (low < high) {
		int pivotops = partition(elem, low, high);
		QuickSort(elem, low, pivotops - 1);
		QuickSort(elem, pivotops + 1, high);
	}
}
void QuickSort_1(ElemType* elem, int low, int high) {
	if (low < high) {
		int pivotops = partition_1(elem, low, high);
		QuickSort_1(elem, low, pivotops - 1);
		QuickSort_1(elem, pivotops + 1, high);
	}
}
int main() {
	SSTable ST;
	int pos;
	ElemType_Init(ST, 10);
	ST_Print(ST);
	//pos = partition(ST.elem, 0, 9);
	QuickSort(ST.elem, 0, 9);
	ST_Print(ST);
	QuickSort_1(ST.elem, 0, 9);
	ST_Print(ST);

}