#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

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


class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//Date(const Date& d)
	//{
	//	cout << "Date(const Date& d)" << endl;

	//	this->_year = d._year;
	//	this->_month = d._month;
	//	this->_day = d._day;
	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2024, 11, 14);
	Date d2(d1);
	d1.Print();
	d2.Print();//如果不手动添加拷贝构造，系统自动提供的拷贝构造会进行浅（值）拷贝，所以d2里面也有一样的值


	return 0;
}