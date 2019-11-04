#include<stdio.h>
#include<stdlib.h>

struct node
{
	int score;
	struct node* next;
};
typedef struct node node;

node* creatlinklist(void)
{
	node* head = NULL;
	node* p = NULL;
	head = (node*)malloc(sizeof(node));		//产生头节点
	p = head;
	int temp;

	printf("请输入链表的数据，若输入值为-1则退出创建\n");
	scanf_s("%d", &temp);
	if (temp == -1)		//如果一来就输入-1，则直接退出
	{
		free(head);	//退出前删除创建的头节点
		return 0;
	}
	p->score = temp;

	while (scanf_s("%d", &temp) && temp != -1)		//开始不断创建节点,循环的条件是scanf成功赋值和输入的数据不等于-1
	{
		p->next = (node*)malloc(sizeof(node));
		p->next->score = temp;
		p = p->next;
	}
	p->next = NULL;		//创建结束后，将最后一个节点的next指针指向NULL

	return head;
}

void printlistdata(node* p)
{
	while (p != NULL)
	{
		printf("%d  ", p->score);
		p = p->next;
	}
	printf("\n");
}

node* deletenode(node* head)
{
	int data;
	printf("please enter a number you want to delete\n");
	scanf_s("%d", &data);
	node* p = head;		//不断移动的p指针
	node* last=p;		//用与指向p的前一个节点

	if (head->score==data)	//第一个节点就是要被删除的节点
	{
		head = head->next;
		free(p);
		return head;
	}

	while (p->next!=NULL)
	{
		p = p->next;
		if (p->score==data)
		{
			last->next = p->next;
			free(p);
			return head;
		}
		last = p;
	}

	printf("not found the data!\n");
	return head;
}

void deletallnode(node* p)
{
	node* pnext=p;
	while (pnext!=NULL)
	{
		pnext = p->next;
		free(p);
		p = pnext;
	}
	free(p);
}

int  main(void)
{
	node* head = creatlinklist();
	printlistdata(head);
	head=deletenode(head);
	printlistdata(head);
	deletallnode(head);
	return 0;
}