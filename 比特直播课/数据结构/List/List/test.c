#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

// 测试函数
void TestList() {
    // 创建链表
    ListNode* pHead = ListCreate();

    // 测试尾插
    ListPushBack(pHead, 10);
    ListPushBack(pHead, 20);
    ListPushBack(pHead, 30);
    printf("After pushing back 10, 20, 30:\n");
    ListPrint(pHead);  // 应该输出: 10 -> 20 -> 30 -> NULL
    printf("\n");

    // 测试头插
    ListPushFront(pHead, 5);
    printf("After pushing front 5:\n");
    ListPrint(pHead);  // 应该输出: 5 -> 10 -> 20 -> 30 -> NULL
    printf("\n");

    // 测试尾删
    ListPopBack(pHead);
    printf("After popping back:\n");
    ListPrint(pHead);  // 应该输出: 5 -> 10 -> 20 -> NULL
    printf("\n");

    // 测试头删
    ListPopFront(pHead);
    printf("After popping front:\n");
    ListPrint(pHead);  // 应该输出: 10 -> 20 -> NULL
    printf("\n");

    // 测试查找
    ListNode* foundNode = ListFind(pHead, 20);
    if (foundNode) 
    {
        printf("Found node with value: %d\n", foundNode->data);  // 应该输出: Found node with value: 20
    }
    else 
    {
        printf("Node not found.\n");
    }

    // 测试插入
    ListInsert(pHead->next, 15);  // 在 10 前面插入 15
    printf("After inserting 15 before 20:\n");
    ListPrint(pHead);  // 应该输出: 10 -> 15 -> 20 -> NULL
    printf("\n");

    // 测试删除
    ListErase(pHead->next);  // 删除节点 15
    printf("After erasing 15:\n");
    ListPrint(pHead);  // 应该输出: 10 -> 20 -> NULL
    printf("\n");

    // 测试链表销毁
    ListDestory(pHead);  // 清理内存
}

int main() 
{
    TestList();
    return 0;
}
