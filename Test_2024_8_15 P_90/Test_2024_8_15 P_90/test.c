#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "Hello World";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}


//编程常见的错误
//1.编译型错误（语法错误）
//2.链接型错误（出现在链接期间） - 基本上都是因为找不到符号（1.不存在 2.写错了）
//3.运行时错误（最难受，需要调试来解决）
//
//
//
//int main()
//{
//	int a
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//
//int main()
//{
//	int a = 0;
//	int b = 10;
//	int c = Add(a, b);
//
//	printf("%d\n", c);
//
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	short* p = (short*)arr;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		*(p + i) = 0;
//	}
//
//	for (i = 0; i < 5; i++) 
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulptr;
//	pulptr = pulArray;
//	*(pulptr + 3) += 3;
//	printf("%d, %d\n", *pulptr, *(pulptr + 3));
//
//	return 0;
//}










#include <stdio.h>  

int gcd(int a, int b) //使用欧几里得算法求最大公约数的函数  
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    int num1, num2;

    printf("请输入两个数（用空格分隔）: ");
    scanf("%d %d", &num1, &num2);

    //调用gcd函数并打印结果  
    printf("%d 和 %d 的最大公约数是: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}





