#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include "Tree.h"

void test() {
    BTDataType a[] = "ABD##E#H##CF##G##";
    int index = 0;
    int length = (int)strlen(a);
    // 构建二叉树
    BTNode* root = BinaryTreeCreate(a, length, &index);
    printf("BinaryTreeCreate: 构建完成\n");

    // 前序遍历
    BinaryTreePrevOrder(root);
    printf("\n");

    // 中序遍历
    BinaryTreeInOrder(root);
    printf("\n");

    // 后序遍历
    BinaryTreePostOrder(root);
    printf("\n");

    // 层序遍历
    BinaryTreeLevelOrder(root);
    printf("\n");

    // 节点总数
    int size = BinaryTreeSize(root);
    printf("BinaryTreeSize (Expected: 8): %d\n", size);

    // 叶子节点总数
    int leafSize = BinaryTreeLeafSize(root);
    printf("BinaryTreeLeafSize (Expected: 4): %d\n", leafSize);

    // 第三层节点数
    int level3Size = BinaryTreeLevelKSize(root, 3);
    printf("BinaryTreeLevelKSize for k=3 (Expected: 4): %d\n", level3Size);

    // 二叉树深度
    int depth = BinaryTreeDepth(root);
    printf("BinaryTreeDepth (Expected: 4): %d\n", depth);

    // 查找节点
    BTNode* findNode = BinaryTreeFind(root, 'E');
    printf("BinaryTreeFind 'E' (Expected: 找到了): ");
    if (findNode != NULL) {
        printf("找到了\n");
    }
    else {
        printf("未找到\n");
    }

    // 判断是否是完全二叉树
    bool isComplete = BinaryTreeComplete(root);
    printf("BinaryTreeComplete (Expected: true): %s\n", isComplete ? "true" : "false");

    // 销毁二叉树
    BinaryTreeDestory(&root);
    printf("BinaryTreeDestory: 二叉树已销毁\n");
}

main() 
{
    test();
}


