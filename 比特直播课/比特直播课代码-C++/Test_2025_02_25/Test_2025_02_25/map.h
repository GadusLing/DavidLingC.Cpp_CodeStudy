#pragma once

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int testset()
{
	//map<string, string> dict;

	//pair<string, string> kv1("sort", "排序");// 有名对象构造
	//dict.insert(kv1);

	//dict.insert(pair<string, string>("string", "字符串"));// 匿名对象构造

	//dict.insert(make_pair("pair", "一对"));// c++98最喜欢的make_pair函数模板  自动推导类型生成匿名对象构造

	////c++11喜欢的方式
	//dict.insert({ "left", "左边" });// 这个不是initializer_list构造，是c++11支持的 多参数构造函数的隐式类型转换

	//auto it = dict.begin();
	//while (it != dict.end())
	//{
	//	// map 的迭代器指向的是一个 pair<const Key, Value>
	//	// 所以 it->first 表示 key，it->second 表示 value

	//	 //cout << (*it).first <<":"<<(*it).second << endl;
	//	// 下面这行是标准写法，推荐使用：
	//	cout << it->first << ":" << it->second << endl;

	//	// 更底层的写法（不推荐，但你理解它是非常棒的）：
	//	// cout << it.operator->()->first << ":" << it.operator->()->second << endl;
	//	// map的迭代基本都使⽤operator->,这⾥省略了⼀个->
	//	// 第⼀个->是迭代器运算符重载，返回pair*，第⼆个箭头是结构指针解引⽤取pair数据
	//	++it;
	//}
	//cout << endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//// 使用 initializer_list 初始化 map
	//std::map<std::string, std::string> dict = {
	//	{"left", "左边"},
	//	{"left", "左"}, // 哪怕value不相同也不会重复，只看key值，key一样的话不会重复插入
	//	{"right", "右边"},
	//	{"insert", "插入"},
	//	{"string", "字符串"}
	//};

	//dict.insert({ "left", "左" }); //key一样不重复插入

	//for (const auto& kv : dict)
	//{
	//	cout << kv.first << " " << kv.second << endl;
	//}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//// 迭代器与operator[]

	//////operator[]大概的实现逻辑
	////V& operator[](const K& key)
	////{
	////	pair<iterator, bool> ret = insert({ key, V() });// 注意：insert这个函数的返回值是一个 pair<iterator, bool>, 这里insert 插入的value是个默认构造V()
	////	return ret.first->second;
	////}
	//// insert({ key, V() })：key不存在：插入一个pair<const K, V>，其中V是默认构造的（比如int是0，string是空字符串""）。key已存在：什么也不做，直接返回找到的元素。
	//// 
	//// pair<iterator, bool>：first是一个iterator，指向 key 对应的元素。second是一个bool，表示是否插入成功（true是新插入的，false是已经存在）。
	//// 
	//// return ret.first->second：通过迭代器拿到元素（一个pair<const K, V>），然后.second就是value。

	//std::string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果",
	//					 "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	//std::map<std::string, int> countMap;

	//// 遍历数组，统计水果出现次数
	//for (const auto& fruit : arr) 
	//{
	//	//// 使用 find 查找当前水果是否已在 map 中
	//	//auto it = countMap.find(fruit);
	//	//if (it != countMap.end()) 
	//	//{
	//	//	// 如果存在，则增加计数
	//	//	it->second++;
	//	//}
	//	//else 
	//	//{
	//	//	// 如果不存在，则插入新条目，初始计数为 1
	//	//	countMap[fruit] = 1;
	//	//}

	//	countMap[fruit]++;// 这一段，当重载[]之后，一句就搞定
	//}
	//// countMap[fruit]++ 的工作原理：
	//// 如果 fruit 不存在，operator[] 会自动插入{ fruit, 0 }，然后 ++ 使其变为 1。
	//// 如果 fruit 已存在，operator[] 返回对应value的引用，直接 ++ 递增计数。
	//// operator[]的底层可以结合 insert 的返回值 pair<iterator, bool> 来理解
	//// ---------------------------------------------------------------------
	//// insert 的返回值是一个 pair: pair<iterator, bool>
	////   - pair.first (iterator): 指向插入的元素迭代器（或已存在的元素迭代器）
	////   - pair.second (bool): 
	////       - true:  表示插入成功（原本没有该 key），iterator 指向新插入元素的迭代器
	////       - false: 表示插入失败（key 已存在，iterator 指向旧元素迭代器）

	////可以通过调试来验证
	//pair<map<string, int>::iterator, bool> ret1 = countMap.insert({ "草莓", 1 });
	//pair<map<string, int>::iterator, bool> ret2 = countMap.insert({ "西瓜", 1 });


	//// 使用迭代器遍历输出统计结果
	//for (auto it = countMap.begin(); it != countMap.end(); ++it) 
	//{
	//	std::cout << it->first << ": " << it->second << std::endl;
	//}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//multimap 和 map的差异

	map<string, string> dict;
	dict.insert({ "string", "字符串" });
	dict.insert({ "pair", "一对" });
	dict.insert({ "pair", "xxx" });

	multimap<string, string> mdict;
	mdict.insert({ "string", "字符串" });
	mdict.insert({ "pair", "一对" });
	mdict.insert({ "pair", "一对" });
	mdict.insert({ "pair", "xxx" });
	mdict.insert({ "pair", "xxx" });
	
	
	
	
	
	
	return 0;

}