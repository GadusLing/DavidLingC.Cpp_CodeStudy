#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h> 





////���軷����x86��������������Ľ����ɶ��
//#include <stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//�������ָ��-ָ�룬ָ��-ָ��õ���������ָ��֮���Ԫ�ظ���
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };//����Ҫע��һ�㣬�ַ����浽ָ����������������Ԫ�صĵ�ַ��������һ�����ַ���������Ҳ�治�£�ָ��ֻ��4or8���ֽڣ�
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
////����������Ҫ�㣬һ��++�������и����õģ���ı������Ӱ�����cpp��λ��
////����cpp[]�൱���Ѿ������ÿ�����

#include <ctype.h>

//int main()
//{
//	int ret = islower('x');
//	printf("%d\n", ret);
//
//	if (ret)
//	{
//		printf("Сд��ĸ\n");
//	}
//	else
//	{
//		printf("��Сд��ĸ\n");
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
//		printf("�����ַ�\n");
//	}
//	else
//	{
//		printf("�������ַ�\n");
//	}
//	return 0;
//}




////дһ��C���룬���ַ����е�Сд��ĸת��Ϊ��д�������ַ�����
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
//			arr[i] -= 32;//�� ASCII ���У�Сд��ĸ��'a' �� 'z'���� ASCII ��ֵ��Χ�� 97 �� 122������д��ĸ��'A' �� 'Z'���� ASCII ��ֵ��Χ�� 65 �� 90��ÿ��Сд��ĸ�����Ӧ�Ĵ�д��ĸ֮��Ĳ�ֵǡ���� 32
//			             //����ͨ����ȥASCII �ķ�ʽ��ʵ�ֵģ������Ĺ�����һ��ͨ�� toupper(arr[i])������ʵ��ת����ͷ�ļ���#include <ctype.h>
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
//			arr[i] = toupper(arr[i]);//ͨ�� toupper(arr[i])������ʵ��ת����ͷ�ļ���#include <ctype.h>, ����int tolower ( int c ) ��ת��ΪСд
//		}
//	}
//	printf("%s", arr);
//	return 0;
//}




//int main()
//{
//	char arr[] = "abcdef";
//	size_t len = strlen(arr);//ע�����ﷵ�ص����޷�������size_t���ͣ�������״�,������������⣬��Ϊͳ���ַ�������Ҫ���������������������Ȼ��ʹ���޷�������
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


//�������ķ�ʽ
//#include <assert.h> 
//size_t my_strlen (const char* str)//����Ӹ�Const֮�� str����ı�ԭ������������
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

////ָ��ķ�ʽ
//#include <assert.h> 
//size_t my_strlen(const char* str)//����Ӹ�Const֮�� str����ı�ԭ������������
//{
//	char* start = str;
//	assert(str != NULL);
//	while (*str)
//	{
//		str++;
//	}
//	return str - start;
//}


////�ݹ�ķ�ʽ
//#include <assert.h> 
//size_t my_strlen(const char* str)//����Ӹ�Const֮�� str����ı�ԭ������������
//{
//	assert(str != NULL);
//	if (*str)
//	{
//		return 1 + my_strlen(str + 1);//�����(str + 1)������char���͵Ĳ��������1��
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
//	//arr2 = arr1;//ok?   ���� err   �������ǵ�ַ����ַ�ǳ�����ֵ
//	strcpy(arr2, arr1);
//	printf("%s", arr2);
//
//	return 0;
//}

//void my_strcpy(char* dest, char* src)//�Լ�д��
//{
//	int i = 0;
//	for  (i = 0; i < strlen(src); i++)
//	{
//		dest[i] = src[i];
//	}
//	dest[i] = '\0';
//}

//void my_strcpy(char* dest, char* src)//�γ̳���
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = *src;
//}

////strcpy�⺯���ķ���ֵ��char*����
////�����ص���Ŀ��ռ����ʼ��ַ
//char* my_strcpy(char* dest, const char* src)//����һ��
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
//	//arr2 = arr1;//ok?   ���� err   �������ǵ�ַ����ַ�ǳ�����ֵ
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
//	const char* cur = str1;//curָ���¼���ܿ�ʼƥ���λ��
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
//		printf("û�ҵ�\n");
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
//		printf("û�ҵ�\n");
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
//	strcpy(buf, arr1);//���������ã������Σ��
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
//	strcpy(buf, arr1);//���������ã������Σ��
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
	strcpy(buf, arr1);//���������ã������Σ��

	char* p = NULL;
	for (p = strtok(buf, sep); p != NULL; p = strtok(NULL, sep))
	{
		printf("%s\n", p);
	}

	return 0;
}