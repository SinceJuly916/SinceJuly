#include<stdio.h>
#include"saolei.h"

void menu()
{
	printf("##################################################\n");
	printf("##################1����ʼ��Ϸ#####################\n");
	printf("##################2���˳���Ϸ#####################\n");
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
	//���������������
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
		printf("��ѡ��\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 2:printf("�˳���Ϸ\n");
			break;
		default:printf("�������������ѡ��\n");
			break;
		}
	}while (input);		
}
int main()
{
	test();
	return 0;
}