#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void test()
{
	//手动构造一个链表
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

}

int main()
{

	return 0;
}