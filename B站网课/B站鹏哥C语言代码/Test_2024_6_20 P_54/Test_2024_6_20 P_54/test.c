#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	//int a = 1;
//	//int b = 2;
//	//int c = 3;
//	//1~10
//	//1~100
//	//������һ����ͬ����Ԫ�صļ���
//
//	int arr[10];
//	char ch[5];
//	double data1[20];
//	double data2[15 + 5];
//
//
//	//����Ĵ���ֻ����֧��c99��׼�ı������ϱ���
//	int n = 10;
//	scanf("%d\n", &n);
//	int arr2[n];//���ֱ䳤�����ǲ��ܳ�ʼ����
//	//��C99��׼֮ǰ������Ĵ�С�����ǳ������߳������ʽ
//    //��c99֮������Ĵ�С�����Ǳ�����Ϊ��֧�ֱ䳤����
//	//�䳤���顪�����������С���ݱ�������
//
//
//	return 0;
//}

//int main()
//{
//	//����ȫ��ʼ����ʣ���Ԫ��Ĭ�ϳ�ʼ��Ϊ0
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
//	//[] - �±����ò�����
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
//	int arr1[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };//ǰ�����У���������
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

//����һ�������ʾ��
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



//���鴫�ε�ʱ���β�������д��
//1.����
//2.ָ��
//
//�β����������ʽ
//void bubble_sort(int arr[], int sz)
//{
//	//����
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j = 0; j <sz -1 -i ; j++)
//		{
//			if (arr[j] > arr[j + 1])//����
//			{
//				//����
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
//	//����
//	//������������ų�����
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	//0 1 2 3 4 5 6 7 8 9
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//ð�������㷨���������������
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//������ȷʵ�ܱ�ʾ��Ԫ�صĵ�ַ
//������2������:
//1.sizeof(������)���������������ʾ�������飬���������������Ĵ�С����λ���ֽ�
//2.&���������������������ʾ�������飬ȡ��������������ĵ�ַ
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


//��ά����������������
int main()
{
	int arr[3][4];
	int sz = sizeof(arr);
	printf("%d\n", sz);


	return 0;
}