#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef char BTDataType;//�������������������

//�������ڵ�ṹ�Ķ���
typedef struct BinaryTreeNode
{
	BTDataType data;//���ݴ�����
	struct BinaryTreeNode* left;//����
	struct BinaryTreeNode* right;//�Һ���
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, size_t n, int* pi);

// ����������
void BinaryTreeDestory(BTNode** root);

// �������ڵ����
int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

// ����������� / �߶�
int BinaryTreeDepth(BTNode* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);

// �������������
void BinaryTreeInOrder(BTNode* root);

// �������������
void BinaryTreePostOrder(BTNode* root);

// �������
void BinaryTreeLevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);
