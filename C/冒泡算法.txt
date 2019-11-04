#include<stdio.h>
void sort(int *a, int size)
{
	int i, j;
	int temp = a;
	for ( i = 0; i < size-1; i++)	//外圈循环决定比较的尾部，次数为数组长度-1
	{
		for (j = 0;  j<size-i-1 ; j++)		//内圈循环决定一个外循环下比较的次数，次数为数组长度-1-i
		{
			if (a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main(void)
{
	int a[6] = { 5,6,11,25,1,9 };
	for (int i = 0; i < 6; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
	sort(a, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}	