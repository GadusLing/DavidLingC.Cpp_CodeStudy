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
//	for (const auto& e : v2)// 范围for这样引用写更健壮，避免传值要深拷贝代价太大
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


void func(const LDW::vector<int>& v)// 很多时候会有这种情况，传参过来用了const引用之后
{
	for (size_t i = 0; i < v.size(); ++i)// 范围for遍历编译会不通过
	{
		//v[i]++; //不能修改哦，因为是返回的是const别名
		cout << v[i] << " ";//因为此处的[]接收参数是普通对象，const对象无法传给普通对象，所以需要额外增加一份const [] 见vector.h
	}
	cout << endl;

	////int* const it = v.begin();
	//const LDW::vector<int>::iterator it = v.begin();// const在左边是修饰迭代器本身，我们要const迭代器的目的并不是让迭代器本身不能修改，而是要内容不能修改，
	// //所以const迭代器并非是在普通迭代器左边加上const就完事了，而是要额外实现重载一份，命名上以const_iterator来区分
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}


	LDW::vector<int>::const_iterator it = v.begin();// 这样就完成了，不是在左边加const
	while (it != v.end())
	{
		//*int += 5;
		cout << *it << " ";
		++it;
	}
	cout << endl;


	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

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

	func(v1);


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
}//2025,明年再见