#include<stdio.h>
#include "sanziqi.h"
//菜单的打印
void menu()
{
		printf("********************************************\n");
		printf("******1、开始游戏   2、退出游戏    *********\n");
		printf("********************************************\n");

}
//算法的实现
void game()
{
	char flag=0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	ClearBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断当前胜负情况
		flag = is_win(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
		//电脑走
		ComputerMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断当前胜负情况
		flag = is_win(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
	}
		if (flag == '*')
		{
			printf("玩家获胜！\n");
		}
		else if (flag == '#')
			{
				printf("电脑获胜！\n");
			}
		else 
		{
			printf("平局！\n");
		}
	
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//生成随机数
	do 
	{
		menu();
		printf("请选择\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 2:printf("退出游戏\n");
			break;
		default:printf("请重新选择\n");
			break;
	}
	} while (input);
}
int main()
{
	test();
	return 0;
}