#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node linknode;

linknode* creatnodelist(void)		//函数返回值是链表的首节点地址
{
	linknode* head, *pre, *p;
	head = pre = p = NULL;
	printf("输入10086结束创建\n");
	int x = 0;
creat:
	scanf("%d", &x);

	if (x!=10086)
	{
		p = (linknode*)malloc(sizeof(linknode));		//获取一个节点空间，并将其地址赋给p，p即为当前产生的节点的指针
		p->next = NULL;
		if (head==NULL)		//生成第一个节点时，将节点地址赋给head和pre
		{
			head = pre=p;
		}
		else							//生成的不是第一个节点时
		{
			pre->next = p;		//将产生的节点地址赋给上一个节点的next，此时pre为上一节点的指针
			pre = p;					//将pre指向产生的节点
		}
		p->data = x;		//将x的值赋给新创建的节点的数据
	}

	else    //如果x=10086,即退出创建节点的过程
	{
		
		return head;
	}

	goto creat;
}

linknode* searchinnodelist(int x,linknode* head)
{
	linknode* p=head;
	while (p->data != x)
	{
		if (p->next==NULL)
		{
			return NULL;
		}
		p = p->next;
	}
	return p;
}

void deletenode(linknode* head, linknode* target)
{
	linknode* pre=head;

	while (pre->next!=target)		//将pre指针移动到target的上一个节点
	{
		pre = pre->next;
	}
	pre->next = target->next;
	free(target);
}

int main(void) 
{
	linknode* p, *head;
	p=head=creatnodelist();

	/*while(p!=NULL)
	{
		printf("%d\n", p->data);
		p=p->next;
	}
	p = head;
	*/

	printf("请输入要查找的数字");
	int x;
	scanf("%d", &x);
	linknode* result = searchinnodelist(x,head);
	if (result==NULL)
	{
		printf("未查找到");
	}

	deletenode(head,result);

	p = head;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	p = head;

	return 0;
}