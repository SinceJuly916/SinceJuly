#include<stdio.h>
#include "sanziqi.h"
//�˵��Ĵ�ӡ
void menu()
{
		printf("********************************************\n");
		printf("******1����ʼ��Ϸ   2���˳���Ϸ    *********\n");
		printf("********************************************\n");

}
//�㷨��ʵ��
void game()
{
	char flag=0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	ClearBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ�ǰʤ�����
		flag = is_win(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
		//������
		ComputerMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ�ǰʤ�����
		flag = is_win(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
	}
		if (flag == '*')
		{
			printf("��һ�ʤ��\n");
		}
		else if (flag == '#')
			{
				printf("���Ի�ʤ��\n");
			}
		else 
		{
			printf("ƽ�֣�\n");
		}
	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//���������
	do 
	{
		menu();
		printf("��ѡ��\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 2:printf("�˳���Ϸ\n");
			break;
		default:printf("������ѡ��\n");
			break;
	}
	} while (input);
}
int main()
{
	test();
	return 0;
}