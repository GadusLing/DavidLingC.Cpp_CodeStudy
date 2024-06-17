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

//#include "add.h"
//#include "sub.h"

//#pragma comment(lib, "add.lib")
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	//加法
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//
//	//int ret = Sub(a, b);
//	//printf("%d\n", ret);//学到了头文件和源文件的模块划分
//
//
//	return 0;
//}

//函数的定义
//int Add(int x, int y)
//{
//	return x + y;
//}

//接受一个整型值(无符号)，按照顺序打印它的每一位。
//例如:
//输入:1234，输出1 2 3 4.


//%d 是打印有符号的整数(会有正负数)
//%u 是打印无符号的整数
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);//1234
//	while (num)
//	{
//		printf("%d ", num % 10);
//		num = num / 10;
//	}
//
//	//1 2 3 4
//	//printf("%u", num);
//
//	return 0;
//}


//递归法
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}	
//	printf("%d ", n % 10);
//	
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);//1234
//	print(num);//让print这个函数接受一个整型值(无符号)，按照顺序打印它的每一位。
//
//	return 0;
//}



//编写函数不允许创建临时变量，求字符串的长度

#include <string.h>

//int my_strlen(char str[])//参数部分写出数组的形式
//int my_strlen(char * str)//参数部分写成指针的形式,和上面两者没啥区别，写成哪种都可以
//{
//	int count = 0;//临时变量，但题目是不要临时变量，所以该怎么做呢？
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//如何不创建临时变量用递归的方法求解
//int my_strlen(char* str)
//{
//	if (*str != '/0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//int main()
//{
//	char arr[] = "abc";//[a b c \0]
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//
//	return 0;
//}



//解决阶乘问题
//递归实现
//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}

//循环的方式来写————迭代实现
//int fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n ; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}




//求第n个斐波那契数的问题
//斐波那契数列
//1 1 2 3 5 8 13 21 34 55... 前两数之后等于后一位数

//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);//这里用递归显然不合适了，复杂程度太大                 
//	}
//	
//}

//int Fib(int n)//试试迭代法
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//
//	return c;
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}


//void test(int n)
//{
//	if (n < 10000)
//	{
//		test(n + 1);
//	}
//}
//
//int main()
//{
//
//    test(1);
//	return 0;
//}//层次不深优先考虑递归，层次比较深就迭代
