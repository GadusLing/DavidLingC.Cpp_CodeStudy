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

#include "add.h"
#include "sub.h"

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	//�ӷ�
	int sum = Add(a, b);
	printf("%d\n", sum);

	int ret = Sub(a, b);
	printf("%d\n", ret);//ѧ����ͷ�ļ���Դ�ļ���ģ�黮��


	return 0;
}

//�����Ķ���
//int Add(int x, int y)
//{
//	return x + y;
//}
