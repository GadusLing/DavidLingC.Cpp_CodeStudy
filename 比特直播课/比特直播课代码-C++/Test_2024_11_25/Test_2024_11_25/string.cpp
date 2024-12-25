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

	//string::string(const string& s)//拷贝构造,传统写法
	//{
	//	_str = new char[s._capacity + 1];
	//	strcpy(_str, s._str);
	//	_size = s._size;
	//	_capacity = s._capacity;
	//}	
	
	void string::swap(string& s)//现代写法
	{
		std::swap(_str, s._str);//要加std，因为搜索顺序是局部-全局，先搜局部自己调自己参数匹配不上，而我是要用std里面的swap
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	string::string(const string& s)//拷贝构造,现代写法
	{
		string tmp(s._str);
		swap(tmp);
	}

	//string& string::operator=(const string& s)//赋值  "="重载 的深拷贝
	//{
	//	if (this != &s)//防止一些神人自己给自己赋值,那上来就把自己的空间delete了
	//	{
	//		//现代写法
	//		string tmp(s._str);
	//		swap(tmp);

	//		//传统写法
	//		//delete[] _str;
	//		//_str = new char[s._capacity + 1];//时刻记住开空间+1哈,因为capacity不包含\0
	//		//strcpy(_str, s._str);
	//		//_size = s._size;
	//		//_capacity = s._capacity;
	//	}
	//	return *this;
	//}	
	
	string& string::operator=(string s)//更简洁的赋值现代写法
	{//没有用const引用 而是采用传值传参调用拷贝构造的特性来创建临时对象
		swap(s);
		return *this;
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
			cout << "reserve:" << n << endl;
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

		size_t end = _size + n;
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
		if (p == nullptr)
		{
			return npos;
		}
		else
		{
			return p - _str; //指针相减得到的是它们之间所差元素的个数，也就是下标数,用竖杠下标的方式来理解
		}
	}

	string string::substr(size_t pos, size_t len)
	{
		size_t leftlen = _size - pos;
		if (len > leftlen)
		{
			len = leftlen;
		}
		string tmp;
		tmp.reserve(len);

		for (size_t i = pos; i < pos + len; i++)//这里注意是pos+len哦
		{
			tmp += _str[i];
		}
		return tmp;//值传递要用拷贝构造哦,要写拷贝不然会报错,当然编译器够新会优化,但要注意这种实际语法上的错误
	}

	bool string::operator==(const string& s) const
	{
		return strcmp(_str, s._str) == 0;
	}

	bool string::operator!=(const string& s) const
	{
		return !(*this == s);
	}

	bool string::operator<(const string& s) const
	{
		return strcmp(_str, s._str) < 0;
	}

	bool string::operator<=(const string& s) const
	{
		return (*this < s || *this == s);
	}

	bool string::operator>(const string& s) const 
	{
		return !(*this <= s);
	}

	bool string::operator>=(const string& s) const
	{
		return !(*this < s);
	}

	ostream& operator<<(ostream& out, const string& s)//流插入,重载为全局记得
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s) //流提取
	{
		s.clear();

		const size_t N = 1024;
		char buff[N];//开一段缓冲区,避免短串浪费空间,而长串也会从大基数开始增容,避免频繁增容
		int i = 0;
		char ch;
		//in >> ch; //std::cin 和 scanf 的行为类似,在默认情况下会自动跳过空格、换行符以及其他空白字符,导致读不到终止符不能终止程序,所以这里不能用>>
		ch = in.get();//用get会一个一个字符的去读,所以就能读到终止符了
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}

	istream& getline(istream& in, string& s, char delim)
	{
		s.clear();

		const size_t N = 1024;
		char buff[N];
		int i = 0;
		char ch;
		ch = in.get();
		while (ch != delim)//这里终止符缺省是\n,由于get是一个字符一个字符去读,所以\n会被拆成\和n,此时就能在控制台打印出来的,但如果回车
			//就会被视做\n换行符
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
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

		string s2("hello helleoo");
		cout << s2.find('e') << endl;
		cout << s2.find("helle") << endl;
	}

	void test_string4()
	{
		string s1("hello world");
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
			cout << s1[i] << " ";
		}
		cout << endl;

		string::iterator it = s1.begin();//迭代器的方式来控制
		while (it != s1.end())//当然只有底层是数组的时候,物理区间上是连续的可以这么玩哈
		{
			cout << *it++ << " ";
		}
		cout << endl;

		for (auto e : s1)//支持迭代器就支持范围for哦
		{
			cout << e << " ";
		}
		cout << endl;

		const string s2("hello world");
		for (auto e : s2)//这里const的串想实现范围for就要用const的迭代器哦,如果之前没有实现const迭代器,这里就会报错
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_string5()
	{
		string s1("hello world");

		string sub1 = s1.substr(6, 3);
		cout << sub1.c_str() << endl;

		string sub2 = s1.substr(6, 300);
		cout << sub2.c_str() << endl;

		string sub3 = s1.substr(6);
		cout << sub3.c_str() << endl;

		string s2("hello ldwxxxxxxxxxxxxxxxxxxx");
		s1 = s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		s1 = s1;
		cout << s1.c_str() << endl;
	}

	void test_string6()
	{
		//string s1("hello world");
		//string s2("hello dw");

		//cout << s1 << endl;
		//cout << s2 << endl;

		//string s3;
		//cin >> s3;
		//cout << s3 << endl;
		
		string s1, s2;
		cin >> s1 >> s2;
		cout << s1 << endl;
		cout << s2 << endl;

		string s3;
		//getline(cin, s3,'\n');
		getline(cin, s3, '!');
		cout << s3 << endl;
	}
	void test_string7()
	{
		string s1("111111111111");
		string s2(s1);
		cout << s1 << endl;
		cout << s2 << endl;

		const string s3("2222222222222222222222222");
		s1 = s3;
		cout << s3 << endl;
		cout << s1 << endl;


	}

}














