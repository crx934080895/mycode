#include<stdio.h>
int result=1;	//全局变量

int f1(int a)
{
	if (a > 0)
	{
		result *=a;
		a --;
		f1(a);
	}
	return result;
}
int main(void)
{
	int a = 0,b;
	scanf("%d", &a);
	b =  f1(a);
	printf("%d", b);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int taolu(int a)
{
	if (a == 0)
		return 1;
	return a * taolu(a - 1);
}


int  main(void)
{
	printf("%d", taolu(3));
	return 0;
}