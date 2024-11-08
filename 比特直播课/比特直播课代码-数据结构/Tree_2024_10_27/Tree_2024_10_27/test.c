#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include "Tree.h"

void test() {
    BTDataType a[] = "ABD##E#H##CF##G##";
    int index = 0;
    int length = (int)strlen(a);
    // ����������
    BTNode* root = BinaryTreeCreate(a, length, &index);
    printf("BinaryTreeCreate: �������\n");

    // ǰ�����
    BinaryTreePrevOrder(root);
    printf("\n");

    // �������
    BinaryTreeInOrder(root);
    printf("\n");

    // �������
    BinaryTreePostOrder(root);
    printf("\n");

    // �������
    BinaryTreeLevelOrder(root);
    printf("\n");

    // �ڵ�����
    int size = BinaryTreeSize(root);
    printf("BinaryTreeSize (Expected: 8): %d\n", size);

    // Ҷ�ӽڵ�����
    int leafSize = BinaryTreeLeafSize(root);
    printf("BinaryTreeLeafSize (Expected: 4): %d\n", leafSize);

    // ������ڵ���
    int level3Size = BinaryTreeLevelKSize(root, 3);
    printf("BinaryTreeLevelKSize for k=3 (Expected: 4): %d\n", level3Size);

    // ���������
    int depth = BinaryTreeDepth(root);
    printf("BinaryTreeDepth (Expected: 4): %d\n", depth);

    // ���ҽڵ�
    BTNode* findNode = BinaryTreeFind(root, 'E');
    printf("BinaryTreeFind 'E' (Expected: �ҵ���): ");
    if (findNode != NULL) {
        printf("�ҵ���\n");
    }
    else {
        printf("δ�ҵ�\n");
    }

    // �ж��Ƿ�����ȫ������
    bool isComplete = BinaryTreeComplete(root);
    printf("BinaryTreeComplete (Expected: true): %s\n", isComplete ? "true" : "false");

    // ���ٶ�����
    BinaryTreeDestory(&root);
    printf("BinaryTreeDestory: ������������\n");
}

main() 
{
    test();
}


