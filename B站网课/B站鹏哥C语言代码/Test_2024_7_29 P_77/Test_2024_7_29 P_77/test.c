#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	int a = 10;//a�����α�����ռ4��byte���ڴ�ռ�
//
//
//	return 0;
//}

//int main()
//{
//	char* pc = NULL;
//	short* ps = NULL;
//	int* pi = NULL;
//	double* pd = NULL;
//
//	//sizeof ���ص�ֵ���������޷������� unsigned int
//	printf("%zu\n", sizeof(pc));
//	printf("%zu\n", sizeof(ps));
//	printf("%zu\n", sizeof(pi));
//	printf("%zu\n", sizeof(pd));
//
//	return 0;
//}

//ָ�����͵�����

//0 1 2 3 4 5 6 7 8 9 a b c d e f
// 0  0
// 1  1
// 10  2
// 11  3
// 100  4 
// 1010  10
// 
//f = 15
//1111


//int main()
//{
//	int a = 0x11223344;//0x��ͷ�Ķ���16�������֣�1��16����λ��4��2����λ��2��16����λ����8��2����λ������2��16����λ����1���ֽڣ�8bit��
//	
//	//int * pa = &a;
//	//*pa = 0;
//
//	char* pc = (char*)&a;//int*
//	*pc = 0;
//	//����:
//	//ָ�����;�����ָ���ڱ������õ�ʱ����ʼ����ֽ�
//	//�����int*��ָ�룬�����÷���4���ֽ�
//	//�����char*��ָ�룬�����÷���1���ֽ�
//	//�ƹ㵽��������
//	return 0;
//	
//}

//int main()
//{
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = (char*) & a;
//	
//	printf("pa   = %p\n", pa);
//	printf("pa+1 = %p\n", pa + 1);
//	
//	printf("pc   = %p\n", pc);
//	printf("pc+1 = %p\n", pc + 1);
//
//
//	return 0;
//}

//����2:
//ָ������;�����ָ�� +1 -1 ������ʱ�����������ֽ�
//������ָ��Ĳ���
//

//int main()
//{
//	int a = 0;
//
//	int* pi = &a;//pi �����÷���4���ֽڣ�pi+1Ҳ������4���ֽ�
//	float* pf = &a;//pf �����÷���4���ֽڣ�pf+1Ҳ������4���ֽ�
//	//int*�� float* �ǲ��ǾͿ���ͨ�ð� ?
//	//����
//	//*pi = 100;
//	*pf = 100.0;
//
//	return 0;
//}


//int main()
//{
//	int* p;//pû�г�ʼ����Ĭ��Ϊ���ֵ
//	
//	*p = 10;//�Ƿ������ڴ���
//
//	return 0;
//}


//int main()//Խ�����
//{
//	int arr[10] = { 0 };
//	int* p = arr;//&arr[0]
//	for (int i = 0; i <= 10; i++)
//	{
//		*p = i;
//		p++;
//	}
//
//
//	return 0;
//}



//int* test()//�ռ䱻�ͷ���
//{
//	int a = 10;
//	return &a;
//}
//
//int main()
//{
//	int* p = test();
//
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//	//int* p = &a;
//	//*p = 20;
//
//	//int* p2 = NULL;
//	//*p2 = 100;//err
//
//	int* p3 = NULL;
//	if (p3 != NULL)
//	{
//		*p3 = 100;//ok���÷�
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizrof(arr) / sizrof(arr[0]);
//	////�����±��д��
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	arr[i] = 1;
//	//}
//
//	//int* p = arr;
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	*p = 1;
//	//	 p++ ;
//	//}
//
//	int* p = arr;
//	for (int i = 0; i < sz; i++)
//	{
//		*(p + i) = 1;
//	}
//
//
//
//	return 0;
//}

//ָ������
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[0] - &arr[9]);
//
//
//	return 0;
//}

#include <string.h>
//�����汾
//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}

//�ݹ�İ汾��֮ǰ����
/////////

//ָ��-ָ�� �İ汾
int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return (str - start);
}


int main()
{
	int len = my_strlen("abcdef");
	printf("%d\n", len);

	return 0;
}




