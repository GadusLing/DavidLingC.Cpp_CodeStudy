#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

void Swap(int* x, int* y)//�������������𽻻�
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//ð������
void BubbleSort(int* arr, int n)
{
	int index;//����һ��ָʾ����0��ʾδ��������1��ʾ�����˽���

	for (int i = 0; i < n - 1; i++)
	{
		index = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])//ð�ݳ�����
			{
				Swap(&arr[j], &arr[j + 1]);
				index = 1;
			}
		}
		if (!index) // ���һ������û�н�����˵���Ѿ��������
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


//// C++��ʵ��
//#include <algorithm>
//
//void BubbleSort(std::vector<int>& a) {
//	for (size_t i = 0; i < a.size() - 1; ++i)
//		for (size_t j = 0; j < a.size() - 1 - i; ++j)
//			if (a[j] > a[j + 1]) std::swap(a[j], a[j + 1]);
//}
//
//// �������� Hoare �汾
//int PartSort1(std::vector<int>& a, int l, int r) {
//	int p = a[l];
//	while (l < r) {
//		while (l < r && a[r] >= p) --r;
//		a[l] = a[r];
//		while (l < r && a[l] <= p) ++l;
//		a[r] = a[l];
//	}
//	a[l] = p;
//	return l;
//}
//
//// �������� �ڿӷ�
//int PartSort2(std::vector<int>& a, int l, int r) {
//	int p = a[l], hole = l;
//	while (l < r) {
//		while (l < r && a[r] >= p) --r;
//		a[hole] = a[r]; hole = r;
//		while (l < r && a[l] <= p) ++l;
//		a[hole] = a[l]; hole = l;
//	}
//	a[hole] = p;
//	return hole;
//}
//
//// �������� ǰ��ָ�뷨
//int PartSort3(std::vector<int>& a, int l, int r) {
//	int p = a[r], i = l - 1;
//	for (int j = l; j < r; ++j)
//		if (a[j] < p) std::swap(a[++i], a[j]);
//	std::swap(a[++i], a[r]);
//	return i;
//}
//
//void QuickSort(std::vector<int>& a, int l, int r) {
//	if (l < r) {
//		int p = PartSort3(a, l, r);
//		QuickSort(a, l, p - 1);
//		QuickSort(a, p + 1, r);
//	}
//}
//
//void QuickSortNonR(std::vector<int>& a, int l, int r) {
//	std::vector<int> s(r - l + 1); int t = -1;
//	s[++t] = l; s[++t] = r;
//	while (t >= 0) {
//		r = s[t--]; l = s[t--];
//		int p = PartSort3(a, l, r);
//		if (p - 1 > l) { s[++t] = l; s[++t] = p - 1; }
//		if (p + 1 < r) { s[++t] = p + 1; s[++t] = r; }
//	}
//}
