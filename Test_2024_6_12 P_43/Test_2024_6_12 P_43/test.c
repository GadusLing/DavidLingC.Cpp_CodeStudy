#define _CRT_SECURE_NO_WARNINGS

//��ʽ����

#include <stdio.h>

//int main()
//{
//	//int len = strlen("abcdef");
//	//printf("%d\n", len);
//
//	////��ʽ����
//	//printf("%d\n", strlen("abcdef"));
//
//	printf("%d", printf("%d", printf("%d", 43)));//������ʽ���ʣ�����ӡ������ɶ��4321
//
//
//	return 0;
//}




//�����Ķ��������

//����������
//int Add(int x, int y);

//#include "add.h"
//#include "sub.h"

//#pragma comment(lib, "add.lib")
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	//�ӷ�
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//
//	//int ret = Sub(a, b);
//	//printf("%d\n", ret);//ѧ����ͷ�ļ���Դ�ļ���ģ�黮��
//
//
//	return 0;
//}

//�����Ķ���
//int Add(int x, int y)
//{
//	return x + y;
//}

//����һ������ֵ(�޷���)������˳���ӡ����ÿһλ��
//����:
//����:1234�����1 2 3 4.


//%d �Ǵ�ӡ�з��ŵ�����(����������)
//%u �Ǵ�ӡ�޷��ŵ�����
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);//1234
//	while (num)
//	{
//		printf("%d ", num % 10);
//		num = num / 10;
//	}
//
//	//1 2 3 4
//	//printf("%u", num);
//
//	return 0;
//}


//�ݹ鷨
//void print(unsigned int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}	
//	printf("%d ", n % 10);
//	
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);//1234
//	print(num);//��print�����������һ������ֵ(�޷���)������˳���ӡ����ÿһλ��
//
//	return 0;
//}



//��д��������������ʱ���������ַ����ĳ���

#include <string.h>

//int my_strlen(char str[])//��������д���������ʽ
//int my_strlen(char * str)//��������д��ָ�����ʽ,����������ûɶ����д�����ֶ�����
//{
//	int count = 0;//��ʱ����������Ŀ�ǲ�Ҫ��ʱ���������Ը���ô���أ�
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//��β�������ʱ�����õݹ�ķ������
//int my_strlen(char* str)
//{
//	if (*str != '/0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//int main()
//{
//	char arr[] = "abc";//[a b c \0]
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//
//	return 0;
//}



//����׳�����
//�ݹ�ʵ��
//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * fac(n - 1);
//	}
//}

//ѭ���ķ�ʽ��д������������ʵ��
//int fac(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n ; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fac(n);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}




//���n��쳲�������������
//쳲���������
//1 1 2 3 5 8 13 21 34 55... ǰ����֮����ں�һλ��

//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);//�����õݹ���Ȼ�������ˣ����ӳ̶�̫��                 
//	}
//	
//}

//int Fib(int n)//���Ե�����
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//
//	return c;
//
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}


//void test(int n)
//{
//	if (n < 10000)
//	{
//		test(n + 1);
//	}
//}
//
//int main()
//{
//
//    test(1);
//	return 0;
//}//��β������ȿ��ǵݹ飬��αȽ���͵���
