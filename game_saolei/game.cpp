#include "saolei.h"
void InitBoard(char mine[ROWS][COLS], int rows, int cols, char  set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = set;
		}
	}
}
void DisplayBoard(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= ROW; i++)
	{
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (mine[x][y]== '0')
		{
			mine[x][y]='1';
				count--;
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	int win=0;
	while (win < ROW * COL - EASY_COUNT)
	{
		printf("ÇëÊäÈëÒªÅÅ²éÀ×µÄ×ø±ê£¡\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			//±»Õ¨ËÀ
			if (mine[x][y] == '1')
			{
				printf("ºÜÒÅº¶£¬Äã±»Õ¨ËÀÁË\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			//¼ÌÐøÅÅÀ×
			else
			{
				int count = number_lei(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}

		}
		else {
			printf("ÊäÈë×ø±ê´íÎó£¬ÇëÖØÐÂÊäÈë£¡\n");
		}
		if (win == ROW * COL - EASY_COUNT)
		{
			printf("¹§Ï²ÄãÅÅÀ×³É¹¦!\n");
			DisplayBoard(mine, ROW, COL);
			break;
		}
	}	
}
int number_lei(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] - 8 * '0';
}