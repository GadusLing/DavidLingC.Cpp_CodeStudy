#pragma once

#include<iostream>
using namespace std;

class Date
{
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

	// d1 += 天数
	Date& operator+=(int day);
	Date operator+(int day) const;

	// d1 -= 天数
	Date& operator-=(int day);
	Date operator-(int day) const;

private:
	int _year;
	int _month;
	int _day;
};
