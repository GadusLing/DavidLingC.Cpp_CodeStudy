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
			return _start;// 从iterator* 变为返回const iterator* 本质是一种权限缩小
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
		{}

		vector(initializer_list<T> il)// initializer_list构造
		{
			reserve(il.size());
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		//类模板的成员函数，也可以是一个函数模板
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)// 迭代器区间构造
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val = T())// n 个 value初始化
		{
			resize(n, val);
		}

		vector(int n, const T& val = T()) // 官方库里写了两个，size_t和int都有 ，避免了匹配问题
		{
			resize(n, val);
		}

	


		// 拷贝构造 v2(v1)，上面的构造不能删哦，因为拷贝构造也是一种构造，当写了拷贝构造之后，系统提供的默认构造会失效，所以要留个壳子，让系统有构造可以调，哪怕默认参数都在private那边
		vector(const vector<T>& v)
		{
			/*_start = new T[v.size()];
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}*/  // 传统拷贝的写法

			reserve(v.size());
			for (auto e : v)
			{
				push_back(e);
			}// 现代写法


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
		//	return *this; // 传统写法
		//}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector<T>& operator=(vector<T> v)// 现代写法的关键————传值传参，通过中间所创建的临时对象来交换
		{
			swap(v);
			return *this; // 现代写法
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


		void resize(size_t n, const T& val = T()) // size_t n：新的大小。   const T& val = T()：新元素的默认值。如果没有提供 val，则使用类型 T 的默认构造函数来初始化新元素。
		{
			if (n > size())
			{
				// 如果新的大小 大于当前大小，则需要扩容并添加新元素
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
				// 如果新的大小 小于当前大小，则移除多余的元素
				_finish = _start + n;
			}
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				//memcpy(tmp, _start, sizeof(T) * size());// 这里潜藏着一个memcpy浅拷贝导致的问题，memcpy是一个一个字符拷贝，还是浅拷贝，是同一个地址
				for (size_t i = 0; i < oldSize; i++)
				{
					tmp[i] = _start[i];// 所以要用=赋值来实现，string的=赋值是实现了深拷贝的
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

		const T& operator[](size_t i) const// const版本只能读不能写，所以需要两份都保留
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

			*_finish = x;// 解引用_finish, 将 x 的值赋给 _finish 所指向的内存位置
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
			assert(pos <= _finish);// insert 这里的检查和erase就不同，这里可以写成<= _finish 因为如果==_finish就相当于直接尾插了

			if (_finish == _end_of_storage)// 空间满了，需要扩容
			{
				size_t len = pos - _start;// 防止迭代器失效，所以要计算一个相对位置
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator it = _finish - 1;// 等待扩容后再计算迭代器位置，确保位置不会失效

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
			assert(pos < _finish);//erase这里不可以写成<= _finish 因为不能删除_finish，所以必须写成<_finish

			iterator it = pos + 1; // 从 pos 的下一个位置开始
			while (it < _finish) // 将 pos 之后的元素依次向前移动一个位置
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish; // 更新 _finish，表示数组的有效元素减少了一个
			return pos;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}
