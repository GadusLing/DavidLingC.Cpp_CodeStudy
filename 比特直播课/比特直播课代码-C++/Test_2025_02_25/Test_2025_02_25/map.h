#pragma once

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int testset()
{
	map<string, string> dict;

	pair<string, string> kv1("sort", "排序");// 有名对象构造
	dict.insert(kv1);

	dict.insert(pair<string, string>("string", "字符串"));// 匿名对象构造

	dict.insert(make_pair("pair", "一对"));// c++98最喜欢的make_pair函数模板  自动推导类型生成匿名对象构造

	//c++11喜欢的方式
	dict.insert({ "left", "左边" });// 这个不是initializer_list构造，是c++11支持的 多参数构造函数的隐式类型转换

	auto it = dict.begin();
	while (it != dict.end())
	{
		// map 的迭代器指向的是一个 pair<const Key, Value>
		// 所以 it->first 表示 key，it->second 表示 value

		 //cout << (*it).first <<":"<<(*it).second << endl;
		// 下面这行是标准写法，推荐使用：
		cout << it->first << ":" << it->second << endl;

		// 更底层的写法（不推荐，但你理解它是非常棒的）：
		// cout << it.operator->()->first << ":" << it.operator->()->second << endl;
		// map的迭代基本都使⽤operator->,这⾥省略了⼀个->
		// 第⼀个->是迭代器运算符重载，返回pair*，第⼆个箭头是结构指针解引⽤取pair数据
		++it;
	}
	cout << endl;


	return 0;

}