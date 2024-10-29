#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>




//int main()
//{
//	int* p = (int*)malloc(40);
//	//NULL
//	if (p == NULL)//防止申请空间失败
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	return 0;
//}




//int main()
//{
//	int* p = (int*)malloc(40);
//	//NULL
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	for (int i = 0; i <= 10; i++)//i<=10 就越界了
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		//printf("%d ", *(p + i));
//		printf("%d ", p[i]);
//	}
//
//	return 0;
//}




//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	int arr[5] = { 0 };
//	p = arr;//p被改了
//
//	free(p);//又去释放，但此时p并非是动态开辟的空间了
//	p = NULL;
//
//	return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	for (int i = 0; i < 5; i++)
//	{
//		*p = i;
//		p++;
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}



//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	free(p);
//
//
//	free(p);//二次释放要出事的
//	p = NULL;
//
//	return 0;
//}




//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	while (1)
//	{
//		;
//	}
//
//	return 0;
//}




//int* test()
//{
//	int* p = (int*)malloc(10 * sizeof(int));//这种情况下想释放都释放不了，局部变量出了函数被销毁了，但申请的那块空间没有free，再之后地址都找不到
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	return p;
//}
//int main()
//{
//
//
//	int* p2 = test();
//	feee(p2);//要么就把地址返回来再free
//
//	return 0;
//}

//void test()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//
//	if (1)
//	{
//		return;
//	}
//
//
//	free(p);
//	p = NULL;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}



//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf("%s", str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}


//char* GetMemory()
//{
//	char* p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	strcpy(str, "hello world");
//	printf("%s", str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}




//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}




//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}



//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}


//struct S
//{
//	int n;
//	int arr[];
//};
//
//int main()
//{
//	//struct S s;//不会这样写
//	//会这样写
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * (sizeof(int)));
//	ps->n = 100;
//	for (int i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i + 1;
//	}
//	struct S* tmp = (struct S*)realloc(ps, sizeof(struct S) + 40);
//	if (tmp == NULL)
//	{
//		perror("realloc");
//		return 1;
//	}
//	ps = tmp;
//	for (int i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i + 1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	free(ps);
//	ps = NULL;
//	
//	//printf("%zd\n", sizeof(struct S));
//}


//struct S2
//{
//	int n;
//	int* arr;
//};
//
//int main()
//{
//	struct S2* ps = (struct S2*)malloc(sizeof(struct S2));
//	if (ps == NULL)
//	{
//		perror("malloc-1");
//		return 1;
//	}
//	ps->n = 100;
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	if (ps->arr == NULL)
//	{
//		perror("malloc-2");
//		return 1;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i + 1;
//	}
//	int* ptr = (int*)realloc(ps->arr, 10 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("realloc");
//		return 1;
//	}
//	else
//	{
//		ps->arr = ptr;
//	}
//	for (int i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i + 1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	free(ps->arr);
//	ps->arr = NULL;
//
//	free(ps);
//	ps = NULL;
//
//
//	return 0;
//}









































