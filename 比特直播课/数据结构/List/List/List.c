#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->prev = phead->next = NULL;

	return phead;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{

}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* Temp = pHead->next;
	while (Temp)
	{
		printf("%d -> ", Temp->data);
		Temp = Temp->next;
	}
	printf("NULL");
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = ListCreate();
	newNode->data = x;
	ListNode* Temp = pHead;
	while (Temp->next)
	{
		Temp = Temp->next;
	}
	newNode->prev = Temp;
	Temp->next = newNode;
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (!pHead->next)
	{
		return;
	}
	ListNode* Temp = pHead;
	while (Temp->next)
	{
		Temp = Temp->next;
	}
	Temp->prev->next = NULL;
	free(Temp);
	Temp = NULL;
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* newNode = ListCreate();
	newNode->data = x;
	ListNode* Temp = pHead;
	newNode->prev = Temp;
	newNode->next = Temp->next;
	if (Temp->next)
	{
		Temp->next->prev = newNode;
	}
	Temp->next = newNode;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	if (!pHead->next)
	{
		return;
	}

	ListNode* Del = pHead->next;
	pHead->next = Del->next;
	if (pHead->next)
	{
		Del->next->prev = pHead;
	}
	free(Del);
	Del = NULL;
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	if (!pHead->next)
	{
		return NULL;
	}
	ListNode* Temp = pHead->next;
	while(Temp != phead)


}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{

}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{

}



