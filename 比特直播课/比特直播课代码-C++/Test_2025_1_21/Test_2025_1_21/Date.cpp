
#include"Date.h"
bool Date::operator==(const Date& d) {
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)const {
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator<=(const Date& d) {
	return (*this == d) || (*this < d);
}

bool Date::operator>(const Date& d) {
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) {
	return (*this == d) || (*this) > d;
}
bool Date::operator!=(const Date& d) {
	return !(*this == d);
}

Date& Date::operator = (const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day) {
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetDay(_year, _month))
	{
		_day -= GetDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator+(int day) {
	Date a = *this;
	a += day;
	return a;
}
Date& Date::operator-=(int day) {
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day) {
	Date a = *this;
	a -= day;
	return a;
}
Date& Date::operator++() {
	return *this += 1;
}

Date Date::operator++(int) {
	Date a = *this;
	*this += 1;
	return a;
}

Date& Date::operator--() {
	return *this -= 1;
}

Date Date::operator--(int) {
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

int Date::operator-(const Date& d) {
	int day = 0;
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (min != max)
	{
		++min;
		++day;
	}
	return day * flag;
}

ostream& operator<<(ostream& out, Date& d) {
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}