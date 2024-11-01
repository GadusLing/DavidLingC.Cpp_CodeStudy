#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"


// 初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

// 销毁队列
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

// 入队列（队尾）
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

// 出队列（队头）
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (!pq->phead->next)//只有一个节点时
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

// 取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->phead->val;
}

// 取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->ptail->val;
}

// 队列判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

// 队列有效元素个数
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









