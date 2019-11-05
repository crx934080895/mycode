#include<stdio.h>
#include<stdlib.h>
struct student
{
	char name[10];
	int score[3];
	int total;
};
typedef struct student student;

void intputdata(student stu[], int a)
{
	for (int i = 0; i < a; i++)
	{
		gets(stu[i].name);
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%d ", &stu[i].score[j]);
		}
	}
} 

void cultotal(student stu[], int len)
{
	for (int i = 0; i < len; i++)
	{
			stu[i].total = 0;
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stu[i].total += stu[i].score[j];
		}
	}
}

void exchange(student* a,student *b)
{
	student temp = *a;
	*a = *b;
	*b = temp;
}

void sort_struct_array(student stu[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (stu[j].total> stu[j+1].total)
			{
				exchange(stu + j, stu + j + 1);
			}
		}
	}
}

int  main(void)
{
	student stu[4];
	intputdata(stu, 4);
	cultotal(stu, 4);
	sort_struct_array(stu, 4);

	for (int i = 0; i < 4; i++)
	{
		printf("姓名:%s,语文:%d,数学:%d,英语:%d,总分:%d\n",stu[i].name,stu[i].score[0], stu[i].score[1], stu[i].score[2],stu[i].total);
	}
	return 0;
}