#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SLTprint(SLTNode* phead);

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);


