#pragma once

#include <iostream>

namespace LDW
{
	template<class T>
	struct list_node// 像这种节点的地方用struct就很棒，因为我就是需要它封装起来，但是又能随便访问，如果用class还得考虑什么公有私有友元之类的，用struct就很合理
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())// 给个T()构造的匿名对象做缺省值
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

		list_iterator(Node* node) //通过节点指针Node* 来构造迭代器
			:_node(node)// 所以说迭代器是不是就是类指针的东西
		{}

		T& operator*()// 重载解引用
		{
			return _node->_data;
		}

		const T& operator*() const // 成员函数后的 const：确保该成员函数不会修改对象的状态，使其可以在 const 对象上调用。
								   // 返回类型前的 const：确保返回的引用是常量引用，防止通过该引用修改数据。
		{
			return _node->_data;
		}

		list_iterator<T>& operator++()// 重载++
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!=(const list_iterator<T>& it)// 重载!=
		{// 这里必须要在list前加const，因为list_iterator<T>& it 在const修饰后变成常量引用，不会被修改，可以同时接收 左值和右值
	     // 左值（Lvalue）：它们有明确的 内存地址，可以被赋值，也可以被取地址 &a  比如 int a = 10;  int b = a; int c = a + b; abc都是左值
	     // 右值（Rvalue）：它是 表达式的结果，没有明确的内存地址，不能被取地址& (a + b)，不能赋值 a + b = 10（不合法）,a + b就是右值
		// 在test_list8(); 里，lt1.end()就是一个右值，所以这里不加const，那边就会报错
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
			return iterator(_head->_next);// 返回开始位置（第一个数据，除头节点）的节点，这里写完整一点就是匿名对象构造一个迭代器
		}

		iterator end()
		{
			return iterator(_head);// 返回最后一个元素下一个位置，就是_head，这里写完整一点就是匿名对象构造一个迭代器
		}

		list()// 带头双向构造
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



