#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

//int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str);
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "Hello World";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}


//��̳����Ĵ���
//1.�����ʹ����﷨����
//2.�����ʹ��󣨳����������ڼ䣩 - �����϶�����Ϊ�Ҳ������ţ�1.������ 2.д���ˣ�
//3.����ʱ���������ܣ���Ҫ�����������
//
//
//
//int main()
//{
//	int a
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//
//int main()
//{
//	int a = 0;
//	int b = 10;
//	int c = Add(a, b);
//
//	printf("%d\n", c);
//
//	return 0;
//}

//
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	short* p = (short*)arr;
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		*(p + i) = 0;
//	}
//
//	for (i = 0; i < 5; i++) 
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulptr;
//	pulptr = pulArray;
//	*(pulptr + 3) += 3;
//	printf("%d, %d\n", *pulptr, *(pulptr + 3));
//
//	return 0;
//}










#include <stdio.h>  

int gcd(int a, int b) //ʹ��ŷ������㷨�����Լ���ĺ���  
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    int num1, num2;

    printf("���������������ÿո�ָ���: ");
    scanf("%d %d", &num1, &num2);

    //����gcd��������ӡ���  
    printf("%d �� %d �����Լ����: %d\n", num1, num2, gcd(num1, num2));

    return 0;
}





