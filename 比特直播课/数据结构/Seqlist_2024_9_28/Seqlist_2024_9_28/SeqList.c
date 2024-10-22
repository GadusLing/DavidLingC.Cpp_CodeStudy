#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//��ʼ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//��ӡ˳�������
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//����
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//�˶Կռ�
void SLcheckCapacity(SL* ps)
{
	//�ռ䲻���ҵü�������ռ����
	if (ps->size == ps->capacity)
	{
		SLDataType newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//�ռ䲻�� ���ӿռ� 2������
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

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	////����Դ���ָ������ķ�ʽ
	//if (ps == NULL)
	//{
	//	return;
	//}
	// �ֱ��Ĵ���ʽ
	assert(ps);
	
	SLcheckCapacity(ps);

	ps->arr[ps->size++] = x;
	//++(ps->size);������һ���ϲ�,++ֱ�ӷŵ�size����
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLcheckCapacity(ps);
	//ֱ��ͷ��
	//�����������Ų��һλ
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps && ps->size > 0);
	ps->size--;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps && ps->size > 0);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//˳������
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;//�ҵ��ˣ������±�
		}
	}
	return -1;//û�ҵ���������Ч�±�
}

//˳�����posλ��ǰ����x
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

//˳���ɾ��posλ�õ�ֵ
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














