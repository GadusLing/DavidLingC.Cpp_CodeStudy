#define _CRT_SECURE_NO_WARNINGS

//链式访问

#include <stdio.h>

//int main()
//{
//	//int len = strlen("abcdef");
//	//printf("%d\n", len);
//
//	////链式访问
//	//printf("%d\n", strlen("abcdef"));
//
//	printf("%d", printf("%d", printf("%d", 43)));//经典链式访问，它打印出来是啥？4321
//
//
//	return 0;
//}




//函数的定义和声明

//函数的声明
//int Add(int x, int y);

#include "add.h"
#include "sub.h"

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	//加法
	int sum = Add(a, b);
	printf("%d\n", sum);

	int ret = Sub(a, b);
	printf("%d\n", ret);//学到了头文件和源文件的模块划分


	return 0;
}

//函数的定义
//int Add(int x, int y)
//{
//	return x + y;
//}
