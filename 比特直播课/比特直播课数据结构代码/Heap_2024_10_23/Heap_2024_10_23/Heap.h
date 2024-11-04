#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr; //�������ݵ�����
	int size; //��Ч�����ݸ���
	int capacity; //�ѵ�����
}Heap;

//�ѳ�ʼ��
void HeapInit(Heap* hp);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);