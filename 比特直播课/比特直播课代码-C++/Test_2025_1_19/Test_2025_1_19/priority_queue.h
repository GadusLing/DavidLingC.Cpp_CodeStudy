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

	template<class T, class Container = vector<T>, class Compare = Less<T>>// priority_queueĬ���õ�vector��container

	class priority_queue// priority_queue�ײ��Ǹ���
	{
	public:
		void adjust_up(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;// ��0��ʼ������Ķѣ����׵Ĺ�ʽ�Ǻ���-1 �� /2�� ��������*2+1  ��*2+2
			while (child > 0)// ������ǵ���������Ҳ����0�����Դ���0��ѭ������
			{
				//if (_con[parent] < _con[child])// Ĭ���Ǵ�ѣ����Ӵ��ڸ��׾ͽ����������ú��ӱ�ɵ����ϵ�
				if (com(_con[parent] , _con[child]))// Ĭ���Ǵ�ѣ����Ӵ��ڸ��׾ͽ����������ú��ӱ�ɵ����ϵ�
				{
					swap(_con[child], _con[parent]);// �������Ӻ͸��׵�ֵ
					child = parent;// ��֮ǰ���׵�������ԭ���ĺ���
					parent = (child - 1) / 2;//��Ҫ��֮ǰ���׵ĸ����ˣ���ʱchild�Ѿ������ˣ��ٸ���parent��Ϊ��һ�������Ҫ��child��׼��
				}
				else// ������������ڸ��׾�ͣ�£�����������
				{
					break;
				}
			}
		}

		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;//��������Ӵ��ȸ�����ֵ���������ж�������������ȫ�������϶���������ң��϶�����
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child] < _con[child + 1])// �����Ҷ������Ҷ��Ӵ��������
				if (child + 1 < _con.size() && com(_con[child] , _con[child + 1]))// �����Ҷ������Ҷ��Ӵ��������
				{
					++child;// ȷ���Ҷ���̫�ӵ�λ
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
			adjust_up(_con.size() - 1);// �����Լ�������ϵ����㷨�����ӣ������������º�����������һ��push_heap���Ǹ��������ϵ����㷨��ʵ�ʿ��������Ǹ�
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);// priority_queue��pop����ɾ����ֵ�����or��С��Ҳ���ǶѶ����ݣ����Ժ�β����������ɾ
			_con.pop_back();
			adjust_down(0);//֮���������µ������㷨ά�ֶѽṹ
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


