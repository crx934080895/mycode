#include <stdio.h>
#include<math.h>

int main(void)
{
	int count=0;
	for (int i = 100; i <1000; i++)
	{
		int a[3];
		a[0] = i/100;		//取得数字的百位
		a[1] = (i - a[0]*100)/10;	//取得十位的数字
		a[2] = (i - a[0] * 100 - a[1] * 10);		//取得个位的数字
		if((pow(a[0],3)+ pow(a[1], 3)+ pow(a[2], 3))==i)
		{
			count++;
			printf("%d\n", i);
		}
	}
	printf("三位的水仙花数共有%d个", count);
	return 0;
}