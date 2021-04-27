#include<stdio.h>
//int count_one(int a,int b)
//{
//	//int i = 0;
//	//int count=0;
//	//{
//	//	for (i = 0; i < 32; i++)
//	//	{
//	//		if (((a >> i)&1 )== 1)
//	//			count++;
//	//	}
//	//	return count;
//	//}
//	int count = 0;
//	int c = 0;
//	c = a ^ b;
//
//	while (c)
//	{
//		c = c & (c - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d%d", &a,&b);
//	int count=count_one(a,b);
//	printf("count=%d\n", count);
//	return 0;
//}

void print(int a)
{
	int i = 0;
	for (i = 1; i<= a; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d  ", i, j, i * j);
		}
		printf("\n");

	}
}
int main()
{
	int a = 0;
	scanf_s("%d", &a);
	print(a);
	return 0;
}