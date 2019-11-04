#include <stdio.h>
int main(void)
{
	int a;
	printf("请输入行数\n");
	scanf("%d", &a);
	for (int i = 1; i < a+1; i++)		                  //换行
	{
																	  //行数为i
		for (int t = 0; t < a-i; t++)   //打空格
		{
			printf(" "); 
		}

		for (int p = 0; p <2*i-1; p++)               //打*
		{
			printf("*");
		}
		
		printf("\n");

	}

	return 0;
}