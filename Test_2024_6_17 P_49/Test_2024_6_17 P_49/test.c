#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)//ֻ��һ���Ⱥţ�������ô�������أ����Ǹ�ֵ��i����ֵ��5�ˣ������ı���ֵ5�����ϴ�ӡ
//			printf("%d", i);
//	}
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//		printf("1\n");
//		break;
//	case 2:
//		printf("1\n");
//		break;
//	default:
//		printf("�Ǻ�\n");
//		break;
//
//	}
//
//	return 0;
//
//}


//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1:b = 30;
//	case 2:b = 20;
//	case 3:b = 16;
//	default:b = 0;
//	}
//
//	return b;
//}

//int main()
//{
//	int x = 3;
//	int y = 3;
//	switch (x % 2)
//	{
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}


//дһ�������ӡ1-100֮������3�ı���������
//void swap(int *px, int* py)
//{
//	int tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	scanf("%d %d %d", &a, &b, &c);
//	int tmp = 0;
//	if (a < b)
//	{
//		swap(&a, &b);
//	}
//	if (a < c)
//	{
//		swap(&a, &c);
//	}
//	if (b < c)
//	{
//		swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 3; i <= 100; i+=3)
//	{
//		printf("%d ", i);
//	}
//
//	return 0;
//}


//���������������������������Լ��  ŷ������㷨-շת�����

//����ö�ٷ�
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	
//	int min = (a < b) ? a : b;
//	int m = min;
//
//	while (1)
//	{
//		if (a % m == 0 && b % m == 0)
//		{
//			break;
//		}
//		m--;
//	}
//	printf("%d\n", m);
//
//	return 0;
//}

//շת���
//int main()
//{
//	int a = 0;
//	int b = 0;
//    int c = 0;
//	scanf("%d %d", &a, &b);
//
//	while (c = a % b)//û��д��������Ϊ0Ϊ�٣���0Ϊ�棬���
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d\n", b);
//
//	return 0;
//}

//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}

//��д������һ�� 1 �� 100 �����������г��ֶ��ٸ�����9

//int countDigitNine(int n)
//{
//    int count = 0;
//    while (n)
//    {
//        if (n % 10 == 9)
//        {
//            count++;
//        }
//        n /= 10;
//    }
//    return count;
//}
//
//int main() 
//{
//    int totalCount = 0;
//    for (int i = 1; i <= 100; i++) 
//    {
//        totalCount += countDigitNine(i);
//    }
//    printf("1-100��9������: %d\n", totalCount);
//    return 0;
//}

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("1-100��9������: %d\n", count);
//	return 0;
//}


//����1/1 - 1/2 + 1/3 - 1/4 + 1/5......+1/99 - 1/100 ��ֵ����ӡ�����
//��������1
//��ĸ��1~100

//int main() 
//{
//    double sum = 0.0; // ��ʼ���ۼӺ�Ϊ0  
//    int sign = 1;     // ������ʾ�����ţ���ʼΪ��  
//
//    // ����1��100������  
//    for (int i = 1; i <= 100; i++)
//    {
//        // ����sign��ֵ�������Ǽӻ��Ǽ�  
//        sum += sign * (1.0 / i);
//        // ����sign��ֵ���´�ѭ��ʱȡ��  
//        sign *= -1;
//    }
//
//    // ��ӡ���  
//    printf("The result is: %f\n", sum);
//
//    return 0;
//}


//�� 10 �������е����ֵ

//int main()
//{
//	int numbers[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int max = numbers[0];
//
//    int i = 0; 
//    for (i = 1; i < 10; i++) 
//    {
//        if (numbers[i] > max)
//        {
//            max = numbers[i];
//        }
//    }
//    printf("���������ǣ�%d\n", max);
//
//	return 0;
//}


//����Ļ�����9*9�˷��ھ���

//int main() {
//    int i = 0;
//    int j = 0;
//    // ���ѭ�����Ƴ˷��ھ��������  
//    for (i = 1; i <= 9; i++) {
//        // �ڲ�ѭ�����Ƴ˷��ھ��������  
//        for (j = 1; j <= i; j++) {
//            // ��ӡ�˷����ʽ�ͽ��  
//            printf("%d*%d=%-2d  ", j, i, i * j);
//        }
//        // ÿ��ӡ��һ�к���  
//        printf("\n");
//    }
//
//    return 0;
//}


//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�� : ����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���

//void print_table(int n)
//{
//    int i = 0;
//    int j = 0;
//    for (i = 1; i <= n; i++) 
//    {
//        for (j = 1; j <= i; j++) 
//        {
//            printf("%d*%d=%-2d  ", j, i, i * j);
//        }
//        printf("\n");
//    }
//}
//
//int main() 
//{
//    int n = 0;
//    scanf("%d", &n);
//    print_table(n);
//
//    return 0;
//}


