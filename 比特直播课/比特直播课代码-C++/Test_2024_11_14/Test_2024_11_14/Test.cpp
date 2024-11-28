#define _CRT_SECURE_NO_WARNINGS

#include"Date.h"

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 编译报错：error C2652 : “Date”:⾮法的复制构造函数:第⼀个参数不应是“Date”
//	//Date d2(d1)
//	//这就是拷贝构造函数，这里为啥要用引用呢？看下面的func1例子
//	Date(const Date& d)//, int x = 1)//拷贝构造也可以有缺省值哈，这也叫拷贝构造。虽然一般不这么写
//	{//那这里为啥最好加const呢？因为健壮性，要防止在函数内实现代码时的误写，把==写成=之类的，原本拷贝张三过来给你用作构成李四，结果你构成李四时把张三也改了，这显然不合理
//	 //并且加了const之后，原本一些const对象也可以当参数传过来了
//		cout << "Date(const Date& d)" << endl;
//
//		this->_year = d._year;//d就是传过来的参数d1  this->是谁调用这个函数，this就指向谁，所以this指向d2
//		this->_month = d._month;//那么这一段的意思就是，把d1里面的year  month  day的数据，赋值给d2中对应的成员
//		this->_day = d._day;//以此完成拷贝构造，这里的this一般不写哈，入门的小白为了区分清楚会写，后期熟悉了可以不写
//	}
//	Date(Date* d)//传地址也可以，但这就不叫拷贝构造了
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void func1(Date d)//那么为什么这里不引用传参会有问题呢？因为会无穷递归
//{
//	//首先，当我调用func1，把d1传参，传给d，我就要调用拷贝构造
//	//然后，当我调用拷贝构造，而拷贝构造那边如果写的不是引用，而是传值，那我传给拷贝构造的那个参数，是不是又要调用拷贝构造
//	//那拷贝构造又调拷贝构造，如此递归，传出去的d1回不来了，就死递归了
//	//所以如果拷贝构造那里用引用传参，引用相当于别名，用别名就不需要拷贝对象，直接把原参数地址传过去了，就不会有再需要调拷贝构造去传参的一系列问题了
//}
//
//Date func2()
//{
//	Date d;
//	//...
//	return d;//传值返回也有拷贝构造哦，只是像VS2022比较新的这种编译器，做了优化， 可能演示不出来，实际上这里按照C++的语法也会调用拷贝构造
//	//为什么传值返回有拷贝构造？因为实际上并不是返回的d，d出了这个函数之后就销毁了，所以这里返回的是拷贝d的临时对象
//}
//
//
//int main()
//{
//	Date d1(2024, 11, 14);
//	Date d2(d1);
//
//	func1(d1);//传值传参和传值返回都要形成一个临时对象（变量），所以C++规定自定义类型要调用自定义类型的拷贝构造 这里传值d1，实际是拷贝d1构造后传给上面func1所接受的形参d；
//	//实际上内置类型也拷贝了，只不过是编译器自己完成了
//	func2();
//
//	Date d3(&d1);
//
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////


//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date(const Date& d)
//	//{
//	//	cout << "Date(const Date& d)" << endl;
//
//	//	this->_year = d._year;
//	//	this->_month = d._month;
//	//	this->_day = d._day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)
//	{
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
////
////class MyQueue
////{
////public:
////private:
////	Stack _pushst;
////	Stack _popst;
////
////};
////
////
////int main()
////{
////	Date d1(2024, 11, 14);
////	Date d2(d1);
////	d1.Print();
////	d2.Print();//如果不手动添加拷贝构造，系统自动提供的拷贝构造会进行浅（值）拷贝，所以d2里面也有一样的值
////
////	Stack st1;
////	st1.Push(1);
////	st1.Push(2);
////	st1.Push(3);
////	st1.Push(4);
////
////	Stack st2(st1);//这里就是典型的浅拷贝所引发的问题，因为浅拷贝，两份数据的地址依然是同一块空间，当调用析构时会析构两次
////	//同时，还会存在两份数据都会改变一块空间的情况，修改一份数据，会影响另一份，比如调用st1的pop，结果再访问st2时，由于共用空间，st2的数据实际上也是修改过的，这显然不合理
////
////	//所以为了解决这两个问题，就需要进行深拷贝
////
////	//所以总结一下，对于一些类，它的私有成员如果只是一些内置类型，譬如日期类，那么不用管理它的拷贝构造，系统提供的就能使用
////	//但是对于需要开辟空间的类型，类内部有指针、引用这种成员的，就要注意深浅拷贝的问题
////	//这里有一个小技巧，凡是需要显示实现析构释放资源的类，必然意味着它有空间管理的需求，所以也就意味着，它必然需要显示写拷贝构造
////
////	MyQueue q1;
////	MyQueue q2(q1);//那像双栈队列MyQueue这样的，基本都是自定义类型的类，它既不用写构造，又不用写拷贝、析构，因为它全部都是在调用之前类中已经写好的函数
////
////	return 0;
////}
///////////////////////////////////////////////////////////////////////////
//
////Stack func1()
////{
////	Stack st1;
////	st1.Push(1);
////	st1.Push(2);
////	st1.Push(3);
////	st1.Push(4);
////
////	return st1;
////}
////
////int main()
////{
////	//Stack st1;
////	//Stack st2(st1);//拷贝构造的两种写法
////	//Stack st3 = st1;//() 和 = 都是拷贝构造，只是()的写法更标准一些
////
////	//Stack st4(func1());
////	Stack st5 = func1();
////	cout << st5.Top() << endl;//这里如果func1使用的是引用传参，那传回来的时候st1就销毁了，所以会得到一个野引用
////	//所以再次强调，使用引用返回要慎重
////
////
////	return 0;
////}
///////////////////////////////////////////////////

