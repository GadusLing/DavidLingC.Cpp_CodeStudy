#pragma once

namespace LDW
{
	//stack<int, vector<int>>
	//stack<int, list<int>>
	template<class T, class Container>// дģ���ʱ�����Container�������������ܿ���������ջ��������ջ
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);// push���൱����ջ������������
		}



	private:
		Container _con;

	};









}