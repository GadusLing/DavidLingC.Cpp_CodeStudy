#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>


//void move_odd_even(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left < right)
//	{
//		//����������һ��ż�����ҵ���ͣ����
//		while ((left < right) && arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		//����������һ���������ҵ���ͣ����
//		while ((left < right) && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		//���������ҵ���������ż��
//		if (left < right)
//		{
//			int temp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = temp;
//			left++;
//			right--;
//		}
//	}
//}
//
//
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		//scanf("%d", &arr[i]);
//		scanf("%d", arr + i);//���������Ч����һ���ģ�arr������������Ԫ�ص�ַ
//	}
//
//	move_odd_even(arr, sz);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    int arr1[1001] = { 0 };
//    int arr2[1001] = { 0 };
//    int merged[2002] = { 0 };
//    for (int i = 0; i < n; i++)//�����һ�е�n��Ԫ��
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (int i = 0; i < m; i++)//����ڶ��е�m��Ԫ��
//    {
//        scanf("%d", &arr2[i]);
//    }
//
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < n && j < m)//������Ŀ�е������������������У���ֵһ��������ֵ�����Ը�ѭ�����յĽ����������ĳ������һ���޴��ֵΪ���ޣ�����һ�������������
//    {
//        if (arr1[i] < arr2[j]) //���������������е�Ԫ�أ���һ�����ݱ����ױ�����֮����һ��ʣ�µ�ֻ��һЩ�����ֵ
//        {
//            merged[k++] = arr1[i++];
//        }
//        else
//        {
//            merged[k++] = arr2[j++];
//        }
//    }
//
//    //��©��������ֵ�����������е�������ֵ��ӵ�merged��  
//    while (i < n) //��arr1���滹��ֵ��½���ŵ�merged��
//    {
//        merged[k++] = arr1[i++];
//    }
//    while (j < m) //��arr2���滹��ֵ��½���ŵ�merged��
//    {
//        merged[k++] = arr2[j++];
//    }
//
//    //�����Ŀ�ĳ��������飬���һ��ð�����򼴿�
//
//    // ����ϲ��������  
//    for (int l = 0; l < k; l++)
//    {
//        printf("%d ", merged[l]);
//    }
//    printf("\n");
//
//    return 0;
//}


