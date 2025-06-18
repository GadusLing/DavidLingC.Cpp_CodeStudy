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
	dict.Insert({ "sort", "����"});
	dict.Insert({ "string", "�ַ���"});

	open_address::HashTable<double, int> ht;
	ht.Insert({ 1.23, 1 });

	unordered_map<string, string> stddict;//�����string����д�º�������Ϊ�ػ�������
	stddict.insert({ "sort", "����" });
	stddict.insert({ "string", "�ַ���" });

	//unordered_map<Date, string> m2; //�����Զ�������������Ҫ��K��ֵ�ͱ����Լ�д�º���

}


int main()
{
	//testHT();
	testHT();
	testHT2();

	HashFunc<string> hf;
	cout << hf("abcd") << endl;
	cout << hf("bcad") << endl;
	cout << hf("aadd") << endl;//����������Ȼ˳��һ��������+ֵ��ͬ���ַ�����ô��������أ�
	//�кܶ������� ����BKDR hash

	return 0;
}