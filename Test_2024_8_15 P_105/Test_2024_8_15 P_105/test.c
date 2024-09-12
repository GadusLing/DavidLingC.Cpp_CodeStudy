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



//数组指针
//先要讲清楚数组名
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr);

	printf("%d\n", sizeof(arr));

	return 0;
}
//数组名通常表示的都是数组首元素的地址
//但是有2个例外:
//1. sizeof(数组名),这里的数组名表示整个数组，计算的是整个数组的大小
//2. &数组名,这里的数组名表示的依然是整个数组，所以&数组名取出的是整个数组的地址








