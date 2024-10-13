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

//Î²²å
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//Í·²å
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//Î²É¾
void SLTPopBack(SLTNode** pphead);
//Í·É¾
void SLTPopFront(SLTNode** pphead);


