#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>




//int main()
//{
//	int a = 10;
//	printf("%zd\n", sizeof(a));
//	printf("%zd\n", sizeof a);
//
//	printf("%zd\n", sizeof(int));
//
//
//	return 0;
//}


//int main()
//{
//	//size_t len = strlen("abcdef");
//
//	char arr[] = "abcdef";
//	size_t len = strlen("abcdef");
//
//	printf("%zd", len);
//
//	return 0;
//}




//int main()
//{
//	char arr[3] = { 'a','b','c' };//[a b c]
//	size_t len = strlen(arr);
//	printf("%zd", len);
//
//	return 0;
//}






//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%zd\n", sizeof(a));//16   sizeof(������)�������������Ĵ�С
//	printf("%zd\n", sizeof(a + 0));//4or8    a+0��Ȼ����Ԫ�ص�ַ   sizeof(a + 0)���������Ԫ�ص�ַ�Ĵ�С����ַ���ݲ�ͬƽ̨��4or8
//	printf("%zd\n", sizeof(*a));//4     ��Ԫ�ص�a�����ã��õ���Ԫ��    sizeof(*a)����ĵ�����Ԫ�صĴ�С-int 4
//	printf("%zd\n", sizeof(a + 1));//4or8    ��Ԫ�ص�ַ+1���õ��ڶ���Ԫ�صĵ�ַ����ַ���ݲ�ͬƽ̨��4or8
//	printf("%zd\n", sizeof(a[1]));//4    a����ĵڶ���Ԫ�أ�int���ͣ� ��4
//	printf("%zd\n", sizeof(&a));//4or8     &aȡ��������������ĵ�ַ������ֻҪ�ǵ�ַ����4or8������ʲô���͵ĵ�ַ����4or8
//	printf("%zd\n", sizeof(*&a));//16      1.&aȡ��������������ĵ�ַ���ٽ����þ͵õ���������������Ԫ�ص��ܴ�С��������4��int��4*4=16
//	                             //        2.*&a == a��*��&�໥������ʣ�µľ��Ǹ�a��sizeof(*&a) == sizeof(a)   16
//	printf("%zd\n", sizeof(&a + 1));//4or8    &aȡ������������ĵ�ַ�������䲽�������������飬����������16���ֽڣ�����Ȼ�ǵ�ַ 4or8
//	printf("%zd\n", sizeof(&a[0]));//4or8     a�Ⱥ�[]��ϣ�a[0]��ʾa�������һ��Ԫ�صĵ�ַ���ٺ�&��ϣ��䱾����Ȼ�ǵ�ַ 4or8
//	printf("%zd\n", sizeof(&a[0] + 1));//4or8     ������һ��������ô����Ҳ�Ǹ���ַ���޷��ǵ���Ԫ�صĻ�����������ģ���ֻҪ�ǵ�ַ ����4or8
//
//	return 0;
//}


//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%zd\n", sizeof(arr));//6
//	printf("%zd\n", sizeof(arr + 0));//4or8
//	printf("%zd\n", sizeof(*arr));//1
//	printf("%zd\n", sizeof(arr[1]));//1
//	printf("%zd\n", sizeof(&arr));//4or8
//	printf("%zd\n", sizeof(&arr + 1));//4or8
//	printf("%zd\n", sizeof(&arr[0] + 1));//4or8
//
//	return 0;
//}



//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%zd\n", strlen(arr));//      ��֪��ʱ�ҵ�\0 δ֪��
//	printf("%zd\n", strlen(arr + 0));//   ��֪��ʱ�ҵ�\0 δ֪��
//	//printf("%zd\n", strlen(*arr));//      ������arr��������Ԫ�� 'a' - ASSIC��97   97��Ϊ��ַ�ռ䴫��ȥstrlenû�취�����  ������Ҫ�����
//	//printf("%zd\n", strlen(arr[1]));//     ͬ�������⣬  ��Ԫ�� 'b'-98 ��ȥstrlenû�취����
//	printf("%zd\n", strlen(&arr));//       ��֪��ʱ�ҵ�\0 δ֪��
//	printf("%zd\n", strlen(&arr + 1));//     ��֪��ʱ�ҵ�\0 δ֪��
//	printf("%zd\n", strlen(&arr[0] + 1));//    ��֪��ʱ�ҵ�\0 δ֪��
//
//	return 0;
//}




