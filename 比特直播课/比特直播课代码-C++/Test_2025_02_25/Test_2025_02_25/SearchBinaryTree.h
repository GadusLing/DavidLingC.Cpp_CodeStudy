#pragma once

#include <iostream>
using namespace std;

namespace key_value
{
	template <class K, class V>
	struct BSTNode
	{
		K _key;
		V _value;
		BSTNode<K, V>* _left;
		BSTNode<K, V>* _right;
		BSTNode(const K& key, const V& value)
			:_key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};


	template <class K, class V>
	class BSTree
	{
		typedef BSTNode<K, V> Node;

	public:
		BSTree(){}

		BSTree(const BSTree<K, V>& t)
		{
			_root = Copy(t._root);
		}

		~BSTree()
		{
			Destroy(_root);
			_root = nullptr;
		}

		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
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
			cur = new Node(key, value);
			if (key < parent->_key) parent->_left = cur;
			else if (key > parent->_key) parent->_right = cur;

			//���ǻ����Ķ����������������AVL��or������������ﻹ������ƽ������ȥ����ƽ��

			return true;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key) cur = cur->_right;
				else if (cur->_key > key) cur = cur->_left;
				else return cur;
			}
			return nullptr;
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
						swap(cur->_value, replace->_value);
						if (replace == replaceParent->_left) replaceParent->_left = replace->_right;
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
			cout << root->_key << ":";
			cout << root->_value << " ";
			_InOrder(root->_right);
		}

		void Destroy(Node* root)
		{
			if (root == nullptr) return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr) return nullptr;
			Node* newRoot = new Node(root->_key, root->_value);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);
			return newRoot;
		}
	};

	void TestBSTree()
	{
		BSTree<string, string> dict;
		dict.Insert("insert", "����");
		dict.Insert("erase", "ɾ��");
		dict.Insert("left", "���");
		dict.Insert("string", "�ַ���");

		string str;
		cout << "������Ӣ�ĵ��ʽ��в�ѯ (Ctrl+Z ��ֹ):" << endl;
		while (cin >> str)
		{
			auto ret = dict.Find(str);
			if (ret) cout << str << " : " << ret->_value << endl;
			else cout << "����ƴд����" << endl;
		}

		// ˮ��ͳ�Ʋ���
		string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
		BSTree<string, int> countTree;
		for (auto& s : strs)
		{
			auto ret = countTree.Find(s);
			//BSTNode<string, int>* ret = countTree.Find(s);
			if (ret == nullptr) countTree.Insert(s, 1);
			else ret->_value++;
		}

		cout << "\nˮ��ͳ�ƽ����" << endl;
		countTree.InOrder();
	}
}