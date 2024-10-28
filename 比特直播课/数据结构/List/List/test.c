#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

// ���Ժ���
void TestList() {
    // ��������
    ListNode* pHead = ListCreate();

    // ����β��
    ListPushBack(pHead, 10);
    ListPushBack(pHead, 20);
    ListPushBack(pHead, 30);
    printf("After pushing back 10, 20, 30:\n");
    ListPrint(pHead);  // Ӧ�����: 10 -> 20 -> 30 -> NULL
    printf("\n");

    // ����ͷ��
    ListPushFront(pHead, 5);
    printf("After pushing front 5:\n");
    ListPrint(pHead);  // Ӧ�����: 5 -> 10 -> 20 -> 30 -> NULL
    printf("\n");

    // ����βɾ
    ListPopBack(pHead);
    printf("After popping back:\n");
    ListPrint(pHead);  // Ӧ�����: 5 -> 10 -> 20 -> NULL
    printf("\n");

    // ����ͷɾ
    ListPopFront(pHead);
    printf("After popping front:\n");
    ListPrint(pHead);  // Ӧ�����: 10 -> 20 -> NULL
    printf("\n");

    // ���Բ���
    ListNode* foundNode = ListFind(pHead, 20);
    if (foundNode) 
    {
        printf("Found node with value: %d\n", foundNode->data);  // Ӧ�����: Found node with value: 20
    }
    else 
    {
        printf("Node not found.\n");
    }

    // ���Բ���
    ListInsert(pHead->next, 15);  // �� 10 ǰ����� 15
    printf("After inserting 15 before 20:\n");
    ListPrint(pHead);  // Ӧ�����: 10 -> 15 -> 20 -> NULL
    printf("\n");

    // ����ɾ��
    ListErase(pHead->next);  // ɾ���ڵ� 15
    printf("After erasing 15:\n");
    ListPrint(pHead);  // Ӧ�����: 10 -> 20 -> NULL
    printf("\n");

    // ������������
    ListDestory(pHead);  // �����ڴ�
}

int main() 
{
    TestList();
    return 0;
}
