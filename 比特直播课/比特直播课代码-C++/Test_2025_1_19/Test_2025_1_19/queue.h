#pragma once

#include <vector>
#include <list>
#include <deque>

using namespace std;

namespace LDW
{
	template<class T, class Container = deque<T>>// queue注意不能用vector去适配，因为vector没有提供pop_front
	//当然你可以用_con.erase(_con.begin())来模拟queue的pop_front强行支持，但是这样对于数组选型来说并不合理，会需要挪动数据，效率极低，所以最好用list
	// 但是最好的是采用deque类型，因为deque的insert和erase虽然是一坨。但是在头尾删插的操作效率 是要优于其他类型的，对于stack和queue这种头尾操作的结构来说，deque是再合适不过了
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);// push插入数据就相当于容器的尾插呗
		}

		void pop()
		{
			_con.pop_front();// pop出对头就相当于容器的头删呗
		}
		
		const T& front() const
		{
			return _con.front();
		}

		const T& back() const
		{
			return _con.back();
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