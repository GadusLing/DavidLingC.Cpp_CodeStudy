#define _CRT_SECURE_NO_WARNINGS




//算数操作符—————除、取模
#include<stdio.h>
//int main()
//{
//	//int a = 7 / 2; //3,为啥不是3.5？————因为是int，除号的两端都是整数的时候，执行的是整数除法，两端至少要有一个浮点数才执行浮点数的除法
//	//int b = 7 % 2;//取模，得到余数
//	//printf("%d\n", a);
//	//printf("%d\n", b);
//
//	float a = 7 / 2.0; //你看，这里2.0是浮点的写法，就能算出浮点
//	int b = 7 % 2;
//	printf("%f\n", a);//3.50000
//	printf("%d\n", b);
//
//
//
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a = 0;//初始化
//	a = 20;//赋值
//
//	a = a + 3;//a = 23
//
//	a += 3;
//
//	a -= 3;
//
//	return 0;
//}

//C语言中
//0表示假
//非0表示真

//int main()
//{
//	//int flag = 0;
//	//if (!flag)//!就是取反，把假变成真，真变成假
//	//{
//	//	printf("%s\n", "Hello");
//	//}
//
//	//int a = -10;
//	//int b = -a;
//	//printf("%d\n", b);
//
//	//sizeof是操作符，是单目操作符
//
//	//int a = 10;
//	//printf("%d\n",sizeof(a));//4
//	//printf("%d\n",sizeof(int));//4
//	//printf("%d\n",sizeof a);//4 
//	//printf("%d\n",sizeof int);//因为是类型，这里不能不加括号
//
//	//int arr[10] = { 0,9,9,8,5,6,5 };
//	//printf("%d\n", sizeof(arr));//40,计算的是整个数组的大小，单位是字节；方括号里如果不填就是自动计算了数组长度
//	//printf("%d\n", sizeof(arr[0]));//这里计算排序首位的元素字节长度，也是4（整数类型固定占4字节）
//	//printf("%d\n", sizeof(arr) / sizeof(arr[0]));//10 - 数组的元素个数
//
//
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//	//int b = a++;//后置++，先用后加
//	//printf("%d\n", b);//10
//	//printf("%d\n", a);//11
//
//	//int a = 10;
//	//int b = ++a;//前置++，先加后用
//	//printf("%d\n", b);//11
//	//printf("%d\n", a);//11
//
//	//int a = 10;
//	//int b = a--;
//	//printf("%d\n", b);//10
//	//printf("%d\n", a);//9
//
//	//int a = 10;
//	//int b = --a;
//	//printf("%d\n", b);//9
//	//printf("%d\n", a);//9
//
//	int a = (int)3.14;
//	printf("%d\n", a);
//	//int a = int(3.14);//err，不要这样写！！！非常清澈
//	//3.14 字面浮点数，编译器默认理解为double类型
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	if (a == 3)//两个等号！！！一个就成赋值了
//	{
//		printf("%s\n","Hello,World");
//	}
//
//	return 0;
//}

//int main()
//{
//	//// && 逻辑与 - 并且
//	//// || 逻辑或 - 或者
//	//int a = 0;
//	//int b = 0;
//	//if (a && b)//0是假，非0是真
//	//{
//	//	printf("%s\n", "Hello,World");
//	//}
//
//	//int a = 0;
//	//int b = 4;
//	//if (a || b)//0是假，非0是真
//	//{
//	//	printf("%s\n", "Hello,World");
//	//}
//
//	int a = 10;
//	int b = 20;
//
//	int r = a > b ? a : b;
//	printf("%d\n", r);
//
//
//	return 0;
//}

//逗号表达式就是逗号隔开的一串表达式
//逗号表达式的特点是: 从左向右依次计算，整个表达式的结果是最后一个表达式的结果

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 0;
//	int d = (c = a - 2, a = b + c, c - 3);// c = 8,a = 28, 5
//
//	printf("%d\n", d);
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int n = 3;
//	arr[n];//这里的方括号就是下标引用操作符    arr和3就是[]的操作数
//	//a + b
//
//	return 0;
//}

//函数调用操作符()
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int sun = Add(2, 3);//()就是函数调用操作符，Add,2，3都是()的操作数
//
//	return 0;
//}

int main()
{
	auto int a = 10;//自动变量，局部变量都是自动变量，所以auto没啥存在感，等于默认的存在

	return 0;
}










