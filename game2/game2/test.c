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
//	char mine[ROWS][COLS] = { 0 };//��Ų��úõĵ��׵���Ϣ
//	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
//	//��ʼ����������Ϊָ������
//	//mine ��ʼ��û�в�����ʱȫΪ'0'
//	InitBoard(mine, ROWS, COLS, '0');
//	//show ��ʼ��û���Ų���ʱȫΪ'*'
//	InitBoard(show, ROWS, COLS, '*');
//	
//	//������
//	SetMine(mine, ROW, COL);
//
//	DisplayBoard(mine, ROW, COL);
//	//DisplayBoard(show, ROW, COL);
//	//�Ų���
//	FindMine(mine, show, ROW, COL);
//}
//
//int main()
//{
//	int input = 0;
//	//������������������
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//			case 1:
//				printf("ɨ��\n");
//				game();
//				break;
//			case 0:
//				printf("�˳���Ϸ\n");
//				break;
//			default:
//				printf("������������������\n");
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
	char mine[ROWS][COLS] = { 0 };//��Ų��úõĵ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//�����ҿ����Ų�����׵���Ϣ
	
	InitBoard(mine, ROWS, COLS, '0');//mine ��ʼ��û�в�����ʱȫΪ'0'
	InitBoard(show, ROWS, COLS, '*');//show ��ʼ��û���Ų���ʱȫΪ'*'

	SetMine(mine, ROW, COL);//������

	//DisplayBoard(mine, ROW, COL);//չʾ���׵�����
	DisplayBoard(show, ROW, COL);//չʾ��ҵ���Ϸ����

	FindMine(mine, show, ROW, COL);//�Ų���
}

int main()
{
	srand((unsigned int)time(NULL));//������������������

	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������������������\n");
			break;
		}

	} while (input);

	return 0;
}




