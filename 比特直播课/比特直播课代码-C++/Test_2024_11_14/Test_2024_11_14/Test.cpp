#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 编译报错：error C2652 : “Date”:⾮法的复制构造函数:第⼀个参数不应是“Date”
	//Date(Date d)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date(Date* d)
	{
		_year = d->_year;
		_month = d->_month;
		_day = d->_day;
	}
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

	return 0;
}