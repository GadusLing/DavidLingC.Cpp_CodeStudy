#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"


//�ѳ�ʼ��
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->arr);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}

// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

//�������ӽڵ�λ��
void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//���ϵ���
void adjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])//���Ǵ�ѣ����С�ѾͰѴ˴� > ���� <
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity ? 2 * hp->capacity : 4;
		HPDataType* temp = (HPDataType*)realloc(hp->arr, sizeof(HPDataType) * newCapacity);
		if (!temp)
		{
			perror("realloc");
			exit(1);
		}
		hp->arr = temp;
		hp->capacity = newCapacity;
	}
	hp->arr[hp->size] = x;
	adjustUp(hp->arr, hp->size);
	++hp->size;
}

//���µ���
void adjustDown(HPDataType* arr, int parent, int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// ��(��)��ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->arr[0], &hp->arr[hp->size - 1]);
	--hp->size;
	adjustDown(hp->arr, 0, hp->size);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->arr[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

//������
void HeapSort(int* arr, int n)
{
	for (int u = 0; u < n; u++)//���ϵ����㷨����
	{
		adjustUp(arr, u);
	}

	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)//���µ����㷨����
	//{
	//	adjustDown(arr, i, n);
	//}

	for (int j = n; j > 1; j--)
	{
		Swap(&arr[0], &arr[j - 1]);
		adjustDown(arr, 0, j- 1);
	}
}
