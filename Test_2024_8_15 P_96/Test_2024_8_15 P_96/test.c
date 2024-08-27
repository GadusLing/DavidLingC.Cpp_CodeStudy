#define _CRT_SECURE_NO_WARNINGS





#include<stdio.h>
//int cnt = 0;
//
//int fib(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
////8
////7 6
////6 5 5 4
////5 4 4 3 4 3 3 2
////4 3 3 2 3 2 2 1 3 2 2 1 2 1 1 0
////3 2 2 1 2 1 1 0 2 1 1 0 1 0 2 1 1 0 1 0 1 0
////2 1 1 0 1 0 1 0 1 0 1 0
////1 0
//
//
//
//void main()
//{
//	fib(8);
//	printf("%d", cnt);
//}



//1011
//1010
//1011
//
//
//

//int GetGCD(int x, int y)
//{
//	return (x % y == 0) ? y : GetGCD(y, x % y);//欧几里得法（辗转相除）算出最大公约数
//}
//
//
//int GetLCM(int x,int y)
//{
//	if (1 <= x && x <= 100000 && 1 <= y && y <= 100000)//确定范围
//	{
//		return x / GetGCD(x, y) * y;//两数之积=最大公约*最小公倍，所以用任意数先/最大公约再*另一数则=最小公倍数
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int a = 0;//7
//	int b = 0;//5
//	scanf("%d %d", &a, &b);
//	printf("%d\n", GetLCM(a, b));
//
//	return 0;
//}




#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char* left, char* right)
{
    assert(left);
    assert(right);

    while (left < right)
    {
        char tmp = *left;
        *left = *right;

        *right = tmp;
        left++;
        right--;
    }
}

int main()
{
    char arr[101] = { 0 };
    gets(arr);//I like beijing.
    int len = strlen(arr);
    reverse(arr, arr + len - 1);

    char* start = arr;

    while (*start)
    {
        char* end = start;
        while (*end != ' ' && *end != '\0')
        {
            end++;
        }
        reverse(start, end - 1);
        if (*end != '\0')
        {
            end++;
        }
        start = end;
    }
    printf("%s\n", arr);

    return 0;
}