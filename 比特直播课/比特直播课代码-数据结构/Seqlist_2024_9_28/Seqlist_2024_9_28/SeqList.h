#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h> 

//#define N 1000
//typedef int SLDataType;
////静态顺序表
//typedef struct SeqList
//{
//	SLDataType arr[N];
//	int size;//有效数据个数
//}SL;

//typedef struct SeqList SL  //单独写出来也行


//动态顺序表
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;//有效数据个数
	int capacity;//容量大小
}SL;

//顺序表的初始化
void SLInit(SL* ps);

//销毁
void SLDestroy(SL* ps);

//打印
void SLPrint(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//头插
void SLPushFront(SL* ps, SLDataType x);

//尾删
void SLPopBack(SL* ps);

//头删
void SLPopFront(SL* ps);

//顺序表查找
int SLFind(SL* ps, SLDataType x);

//顺序表在pos位置插入x
void SLInsert(SL* ps, int pos, SLDataType x);

//顺序表删除pos位置的值
void SLErase(SL* ps, int pos);