#pragma once

#include <iostream>
#include <list>
#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include "iterator.h"

using namespace std;

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

	//template<class T>
	//struct list_iterator
	//{
	//	typedef list_node<T> Node;
	//	Node* _node;

	//	list_iterator(Node* node) //通过节点指针Node* 来构造迭代器
	//		:_node(node)// 所以说迭代器是不是就是类指针的东西
	//	{}

	//	T& operator*()// 重载解引用
	//	{
	//		return _node->_data;
	//	}

	//	T* operator->()// 重载->  本来应该是两个箭头，编译器为了可读性省略了一个
	//	{
	//		return &_node->_data;
	//	}

	//	list_iterator<T>& operator++()// 重载++
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	bool operator!=(const list_iterator<T>& it)// 重载!=
	//	{// 这里必须要在list前加const，因为list_iterator<T>& it 在const修饰后变成常量引用，不会被修改，可以同时接收 左值和右值
	//     // 左值（Lvalue）：它们有明确的 内存地址，可以被赋值，也可以被取地址 &a  比如 int a = 10;  int b = a; int c = a + b; abc都是左值
	//     // 右值（Rvalue）：它是 表达式的结果，没有明确的内存地址，不能被取地址& (a + b)，不能赋值 a + b = 10（不合法）,a + b就是右值
	//	// 在test_list8(); 里，lt1.end()就是一个右值，所以这里不加const，那边就会报错
	//		return _node != it._node;
	//	}

	//	bool operator==(const list_iterator<T>& it)// 重载==
	//	{
	//		return _node == it._node;
	//	}

	//};

	////const 版本做法一 笨办法，复制一份然后加const,但是其实两份代码基本相同，除了几个const，所以我们可以考虑将两份代码做成一个模板
	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	Node* _node;

	//	list_const_iterator(Node* node) //通过节点指针Node* 来构造迭代器
	//		:_node(node)// 所以说迭代器是不是就是类指针的东西
	//	{}

	//	const T& operator*() const // 重载解引用
	//	{
	//		return _node->_data;
	//	}

	//	const T* operator->() const// 重载->  本来应该是两个箭头，编译器为了可读性省略了一个
	//	{
	//		return &_node->_data;
	//	}

	//	list_const_iterator<T>& operator++()// 重载++
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	bool operator!=(const list_const_iterator<T>& it) const
	//	{
	//		return _node != it._node;
	//	}

	//	bool operator==(const list_const_iterator<T>& it) const// 重载==
	//	{
	//		return _node == it._node;
	//	}
	//};

	// 把两份做成一个模板，需要增加两个参数，Ref和Ptr  reference and pointer
	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		list_iterator(Node* node) //通过节点指针Node* 来构造迭代器
			:_node(node)// 所以说迭代器是不是就是类指针的东西
		{}

		Ref operator*() // 重载解引用
		{
			return _node->_data;
		}

		Ptr operator->()// 重载->  本来应该是两个箭头，编译器为了可读性省略了一个
		{
			return &_node->_data;
		}

		Self& operator++()// 重载++ 前置
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)// 重载++ 后置 int充当占位符 标明后置
		{
			Self tmp = *this;
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()// 重载--
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)// 重载--，后置 int充当占位符 标明后置
		{
			Self tmp = *this;
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const Self& it) const// 重载==
		{
			return _node == it._node;
		}
	};


	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		//typedef list_iterator<T> iterator;
		//typedef list_const_iterator<T> const_iterator;

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;// 通过模板参数的不同来搞定一份iterator
		using reverse_iterator = ReverseIterator<iterator, T&, T*>;
		using const_reverse_iterator = ReverseIterator<const_iterator, const T&, const T*>;

		reverse_iterator rbegin()
		{
			return reverse_iterator(--end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(--end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(end());
		}

		iterator begin()
		{
			return iterator(_head->_next);// 返回开始位置（第一个数据，除头节点）的节点，这里写完整一点就是匿名对象构造一个迭代器
		}

		iterator end()
		{
			return iterator(_head);// 返回最后一个元素下一个位置，就是_head，这里写完整一点就是匿名对象构造一个迭代器
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list() // 带头双向构造
		{
			empty_init();
		}

		list(initializer_list<T> lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		list(const list<T>& lt) // 深拷贝构造 lt2(lt1)
		{
			empty_init(); // 这里要初始化lt2 也就是*this，搞搞头节点、指向啥的， ，不能在一个构造函数内部再去调用类的构造函数，所以要把构造的初始化列表拆出来写个empty_init()
			for (auto e : lt)
			{
				push_back(e);
			}
		}

		list<T>& operator=(list<T> lt)// 现代写法这里用传值
		{
			swap(lt);
			return *this;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		~list() // 析构
		{
			clear();
			delete _head;
			_head = nullptr;
			_size = 0;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);// erase后迭代器会失效，我们在那边写了erase返回了下个位置的迭代器，此时用it接收它相当于++了
				// 这样不断erase就达到了清除的目的
			}
		}

		size_t size() const
		{
			//size_t count = 0;
			//for (auto it : *this)
			//{
			//	++count;
			//}
			//return count;
			return _size;// 这样就可以直接返回数量了
		}

		void push_back(const T& x)// 尾插
		{
			/*Node* newNode = new Node(x);
			_head->_prev->_next = newNode;
			newNode->_next = _head;
			newNode->_prev = _head->_prev;
			_head->_prev = newNode;*/

			insert(end(), x); // 复用insert，多爽，双向带头链表的尾插就是在end()前插入
		}

		void push_front(const T& x)// 头插
		{

			insert(begin(), x); // 复用insert，多爽，双向带头链表的头插就是在begin()前插入
		}

		void pop_back(iterator pos)// 尾删
		{
			erase(--end());
		}

		void pop_front(iterator pos)// 头删
		{
			erase(begin());
		}


		// 在pos位置前插入，就是插入啦
		void insert(iterator pos, const T& x)// 链表的insert不存在迭代器失效
		{
			Node* newNode = new Node(x);
			Node* cur = pos._node;
			newNode->_next = cur;
			newNode->_prev = cur->_prev;
			cur->_prev->_next = newNode;
			cur->_prev = newNode;
			++_size;
		}

		iterator erase(iterator pos)// erase会导致迭代器失效，返回一个“删除位下一个位置的迭代器”
		{
			assert(pos != end()); // erase一定要注意不能把哨兵位给erase了
			Node* cur = pos._node;
			Node* nextNode = cur->_next; // 保存下一个节点的指针
			cur->_prev->_next = cur->_next;
			cur->_next->_prev = cur->_prev;
			delete cur;
			--_size;
			return iterator(nextNode); // 返回下一个节点的迭代器
		}

	private:
		Node* _head;
		size_t _size;// list如果需要求size每次都得完全遍历，那就很费效能，所以直接增加一个成员变量来计数size
	};



}



