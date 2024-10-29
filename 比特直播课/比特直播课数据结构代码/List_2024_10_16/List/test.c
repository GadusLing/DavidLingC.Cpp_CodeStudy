#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

void TestList()
{
    // 1. ��������
    ListNode* pHead = ListCreate();
    assert(pHead != NULL);
    printf("�������ɹ���\n");

    // 2. β������
    ListPushBack(pHead, 1);
    ListPushBack(pHead, 2);
    ListPushBack(pHead, 3);
    printf("β������ 1, 2, 3:\n");
    ListPrint(pHead);  // Ӧ����� 1 -> 2 -> 3 -> 

    // 3. ͷ������
    ListPushFront(pHead, 0);
    printf("ͷ������ 0:\n");
    ListPrint(pHead);  // Ӧ����� 0 -> 1 -> 2 -> 3 -> 

    // 4. ����Ԫ��
    ListNode* foundNode = ListFind(pHead, 2);
    assert(foundNode != NULL && foundNode->data == 2);
    printf("�ҵ�Ԫ�� 2��\n");

    // 5. ɾ��β��Ԫ��
    ListPopBack(pHead);
    printf("ɾ��β��Ԫ�غ�:\n");
    ListPrint(pHead);  // Ӧ����� 0 -> 1 -> 2 -> 

    // 6. ɾ��ͷ��Ԫ��
    ListPopFront(pHead);
    printf("ɾ��ͷ��Ԫ�غ�:\n");
    ListPrint(pHead);  // Ӧ����� 1 -> 2 -> 

    // 7. ��ָ��λ�ò���Ԫ��
    ListInsert(pHead->next, 1);  // ��λ�� 1 �����Ԫ�� 1
    printf("��λ�� 1 �����Ԫ�� 1:\n");
    ListPrint(pHead);  // Ӧ����� 1 -> 1 -> 2 -> 

    // 8. ɾ��ָ��λ��Ԫ��
    ListErase(pHead->next);  // ɾ��λ�� 1 ��Ԫ��
    printf("ɾ��λ�� 1 ��Ԫ�غ�:\n");
    ListPrint(pHead);  // Ӧ����� 1 -> 2 -> 

    // 9. ��������
    ListDestory(pHead);
    printf("�������ٳɹ���\n");
}

int main()
{
    TestList();  // ���в���
    return 0;
}
