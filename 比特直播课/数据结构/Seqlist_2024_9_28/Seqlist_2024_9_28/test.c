#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

void SLTest()
{
	//SL sl;
	//SLInit(&sl);
	////SLPushBack(&sl, 1);
	////SLPushBack(&sl, 2);
	////SLPushBack(&sl, 3);
	////SLPushBack(&sl, 4);
	////SLPushBack(&sl, 5);
	//////SLPushBack(NULL, 1);

	////SLPushFront(&sl, 1);
	////SLPushFront(&sl, 2);
	////SLPushFront(&sl, 3);
	////SLPushFront(&sl, 4);
	////SLPushFront(&sl, 5);

	////SLPopBack(&sl);
	////SLPrint(&sl);
	////SLPopBack(&sl);
	////SLPrint(&sl);
	////SLPopBack(&sl);
	////SLPrint(&sl);
	////SLPopBack(&sl);
	////SLPrint(&sl);
	////SLPopBack(&sl);
	////SLPrint(&sl);
	////SLPopBack(&sl);

	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);
	//SLPrint(&sl);
	//SLPopFront(&sl);

}

void SLTest2()
{
	//SL sl;
	//SLInit(&sl);
	//SLPushBack(&sl, 1);
	//SLPushBack(&sl, 2);
	//SLPushBack(&sl, 3);
	//SLPushBack(&sl, 4);
	//SLPushBack(&sl, 5);
	////SLPushBack(NULL, 1);

	////int ret = SLFind(&sl, 6);
	////if (ret < 0)
	////{
	////	printf("未找到目标!\n");
	////}
	////else
	////{
	////	printf("找到目标,下标为%d\n", ret);
	////}

	//SLErase(&sl, 4);
	//SLPrint(&sl);
	//SLErase(&sl, 2);
	//SLPrint(&sl);
	//SLErase(&sl, 0);
	//SLPrint(&sl);
	//SLErase(&sl, 4);
	//SLPrint(&sl);

}

void SLTest3()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);

	SLDestroy(&sl);

}

int main()
{
	//SLTest();
	//SLTest2();
	SLTest3();

	return 0;
}