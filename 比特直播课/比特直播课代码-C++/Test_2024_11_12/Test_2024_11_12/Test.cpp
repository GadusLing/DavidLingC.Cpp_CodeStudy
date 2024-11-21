#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//class Date
//{
//public:
//	//void Init(Date* const this, int year, int month, int day) //实际上有个this指针哦
//	void Init(int year, int month, int day)
//	{
//		//this = nullptr;// 编译报错：error C2106 : “ = ” :左操作数必须为左值   this被const修饰，无法更改的
//		//this->_year = year;
//		//this->_month = month;
//		//this->_day = day; //不能在实参和形参的位置显⽰的写this指针(编译时编译器会处理)，但是可以在函数体内显⽰使⽤this指针
//		_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	// 这⾥只是声明，没有开空间，那为什么上面Init的调用能赋值，因为实际上有个this指针，谁（哪个对象）调用，就指向谁
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//	//d1.Init(&d1, 2024, 3, 31);//this指针不能显示的传，只能在类内部显示的用
//	d1.Init(2024, 3, 31);
//	d1.Print();
//
//	d2.Init(2024, 7, 5);
//	d2.Print();
//
//	return 0;
//}

//class A 
//{
//public:
//    void Print() 
//    {
//        cout << this << endl;
//        cout << "A::Print()" << endl;
//    }
//private:
//    int _a;
//};
//
//int main() {
//    A* p = nullptr;
//    p->Print();
//
//    return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << this << endl;
//		cout << _a << endl; //这里不崩溃可能是因为新版的编译器做了优化处理，但是注意看退出代码，它依然是一个问题代码
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//
//	return 0;
//}

//int main()
//{
//	const int i = 0;
//	int j = 0;
//	const char* str = "1111111";
//
//	//int* ptr = (int*)&i;
//
//	cout << &i << endl;
//	cout << &j << endl;
//	cout << (void*)str << endl;
//
//	return 0;
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//构造函数部分

//class Date
//{
//public:
//	//无参构造
//	//Date()//默认构造函数名和类名相同
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	// 2.带参构造函数
//	Date(int year = 1, int month = 1, int day = 1) //注意，如果这里写了缺省，可以和上面的参数同时存在，构成重载，但无参对象调用时会产生歧义
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}//但推理一下，如果有全缺省存在，是不是便不需要无参了呢？所以直接替代了无参构造的功能，实际使用中也不存在问题
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//Date d1();//无参的不要在后面带括号，编译器会报错
//	//会有歧义，比如 Date Func() 编译器无法确定这是一个函数声明还是对象定义
//
//	Date d1;
//	d1.Print();
//
//	Date d2(2024, 11, 12);
//	d2.Print();
//
//	Date d3(2024, 11);//少写参数也不行哦 除非构造那边写了缺省
//	d3.Print();
//
//	return 0;
//}


class Date
{
public:

	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	~Date()
	{

	}

private:
	int _year;
	int _month;
	int _day;
};


typedef int STDataType;
class Stack
{
public:
	Stack(int n)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = n;
		_top = 0;
	}

	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}

private:
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};

//两个栈实现一个队列的例子
class MyQueue
{
public:
	//不需要写构造，默认生成调用之前写的Stack构造
	//之前我们定义了默认构造的三种类型————
	//1.系统生成的无内容无参构造，只起调用其他已写好的默认构造的作用  (对于内置类型根据编译器初始化为0 or 随机值，可以视作不做处理，对于自定义类型，会调用自定义类型的默认构造)
	//2.手写的无参构造    3.手写的全缺省构造 三种只会存在一种
	//那么当我要构造一个双栈队列，但是栈那边我写的是有参构造，有了有参之后，系统不会提供默认构造了，此时我再构造双栈队列，就需要引入初始化列表，
	//调用时传参并用初始化列表构造，或者初始化列表写缺省也可以
	MyQueue(int n = 10)
		:_pushst(n)
		,_popst(n)
	{}
	~MyQueue()//即使显示写了析构函数，不管是不是有用的析构，都会调用原本自定义类型的析构，防止内存泄漏
	{
		cout << "~MyQueue" << endl;
	}

private:
	Stack _pushst;
	Stack _popst;
};


int main()
{
	Date d1;
	d1.Print();

	Stack st1(4);

	MyQueue mq1;


	return 0;
}











