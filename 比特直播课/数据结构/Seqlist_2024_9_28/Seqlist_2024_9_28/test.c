#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

void SLTest()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	//SLPushBack(NULL, 1);
}

int main()
{
	SLTest();

	return 0;
}