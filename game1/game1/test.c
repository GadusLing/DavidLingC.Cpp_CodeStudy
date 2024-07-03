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
	//��ʼ�����̵ĺ���
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		PlayerMove(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("\n��Ӯ�ˣ�����\n");
	}
	else if (ret == '#')
	{
		printf("\nAI��ʤ������\n");
	}
	else
	{
		printf("\nƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));//������������������

	int input = 0;
	do 
	{
		menu();//��ӡ�˵�
		printf("\n��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n��ʼ%d����\n", ROW);
			game();
			break;
		case 0:
			printf("\n�˳���Ϸ\n");
			break;
		default:
			printf("\n��������ȷѡ�� 1 or 0\n");
			break;
		}
	} while (input != 0);

	return 0;
}