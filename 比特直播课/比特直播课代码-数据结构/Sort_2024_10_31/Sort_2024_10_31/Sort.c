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
int PartSort1(int* a, int left, int right) // �һ�׼ֵ����
{
	int key = left; // ��������Ԫ��Ϊ��׼ֵ
	++left; // ����Ԫ�غ�һ������ʼ����
	while (left <= right) // ����ָ��С�ڵ�����ָ��ʱ
	{
		while (left <= right && a[right] > a[key]) // ���ұ��ұȻ�׼ֵС��Ԫ��
		{
			right--; // ��ָ������
		}

		while (left <= right && a[left] < a[key]) // ������ұȻ�׼ֵ���Ԫ��
		{
			left++; // ��ָ������
		}

		if (left <= right) // �����ָ��С�ڵ�����ָ�룬��������ָ����ָ��Ԫ��
		{
			Swap(&a[left++], &a[right--]);
		}
	}
	Swap(&a[key], &a[right]); // ����׼ֵ����ָ��ָ���Ԫ�ؽ���
	return right; // ���ػ�׼ֵ���ڵ�λ��
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	// ��ʼ���ӵ�λ�ã��ӵ�λ�ô�left��ʼ��a[hole]�ǵ�ǰ�Ļ�׼ֵ
	int hole = left;
	int key = a[hole];  // ��׼ֵ��ѡȡ��߽�Ԫ����Ϊ��׼ֵ

	// ����ֱ������ָ������
	while (left < right)
	{
		// ���ұ߿�ʼѰ��һ��С�ڻ�׼ֵ��Ԫ�أ��ҵ���ŵ�����λ��
		while (left < right && a[right] > key)
		{
			right--;// û�ҵ��Ȼ�׼ֵС�ģ���������ȥ��
		}
		a[hole] = a[right];  // ���ҵ����ұ�С�ڻ�׼ֵ��Ԫ�ط��롰�ӡ�λ��
		hole = right;  // ���µ�ǰ�ұ�Ϊ�¿ӵ�λ��

		// ����߿�ʼѰ��һ�����ڻ�׼ֵ��Ԫ�أ��ҵ���ŵ��ӵ�λ��
		while (left < right && a[left] < key)
		{
			left++;  // û�ҵ��Ȼ�׼ֵ��ģ���������ȥ��
		}
		a[hole] = a[left];  // ���ҵ�����ߴ��ڻ�׼ֵ��Ԫ�ط��롰�ӡ�λ��
		hole = left;  // ���¿ӵ�λ��
	}

	// ������ָ������ʱ����ʾ�Ѿ���С�Ҵ������ˣ�ֻ�����յ�һ����λ�ˣ�����һ��ʼ��¼�Ļ�׼ֵkey
	a[hole] = key;

	// ���ط����㣨��׼ֵ����λ�ã�
	return hole;
}

// ��������ǰ��ָ�뷨 (Lomuto)
int PartSort3(int* a, int left, int right)
{
	// prevָ��ָ�������򲿷ֵ����һ��Ԫ��
	// curָ������ɨ��δ���򲿷�
	// key�ǵ�ǰѡ���Ļ�׼Ԫ�أ���ʼΪleftλ��
	int prev = left, cur = prev + 1;
	int key = left;
	while (cur <= right)
	{
		// ����ǰԪ��С�ڻ�׼Ԫ�أ�����prevָ�벻����curָ�룬�򽻻�
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;  // �ƶ�curָ�����ɨ��
	}
	// ����׼Ԫ�طŵ���ȷλ��
	Swap(&a[prev], &a[key]);
	return prev;  // ���ػ�׼Ԫ�ص�λ��
}


void QuickSort(int* a, int left, int right) // hoare�汾�Ŀ�������
{
	if (left >= right) // �����ָ����ڵ�����ָ�룬˵���Ѿ�û��Ԫ����Ҫ���򣬵ݹ����
	{
		return;
	}
	int key = PartSort3(a, left, right); // ����partSort�����õ���׼ֵ������λ��
	QuickSort(a, left, key - 1); // ����ߵ���������еݹ�����
	QuickSort(a, key + 1, right); // ���ұߵ���������еݹ�����
	//�������ǲ��Ǻ����������ǰ������������������ң�����Ƿ��η�
}

// �������� �ǵݹ�ʵ��,���� ջ �ṹ
typedef struct 
{
	int left, right;
} StackFrame;//����һ�����������������±꣬һ��StackFrame����һ����Ҫ���������

void QuickSortNonR(int* a, int n) 
{
	// ��̬����ջ�ڴ�
	StackFrame* stack = (StackFrame*)malloc(n * sizeof(StackFrame));
	if (!stack) 
	{
		printf("�ڴ����ʧ��!\n");
		return;
	}

	int top = -1;  // ջ��ָ�룬����Ϊ-1����ָ��ջ��������Ϊ0����ָ��ջ����һ����λ�ã��������Լ���ϰһ��ջ

	// ��ʼ��ջ�������ʼ����
	stack[++top] = (StackFrame){ 0, n - 1 };
	//(StackFrame) { 0, n - 1 } ��һ���ṹ���ʼ�����﷨;stackFrame �ǽṹ�����ͣ�����������Ա���� low �� high
	//{0, n - 1} ��һ����ʼ���б���ʾ�� low ��ʼ��Ϊ 0���� high ��ʼ��Ϊ n - 1
	//��������
	/*StackFrame initialFrame;
	initialFrame.low = 0;
	initialFrame.high = n - 1;
	stack[++top] = initialFrame;*/

	while (top >= 0) //��ջ��Ϊ�������ѭ��
	{
		StackFrame current = stack[top--];// ȡջ�����StackFrame��������Ҫ������Ǹ����丳���´�����current���������������Ȼ�󵯳�ջ��
		int left = current.left;//�Ӹոյõ���current���������ȡ�������������ָ��
		int right = current.right;

		int prev = left, cur = prev + 1;// ��Lomuto˫ָ����л�׼ֵ������
		int key = left;
		while (cur <= right)
		{
			// ����ǰԪ��С�ڻ�׼Ԫ�أ�����prevָ�벻����curָ�룬�򽻻�
			if (a[cur] < a[key] && ++prev != cur)
			{
				Swap(&a[cur], &a[prev]);
			}
			++cur;  // �ƶ�curָ�����ɨ��
		}
		// ����׼Ԫ�طŵ���ȷλ��
		Swap(&a[prev], &a[key]);
		key = prev;//Ϊ�˷����������ำֵһ�Σ��ܹ����������׼Ԫ�ص�λ�ã�ʵ���Ͼ���������prev
		//֮�������˿���ֱ�Ӱ�����������Ϊprev + 1, right; left, prev - 1

		// ���Ҳ��������������������ջ��,ʵ���Ͼ�����ջ��ģ��ݹ��У���Ҫ�������䱻���޲�ֳɸ�С�Ĺ���
		// ��û�и�С������Ͳ���ջ��������ջ��գ��ʹ����������������������
		if (key + 1 < right)
		{
			stack[++top] = (StackFrame){ key + 1, right };
		}
		if (key - 1 > left) 
		{
			stack[++top] = (StackFrame){ left, key - 1 };
		}

	}
	// �ͷ�ջ�ڴ�
	free(stack);
}

//�鲢���� �ݹ�ʵ��
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
