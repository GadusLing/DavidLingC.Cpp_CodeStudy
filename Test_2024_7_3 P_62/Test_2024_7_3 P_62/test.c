#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int Fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}
//
//int main()
//{
//	int ret = Fun(2);
//	printf("%d\n", ret);
//
//
//	return 0;
//}


//�����ķ�ʽ
//void reverse(char arr[])
//{
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	//int right = sz - 2;//�����ڲ��Ͳ�����sizeof�ķ�����-���鴫������Ԫ��ָ���ַ
//	int right = strlen(arr) - 1;//��strlen�������Ч����һ����
//
//	while (left < right)
//	{
//		char temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//
//		left++;
//		right--;
//	}
//}



//�ݹ�ķ�ʽ

int my_strlen(char* p)
{
	int count = 0;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}
//����һ������
//void reverse(char* str)
//{
//	char tmp = *str;
//	int len = my_strlen(str);
//	printf("%d\n", len);
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) >= 2)
//	{
//		reverse(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
// 
//int main()
//{
//	char arr[] = "abcdefg";//[a b c d e f g \0]
//
//	reverse(arr);
//
//	printf("%s\n", arr);
//
//	return 0;
//}



//��������������ôд
void reverse(char arr[], int left, int right)
{
	
	if (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		reverse(arr, left + 1, right - 1);
	}
}
int main()
{
	char arr[] = "abcdef";//[a b c d e f g \0]
	int left = 0;
	int right = my_strlen(arr) - 1;
	reverse(arr, left, right);

	printf("%s\n", arr);

	return 0;
}


//int DigitSum(unsigned int n)
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	printf("%d\n", DigitSum(n));
//	return 0;
//}


//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��


//double Pow(int n, int k) 
//{
//    if (k == 0)
//    {
//        return 1; // �κ�����0�η�����1  
//    }
//    else if (k < 0) 
//    {
//        return 1.0 / Pow(n, -k); // ����ָ��  
//    }
//    else if (k % 2 == 1) 
//    {
//        return n * Pow(n, k - 1); // �����η�  
//    }
//    else 
//    {
//        double half = Pow(n, k / 2);
//        return half * half; // ż���η�  
//    }
//}
//
//double Pow(int n, int k)
//{
//    if (k > 0)
//    {
//        return n * Pow(n, k -1);  
//    }
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 1.0 / Pow(n, -k);
//	}
//
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("%lf\n", ret);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,(3,4),5 };
//	printf("%d\n", sizeof(arr));
//	return 0;
//}



////sizeof
////sizeof��һ��������
////�������������(����)��ռ�ڴ�ռ�Ĵ�С������ע�ڴ��д�ŵľ�������
////��λ���ֽ�
//// 
//// 
////strlen
////strlen��һ���⺯������ר�����ַ������ȵģ�ֻ������ַ���
////�Ӳ��������ĵ�ַ���һֱ��\0,ͳ��\0֮ǰ���ֵ��ַ��ĸ���
//#include <stdio.h>
//int main()
//{
//	char str[] = "hello bit";
//	printf("%d %d\n", sizeof(str), strlen(str));
//	return 0;
//}


//������A�е����ݺ�����B�е����ݽ��н�����(����һ����)
//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,0 };
//
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr1[i]);
//
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr2[i]);
//
//	}
//	//����һ�������ʾ��
//    //int tmp[]={ 0 };//һ�������ʼ��ֻ��һ��Ԫ�صĿռ䣬�ռ䲻��
//	// 
//    //tmp = arr1;//�������鶼��ָ�룬����Ӱ�첻���ڲ�����
//	//arr1= arr2;
//	//arr2 = tmp;
//
//	return 0;
//}



//����һ���������飬��ɶ�����Ĳ���

//ʵ�ֺ���init()��ʼ������Ϊȫ0
//ʵ��print() ��ӡ�����ÿ��Ԫ��
//ʵ��reverse() �����������Ԫ�ص����á�

//void init(int arr[],int sz)
//{
//	int i = 0;
//	for(i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//}
//
//reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	for (left = 0; left < right; left++)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	init(arr,sz);
//	print(arr, sz);
//
//	return 0;
//}
