#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h> 





////假设环境是x86环境，程序输出的结果是啥？
//#include <stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//考察的是指针-指针，指针-指针得到的是两个指针之间的元素个数
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };//这里要注意一点，字符串存到指针数组里存的是它首元素的地址，而不是一整个字符串（长了也存不下，指针只有4or8个字节）
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//ER
//	printf("%s\n", *cpp[-2] + 3);//ST
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	return 0;
//}
////这题有两个要点，一是++操作是有副作用的，会改变变量，影响后续cpp的位置
////二是cpp[]相当于已经解引用开盒了

#include <ctype.h>

//int main()
//{
//	int ret = islower('x');
//	printf("%d\n", ret);
//
//	if (ret)
//	{
//		printf("小写字母\n");
//	}
//	else
//	{
//		printf("非小写字母\n");
//	}
//	return 0;
//}


//int main()
//{
//	int ret = isdigit('1');
//	printf("%d\n", ret);
//
//	if (ret)
//	{
//		printf("数字字符\n");
//	}
//	else
//	{
//		printf("非数字字符\n");
//	}
//	return 0;
//}




////写一个C代码，将字符串中的小写字母转化为大写，其他字符不变
//#include <string.h>
//
//int main()
//{
//	char arr[] = "Hi, I am a Student.";
//	int sz = strlen(arr);
//	for (int i = 0; i < sz; i++)
//	{
//		int ret = islower(arr[i]);
//		if (ret)
//		{
//			arr[i] -= 32;//在 ASCII 表中，小写字母（'a' 到 'z'）的 ASCII 码值范围是 97 到 122，而大写字母（'A' 到 'Z'）的 ASCII 码值范围是 65 到 90。每个小写字母与其对应的大写字母之间的差值恰好是 32
//			             //这是通过减去ASCII 的方式来实现的，正常的工作中一般通过 toupper(arr[i])函数来实现转换，头文件是#include <ctype.h>
//		}
//	}
//	printf("%s", arr);
//	return 0;
//}




#include <string.h>

//int main()
//{
//	char arr[] = "Hi, I am a Student.";
//	size_t sz = strlen(arr);
//	for (int i = 0; i < sz; i++)
//	{
//		int ret = islower(arr[i]);
//		if (ret)
//		{
//			arr[i] = toupper(arr[i]);//通过 toupper(arr[i])函数来实现转换，头文件是#include <ctype.h>, 还有int tolower ( int c ) 是转换为小写
//		}
//	}
//	printf("%s", arr);
//	return 0;
//}




//int main()
//{
//	char arr[] = "abcdef";
//	size_t len = strlen(arr);//注意这里返回的是无符号整形size_t类型，这很容易错,不过很容易理解，因为统计字符数不需要负数，负数情况不存在自然就使用无符号整形
//	//size_t len = strlen(arr + 1);
//	printf("%zd", len);
//
//	return 0;
//}



//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abc";
//
//	//if ((int)(strlen(arr2) - strlen(arr1)) > 0)
//	if (strlen(arr2) > strlen(arr1))
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<=\n");
//
//	}
//
//	return 0;
//}


//计数器的方式
//#include <assert.h> 
//size_t my_strlen (const char* str)//这里加个Const之后 str不会改变原来的数组内容
//{
//	//size_t i = 0;
//	//while(str[i] != '\0')
//	//{
//	//	i++;
//	//}
//	//return i;
//
//	size_t count = 0;
//	assert(str != NULL);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

////指针的方式
//#include <assert.h> 
//size_t my_strlen(const char* str)//这里加个Const之后 str不会改变原来的数组内容
//{
//	char* start = str;
//	assert(str != NULL);
//	while (*str)
//	{
//		str++;
//	}
//	return str - start;
//}


////递归的方式
//#include <assert.h> 
//size_t my_strlen(const char* str)//这里加个Const之后 str不会改变原来的数组内容
//{
//	assert(str != NULL);
//	if (*str)
//	{
//		return 1 + my_strlen(str + 1);//这里的(str + 1)代表用char类型的步长向后走1步
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//
//
//int main()
//{
//	char arr[] = "abcdef";
//
//	size_t len = my_strlen(arr);
//	printf("%zd\n", len);
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr + 1);
//
//
//	return 0;
//}


//int main()
//{
//	char arr1[] = { 'a','b','c' };
//	char arr2[30] = "xxxxxxxxxxxxxxxx";
//	//arr2 = arr1;//ok?   大咩 err   数组名是地址，地址是常量的值
//	strcpy(arr2, arr1);
//	printf("%s", arr2);
//
//	return 0;
//}

