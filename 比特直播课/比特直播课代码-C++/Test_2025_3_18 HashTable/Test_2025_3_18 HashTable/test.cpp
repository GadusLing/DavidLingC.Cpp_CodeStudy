#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_map>
#include"HashTable.h"

void testHT()
{
	int a[] = { 19,30,5,36,13,20,21,12 };
	open_address::HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert({e, e});
	}
	ht.Insert({ 34, 34 });
	for (int i = 0; i < 54; ++i)
	{
		ht.Insert({ rand(), 1});
	}
	


	cout << ht.Find(20) << endl;
	cout << ht.Find(9) << endl;

	ht.Erase(30);
	cout << ht.Find(-20) << endl;
	cout << ht.Find(9) << endl;
	cout << ht.Find(30) << endl;

}

struct Date
{
	int _year;
	int _month;
	int _day;
};


void testHT2()
{
	//HashTable<string, string, HashFuncString> dict;
	open_address::HashTable<string, string> dict;
	dict.Insert({ "sort", "排序"});
	dict.Insert({ "string", "字符串"});

	open_address::HashTable<double, int> ht;
	ht.Insert({ 1.23, 1 });

	unordered_map<string, string> stddict;//库里的string不用写仿函数是因为特化处理了
	stddict.insert({ "sort", "排序" });
	stddict.insert({ "string", "字符串" });

	//unordered_map<Date, string> m2; //比如自定义这种日期类要做K键值就必须自己写仿函数

}


int main()
{
	//testHT();
	testHT();
	testHT2();

	HashFunc<string> hf;
	cout << hf("abcd") << endl;
	cout << hf("bcad") << endl;
	cout << hf("aadd") << endl;//那像这种虽然顺序不一样，但总+值相同的字符串怎么处理最好呢？
	//有很多解决方法 比如BKDR hash

	return 0;
}