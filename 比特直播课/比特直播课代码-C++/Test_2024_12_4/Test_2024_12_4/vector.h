#pragma once

#include<assert.h>
#include<iostream>
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

namespace LDW
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}
		
		const_iterator begin() const
		{
			return _start;// ��iterator* ��Ϊ����const iterator* ������һ��Ȩ����С
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
		{}

		vector(initializer_list<T> il)// initializer_list����
		{
			reserve(il.size());
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		//��ģ��ĳ�Ա������Ҳ������һ������ģ��
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)// ���������乹��
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())// n �� value��ʼ��
		{
			resize(n, val);
		}

		vector(int n, const T& val = T()) // �ٷ�����д��������size_t��int���� ��������ƥ������
		{
			resize(n, val);
		}

	


		// �������� v2(v1)������Ĺ��첻��ɾŶ����Ϊ��������Ҳ��һ�ֹ��죬��д�˿�������֮��ϵͳ�ṩ��Ĭ�Ϲ����ʧЧ������Ҫ�������ӣ���ϵͳ�й�����Ե�������Ĭ�ϲ�������private�Ǳ�
		vector(const vector<T>& v)
		{
			/*_start = new T[v.size()];
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}*/  // ��ͳ������д��

			reserve(v.size());
			for (auto e : v)
			{
				push_back(e);
			}// �ִ�д��


		}

		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		clear();
		//		reserve(v.size());
		//		for (auto e : v)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this; // ��ͳд��
		//}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector<T>& operator=(vector<T> v)// �ִ�д���Ĺؼ�����������ֵ���Σ�ͨ���м�����������ʱ����������
		{
			swap(v);
			return *this; // �ִ�д��
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		void clear()
		{
			_finish = _start;
		}


		void resize(size_t n, const T& val = T()) // size_t n���µĴ�С��   const T& val = T()����Ԫ�ص�Ĭ��ֵ�����û���ṩ val����ʹ������ T ��Ĭ�Ϲ��캯������ʼ����Ԫ�ء�
		{
			if (n > size())
			{
				// ����µĴ�С ���ڵ�ǰ��С������Ҫ���ݲ������Ԫ��
				if (n > capacity())
				{
					reserve(n);
				}
				while (size() < n)
				{
					push_back(val);
				}
			}
			else if (n < size())
			{
				// ����µĴ�С С�ڵ�ǰ��С�����Ƴ������Ԫ��
				_finish = _start + n;
			}
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				//memcpy(tmp, _start, sizeof(T) * size());// ����Ǳ����һ��memcpyǳ�������µ����⣬memcpy��һ��һ���ַ�����������ǳ��������ͬһ����ַ
				for (size_t i = 0; i < oldSize; i++)
				{
					tmp[i] = _start[i];// ����Ҫ��=��ֵ��ʵ�֣�string��=��ֵ��ʵ���������
				}
				delete[] _start;

				_start = tmp;
				_finish = tmp + oldSize;
				_end_of_storage = _start + n;
			}
		}

		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}

		const T& operator[](size_t i) const// const�汾ֻ�ܶ�����д��������Ҫ���ݶ�����
		{
			assert(i < size());

			return _start[i];
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;// ������_finish, �� x ��ֵ���� _finish ��ָ����ڴ�λ��
			++_finish;
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);// insert ����ļ���erase�Ͳ�ͬ���������д��<= _finish ��Ϊ���==_finish���൱��ֱ��β����

			if (_finish == _end_of_storage)// �ռ����ˣ���Ҫ����
			{
				size_t len = pos - _start;// ��ֹ������ʧЧ������Ҫ����һ�����λ��
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator it = _finish - 1;// �ȴ����ݺ��ټ��������λ�ã�ȷ��λ�ò���ʧЧ

			while (it >= pos)
			{
				*(it + 1) = *it;
				--it;
			}
			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);//erase���ﲻ����д��<= _finish ��Ϊ����ɾ��_finish�����Ա���д��<_finish

			iterator it = pos + 1; // �� pos ����һ��λ�ÿ�ʼ
			while (it < _finish) // �� pos ֮���Ԫ��������ǰ�ƶ�һ��λ��
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish; // ���� _finish����ʾ�������ЧԪ�ؼ�����һ��
			return pos;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}
