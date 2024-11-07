#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr; //储存数据的数组
	int size; //有效的数据个数
	int capacity; //堆的容量
}Heap;

//堆初始化
void HeapInit(Heap* hp);

// 堆的销毁
void HeapDestory(Heap* hp);

// 堆的插入
void HeapPush(Heap* hp, HPDataType x);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HPDataType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
int HeapEmpty(Heap* hp);

//交换父子节点位置
void Swap(int* x, int* y);

//向上调整
void adjustUp(HPDataType* arr, int child);

//向下调整
void adjustDown(HPDataType* arr, int parent, int size);

//堆排序
void HeapSort(int* arr, int n);