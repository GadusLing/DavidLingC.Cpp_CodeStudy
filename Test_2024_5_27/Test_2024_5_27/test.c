#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int i = 1;
//
//	do
//	{
//		if (i == 5)
//			continue;
//
//		printf("%d ", i);
//		i++;
//	}
//	while (i <= 10);
//
//	return 0;
//}


//����n�Ľ׳�
//1*2*3*...*n


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int a = 0;
//	int m = 1;
//	for (a = 1;a <= n; a++)
//	{
//		m = m * a;
//	}
//	printf("\n%d\n", m);
//	return 0;
//}


//���� 1! + 2!+ 3!+ ..10!

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int a = 0;
//	int m = 1;
//	int b = 0;
//	for (a = 1; a <= n; a++)
//	{
//		m *= a;
//		b += m;
//	}
//	printf("\n%d\n", m);
//	printf("\n%d\n", b);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 1;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("\n%d\n", ret);
//	printf("\n%d\n", sum);
//	return 0;
//}


//��һ�����������в��Ҿ����ĳ������n��(������ֲ���)
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d\n", i);
//				break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("�Ҳ���\n");
//	}
//
//	return 0;
//}
//���ַ�ʽ�ǿ�����ɼ��������񣬵�����Ҫ���������е�����Ԫ�أ��������Ԫ�ع��࣬����������������ģ�������ò��ö��ַ����������


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int left = 0;
//	int right = sz-1;
//	
//
//	while (left <= right)
//	{
//		//int mid = (left + right) / 2;//������Ľ����㷨���������������������,������ĵ�P_34����ͼ
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
//			printf("�ҵ��ˣ��±��ǣ�%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���\n");
//	}
//
//	return 0;
//}


//��д���룬��ʾ����ַ��������ƶ������м���
//
//int main()
//{
//	char arr1[] = "Hello World!";
//	char arr2[] = "############";
//
//	char buf[] = "abc";
//	//[a b c \0]
//
//	int left = 0;
//	int right = strlen(buf) - 1;// strlenͳ�Ƶ���\0֮ǰԪ�صĸ�����������3�����±��Ǵ�0��ʼ��ģ�����Ҫ-1
//
//	return 0;
//}

#include <windows.h>
#include <stdlib.h>

//int main()
//{
//	char arr1[] = "Hello,World!";
//	char arr2[] = "############";
//
//	int size = sizeof(arr1) / sizeof(arr1[0]);
//
//	int left = 0;
//	int right = size - 2;//[a b c \0] \0Ҳ��һ��Ԫ�أ�����֮������4��C��Ӧ���±���2������Ҫ-2
//	
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		//���ƽ��
//		system("cls");//system��һ�������⣬����ִ��ϵͳ����
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}


//��д����ʵ�֣�ģ���û���¼�龰������ֻ�ܵ�¼���Ρ�(ֻ���������������룬���������ȷ��
//��ʾ��¼�ɣ�������ξ�����������˳�����

#include <string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("����������:>");
		scanf("%s", password);
		if (strcmp(password, "lingdawei") == 0 ) //�Ƚ�2���ַ����Ƿ���ȣ�����ʹ�� == ����Ӧ��ʹ��һ���⺯��: strcmp  //strcmp�����ķ���ֵΪ0��ʾ�����ַ�����ͬ
		{
			printf("��½�ɹ�");
			break;
		}
		else
		{
			printf("�������\n");
		}
	}
	if (i == 3)
	{
		printf("���δ������룬������ʱ���������Ժ�����\n");
	}

	return 0;
}
