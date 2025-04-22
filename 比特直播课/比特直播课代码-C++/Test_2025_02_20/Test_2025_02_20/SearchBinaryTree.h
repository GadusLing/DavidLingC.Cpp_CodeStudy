#pragma once

#include <iostream>
using namespace std;


template <class K>
struct BSTNode
{
	K _key;
	BSTNode<K>* _left;
	BSTNode<K>* _right;
	BSTNode(const K& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
	{}
};


template <class K>
class BSTree
{
	typedef BSTNode<K> Node;

public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else return false;// 这里不考虑相等的情况，相等就插入失败
		}
		cur = new Node(key);
		if (key < parent->_key) parent->_left = cur;
		else if (key > parent->_key) parent->_right = cur;

		//这是基本的二叉搜索树，如果是AVL树or红黑树，在这里还会引入平衡引子去控制平衡

		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key) cur = cur->_right;
			else if (cur->_key > key) cur = cur->_left;
			else return true;
		}
		return false;
	}

	bool Erase(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//开始删除
				if (cur->_left == nullptr)
				{
					if (cur == _root) _root = cur->_right;
					else
					{
						if (cur == parent->_left) parent->_left = cur->_right;
						else parent->_right = cur->_right;
						delete cur;
					}
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root) _root = cur->_left;
					else
					{
						if (cur == parent->_left) parent->_left = cur->_left;
						else parent->_right = cur->_left;
						delete cur;
					}
				}
				else
				{
					// 替代节点找左子树的最右(大)节点or右子树的最左(小)节点都可，这里选右子树的最左节点
					Node* replaceParent = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						replaceParent = replace;
						replace = replace->_left;// 找到右子树的最小节点
					}
					swap(cur->_key, replace->_key);
					if(replace == replaceParent->_left) replaceParent->_left = replace->_right;
					else replaceParent->_right = replace->_right;
					delete replace;
				}
				return true;
			}
		}
		return false;
	}

	void InOrder()// 无参 InOrder()，由这个无参版本自动传入 _root，这样就解决了 InOrder()的传参问题
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;

	void _InOrder(Node* root)// 中序遍历
	{
		if (!root) return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

};

void TestBSTree1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (const auto& e : a)
	{
		t.Insert(e);
	}
	t.InOrder();// 搜索二叉中序遍历之后就会变成一个升序数组
	t.Insert(16);
	t.InOrder();

	t.Insert(3);// 现在不允许冗余，所以没插进来
	t.InOrder();

	// 测试用例，左右都不为空
	t.Erase(8);
	t.InOrder();
	t.Erase(3);
	t.InOrder();

	// 右为空
	t.Erase(14);
	t.InOrder();

	//左为空
	t.Erase(6);
	t.InOrder();

	//整棵树删一遍
	for (const auto& e : a)
	{
		t.Erase(e);
		t.InOrder();
	}
}