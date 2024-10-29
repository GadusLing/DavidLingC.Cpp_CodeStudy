#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//int main()
//{
//	int a = 10;
//	if (a == 3)
//		printf("%s\n", "hehe");
//
//	int age = 20;
//	if (age > 18)
//	{
//		printf("未成年\n");
//		printf("不能饮酒\n");
//	}
//	else
//	{
//        printf("成年\n");
//	}
//
//	return 0;
//}
	//int age = 10;
	//scanf("%d", &age);
	//if (age < 18)
	//{
	//	printf("青少年\n");
	//}
	//else if (age >= 18 && age < 28)
	//{
	//	printf("青年\n");
	//}
	//else if (age >= 28 && age < 40)
	//{
	//	printf("中年\n");
	//}
	//else if (age >= 40 && age < 60)
	//{
	//	printf("壮年\n");
	//}
	//else if (age >= 60 && age <= 100)
	//{
	//	printf("老年\n");
	//}
	//else
	//{
	//	printf("老寿星\n");
	//}

	//return 0;

	//int main();
	//{
	//	int age = 20;
	//	if (age < 18)
	//		printf("未成年\n");
	//	else
	//	{
	//		printf("成年\n");
	//		printf("打游戏\n");
	//	}

	//		return 0;
	//}

	//int main();
	//{
	//	int a = 0;
	//	int b = 2;
	//	if (a == 1)
	//	{
	//		if (b == 2)
	//			printf("hehe\n");
	//		else
	//			printf("haha\n");
	//	}
	//	return 0;
	//}

	//int main();
	//{
	//	int a = 0;
	//	int b = 2;
	//	if (a == 1)
	//	{
	//		if (b == 2)
	//			printf("hehe\n");
	//	}
	//	else
	//		printf("haha\n");
	//	
	//	return 0;
	//}

	//1.同时还要注意：变量的命名最好是有意义的，规范的
	//int main;
	//{
	//	//char firstname[20] = { 0 };
	//	//char first_name[20] = { 0 };//下划线区分
	//	//char FirstName[20] = { 0 };//驼峰

	//	int a = 10;
	//	int a=10;//密集，不舒服

	//  return 0;
	//}

//int test()
//{
//	int a = 4;
//	if (a == 3)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	int r = test();
//	printf("%d\n", r);
//
//	return 0;
//}

//int main()
//{
//	int num = 3;
//		if (5 == num)//if (num == 5)   //在判断数值而非赋值的情况下，常量放左值的写法情况可以避免遗失等号的错误
//			printf("hehe\n");
//
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	//判断
//	if (num % 2 == 1)
//		printf("奇数\n");
//	else
//		printf("非奇数\n");
//
//	return 0;
//}

//int main()
//{
//	int num = 1;
//	while (num >= 1 & num <= 100)
//	{
//		if (num % 2 == 1)
//			printf("%d ", num);
//		num++;
//	}
//	return 0;
//}

//int main()
//{
//	int num = 1;
//	while (num >= 1 & num <= 100)
//	{
//		if (num % 2 == 1)
//			printf("%d ", num);
//		num+=2;//+2一样也是奇数，从数理角度避免了枚举过程，减少了损耗
//	}
//	return 0;
//}

//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	//if (1 == day)
//	//{
//	//	printf("星期一\n");
//	//}
//	//else if (2 == day)
//	//{
// //       printf("星期二\n");
//	//}   
//	//else if (3 == day) 
//	//{
//	//	printf("星期三\n");
//	//}
//	//else if (4 == day)
//	//{
//	//	printf("星期四\n");
//	//}
//	//else if (5 == day)
//	//{
//	//	printf("星期五\n");
//	//}
//	//else if (6 == day)
//	//{
//	//	printf("星期六\n");
//	//}
//	//else if (7 == day)
//	//{
//	//	printf("星期天\n");
//	//}
//
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	default:
//		printf("输入有误，请重新输入\n");
//		break;
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//		case 1:m++;
//		case 2:n++;
//		case 3:
//			switch (n)
//			{//switch 允许嵌套使用
//			case 1:n++;
//			case 2:m++; n++;
//				break;
//			}
//		case 4:
//			m++;
//			break;
//		default:
//			break;
//	}
//	printf("m = %d,n = %d", m, n);
//	return 0;
//}

//int main()
//{
//	while (1)
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}

//while循环中的
//break是用于永久的终止循环
//continue 跳过本次循环后面的代码，直接去判断部分，进行下一次循环的判断
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i++;
//		if (5 == i)
//			continue;
//
//		printf("%d\n", i);
//	}
//
//	return 0;
//}
//int main()
//{
//	//int ch = 0;
//	//while (getchar())
//	//EOF;//end of file
//	//int ch = getchar();
//	//printf("%c\n", ch);
//	//putchar(ch);
//
//	//int ch = 0;
//	//while ((ch = getchar()) != EOF)
//	//{
//	//	putchar(ch);
//
//	//}
//
//
//	//举一个例子
//	//假设密码是一个字符串
//	char password[20] = { 0 };
//	printf("请输入密码:>");//123456
//	scanf("%s", password);
//	
//	//getchar();//读取了\n
//	int ch = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//
//
//	printf("请确认密码(Y/N):>");
//	int ret = getchar();
//	if ('Y' == ret)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	char ch = '\0';
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//		putchar(ch);
//	}
//	//只打印数字字符
//	return 0;
//}

