#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* a;
	int size;      //已有数据个数
	int capacity;  //容量
}HP;

//初始化
void HeapInit(HP* php);
//插入
void HeapPush(HP* php, HeapDataType x);

//删除堆顶元素
void HeapPop(HP* php);

//销毁
void HeapDestory(HP* php);

//向上调整
void AdjustUp(HeapDataType* a, int child);
void AdjustDown(HeapDataType* a, int n);

//建堆
void HeapCreat(HP* php, HeapDataType* a, int len);
//堆排序
void HeapSort(HeapDataType* a, int n);
//打印
void Print(HP* php);
//取堆顶元素
HeapDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
