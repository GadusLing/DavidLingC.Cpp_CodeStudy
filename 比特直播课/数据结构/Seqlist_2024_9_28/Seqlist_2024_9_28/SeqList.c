#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//��ʼ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SLcheckCapacity(SL* ps)
{
	//�ռ䲻���ҵü�������ռ����
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
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
	//++ps->size;������һ���ϲ�,++ֱ�ӷŵ�size����
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLcheckCapacity(ps);
	//ֱ��ͷ��
	//�����������Ų��һλ

}