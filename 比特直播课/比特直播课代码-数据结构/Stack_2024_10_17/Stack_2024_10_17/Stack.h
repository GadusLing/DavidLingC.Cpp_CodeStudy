#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

// ջ�ṹ
typedef struct stack {
    STDataType* arr;   // ջ�����ݴ洢��
    int top;         // ջ������
    int capacity;    // ջ������
} ST;

// ��ʼ��ջ
void STInit(ST* ps);

// ����ջ
void STDestroy(ST* ps);

// ��ջ
void STPush(ST* ps, STDataType x);

// ��ջ
void STPop(ST* ps);

// ȡջ��Ԫ��
STDataType STTop(ST* ps);

// ��ȡջ����ЧԪ�ظ���
int STSize(ST* ps);

// �ж�ջ�Ƿ�Ϊ��
bool STEmpty(ST* ps);

