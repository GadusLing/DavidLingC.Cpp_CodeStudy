#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------扫雷游戏------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = MINE_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//找到非雷方块的个数
	while (win < row * col - MINE_COUNT)//81个格子减去9雷数
	{
		printf("请输入要排查的坐标，先横后纵\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y < col)//限制输入坐标只能在棋盘范围内
		{
			if (show[x][y] != '*')//原本演出棋盘上都是*，不是*那就肯定查过了
			{
				printf("该位置已被排查过了\n");
				continue;//continue跳过接下来的判断，进入下一次循环
			}
			if (mine[x][y] == '1')//如果是雷
			{
				printf("碰到地雷啦！！！BOOM！！！\n");
				DisplayBoard(mine, ROW, COL);//玩家输了让他看看埋雷的位置
				break;
			}
			else//如果不是雷
			{
				win++;
				int count = get_mine_count(mine, x, y);//统计xy周围8格的雷数
				show[x][y] = count + '0';//count原本是个int，+'0'会转换为字符字数，才能显示在char类型的棋盘上
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("输入坐标有误，请重新输入\n");
		}
	}
	if (win == row * col - MINE_COUNT)
	{
		printf("恭喜你排雷成功！！！\n");
		DisplayBoard(mine, ROW, COL);
	}
}

//基础的功能已然实现
//接下来留几个任务
//1.标记功能
//2.一片展开的功能