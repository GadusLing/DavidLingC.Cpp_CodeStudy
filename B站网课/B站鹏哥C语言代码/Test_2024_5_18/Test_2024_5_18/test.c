#define _CRT_SECURE_NO_WARNINGS

//'a';//97

#include <stdio.h>

//int main()
//{
//	printf("%c\n", 'a');
//	printf("%c\n", 97);
//	
//	return 0;
//
//}

//int main()
//{
//	int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	while (i < sz)
//	{
//		printf("%c", arr[i]);
//		i++;
//	}
//
//	return 0;
//}

int sum(int a)
{
	int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return(a + b + c);
}
int main()
{
	int i;
	int a = 2;
	for (i = 0; i < 5; i++) 
	{
		printf("%d,", sum(a));
	}
}

