#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SLcheckCapacity(SL* ps)
{
	//空间不够我得继续申请空间出来
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//空间不够 增加空间 2倍增容
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	////温柔对待空指针参数的方式
	//if (ps == NULL)
	//{
	//	return;
	//}
	// 粗暴的处理方式
	assert(ps);
	
	SLcheckCapacity(ps);

	ps->arr[ps->size++] = x;
	//++ps->size;和上面一条合并,++直接放到size后面
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLcheckCapacity(ps);
	//直接头插
	//数据整体向后挪动一位

}