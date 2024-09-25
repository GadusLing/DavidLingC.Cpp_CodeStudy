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
//	printf("%zd\n", sizeof(a));//16   sizeof(数组名)求的是整个数组的大小
//	printf("%zd\n", sizeof(a + 0));//4or8    a+0依然是首元素地址   sizeof(a + 0)计算的是首元素地址的大小，地址根据不同平台是4or8
//	printf("%zd\n", sizeof(*a));//4     首元素的a解引用，得到首元素    sizeof(*a)计算的的是首元素的大小-int 4
//	printf("%zd\n", sizeof(a + 1));//4or8    首元素地址+1，得到第二个元素的地址，地址根据不同平台是4or8
//	printf("%zd\n", sizeof(a[1]));//4    a里面的第二个元素，int类型， 是4
//	printf("%zd\n", sizeof(&a));//4or8     &a取出的是整个数组的地址，但是只要是地址就是4or8，不管什么类型的地址都是4or8
//	printf("%zd\n", sizeof(*&a));//16      1.&a取出的是整个数组的地址，再解引用就得到了整个数组里面元素的总大小，里面有4个int，4*4=16
//	                             //        2.*&a == a，*和&相互抵消，剩下的就是个a，sizeof(*&a) == sizeof(a)   16
//	printf("%zd\n", sizeof(&a + 1));//4or8    &a取出了整个数组的地址，根据其步长跳过整个数组，往后找了了16个字节，但依然是地址 4or8
//	printf("%zd\n", sizeof(&a[0]));//4or8     a先和[]结合，a[0]表示a数组里第一个元素的地址，再和&结合，其本质依然是地址 4or8
//	printf("%zd\n", sizeof(&a[0] + 1));//4or8     和上面一样，再怎么加它也是个地址，无非是单个元素的还是整个数组的，但只要是地址 就是4or8
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
//	printf("%zd\n", strlen(arr));//      不知何时找到\0 未知数
//	printf("%zd\n", strlen(arr + 0));//   不知何时找到\0 未知数
//	//printf("%zd\n", strlen(*arr));//      解引用arr给的是首元素 'a' - ASSIC码97   97作为地址空间传过去strlen没办法处理的  编译器要报错的
//	//printf("%zd\n", strlen(arr[1]));//     同样的问题，  传元素 'b'-98 过去strlen没办法处理
//	printf("%zd\n", strlen(&arr));//       不知何时找到\0 未知数
//	printf("%zd\n", strlen(&arr + 1));//     不知何时找到\0 未知数
//	printf("%zd\n", strlen(&arr[0] + 1));//    不知何时找到\0 未知数
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
//	//printf("%zd\n", strlen(*arr));// 传的是a的ASSIC 报错的
//	//printf("%zd\n", strlen(arr[1]));// 传的是b的ASSIC 报错的
//	printf("%zd\n", strlen(&arr));// 6
//	printf("%zd\n", strlen(&arr + 1));// 随机值
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
//	//printf("%zd\n", strlen(*p));// 传内容报错的
//	//printf("%zd\n", strlen(p[0]));// 传内容报错的
//	printf("%zd\n", strlen(&p));// 随机数
//	printf("%zd\n", strlen(&p + 1));// 随机数
//	printf("%zd\n", strlen(&p[0] + 1));// 5
//
//	return 0;
//}


//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%zd\n", sizeof(a));//16 or 48  看前面的行数写不写清楚
//	printf("%zd\n", sizeof(a[0][0]));//4
//	printf("%zd\n", sizeof(a[0]));//16
//	printf("%zd\n", sizeof(a[0] + 1));//16 ? 不是单独放sizeof里的同统一都是当首元素地址处理，所以这里是二维数组里第一行的首元素地址 是地址就是4or8
//	printf("%zd\n", sizeof(*(a[0] + 1)));//4or8 ?  地址解引用，第一行第二个元素 是int   4
//	printf("%zd\n", sizeof(a + 1));//4or8
//	printf("%zd\n", sizeof(*(a + 1)));//16
//	printf("%zd\n", sizeof(&a[0] + 1));//4or8
//	printf("%zd\n", sizeof(*(&a[0] + 1)));//16
//	printf("%zd\n", sizeof(*a));//16
//	printf("%zd\n", sizeof(a[3]));//16   不越界，sizeof不真实的访问内存进行运算，它只根据你提供的类型去反映大小
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

