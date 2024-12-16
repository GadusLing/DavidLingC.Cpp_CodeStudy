#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


#include<string>
#include<assert.h>
#include<list>

namespace LDW
{
	class string
	{
	public:
		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

	private:
		char _buff[16];
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}


void test_string1()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	//string s4(s2, 6, 1000);
	string s4(s2, 6);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

	//1.下标 + []
	for (size_t i = 0; i < s2.size(); i++)
	{
		s2[i] += 1;
		//等价 s2.operator[](i) += 1;
	}

	for (size_t i = 0; i < s2.length(); i++)//size length效果是一样的，历史遗留原因，早先开发的时候写的是length，后面整合了之后就都用size了，了解一下即可
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	const string s5("xxxxxxx");
	//s5[0] = 'y';//string::operator[] 方括号有两个接口，一个负责普通的，一个是const的，所以如果const对象调用，它是不能修改内容的


	cout << s2.size() << endl;//size不包含\0
	//2.迭代器
	//string::iterator it = s2.begin();//begin指向第一个数据的位置，end指向最后一个数据下一个位置
	auto it = s2.begin();//这里用auto就很合适
	while (it != s2.end())//这里!=能否换成<呢？在string这个部分可以，但不推荐，因为不是通用写法，string底层是数组，是一块连续的储存空间，但比如list链表这种没办法保证后面的地址一定比前面大，所以推荐写!=
	{
		cout << *it << " ";//迭代器是一个行为像指针一样的对象，有时候可能是指针，有时候不是指针，但行为是类似指针的
		++it;
	}
	cout << endl;

	//string::const_iterator it5 = s5.begin();//迭代器也有两个版本，普通版和const版
	auto it5 = s5.begin();//这里用auto就很合适
	while (it5 != s5.end())
	{
		//*it5 += 1;指向的内容不能修改   const在左是修饰指向内容的，指向内容不可修改
		cout << *it5 << " ";
		++it5;
	}
	cout << endl;

	//有下标+[]这么方便为啥还要迭代器呢？
	//因为下标+[]是特殊类的访问方式，而迭代器是通用的访问方式
	//下标+[]限定底层是数组，或者类数组的结构中才能使用，但比如链表就没办法使用，而这种情况就要用到迭代器这种通用的访问方式
	list<int> lt = { 1,2,3,4,5 };
	list<int>::iterator it1 = lt.begin();
	while (it1 != lt.end())
	{
		*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	//反向迭代器，不是指针，是类封装的，因为如果是指针，内部的++就没办法解释了，怎么能++倒着走，所以肯定是封装的，是++重载的
	string::reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		cout << *rit << " ";
		++rit;//这里是++，别搞错了
	}
	cout << endl;

	//范围for访问容器
	for (auto ch : s2)//范围for底层其实很朴素，就是迭代器
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test_string2()
{
	string s1;
	cout << s1.max_size() << endl;

	string s2("hello world");
	cout << s2.size() << endl;//size  不包含\0   实际存了多少个有效字符 
	cout << s2.capacity() << endl;//capacity 不包含\0   能存多少个有效字符

	s2.clear();//clear只清理数据，一般不释放空间
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2[15];//报错是断言
	//s2.at(15);//报错是抛异常

}

void test_string3()
{
	string s1;
	s1.push_back('x');
	s1.push_back('x');
	s1.push_back('x');
	s1.append("yyyyy");
	cout << s1 << endl;

	string s2("hello world");
	s1.append(s2.begin(), s2.end());//迭代器插入
	cout << s1 << endl;

	s1.append(s2.begin() + 6, s2.end());//迭代器从字符串中段插入，这里可以用+
	cout << s1 << endl;

	s1 += ' ';
	s1 += "zzz";
	s1 += s2;
	cout << s1 << endl;//+=类似于C种的strcat 但strcat是个很矬的接口，少用
	//一是因为strcat是遍历找到\0后追加，其次是它不会扩容，所以效率和实用性都很差
	//但是+=是用string类里的size的地址去处理的，少了遍历效率高，并且会自己管理空间，不用手动调整

}

void test_string4()
{
	string s1("1111111");
	string s2("22222222222222222222222222222222222222222222222");
	s2.reserve(100);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	s2.reserve(40);//vs下面的选择，当reserve传参比capacity小,或者比size小的时候，是不会缩的,但是Linux g++会缩
	cout << s2.size() << endl;//缩也是缩到size的大小哈,因为reserve的核心就是不改变原内容,所以最多只能缩到原size的大小
	cout << s2.capacity() << endl;
	//日常用reserve主要是扩容而非缩容,缩容去调shrink_to_fit,因为reserve是否缩容不确定,取决编译器


	string s;
	s.reserve(1000);//reserve的主要功能是，我知道我要插入多少数据，我提前把空间开好，减少扩容。

	size_t sz = s.capacity();
	cout << "capacity changed:" << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{	
		//s.push back('c');
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}//除了最开始是2倍增容，后面的结果基本上是一个1.5倍的增容
//为了处理一些内存碎片的问题
//string 内部有两段存储机制。当字符串的字符数小于 16 时，数据会直接存储在对象内部的数组中，不需要动态申请内存。这样就相当于数据存储在对象本身的 buffer 中。
//而当字符数大于等于 16 时，就不再使用这种内置存储机制，而是通过动态分配内存的方式来存储数据，1.5倍实际是堆上的扩容机制;


void test_string5()
{
	//resize

	string s2("22222222");
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
	
	s2.resize(3);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
	
	s2.resize(13);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;

	s2.resize(23);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
	//size = 8,capacity = 15
	//resize(3);//比size小，删除数据
	//resize(13)比size大，插入数据，传了参就插参数字符，没传就插默认初始化字符\0。
	//resize(20)比capacity还要大,扩容加插入数据。

}

void test_string6()
{
	string s1("22222222");
	cout << s1 << endl;
	//string少用头插和中插,因为连续的物理空间要挪数据,是一个On复杂度的接口
	s1.insert(0, "hello");
	cout << s1 << endl;

	s1.insert(0, 1 , 'x');//在0位置插1个x,变相实现了头插
	cout << s1 << endl;

	s1.erase(5, 2);
	cout << s1 << endl;

	s1.erase(5);
	cout << s1 << endl;

}

void test_string7()
{
	string s1("22222222");
	string s2("33333333");

	//s1 = s2;
	s1.assign(s2);

	cout << s1 << endl;
	cout << s2 << endl;
}




int main()
{
	//while (1) 
	//{
	//	try
	//	{
	//		int i = 0;
	//		cin >> i;//这就是最典型的阻塞接口，不输入数据不执行下一步的

	//		//test_string1();
	//		test_string2();
	//	}
	//	catch (const exception& e)
	//	{
	//		cout << e.what() << endl;
	//	}
	//}

	//test_string3();

	//test_string4();

	//test_string5();

	//test_string6();

	test_string7();


	
	return 0;
}