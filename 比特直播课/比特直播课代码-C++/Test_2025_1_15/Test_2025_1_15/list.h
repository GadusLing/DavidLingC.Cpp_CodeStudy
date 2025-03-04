#pragma once

#include <iostream>

namespace LDW
{
	template<class T>
	struct list_node// �����ֽڵ�ĵط���struct�ͺܰ�����Ϊ�Ҿ�����Ҫ����װ�������������������ʣ������class���ÿ���ʲô����˽����Ԫ֮��ģ���struct�ͺܺ���
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())// ����T()���������������ȱʡֵ
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}

	};

	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		list_iterator(Node* node) //ͨ���ڵ�ָ��Node* �����������
			:_node(node)// ����˵�������ǲ��Ǿ�����ָ��Ķ���
		{}

		T& operator*()// ���ؽ�����
		{
			return _node->_data;
		}

		const T& operator*() const // ��Ա������� const��ȷ���ó�Ա���������޸Ķ����״̬��ʹ������� const �����ϵ��á�
								   // ��������ǰ�� const��ȷ�����ص������ǳ������ã���ֹͨ���������޸����ݡ�
		{
			return _node->_data;
		}

		list_iterator<T>& operator++()// ����++
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!=(const list_iterator<T>& it)// ����!=
		{// �������Ҫ��listǰ��const����Ϊlist_iterator<T>& it ��const���κ��ɳ������ã����ᱻ�޸ģ�����ͬʱ���� ��ֵ����ֵ
	     // ��ֵ��Lvalue������������ȷ�� �ڴ��ַ�����Ա���ֵ��Ҳ���Ա�ȡ��ַ &a  ���� int a = 10;  int b = a; int c = a + b; abc������ֵ
	     // ��ֵ��Rvalue�������� ���ʽ�Ľ����û����ȷ���ڴ��ַ�����ܱ�ȡ��ַ& (a + b)�����ܸ�ֵ a + b = 10�����Ϸ���,a + b������ֵ
		// ��test_list8(); �lt1.end()����һ����ֵ���������ﲻ��const���Ǳ߾ͻᱨ��
			return _node != it._node;
		}

	};


	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		typedef list_iterator<T> iterator;

		iterator begin()
		{
			return iterator(_head->_next);// ���ؿ�ʼλ�ã���һ�����ݣ���ͷ�ڵ㣩�Ľڵ㣬����д����һ���������������һ��������
		}

		iterator end()
		{
			return iterator(_head);// �������һ��Ԫ����һ��λ�ã�����_head������д����һ���������������һ��������
		}

		list()// ��ͷ˫����
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			Node* newNode = new Node(x);
			_head->_prev->_next = newNode;
			newNode->_next = _head;
			newNode->_prev = _head->_prev;
			_head->_prev = newNode;
		}



	private:
		Node* _head;
	};



}