//运算符重载内容
 
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date(const Date& d)
//	//{
//	//	cout << "Date(const Date& d)" << endl;
//
//	//	this->_year = d._year;
//	//	this->_month = d._month;
//	//	this->_day = d._day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	//通常C++喜欢直接把运算符重载函数放在类中，这样就能直接访问私有成员了，但是此处要注意，重载运算符函数规定只能用一个参数，所以对比全局的重载，要稍稍改变一下写法
//	bool operator==(const Date& d)
//	{
//		return this->_year == d._year//这里的this->可以不写，这里方便认知写上
//			&& this->_month == d._month
//			&& this->_day == d._day;
//	}
//
//
//	int GetYear() const //这也是一种解决私有成员无法访问的方式，JAVA中喜欢使用类似的方式
//	{
//		return _year;
//	}
//	int GetMonth() const
//	{
//		return _month;
//	}
//	int GetDay() const
//	{
//		return _day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////bool operator==(const Date& x1, const Date& x2)
////{
////	return x1.GetYear() == x2.GetYear()
////		&& x1.GetMonth() == x2.GetMonth()
////		&& x1.GetDay() == x2.GetDay();
////}
//
//int operator-(const Date& x1,const Date& x2)
//{
//
//	return 0;
//}
//
//
//int main()
//{
//	Date d1(2024, 11, 14);
//	Date d2(2024, 11, 11);
//
//
//	//bool ret1 = operator==(d1, d2);
//	bool ret1 = d1 == d2;
//	//bool ret2 = d1.operator==(d2);
//	bool ret2 = d1 == d2;
//	cout << ret1 << endl;
//	cout << ret2 << endl;
//
//
//	//int i = 1, j = 2;
//
//	//int ret1 = i + j;
//	//bool ret2 = i == j;
//	//bool ret3 = i ^ j;
//
//	//cout << ret1 << endl;
//	//cout << ret2 << endl;
//	//cout << ret3 << endl;
//
//
//	return 0;
//}
///////////////////////////////////////////////////////////////////

////.*操作符，取成员函数指针
//class A
//{
//public:
//	void func1()
//	{
//		cout << "A::func1()" << endl;
//	}
//};
//
//void func2()
//{
//	cout << "func2()" << endl;
//}
//
//typedef void(A::*PF)(); //成员函数指针类型
//typedef void(*PF2)(); //普通函数指针类型
//
//int main()
//{
//	PF pf1 = &A::func1;// C++规定普通函数名就是函数指针，而成员函数要加&才能取到函数指针
//	A obj;//定义ob类对象temp
//	(obj.*pf1)();// 对象调⽤成员函数指针时，使⽤.*运算符
//
//	PF2 pf2 = func2;
//	(*pf2)();//普通函数调用和成员函数调用最大的区别就是普通函数没有this指针
//
//
//	return 0;
//}
///////////////////////////////////////////////////////////////////////

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//
//		this->_year = d._year;
//		this->_month = d._month;
//		this->_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////d1 - d2
//int operator-(const Date& d1, const Date& d2)//可以重载日期减日期，得出来的是天数int
//{
//	return 0;
//}
//
////d1 - 100
//Date operator-(const Date& d1, int day)//也可以重载日期减天数，得出来的是日期Date
//{
//	Date ret;
//
//	return ret;
//}
//
//int main()
//{
//
//
//	return 0;
//}


int main()
{
	Date d1(2024, 11, 14);
	Date d2 = d1 + 50;
	d2.Print();
	d1.Print();
	d1 += 5000;
	d1.Print();
	cout << "\n" << endl;

	Date d3(2024, 11, 16);
	Date d4 = d3 - 50;
	d4.Print();
	d3.Print();
	d3 -= 5000;
	d3.Print();

	cout << (d1 > d3) << endl;//cout << d1 > d2 << endl;这样编不过，因为流插入提取的优先级要高于比较符号，所以加个括号
	cout << (d1 == d3) << endl;
	cout << (d1 < d3) << endl;
	cout << (d1 >= d3) << endl;
	cout << (d1 <= d3) << endl;
	cout << (d1 != d3) << endl;

	Date d5(2024, 11, 16);
	Date d6= ++d5;
	//Date d6= d5.operator++();
	Date d7= d5++;
	//Date d7= d5.operator++(5);//显式调用写出来就是这个样子，这里的int值随便你填，0，1，2....都行，只要是个int
	d5.Print();
	d6.Print();
	d7.Print();

	d6 = --d5;
	d7 = d5--;
	d5.Print();
	d6.Print();
	d7.Print();

	Date d8(2035, 1, 15);
	Date d9(2024, 1, 27);
	cout << d9 - d8 << endl;

	cout << d8 << " 和 " << d9 << endl << d5 << endl;


	cin >> d8 >> d9;
	cout << d8 << " 和 "  << d9 << endl;

	return 0;
}