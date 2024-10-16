#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////结构体类型
//struct Stu
//{
//	char name[20];
//	int age;
//	char id[12];
//	double wight;
//}; s4, s5, s6; // 这里的s4, s5, s6是全局变量
//
//
//int main()
//{
//	struct Stu s1 = { "zhangsan",20,"20240101",75.2 };//这就叫变量的初始化
//	struct Stu s2 = { .age = 18,.wight = 78.3,.name = "lisi",.id = "20230102" };
//	//struct Stu s3;//这里创建的s1 s2 s3 是局部变量
//
//	printf("名字：%s 年龄：%d\n", s1.name, s1.age);//.点操作符  左边是结构体变量名  右边是结构体内的成员名
//	printf("名字：%s 年龄：%d\n", s2.name, s2.age);
//	printf("名字：%s 年龄：%d\n", (&s2)->name, (&s2)->age);//->箭头操作符，当用结构体的地址来寻找成员时， 左边是结构体变量名  右边是结构体内的成员名
//
//	return 0;
//}


//结构体的特殊声明
//匿名结构体

//struct          //这就叫匿名结构体，没有写结构体名字大S 这种结构体只能用一次
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
//	struct Node *next;//存放下一个节点的地址4or8
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
//#pragma pack(2)//修改对齐数
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








