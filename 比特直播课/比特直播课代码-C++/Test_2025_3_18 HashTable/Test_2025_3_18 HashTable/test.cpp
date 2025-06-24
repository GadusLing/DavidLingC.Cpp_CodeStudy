#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include"HashTable.h"
#include "UnorderedSet.h"
#include "UnorderedMap.h"
using namespace std;

//void testHT()
//{
//	int a[] = { 19,30,5,36,13,20,21,12 };
//	open_address::HashTable<int, int> ht;
//	for (auto e : a)
//	{
//		ht.Insert({e, e});
//	}
//	ht.Insert({ 34, 34 });
//	for (int i = 0; i < 54; ++i)
//	{
//		ht.Insert({ rand(), 1});
//	}
//	
//
//
//	cout << ht.Find(20) << endl;
//	cout << ht.Find(9) << endl;
//
//	ht.Erase(30);
//	cout << ht.Find(-20) << endl;
//	cout << ht.Find(9) << endl;
//	cout << ht.Find(30) << endl;
//
//}
//
//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//void testHT2()
//{
//	//HashTable<string, string, HashFuncString> dict;
//	open_address::HashTable<string, string> dict;
//	dict.Insert({ "sort", "����"});
//	dict.Insert({ "string", "�ַ���"});
//
//	open_address::HashTable<double, int> ht;
//	ht.Insert({ 1.23, 1 });
//
//	unordered_map<string, string> stddict;//�����string����д�º�������Ϊ�ػ�������
//	stddict.insert({ "sort", "����" });
//	stddict.insert({ "string", "�ַ���" });
//
//	//unordered_map<Date, string> m2; //�����Զ�������������Ҫ��K��ֵ�ͱ����Լ�д�º���
//
//}
//
//namespace hash_bucket
//{
//	void testHT()
//	{
//		int a[] = { 19,30,5,36,13,20,21,12,58,111 };
//		hash_bucket::HashTable<int, int> ht;
//		for (auto e : a)
//		{
//			ht.Insert({ e, e });
//		}
//
//		ht.Erase(5);
//		ht.Erase(58);
//		ht.Erase(111);
//
//		ht.Insert({ 34, 34 });
//		for (int i = 0; i < 54; ++i)
//		{
//			ht.Insert({ rand(), 1 });
//		}
//
//		hash_bucket::HashTable<string, string> dict;
//
//		dict.Insert({ "sort", "����" });
//		dict.Insert({ "string", "�ַ���" });
//	}
//}

void test_set1()//�������Ӳ���
{
	unordered_set<int> us;
	us.insert(42);
	us.insert(421);
	us.insert(2);
	us.insert(312);
	us.insert(313);
	us.insert(314);
	us.insert(315);
	us.insert(316);
	us.insert(317);
	cout << us.bucket_count() << endl;
	cout << us.max_bucket_count() << endl;


	cout << us.load_factor() << endl;
	cout << us.max_load_factor() << endl;

}

int main()
{
	////testHT();
	//testHT();
	//testHT2();

	//HashFunc<string> hf;
	//cout << hf("abcd") << endl;
	//cout << hf("bcad") << endl;
	//cout << hf("aadd") << endl;//����������Ȼ˳��һ��������+ֵ��ͬ���ַ�����ô��������أ�
	////�кܶ������� ����BKDR hash

	//hash_bucket::testHT();

	test_set1();

	return 0;
}



//int main()
//{
//	LDW::test_unordered_set();
//	LDW::test_unordered_map();
//
//	return 0;
//}