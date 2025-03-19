#define _CRT_SECURE_NO_WARNINGS

#include <iostream>	
#include <array>	// C++11
#include <vector>
#include "Date.h"
using namespace std;

//#define N 10

template <class T, size_t N = 10>
// 到C++11，非模板参数的主要都是供整形使用，用来定义数组大小和一些整形数据
class mystack
{
public:
	// ...
private:
	T _a[N];
	int _top;
};


//int main()
//{
//	mystack<int, 10> s1;        // 10
//	mystack<int> s2;        // 10
//	mystack<double, 200> s3;     // 200
//
//
//
//	return 0;
//}

//// 接下来讲讲array 静态数组，实际使用中STL的array并不好用
//int main()
//{
//	array<int, 10> a1;
//	array<int, 100> a2;
//	//两种数组对比，两者之间最大的区别就是array检查数组越界非常敏感，而C语言风格的数组的越界检查是一种抽查，不敏感
//	int arr1[10];
//	int arr2[100];
//
//	//是怎实现的呢？C语言数组检查实际上是在数组尾部设置一个标识，当访问到标识时，就会报错，
//	//但设置的标识根据不同操作系统和编译器不同，可能会有所不同，而且过度越界也不会检查出来
//	//比如只设置了两个标识，但是访问了十个，就不会报错
//	//但array则会通过参数部分的模板参数，比如上面的10，来检查数组越界，只要[]内访问的下标超过了模板参数的值，就会报错
//
//	//但是除了这个优势之外，array并不好用，作为一个静态数组，它会占用栈空间
//	//而栈空间和堆空间不同，栈空间并不大，Window下，栈的大小是2MB，Linux下，默认栈空间大小为8MB
//	//所以如果数组过大，就会导致栈溢出
//	//而且array所谓的检测越界，vector也能做到
//	//vector<int> v1(10, 0);  还能更方便的初始化
//
//	return 0;
//}


// 接下来讲讲函数模板的特化
// 函数模板的特化，就是对函数模板的一个特殊化处理
template <class T>
bool Less(T left, T right)
{
	return left < right;
}

int main()
{
	cout << Less(1, 2) << endl;//可以比较，结果正确

	Date d1(2025, 7, 7);
	Date d2(2025, 7, 8);
	cout << Less(d1, d2) << endl;

	cout << Less(new Date(2025, 3, 7), new Date(2025, 3, 8)) << endl;// 这里比的是指针，错误
	// 所以我们在原模板的基础上，对指针类型进行特化


	return 0;
}