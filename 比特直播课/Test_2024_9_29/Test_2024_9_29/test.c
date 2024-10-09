#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	strcpy(arr2, arr1);//
//
//	int arr3[] = { 1,2,3,4 };
//	int arr4[5] = { 0 };
//	strcpy(arr4, arr3);//err
//	//这是整形，传不过去的，所以要用memcpy  -- memory内存  copy
//
//	return 0;
//}


//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	strcpy(arr2, arr1);//
//
//	int arr3[] = { 1,2,3,4 };
//	int arr4[5] = { 0 };
//	strcpy(arr4, arr3);//err
//	//这是整形，传不过去的，所以要用memcpy  -- memory内存  copy
//
//	return 0;
//}


//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(src && dest);
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr4[20] = { 0 };
//	my_memcpy(arr4, arr3, 5 * sizeof(int));
//	//这是整形，传不过去的，所以要用memcpy  -- memory内存  copy
//
//	return 0;
//}


//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(src && dest);
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr4[20] = { 0 };
//	my_memcpy(arr4, arr3, 5 * sizeof(int));
//
//	return 0;
//}

//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(src && dest);
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr4[20] = { 0 };
//	//my_memcpy(arr3 + 2, arr3, 5 * sizeof(int));
//	memmove(arr3 + 2, arr3, 5 * sizeof(int));
//
//	return 0;
//}



////实现内存块的拷贝，具体拷贝什么数据是未知的
//my_memmove(void* dest, void* src, size_t num)
//{
//	if (dest < src)//前 -> 后
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else//后 -> 前
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr, arr + 2, 5 * sizeof(int));
//
//
//	return 0;
//}



//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i + 1;
//	}
//	//1 2 3 4 5 6 7 8 9 10
//	//如果需要把数组内容全置为0
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	arr[i] = 0;
//	//}
//	memset(arr, 1, 10 * sizeof(int));//memory set
//
//	return 0;
//}


//int main()
//{
//	char arr[] = "hello world";
//	memset(arr + 6, 'x', 5 * sizeof(char));//memory set
//
//	return 0;
//}


int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 ...
	//01 00 00 00 02 00 00 00 03 00 00 00 03 00 00 00 ...
	int arr2[] = { 1,2,3,3 };
	int ret = memcmp(arr1, arr2, 13);//memory set
	printf("%d\n", ret);

	return 0;
}

