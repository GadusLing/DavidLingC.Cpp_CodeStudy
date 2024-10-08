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

void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(src && dest);

	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

int main()
{
	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr4[20] = { 0 };
	//my_memcpy(arr3 + 2, arr3, 5 * sizeof(int));
	memmove(arr3 + 2, arr3, 5 * sizeof(int));

	return 0;
}