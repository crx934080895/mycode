#include<stdio.h>
#include<stdlib.h>
int feb(int a)
{
	if (a<=2)
	{
		return 1;
	}
	return feb(a - 1) + feb(a - 2);
}

int  main(void)
{
	int sum=0,a=0;
	scanf_s("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		sum += feb(i);
	}
	printf("%d", sum);
	return 0;
}