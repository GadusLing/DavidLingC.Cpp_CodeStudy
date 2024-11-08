#define _CRT_SECURE_NO_WARNINGS

#include "Tree.h"
#include "Queue.h"


// ������ǰ����� ������
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// ������������� �����
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}

// ������������� ���Ҹ�
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	// �������λ�ó�����Χ�����ߵ�ǰ�ַ��� '#', ���� NULL
	if (*pi >= n || a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	// ������ǰ�ڵ�
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL) // ����ڴ�����Ƿ�ɹ�
	{
		perror("malloc failed");
		exit(1);
	}
	newNode->data = a[*pi];
	(*pi)++;

	// �ݹ鴴����������
	newNode->left = BinaryTreeCreate(a, n, pi);
	newNode->right = BinaryTreeCreate(a, n, pi);

	return newNode;
}


// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));
	free(*root);
	*root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// ����������� / �߶�
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//return 1 + (BinaryTreeDepth(root->left) > BinaryTreeDepth(root->right) ? BinaryTreeDepth(root->left) : BinaryTreeDepth(root->right));
	
	// �ݹ�����������������
	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	// ��������������ȵĽϴ�ֵ�� 1
	return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)//�����ڵ��Ƿ�Ϊ�ա����Ϊ�գ����� NULL
	{
		return NULL;
	}
	if (root->data == x)//����ǰ�ڵ��ֵ���� x����� "�ҵ���" �����ظýڵ�
	{
		printf("�ҵ���");
		return root;
	}
	BTNode* leftFind = BinaryTreeFind(root->left, x);
	if (leftFind)//���������ݹ���ҡ�����ҵ����򷵻� leftFind
	{
		return leftFind;
	}
	return BinaryTreeFind(root->right, x); //�����������δ�ҵ�����ݹ���������������ؽ��
	//�˴����˺��������������ƵĴ���rightFind �� if���룬��Ϊ����������Ҳ���������Ҷ�ӽڵ���ӣ��գ��ڵ�᷵�� NULL���ҵ���Ҳ��ֱ�ӷ��ء��ҵ��ˡ����ʼ�
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL) return;
	//�������еĽṹ��ʵ��
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* top = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", top->data);
		if (top->left)
		{
			QueuePush(&q, top->left);
		}
		if (top->right)
		{
			QueuePush(&q, top->right);
		}
	}
	QueueDestroy(&q);
}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL) 
	{
		return true;  // ��������ȫ������
	}
	Queue q;
	bool foundNull = false;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* top = QueueFront(&q);
		QueuePop(&q);
		if (!top)
		{
			foundNull = true;
		}
		else
		{
			if (foundNull)
			{
				return false;
			}
			QueuePush(&q, top->left);
			QueuePush(&q, top->right);
		}
	}
	QueueDestroy(&q);
	return true;
}

//�����Լ������ܼ������飬���ҽ�������������ԸΥ