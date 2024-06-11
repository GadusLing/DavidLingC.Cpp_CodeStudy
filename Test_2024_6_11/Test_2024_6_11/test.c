#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//放假回来复习上节课的内容————函数与指针

//void Swap(int *px,int *py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//
//Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	int c = Add(a, b);//这里不用传地址，那思考一下，在什么样的情况下要传地址，什么情况下不传地址呢？
//	//当需要使用或改变参数时，就用取地址的方式；当只是借用数值做运算、记录，而并不使用或改变时，就只传数值就行了
//	printf("%d\n", c);
//
//	printf("交换前a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("交换后a=%d,b=%d\n", a, b);
//
//	return 0;
//}


//1.写一个函数可以判断一个数是不是素数。
//素数(质数)————只能被1和自身所整除

#include <math.h>//数学库函数，下面sqrt要用的
int main()
{
	int i = 0;//初始化i来循环要判断的那个数
	int j = 0;//初始化j，用来表示i之前所有的数
	scanf("%d", &i);//输入i
    int flag = 1;//flag为1，非常干净，表示是素数
	for (j = 3; j <= sqrt(i); j+=2)//用i之前除1之外的所有的数(i-1)来循环试除i
	{//这里的j < i -1也可以用厄拉多塞/埃托尼斯/埃式筛法来优化
		if (i % j == 0)//i对j取模，结果若为0，则表示没有余数，在i本身之前有数可以整除i，那i就不是素数
		{
			flag = 0;//标记一下，不干净了，不是素数
			break;//跳出当前的for循环
		}	
	}
	if (flag == 1)
	{
		printf("%d是素数\n", i);
	}
	else
	{
		printf("%d不是素数\n", i);
	}
	return 0;
}

//函数的版本




//2.写一个函数判断一年是不是闰年。



//3.写一个函数，实现一个整形有序数组的二分查找。




//4.写一个函数，每调用一次这个函数，就会将 num 的值增加1。