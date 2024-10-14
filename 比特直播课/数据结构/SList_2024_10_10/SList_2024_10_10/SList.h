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

// �������ӡ
void SLTprint(SLTNode* phead);
// ��̬����һ���ڵ�
SLTNode* SLTBuyNode(SLTDataType x);
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);


