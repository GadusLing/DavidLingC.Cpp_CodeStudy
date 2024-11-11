#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

//冒泡排序
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int swapped = 0; // 标记本轮是否发生交换
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 交换 arr[j] 和 arr[j + 1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		// 如果没有发生交换，数组已经有序，可以提前结束
		if (swapped == 0)
			break;
	}
}

//直接插入排序
void InsertSort(int* arr, int n )
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i + gap < n; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}