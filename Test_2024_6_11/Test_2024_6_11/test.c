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
//int main()
//{
//	int i = 0;//初始化i来循环要判断的那个数
//	int j = 0;//初始化j，用来表示i之前所有的数
//	scanf("%d", &i);//输入i
//    int flag = 1;//flag为1，非常干净，表示是素数
//	for (j = 3; j <= sqrt(i); j+=2)//用i之前除1之外的所有的数(i-1)来循环试除i
//	{//这里的j < i -1也可以用厄拉多塞/埃托尼斯/埃式筛法来优化
//		if (i % j == 0)//i对j取模，结果若为0，则表示没有余数，在i本身之前有数可以整除i，那i就不是素数
//		{
//			flag = 0;//标记一下，不干净了，不是素数
//			break;//跳出当前的for循环
//		}	
//	}
//	if (flag == 1)
//	{
//		printf("%d是素数\n", i);
//	}
//	else
//	{
//		printf("%d不是素数\n", i);
//	}
//	return 0;
//}

//函数的版本

//int is_prime(int n)
//{
//    if (n <= 1)
//    {
//        return 0; // 0和1不是素数  
//    }
//    if (n == 2)
//    {
//        return 1; // 2是素数  
//    }
//    if (n % 2 == 0)
//    {
//        return 0; // 除了2以外的偶数都不是素数  //筛法，把2的倍数右值全筛了
//    }
//    for (int j = 3; j <= sqrt(n); j += 2) 
//    {
//        if (n % j == 0) 
//        {
//            return 0; // 如果n能被j整除，则不是素数  
//        }
//    }
//    return 1; // 如果上述条件都不满足，则n是素数  
//}
//
//int main() 
//{
//    int i = 0;
//    scanf("%d", &i);
//
//    if (is_prime(i)) 
//    {
//        printf("%d是素数\n", i);
//    }
//    else 
//    {
//        printf("%d不是素数\n", i);
//    }
//    return 0;
//}



//2.写一个函数判断一年是不是闰年。
//打印1000-2000年之间的闰年
//闰年————能被4整除，且不能被100整除；能被400整除
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//		}
//	}
//
//	return 0;
//}


//函数版本
//int is_leap_year(int y)
//{
//	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year))
//		{
//			printf("%d ", year);
//		}
//	}
//
//	return 0;
//}



//3.写一个函数，实现一个整形有序数组的二分查找。
//int binary_search(int arr[], int k, int sz)//形式参数和实际参数的名字可以相同，也可以不同
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
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
//			return mid;
//		}
//	}
//
//	return - 1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//    //找到了，返回下标
//	//找不到，返回-1，为啥不返回0？因为下标第一位会是0，有歧义
//
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到");
//	}
//	else
//	{
//		printf("找到了，下标是:%d\n", ret);
//	}
//	
//	return 0;
//}



//4.写一个函数，每调用一次这个函数，就会将 num 的值增加1。

void Add(int* p)
{
	(*p)++;
}

int main()
{
	int num = 0;
	Add(&num);
	printf("%d\n", num);//1
	Add(&num);
	printf("%d\n", num);//2

	return 0;
}