//int main()
//{
//	char arr[] = "abcdef";
//	printf("%zd\n", sizeof(arr));// 7
//	printf("%zd\n", sizeof(arr + 0));// 4or8
//	printf("%zd\n", sizeof(*arr));// 1
//	printf("%zd\n", sizeof(arr[1]));// 1
//	printf("%zd\n", sizeof(&arr));// 4or8
//	printf("%zd\n", sizeof(&arr + 1));// 4or8
//	printf("%zd\n", sizeof(&arr[0] + 1));// 4or8
//
//	return 0;
//}



//int main()
//{
//	char arr[] = "abcdef";
//	printf("%zd\n", strlen(arr));// 6
//	printf("%zd\n", strlen(arr + 0));// 6
//	//printf("%zd\n", strlen(*arr));// ������a��ASSIC �����
//	//printf("%zd\n", strlen(arr[1]));// ������b��ASSIC �����
//	printf("%zd\n", strlen(&arr));// 6
//	printf("%zd\n", strlen(&arr + 1));// ���ֵ
//	printf("%zd\n", strlen(&arr[0] + 1));// 5 
//
//	return 0;
//}


//int main()
//{
//	char* p = "abcdef";
//	printf("%zd\n", sizeof(p));//4or8
//	printf("%zd\n", sizeof(p + 1));//4or8
//	printf("%zd\n", sizeof(*p));//1
//	printf("%zd\n", sizeof(p[0]));//1
//	printf("%zd\n", sizeof(&p));//4or8
//	printf("%zd\n", sizeof(&p + 1));//4or8
//	printf("%zd\n", sizeof(&p[0] + 1));//4or8
//
//	return 0;
//}


//int main()
//{
//	char* p = "abcdef";
//	printf("%zd\n", strlen(p));// 6
//	printf("%zd\n", strlen(p + 1));// 5
//	//printf("%zd\n", strlen(*p));// �����ݱ����
//	//printf("%zd\n", strlen(p[0]));// �����ݱ����
//	printf("%zd\n", strlen(&p));// �����
//	printf("%zd\n", strlen(&p + 1));// �����
//	printf("%zd\n", strlen(&p[0] + 1));// 5
//
//	return 0;
//}


//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%zd\n", sizeof(a));//16 or 48  ��ǰ�������д��д���
//	printf("%zd\n", sizeof(a[0][0]));//4
//	printf("%zd\n", sizeof(a[0]));//16
//	printf("%zd\n", sizeof(a[0] + 1));//16 ? ���ǵ�����sizeof���ͬͳһ���ǵ���Ԫ�ص�ַ�������������Ƕ�ά�������һ�е���Ԫ�ص�ַ �ǵ�ַ����4or8
//	printf("%zd\n", sizeof(*(a[0] + 1)));//4or8 ?  ��ַ�����ã���һ�еڶ���Ԫ�� ��int   4
//	printf("%zd\n", sizeof(a + 1));//4or8
//	printf("%zd\n", sizeof(*(a + 1)));//16
//	printf("%zd\n", sizeof(&a[0] + 1));//4or8
//	printf("%zd\n", sizeof(*(&a[0] + 1)));//16
//	printf("%zd\n", sizeof(*a));//16
//	printf("%zd\n", sizeof(a[3]));//16   ��Խ�磬sizeof����ʵ�ķ����ڴ�������㣬��ֻ�������ṩ������ȥ��ӳ��С
//
//	return 0;
//}



int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	//2  5
	return 0;
}

