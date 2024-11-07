#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//struct S
//{
//	char c;
//	int i;
//};
//
//union U
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(struct S));
//	printf("%zd\n", sizeof(union U));
//	return 0;
//}



//union U
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(union U));
//	union U u;
//	printf("%p\n", &u);
//	printf("%p\n", &(u.c));
//	printf("%p\n", &(u.i));
//
//	return 0;
//}



//union U
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	union U u;
//	u.i = 0x11223344;
//	u.c = 0;
//
//	return 0;
//}


//union un
//{
//	char c[5];//5
//	int i;//4
//};
//
//union un2
//{
//	short c[7];//14
//	int i;//4
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(union un));
//	printf("%zd\n", sizeof(union un2));
//
//	return 0;
//}


//struct gift_list
//{
//	//公共属性
//	int stock_number;//库存量
//	double price; //定价
//	int item_type;//商品类型
//
//	//特殊属性
//	char title[20];//书名
//	char author[20];//作者
//	int num_pages;//⻚数
//
//
//	char design[30];//设计
//	int colors;//颜⾊
//	int sizes;//尺⼨
//};

//struct gift_list
//{
//    int stock_number;//库存量
//    double price; //定价
//    int item_type;//商品类型
//
//    union
//    {
//        struct
//        {
//            char title[20];//书名
//            char author[20];//作者
//            int num_pages;//⻚数
//        }book;
//        struct
//        {
//            char design[30];//设计
//        }mug;
//        struct
//        {
//            char design[30];//设计
//            int colors;//颜⾊
//            int sizes;//尺⼨
//        }shirt;
//    }item;
//};




//int check_sys()
//{
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//
//	return un.c;//返回1是⼩端，返回0是⼤端
//}
//
//int main()
//{
//	int a = 1;
//	if (*(char*)&a == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	if (check_sys() == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}


//enum Day//星期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//
//enum Sex//性别
//{
//	MALE,
//	FEMALE=4,
//	SECRET
//};
//
//enum Color//颜⾊
//{
//	RED,
//	GREEN,
//	BLUE
//};
//
//int main()
//{
//	printf("%d\n", MALE);
//	printf("%d\n", FEMALE);
//	printf("%d\n", SECRET);
//
//	return 0;
//}



#include <stdlib.h>
////动态内存管理的内容
//int main()
//{
//	//int a = 10;//一次性开辟一块空间 - 4 字节
//	//int arr[5];//一块连续的空间 - 20 字节
//
//	//struct S s[30];//15 31? 不灵活
//
//	int* p = (int*)malloc(40);//10*sizeof(int)
//	//int* p = (int*)malloc(INT_MAX * 4);
//
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;//异常返回
//	}
//	//如果开辟成功就可以使用空间了
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i + 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	//申请了要还！一定要释放！
//	free(p);//此时p还记录着申请空间的地址，要指控，不然就野指针了
//
//	p = NULL;//置为空指针
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int* p = &a;
//	
//	free(p);//err
//
//	return 0;
//}



//int main()
//{
//	int* p = malloc(10 * sizeof(int));
//	//int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		perror("calloc");
//		return 1;
//	}
//	//使用
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	//释放
//	free(p);
//	p = NULL;
//
//	return 0;
//}



int main()
{
	int* p = (int*)malloc(20);
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	//使用
	for (int i = 0; i < 5; i++)
	{
		*(p + i) = i + 1;
	}
	//1 2 3 4 5
	int* ptr = (int*)realloc(p, 40);
	if (ptr != NULL)
	{
		p = ptr;
	}
	else
	{
		perror("realloc");
		return 1;
	}
	for (int i = 5; i < 10; i++)
	{
		*(p + i) = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
	//释放
	free(p);
	p = NULL;

	return 0;
}



int main()
{
	realloc(NULL, 20);//此时realloc的功能等价于malloc(20)

	return 0;
}
















































