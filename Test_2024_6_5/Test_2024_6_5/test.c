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

//关机程序
//1.电脑运行起来后，1分中内关机
//2.如果输入:我是猪，就取消关机
//

#include <stdio.h>
#include <string.h>

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 100");
	printf("哈哈哈，笨蛋，我骇入了你的电脑，100秒之后就会关机\n现在输入：我是猪 三个字，承认你的愚蠢\n我就大发慈悲放过你可怜的小电脑！！\n");
again:
	scanf("%s", input);
	if(strcmp(input, "我是猪") == 0)
	{
		printf("嚯嚯嚯，很好，小猪，放过你啦。\n");
		system("shutdown -a");
	}
	else
	{
		printf("蠢货，你输错啦！要么好好承认你是猪，要么就等着关机吧！！！\n");
		goto again;
	}

	return 0;
}