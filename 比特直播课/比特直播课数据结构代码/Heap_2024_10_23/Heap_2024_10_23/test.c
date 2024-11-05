#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"


void test1()
{
	HPDataType a[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap S;
	HeapInit(&S);//初始化堆

	HeapPush(&S, 1);//堆的插入
	HeapPop(&S);//删除堆顶数据
	HeapTop(&S);//取堆顶数据

	HeapSort(a, sizeof(a) / sizeof(HPDataType));//堆数组a进行排序

	for (int i = 0; i < sizeof(a) / sizeof(HPDataType); i++)//排完序后进行输出
	{
		printf("%d ", a[i]);
	}

	HeapDestory(&S);//销毁堆

}

void CreateNDate()
{
	// 造数据
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
	printf("请输入K: ");
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
