#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

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


int main()
{
	char arr1[] = "abcdef";
	char arr2[20] = { 0 };
	strcpy(arr2, arr1);//

	int arr3[] = { 1,2,3,4 };
	int arr4[5] = { 0 };
	strcpy(arr4, arr3);//err
	//这是整形，传不过去的，所以要用memcpy  -- memory内存  copy

	return 0;
}