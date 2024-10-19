#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>




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

void test()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}

	if (1)
	{
		return;
	}


	free(p);
	p = NULL;
}

int main()
{
	test();

	return 0;
}



































