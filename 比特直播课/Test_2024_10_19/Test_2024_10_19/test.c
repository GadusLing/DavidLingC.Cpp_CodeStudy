#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>




//int main()
//{
//	int* p = (int*)malloc(40);
//	//NULL
//	if (p == NULL)//��ֹ����ռ�ʧ��
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
//	for (int i = 0; i <= 10; i++)//i<=10 ��Խ����
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
//	p = arr;//p������
//
//	free(p);//��ȥ�ͷţ�����ʱp�����Ƕ�̬���ٵĿռ���
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
//	free(p);//�����ͷ�Ҫ���µ�
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
//	int* p = (int*)malloc(10 * sizeof(int));//������������ͷŶ��ͷŲ��ˣ��ֲ��������˺����������ˣ���������ǿ�ռ�û��free����֮���ַ���Ҳ���
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
//	feee(p2);//Ҫô�Ͱѵ�ַ��������free
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



































