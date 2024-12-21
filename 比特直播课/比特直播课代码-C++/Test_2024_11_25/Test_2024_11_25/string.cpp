#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace LDWT
{
	const size_t string::npos = -1;

	string::string(size_t n, char ch)
		:_str(new char[n + 1])
		,_size(n)
		,_capacity(n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_str[i] = ch;
		}
		_str[_size] = '\0';
	}

	string::string(const char* str)//全缺省
		:_size(strlen(str))//使用 strlen 计算传入字符串的长度（不包括结束符 '\0'），存入 _size。
	{
		_capacity = _size;//初始化 _capacity 为 _size，确保足够的存储空间。
		_str = new char[strlen(str) + 1];//动态分配内存，大小为字符串长度加 1（为结束符 '\0' 留空间）
		strcpy(_str, str);//使用 strcpy 将字符串内容从 str 复制到 _str。
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size + 1 > _capacity)
		{
			//扩容 
			string::reserve(_size == 0 ? 4 : _capacity * 2);
		}

		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			//扩容
			size_t newCapacity = 2 * _capacity;
			if (_size + len > 2 * _capacity)
			{
				newCapacity = _size + len;
			}

			reserve(newCapacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator+=(char ch)
	{
		string::push_back(ch);
		return *this;
	}

	string& string::operator+=(const char* str)
	{
		string::append(str);
		return *this;
	}

	void string::insert(size_t pos, size_t n, char ch)
	{
		assert(pos <= _size);
		assert(n > 0);
		if (_size + n > _capacity)//检查当前容量 _capacity 是否足够容纳插入后的字符串长度。如果不够，则需要扩容。
		{
			//扩容
			size_t newCapacity = 2 * _capacity;
			if (_size + n > 2 * _capacity)
			{
				newCapacity = _size + n;
			}

			reserve(newCapacity);
		}
		//挪动数据
		//int end = _size;//end 初始化为字符串的最后一个字符索引 _size（实际存储为 '\0' 的位置）。
		//while (end >= (int)pos)//强转为int比较,避免出现自动转换为size_t比较而产生的越界错误
		//{
		//	_str[end + n] = _str[end]; //将索引 end 的字符移动到 end + n 的位置，为新插入的字符腾出空间。
		//	--end;//end 向前移动。
		//}

		int end = _size + n;
		while (end > pos + n - 1)//防止越界问题
		{
			_str[end] = _str[end - n];
			--end;
		}

		for (size_t i = 0; i < n; ++i)
		{
			_str[pos + i] = ch;
		}
		_size += n;

	/*	string tmp(n, ch);
		insert(pos, tmp.c_str());*/

	}

	void string::insert(size_t pos, const char* str)
	{
		//assert(pos <= _size);

		//size_t n = strlen(str);
		//if (_size + n > _capacity)//检查当前容量 _capacity 是否足够容纳插入后的字符串长度。如果不够，则需要扩容。
		//{
		//	//扩容
		//	size_t newCapacity = 2 * _capacity;
		//	if (_size + n > 2 * _capacity)
		//	{
		//		newCapacity = _size + n;
		//	}

		//	reserve(newCapacity);
		//}

		//size_t end = _size + n;
		//while (end > pos + n - 1)
		//{
		//	_str[end] = _str[end - n];
		//	--end;
		//}

		//for (size_t i = 0; i < n; ++i)
		//{
		//	_str[pos + i] = str[i];
		//}
		//_size += n;

		size_t n = strlen(str);
		insert(pos, n, 'x');//先随便插对应数量的字符
		for (size_t i = 0; i < n; ++i)//和单个ch insert一样的逻辑,只是多了一遍覆盖
		{
			_str[pos + i] = str[i];
		}

	}
	//程序员美德之一:至少要对自己的程序进行冒烟测试,负责
	void string::erase(size_t pos, size_t len)
	{
		if (len >= _size - pos)//要删的字符个数大于等于有效字符个数
		{
			//删完了
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			size_t end = pos + len;
			while (end <= _size)
			{
				_str[end - len] = _str[end];
				++end;
			}
			_size -= len;
		}
	}

	size_t string::find(char ch, size_t pos)
	{
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
			{
				return i;
			}
		}
		return npos;
	}

	size_t string::find(const char* str, size_t pos)
	{
		const char* p = strstr(_str + pos, str);

	}


	void test_string1()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2;
		cout << s2.c_str() << endl;

		s1 += ' ';
		s1 += '+';
		s1 += "hello world";
		cout << s1.c_str() << endl;
	}

	void test_string2()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.insert(11, 3, 'x');
		cout << s1.c_str() << endl;

		s1.insert(6, 3, 'x');
		cout << s1.c_str() << endl;

		s1.insert(0, 3, 'x');
		cout << s1.c_str() << endl;

		string s2("hello world");
		cout << s2.c_str() << endl;

		s2.insert(11, "yyy");
		cout << s2.c_str() << endl;

		s2.insert(6, "yyy");
		cout << s2.c_str() << endl;

		s2.insert(0, "yyy");
		cout << s2.c_str() << endl;

	}

	void test_string3()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.erase(6, 2);
		cout << s1.c_str() << endl;

		s1.erase(6, 20);
		cout << s1.c_str() << endl;

		s1.erase(3);
		cout << s1.c_str() << endl;
	}

}