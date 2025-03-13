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

	//template<class T>
	//struct list_iterator
	//{
	//	typedef list_node<T> Node;
	//	Node* _node;

	//	list_iterator(Node* node) //ͨ���ڵ�ָ��Node* �����������
	//		:_node(node)// ����˵�������ǲ��Ǿ�����ָ��Ķ���
	//	{}

	//	T& operator*()// ���ؽ�����
	//	{
	//		return _node->_data;
	//	}

	//	T* operator->()// ����->  ����Ӧ����������ͷ��������Ϊ�˿ɶ���ʡ����һ��
	//	{
	//		return &_node->_data;
	//	}

	//	list_iterator<T>& operator++()// ����++
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	bool operator!=(const list_iterator<T>& it)// ����!=
	//	{// �������Ҫ��listǰ��const����Ϊlist_iterator<T>& it ��const���κ��ɳ������ã����ᱻ�޸ģ�����ͬʱ���� ��ֵ����ֵ
	//     // ��ֵ��Lvalue������������ȷ�� �ڴ��ַ�����Ա���ֵ��Ҳ���Ա�ȡ��ַ &a  ���� int a = 10;  int b = a; int c = a + b; abc������ֵ
	//     // ��ֵ��Rvalue�������� ���ʽ�Ľ����û����ȷ���ڴ��ַ�����ܱ�ȡ��ַ& (a + b)�����ܸ�ֵ a + b = 10�����Ϸ���,a + b������ֵ
	//	// ��test_list8(); �lt1.end()����һ����ֵ���������ﲻ��const���Ǳ߾ͻᱨ��
	//		return _node != it._node;
	//	}

	//	bool operator==(const list_iterator<T>& it)// ����==
	//	{
	//		return _node == it._node;
	//	}

	//};

	////const �汾����һ ���취������һ��Ȼ���const,������ʵ���ݴ��������ͬ�����˼���const���������ǿ��Կ��ǽ����ݴ�������һ��ģ��
	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	Node* _node;

	//	list_const_iterator(Node* node) //ͨ���ڵ�ָ��Node* �����������
	//		:_node(node)// ����˵�������ǲ��Ǿ�����ָ��Ķ���
	//	{}

	//	const T& operator*() const // ���ؽ�����
	//	{
	//		return _node->_data;
	//	}

	//	const T* operator->() const// ����->  ����Ӧ����������ͷ��������Ϊ�˿ɶ���ʡ����һ��
	//	{
	//		return &_node->_data;
	//	}

	//	list_const_iterator<T>& operator++()// ����++
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	bool operator!=(const list_const_iterator<T>& it) const
	//	{
	//		return _node != it._node;
	//	}

	//	bool operator==(const list_const_iterator<T>& it) const// ����==
	//	{
	//		return _node == it._node;
	//	}
	//};

	// ����������һ��ģ�壬��Ҫ��������������Ref��Ptr  reference and pointer
	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		list_iterator(Node* node) //ͨ���ڵ�ָ��Node* �����������
			:_node(node)// ����˵�������ǲ��Ǿ�����ָ��Ķ���
		{}

		Ref operator*() // ���ؽ�����
		{
			return _node->_data;
		}

		Ptr operator->()// ����->  ����Ӧ����������ͷ��������Ϊ�˿ɶ���ʡ����һ��
		{
			return &_node->_data;
		}

		Self& operator++()// ����++ ǰ��
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)// ����++ ���� int�䵱ռλ�� ��������
		{
			Self tmp = *this;
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()// ����--
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)// ����--������ int�䵱ռλ�� ��������
		{
			Self tmp = *this;
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const Self& it) const// ����==
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
		typedef list_iterator<T, const T&, const T*> const_iterator;// ͨ��ģ������Ĳ�ͬ���㶨һ��iterator
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
			return iterator(_head->_next);// ���ؿ�ʼλ�ã���һ�����ݣ���ͷ�ڵ㣩�Ľڵ㣬����д����һ���������������һ��������
		}

		iterator end()
		{
			return iterator(_head);// �������һ��Ԫ����һ��λ�ã�����_head������д����һ���������������һ��������
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

		list() // ��ͷ˫����
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

		list(const list<T>& lt) // ������� lt2(lt1)
		{
			empty_init(); // ����Ҫ��ʼ��lt2 Ҳ����*this�����ͷ�ڵ㡢ָ��ɶ�ģ� ��������һ�����캯���ڲ���ȥ������Ĺ��캯��������Ҫ�ѹ���ĳ�ʼ���б�����д��empty_init()
			for (auto e : lt)
			{
				push_back(e);
			}
		}

		list<T>& operator=(list<T> lt)// �ִ�д�������ô�ֵ
		{
			swap(lt);
			return *this;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		~list() // ����
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
				it = erase(it);// erase���������ʧЧ���������Ǳ�д��erase�������¸�λ�õĵ���������ʱ��it�������൱��++��
				// ��������erase�ʹﵽ�������Ŀ��
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
			return _size;// �����Ϳ���ֱ�ӷ���������
		}

		void push_back(const T& x)// β��
		{
			/*Node* newNode = new Node(x);
			_head->_prev->_next = newNode;
			newNode->_next = _head;
			newNode->_prev = _head->_prev;
			_head->_prev = newNode;*/

			insert(end(), x); // ����insert����ˬ��˫���ͷ�����β�������end()ǰ����
		}

		void push_front(const T& x)// ͷ��
		{

			insert(begin(), x); // ����insert����ˬ��˫���ͷ�����ͷ�������begin()ǰ����
		}

		void pop_back(iterator pos)// βɾ
		{
			erase(--end());
		}

		void pop_front(iterator pos)// ͷɾ
		{
			erase(begin());
		}


		// ��posλ��ǰ���룬���ǲ�����
		void insert(iterator pos, const T& x)// �����insert�����ڵ�����ʧЧ
		{
			Node* newNode = new Node(x);
			Node* cur = pos._node;
			newNode->_next = cur;
			newNode->_prev = cur->_prev;
			cur->_prev->_next = newNode;
			cur->_prev = newNode;
			++_size;
		}

		iterator erase(iterator pos)// erase�ᵼ�µ�����ʧЧ������һ����ɾ��λ��һ��λ�õĵ�������
		{
			assert(pos != end()); // eraseһ��Ҫע�ⲻ�ܰ��ڱ�λ��erase��
			Node* cur = pos._node;
			Node* nextNode = cur->_next; // ������һ���ڵ��ָ��
			cur->_prev->_next = cur->_next;
			cur->_next->_prev = cur->_prev;
			delete cur;
			--_size;
			return iterator(nextNode); // ������һ���ڵ�ĵ�����
		}

	private:
		Node* _head;
		size_t _size;// list�����Ҫ��sizeÿ�ζ�����ȫ�������Ǿͺܷ�Ч�ܣ�����ֱ������һ����Ա����������size
	};



}



