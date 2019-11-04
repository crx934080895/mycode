#include <stdio.h>
#include <stdlib.h>

//不使用指针与子函数
/*
int main(void)
{
    int a=1;
    int b=2;
    int temp;
    printf("a=%d,b=%d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
*/


//使用子函数与指针
/*
int main()
{
    int a=1;
    int b=2;
    printf("a=%d,b=%d\n",a,b) ;
    taolu(&a,&b);
    printf("a=%d,b=%d\n",a,b) ;
    return 0;
}

int taolu(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
*/

//只使用指针
/*
int main(void)
{
    int a=1;
    int b=2;
    int temp;
    printf("a=%d,b=%d\n",a,b);

    int* ad_a=&a;
    int* ad_b=&b;

    temp=*ad_a;
    *ad_a=*ad_b;
    *ad_b=temp;

    printf("a=%d,b=%d\n",a,b);
    printf("a=%d,b=%d\n",*ad_a,*ad_b);
    return 0;
}
*/
int main(void)
{
	int a = 1;
	int b = 2;
	printf("调换前： a=%d,b=%d", a, b);
	int* t = &a;

	*t = a;
	a = b;
	b = *t;
	printf("调换后： a=%d,b=%d", a, b);
	return 0;
	
}

