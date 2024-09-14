#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



//int main()
//{
//	//char ch = 'w';
//	//char* pc = &ch;
//	//*pc = 'b';
//	//
//	//printf("%c\n", ch);
//
//	const char* p = "abcdef";
//	printf("%s\n", p);
//
//	return 0;
//}

//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	if (p1 == p2)
//		printf("p1==p2\n");
//	else
//		printf("p1!=p2\n");
//
//	if (arr1 == arr2)
//		printf("arr1 == arr2\n");
//	else
//		printf("arr1 != arr2\n");
//
//	return 0;
//}


//指针数组
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//
//	int* parr[3] = { arr1,arr2,arr3 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			//*(p+i) --> p[i]
//
//			//printf("%d ", *(parr[i] + j));
//			printf("%d ", parr[i][j]);
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}



////数组指针
////先要讲清楚数组名
//int main()
//{
//	char* arr[5] = { 0 };
//	char* (*pc)[5] = &arr;
//
//
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//int (*p2)[10] = &arr;//int (*)[10] 这叫做数组指针类型，去掉名字就是类型
//
//
//	//printf("%p\n", arr);
//	//printf("%p\n", arr + 1);
//	//
//	//
//	//printf("%p\n", &arr[0]);
//	//printf("%p\n", &arr[0] + 1);
//	//
//	//
//	//printf("%p\n", &arr);
//	//printf("%p\n", &arr + 1);
//
//	//printf("%d\n", sizeof(arr));
//
//	return 0;
//}
////数组名通常表示的都是数组首元素的地址
////但是有2个例外:
////1. sizeof(数组名),这里的数组名表示整个数组，计算的是整个数组的大小，单位是字节
////2. &数组名,这里的数组名表示的依然是整个数组，所以&数组名取出的是整个数组的地址



//int main()
//{
//	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int* p = arr;
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%d", *(p + i));
//	//}
//
//
//	//int (*p)[10] = &arr;
//
//	//int i = 0;
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(*p + i));//这是很难受的写法，错误的用法案例  //p是指向数组的，*p其实就相当于数组名,数组名又是数组首元素的地址
//	//}                                                           //所以*p本质上是数组首元素的地址
//
//
//	return 0;
//}


void print1(int arr[3][5], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}
}

void print2(int (*p)[5], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *((*p + i) + j));

		}
		printf("\n");
	}
}
 


int main()
{
	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
	print1(arr, 3, 5);
	print2(arr, 3, 5);


	return 0;
}











