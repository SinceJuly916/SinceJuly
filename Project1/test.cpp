#include<stdio.h>
void paixu_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{

		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int i;
	int arr[] = {1,5,2,6,7,5,9,2,3};
	int sz = sizeof(arr) / sizeof (arr[0]);
	paixu_arr(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}