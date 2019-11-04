#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node node;

node* creat_link()
{
	node* head=NULL,*p,*newnode;
	int temp=0;
	
	if(scanf("%d ",&temp)==0)
	{
		return head;
	}
	else
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=temp;
		head=newnode;
		p=head; 
	}

	while(scanf("%d",&temp)!=0)
	{
		newnode=(node*)malloc(sizeof(node));
		newnode->data=temp;
		p->next=newnode;
		p=newnode;
	}
	p->next=NULL;
	return head;
}

void print_list(node* head)
{
	node* p=head;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

int judge(node* head)
{
	int flag=1;
	node* p=head;
	
	if(p->data < p->next->data)
	{
		while(flag==1 && p->next->next!=NULL)
		{
			if(!(p->data < p->next->data))
			{
				flag=0;
			}
			p=p->next;
		}
	}
	
	else if(p->data > p->next->data)
	{
		while(flag==1 && p->next->next!=NULL)
		{
			if(!(p->data > p->next->data))
			{
				flag=0;
			}
			p=p->next;
		}
	}
	
	if(flag==1)
	{
		printf("链表有序\n");
	}
	else
	{
		printf("链表无序\n");
	}
	
	return flag;
}

node* fanzhuan(node* head)
{
	node* p=head;
	node* next=p->next;
	head->next=NULL;
	while(next->next!=NULL)
	{
		node* temp=next->next;
		next->next=p;
		p=next;
		next=temp;
	}
	next->next=p;
	head=next;
	return head;
}

node* findnode(node* head,int x)
{
	node*p=head;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}


node* insert(node* head,int x,int y)
{
	node* p=findnode(head,x);
	//插在首节点前
	if(p==head)
	{
		node* newnode=(node*)malloc(sizeof(node));
		newnode->data=y;
		newnode->next=p;
		head=newnode;
		return newnode;
	}
}


int main(int argc,char ** argv)
{
	node* head=creat_link();
	//print_list(head);
	//int flag=judge(head);
	head=fanzhuan(head);
	print_list(head);
	getchar();
	getchar();
	getchar();
	return 0;
}