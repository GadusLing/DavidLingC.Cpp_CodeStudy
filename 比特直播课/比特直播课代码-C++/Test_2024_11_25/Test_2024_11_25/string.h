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
		//string()//无参构造函数
			//	:_str(new char[1]{'\0'})//new char[1]: 动态分配一个字符数组，大小为 1。 {'\0'}: 初始化为字符串结束符 '\0',相当于占位符
			//	, _size(0)//_size: 当前字符串的长度（不包括结束符 '\0'）。
			//	,_capacity(0)//_capacity: 当前字符串分配的存储空间大小。
			//{}

		string(const char* str = "");//全缺省

		const char* c_str() const//返回字符串的 C 风格表示。
		{
			return _str;//返回 _str 的地址，供外部访问字符串内容。
		}

		~string();

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, size_t n, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = nops);

	private:
		//声明
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t nops;
	};

	void test_string1();
	void test_string2();
}