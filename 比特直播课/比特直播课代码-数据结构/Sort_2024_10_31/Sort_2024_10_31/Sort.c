#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

//ð������
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int swapped = 0; // ��Ǳ����Ƿ�������
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// ���� arr[j] �� arr[j + 1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
		// ���û�з��������������Ѿ����򣬿�����ǰ����
		if (swapped == 0)
			break;
	}
}

//ֱ�Ӳ�������
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

//ϣ������
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