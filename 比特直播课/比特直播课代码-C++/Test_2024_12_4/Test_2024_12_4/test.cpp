#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

//int main()
//{
//	vector<int> v1 = { 1,-2,30,4,5 };
//	list<int> lt1 = { 1,2,3,4,5 };
//
//	vector<string> v2;
//	vector<vector<int>> v3;
//
//	string name1 = "����";
//	v2.push_back(name1);//��������
//
//	v2.push_back(string("����"));//��������
//
//	v2.push_back("����");//��ʽ����ת��
//	
//	for (const auto& e : v2)// ��Χfor��������д����׳�����⴫ֵҪ�������̫��
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//int x;
//	//cin >> x;
//	////vector<int>::iterator it1 = find(v1.begin(), v1.end(), x);
//	//auto it1 = find(v1.begin(), v1.end(), x);
//	//if (it1 != v1.end())
//	//{
//	//	cout << x << "�ҵ���" << endl;
//	//}
//
//	//cin >> x;
//	////vector<int>::iterator it1 = find(v1.begin(), v1.end(), x);
//	//auto it2 = find(lt1.begin(), lt1.end(), x);
//	//if (it2 != lt1.end())
//	//{
//	//	cout << x << "�ҵ���" << endl;
//	//}
//
//	sort(v1.begin(), v1.end());//sortĬ������,�ײ��ǿ���,�ϸ���˵����ʡ����
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//������?�漰���º���,����֮��ὲ,������������
//	// Ĭ��less
//	//greater <int> gt;
//	//sort(v1.begin(), v1.end(), gt);
//	sort(v1.begin(), v1.end(), greater<int>());
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	//������Ҳ�����͵�,����˫�������,֧��++,֧��++--,֧��+N - N
//	//sort(lt1.begin(), lt1.end());
//	//��list�ĵ��������ǲ�֧��sort��
//
//
//	return 0;
//}

#include"vector.h"


void func(LDW::vector<int> v)// �ܶ�ʱ������������������
{

}


int main()
{
	LDW::vector<int> v1;
	LDW::vector<double> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	for (const auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//v1[i]
	//v1.operator[](i);

	//int a[10];
	//a[i];  *(a+i)

	//std::vector<int> v;
	//cout << typeid(std::vector<int>::iterator).name() << endl;
	//cout << typeid(std::vector<int>::const_iterator).name() << endl;
	//cout << typeid(std::vector<int>::reverse_iterator).name() << endl;
	//cout << typeid(std::vector<int>::const_reverse_iterator).name() << endl;


	return 0;
}//2025,�����ټ