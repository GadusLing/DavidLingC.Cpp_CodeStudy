#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	*pa = 20;
//	printf("%d\n", a);
//
//
//	char ch = 'w';
//	char* pc = &ch;
//
//
//
//
//
//
//	return 0;
//}


int Add(int x, int y)
{
	return x + y;
}

int main()
{
	
	//printf("%p\n", &Add);
	int (*pf)(int, int) = &Add;
	//函数地址存到函数指针变量中
	int sum = (*pf)(2, 3);
	int sum1 = pf(2, 3);

	printf("%d\n", (*pf)(2, 3));
	printf("%d\n", sum);
	printf("%d\n", sum1);
	return 0;
}



