#pragma once

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);//������ȱʡ����߸�

	void Print() const;

	//Date& operator=(const Date& d)//����Ǹ�ֵ��������أ�������Date����û�ÿռ�����ģ�Ĭ�ϵĸ�ֵǳ�������ؾ͹����ˣ��������ﲻ��д
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	
	//	return *this;
	//}


	//GetMonthDayֱ�������ж��壬��Ϊ��Ƶ�����õ�С�������������ж���Ĭ��������������Ч��
	int GetMonthDay(int year, int month) const//��ȡ�·�����
	{
		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//û��0�£������±�0��-1����
		//����static����ΪƵ�����õ��ֲ��ı���ֵ���ݣ����÷���������ʱ���飬��static���뾲̬��������Ч��

		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//�������29�� ����һ�򣬰��겻���İ�һ��
		{//month == 2����ǰ�棬���ж��Ƿ���£���·����Ч��
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

	// d1 += ����
	Date& operator+=(int day);
	Date operator+(int day) const;

	// d1 -= ����
	Date& operator-=(int day);
	Date operator-(int day) const;

private:
	int _year;
	int _month;
	int _day;
};
