#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

//void test()
//{
//	//手动构造一个链表
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//
//	//存data
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	
//	//链式链接next
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	SLTNode* plist = node1;
//	SLTprint(plist);
//}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"

// 测试函数
void TestSList()
{
    SLTNode* head = NULL; // 初始化链表头指针

    // 测试尾插
    SLTPushBack(&head, 1);
    SLTPushBack(&head, 2);
    SLTPushBack(&head, 3);

    printf("测试尾插: ");
    SLTprint(head); // 应该输出: 1 -> 2 -> 3 -> NULL

    // 测试头插
    SLTPushFront(&head, 0);
    printf("测试头插: ");
    SLTprint(head); // 应该输出: 0 -> 1 -> 2 -> 3 -> NULL

    // 测试尾删
    SLTPopBack(&head);
    printf("测试尾删: ");
    SLTprint(head); // 应该输出: 0 -> 1 -> 2 -> NULL

    // 测试头删
    SLTPopFront(&head);
    printf("测试头删: ");
    SLTprint(head); // 应该输出: 1 -> 2 -> NULL

    // 测试查找
    SLTNode* found = SListFind(head, 1);
    printf("测试查找 1: %s\n", found ? "找到" : "未找到"); // 应该输出: 找到

    found = SListFind(head, 3);
    printf("测试查找 3: %s\n", found ? "找到" : "未找到"); // 应该输出: 未找到

    // 测试插入后
    SLTNode* pos = head; // 假设在第一个节点后插入
    SListInsertAfter(pos, 2);
    printf("测试在1后插入2: ");
    SLTprint(head); // 应该输出: 1 -> 2 -> 2 -> NULL

    // 测试删除后
    SListEraseAfter(pos);
    printf("测试删除1后: ");
    SLTprint(head); // 应该输出: 1 -> 2 -> NULL

    // 测试在特定位置插入
    SLTInsert(&head, head->next, 1);
    printf("测试在位置插入1: ");
    SLTprint(head); // 应该输出: 1 -> 1 -> 2 -> NULL

    // 测试删除特定位置
    SLTErase(&head, head->next);
    printf("测试删除指定位置: ");
    SLTprint(head); // 应该输出: 1 -> 2 -> NULL

    // 销毁链表
    SLTDestroy(&head);
    printf("销毁链表后: ");
    SLTprint(head); // 应该输出: NULL
}

int main()
{
    TestSList();
    return 0;
}
