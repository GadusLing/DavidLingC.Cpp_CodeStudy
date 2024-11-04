#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"


//堆初始化
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->arr);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

//交换父子节点位置
void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//向上调整
void adjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])//这是大堆，如果小堆就把此处 > 换成 <
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

// 堆的插入
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

//向下调整
void adjustDown(HPDataType* arr, int parent, int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child] > arr[child + 1])
		{
			child++;
		}
		if (arr[child] < arr[parent])
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

// 堆(顶)的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	Swap(&hp->arr[0], &hp->arr[hp->size - 1]);
	--hp->size;
	adjustDown(hp->arr, 0, hp->size);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->arr[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void HeapSort(int* arr, int n)
{

}
