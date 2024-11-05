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

	HeapSort(a, sizeof(a) / sizeof(HPDataType));//������a��������

	for (int i = 0; i < sizeof(a) / sizeof(HPDataType); i++)//�������������
	{
		printf("%d ", a[i]);
	}

	HeapDestory(&S);//���ٶ�

}

void CreateNDate()
{
	// ������
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	printf("������K: ");
	scanf("%d", &k);

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		exit(1);
	}

	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc error");
		exit(2);
	}

	for (int i = 0; i < k; i++)
	{

	}

}

int main()
{
	//test1();
	CreateNDate();
	int k = 0;
	void PrintTopK(int k);


	return 0;
}
