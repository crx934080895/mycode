#include <stdio.h>
int main(void)
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", (a+i));
	}												//给数组赋值
	
	int max=a[0];
	int min = a[0];
	for (int i = 0; i < 10; i++)
	{
		if (max < a[i])
			max = a[i];
		if (min > a[i])
			min = a[i];
	}											//循环比较找出最大数和最小数

	printf("max=%d,min=%d", max,min);
	return 0;
}