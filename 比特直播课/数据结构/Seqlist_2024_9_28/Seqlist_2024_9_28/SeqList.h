#pragma once
#include <stdio.h>

#define N 1000
typedef char SLDataType;
////��̬˳���
//typedef struct SeqList
//{
//	SLDataType arr[N];
//	int size;//��Ч���ݸ���
//}SL;

//typedef struct SeqList SL



//��̬˳���
typedef struct SeqList
{
	SLDataType* arr;
	int size;//��Ч���ݸ���
	int capacity;//������С
}SL;

//˳���ĳ�ʼ��
void SLInit(SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	ps->arr[ps->size++]
}