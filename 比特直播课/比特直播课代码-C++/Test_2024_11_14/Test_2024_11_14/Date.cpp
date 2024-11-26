#define _CRT_SECURE_NO_WARNINGS

#include"Date.h"

Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
    //if (!CheckDate())
    //{
    //    cout << "⽇期⾮法" << endl;
    //}
}

void Date::Print() const
{
    cout << _year << "-" << _month << "-" << _day << endl;
}

bool Date::operator<(const Date& d) const
{
    return !(*this >= d);
}

bool Date::operator<=(const Date& d) const
{
    return !(*this > d);
}

bool Date::operator>(const Date& d) const
{
    if (_year > d._year)//年大为大
    {
        return true;
    }
    else if (_year == d._year && _month > d._month)//年等，月大为大
    {
        return true;
    }
    else if (_year == d._year && _month == d._month)//年月都等，天大为大
    {
        return _day > d._day;
    }

    return false;//都不大，则等or小
}

bool Date::operator>=(const Date& d) const
{
    return *this > d || *this == d;
}

bool Date::operator==(const Date& d) const//类似的判断逻辑理论上只要实现两个> == or < ==，其他的就能直接调用已实现的函数，再加上一些取反判断就能简化实现了
{
    return _year == d._year
        && _month == d._month
        && _day == d._day;
}

bool Date::operator!=(const Date& d) const
{
    return !(*this == d);
}


// d1 += 天数
Date& Date::operator+=(int day)
{
    if (day < 0)
    {
        return *this -= (-day);
    }

    _day += day;

    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        ++_month;
        if (_month == 13)
        {
            ++_year;
            _month = 1;
        }
    }

    return *this;//同+法逻辑一致，只不过做计算和返回值的是this指针，用this就会影响原本调用该函数的参数
}

//Date Date::operator+(int day) const//+不可以用引用返回哦，tmp出了作用域就销毁了，返回结果就行了，但是像+=就可以
//{
//    Date tmp(*this);//用*this解引用this中的Date出来拷贝构造一个tmp
//    tmp._day += day;//加上给的天数
//
//    while (tmp._day > GetMonthDay(tmp._year, tmp._month))//循环判断加完的天数是否符合该年月中的正确天数
//    {
//        tmp._day -= GetMonthDay(tmp._year, tmp._month);//如果大，就用剩余天数 - 本月应有的满天数
//        ++tmp._month;//进位月份
//        if (tmp._month == 13)//月份超过12个月则进位年份
//        {
//            ++tmp._year;
//            tmp._month = 1;//重置月份为下一年的一月
//        }
//    }//循环至此，天数若还有剩余，超过了当年月的应有满天数，则继续循环，直至天数在正常范围内，此时年月也由于进位而进到了正确的位置
//
//    return tmp;//最后返回tmp中的值
//}

Date Date::operator+(int day) const
{
    Date tmp(*this);
    tmp += day;//+=和+的逻辑几乎一致，最大的区别就是+=改变this内容，而+是temp拷贝，不改变原this的内容，所以直接在+内部做拷贝，然后复用+=的代码，再传拷贝的temp就行了

    return tmp;
}

//Date& Date::operator+=(int day)//写了+之后，+=也能复用+的代码哦，但是写+=，在+中复用会好一些，因为+=是引用返回，复用的话拷贝开销更小
//{
//    *this = *this + day;
//    return *this;
//}


// d1 -= 天数
Date& Date::operator-=(int day)
{
    if (day < 0)
    {
        return *this += (-day);
    }

    _day -= day;//本月天数-=传过来的天数

    while (_day < 1)//如果减完，天数为0or负，表示要退位月年，进入退位循环
    {
        --_month;//先退位月，这样下面的GetMonthDay才能获取到正确的月份天数
        //比如11月14 - 14天，应该是10月31，此时_day为0，小于1进入循环，如果不先退位月，那么_day 实际上+= 了11月的30天==30，此时再退位到10月份，就变成了10月30号，所以要先退位成10月，变成10月的31

        if (_month == 0)//这里注意，因为是进来就先--month，所以if判断要放在天数加减之前，防止month被减成了0的情况，因为在月份数组定义那边0月是用-1值来标记的，不先判断的话，月份输出是会有问题的
        {
            --_year;
            _month = 12;
        }

        _day += GetMonthDay(_year, _month);//获取对应月份最大天数加到之前的负数_day上，如果某次循环到这里_day变正了，那就证明已经到了正确的月份了
        
    }

    return *this;
}

//Date Date::operator-(int day) const
//{
//    Date tmp(*this);
//    tmp._day -= day;
//
//    while (tmp._day < 1)
//    {
//        --tmp._month;
//
//        if (tmp._month == 0)
//        {
//            --tmp._year;
//            tmp._month = 12;
//        }
//
//        tmp._day += GetMonthDay(tmp._year, tmp._month);
//        
//    }
//
//    return tmp;
//}

Date Date::operator-(int day) const
{
    Date tmp(*this);
    tmp -= day;

    return tmp;
}