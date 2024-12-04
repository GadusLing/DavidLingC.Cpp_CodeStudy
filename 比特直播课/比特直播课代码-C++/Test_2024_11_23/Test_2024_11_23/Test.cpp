#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//// 类模版
//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		_array = new T[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const T& data);
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//
//// 模版不建议声明和定义分离到两个文件.h 和.cpp会出现链接错误，具体原因后面会讲
//template<class T>
//void Stack<T>::Push(const T& data)
//{
//	// 扩容
//	_array[_size] = data;
//	++_size;
//}
//
//
//
//int main()
//{
//	Stack<int> st1;    // int
//	Stack<double> st2; // double
//	return 0;
//}
/////////////////////////////////////////////////

//内存管理讲漏了一个知识
//定位new

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};
//// 定位new/replacement new
//int main()
//{
//	//如果不让用new，要动态开辟怎么办？要么用operator new 要么 malloc
//	A* p1 = (A*)operator new(sizeof(A));
//	//那么这里有个问题，因为P1内部的_a是私有的，我没法初始化
//	//所以我得写一个Init函数来初始化，但是这会和构造的功能重复
//	//所以这个时候要用到定位new
//	//定位new表达式是在已分配的原始内存空间中调用构造函数初始化一个对象
//
//	//new(p1)A;
//	new(p1)A(10);
//
//	//delete p1;
//	p1->~A();//析构是支持显示调用的，但是构造不支持哈
//	operator delete(p1);
//
//
//	//所以上述所有的定位new实际上都封装到new里面了
//	//A* p2 = new A(10);//一句就搞定了
//
//	//那么在实际的开发过程中确实有些场景是不使用new的，比如内存池
//  //当用池化技术创建了内存池后，就会用定位new直接从已存在的内存池中调用内存操作，而不使用new or malloc再重新向系统要空间了
//
//	return 0;
//}
//////////////////////////////////////////////////////////

//STL部分
//开源
//Alexander Stepanov、Meng Lee 在惠普实验室完成的原始版本，本着开源精神，他们声明允许任何人任意运用、拷贝、修改、传播、商业使用这些代码，无需付费。
//唯一的条件就是也需要向原始版本一样做开源使用。 HP 版本--所有STL实现版本的始祖。

//原初互联网精神————开源，多么伟大
///////////////////////////////////////////////////////////////

//string部分

//auto func1()
//{
//	return 1;
//}
//
//auto func2()
//{
//	return func1();
//}
//
//auto func3()
//{
//	return func2();
//}
//
//int main()
//{
//	int x = 10;
//
//	auto y = &x;
//	auto* z = &x;//这种写法右边必须写指针
//
//	auto& m = x;
//	auto n = x;
//
//	auto aa = 1, bb = 2;
//	// 编译报错：error C3538: 在声明符列表中，“auto”必须始终推导为同一类型
//	//auto cc = 3, dd = 4.0;//一行声明多个对象，推导类型必须是一样的
//	// 编译报错：error C3318: “auto []”: 数组不能具有其中包含“auto”的元素类型
//
//
//	//auto array[] = { 4, 5, 6 };//auto不能推导数组
//
//	//那实际开发auto用来干啥？当类型很长的时候用auto
//	//std::map<std::string, std::string> dict = { { "apple", "苹果" },{ "orange","橙子" }, {"pear","梨"} };    //auto的用武之地
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	
//	//auto it = dict.begin();   用auto就很漂亮，所以auto的核心价值就是替代长类型
//	
//	//auto在之前某些时候不支持做参数，可以做返回值，但是最新的那一批编译器又支持做参数了
//	
//	//auto做返回值有个弊端，要谨慎，看上面的函数例子
//	auto ret = func3();
//	//这样层层嵌套的时候，写auto的人是爽了，但读的人会非常难受，一层层去查要
//
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////

//范围for

//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	//// C++98的遍历
//	//for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
//	//{
//	//	array[i] *= 2;
//	//}
//	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
//	//{
//	//	cout << array[i] << " ";
//	//}
//	//cout << endl;
//	////通常我们传统写循环都是用上面的方式，但学了范围for之后，我们可以像下面这样写
//
//	// C++11的遍历
//	for (auto& e : array)//不加引用e是拷贝，所以如果想要改变数据时需要用引用
//	{
//		e *= 2;
//	}
//	for (auto e : array)//auto 会根据数组元素的类型自动推导出变量 e 的类型    自动取数据赋值给给e、自动++、自动结束
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (const auto& e : array)//如果对象是自定义类型那么要调拷贝构造，所以如果不想拷贝又不想修改，就用经典的const auto& e 常量引用的写法来写
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//
//}
//范围for不仅可以遍历数组，还可以遍历容器，比如后面要学的string vector list之类的

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//string 部分
//性质上string在Cplusplus中被归于Miscellaneous杂项，也就是说它严格来说不属于STL，可能是由于一些历史原因，string是早先开发的，但是string从功能上是一个标标准准的容器，之后也可以视作为容器，没有问题

//string底层是用 basic_string<char> 的类来typedef的模板
//basic_string<char>是一个用来管理char数组的，类似char顺序表的一个东西

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
	
	for (size_t i = 0; i < s2.length(); i++)//size length效果是一样的，历史遗留原因，早起开发的时候写的是length，后面整合了之后就都用size了，了解一下即可
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

int main()
{
	test_string1();

	return 0;
}























