#pragma once

#include <vector>
#include <list>
#include <deque>

using namespace std;

namespace LDW
{
	//stack<int, vector<int>>
	//stack<int, list<int>>
	template<class T, class Container = deque<T>>// 写模板的时候采用Container容器参数，就能控制是数组栈还是链表栈
	// 但是最好的是采用deque类型，因为deque的insert和erase虽然是一坨。但是在头尾删插的操作效率 是要优于其他类型的，对于stack和queue这种头尾操作的结构来说，deque是再合适不过了
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);// push在栈顶插入数据就相当于容器的尾插呗
		}

		void pop()
		{
			_con.pop_back();// pop出栈就相当于容器的尾删呗
		}

		const T& top() const
		{
			return _con.back();// top就是返回栈顶元素，就是容器的尾部元素，back这个接口就起作用了
		}

		size_t size() const
		{
			return _con.size();// size就是容器的size
		}

		bool empty() const
		{
			return _con.empty();// empty就是容器的empty
		}

	private:
		Container _con;

	};









}