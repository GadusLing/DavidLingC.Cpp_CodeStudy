#define _CRT_SECURE_NO_WARNINGS
//C���Դ�����һ��Ҫ��main����
//main ����


//printf��һ���⺯��
//ר��������ӡ����

//stdio.h --- (std - Standard - ��׼)  (i - input - ����)  (o - output - ���)

//vs2022����������д��� --- ctrl + F5 ---   ���ּ�����Ҫ��סfn + ctrl +F5

#include <stdio.h>
//main�����ǳ������ڣ���������ڴ������ִ��
//main��������ֻ��һ��
//int main()
//{
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//
//   return 0;          //C������ʷ����ϰ�ߣ���BUG����0����BUG����1
//}

//���ϵ�д�������Ƽ���
//void main()
//{
//
//}

//char  �ַ���������

//short  ������
//int  ����
//long  ������
//long long  ����������

//float  �����ȸ�����
//double  ˫���ȸ�����

//ÿ�����͵Ĵ�С��Χ�Ƕ��٣�
//int main()
//{
//	printf("%zu\n", sizeof(char));
//	printf("%zu\n", sizeof(short));
//	printf("%zu\n", sizeof(int));
//	printf("%zu\n", sizeof(long));
//	printf("%zu\n", sizeof(long long));
//	printf("%zu\n", sizeof(float));
//	printf("%zu\n", sizeof(double));
//	return 0;
//}

//������еĵ�λ
//bit ����λ
//byte �ֽ�
//kb
//mb
//gb
//tb
//pb
//8bit = 1byte = 1024kb = 1024mb = 1024gb = 1024tb = 1024pb

//int main()
//{
//	int age = 20;
//	float price = 66.6;
//	return 0;
//}

//C������û���ַ�������?
//C��������û��ר�ŵ��ַ������͡���C�����У��ַ����Ǳ������ַ������������

//�����ͳ���
//int main()
//{
//	short age = 20;
//	int number = 420984199015262564;
//	float high = 180;
//	float weight = 80.5;
//	return 0;
//}
//������Ϊ�ֲ�������ȫ�ֱ�������
//�ֲ�����-{}�ڲ�����ı���
//ȫ�ֱ���-{}�ⲿ����ı���

//int b = 20;
//
//int main()
//{
//	int a = 10;
//	return 0;
//}

//int a = 100;
//
//int main()
//{
//	int a = 10;
//	printf("a=%d\n", a); //��ȫ�ֱ����;ֲ�����������ͬ������£��ֲ�����
//
//	return 0;
//}

//���ǽ��鲻Ҫ��ȫ�ֺ;ֲ�����������д��һ����

//дһ�����룬����2�������ĺ�
//scanf ��һ�����뺯��
//printf��һ���������
//int main()
//{
//	int num1 = 0;//���︳��0ֵ����ʼ����ΪʲôҪ��ʼ������Ϊһ�ᱨ���棬���������û�г�ʼ������Ĭ�Ϸŵ��Ǹ����ֵ��Ӱ���������
//	int num2 = 0;
//
//	//����2������
//	scanf("%d %d", &num1, &num2);
//	//���
//	int sum = num1 + num2;
//	//���
//	printf("%d\n",sum);
//
//	return 0;
//}
//This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online 
// help for details.

//�������ʹ��scanf_s����Դ�����һ�м���#define _CRT_SECURE_NO_WARNINGS
//Ϊʲô����scanf_s����Ϊ scanf_s ���������VS�������Լ��ṩ�ĺ���,�Ǳ�׼C�ṩ�ĺ�������Ҳ����ֻ��VS��������ʶ,��������������ʶ!
//�ҵĽ�����ʹ��scanf
//������Ҫʹ��scanf_s�������о�һ����ʹ��!


//������������
//1.�ֲ�����
//�ֲ��������������Ǳ������ڵľֲ���Χ
//2.ȫ�ֱ���
//ȫ�ֱ��������������������̡�


//������������
//�ֲ�����������������: �����������������ڿ�ʼ�����������������ڽ���
//ȫ�ֱ���������������: �����������������
//int main()
//{
//	{
//		int a = 100;
//		printf("% d\n", a);
//	}
//
//	printf("% d\n", a);
//	return 0;
//}


//���������ⲿ�ķ���
//extern int a;
//
//
//void test()
//{
//	printf("test-->%d\n", a);
//}
//
//
//int main()
//{
//	test();
//	{
//		printf("a=%d\n",a);
//	}
//	printf("a=%d\n", a);
//
//	return 0;
//}





























