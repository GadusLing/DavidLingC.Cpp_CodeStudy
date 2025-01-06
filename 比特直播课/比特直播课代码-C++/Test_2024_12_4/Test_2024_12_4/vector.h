#pragma once
#include<assert.h>

namespace LDW
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
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

			*_finish = x;
			++_finish;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}
