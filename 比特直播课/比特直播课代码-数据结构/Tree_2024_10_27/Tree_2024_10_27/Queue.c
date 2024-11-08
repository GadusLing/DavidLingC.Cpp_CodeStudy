#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"


// ��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// ���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* del = pq->phead;
	while (del)
	{
		QNode* temp = del->next;
		free(del);
		del = temp;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// ����У���β��
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (!newNode)
	{
		perror("malloc");
		exit(1);
	}
	newNode->val = x;
	newNode->next = NULL;

	if(!pq->phead)
	{
		pq->phead = pq->ptail = newNode;
	}
	else
	{
		pq->ptail->next = newNode;
		pq->ptail = newNode;
	}
	pq->size++;
}

// �����У���ͷ��
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (!pq->phead->next)//ֻ��һ���ڵ�ʱ
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* temp = pq->phead->next;
		free(pq->phead);
		pq->phead = temp;
	}
	pq->size--;
}

// ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->phead->val;
}

// ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->ptail->val;
}

// �����п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

// ������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	//assert(pq);
	//int size = 0;
	//QNode* pcur = pq->phead;
	//while (pcur)
	//{
	//	size++;
	//	pcur = pcur->next;
	//}
	//return size;
	return pq->size;
}









