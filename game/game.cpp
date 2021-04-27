#include"sanziqi.h"
#include<stdio.h>
#include<windows.h>
void ClearBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		} 
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	//1����򵥵�ֱ�Ӵ�ӡ
	/*printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);*/
	//2��ѭ������ӡ
	/*int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if(i<row-1)
			printf("-----------\n");
	}*/
	//3�����޸����̴�С
	int i=0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//��ӡ������
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");	
		//��ӡ�ָ�����
		if (i < row - 1)
		{
			for (j= 0; j < col; j++)
			{
					printf("---");
					if (j < col - 1)
						printf("|");
			}
			printf("\n");
		}	
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1) 
	{
		printf("��һغϣ������ѡ������λ�ã�\n");
		scanf_s("%d %d", &x, &y);
		if (x <= row && x >= 1 && y <= col&& y >=1)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�������Ѿ���ռ�ã�\n");

		}
		else
			printf("��������������������룡\n");
	}
}
void ComputerMover(char board[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("�����ߣ�����ҵȴ���\n");
	Sleep(1000);
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}	
}
char is_win(char board[ROW][COL], int row, int col)
{
	int i=0;
	//�ж����Ƿ���ͬ
	for (i = 0; i<col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//�ж����Ƿ���ͬ
	for (i = 0; i<row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return  board[i][1];
	}
	//�ж϶Խ����Ƿ���ͬ
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//�ж������Ƿ���
	if (1 == is_full(board, ROW, COL))
		return 'Q';
	else
		return 'C';
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i=0;
	int j=0;
	for (i = 0; i <= row; i++)
	{
		for (j = 0; j <= col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}