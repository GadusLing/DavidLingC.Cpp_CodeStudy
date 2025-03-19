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
	//ȫȱʡ�Ĺ��캯��
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//���������
	bool operator==(const Date& d);
	bool operator<(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);
	Date& operator = (const Date& d);

	//����+����
	Date& operator+=(int day);
	Date operator+(int day);

	//����-����
	Date& operator-=(int day);
	Date operator-(int day);

	//���ڵ�ǰ�úͺ���++
	Date& operator++();
	Date operator++(int);

	//���ڵ�ǰ�úͺ���--
	Date& operator--();
	Date operator--(int);

	//���ڼ�����=��������
	int operator-(const Date& d);

	//void operator<<(ostream& out);


	//������������ȡyear���month������
	int GetDay(int year, int month) {
		assert(month > 0 && month < 13);
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//����Ķ��·���29
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
	//��������
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