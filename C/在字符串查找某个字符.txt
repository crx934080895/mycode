#include <stdio.h>
int main(void)
{
	char a[100];
	scanf("%[^\n]", a);
	printf("%s", a);
	char b;
	scanf(" %c", &b);		//两个scanf连在一起，第二个scanf前要打空格，
	int co=0;					//以排除上一个scanf结束的回车符，不然第二个scanf接受的就是回车
	for (int i = 0; i < 100; i++)
	{
		if (a[i] == b)
			co++;
	}
	printf("%d", co);
	return 0;
}