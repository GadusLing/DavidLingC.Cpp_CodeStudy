#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int i = 1;
//
//	do
//	{
//		if (i == 5)
//			continue;
//
//		printf("%d ", i);
//		i++;
//	}
//	while (i <= 10);
//
//	return 0;
//}


//计算n的阶乘
//1*2*3*...*n


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int a = 0;
//	int m = 1;
//	for (a = 1;a <= n; a++)
//	{
//		m = m * a;
//	}
//	printf("\n%d\n", m);
//	return 0;
//}


//计算 1! + 2!+ 3!+ ..10!

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int a = 0;
//	int m = 1;
//	int b = 0;
//	for (a = 1; a <= n; a++)
//	{
//		m *= a;
//		b += m;
//	}
//	printf("\n%d\n", m);
//	printf("\n%d\n", b);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 1;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("\n%d\n", ret);
//	printf("\n%d\n", sum);
//	return 0;
//}


//在一个有序数组中查找具体的某个数字n。(讲解二分查找)
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("找到了，下标是：%d\n", i);
//				break;
//		}
//	}
//	if (i == sz)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}
//这种方式是可以完成检索的任务，但是需要遍历数组中的所有元素，如果数组元素过多，增添了许多性能消耗，所以最好采用二分法来解决问题


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int left = 0;
//	int right = sz-1;
//	
//
//	while (left <= right)
//	{
//		//int mid = (left + right) / 2;//看下面改进的算法，不会有数据溢出的问题,详情见文档P_34分析图
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}


//编写代码，演示多个字符从两端移动，向中间汇聚
//
//int main()
//{
//	char arr1[] = "Hello World!";
//	char arr2[] = "############";
//
//	char buf[] = "abc";
//	//[a b c \0]
//
//	int left = 0;
//	int right = strlen(buf) - 1;// strlen统计的是\0之前元素的个数，总数有3个，下标是从0开始算的，所以要-1
//
//	return 0;
//}

#include <windows.h>
#include <stdlib.h>

//int main()
//{
//	char arr1[] = "Hello,World!";
//	char arr2[] = "############";
//
//	int size = sizeof(arr1) / sizeof(arr1[0]);
//
//	int left = 0;
//	int right = size - 2;//[a b c \0] \0也算一个元素，除了之后结果是4，C对应的下标是2，所以要-2
//	
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		//清空平面
//		system("cls");//system是一个函数库，可以执行系统命令
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//
//	return 0;
//}


//编写代码实现，模拟用户登录情景，并且只能登录三次。(只允许输入三次密码，如果密码正确则
//提示登录成，如果三次均输入错误，则退出程序。

#include <string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", password);
		if (strcmp(password, "lingdawei") == 0 ) //比较2个字符串是否相等，不能使用 == ，而应该使用一个库函数: strcmp  //strcmp函数的返回值为0表示两个字符串相同
		{
			printf("登陆成功");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if (i == 3)
	{
		printf("三次错误输入，程序暂时锁定，请稍后再试\n");
	}

	return 0;
}
