#include <stdio.h>
void swap(int *a, int *b);
void fanzhuanshuzu(int a[], int n)
{
	if(n%2==0)    //数组长度为偶数
		for (int i=0; i < n/2; i++)
		swap(&(a[i]) , &(a[n - i]));
	else				//数组长度为奇数
	{
		for (int i = 0; i < (n+1)/2; i++)
		{
			swap(&(a[i]), &(a[n - i-1]));
		}
	}
}

void swap(int *a, int *b) 
{
	int temp;
	temp = *a;
	*a = *b;
	*b=temp;
}


int main(void)
{
	int a[5] = { 1,2,3,4,5 };
	fanzhuanshuzu(a, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}