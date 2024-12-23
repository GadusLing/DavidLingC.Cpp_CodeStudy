#pragma once

#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>


//模拟实现一个简化的string类


namespace LDWT//创建一个命名空间 LDWT，用于将内部代码与其他代码隔离，防止命名冲突。
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;//const迭代器是单独用const_命名哦

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;//这里注意end迭代器返回的是一个char*类型的指针,所以不能直接写return _size,要用_str + _szie
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		//string()//无参构造函数
			//	:_str(new char[1]{'\0'})//new char[1]: 动态分配一个字符数组，大小为 1。 {'\0'}: 初始化为字符串结束符 '\0',相当于占位符
			//	, _size(0)//_size: 当前字符串的长度（不包括结束符 '\0'）。
			//	,_capacity(0)//_capacity: 当前字符串分配的存储空间大小。
			//{}

		string(const char* str = "");//全缺省
		string(size_t n, char ch);

		const char* c_str() const//返回字符串的 C 风格表示。
		{
			return _str;//返回 _str 的地址，供外部访问字符串内容。
		}

		string(const string& s);

		string& operator=(const string& s);

		~string();

		void clear()
		{
			//erase();//调一下erase就行了
			_str[0] = '\0';//自己写也很简单
			_size = 0;
		}

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, size_t n, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);

		size_t find(char ch, size_t pos = 0);
		size_t find(const char* ch, size_t pos = 0);

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		string substr(size_t pos, size_t len = npos);

		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;
		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;


	private:
		//声明
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos;
	};

	//流插入和流提取,重载为全局记得
	ostream& operator<<(ostream& out, const string& s);
	ostream& operator>>(ostream& out, string& s);

	istream& getline(istream& in, string& s, char delim = '\n');


	void test_string1();
	void test_string2();
	void test_string3();
	void test_string4();
	void test_string5();
	void test_string6();


}