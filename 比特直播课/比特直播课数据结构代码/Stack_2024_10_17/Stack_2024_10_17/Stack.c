#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

// ��ʼ��ջ
void STInit(ST* ps)
{
	assert(ps);
	ps->top = ps->capacity = 0;
}

// ����ջ
void STDestroy(ST* ps)
{
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
	if (ps->top = ps->capacity)
	{
		STDataType* tmp = 
	}
}

// ��ջ
void STPop(ST* ps)
{

}

// ȡջ��Ԫ��
STDataType STTop(ST* ps)
{

}

// ��ȡջ����ЧԪ�ظ���
int STSize(ST* ps)
{

}

// �ж�ջ�Ƿ�Ϊ��
bool STEmpty(ST* ps)
{

}