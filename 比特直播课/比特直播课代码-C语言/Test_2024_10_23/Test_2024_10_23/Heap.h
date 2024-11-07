#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* a;
	int size;      //�������ݸ���
	int capacity;  //����
}HP;

//��ʼ��
void HeapInit(HP* php);
//����
void HeapPush(HP* php, HeapDataType x);

//ɾ���Ѷ�Ԫ��
void HeapPop(HP* php);

//����
void HeapDestory(HP* php);

//���ϵ���
void AdjustUp(HeapDataType* a, int child);
void AdjustDown(HeapDataType* a, int n);

//����
void HeapCreat(HP* php, HeapDataType* a, int len);
//������
void HeapSort(HeapDataType* a, int n);
//��ӡ
void Print(HP* php);
//ȡ�Ѷ�Ԫ��
HeapDataType HeapTop(HP* php);
int HeapSize(HP* php);
bool HeapEmpty(HP* php);
