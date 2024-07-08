#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int Fun(int n)
//{
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}
//
//int main()
//{
//	int ret = Fun(2);
//	printf("%d\n", ret);
//
//
//	return 0;
//}


//迭代的方式
//void reverse(char arr[])
//{
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	//int right = sz - 2;//函数内部就不能用sizeof的方法了-数组传的是首元素指针地址
//	int right = strlen(arr) - 1;//用strlen和上面的效果是一样的
//
//	while (left < right)
//	{
//		char temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//
//		left++;
//		right--;
//	}
//}



//递归的方式

int my_strlen(char* p)
{
	int count = 0;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}
//限制一个参数
//void reverse(char* str)
//{
//	char tmp = *str;
//	int len = my_strlen(str);
//	printf("%d\n", len);
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if (my_strlen(str + 1) >= 2)
//	{
//		reverse(str + 1);
//	}
//	*(str + len - 1) = tmp;
//}
// 
//int main()
//{
//	char arr[] = "abcdefg";//[a b c d e f g \0]
//
//	reverse(arr);
//
//	printf("%s\n", arr);
//
//	return 0;
//}



//如果多个参数就这么写
void reverse(char arr[], int left, int right)
{
	
	if (left < right)
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		reverse(arr, left + 1, right - 1);
	}
}
int main()
{
	char arr[] = "abcdef";//[a b c d e f g \0]
	int left = 0;
	int right = my_strlen(arr) - 1;
	reverse(arr, left, right);

	printf("%s\n", arr);

	return 0;
}


//int DigitSum(unsigned int n)
//{
//	if (n > 9)
//	{
//		return DigitSum(n / 10) + n % 10;
//	}
//	else
//		return n;
//}
//
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	printf("%d\n", DigitSum(n));
//	return 0;
//}


//编写一个函数实现n的k次方，使用递归实现


//double Pow(int n, int k) 
//{
//    if (k == 0)
//    {
//        return 1; // 任何数的0次方都是1  
//    }
//    else if (k < 0) 
//    {
//        return 1.0 / Pow(n, -k); // 处理负指数  
//    }
//    else if (k % 2 == 1) 
//    {
//        return n * Pow(n, k - 1); // 奇数次方  
//    }
//    else 
//    {
//        double half = Pow(n, k / 2);
//        return half * half; // 偶数次方  
//    }
//}
//
//double Pow(int n, int k)
//{
//    if (k > 0)
//    {
//        return n * Pow(n, k -1);  
//    }
//	else if (k == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 1.0 / Pow(n, -k);
//	}
//
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	double ret = Pow(n, k);
//	printf("%lf\n", ret);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,(3,4),5 };
//	printf("%d\n", sizeof(arr));
//	return 0;
//}



////sizeof
////sizeof是一个操作符
////是用来计算变量(类型)所占内存空间的大小，不关注内存中存放的具体内容
////单位是字节
//// 
//// 
////strlen
////strlen是一个库函数，是专门求字符串长度的，只能针对字符串
////从参数给定的地址向后一直找\0,统计\0之前出现的字符的个数
//#include <stdio.h>
//int main()
//{
//	char str[] = "hello bit";
//	printf("%d %d\n", sizeof(str), strlen(str));
//	return 0;
//}


//将数组A中的内容和数组B中的内容进行交换。(数组一样大)
//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,0 };
//
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr1[i]);
//
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr2[i]);
//
//	}
//	//这是一个错误的示范
//    //int tmp[]={ 0 };//一是数组初始化只有一个元素的空间，空间不够
//	// 
//    //tmp = arr1;//二是数组都是指针，交换影响不了内部内容
//	//arr1= arr2;
//	//arr2 = tmp;
//
//	return 0;
//}



//创建一个整形数组，完成对数组的操作

//实现函数init()初始化数组为全0
//实现print() 打印数组的每个元素
//实现reverse() 函数完成数组元素的逆置。

//void init(int arr[],int sz)
//{
//	int i = 0;
//	for(i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	printf("\n");
//}
//
//reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	for (left = 0; left < right; left++)
//	{
//		tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(arr, sz);
//	reverse(arr, sz);
//	print(arr, sz);
//	init(arr,sz);
//	print(arr, sz);
//
//	return 0;
//}
