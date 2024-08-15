#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//int main()
//{
//	int a = 2 + 6 / 3;
//	int b = 2 + 3 + 4;
//
//	return 0;
//}

//int main()
//{
//	char c = -1;//-1本身是整数怎么放到char里面去的呢？
//	//10000000000000000000000000000001
//	//11111111111111111111111111111110
//	//11111111111111111111111111111111  -> -1的补码
//	//11111111          char只有一个字节的容量（8个bit），所以发生了截断（从右向左数），只能存下8个1
//	//这个时候做整型提升，把左边第一位当作符号位
//	//11111111111111111111111111111111    高位全部补1，反之正数或无符号全部补0，具体可看p_72文档
//
//	return 0;
//}

//int main()
//{
//	char a = 5;
//	//00000000000000000000000000000101  整形提升
//	//00000101                          char 8bit
//	
//	char b = 126;
//	//00000000000000000000000001111110  整形提升
//	//01111110                          char 8bit
//
//	char c = a + b;
//	//00000000000000000000000000000101  整形提升
//	//00000000000000000000000001111110  整形提升
//	//00000000000000000000000010000011  整形提升后相加
//	//10000011 - c                      相加得到的char 8bit
//	//11111111111111111111111110000011  再次整形提升的补码
//	//11111111111111111111111110000010  再次整形提升的反码  负数补码-1
//	//10000000000000000000000001111101  再次整形提升的原码  符号位保留其余取反
//
//	printf("%d\n", c);
//
//	return 0;
//}

//int main()
//{
//	char a = 0xb6;//10110110,不是unsigned的话，高位为1，会补成一个不一样的数字
//	unsigned short b = 0xb600;
//	int c = 0xb6000000;
//
//	if (a == 0xb6)
//		printf("a");
//
//	if (b == 0xb600)
//		printf("b");
//
//	if (c == 0xb6000000)
//		printf("c");
//
//	return 0;
//}


//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c)); //1
//	printf("%u\n", sizeof(+c));//4 给了符号，是表达式，这就是整形提升后参与运算的了
//	printf("%u\n", sizeof(-c));//4
//
//	return 0;
//}

//int main()
//{
//	3 + 2 * 4 + 5;
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = (++a) + (++a) + (++a);
//	printf("%d\n", b);
//
//
//	return 0;
//}

#include <stdio.h>  
#include <string.h>  
#include <stdlib.h> // 用于atoi  

int isLilyNumber(int num) 
{
    char str[6]; // 存储数字（包括字符串结束符'\0'）  
    sprintf(str, "%d", num); // 将整数转换为字符串  
    int len = strlen(str);
    int sum = 0;

    // 遍历所有可能的拆分点（从第一个字符之后到倒数第二个字符之前）  
    for (int i = 1; i < len; i++) 
    {
        // 计算左边的数字  
        long left = 0;
        for (int j = 0; j < i; j++)
        {
            left = left * 10 + (str[j] - '0');
        }

        // 计算右边的数字（直接使用atoi是更简单但稍低效的方法）  
        // 这里为了保持与左边数字计算方式一致，我们也用循环来计算  
        long right = 0;
        for (int j = i; j < len; j++)
        {
            right = right * 10 + (str[j] - '0');
        }

        // 累加乘积  
        sum += left * right;
    }

    // 检查乘积之和是否等于原数  
    return sum == num;
}

int main() {
    printf("5位数中的所有Lily Number是：");
    for (int num = 10000; num <= 99999; num++) 
    {
        if (isLilyNumber(num)) 
        {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}

















