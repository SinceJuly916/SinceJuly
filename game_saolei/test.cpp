#include<stdio.h>
#include"saolei.h"

void menu()
{
	printf("##################################################\n");
	printf("##################1、开始游戏#####################\n");
	printf("##################2、退出游戏#####################\n");
	printf("##################################################\n");
}
void game()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//给棋盘随机布置雷
	SetMine(mine,ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	FindMine(mine,show, ROW, COL);
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择！\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 2:printf("退出游戏\n");
			break;
		default:printf("输入错误，请重新选择！\n");
			break;
		}
	}while (input);		
}
int main()
{
	test();
	return 0;
}