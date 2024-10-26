#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"



// 动态申请一个节点
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

// 单链表打印
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

// 单链表尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)//链表为空时
	{
		*pphead = newnode;
	}
	else//链表非空时
	{
		SLTNode* ptail = *pphead;
		while (ptail->next)//等价于 ptail->next != NULL
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}

// 单链表头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	//newnode *pphead
	newnode->next = *pphead;
	*pphead = newnode;
}

// 单链表尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	//只有一个节点时
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

// 单链表头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// 单链表查找
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

// 单链表在pos位置之后插入x
void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);// 检查 pos 是否为 NULL

	SLTNode* newnode = SLTBuyNode(x);
	if (newnode == NULL)
	{
		perror("SLTBuyNode failed");
		return;
	}
	newnode->next = pos->next;
	pos->next = newnode;       
}

// 单链表删除pos位置之后的值
void SListEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next); 

	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

// 在pos的前面插入
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

// 删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	SLTNode* pcur = *pphead;
	
	if (pcur == pos)// 如果要删除的是头节点
	{
		*pphead = pcur->next; // 更新头节点
		free(pcur);           // 释放头节点
		return;
	}

	SLTNode* prev = NULL;
	while (pcur != NULL && pcur != pos)// 查找 pos 的前驱节点
	{
		prev = pcur;
		pcur = pcur->next;
	}

	if (pcur == pos)// 如果找到了要删除的节点
	{
		prev->next = pcur->next; // 跳过要删除的节点
		free(pcur);              // 释放 pos
	}
}

//销毁
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




