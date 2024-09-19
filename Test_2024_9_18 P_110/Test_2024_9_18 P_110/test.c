#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	//指针数组
//	int* arr[4];
//	char* ch[5];
//	int** p = arr;//arr数组名 = 首元素地址 = int*类型的地址，也就是一级指针，所以用二级指针p来存
//
//	//数组指针
//	int arr2[5];
//	int(*pa)[5] = &arr2;
//
//	char* arr3[6];
//	char* (*p3)[6] = &arr3;
//
//
//	return 0;
//}



//
//int test(const char* str)
//{
//	printf("test()\n");
//	return 0;
//}
//
//int main()
//{
//	//函数指针 - 也是一种指针，是指向函数的指针
//	printf("%p\n", test);
//	printf("%p\n", &test);
//
//	int (*pf)(const char*) = &test;
//	(*pf)("abc");
//	test("abc");
//	pf("abc");
//
//	return 0;
//}


////typedef unsigned int uint;
//typedef void(*pf_t)(int);//把void(*)(int)类型重命名为pf_t
//
//
//
//int main()
//{
//	(*(void (*)())0)();//见P105
//
//	void(*signal(int, void(*)(int)))(int);
//	pf_t signal(int, pf_t);
//
//
//	return 0;
//}




////函数指针的用途
////写一个计算器
////加法、减法、乘法、除法
//
//void menu()
//{
//	printf("***********************\n");
//	printf("****1. add   2. sub****\n");
//	printf("****3. mul   4. div****\n");
//	printf("****    0. exit    ****\n");
//	printf("***********************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("请输入两个操作数\n");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);//回调函数
//	printf("%d\n", ret);
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("请选择\n");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("退出计算器\n");
//			break;
//
//		default:
//			printf("选择错误\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}
