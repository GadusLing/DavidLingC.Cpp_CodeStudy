#pragma once

namespace LDW
{
	//stack<int, vector<int>>
	//stack<int, list<int>>
	template<class T, class Container>// 写模板的时候采用Container容器参数，就能控制是数组栈还是链表栈
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);// push就相当于在栈顶插入数据呗
		}



	private:
		Container _con;

	};









}