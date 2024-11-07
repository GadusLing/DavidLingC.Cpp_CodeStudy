#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"



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

// ������β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)//����Ϊ��ʱ
	{
		*pphead = newnode;
	}
	else//����ǿ�ʱ
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

// ���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	assert(plist);
	SLTNode* find = plist;
	while (find)
	{
		if (find->data == x)
		{
			return find;
		}
		find = find->next;
	}
	return NULL;
}

// ��������posλ��֮�����x
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);// ��� pos �Ƿ�Ϊ NULL

	SLTNode* newnode = SLTBuyNode(x);
	if (newnode == NULL)
	{
		perror("SLTBuyNode failed");
		return;
	}
	newnode->next = pos->next;
	pos->next = newnode;       
}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next); 

	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

// ��pos��ǰ�����
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && pos);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
		return;
	}

	SLTNode* newnode = SLTBuyNode(x);
	if (newnode == NULL)
	{
		perror("SLTBuyNode failed");
		return;
	}

	SLTNode* prev = *pphead;
	while (prev->next != pos)
	{
		prev = prev->next;
	}
	newnode->next = pos;
	prev->next = newnode;
}

// ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	SLTNode* pcur = *pphead;
	
	if (pcur == pos)// ���Ҫɾ������ͷ�ڵ�
	{
		*pphead = pcur->next; // ����ͷ�ڵ�
		free(pcur);           // �ͷ�ͷ�ڵ�
		return;
	}

	SLTNode* prev = NULL;
	while (pcur != NULL && pcur != pos)// ���� pos ��ǰ���ڵ�
	{
		prev = pcur;
		pcur = pcur->next;
	}

	if (pcur == pos)// ����ҵ���Ҫɾ���Ľڵ�
	{
		prev->next = pcur->next; // ����Ҫɾ���Ľڵ�
		free(pcur);              // �ͷ� pos
	}
}

//����
void SLTDestroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;

	while (pcur != NULL)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}

	*pphead = NULL;
}




