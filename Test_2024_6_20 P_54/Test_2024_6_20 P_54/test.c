#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	//int a = 1;
//	//int b = 2;
//	//int c = 3;
//	//1~10
//	//1~100
//	//数组是一组相同类型元素的集合
//
//	int arr[10];
//	char ch[5];
//	double data1[20];
//	double data2[15 + 5];
//
//
//	//下面的代码只能在支持c99标准的编译器上编译
//	int n = 10;
//	scanf("%d\n", &n);
//	int arr2[n];//这种变长数组是不能初始化的
//	//在C99标准之前，数组的大小必须是常量或者常量表达式
//    //在c99之后，数组的大小可以是变量，为了支持变长数组
//	//变长数组————数组大小根据变量决定
//
//
//	return 0;
//}

int main()
{
	//不完全初始化，剩余的元素默认初始化为0
	int arr[10] = { 1,2,3 };
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };

	char ch1[10] = { 'a','b','c' };
	char ch2[10] = "abc";

	return 0;
}