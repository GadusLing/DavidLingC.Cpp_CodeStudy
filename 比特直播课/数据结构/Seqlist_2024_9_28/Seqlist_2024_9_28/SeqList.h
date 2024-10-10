#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h> 

#define N 1000
typedef int SLDataType;
////静态顺序表
//typedef struct SeqList
//{
//	SLDataType arr[N];
//	int size;//有效数据个数
//}SL;

//typedef struct SeqList SL


//动态顺序表
typedef struct SeqList
{
	SLDataType* arr;
	int size;//有效数据个数
	int capacity;//容量大小
}SL;

//顺序表的初始化
void SLInit(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//头插
void SLPushFront(SL* ps, SLDataType x);