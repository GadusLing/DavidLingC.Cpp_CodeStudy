#define _CRT_SECURE_NO_WARNINGS

#include "game.h";


//void menu()
//{
//	printf("***************************\n");
//	printf("********  1. PLAY  ********\n");
//	printf("********  0. EXIT  ********\n");
//	printf("***************************\n");
//}
//
//void game()
//{
//	char mine[ROWS][COLS] = { 0 };//存放布置好的地雷的信息
//	char show[ROWS][COLS] = { 0 };//存放排查出地雷的信息
//	//初始化数组内容为指定内容
//	//mine 初始化没有布置雷时全为'0'
//	InitBoard(mine, ROWS, COLS, '0');
//	//show 初始化没有排查雷时全为'*'
//	InitBoard(show, ROWS, COLS, '*');
//	
//	//设置雷
//	SetMine(mine, ROW, COL);
//
//	DisplayBoard(mine, ROW, COL);
//	//DisplayBoard(show, ROW, COL);
//	//排查雷
//	FindMine(mine, show, ROW, COL);
//}
//
//int main()
//{
//	int input = 0;
//	//设置随机数的生成起点
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//				printf("扫雷\n");
//				game();
//				break;
//			case 0:
//				printf("退出游戏\n");
//				break;
//			default:
//				printf("输入有误，请重新输入\n");
//				break;
//		}
//	} while (input);
//
//	return 0;
//}









void menu()
{
	printf("***************************\n");
	printf("********  1. PLAY  ********\n");
	printf("********  0. EXIT  ********\n");
	printf("***************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的地雷的信息
	char show[ROWS][COLS] = { 0 };//存放玩家看到排查出地雷的信息
	
	InitBoard(mine, ROWS, COLS, '0');//mine 初始化没有布置雷时全为'0'
	InitBoard(show, ROWS, COLS, '*');//show 初始化没有排查雷时全为'*'

	SetMine(mine, ROW, COL);//设置雷

	//DisplayBoard(mine, ROW, COL);//展示布雷的棋盘
	DisplayBoard(show, ROW, COL);//展示玩家的游戏棋盘

	FindMine(mine, show, ROW, COL);//排查雷
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点

	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}

	} while (input);

	return 0;
}




