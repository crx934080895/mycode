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
	node* head = NULL, *p, *newnode;
	int temp = 0;

	if (scanf_s("%d", &temp) == 0)
	{
		return head;
	}

	else
	{
		newnode = (node*)malloc(sizeof(node));
		newnode->data = temp;
		head = newnode;
		p = head;
	}

	while (scanf_s("%d", &temp) != 0)
	{
		newnode = (node*)malloc(sizeof(node));
		newnode->data = temp;
		p->next = newnode;
		p = newnode;
	}
	p->next = NULL;
	return head;
}

void print_list(node* head)
{
	node* p = head;
	if (head==NULL)
	{
		printf("链表为空");
		return;
	}
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

int judge(node* head)
{
	int flag = 1;
	node* p = head;

	if (p->data < p->next->data)
	{
		while (flag == 1 && p->next->next != NULL)
		{
			if (!(p->data < p->next->data))
			{
				flag = 0;
			}
			p = p->next;
		}
	}

	else if (p->data > p->next->data)
	{
		while (flag == 1 && p->next->next != NULL)
		{
			if (!(p->data > p->next->data))
			{
				flag = 0;
			}
			p = p->next;
		}
	}

	if (flag == 1)
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
	node* p = head;
	node* next = p->next;
	head->next = NULL;
	while (next->next != NULL)
	{
		node* temp = next->next;
		next->next = p;
		p = next;
		next = temp;
	}
	next->next = p;
	head = next;
	return head;
}

node* findnode(node* head, int x)
{
	node*p = head;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}


/*node* insert(node* head, int x, int y)
{
	node* p = findnode(head, x);
	//插在首节点前
	if (p == head)
	{
		node* newnode = (node*)malloc(sizeof(node));
		newnode->data = y;
		newnode->next = p;
		head = newnode;
		return newnode;
	}
}*/

node* append_node(node* tail,int newdata)
{
	node* new_tail = (node*)malloc(sizeof(node));
	new_tail->data = newdata;
	new_tail->next = NULL;
	tail->next = new_tail;
	return new_tail;
}


node* jiaoji(node* head0,node* head1)
{
	node* p = head0;
	node* head2=(node*)malloc(sizeof(node));
	head2->next = NULL;
	node* tail = head2;

	while (p!=NULL)
	{
		node* temp = findnode(head1, p->data);
		if (temp!=NULL)
		{
			tail = append_node(tail,p->data);
		}
		p = p->next;
	}

	if (head2->next==NULL)
	{
		printf("两链表的交集为空");
		return NULL;
	}

	return head2->next;
}

node* findtail(node* head)
{
	node* p = head;
	while (p->next!=NULL)
	{
		p = p->next;
	}
	return p;
}

void merge(node* head0, node* head1)
{
	int flag = 0;

	if (head0->data>head0->next->data)//降序链表
	{
		flag = 0;
	}
	else//升序链表
	{
		flag = 1;
	}

	if (flag==0)
	{
		if (head0->data>head1->data)
		{
			findtail(head0)->next = head1;
		}
		else
		{
			findtail(head1)->next = head0;
		}
	}
	else
	{
		if (head0->data > head1->data)
		{
			findtail(head1)->next = head0;
		}
		else
		{
			findtail(head0)->next = head1;
		}
	}
}

int main(int argc, char ** argv)
{
	node* head0 = creat_link();
	getchar();
	node* head1 = creat_link();
	merge(head0, head1);
	print_list(head0);
	//node* head2 = jiaoji(head0, head1);
	//print_list(head2);
	//int temp = 0;
	//printf("%d", scanf_s("%d", &temp));
	//print_list(head);
	//int flag=judge(head);
	//head = fanzhuan(head);
	//print_list(head);
}