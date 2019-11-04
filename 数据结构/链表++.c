#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

struct mynode
{
	char name[10];
	char phone_number[30];
	char airline_number[30];
	char email[20];
	struct mynode* next;
};
typedef struct mynode mynode;

void set_data(mynode* p, char name[], char phone_number[], char airline_number[], char email[])
{
	strcpy(p->name, name);
	strcpy(p->phone_number, phone_number);
	strcpy(p->airline_number, airline_number);
	strcpy(p->email, email);
}

mynode* query_data_by_name(mynode* p,char data[10])
{
	while (p!=NULL)
	{
		if (strcmp(data,p->name)==0)
		{
			return p;
		}
		p = p->next;
	}
	printf("not fount the node\n");
	return NULL;
}

mynode* append_node(mynode* tail,char name[],char phone_number[], char airline_number[],char email[])
{
	mynode* new_tail = (mynode*)malloc(sizeof(mynode));
	strcpy(new_tail->name, name);
	strcpy(new_tail->phone_number, phone_number);
	strcpy(new_tail->airline_number, airline_number);
	strcpy(new_tail->email, email);
	new_tail->next = NULL;
	tail->next = new_tail;
	return new_tail;
}

mynode* delete_node(mynode* head, char name[])
{
	mynode* p = head;		//不断移动的p指针
	mynode* last = p;		//用与指向p的前一个节点

	if (strcmp(name,p->name)==0)	//第一个节点就是要被删除的节点
	{
		head = head->next;
		free(p);
		return head;
	}

	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(name, p->name)==0)
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

void modify_data(mynode* p,char field[],char data[])
{
	int flag;
	if (strcmp(field,"name")==0)
	{
		flag = 0;
	}
	else if (strcmp(field, "phone_number") == 0)
	{
		flag = 1;
	}
	else if (strcmp(field, "phone_number") == 0)
	{
		flag = 2;
	}
	else if (strcmp(field, "phone_number") == 0)
	{
		flag = 3;
	}
	switch (flag)
	{
	case 0:strcpy(p->name, data); break;
	case 1:strcpy(p->phone_number, data); break;
	case 2:strcpy(p->airline_number, data); break;
	case 3:strcpy(p->email, data); break;
	default:
		printf("not found the field\n");
	}
}

void print_list(mynode* head)
{
	mynode* p = head;
	while (p !=NULL)
	{
		printf("name:%s\t\tphone number:%s\tairline number:%s\temail:%s\n", p->name, p->phone_number, p->airline_number, p->email);
		p = p->next;
	}
}

void main()
{
	/*
	mynode node4 = {"z6","15779019879","13362614958","123@qq.com",NULL};
	mynode node3 = { "l5","15779018779","13363614958","321@qq.com",&node4};
	mynode node2 = { "w4","15779019879","13364614958","233@qq.com",&node3};
	mynode node1 = { "z3","15779015879","13366614958","404@qq.com",&node2};
	mynode* head = &node1;
	mynode* tail = &node4;
	使用这种方法创建链表的前端节点，这部分的节点无法使用free函数释放空间，
	故必须使用malloc来创建空间储存节点，因为在main函数里面创建的变量的空间属于静态空间
	*/

	mynode *head = (mynode*)malloc(sizeof(mynode));
	mynode *tail = head;
	set_data(head, "z3", "15779015879", "13366614958", "404@qq.com");
	tail = append_node(tail, "w4","15779019879","13364614958","233@qq.com");
	tail = append_node(tail, "l5", "15779018779", "13363614958", "321@qq.com");
	tail = append_node(tail, "z6","15779019879", "13362614958", "123@qq.com");

	//测试搜索
	mynode* p1 = query_data_by_name(head,"w4");
	mynode* p2 = query_data_by_name(head, "666");
	if(p1!=NULL)
		printf("name:%s\t\tphone number:%s\tairline number:%s\temail:%s\n", p1->name, p1->phone_number, p1->airline_number, p1->email);
	printf("====================\n");

	//测试增加
	tail = append_node(tail, "c7", "15779018801", "13351514657", "303@qq.com");
	tail = append_node(tail, "c8", "15779018809", "13451514657", "200@qq.com");
	print_list(head);
	printf("====================\n");

	//测试删除
	head = delete_node(head, "z3");
	head = delete_node(head, "c7");
	print_list(head);
	printf("====================\n");

	//测试修改
	modify_data(p1, "name", "dh");
	print_list(head);
	printf("====================\n");
}