#define _CRT_SECURE_NO_WARNINGS
#include"game.h"


void menu()
{
	printf("**********************\n");
	printf("****1.PLAY  0.EXIT****\n");
	printf("**********************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	//初始化棋盘的函数
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("\n你赢了！！！\n");
	}
	else if (ret == '#')
	{
		printf("\nAI获胜！！！\n");
	}
	else
	{
		printf("\n平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点

	int input = 0;
	do 
	{
		menu();//打印菜单
		printf("\n请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n开始%d子棋\n", ROW);
			game();
			break;
		case 0:
			printf("\n退出游戏\n");
			break;
		default:
			printf("\n请输入正确选择 1 or 0\n");
			break;
		}
	} while (input != 0);

	return 0;
}