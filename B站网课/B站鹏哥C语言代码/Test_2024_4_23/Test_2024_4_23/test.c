#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//	int a = 10;
//	if (a == 3)
//		printf("%s\n", "hehe");
//
//	int age = 20;
//	if (age > 18)
//	{
//		printf("δ����\n");
//		printf("��������\n");
//	}
//	else
//	{
//        printf("����\n");
//	}
//
//	return 0;
//}
	//int age = 10;
	//scanf("%d", &age);
	//if (age < 18)
	//{
	//	printf("������\n");
	//}
	//else if (age >= 18 && age < 28)
	//{
	//	printf("����\n");
	//}
	//else if (age >= 28 && age < 40)
	//{
	//	printf("����\n");
	//}
	//else if (age >= 40 && age < 60)
	//{
	//	printf("׳��\n");
	//}
	//else if (age >= 60 && age <= 100)
	//{
	//	printf("����\n");
	//}
	//else
	//{
	//	printf("������\n");
	//}

	//return 0;

	//int main();
	//{
	//	int age = 20;
	//	if (age < 18)
	//		printf("δ����\n");
	//	else
	//	{
	//		printf("����\n");
	//		printf("����Ϸ\n");
	//	}

	//		return 0;
	//}

	//int main();
	//{
	//	int a = 0;
	//	int b = 2;
	//	if (a == 1)
	//	{
	//		if (b == 2)
	//			printf("hehe\n");
	//		else
	//			printf("haha\n");
	//	}
	//	return 0;
	//}

	//int main();
	//{
	//	int a = 0;
	//	int b = 2;
	//	if (a == 1)
	//	{
	//		if (b == 2)
	//			printf("hehe\n");
	//	}
	//	else
	//		printf("haha\n");
	//	
	//	return 0;
	//}

	//1.ͬʱ��Ҫע�⣺���������������������ģ��淶��
	//int main;
	//{
	//	//char firstname[20] = { 0 };
	//	//char first_name[20] = { 0 };//�»�������
	//	//char FirstName[20] = { 0 };//�շ�

	//	int a = 10;
	//	int a=10;//�ܼ��������

	//  return 0;
	//}

//int test()
//{
//	int a = 4;
//	if (a == 3)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	int r = test();
//	printf("%d\n", r);
//
//	return 0;
//}

//int main()
//{
//	int num = 3;
//		if (5 == num)//if (num == 5)   //���ж���ֵ���Ǹ�ֵ������£���������ֵ��д��������Ա�����ʧ�ȺŵĴ���
//			printf("hehe\n");
//
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	//�ж�
//	if (num % 2 == 1)
//		printf("����\n");
//	else
//		printf("������\n");
//
//	return 0;
//}

//int main()
//{
//	int num = 1;
//	while (num >= 1 & num <= 100)
//	{
//		if (num % 2 == 1)
//			printf("%d ", num);
//		num++;
//	}
//	return 0;
//}

//int main()
//{
//	int num = 1;
//	while (num >= 1 & num <= 100)
//	{
//		if (num % 2 == 1)
//			printf("%d ", num);
//		num+=2;//+2һ��Ҳ��������������Ƕȱ�����ö�ٹ��̣����������
//	}
//	return 0;
//}

//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	//if (1 == day)
//	//{
//	//	printf("����һ\n");
//	//}
//	//else if (2 == day)
//	//{
// //       printf("���ڶ�\n");
//	//}   
//	//else if (3 == day) 
//	//{
//	//	printf("������\n");
//	//}
//	//else if (4 == day)
//	//{
//	//	printf("������\n");
//	//}
//	//else if (5 == day)
//	//{
//	//	printf("������\n");
//	//}
//	//else if (6 == day)
//	//{
//	//	printf("������\n");
//	//}
//	//else if (7 == day)
//	//{
//	//	printf("������\n");
//	//}
//
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	default:
//		printf("������������������\n");
//		break;
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//		case 1:m++;
//		case 2:n++;
//		case 3:
//			switch (n)
//			{//switch ����Ƕ��ʹ��
//			case 1:n++;
//			case 2:m++; n++;
//				break;
//			}
//		case 4:
//			m++;
//			break;
//		default:
//			break;
//	}
//	printf("m = %d,n = %d", m, n);
//	return 0;
//}

//int main()
//{
//	while (1)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//whileѭ���е�
//break���������õ���ֹѭ��
//continue ��������ѭ������Ĵ��룬ֱ��ȥ�жϲ��֣�������һ��ѭ�����ж�
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i++;
//		if (5 == i)
//			continue;
//
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
//int main()
//{
//	//int ch = 0;
//	//while (getchar())
//	//EOF;//end of file
//	//int ch = getchar();
//	//printf("%c\n", ch);
//	//putchar(ch);
//
//	//int ch = 0;
//	//while ((ch = getchar()) != EOF)
//	//{
//	//	putchar(ch);
//
//	//}
//
//
//	//��һ������
//	//����������һ���ַ���
//	char password[20] = { 0 };
//	printf("����������:>");//123456
//	scanf("%s", password);
//	
//	//getchar();//��ȡ��\n
//	int ch = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//
//
//	printf("��ȷ������(Y/N):>");
//	int ret = getchar();
//	if ('Y' == ret)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	char ch = '\0';
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//		putchar(ch);
//	}
//	//ֻ��ӡ�����ַ�
//	return 0;
//}

