#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


void Test()
{
	// 动态申请一个int类型的空间
	int* ptr4 = new int;
	// 动态申请一个int类型的空间并初始化为10
	int* ptr5 = new int(10);
	// 动态申请3个int类型的空间
	int* ptr6 = new int[3];
	//C++11之后支持多对象初始化
	int* ptr7 = new int[10] {1, 2, 3};//后7个默认给0

	delete ptr4;
	delete ptr5;
	delete[] ptr6;
	delete[] ptr7;

}
////这里浅浅演示一下抛异常的问题，主要用作了解，后面会详细讲关于异常的问题
//double Divide(int a, int b)
//{
//	try//；利用try catch来捕获异常，这里只要大概知道这样处理就好了，详细的异常之后会讲
//	{
//		if (b == 0)
//		{
//			string s("Divide by zero condition!");
//			throw s;//抛异常可以抛出一个任意类型的信息，这里就抛了一个string
//		}
//		else 
//		{
//			return ((double)a / (double)b);
//		}
//	}
//	catch (int errid)
//	{
//		cout << errid << endl;
//	}
//	return 0;
//}



int main()
{
	Test();

	return 0;
}