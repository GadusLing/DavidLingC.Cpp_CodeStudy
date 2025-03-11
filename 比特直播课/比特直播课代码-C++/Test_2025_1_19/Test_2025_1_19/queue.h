#pragma once

#include <vector>
#include <list>
#include <deque>

using namespace std;

namespace LDW
{
	template<class T, class Container = deque<T>>// queueע�ⲻ����vectorȥ���䣬��Ϊvectorû���ṩpop_front
	//��Ȼ�������_con.erase(_con.begin())��ģ��queue��pop_frontǿ��֧�֣�����������������ѡ����˵������������ҪŲ�����ݣ�Ч�ʼ��ͣ����������list
	// ������õ��ǲ���deque���ͣ���Ϊdeque��insert��erase��Ȼ��һ�硣������ͷβɾ��Ĳ���Ч�� ��Ҫ�����������͵ģ�����stack��queue����ͷβ�����Ľṹ��˵��deque���ٺ��ʲ�����
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);// push�������ݾ��൱��������β����
		}

		void pop()
		{
			_con.pop_front();// pop����ͷ���൱��������ͷɾ��
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