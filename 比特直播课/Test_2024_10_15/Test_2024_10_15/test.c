#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////�ṹ������
//struct Stu
//{
//	char name[20];
//	int age;
//	char id[12];
//	double wight;
//}; s4, s5, s6; // �����s4, s5, s6��ȫ�ֱ���
//
//
//int main()
//{
//	struct Stu s1 = { "zhangsan",20,"20240101",75.2 };//��ͽб����ĳ�ʼ��
//	struct Stu s2 = { .age = 18,.wight = 78.3,.name = "lisi",.id = "20230102" };
//	//struct Stu s3;//���ﴴ����s1 s2 s3 �Ǿֲ�����
//
//	printf("���֣�%s ���䣺%d\n", s1.name, s1.age);//.�������  ����ǽṹ�������  �ұ��ǽṹ���ڵĳ�Ա��
//	printf("���֣�%s ���䣺%d\n", s2.name, s2.age);
//	printf("���֣�%s ���䣺%d\n", (&s2)->name, (&s2)->age);//->��ͷ�����������ýṹ��ĵ�ַ��Ѱ�ҳ�Աʱ�� ����ǽṹ�������  �ұ��ǽṹ���ڵĳ�Ա��
//
//	return 0;
//}


//�ṹ�����������
//�����ṹ��

//struct          //��ͽ������ṹ�壬û��д�ṹ�����ִ�S ���ֽṹ��ֻ����һ��
//{
//	char c;
//	int i;
//	double d;
//}s;
//
//int main()
//{
//	s.i = 100;
//	printf("%d\n", s.i);
//	return 0;
//}



//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//
//struct
//{
//	int a;
//	char b;
//	float c;
//} * p;
//
//int main()
//{
//	p = &x;//ok?
//
//	return 0;
//}


//struct Node
//{
//	int data;//4
//	struct Node *next;//�����һ���ڵ�ĵ�ַ4or8
//};

//typedef struct Node
//{
//	int data;//4
//	struct Node* next;
//}Node;


//struct S1
//{
//	char c1;//1
//	char c2;//1
//	int n;//4
//};
//
//struct S2
//{
//	char c1;//1
//	int n;//4
//	char c2;//1
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(struct S1));//8
//	printf("%zd\n", sizeof(struct S2));//12
//	return 0;
//}

//struct S3
//{
//	double d;//4
//	char c;//1
//	int i;//4
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	printf("%zd\n", sizeof(struct S3));//16
//	printf("%zd\n", sizeof(struct S4));//32
// 
//  return 0;
//}

////1 2 4 8
//#pragma pack(2)//�޸Ķ�����
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//
//int main()
//{
//	printf("%zd\n", sizeof(struct S));
//
//	return 0;
//}


struct S
{
	int data[1000];
	int num;
};

void print1(struct S ss)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", ss.data[i]);
	}
	printf("\n");
	printf("num = %d\n", ss.num);
}

void print2(struct S* ps)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
	printf("num = %d\n", ps->num);
}

int main()
{
	struct S s = { {1,2,3,4,5},100 };
	//print1(s);
	print2(&s);
	return 0;
}








