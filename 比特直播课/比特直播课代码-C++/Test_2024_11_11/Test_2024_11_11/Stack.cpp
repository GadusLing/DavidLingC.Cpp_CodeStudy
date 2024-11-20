#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"


void Stack::Init(int n)//需要指定一下类域哦，Stack:: 不然找不到，会报错 “未声明的标识符”
{
	_arr = (int*)malloc(sizeof(int) * n);
	if (nullptr == _arr)
	{
		perror("malloc申请空间失败");
		return;
	}
	_capacity = n;
	_top = 0;
}

void Stack::Destroy(Stack* ps)
{
	assert(ps);
	if (ps->_arr != NULL)
	{
		free(ps->_arr);
	}
	ps->_arr = NULL;
	ps->_top = ps->_capacity = 0;
}

void Stack::Push(Stack* ps, int x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newCapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		int* temp = (int*)realloc(ps->_arr, newCapacity * sizeof(int));
		assert(temp);
		ps->_arr = temp;
		ps->_capacity = newCapacity;
	}
	ps->_arr[ps->_top++] = x;
}

int Stack::Top(Stack* ps)
{
	assert(ps);
	assert(ps->_top > 0);
	return ps->_arr[ps->_top - 1];
}

//...






