#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

namespace LDWT
{
	const size_t string::nops = -1;

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
		while (end > pos + n - 1)
		{
			_str[end] = _str[end - n];
			--end;
		}

		for (size_t i = 0; i < n; ++i)
		{
			_str[pos + i] = ch;
		}
		_size += n;
	}

	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		size_t n = strlen(str);
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

		int end = _size + n;
		while (end > pos + n - 1)
		{
			_str[end] = _str[end - n];
			--end;
		}

		for (size_t i = 0; i < n; ++i)
		{
			_str[pos + i] = str[i];
		}
		_size += n;
	}

	void string::erase(size_t pos, size_t len)
	{


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

}