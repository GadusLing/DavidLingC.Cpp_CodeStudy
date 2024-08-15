#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//int main()
//{
//	int a = 10;//a是整形变量，占4个byte的内存空间
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
//	//sizeof 返回的值的类型是无符号整型 unsigned int
//	printf("%zu\n", sizeof(pc));
//	printf("%zu\n", sizeof(ps));
//	printf("%zu\n", sizeof(pi));
//	printf("%zu\n", sizeof(pd));
//
//	return 0;
//}

//指针类型的意义

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
//	int a = 0x11223344;//0x开头的都叫16进制数字，1个16进制位是4个2进制位，2个16进制位就是8个2进制位，所以2个16进制位就是1个字节（8bit）
//	
//	//int * pa = &a;
//	//*pa = 0;
//
//	char* pc = (char*)&a;//int*
//	*pc = 0;
//	//结论:
//	//指针类型决定了指针在被解引用的时候访问几个字节
//	//如果是int*的指针，解引用访问4个字节
//	//如果是char*的指针，解引用访问1个字节
//	//推广到其他类型
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

//结论2:
//指针的类型决定了指针 +1 -1 操作的时候，跳过几个字节
//决定了指针的步长
//

//int main()
//{
//	int a = 0;
//
//	int* pi = &a;//pi 解引用访问4个字节，pi+1也是跳过4个字节
//	float* pf = &a;//pf 解引用访问4个字节，pf+1也是跳过4个字节
//	//int*和 float* 是不是就可以通用啊 ?
//	//不能
//	//*pi = 100;
//	*pf = 100.0;
//
//	return 0;
//}


//int main()
//{
//	int* p;//p没有初始化，默认为随机值
//	
//	*p = 10;//非法访问内存了
//
//	return 0;
//}


//int main()//越界访问
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



//int* test()//空间被释放了
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
//		*p3 = 100;//ok的用法
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizrof(arr) / sizrof(arr[0]);
//	////数组下标的写法
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

//指针的相减
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[0] - &arr[9]);
//
//
//	return 0;
//}

#include <string.h>
//基础版本
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

//递归的版本，之前讲过
/////////

//指针-指针 的版本
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




