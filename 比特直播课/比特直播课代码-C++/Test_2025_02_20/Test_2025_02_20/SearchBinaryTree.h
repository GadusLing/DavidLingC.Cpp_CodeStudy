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
			else return false;// ���ﲻ������ȵ��������ȾͲ���ʧ��
		}
		cur = new Node(key);
		if (key < parent->_key) parent->_left = cur;
		else if (key > parent->_key) parent->_right = cur;

		//���ǻ����Ķ����������������AVL��or������������ﻹ������ƽ������ȥ����ƽ��

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
				//��ʼɾ��
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
					// ����ڵ���������������(��)�ڵ�or������������(С)�ڵ㶼�ɣ�����ѡ������������ڵ�
					Node* replaceParent = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						replaceParent = replace;
						replace = replace->_left;// �ҵ�����������С�ڵ�
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

	void InOrder()// �޲� InOrder()��������޲ΰ汾�Զ����� _root�������ͽ���� InOrder()�Ĵ�������
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;

	void _InOrder(Node* root)// �������
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
	t.InOrder();// ���������������֮��ͻ���һ����������
	t.Insert(16);
	t.InOrder();

	t.Insert(3);// ���ڲ��������࣬����û�����
	t.InOrder();

	// �������������Ҷ���Ϊ��
	t.Erase(8);
	t.InOrder();
	t.Erase(3);
	t.InOrder();

	// ��Ϊ��
	t.Erase(14);
	t.InOrder();

	//��Ϊ��
	t.Erase(6);
	t.InOrder();

	//������ɾһ��
	for (const auto& e : a)
	{
		t.Erase(e);
		t.InOrder();
	}
}