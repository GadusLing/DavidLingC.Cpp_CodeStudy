#pragma once

#include <vector>
#include <list>
#include <deque>

using namespace std;

namespace LDW
{
	//stack<int, vector<int>>
	//stack<int, list<int>>
	template<class T, class Container = deque<T>>// дģ���ʱ�����Container�������������ܿ���������ջ��������ջ
	// ������õ��ǲ���deque���ͣ���Ϊdeque��insert��erase��Ȼ��һ�硣������ͷβɾ��Ĳ���Ч�� ��Ҫ�����������͵ģ�����stack��queue����ͷβ�����Ľṹ��˵��deque���ٺ��ʲ�����
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);// push��ջ���������ݾ��൱��������β����
		}

		void pop()
		{
			_con.pop_back();// pop��ջ���൱��������βɾ��
		}

		const T& top() const
		{
			return _con.back();// top���Ƿ���ջ��Ԫ�أ�����������β��Ԫ�أ�back����ӿھ���������
		}

		size_t size() const
		{
			return _con.size();// size����������size
		}

		bool empty() const
		{
			return _con.empty();// empty����������empty
		}

	private:
		Container _con;

	};









}