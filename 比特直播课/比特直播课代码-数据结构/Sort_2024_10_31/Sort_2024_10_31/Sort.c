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

// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;//定义两个变量，一个begin从头开始遍历找最小，一个end从尾开始找最大

	while (begin < end)
	{
		int min = begin, max = begin;//初始默认最大最小的值都指向第一个元素0
		for (int i = begin + 1; i <= end; i++)//从首元素的后一个元素遍历至尾元素，外层循环里每次首尾元素之间的距离会缩小，那其实意味着被缩减的那一部分已经排好了小值和大值
		{
			if (a[min] > a[i])//找到最小值并将下标存放在min中
			{
				min = i;
			}
			if (a[max] < a[i])//找到最大值并将下标存放在max中
			{
				max = i;
			}
		}
		if (max == begin)//防止最大值在原本数组的begin位置，避免后续两次交换中的重复交换情况
		{
			max = min;//如果出现最大值在begin的情况，先交换最小值到begin位置，此时begin原本存放的最大值交换到了min，而max此时也指向min，意味着max指向了正确的最大值
		}
		Swap(&a[min], &a[begin]);
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}


// 堆排序
void Swap(int* x, int* y)//辅助函数，负责交换父子节点
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void AdjustDwon(int* a, int n, int root)
{
	//堆排序核心即交换父节点与子节点的中较大（小）的值，以构成大（小）堆
	//此处排升序数组，以构建大堆为例
	int child = root * 2 + 1;//左孩子
	while (child < n)//当孩子下标数小于总节点个数才进入循环调整，也就是说最多到n-1下标，这样保证访问数组不越界
	{
		if (child + 1 < n && a[child] < a[child + 1])//child + 1 < n判断右孩子节点是否为合法下标，因为是建立大堆，所以如果左孩子比右孩子小，就要调整孩子下标，让大孩子与父节点交换
		{
			child++;
		}
		if (a[child] > a[root])//建大堆，如果孩子大于父亲，则交换二者，让孩子上浮
		{
			Swap(&a[child], &a[root]);
			root = child;//让原本的父亲节点走到原本的孩子节点
			child = root * 2 + 1;//原本的孩子节点变成现在父亲节点的左孩子，以进行下一次父子的再排序
		}
		else
		{
			break;//如果父节点已经>=子节点，那么意味着在正确的堆结构下，该父节点及其下属全部子树的关系已处理正确，此时可以直接跳出，因为接下来的循环对比已经是不必要的了
		}
	}
}
void HeapSort(int* a, int n)
{
	//根据数组向下调整建堆,对于堆结构中的节点i，其父节点为（i-1）/2，左孩子为2i+1，右孩子为2i+2
	//如果数组数据是随机混乱的情况下，我们使用向下调整建堆，就从最后一个节点的父节点开始比较，比较修正每一个父节点与它的子节点的关系，这样就能构建出正确的（大or小）堆属性
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//n为数组数据个数，n-1是数组最后一个有效数据下标，(n-1-1)/2就是最后一个节点的父节点，从它开始循环调整i--至多到i=0
	{
		AdjustDwon(a, n, i);//向下调整三个参数:数组地址 有效元素个数 父节点索引
	}
	//此时一个无序数组已然成为了一个大堆，但是这个大堆未必是完全正确的降序数组，只是一个总体趋势降序的数组
	//但是此时可以确定的是，堆顶元素一定是堆中最大的元素了，所以还需要取堆顶节点与尾节点交换，交换后再除去最后一个已经被确定的最大元素，再剩余的堆中循环调整维持大堆结构
	//此后再循环取堆顶与尾节点交换，至此，便能获得一个完全正确的降序数组

	for (int i = n - 1; i > 0; i--)//此处i>0不用=，因为如果只剩1个元素，就不用调整了
	{
		Swap(&a[0], &a[i]);//交换堆顶最大的元素与尾元素
		AdjustDwon(a, i, 0);//此时i是n-1，原本正常的调整n是总元素个数，此时就相当于减掉了最后那个被交换的最大元素，在剩余的结构中调整
	}
}

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{

}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{

}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{

}
void QuickSort(int* a, int left, int right)
{

}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{

}