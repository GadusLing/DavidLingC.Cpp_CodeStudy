#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

//void test()
//{
//	//�ֶ�����һ������
//	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
//
//	//��data
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	
//	//��ʽ����next
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

// ���Ժ���
void TestSList()
{
    SLTNode* head = NULL; // ��ʼ������ͷָ��

    // ����β��
    SLTPushBack(&head, 1);
    SLTPushBack(&head, 2);
    SLTPushBack(&head, 3);

    printf("����β��: ");
    SLTprint(head); // Ӧ�����: 1 -> 2 -> 3 -> NULL

    // ����ͷ��
    SLTPushFront(&head, 0);
    printf("����ͷ��: ");
    SLTprint(head); // Ӧ�����: 0 -> 1 -> 2 -> 3 -> NULL

    // ����βɾ
    SLTPopBack(&head);
    printf("����βɾ: ");
    SLTprint(head); // Ӧ�����: 0 -> 1 -> 2 -> NULL

    // ����ͷɾ
    SLTPopFront(&head);
    printf("����ͷɾ: ");
    SLTprint(head); // Ӧ�����: 1 -> 2 -> NULL

    // ���Բ���
    SLTNode* found = SListFind(head, 1);
    printf("���Բ��� 1: %s\n", found ? "�ҵ�" : "δ�ҵ�"); // Ӧ�����: �ҵ�

    found = SListFind(head, 3);
    printf("���Բ��� 3: %s\n", found ? "�ҵ�" : "δ�ҵ�"); // Ӧ�����: δ�ҵ�

    // ���Բ����
    SLTNode* pos = head; // �����ڵ�һ���ڵ�����
    SListInsertAfter(pos, 2);
    printf("������1�����2: ");
    SLTprint(head); // Ӧ�����: 1 -> 2 -> 2 -> NULL

    // ����ɾ����
    SListEraseAfter(pos);
    printf("����ɾ��1��: ");
    SLTprint(head); // Ӧ�����: 1 -> 2 -> NULL

    // �������ض�λ�ò���
    SLTInsert(&head, head->next, 1);
    printf("������λ�ò���1: ");
    SLTprint(head); // Ӧ�����: 1 -> 1 -> 2 -> NULL

    // ����ɾ���ض�λ��
    SLTErase(&head, head->next);
    printf("����ɾ��ָ��λ��: ");
    SLTprint(head); // Ӧ�����: 1 -> 2 -> NULL

    // ��������
    SLTDestroy(&head);
    printf("���������: ");
    SLTprint(head); // Ӧ�����: NULL
}

int main()
{
    TestSList();
    return 0;
}
