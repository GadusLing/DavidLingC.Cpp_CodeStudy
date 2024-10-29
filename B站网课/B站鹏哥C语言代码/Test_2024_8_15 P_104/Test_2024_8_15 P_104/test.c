#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>


//void move_odd_even(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left < right)
//	{
//		//从左向右找一个偶数，找到就停下来
//		while ((left < right) && arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		//从右向左找一个奇数，找到就停下来
//		while ((left < right) && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		//交换上面找到的奇数和偶数
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
//		scanf("%d", arr + i);//和上面语句效果是一样的，arr数组名就是首元素地址
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
//    for (int i = 0; i < n; i++)//输入第一行的n个元素
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (int i = 0; i < m; i++)//输入第二行的m个元素
//    {
//        scanf("%d", &arr2[i]);
//    }
//
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while (i < n && j < m)//由于题目中的两个数组是升序排列，右值一定大于左值，所以该循环最终的结果会以遇到某数组中一个巨大的值为上限，将另一数组遍历排序完
//    {
//        if (arr1[i] < arr2[j]) //升序排列两数组中的元素，当一组数据被彻底遍历完之后，另一组剩下的只有一些更大的值
//        {
//            merged[k++] = arr1[i++];
//        }
//        else
//        {
//            merged[k++] = arr2[j++];
//        }
//    }
//
//    //补漏，将上限值及其升序排列的所有右值添加到merged中  
//    while (i < n) //当arr1里面还有值，陆续放到merged中
//    {
//        merged[k++] = arr1[i++];
//    }
//    while (j < m) //当arr2里面还有值，陆续放到merged中
//    {
//        merged[k++] = arr2[j++];
//    }
//
//    //如果题目改成无序数组，另加一个冒泡排序即可
//
//    // 输出合并后的序列  
//    for (int l = 0; l < k; l++)
//    {
//        printf("%d ", merged[l]);
//    }
//    printf("\n");
//
//    return 0;
//}


