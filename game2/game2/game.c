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
	printf("------ɨ����Ϸ------\n");
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
	int win = 0;//�ҵ����׵ĸ���
	while (win < row * col - MINE_COUNT)
	{
		printf("������Ҫ�Ų����ߣ��Ⱥ����\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y < col)
		{
			if (show[x][y] != '*')
			{
				printf("��λ���ѱ��Ų����\n");
				continue;
			}
			if (mine[x][y] == '1')//�������
			{
				printf("����������������BOOM������\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//���������
			{
				win++;
				int count = get_mine_count(mine, x, y);//ͳ��xy��Χ8�������
				show[x][y] = count + '0';//ת��Ϊ�ַ�����
				DisplayBoard(show, ROW, COL);
			}

		}
		else
		{
			printf("����������������������\n");
		}
	}
	if (win == row * col - MINE_COUNT)
	{
		printf("��ϲ�����׳ɹ�������\n");
		DisplayBoard(mine, ROW, COL);
	}
}

//�����Ĺ�����Ȼʵ��
//����������������
//1.��ǹ���
//2.һƬչ���Ĺ���