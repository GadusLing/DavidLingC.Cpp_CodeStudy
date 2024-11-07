#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//打印顺序表内容
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//核对空间
void SLcheckCapacity(SL* ps)
{
	//空间不够我得继续申请空间出来
	if (ps->size == ps->capacity)
	{
		SLDataType newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
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
	//++(ps->size);和上面一条合并,++直接放到size后面
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLcheckCapacity(ps);
	//直接头插
	//数据整体向后挪动一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps && ps->size > 0);
	ps->size--;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps && ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//顺序表查找
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;//找到了，返回下标
		}
	}
	return -1;//没找到，返回无效下标
}

//顺序表在pos位置前插入x
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLcheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//顺序表删除pos位置的值
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}














