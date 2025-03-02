#pragma once
#include<assert.h>
#include<iostream>

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
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * size());
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

		void insert(iterator pos, cosnt T& x)
		{
			if (_finish == _end_of_storage)// �ռ����ˣ���Ҫ����
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;

		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}
