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
int my_strlen(char* str)
{
	if (*str != '/0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
	{
		return 0;
	}
}


int main()
{
	char arr[] = "abc";//[a b c \0]
	int len = my_strlen(arr);
	printf("%d\n", len);


	return 0;
}