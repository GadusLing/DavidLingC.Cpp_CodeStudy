#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

// 初始化栈
void STInit(ST* ps)
{
	assert(ps);
	ps->top = ps->capacity = 0;
}

// 销毁栈
void STDestroy(ST* ps)
{
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
	if (ps->top = ps->capacity)
	{
		STDataType* tmp = 
	}
}

// 出栈
void STPop(ST* ps)
{

}

// 取栈顶元素
STDataType STTop(ST* ps)
{

}

// 获取栈中有效元素个数
int STSize(ST* ps)
{

}

// 判断栈是否为空
bool STEmpty(ST* ps)
{

}