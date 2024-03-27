#define _CRT_SECURE_NO_WARNINGS




//C语言中的常量分为以下以下几种：

//1.字面常量
//int main()
//{
//	30;
//	3.14;
//	'w';//字符
//	"abc";//字符串
//
//
//	return 0;
//}

//2.const修饰的常变量
//#include <stdio.h>
//int main()
//{
//	//30;
//	//3.14;
//	//'w';//字符
//	//"abc";//字符串
//	//const int a = 10; //在C语言中，const修饰的a，其本质是变量，但是不能被修改，有常量的属性.
//	//a = 20;
//	//printf("%d\n", a);
//
//	const int n = 10;
//	int arr[n] = { 0 };//这里的数组需要一个常量值，但是用const修饰的n依然无法使之运行，顾此处的n本质依然是变量，只不过具有了常量不可改变的属性
//
//
//	return 0;
//}

//3.#define定义的标识符常量
//#define MAX 100
//#define STR "abcdef"
//int main()
//{
//	printf("%d\n", MAX);
//	int a = MAX;
//	printf("%d\n", a);
//	printf("%s\n", STR);
//	//MAX = 200;
//
//
//	return 0;
//}


//4.枚举常量
//enum Color
//{
//	RED,
//	GREEN,
//	BLUE
//};//这三个就是我们列举出来的枚举常量，一个一个枚举出来的
//
////性别
//enum Sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//int main()
//{
//	//三原色
//	//RED GREEN BLUE
//	int num = 10;
//	enum Color c = RED;
//	//RED = 20;//err
//	//MALE = 10//err
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	//Char 字符类型
//	//'a'
//	//char ch = 'w';
//	//C语言中有没有字符串类型呢? - 没有,不是String，而是用双引号引起来就是一串字符，叫做字符串字面值or字符串
//    //"abcdef";
//	char arr1[] = "abcdef";//7位；字符串的结束标志是一个 \0 的转义字符，在计算字符串长度的时候 \0 是结束标志，不算作字符串内容
//	char arr2[] = {'a','b','c','d','e','f','\0'};//6位
//	printf(" %s\n", arr1);
//	printf(" %s\n", arr2);
//	//arr2如果找不到\0就会一直在别人的内存空间里找这个终止符，所以打出了很多“烫烫烫”
//
//	int len = strlen("abc");//求字符串长度的一个函数 string length
//	printf("%d\n",len);//3,不包含\0
//
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//
//
//	return 0;
//}

//int main()
//{
//	printf("abc\0def");
//
//	return 0;
//}

//转义字符
// \? 在书写连续多个问号时使用，防止他们被解析成三字母词
// \' 用于表示字符常量
// \" 用于表示一个字符串内部的双引号
// \\ 用于表示一个反斜杠，防止它被解释为一个转义序列符
// \a 警告字符，蜂鸣
// \b 退格符
// \f 进纸符
// \n 换行
// \r 回车
// \t 水平制表符
// \v 垂直制表符
// \ddd 表示1 - 3个八进制的数字。如: \130 X
// \xdd 表示2个十六进制数字。如: \x30 0


//三字母词
//??) --> ]
//??( --> [

//int main()
//{
//	printf("%s\n", "(are you ok\?\?)");
//
//	return 0;
//}


//%d - 打印整型
//%c - 打印字符
//%s - 打印字符串
//%f - 打印float类型的数据
//%lf - 打印double类型的数据
//%zu - 打印sizeof的返回值


// \' 用于表示字符常量
// \" 用于表示一个字符串内部的双引号
// \\ 用于表示一个反斜杠，防止它被解释为一个转义序列符
// \a 警告字符，蜂鸣
// \n 换行
// \ddd 表示1 - 3个八进制的数字。如: \130 X
// \xdd 表示2个十六进制数字。如: \x30 0
//int main()
//{
//	//printf("%c\n", '\'');
//	//printf("abcdef\n");
//	//printf("%s\n", "abcdef");
//	//printf("\"");
//	//printf("abcd\\\\0ef");
//	//printf("c:\\test\\test.c");
//	//printf("\a");
//	//printf("abc\ndef");
//	//printf("%c\n", '\130');//打印的是ASCII编码中对应的字符码
//	//printf("%c\n", '\x60');//`
//
//	//printf("%d\n", strlen("qwer t"));
//	//printf("%d\n", strlen("c:\test\628\test.c"));
//
//
//	return 0;
//}



//注释
/* C语言的注释风格 */  //c的注释风格不支持嵌套注释,遇*/即停了
// C++的注释风格
// 
//int main()
//{
//	//int a = 10;
//
//	//创建指针变量p，并赋值为NULL
//	int* p = NULL;
//	
//	return 0;
//}

//1.注释可以梳理思路
//2.对复杂的代码进行解释
//3.写代码的时候写注释，是帮助自己，也帮助他人的

//选择语句

//if语句实现选择/分支
//int main()
//{
//	int input = 1;
//	printf("%s\n", "开始学习编程");
//	printf("%s\n", "要好好学习吗？(1要/0不要)");
//	scanf("%d", &input);
//	if (input == 1)
//	{
//		printf("%s\n", "你能做出很棒的游戏");
//	}
//	else
//	{
//		printf("%s\n", "奔波于金钱漩涡之中");
//	}
//
//	return 0;
//}

//20000行有效代码的积累////////////////////////////////////////////////////////////////////////////////////////////////////


//int main()
//{
//	int line = 0;
//	printf("%s\n","学习编程");
//
//	while (line < 20000)
//	{
//		line++;
//		printf("写代码:%d行\n", line);
//	}
//	if (line >= 20000)
//	{
//		printf("恭喜你入门了\n");
//	}
//	else
//	{
//		printf("继续加油\n");
//	}
//
//	return 0;
//}


//求两个任意整数的和

//it is function(函数) that fucking
//Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//初始化
//	int n1 = 0;
//	int n2 = 0;
//	//输入
//	scanf("%d %d",&n1,&n2);
//	//求和
//	int sum = Add(n1, n2);
//
//	int t1 = 100;
//	int t2 = 600;
//	int ret = Add(t1, t2);//函数的调用
//	printf("%d\n", ret);
//
//	//输出打印
//	printf("%d\n", sum);
//
//	return 0;
//}


//数组
//int main()
//{
//	//int a = 10;
//	//int b = 10;
//	//int c = 10;
//	//0~9
//	//int d = 0;
//	//int e = 1;
//	//...
//	int arr[] = { 10,11,12,13,14,15,16,17,18,19};
//	char ch[5];
//	double d[30];
//
//	//数组在实际的内存空间里是有编号的，我们称之为数组的“下标”，下标从"0"开始计算
//	//比如arr[8],就相当于访问了arr这个数组中的第8个元素
//	//printf("%d\n", arr[8]);//18
//	int i = 0;
//	while (i < 10)
//	{
//		printf("%d\n", arr[i]);
//		i = i + 1;
//	}
//
//	return 0;
//}


//Big(int x,int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;	
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;//初始化a b
//	scanf("%d%d", &a, &b);//输入a b
//	int BigNum = Big(a, b);//初始化BigNum值=Big函数运算结果
//	printf("BigNum = %d", BigNum);//打印较大数
//	
//	return 0;
//}


#include <stdio.h>
int main()
{
	//输入
	int x = 0;
	int y = 0;
	scanf("%d", &x);
	//输出
	if(x < 0)
		y = 1;
	else if (x == 0)
		y = 0;
	else
		y = -1;

    printf("%d\n", y);

	return 0;
}


















 













