#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//
//	//��ֵ
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	//��ӡ
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}

//void test(int a[])
//{
//
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	test(arr);
//
//	return 0;
//
//}

//void test2()
//{
//	printf("hello world");
//}
//
//void test1()
//{
//	test2();
//}
//
//void test()
//{
//	test1();
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 20;
//	int c = a + b;
//
//	printf("%d\n", c);
//
//
//	return 0;
//}


//1! + 2! +3! + ... +n! �׳�
//5��= 1*2*3*4*5
//n! = 1*2*3*...*n

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	for (int j = 1; j <= n; j++)
//	{
//		int ret = 1;
//		for (int i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//
//	return 0;
//}


//strcpy

#include <string.h>
#include <assert.h>

//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//}//�����汾�������������д��һ�㣬5��


//Ϊʲô����char*��?
//��Ϊ��ʵ����ʽ����
//strcpy�������ص���Ŀ��ռ����ʼ��ַ
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	//assert���� �������ж���䲻Ϊ��ʱ������
	assert(src != NULL);
	assert(dest != NULL);

	while (*dest++ = *src++)
	{
		
	}
	//return dest;//err
	return ret;
}

int main()
{
	char arr1[20] = "xxxxxxxxxxxxx";
	char arr2[] =   "Hello World";
	//strcpy�ڿ����ַ�����ʱ�򣬻��Դ�ַ����е�\8Ҳ������ȥ

	printf("%s\n", my_strcpy(arr1, arr2));

	return 0;

}


//int main()
//{
//	////int num = 10;
//	////num = 20;
//	////printf("%d\n", num);
//
//	const int num = 10;
//	////num = 20;
//
//	////const����ָ�����
//	////1.const ����*���
//	////��˼��:pָ��Ķ�����ͨ��p���ı���,����p���������ֵ�ǿ��Ըı��
//	////const int* p
//	////int const* p
//	////���ֵȼۣ���һ����ǰ���
//	////
//	//const int* p = &num;
//	////*p = 20;
//	//int n = 100;
//	//p = &n;
//
//	////2.const ����*�ұ�
//	//int* const p = &num;
//	//*p = 0;
//	//int n = 100;
//	//p = &n;
//	////��˼��:pָ��Ķ����ǿ���ͨ��p���ı�ģ����ǲ����޸�p���������ֵ
//
//	//const int* const p = &num;//�������ֶ�����
//
//
//	printf("%d\n", num);
//	return 0;
//}

