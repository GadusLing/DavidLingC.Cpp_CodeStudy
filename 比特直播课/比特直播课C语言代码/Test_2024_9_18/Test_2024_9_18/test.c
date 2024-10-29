#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>


//int main()
//{
//	int a = 10000;
//	//00000000 00000000 0010 0111 0001 0000
//	//00       00       2    7    1    0
//	FILE * pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//⼆进制的形式写到⽂件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("E:\\GithubDownLoad\\DavidLingC_CodeStudy\\比特直播课\\Test_2024_9_18\\Test_2024_9_18\\data.txt", "w");
//	//相对路径
//	//绝对路径
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
//	////写文件
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



//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int ch = 0;
//	while ((ch = fgetc(stdin)) != EOF)
//	{
//		printf("%c", ch);
//	}
//
//	//int ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//
//
//
//	fclose(pf);
//	pf == NULL;
//
//	return 0;
//}



//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputs("hello world\n", pf);
//	fputs("hello everyone\n", pf);
//
//
//
//	fclose(pf);
//	pf == NULL;
//
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char arr[100];
//	while (fgets(arr, 100, pf) != NULL)
//	{
//		printf("%s", arr);
//	}
//
//	//fgets(arr, 100, pf);
//	//printf("%s", arr);
//
//	//fgets(arr, 100, pf);
//	//printf("%s", arr);
//
//	fclose(pf);
//	pf == NULL;
//
//	return 0;
//}



//int main()
//{
//	int num = 100;
//	float score = 75.5;
//	char name[10] = "如花";
//
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fprintf(pf, "%d %f %s\n", num, score, name);
//
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	int num = 0;
//	float score = 0;
//	char name[10] = { 0 };
//
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fscanf(pf, "%d %f %s", &num, &score, &name);
//
//	printf("%d %f %s\n", num, score, name);
//
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	int num = 0;
//	float score = 0;
//	char name[10] = { 0 };
//
//
//	fscanf(stdin, "%d %f %s", &num, &score, &name);
//
//	fprintf(stdout,"%d %f %s\n", num, score, name);
//
//	return 0;
//}



//int main()
//{
//	int num = 100;
//	float score = 3.14f;
//	char name[10] = "小强";
//
//	char str[100] = { 0 };
//	sprintf(str, "%d %f %s\n", num, score, name);
//	
//	printf("字符串的形式打印：%s\n", str);
//
//	int num1 = 0;
//	float score1 = 0;
//	char name1[10] = { 0 };
//
//	sscanf(str, "%d %f %s", &num1, &score1, &name1);
//
//	printf("格式化的形式打印：%d %f %s\n", num1, score1, name1);
//
//	//fprintf(stdout, "%d %f %s\n", num, score, name);
//
//	return 0;
//}



//int main()
//{
//	int num = 0;
//	float score = 0;
//	char name[10] = { 0 };
//
//	FILE* pf = fopen("data.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int arr[] = { 1,2,3,4,5 };
//
//	//二进制形式写入文件
//	fwrite(arr, sizeof(arr[0]), 5, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

////fread是可以读取二进制文件的
//int main()
//{
//	int num = 0;
//	float score = 0;
//	char name[10] = { 0 };
//
//	FILE* pf = fopen("data.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int arr[5] = { 0 };
//
//	//二进制形式写入文件
//	//fread(arr, sizeof(arr[0]), 5, pf);
//
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	fread(&arr[i], sizeof(arr[0]), 1, pf);
//	//}
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	fread(arr + i, sizeof(arr[0]), 1, pf);
//	//}
//
//	int i = 0;
//	while (fread(arr + i, sizeof(arr[0]), 1, pf))
//	{
//		printf("%d ", arr[i]);
//	}
//
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	printf("%d ", arr[i]);
//	//}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//int main()
//{
//
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int ch = fgetc(pf);//a
//	printf("%c ", ch);
//
//	////定位文件中的光标位置
//	//fseek(pf, 2, SEEK_CUR);
//
//	//fseek(pf, 3, SEEK_SET);
//
//	fseek(pf, -3, SEEK_END);
//
//	ch = fgetc(pf);//希望读取到d
//	printf("%c ", ch);
//
//	long int r = ftell(pf);
//	printf("%ld\n", r);
//
//
//	rewind(pf);
//	ch = fgetc(pf);//又读到a了
//	printf("%c ", ch);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



















