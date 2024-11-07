#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

// 初始化栈
void STInit(ST* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}

// 销毁栈
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

// 入栈
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

// 出栈
void STPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

// 取栈顶元素
STDataType STTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->arr[ps->top - 1];
}

// 获取栈中有效元素个数
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

// 判断栈是否为空
bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}