//void my_strcpy(char* dest, char* src)//自己写的
//{
//	int i = 0;
//	for  (i = 0; i < strlen(src); i++)
//	{
//		dest[i] = src[i];
//	}
//	dest[i] = '\0';
//}

//void my_strcpy(char* dest, char* src)//课程初版
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}

////strcpy库函数的返回值是char*类型
////它返回的是目标空间的起始地址
//char* my_strcpy(char* dest, const char* src)//改善一下
//{
//	//assert(dest != NULL);
//	//assert(src != NULL);
//	char* ret = dest;
//	assert(dest && src);
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[30] = "xxxxxxxxxxxxxxxx";
//	//arr2 = arr1;//ok?   大咩 err   数组名是地址，地址是常量的值
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	char*ret = my_strcpy(arr2, arr1);
//	printf("%s\n", ret);
//	size_t len = strlen(my_strcpy(arr2, arr1));
//	printf("%zd\n", len);
//
//	return 0;
//}

//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//    assert(dest && src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[20] = ",world";
//
//	my_strcat(arr1, arr2);
//	//strcat(arr1, ",world");
//	printf("%s\n", arr1);
//
//
//	return 0;
//}



//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while(*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}

//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;		
//	}
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdeq";
//
//	int ret = my_strcmp(arr1, arr2);
//	//printf("%d\n", ret);
//	if (ret > 0)
//	{
//		printf(">\n");
//	}	
//	else if (ret < 0)
//	{
//		printf("<\n");
//	}	
//	else
//	{
//		printf("=\n");
//	}
//
//	return 0;
//}


//int main()
//{
//	char arr1[] = "ab";
//	char arr2[20] = "xxxxxxxxxxxxxxxxx";
//
//	//strcpy(arr2, arr1);
//	strncpy(arr2, arr1, 5);
//
//	printf("%s\n", arr2);
//
//
//	return 0;
//}


//int main()
//{
//	char arr1[20] = "abcdef\0yyyyyyyy";
//	char arr2[20] = "xxxxxx";
//
//	//strcat(arr1, arr2);
//	strncat(arr1, arr2, 5);
//
//	printf("%s\n", arr2);
//
//
//	return 0;
//}



//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[20] = "abcdq";
//
//	//int ret = strcmp(arr1, arr2);
//	int ret = strncmp(arr1, arr2, 5);
//
//	printf("%d\n", ret);
//
//
//	return 0;
//}



//const char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//
//	const char* cur = str1;//cur指针记录可能开始匹配的位置
//	if (*str2 == '\0')
//	{
//		return str1;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = str2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cur;
//		}
//		cur++;
//	}
//	return NULL;
//
//}
//
//
//int main()
//{
//	char arr1[20] = "abcdefabcdef";
//	char arr2[20] = "def";
//
//
//	const char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}





//int main()
//{
//	char arr1[20] = "abcdefabcdef";
//	char arr2[20] = "def";
//
//
//	const char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("没找到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}



//int main()
//{
//	char arr1[] = "zpengwei@yeah.net";
//	char sep[] = "@.";
//	char buf[30] = { 0 };
//	strcpy(buf, arr1);//拷贝后再用，否则很危险
//
//	char* p = strtok(buf, sep);
//	printf("%s\n", p);
//
//	p = strtok(NULL, sep);
//	printf("%s\n", p);
//
//	p = strtok(NULL, sep);
//	printf("%s\n", p);
//
//	p = strtok(NULL, sep);
//	printf("%s\n", p);
//
//	return 0;
//}


//int main()
//{
//	//char arr1[] = "zpengwei@yeah.net";
//	//char arr1[] = "192.168.110.123";
//	char arr1[] = "192@168#110.123";
//	char sep[] = "@#.";
//	char buf[30] = { 0 };
//	strcpy(buf, arr1);//拷贝后再用，否则很危险
//
//	char* p = NULL;
//	for (p = strtok(buf, sep); p != NULL; p = strtok(NULL, sep))
//	{
//		printf("%s\n", p);
//	}
//
//	return 0;
//}




int main()
{
	//char arr1[] = "zpengwei@yeah.net";
	//char arr1[] = "192.168.110.123";
	char arr1[] = "192@168#110.123";
	char sep[] = "@#.";
	char buf[30] = { 0 };
	strcpy(buf, arr1);//拷贝后再用，否则很危险

	char* p = NULL;
	for (p = strtok(buf, sep); p != NULL; p = strtok(NULL, sep))
	{
		printf("%s\n", p);
	}

	return 0;
}