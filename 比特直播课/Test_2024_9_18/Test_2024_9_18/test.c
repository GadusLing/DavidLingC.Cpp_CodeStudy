#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>


int main()
{
	int a = 10000;
	//00000000 00000000 0010 0111 0001 0000
	//00       00       2    7    1    0
	FILE * pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);//⼆进制的形式写到⽂件中
	fclose(pf);
	pf = NULL;
	return 0;
}


//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	//相对路径
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	//打开成功
//	//写文件
//
//
//	//关闭文件
//	fclose(pf);
//	//pf 置为空指针，防止其变成野指针
//	pf == NULL;
//
//
//	return 0;
//
//}

//int main()
//{
//	FILE * pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	//fputc('x', pf);
//	//fputc('y', pf);
//	//fputc('z', pf);
//	char c = 0;
//	for (c = 'a'; c <= 'z'; c++)
//	{
//		fputc(c, stdout);
//	}
//
//
//
//	fclose(pf);
//	pf == NULL;
//
//	return 0;
//}
