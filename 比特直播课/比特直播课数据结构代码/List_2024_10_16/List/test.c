#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

void TestList()
{
    // 1. 创建链表
    ListNode* pHead = ListCreate();
    assert(pHead != NULL);
    printf("链表创建成功。\n");

    // 2. 尾部插入
    ListPushBack(pHead, 1);
    ListPushBack(pHead, 2);
    ListPushBack(pHead, 3);
    printf("尾部插入 1, 2, 3:\n");
    ListPrint(pHead);  // 应该输出 1 -> 2 -> 3 -> 

    // 3. 头部插入
    ListPushFront(pHead, 0);
    printf("头部插入 0:\n");
    ListPrint(pHead);  // 应该输出 0 -> 1 -> 2 -> 3 -> 

    // 4. 查找元素
    ListNode* foundNode = ListFind(pHead, 2);
    assert(foundNode != NULL && foundNode->data == 2);
    printf("找到元素 2。\n");

    // 5. 删除尾部元素
    ListPopBack(pHead);
    printf("删除尾部元素后:\n");
    ListPrint(pHead);  // 应该输出 0 -> 1 -> 2 -> 

    // 6. 删除头部元素
    ListPopFront(pHead);
    printf("删除头部元素后:\n");
    ListPrint(pHead);  // 应该输出 1 -> 2 -> 

    // 7. 在指定位置插入元素
    ListInsert(pHead->next, 1);  // 在位置 1 后插入元素 1
    printf("在位置 1 后插入元素 1:\n");
    ListPrint(pHead);  // 应该输出 1 -> 1 -> 2 -> 

    // 8. 删除指定位置元素
    ListErase(pHead->next);  // 删除位置 1 的元素
    printf("删除位置 1 的元素后:\n");
    ListPrint(pHead);  // 应该输出 1 -> 2 -> 

    // 9. 销毁链表
    ListDestory(pHead);
    printf("链表销毁成功。\n");
}

int main()
{
    TestList();  // 运行测试
    return 0;
}
