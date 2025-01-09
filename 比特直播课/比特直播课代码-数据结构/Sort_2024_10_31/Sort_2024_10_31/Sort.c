#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

void Swap(int* x, int* y)//辅助函数，负责交换
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//冒泡排序
void BubbleSort(int* arr, int n)
{
	int index;//设置一个指示器，0表示未曾交换，1表示产生了交换

	for (int i = 0; i < n - 1; i++)
	{
		index = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])//冒泡成升序
			{
				Swap(&arr[j], &arr[j + 1]);
				index = 1;
			}
		}
		if (!index) // 如果一趟排序没有交换，说明已经是有序的
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
int PartSort1(int* a, int left, int right) // 找基准值函数
{
	int key = left; // 设数组首元素为基准值
	++left; // 从首元素后一个数开始遍历
	while (left <= right) // 当左指针小于等于右指针时
	{
		while (left <= right && a[right] > a[key]) // 从右边找比基准值小的元素
		{
			right--; // 右指针左移
		}

		while (left <= right && a[left] < a[key]) // 从左边找比基准值大的元素
		{
			left++; // 左指针右移
		}

		if (left <= right) // 如果左指针小于等于右指针，交换左右指针所指的元素
		{
			Swap(&a[left++], &a[right--]);
		}
	}
	Swap(&a[key], &a[right]); // 将基准值和右指针指向的元素交换
	return right; // 返回基准值所在的位置
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	// 初始化坑的位置，坑的位置从left开始，a[hole]是当前的基准值
	int hole = left;
	int key = a[hole];  // 基准值，选取左边界元素作为基准值

	// 遍历直到左右指针相遇
	while (left < right)
	{
		// 从右边开始寻找一个小于基准值的元素，找到后放到洞的位置
		while (left < right && a[right] > key)
		{
			right--;// 没找到比基准值小的，继续左移去找
		}
		a[hole] = a[right];  // 把找到的右边小于基准值的元素放入“坑”位置
		hole = right;  // 更新当前右标为新坑的位置

		// 从左边开始寻找一个大于基准值的元素，找到后放到坑的位置
		while (left < right && a[left] < key)
		{
			left++;  // 没找到比基准值大的，继续右移去找
		}
		a[hole] = a[left];  // 把找到的左边大于基准值的元素放入“坑”位置
		hole = left;  // 更新坑的位置
	}

	// 当左右指针相遇时，表示已经左小右大排完了，只有最终的一个坑位了，填入一开始记录的基准值key
	a[hole] = key;

	// 返回分区点（基准值所在位置）
	return hole;
}

// 快速排序前后指针法 (Lomuto)
int PartSort3(int* a, int left, int right)
{
	// prev指针指向已排序部分的最后一个元素
	// cur指针用于扫描未排序部分
	// key是当前选定的基准元素，初始为left位置
	int prev = left, cur = prev + 1;
	int key = left;
	while (cur <= right)
	{
		// 若当前元素小于基准元素，并且prev指针不等于cur指针，则交换
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;  // 移动cur指针继续扫描
	}
	// 将基准元素放到正确位置
	Swap(&a[prev], &a[key]);
	return prev;  // 返回基准元素的位置
}


void QuickSort(int* a, int left, int right) // hoare版本的快速排序
{
	if (left >= right) // 如果左指针大于等于右指针，说明已经没有元素需要排序，递归结束
	{
		return;
	}
	int key = PartSort3(a, left, right); // 调用partSort函数得到基准值的最终位置
	QuickSort(a, left, key - 1); // 对左边的子数组进行递归排序
	QuickSort(a, key + 1, right); // 对右边的子数组进行递归排序
	//看起来是不是很像二叉树的前序遍历————根左右，这就是分治法
}

// 快速排序 非递归实现,借助 栈 结构
typedef struct 
{
	int left, right;
} StackFrame;//定义一个类型用来存左右下标，一个StackFrame代表一个需要排序的区间

void QuickSortNonR(int* a, int n) 
{
	// 动态分配栈内存
	StackFrame* stack = (StackFrame*)malloc(n * sizeof(StackFrame));
	if (!stack) 
	{
		printf("内存分配失败!\n");
		return;
	}

	int top = -1;  // 栈顶指针，设置为-1代表指向栈顶，设置为0代表指向栈顶下一个空位置，有问题自己复习一下栈

	// 初始化栈，推入初始区间
	stack[++top] = (StackFrame){ 0, n - 1 };
	//(StackFrame) { 0, n - 1 } 是一个结构体初始化的语法;stackFrame 是结构体类型，具有两个成员变量 low 和 high
	//{0, n - 1} 是一个初始化列表，表示将 low 初始化为 0，将 high 初始化为 n - 1
	//可以理解成
	/*StackFrame initialFrame;
	initialFrame.low = 0;
	initialFrame.high = n - 1;
	stack[++top] = initialFrame;*/

	while (top >= 0) //若栈不为空则进入循环
	{
		StackFrame current = stack[top--];// 取栈顶存的StackFrame，即现在要排序的那个区间赋给新创建的current，待会儿用来排序，然后弹出栈顶
		int left = current.left;//从刚刚得到的current数据里面获取用于排序的左右指针
		int right = current.right;

		int prev = left, cur = prev + 1;// 用Lomuto双指针进行基准值的排序
		int key = left;
		while (cur <= right)
		{
			// 若当前元素小于基准元素，并且prev指针不等于cur指针，则交换
			if (a[cur] < a[key] && ++prev != cur)
			{
				Swap(&a[cur], &a[prev]);
			}
			++cur;  // 移动cur指针继续扫描
		}
		// 将基准元素放到正确位置
		Swap(&a[prev], &a[key]);
		key = prev;//为了方便理解这里多赋值一次，能够清楚的理解基准元素的位置，实际上就是排序后的prev
		//之后熟练了可以直接把下面的区间改为prev + 1, right; left, prev - 1

		// 将右侧区间和左侧区间继续推入栈中,实际上就是用栈来模拟递归中，需要排序区间被无限拆分成更小的过程
		// 若没有更小的区间就不入栈，这样把栈清空，就代表整齐的排完了所有数据
		if (key + 1 < right)
		{
			stack[++top] = (StackFrame){ key + 1, right };
		}
		if (key - 1 > left) 
		{
			stack[++top] = (StackFrame){ left, key - 1 };
		}

	}
	// 释放栈内存
	free(stack);
}

//归并排序 递归实现
void Divide(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	Divide(a, left, mid);
	Divide(a, mid + 1, right);
}


void mergeSort(int* a, int n)
{



}
