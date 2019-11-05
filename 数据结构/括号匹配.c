#include<stdio.h>
#include<stdlib.h>

struct node
{
	char info;
	struct node* next;
};
typedef struct node node;

int empty(node* st)
{
	return(st == NULL ? 0 : 1);
}

char read(node *top)
{
	if (top == NULL)
	{
		printf("\n链式栈是空的!");
		exit(1);
	}
	return  (top->info);
}

node* push(node *top, char x)
{
	node *p;
	p = (node*)malloc(sizeof(node));
	p->info = x;
	p->next = top;
	top = p;
	return top;
}

node *pop(node *top)
{
	node *q;
	if (!top)
	{
		printf("\n链式栈是空的!");
		return NULL;
	}
	q = top;
	top = top->next;
	free(q);
	return top;
}

int match_kuohao(char c[])
{
	int i = 0;
	node* top = NULL;
	while (c[i] != '#')
	{
		switch (c[i])
		{
		case '{':
		case '[':
		case '(':
			top = push(top, c[i]);
			break;
		case '}':
			if (empty(top) && read(top) == '{')
			{
				top = pop(top);
				break;
			}
			else return 0;
		case ']':
			if (empty(top) && read(top) == '[')
			{
				top = pop(top);
				break;
			}
			else return 0;
		case ')':
			if (empty(top) && (read(top) == '('))
			{
				top = pop(top);
				break;
			}
			else return 0;
		}
		i++;
	}
	return (!empty(top));
}

void main()
{
	char a[100] = "";
	printf("请输入要判断的括号字符串，以#加回车结束：\n");
	gets_s(a,100);
	printf("1表示匹配成功，0表示匹配失败\n匹配结果:%d\n", match_kuohao(a));
	getchar();
}