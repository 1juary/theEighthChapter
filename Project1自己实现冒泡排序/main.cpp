#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef int Elemtype;
typedef struct {
	Elemtype* elem;
	int TableLenth;
}SSTable;


//��ʼ����
void ST_Init(SSTable &ST, int len) {
	ST.TableLenth = len;
	ST.elem = (Elemtype*)malloc(sizeof(Elemtype) * ST.TableLenth);      //��̬����
	int i;
	srand(time(NULL));
	for (i = 0; i < ST.TableLenth; i++) {
		ST.elem[i] = rand() % 100;
	}
} 

//��ӡ����
void ST_Print(SSTable ST) {
	for (int i = 0; i < ST.TableLenth; i++) {
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}
//��������
void swap(Elemtype &i, Elemtype &j) {
	Elemtype temp;
	temp = i;
	i = j;
	j = temp;
};
//��ĭ����
void BubbleSort (SSTable ST, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (ST.elem[i] > ST.elem[j]) {                      //�ݼ�����
				swap(ST.elem[i], ST.elem[j]);
			}
		}
	}
}

//�Ľ���ĭ����
void BubbleSort_1(SSTable ST, int n) {
	int i, j, flag;                                            //�ڱ�
	for (i = 0; i < ST.TableLenth; i++) {
		flag = 0;                                             //��һ��ѭ����ʼʱ����
		for (j = 0; j < ST.TableLenth; j++) {
			if (ST.elem[i] > ST.elem[j]) {
				swap(ST.elem[i], ST.elem[j]);
			}flag = 1;                                        //flag = 1��˵����������
		}
		if (0 == flag) {
			break;                                           //����һ��û�н��뽻����˵���Ѿ�˳��
		}                                                   // ���Լ���һ���ֱȽ�
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