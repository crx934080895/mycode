#include <stdio.h>
#include <stdlib.h>

//��ʹ��ָ�����Ӻ���
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


//ʹ���Ӻ�����ָ��
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

//ֻʹ��ָ��
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
	printf("����ǰ�� a=%d,b=%d", a, b);
	int* t = &a;

	*t = a;
	a = b;
	b = *t;
	printf("������ a=%d,b=%d", a, b);
	return 0;
	
}

