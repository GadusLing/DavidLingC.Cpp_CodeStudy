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

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 100");
	printf("���������������Һ�������ĵ��ԣ�100��֮��ͻ�ػ�\n�������룺������ �����֣���������޴�\n�Ҿʹ󷢴ȱ��Ź��������С���ԣ���\n");
again:
	scanf("%s", input);
	if(strcmp(input, "������") == 0)
	{
		printf("�����룬�ܺã�С���Ź�������\n");
		system("shutdown -a");
	}
	else
	{
		printf("���������������Ҫô�úó���������Ҫô�͵��Źػ��ɣ�����\n");
		goto again;
	}

	return 0;
}