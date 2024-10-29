#define _CRT_SECURE_NO_WARNINGS
//C语言代码中一定要有main函数
//main 函数


//printf是一个库函数
//专门用来打印数据

//stdio.h --- (std - Standard - 标准)  (i - input - 输入)  (o - output - 输出)

//vs2022环境如何运行代码 --- ctrl + F5 ---   部分键盘需要按住fn + ctrl +F5

#include <stdio.h>
//main函数是程序的入口，必须有入口代码才能执行
//main函数有且只有一个
//int main()
//{
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//   printf("Hello World\n");
//
//   return 0;          //C语言历史遗留习惯，无BUG返回0，有BUG返回1
//}

//古老的写法，不推荐！
//void main()
//{
//
//}

//char  字符数据类型

//short  短整型
//int  整形
//long  长整型
//long long  更长的整形

//float  单精度浮点数
//double  双精度浮点数

//每种类型的大小范围是多少？
//int main()
//{
//	printf("%zu\n", sizeof(char));
//	printf("%zu\n", sizeof(short));
//	printf("%zu\n", sizeof(int));
//	printf("%zu\n", sizeof(long));
//	printf("%zu\n", sizeof(long long));
//	printf("%zu\n", sizeof(float));
//	printf("%zu\n", sizeof(double));
//	return 0;
//}

//计算机中的单位
//bit 比特位
//byte 字节
//kb
//mb
//gb
//tb
//pb
//8bit = 1byte = 1024kb = 1024mb = 1024gb = 1024tb = 1024pb

//int main()
//{
//	int age = 20;
//	float price = 66.6;
//	return 0;
//}

//C语言有没有字符串类型?
//C语言里面没有专门的字符串类型。在C语言中，字符串是被当做字符数组来处理的

//变量和常量
//int main()
//{
//	short age = 20;
//	int number = 420984199015262564;
//	float high = 180;
//	float weight = 80.5;
//	return 0;
//}
//变量分为局部变量和全局变量两类
//局部变量-{}内部定义的变量
//全局变量-{}外部定义的变量

//int b = 20;
//
//int main()
//{
//	int a = 10;
//	return 0;
//}

//int a = 100;
//
//int main()
//{
//	int a = 10;
//	printf("a=%d\n", a); //当全局变量和局部变量名字相同的情况下，局部优先
//
//	return 0;
//}

//但是建议不要将全局和局部变量的名字写成一样的

//写一个代码，计算2个整数的和
//scanf 是一个输入函数
//printf是一个输出函数
//int main()
//{
//	int num1 = 0;//这里赋个0值，初始化；为什么要初始化？因为一会报警告，二如果变量没有初始化里面默认放的是个随机值，影响后续计算
//	int num2 = 0;
//
//	//输入2个整数
//	scanf("%d %d", &num1, &num2);
//	//求和
//	int sum = num1 + num2;
//	//输出
//	printf("%d\n",sum);
//
//	return 0;
//}
//This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online 
// help for details.

//如果不想使用scanf_s，在源代码第一行加上#define _CRT_SECURE_NO_WARNINGS
//为什么不用scanf_s？因为 scanf_s 这个函数是VS编译器自己提供的函数,非标准C提供的函数，那也就是只有VS编译器认识,其他编译器不认识!
//我的建议是使用scanf
//如果你非要使用scanf_s，请你研究一下在使用!


//变量的作用域
//1.局部变量
//局部变量的作用域是变量所在的局部范围
//2.全局变量
//全局变量的作用域是整个工程。


//变量生命周期
//局部变量的生命周期是: 进入作用域生命周期开始，出作用域生命周期结束
//全局变量的生命周期是: 整个程序的生命周期
//int main()
//{
//	{
//		int a = 100;
//		printf("% d\n", a);
//	}
//
//	printf("% d\n", a);
//	return 0;
//}


//声明来自外部的符号
//extern int a;
//
//
//void test()
//{
//	printf("test-->%d\n", a);
//}
//
//
//int main()
//{
//	test();
//	{
//		printf("a=%d\n",a);
//	}
//	printf("a=%d\n", a);
//
//	return 0;
//}





























