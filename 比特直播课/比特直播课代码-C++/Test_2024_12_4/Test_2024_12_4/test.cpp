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
//	string name1 = "张三";
//	v2.push_back(name1);//有名对象
//
//	v2.push_back(string("李四"));//匿名对象
//
//	v2.push_back("王五");//隐式类型转换
//	
//	for (const auto& e : v2)
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
//	//	cout << x << "找到了" << endl;
//	//}
//
//	//cin >> x;
//	////vector<int>::iterator it1 = find(v1.begin(), v1.end(), x);
//	//auto it2 = find(lt1.begin(), lt1.end(), x);
//	//if (it2 != lt1.end())
//	//{
//	//	cout << x << "找到了" << endl;
//	//}
//
//	sort(v1.begin(), v1.end());//sort默认升序,底层是快排,严格来说是自省排序
//	for (const auto& e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//降序呢?涉及到仿函数,具体之后会讲,这里先拿来用
//	// 默认less
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
//	//迭代器也分类型的,单向双向随机的,支持++,支持++--,支持+N - N
//	//sort(lt1.begin(), lt1.end());
//	//像list的迭代器就是不支持sort的
//
//
//	return 0;
//}

#include"vector.h"

int main()
{
	LDW::vector<int> v1;
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

	return 0;
}//2025,明年再见