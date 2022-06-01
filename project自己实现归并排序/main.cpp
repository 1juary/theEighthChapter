#include <stdio.h>
#include <stdlib.h>

#define N 7
typedef int ElemType;

void Merge(ElemType A[], int low, int mid, int high) {
	ElemType B [N];                                          //辅助数组，减少操作次数。但直接定义在函数中空间复杂度>O(1)
	int i,j, k;                                             //涉及递归Merge，在main()函数中定义B
	                                                       //使用归并函数时调用地址可以进一步减少空间使用率
	for (k = low; k <= high; k++) {
		B[k] = A[k];                                      //复刻辅助数组
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (B[i] <= B[j])
			A[k] = B[i++];
		else A[k] = B[j++];
	}
	while (i <= mid)
		A[k++] = B[i++];
	while (j <= high)
		A[k++] = B[j++];
}

void MergeSort(ElemType A[], int low, int high)//递归分割
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);                         //合并
	}
}

void print(int* a)
{
	for (int i = 0; i < N; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

int main()
{
	int A[7] = { 49,38,65,97,76,13,27 };//数组，7个元素
	MergeSort(A, 0, 6);
	print(A);
	system("pause");
}