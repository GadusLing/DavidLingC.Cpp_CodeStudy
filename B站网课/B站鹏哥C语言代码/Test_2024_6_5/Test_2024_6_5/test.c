#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//again:
//	printf("hehe\n");
//	printf("haha\n");
//	goto again;
//
//	return 0;
//}

//关机程序
//1.电脑运行起来后，1分中内关机
//2.如果输入:我是猪，就取消关机
//

#include <stdio.h>
#include <string.h>

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 100");
//	printf("哈哈哈，笨蛋，我骇入了你的电脑，100秒之后就会关机\n现在输入：我是猪 三个字，承认你的愚蠢\n我就大发慈悲放过你可怜的小电脑！！\n");
//again:
//	scanf("%s", input);
//	if(strcmp(input, "我是猪") == 0)
//	{
//		printf("嚯嚯嚯，很好，小猪，放过你啦。\n");
//		system("shutdown -a");
//	}
//	else
//	{
//		printf("蠢货，你输错啦！要么好好承认你是猪，要么就等着关机吧！！！\n");
//		goto again;
//	}
//
//	return 0;
//}


//while 循环的方式实现
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 100");
//	printf("哈哈哈，笨蛋，我骇入了你的电脑，100秒之后就会关机\n现在输入：我是猪 三个字，承认你的愚蠢\n我就大发慈悲放过你可怜的小电脑！！\n");
//	while (1)
//	{
//		scanf("%s", input);
//		if (strcmp(input, "我是猪") == 0)
//		{
//			printf("嚯嚯嚯，很好，小猪，放过你啦。\n");
//			system("shutdown -a");
//			break;
//		}
//		else
//		{
//			printf("蠢货，你输错啦！要么好好承认你是猪，要么就等着关机吧！！！\n");
//		}
//	}
//	return 0;
//}
//

//函数来了！！！！非常重要！！！

//int main()
//{
//	char str1[] = "To be or not to be";
//	char str2[40];
//	char str3[40];
//
//	strncpy(str2, str1, sizeof(str2));
//	printf("%s\n", str2);
//
//	return 0;
//}

//int main()
//{
//	char str[50] = "almost every programmer should know memset!";
//	memset(str, 'X', 6);//从字符串开头改
//	printf("%s\n",str);
//
//
//	memset(str + 13, 'X', 3);//从字符串中间改
//	printf("%s\n", str);
//
//	return 0;
//}

//用库函数的时候记得要包含头文件！！！


//int Get_Max(int x, int y)
//{
//    if (x > y)
//    {
//        return x; // 直接返回较大的数  
//    }
//    else
//    {
//        return y; // 直接返回较大的数（包括x和y相等的情况）  
//    }
//    // 移除了printf语句，因为函数只负责比较和返回结果  
//}
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d %d", &a, &b); 
//    int c = Get_Max(a, b); // 调用Get_Max函数并将结果存储在变量c中  
//
//    // 在main函数中打印结果  
//    if (c == a) 
//    {
//        printf("%d更大\n", a);
//    }
//    else if (c == b) 
//    {
//        printf("%d更大\n", b);
//    }
//    else 
//    {
//        // 这个else分支其实是不必要的，因为c只可能是a或b  
//        printf("Unexpected value for c\n");
//    }
//
//    return 0;
//}


//int Get_Max(int x, int y)
//{
//    return (x > y ? x : y);
//}
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d %d", &a, &b);
//    int c = Get_Max(a, b);
//
//    if (c == a)
//    {
//        printf("%d更大\n", a);
//    }
//    else
//    {
//        printf("%d更大\n", b); // 这里不需要else if，因为c只可能是a或b  
//    }
//
//    return 0;
//}


//这里是形式参数 简称形参 
void Ex(int *px, int *py)
{
	int z = 0;//函数内初始化，也可以和下一步合并，但这样写比较清晰
	z = *px;//z = a
	*px = *py;//a = b
	*py = z;//b = a

}
 
//当实参传递给形参的时候，形参是实参的一份临时拷贝
//对形参的修改不会影响实参

int main()

{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前\na = %d b = %d\n", a, b);
	Ex(&a, &b);//这里是实际参数 简称实参
	printf("交换后\na = %d b = %d\n", a, b);

	return 0;
}