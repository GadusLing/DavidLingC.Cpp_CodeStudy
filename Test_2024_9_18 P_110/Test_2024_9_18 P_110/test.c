#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	//ָ������
//	int* arr[4];
//	char* ch[5];
//	int** p = arr;//arr������ = ��Ԫ�ص�ַ = int*���͵ĵ�ַ��Ҳ����һ��ָ�룬�����ö���ָ��p����
//
//	//����ָ��
//	int arr2[5];
//	int(*pa)[5] = &arr2;
//
//	char* arr3[6];
//	char* (*p3)[6] = &arr3;
//
//
//	return 0;
//}



//
//int test(const char* str)
//{
//	printf("test()\n");
//	return 0;
//}
//
//int main()
//{
//	//����ָ�� - Ҳ��һ��ָ�룬��ָ������ָ��
//	printf("%p\n", test);
//	printf("%p\n", &test);
//
//	int (*pf)(const char*) = &test;
//	(*pf)("abc");
//	test("abc");
//	pf("abc");
//
//	return 0;
//}


////typedef unsigned int uint;
//typedef void(*pf_t)(int);//��void(*)(int)����������Ϊpf_t
//
//
//
//int main()
//{
//	(*(void (*)())0)();//��P105
//
//	void(*signal(int, void(*)(int)))(int);
//	pf_t signal(int, pf_t);
//
//
//	return 0;
//}




////����ָ�����;
////дһ��������
////�ӷ����������˷�������
//
//void menu()
//{
//	printf("***********************\n");
//	printf("****1. add   2. sub****\n");
//	printf("****3. mul   4. div****\n");
//	printf("****    0. exit    ****\n");
//	printf("***********************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("����������������\n");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);//�ص�����
//	printf("%d\n", ret);
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}
