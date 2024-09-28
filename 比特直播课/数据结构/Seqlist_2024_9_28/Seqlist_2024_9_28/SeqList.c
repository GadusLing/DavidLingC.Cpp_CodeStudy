#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}