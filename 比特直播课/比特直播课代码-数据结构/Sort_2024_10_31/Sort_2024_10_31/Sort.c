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

// ѡ������
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;//��������������һ��begin��ͷ��ʼ��������С��һ��end��β��ʼ�����

	while (begin < end)
	{
		int min = begin, max = begin;//��ʼĬ�������С��ֵ��ָ���һ��Ԫ��0
		for (int i = begin + 1; i <= end; i++)//����Ԫ�صĺ�һ��Ԫ�ر�����βԪ�أ����ѭ����ÿ����βԪ��֮��ľ������С������ʵ��ζ�ű���������һ�����Ѿ��ź���Сֵ�ʹ�ֵ
		{
			if (a[min] > a[i])//�ҵ���Сֵ�����±�����min��
			{
				min = i;
			}
			if (a[max] < a[i])//�ҵ����ֵ�����±�����max��
			{
				max = i;
			}
		}
		if (max == begin)//��ֹ���ֵ��ԭ�������beginλ�ã�����������ν����е��ظ��������
		{
			max = min;//����������ֵ��begin��������Ƚ�����Сֵ��beginλ�ã���ʱbeginԭ����ŵ����ֵ��������min����max��ʱҲָ��min����ζ��maxָ������ȷ�����ֵ
		}
		Swap(&a[min], &a[begin]);
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}


// ������
void Swap(int* x, int* y)//�������������𽻻����ӽڵ�
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void AdjustDwon(int* a, int n, int root)
{
	//��������ļ��������ڵ����ӽڵ���нϴ�С����ֵ���Թ��ɴ�С����
	//�˴����������飬�Թ������Ϊ��
	int child = root * 2 + 1;//����
	while (child < n)//�������±���С���ܽڵ�����Ž���ѭ��������Ҳ����˵��ൽn-1�±꣬������֤�������鲻Խ��
	{
		if (child + 1 < n && a[child] < a[child + 1])//child + 1 < n�ж��Һ��ӽڵ��Ƿ�Ϊ�Ϸ��±꣬��Ϊ�ǽ�����ѣ�����������ӱ��Һ���С����Ҫ���������±꣬�ô����븸�ڵ㽻��
		{
			child++;
		}
		if (a[child] > a[root])//����ѣ�������Ӵ��ڸ��ף��򽻻����ߣ��ú����ϸ�
		{
			Swap(&a[child], &a[root]);
			root = child;//��ԭ���ĸ��׽ڵ��ߵ�ԭ���ĺ��ӽڵ�
			child = root * 2 + 1;//ԭ���ĺ��ӽڵ������ڸ��׽ڵ�����ӣ��Խ�����һ�θ��ӵ�������
		}
		else
		{
			break;//������ڵ��Ѿ�>=�ӽڵ㣬��ô��ζ������ȷ�Ķѽṹ�£��ø��ڵ㼰������ȫ�������Ĺ�ϵ�Ѵ�����ȷ����ʱ����ֱ����������Ϊ��������ѭ���Ա��Ѿ��ǲ���Ҫ����
		}
	}
}
void HeapSort(int* a, int n)
{
	//�����������µ�������,���ڶѽṹ�еĽڵ�i���丸�ڵ�Ϊ��i-1��/2������Ϊ2i+1���Һ���Ϊ2i+2
	//�������������������ҵ�����£�����ʹ�����µ������ѣ��ʹ����һ���ڵ�ĸ��ڵ㿪ʼ�Ƚϣ��Ƚ�����ÿһ�����ڵ��������ӽڵ�Ĺ�ϵ���������ܹ�������ȷ�ģ���orС��������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//nΪ�������ݸ�����n-1���������һ����Ч�����±꣬(n-1-1)/2�������һ���ڵ�ĸ��ڵ㣬������ʼѭ������i--���ൽi=0
	{
		AdjustDwon(a, n, i);//���µ�����������:�����ַ ��ЧԪ�ظ��� ���ڵ�����
	}
	//��ʱһ������������Ȼ��Ϊ��һ����ѣ�����������δ������ȫ��ȷ�Ľ������飬ֻ��һ���������ƽ��������
	//���Ǵ�ʱ����ȷ�����ǣ��Ѷ�Ԫ��һ���Ƕ�������Ԫ���ˣ����Ի���Ҫȡ�Ѷ��ڵ���β�ڵ㽻�����������ٳ�ȥ���һ���Ѿ���ȷ�������Ԫ�أ���ʣ��Ķ���ѭ������ά�ִ�ѽṹ
	//�˺���ѭ��ȡ�Ѷ���β�ڵ㽻�������ˣ����ܻ��һ����ȫ��ȷ�Ľ�������

	for (int i = n - 1; i > 0; i--)//�˴�i>0����=����Ϊ���ֻʣ1��Ԫ�أ��Ͳ��õ�����
	{
		Swap(&a[0], &a[i]);//�����Ѷ�����Ԫ����βԪ��
		AdjustDwon(a, i, 0);//��ʱi��n-1��ԭ�������ĵ���n����Ԫ�ظ�������ʱ���൱�ڼ���������Ǹ������������Ԫ�أ���ʣ��Ľṹ�е���
	}
}

// ��������ݹ�ʵ��
// ��������hoare�汾
int _PartSort1(int* a, int left, int right)
{
	int key = left;//��������Ԫ��Ϊ��׼ֵ
	++left;//����Ԫ�غ�һ������ʼ����
	while (left <= right)
	{
		while (left <= right && a[right] > a[key])
		{
			right--;
		}

		while (left <= right && a[left] < a[key])
		{
			left++;
		}

		if (left <= right)
		{
			Swap(&a[left++], &a[right--]);
		}
	}
	Swap(&a[key], &a[right]);
	return right;
}

int PartSort1(int* a, int left, int right)
{
	if (left >= right)//�ڱ���������left�����++��right�����--��left�����ұȻ�׼ֵ��right�����ұȻ�׼ֵС���໥����
	{
		return;
	}
	int key = _PartSort1(a, left, right);//�һ�׼ֵ
	PartSort1(a, left, key - 1);
	PartSort1(a, key + 1, right);


}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int hole = left;
	int key = a[hole];

	while (left < right)
	{
		while (left < right && a[right] > key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] < key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

// ��������ǰ��ָ�뷨(lomuto)
int PartSort3(int* a, int left, int right)
{
	//˫ָ�뷨
	int prev = left, cur = prev + 1;
	int key = left;
	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[prev], &a[key]);
	return prev;
}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{

}