#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ���������������
//typedef int QDataType;
typedef struct BinaryTreeNode* QDataType;

// ���нڵ�ṹ
typedef struct QueueNode 
{
    QDataType val;
    struct QueueNode* next;
} QNode;

// ���нṹ
typedef struct Queue 
{
    QNode* phead;
    QNode* ptail;
    int size;
} Queue;

// ��ʼ������
void QueueInit(Queue* pq);

// ���ٶ���
void QueueDestroy(Queue* pq);

// ����У���β��
void QueuePush(Queue* pq, QDataType x);

// �����У���ͷ��
void QueuePop(Queue* pq);

// ȡ��ͷ����
QDataType QueueFront(Queue* pq);

// ȡ��β����
QDataType QueueBack(Queue* pq);

// �����п�
bool QueueEmpty(Queue* pq);

// ������ЧԪ�ظ���
int QueueSize(Queue* pq);