#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)//只有一个等号！！！怎么不敏感呢？？是赋值，i被赋值成5了，反复的被赋值5，不断打印
//			printf("%d", i);
//	}
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//		printf("1\n");
//		break;
//	case 2:
//		printf("1\n");
//		break;
//	default:
//		printf("呵呵\n");
//		break;
//
//	}
//
//	return 0;
//
//}


//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1:b = 30;
//	case 2:b = 20;
//	case 3:b = 16;
//	default:b = 0;
//	}
//
//	return b;
//}

//int main()
//{
//	int x = 3;
//	int y = 3;
//	switch (x % 2)
//	{
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}


//写一个代码打印1-100之间所有3的倍数的数字
//void swap(int *px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	scanf("%d %d %d", &a, &b, &c);
//	int tmp = 0;
//	if (a < b)
//	{
//		swap(&a, &b);
//	}
//	if (a < c)
//	{
//		swap(&a, &c);
//	}
//	if (b < c)
//	{
//		swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 3; i <= 100; i+=3)
//	{
//		printf("%d ", i);
//	}
//
//	return 0;
//}


//给定两个数，求这两个数的最大公约数  欧几里得算法-辗转相除法

//先来枚举法
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	
//	int min = (a < b) ? a : b;
//	int m = min;
//
//	while (1)
//	{
//		if (a % m == 0 && b % m == 0)
//		{
//			break;
//		}
//		m--;
//	}
//	printf("%d\n", m);
//
//	return 0;
//}

//辗转相除
//int main()
//{
//	int a = 0;
//	int b = 0;
//    int c = 0;
//	scanf("%d %d", &a, &b);
//
//	while (c = a % b)//没有写条件，因为0为假，非0为真，简洁
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//
//	return 0;
//}

//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}

//编写程序数一下 1 到 100 的所有整数中出现多少个数字9

//int countDigitNine(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        if (n % 10 == 9)
//        {
//            count++;
//        }
//        n /= 10;
//    }
//    return count;
//}
//
//int main() 
//{
//    int totalCount = 0;
//    for (int i = 1; i <= 100; i++) 
//    {
//        totalCount += countDigitNine(i);
//    }
//    printf("1-100中9的数量: %d\n", totalCount);
//    return 0;
//}

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("1-100中9的数量: %d\n", count);
//	return 0;
//}


//计算1/1 - 1/2 + 1/3 - 1/4 + 1/5......+1/99 - 1/100 的值，打印出结果
//分子总是1
//分母是1~100

//int main() 
//{
//    double sum = 0.0; // 初始化累加和为0  
//    int sign = 1;     // 用来表示正负号，初始为正  
//
//    // 遍历1到100的整数  
//    for (int i = 1; i <= 100; i++)
//    {
//        // 根据sign的值来决定是加还是减  
//        sum += sign * (1.0 / i);
//        // 更改sign的值，下次循环时取反  
//        sign *= -1;
//    }
//
//    // 打印结果  
//    printf("The result is: %f\n", sum);
//
//    return 0;
//}


//求 10 个整数中的最大值

//int main()
//{
//	int numbers[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int max = numbers[0];
//
//    int i = 0; 
//    for (i = 1; i < 10; i++) 
//    {
//        if (numbers[i] > max)
//        {
//            max = numbers[i];
//        }
//    }
//    printf("最大的整数是：%d\n", max);
//
//	return 0;
//}


//在屏幕上输出9*9乘法口诀表

//int main() {
//    int i = 0;
//    int j = 0;
//    // 外层循环控制乘法口诀表的行数  
//    for (i = 1; i <= 9; i++) {
//        // 内层循环控制乘法口诀表的列数  
//        for (j = 1; j <= i; j++) {
//            // 打印乘法表达式和结果  
//            printf("%d*%d=%-2d  ", j, i, i * j);
//        }
//        // 每打印完一行后换行  
//        printf("\n");
//    }
//
//    return 0;
//}


//实现一个函数，打印乘法口决表，口诀表的行数和列数自己指定
//如 : 输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。

//void print_table(int n)
//{
//    int i = 0;
//    int j = 0;
//    for (i = 1; i <= n; i++) 
//    {
//        for (j = 1; j <= i; j++) 
//        {
//            printf("%d*%d=%-2d  ", j, i, i * j);
//        }
//        printf("\n");
//    }
//}
//
//int main() 
//{
//    int n = 0;
//    scanf("%d", &n);
//    print_table(n);
//
//    return 0;
//}


