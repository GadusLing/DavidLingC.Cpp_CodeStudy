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
	//����k��С�Ķѿռ�����Ŵ�����������Ҫ��k��ֵ
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc error");
		exit(2);
	}
	//������������k�����ݴ��������
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	//�����ѽṹ
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		adjustDown(minHeap, i, k);
	}
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			adjustDown(minHeap, 0, k);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	fclose(fout);
}

int main()
{
	//test1();
	int k = 0;
	PrintTopK(k);


	return 0;
}
