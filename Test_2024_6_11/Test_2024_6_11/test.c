#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�żٻ�����ϰ�Ͻڿε����ݡ�������������ָ��

//void Swap(int *px,int *py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//
//Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	int c = Add(a, b);//���ﲻ�ô���ַ����˼��һ�£���ʲô���������Ҫ����ַ��ʲô����²�����ַ�أ�
//	//����Ҫʹ�û�ı����ʱ������ȡ��ַ�ķ�ʽ����ֻ�ǽ�����ֵ�����㡢��¼��������ʹ�û�ı�ʱ����ֻ����ֵ������
//	printf("%d\n", c);
//
//	printf("����ǰa=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("������a=%d,b=%d\n", a, b);
//
//	return 0;
//}


//1.дһ�����������ж�һ�����ǲ���������
//����(����)��������ֻ�ܱ�1������������

#include <math.h>//��ѧ�⺯��������sqrtҪ�õ�
//int main()
//{
//	int i = 0;//��ʼ��i��ѭ��Ҫ�жϵ��Ǹ���
//	int j = 0;//��ʼ��j��������ʾi֮ǰ���е���
//	scanf("%d", &i);//����i
//    int flag = 1;//flagΪ1���ǳ��ɾ�����ʾ������
//	for (j = 3; j <= sqrt(i); j+=2)//��i֮ǰ��1֮������е���(i-1)��ѭ���Գ�i
//	{//�����j < i -1Ҳ�����ö�������/������˹/��ʽɸ�����Ż�
//		if (i % j == 0)//i��jȡģ�������Ϊ0�����ʾû����������i����֮ǰ������������i����i�Ͳ�������
//		{
//			flag = 0;//���һ�£����ɾ��ˣ���������
//			break;//������ǰ��forѭ��
//		}	
//	}
//	if (flag == 1)
//	{
//		printf("%d������\n", i);
//	}
//	else
//	{
//		printf("%d��������\n", i);
//	}
//	return 0;
//}

//�����İ汾

//int is_prime(int n)
//{
//    if (n <= 1)
//    {
//        return 0; // 0��1��������  
//    }
//    if (n == 2)
//    {
//        return 1; // 2������  
//    }
//    if (n % 2 == 0)
//    {
//        return 0; // ����2�����ż������������  //ɸ������2�ı�����ֵȫɸ��
//    }
//    for (int j = 3; j <= sqrt(n); j += 2) 
//    {
//        if (n % j == 0) 
//        {
//            return 0; // ���n�ܱ�j��������������  
//        }
//    }
//    return 1; // ������������������㣬��n������  
//}
//
//int main() 
//{
//    int i = 0;
//    scanf("%d", &i);
//
//    if (is_prime(i)) 
//    {
//        printf("%d������\n", i);
//    }
//    else 
//    {
//        printf("%d��������\n", i);
//    }
//    return 0;
//}



//2.дһ�������ж�һ���ǲ������ꡣ
//��ӡ1000-2000��֮�������
//���ꡪ�������ܱ�4�������Ҳ��ܱ�100�������ܱ�400����
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//		}
//	}
//
//	return 0;
//}


//�����汾
//int is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//
//	return 0;
//}



//3.дһ��������ʵ��һ��������������Ķ��ֲ��ҡ�
//int binary_search(int arr[], int k, int sz)//��ʽ������ʵ�ʲ��������ֿ�����ͬ��Ҳ���Բ�ͬ
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//
//	return - 1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//    //�ҵ��ˣ������±�
//	//�Ҳ���������-1��Ϊɶ������0����Ϊ�±��һλ����0��������
//
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("�Ҳ���");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±���:%d\n", ret);
//	}
//	
//	return 0;
//}



//4.дһ��������ÿ����һ������������ͻὫ num ��ֵ����1��

void Add(int* p)
{
	(*p)++;
}

int main()
{
	int num = 0;
	Add(&num);
	printf("%d\n", num);//1
	Add(&num);
	printf("%d\n", num);//2

	return 0;
}