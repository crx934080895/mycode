#include <stdio.h>
int main(void)
{
	int n,b;
	printf("请输入一个整数\n");
	scanf("%d", &n);
	for (int i = 2; i < n; i++)
	{
		b = n % i;
		if (b == 0)
		{
			printf("它不是一个质数");
			goto quit;			//发现了一个非1和自己的因素则跳出循环并显示结果并结束程序
		}
	}
	printf("它是一个质数");


	
	quit:return 0;
}