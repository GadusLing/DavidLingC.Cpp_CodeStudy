#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
//		cout << "Stack(int n = 4)" << endl;
//
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	// st2(st1)
//	Stack(const Stack& st)
//	{
//		// 需要对_a指向资源创建同样⼤的资源再拷⻉值
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity * sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//	}
//
//	void Pop()
//	{
//		_a[_top - 1] = -1;
//		--_top;
//	}
//
//	int Top()
//	{
//		return _a[_top - 1];
//	}
//
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//class MyQueue
//{
//public:
//	MyQueue(int n)
//		:_popst(n)
//		//,_pushst(n)
//	{
//		_p = 0;//不是那三类必须在初始化列表定义的，可以在其他地方定义，但是建议在初始化列表初始化，因为实际上大家都是在初始化列表初始化的
//	}
//
//private:
//	//成员变量声明
//	Stack _pushst = 100;//缺省值
//	Stack _popst;
//	//const int _i;//1.const 类型的变量只有在创建的时候有一次更改它的机会，所以一定要在定义时进行初始化，之后它就不可更改了
//	//int& _d;//2.引用在定义时必须要初始化，这是之前在引用里讲过的
//	//3.还一种情况比如调用的自定义结构体并没有默认构造（系统提供的、无参的、全缺省的不传参就能调用的都叫默认构造，所以可能那边写的有参的构造，此时系统就不提供默认构造了）
//	//那也就意味着此时你必须要传参数过去构造，此时也需要通过初始化列表来传参完成定义
//
//	int _p;
//	int _l{1000};//C++11支持声明时给缺省值，这个缺省值就会传给初始化列表
//	//C++11还支持花括号给缺省
//};
//
//int main()
//{
//	//对象整体定义
//	MyQueue q1(1000);
//
//	return 0;
//}
////////////////////////////////////////////////////////////////////


class A
{
public:

	// 构造函数explicit就不再⽀持隐式类型转换，但还是支持显示类型的转化————前面用（）转换
	// explicit A(int a1)
	A(int a1)
		:_a1(a1)
	{}

	//explicit A(int a1, int a2)
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}

	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}

private:
	int _a1 = 1;
	int _a2 = 2;
};

class Stack
{
public:
	void Push(const A& aa)
	{

	}
};

int main()
{
	// 1构造⼀个A的临时对象，再⽤这个临时对象拷⻉构造aa1
	// 编译器遇到连续构造+拷⻉构造->优化为直接构造
	A aa1 = 1;
	aa1.Print();

	const A& aa2 = 1;//临时对象具有常性，需要加const才能引用

	// C++11之后才⽀持多参数转化，用花括号括起来
	A aa3 = { 2,2 };

	Stack st;
	A aa7(7);
	st.Push(aa7);

	A aa8(8, 8);
	st.Push(aa8);

	st.Push(7);

	st.Push({ 8,8 });



	return 0;
}