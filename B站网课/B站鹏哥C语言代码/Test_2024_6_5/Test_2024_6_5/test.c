#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//again:
//	printf("hehe\n");
//	printf("haha\n");
//	goto again;
//
//	return 0;
//}

//�ػ�����
//1.��������������1�����ڹػ�
//2.�������:��������ȡ���ػ�
//

#include <stdio.h>
#include <string.h>

//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 100");
//	printf("���������������Һ�������ĵ��ԣ�100��֮��ͻ�ػ�\n�������룺������ �����֣���������޴�\n�Ҿʹ󷢴ȱ��Ź��������С���ԣ���\n");
//again:
//	scanf("%s", input);
//	if(strcmp(input, "������") == 0)
//	{
//		printf("�����룬�ܺã�С���Ź�������\n");
//		system("shutdown -a");
//	}
//	else
//	{
//		printf("���������������Ҫô�úó���������Ҫô�͵��Źػ��ɣ�����\n");
//		goto again;
//	}
//
//	return 0;
//}


//while ѭ���ķ�ʽʵ��
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 100");
//	printf("���������������Һ�������ĵ��ԣ�100��֮��ͻ�ػ�\n�������룺������ �����֣���������޴�\n�Ҿʹ󷢴ȱ��Ź��������С���ԣ���\n");
//	while (1)
//	{
//		scanf("%s", input);
//		if (strcmp(input, "������") == 0)
//		{
//			printf("�����룬�ܺã�С���Ź�������\n");
//			system("shutdown -a");
//			break;
//		}
//		else
//		{
//			printf("���������������Ҫô�úó���������Ҫô�͵��Źػ��ɣ�����\n");
//		}
//	}
//	return 0;
//}
//

//�������ˣ��������ǳ���Ҫ������

//int main()
//{
//	char str1[] = "To be or not to be";
//	char str2[40];
//	char str3[40];
//
//	strncpy(str2, str1, sizeof(str2));
//	printf("%s\n", str2);
//
//	return 0;
//}

//int main()
//{
//	char str[50] = "almost every programmer should know memset!";
//	memset(str, 'X', 6);//���ַ�����ͷ��
//	printf("%s\n",str);
//
//
//	memset(str + 13, 'X', 3);//���ַ����м��
//	printf("%s\n", str);
//
//	return 0;
//}

//�ÿ⺯����ʱ��ǵ�Ҫ����ͷ�ļ�������


//int Get_Max(int x, int y)
//{
//    if (x > y)
//    {
//        return x; // ֱ�ӷ��ؽϴ����  
//    }
//    else
//    {
//        return y; // ֱ�ӷ��ؽϴ����������x��y��ȵ������  
//    }
//    // �Ƴ���printf��䣬��Ϊ����ֻ����ȽϺͷ��ؽ��  
//}
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d %d", &a, &b); 
//    int c = Get_Max(a, b); // ����Get_Max������������洢�ڱ���c��  
//
//    // ��main�����д�ӡ���  
//    if (c == a) 
//    {
//        printf("%d����\n", a);
//    }
//    else if (c == b) 
//    {
//        printf("%d����\n", b);
//    }
//    else 
//    {
//        // ���else��֧��ʵ�ǲ���Ҫ�ģ���Ϊcֻ������a��b  
//        printf("Unexpected value for c\n");
//    }
//
//    return 0;
//}


//int Get_Max(int x, int y)
//{
//    return (x > y ? x : y);
//}
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d %d", &a, &b);
//    int c = Get_Max(a, b);
//
//    if (c == a)
//    {
//        printf("%d����\n", a);
//    }
//    else
//    {
//        printf("%d����\n", b); // ���ﲻ��Ҫelse if����Ϊcֻ������a��b  
//    }
//
//    return 0;
//}


//��������ʽ���� ����β� 
void Ex(int *px, int *py)
{
	int z = 0;//�����ڳ�ʼ����Ҳ���Ժ���һ���ϲ���������д�Ƚ�����
	z = *px;//z = a
	*px = *py;//a = b
	*py = z;//b = a

}
 
//��ʵ�δ��ݸ��βε�ʱ���β���ʵ�ε�һ����ʱ����
//���βε��޸Ĳ���Ӱ��ʵ��

int main()

{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("����ǰ\na = %d b = %d\n", a, b);
	Ex(&a, &b);//������ʵ�ʲ��� ���ʵ��
	printf("������\na = %d b = %d\n", a, b);

	return 0;
}