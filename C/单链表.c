#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node linknode;

linknode* creatnodelist(void)		//��������ֵ��������׽ڵ��ַ
{
	linknode* head, *pre, *p;
	head = pre = p = NULL;
	printf("����10086��������\n");
	int x = 0;
creat:
	scanf("%d", &x);

	if (x!=10086)
	{
		p = (linknode*)malloc(sizeof(linknode));		//��ȡһ���ڵ�ռ䣬�������ַ����p��p��Ϊ��ǰ�����Ľڵ��ָ��
		p->next = NULL;
		if (head==NULL)		//���ɵ�һ���ڵ�ʱ�����ڵ��ַ����head��pre
		{
			head = pre=p;
		}
		else							//���ɵĲ��ǵ�һ���ڵ�ʱ
		{
			pre->next = p;		//�������Ľڵ��ַ������һ���ڵ��next����ʱpreΪ��һ�ڵ��ָ��
			pre = p;					//��preָ������Ľڵ�
		}
		p->data = x;		//��x��ֵ�����´����Ľڵ������
	}

	else    //���x=10086,���˳������ڵ�Ĺ���
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

	while (pre->next!=target)		//��preָ���ƶ���target����һ���ڵ�
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

	printf("������Ҫ���ҵ�����");
	int x;
	scanf("%d", &x);
	linknode* result = searchinnodelist(x,head);
	if (result==NULL)
	{
		printf("δ���ҵ�");
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