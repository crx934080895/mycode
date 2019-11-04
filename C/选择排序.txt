#include<stdio.h>
#include<stdlib.h>
void xchg(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int  main(void)
{
	int a[10] = { 10,55,61,23,-65,33,44,66,78,255 };
	
	int maxmark = 0;
	for (int i = 0; i < 9; i++)
	{
		maxmark = i;
		for (int j = i; j < 10; j++)
		{
			if (a[j]<a[maxmark])
			{
				maxmark=j;
			}
		}
		xchg(a + i, a + maxmark);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}