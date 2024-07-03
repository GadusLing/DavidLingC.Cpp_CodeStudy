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

//int main()
//{
//	//不完全初始化，剩余的元素默认初始化为0
//	int arr[10] = { 1,2,3 };
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
//
//	char ch1[10] = { 'a','b','c' };
//	char ch2[10] = "abc";
//	char ch3[] = { 'a','b','c' };
//	char ch4[] = "abc";
//
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//[] - 下标引用操作符
//	//printf("%d\n", arr[4]);
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	for (i = sz - 1; i >= 0; i--)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//		{
//			printf("&arr[%d] = %p\n", i, &arr[i]);
//		}
//	return 0;
//}



//1 2 3 4
//2 3 4 5
//3 4 5 6

//int main()
//{
//	int arr1[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };//前面是行，后面是列
//	int arr2[3][4] = { {1,2},{3,4},{5,6} };	
//	int arr3[5][10];
//	int arr4[][4] = { {1,2,3,4},{2,3} };
//
//	return 0;
//}

//int main()
//{
//	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
//	int i = 0;
//	printf("%d\n", arr[2][0]);
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
//	int i = 0;
//
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };//0~5
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//这是一个错误的示范
//int main()
//{
//	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//	return 0;
//}



//数组传参的时候，形参有两种写法
//1.数组
//2.指针
//
//形参是数组的形式
//void bubble_sort(int arr[], int sz)
//{
//	//趟数
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟冒泡排序
//		int j = 0;
//		for (j = 0; j <sz -1 -i ; j++)
//		{
//			if (arr[j] > arr[j + 1])//升序
//			{
//				//交换
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	//数组
//	//把数组的数据排成升序
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	//0 1 2 3 4 5 6 7 8 9
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//冒泡排序算法，对数组进行排序
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//数组名确实能表示首元素的地址
//但是有2个例外:
//1.sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小，单位是字节
//2.&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
//int main()
//{
//	int arr[10];
//	printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//	printf("---------------------------\n"); 
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0] + 1);
//	printf("---------------------------\n");
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1);
//
//
//
//	//int n = sizeof(arr);//40
//	//printf("%d\n", n);
//
//	return 0;
//}


//二维数组的数组名的理解
int main()
{
	int arr[3][4];
	int sz = sizeof(arr);
	printf("%d\n", sz);


	return 0;
}