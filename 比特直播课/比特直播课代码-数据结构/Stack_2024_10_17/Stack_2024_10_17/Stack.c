#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

// ��ʼ��ջ
void STInit(ST* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

// ����ջ
void STDestroy(ST* ps)
{
	assert(ps);
	if (ps->arr != NULL)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

// ��ջ
void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* temp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));
		assert(temp);
		ps->arr = temp;
		ps->capacity = newCapacity;
	}
	ps->arr[ps->top++] = x;
}

// ��ջ
void STPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

// ȡջ��Ԫ��
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->arr[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

// �ж�ջ�Ƿ�Ϊ��
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}