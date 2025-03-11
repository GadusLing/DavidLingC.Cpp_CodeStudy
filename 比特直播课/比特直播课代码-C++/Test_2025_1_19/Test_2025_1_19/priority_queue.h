#pragma once

#include <vector>
#include <list>
#include <deque>

using namespace std;

namespace LDW
{
	template<class T>
	class Less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	class Greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>, class Compare = Less<T>>// priority_queue默认用的vector当container

	class priority_queue// priority_queue底层是个堆
	{
	public:
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;// 从0开始的排序的堆，父亲的公式是孩子-1 再 /2； 孩子是左*2+1  右*2+2
			while (child > 0)// 最差结果是调整到根，也就是0，所以大于0是循环条件
			{
				//if (_con[parent] < _con[child])// 默认是大堆，孩子大于父亲就交换，继续让孩子变成爹往上调
				if (com(_con[parent] , _con[child]))// 默认是大堆，孩子大于父亲就交换，继续让孩子变成爹往上调
				{
					swap(_con[child], _con[parent]);// 交换孩子和父亲的值
					child = parent;// 把之前父亲的索引给原本的孩子
					parent = (child - 1) / 2;//再要找之前父亲的父亲了，此时child已经更新了，再更新parent，为下一次如果还要调child做准备
				}
				else// 孩子如果不大于父亲就停下，跳出不动了
				{
					break;
				}
			}
		}

		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;//假设左儿子大，先赋个初值能让它进判断条件，反正完全二叉树肯定是先左后右，肯定有左
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])// 存在右儿子且右儿子大于左儿子
				if (child + 1 < _con.size() && com(_con[child] , _con[child + 1]))// 存在右儿子且右儿子大于左儿子
				{
					++child;// 确认右儿子太子地位
				}
				//if (_con[parent] < _con[child])
				if (com(_con[parent] , _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);// 这里自己造个向上调整算法的轮子，方便待会儿讲仿函数，库里有一个push_heap，那个就是向上调整算法，实际开发就用那个
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);// priority_queue的pop就是删除极值，最大or最小，也就是堆顶数据，所以和尾部交换了再删
			_con.pop_back();
			adjust_down(0);//之后再用向下调整的算法维持堆结构
		}

		const T& top() const
		{
			return _con[0];
		}

		size_t size() const
		{
			return _con.size();
		}

		bool empty() const
		{
			return _con.empty();
		}

	private:
		Container _con;
	};		
}


