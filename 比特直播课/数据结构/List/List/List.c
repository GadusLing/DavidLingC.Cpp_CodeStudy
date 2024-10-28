#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->prev = phead->next = NULL;

	return phead;
}

// ˫����������
void ListDestory(ListNode* pHead)
{

}

// ˫�������ӡ
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

// ˫������β��
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

// ˫������βɾ
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

// ˫������ͷ��
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

// ˫������ͷɾ
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

// ˫���������
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

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{

}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{

}



