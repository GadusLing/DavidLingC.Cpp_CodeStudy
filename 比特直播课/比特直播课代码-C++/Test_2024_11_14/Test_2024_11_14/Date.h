#pragma once

#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	
public:
	Date(int year = 1900, int month = 1, int day = 1);//声明，缺省在这边给

	void Print() const;

	//Date& operator=(const Date& d)//这就是赋值运算符重载，但对于Date这种没用空间需求的，默认的赋值浅拷贝重载就够用了，所以这里不用写
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	
	//	return *this;
	//}


	//GetMonthDay直接在类中定义，因为是频繁调用的小函数，放入类中定义默认是内联，增加效率
	int GetMonthDay(int year, int month) const//获取月份天数
	{
		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//没有0月，所以下标0用-1代替
		//加上static，因为频繁调用但又不改变数值数据，不用反复创建临时数组，加static放入静态区，增加效率

		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//闰年二月29天 四年一闰，百年不闰，四百一闰
		{//month == 2放在前面，先判断是否二月，短路增加效率
			return 29;
		}
		return monthDayArray[month];
	}

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();//前置，前置++返回++之后的值，所以可以用引用
	Date operator++(int);//后置，C++规定这里的int只是为了形成一个重载，做区分作用，给不给值写不写int i都行，但一般不给，因为接不就收i都不会影响内部逻辑，内部不会用到这个参数，写个int纯粹是为了参数匹配去调用对应的函数

	Date& operator--();
	Date operator--(int);

	// d1 += 天数
	Date& operator+=(int day);
	Date operator+(int day) const;

	// d1 -= 天数
	Date& operator-=(int day);
	Date operator-(int day) const;

	//d1 - d2
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};


//流插入与流提取重载    不能放在类中重载哈,cout打印出来会反
ostream& operator<<(ostream& out, const Date& d);
