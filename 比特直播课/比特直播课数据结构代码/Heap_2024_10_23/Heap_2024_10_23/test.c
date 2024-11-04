#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"


void test1()
{
	HPDataType a[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap S;
	HeapInit(&S);//��ʼ����

	HeapPush(&S, 1);//�ѵĲ���
	HeapPop(&S);//ɾ���Ѷ�����
	HeapTop(&S);//ȡ�Ѷ�����

	HeapSort(a, sizeof(a) / sizeof(int));//������a��������

	for (int i = 0; i < S.size; i++)//�������������
	{
		printf("%d ", S.arr[i]);
	}

	HeapDestory(&S);//���ٶ�

}

int main()
{
	test1();

	return 0;
}
