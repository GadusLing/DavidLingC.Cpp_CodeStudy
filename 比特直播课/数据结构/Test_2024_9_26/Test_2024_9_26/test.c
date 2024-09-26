#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int t1 = clock();//当前时间
	for (int i = 0; i < 100000; i++)
	{
		for (int j = 0; j < 100000; j++)
		{
			int a = 1;
		}
	}
	int t2 = clock();//当前时间
	printf("%d\n", t2 - t1);

	return 0;
}