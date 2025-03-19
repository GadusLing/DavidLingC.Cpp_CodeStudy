#pragma once
#include<iostream>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
using namespace std;

class Date {
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	//全缺省的构造函数
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//运算符重载
	bool operator==(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);
	Date& operator = (const Date& d);

	//日期+天数
	Date& operator+=(int day);
	Date operator+(int day);

	//日期-天数
	Date& operator-=(int day);
	Date operator-(int day);

	//日期的前置和后置++
	Date& operator++();
	Date operator++(int);

	//日期的前置和后置--
	Date& operator--();
	Date operator--(int);

	//日期减日期=相差的天数
	int operator-(const Date& d);

	//void operator<<(ostream& out);


	//内联函数，获取year年第month的天数
	int GetDay(int year, int month) {
		assert(month > 0 && month < 13);
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//闰年的二月返回29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		return days[month];
	}
	void print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	int Getyear() {
		return _year;
	}
	int Getmonth() {
		return _month;
	}
	int Getday() {
		return _day;
	}
	//析构函数
	~Date() {
		_year = -1;
		_month = -1;
		_day = -1;
	}
private:
	int _year;
	int _month;
	int _day;
};