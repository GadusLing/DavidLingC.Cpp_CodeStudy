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
//	//�������Σ�������ȥ�ģ�����Ҫ��memcpy  -- memory�ڴ�  copy
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
	//�������Σ�������ȥ�ģ�����Ҫ��memcpy  -- memory�ڴ�  copy

	return 0;
}