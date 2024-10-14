#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

// �������ӡ
void SLTprint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

// ��̬����һ���ڵ�
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("malloc fail\n");
		exit(1);
	}
	node->data = x;
	node->next = NULL;

	return node;
}

// ������β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next)//�ȼ��� ptail->next != NULL
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

// ������ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//newnode *pphead
	newnode->next = *pphead;
	*pphead = newnode;
}

// ������βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//ֻ��һ���ڵ�ʱ
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

// ������ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	
}

