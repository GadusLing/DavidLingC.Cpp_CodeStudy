#define _CRT_SECURE_NO_WARNINGS

#include "Tree.h"
#include "Queue.h"


// 二叉树前序遍历 根左右
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

// 二叉树中序遍历 左根右
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

// 二叉树后序遍历 左右根
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

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	// 如果遍历位置超出范围，或者当前字符是 '#', 返回 NULL
	if (*pi >= n || a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	// 创建当前节点
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL) // 检查内存分配是否成功
	{
		perror("malloc failed");
		exit(1);
	}
	newNode->data = a[*pi];
	(*pi)++;

	// 递归创建左、右子树
	newNode->left = BinaryTreeCreate(a, n, pi);
	newNode->right = BinaryTreeCreate(a, n, pi);

	return newNode;
}


// 二叉树销毁
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

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

// 二叉树叶子节点个数
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

// 二叉树第k层节点个数
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

// 二叉树的深度 / 高度
int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	//return 1 + (BinaryTreeDepth(root->left) > BinaryTreeDepth(root->right) ? BinaryTreeDepth(root->left) : BinaryTreeDepth(root->right));
	
	// 递归计算左、右子树的深度
	int leftDepth = BinaryTreeDepth(root->left);
	int rightDepth = BinaryTreeDepth(root->right);

	// 返回左右子树深度的较大值加 1
	return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)//检查根节点是否为空。如果为空，返回 NULL
	{
		return NULL;
	}
	if (root->data == x)//果当前节点的值等于 x，输出 "找到了" 并返回该节点
	{
		printf("找到了");
		return root;
	}
	BTNode* leftFind = BinaryTreeFind(root->left, x);
	if (leftFind)//在左子树递归查找。如果找到，则返回 leftFind
	{
		return leftFind;
	}
	return BinaryTreeFind(root->right, x); //如果左子树中未找到，则递归查找右子树并返回结果
	//此处简化了和左子树查找类似的创建rightFind 和 if代码，因为右子树如果找不到，到了叶子节点的子（空）节点会返回 NULL，找到了也会直接返回“找到了”，故简化
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL) return;
	//借助队列的结构来实现
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

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL) 
	{
		return true;  // 空树是完全二叉树
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

//做好自己力所能及的事情，并且接受它可能事与愿违