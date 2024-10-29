#define _CRT_SECURE_NO_WARNINGS

#include "List.h"


//����һ��ռ���x
ListNode* buyNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (!node)
	{
		perror("malloc");
	}
	node->data = x;
	node->prev = node->next = node;

	return node;
}

// �������������ͷ���(�ƽڵ�).
ListNode* ListCreate()
{
	ListNode* phead = buyNode(-1);
	return phead;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	ListNode* Des = pHead->next;
	while (Des != pHead)
	{
		ListNode* Temp = Des->next;
		free(Des);
		Des = Temp;
	}
	free(pHead);
	pHead = NULL;
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* Temp = pHead->next;
	while (Temp != pHead)
	{
		printf("%d -> ", Temp->data);
		Temp = Temp->next;
	}
	printf("\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = buyNode(x);
	newNode->prev = pHead->prev;
	newNode->next = pHead;
	pHead->prev->next = newNode;
	pHead->prev = newNode;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (pHead->next == pHead)
	{
		return;
	}
	ListNode* Del = pHead->prev;
	Del->prev->next = pHead;
	pHead->prev = Del->prev;
	free(Del);
	Del = NULL;
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = buyNode(x);
	newNode->prev = pHead;
	newNode->next = pHead->next;
	pHead->next->prev = newNode;
	pHead->next = newNode;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	if (pHead->next == pHead)
	{
		return;
	}
	ListNode* Del = pHead->next;
	Del->next->prev = pHead;
	pHead->next = Del->next;
	free(Del);
	Del = NULL;
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* Temp = pHead->next;
	while (Temp != pHead)
	{
		if (Temp->data == x)
		{
			return Temp;
		}
		Temp = Temp->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newNode = buyNode(x);
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	if (pos->next == pos)
	{
		return;
	}
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}



