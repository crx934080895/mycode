#include<string.h>
#include<stdlib.h>
#include<stdio.h>

struct node
{
	char data;
	struct node *next;
};
typedef struct node node;

node*  strcreat()
{
	node *S = NULL;
	char ch; 
	node *p, *r;
	S = NULL;  
	r = NULL;
	while ((ch = getchar()) != '\n')
	{
		p = (node*)malloc(sizeof(node));
		p->data = ch;
		if (S == NULL)
			S = p;
		else 
			r->next = p;
		r = p;   
		/*r移向当前链接串的最后一个字符的位置*/
	}
	if (r != NULL)
		r->next = NULL;  /*处理表尾结点指针域*/
	return S;
}

int strlen_link(node *S)
{
	int N = 0;
	node *p = S;
	while (p != NULL)
	{
		N++;
		p = p->next;
	}
	return N;
}

void print(node *S)
{
	node *p = S;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int strcmp_link(node *S1, node *S2)
{
	node *p1 = S1;
	node *p2 = S2;
	//匹配标志变量
	int flag = 1;
	//循环能否进行标志变量

	if (p1==NULL && p2==NULL)
	{
		printf("错误，输入了空指针！");
		return 0;
	}

	//判断长度
	if (strlen_link(p1) != strlen_link(p2))
	{
		flag = 0;
		return flag;
	}

	//同长度下判断字符是否相同
	while (p1!=NULL && p2!=NULL)
	{
		if (p1->data != p2->data)
		{
			flag = 0;
			return flag;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	return flag;
}

node* substring(node* S, int i, int len)
{
	int k; 
	node *p, *q, *r, *t;
	p = S, k = 1;
	/*用p查找S中的第i个字符*/

	while (p!=NULL && k < i)
	{
		p = p->next;
		k++;
	}
	if (!p)
	{
		printf("error1\n");
		return(NULL);
	}

	else 
	{
		r = (node*)malloc(sizeof(node));
		r->data = p->data;
		r->next = NULL;
		k = 1;
		q = r;
		/*用q始终指向子串的最后一个字符的位置*/

		while (p->next && k < len)  /*取长度为len的子串*/
		{
			p = p->next; k++;
			t = (node*)malloc(sizeof(node));
			t->data = p->data;
			q->next = t; q = t;
		}
		if (k < len)
		{
			printf("error2\n");
			return(NULL);
		}
		else
		{
			q->next = NULL; return(r);
		}
		/*处理子串的尾部*/
	}
}

node* get_add(node *S,int pos)
{
	node* p = S;
	while (pos>1 && p!=NULL)
	{
		p = p->next;
		pos--;
	}
	return p;
}

node* get_tail(node* S)
{
	node* p = S;
	while (p->next!=NULL)
	{
		p = p->next;
	}
	return p;
}

void fun(node *S1, node *S2, node *S3)
{
	node *p=S1;
	node *S1_Dst_head = NULL;
	node *S1_Dst_tail = NULL;
	node *S3_tail = get_tail(S3);
	int pos[2] = { 0,0 };
	int flag = 0;
	int S1_len = strlen_link(p);

	//查找目标子串
	for (int i = 1; i <= S1_len && flag==0; i++)
	{
		for (int j = 1; j <= S1_len-i+1 && flag==0; j++)
		{
			node* temp = substring(S1, i, j);
			if (strcmp_link(temp,S2))
			{
				flag= 1;
				pos[0] = i;
				pos[1]= i+j-1;
			}
		}
	}

	//获取目标子串的首尾地址
	if (flag==1)
	{
		S1_Dst_head = get_add(S1, pos[0]);
		S1_Dst_tail = get_add(S1, pos[1]);
	}

	//释放无用数据空间
	node* free_p = S1_Dst_head->next;
	while (free_p!=S1_Dst_tail)
	{
		node* temp = free_p;
		free_p = free_p->next;
		free(temp);
	}
	
	//拼接
	S3_tail->next = S1_Dst_tail->next;
	memcpy(S1_Dst_head, S3, sizeof(node));

	//释放无用数据空间
	free(S3);

	if (flag==0)
	{
		printf("未找到要替换的字符串\n");
	}
}

void main(void)
{
	printf("请输入目标串(目标串长度大于或等于2)：");
	node *str1 = strcreat();
	printf("请输入要替换的旧字符(旧串长度大于或等于2)：");
	node *str2 = strcreat();
	printf("请输入替换成的新字符(新串长度大于或等于2)：");
	node *str3 = strcreat();
	fun(str1, str2,str3);
	print(str1);
	getchar();
}
