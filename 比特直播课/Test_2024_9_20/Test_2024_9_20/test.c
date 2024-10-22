#define _CRT_SECURE_NO_WARNINGS


//int main()
//{
//	int a = 100;
//	char arr[] = "abcdef";
//
//	return 0;
//}

//#include <stdio.h>
//#include <windows.h>
////VS2022 WIN11环境测试
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//
//	fputs("abcdef", pf);//先将代码放在输出缓冲区
//
//	printf("睡眠10秒 已经写数据了，打开test.txt文件，发现文件没有内容\n");
//	Sleep(10000);
//	printf("刷新缓冲区\n");
//	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到⽂件（磁盘）
//	//注：fflush在⾼版本的VS上不能使⽤了
//	printf("再睡眠10秒 此时再次打开test.txt文件，文件有内容了\n");
//	Sleep(10000);
//	printf("调用fclose()\n");
//	fclose(pf);
//	//注：fclose在关闭⽂件的时候，也会刷新缓冲区
//	pf = NULL;
//
//	return 0;
//}


