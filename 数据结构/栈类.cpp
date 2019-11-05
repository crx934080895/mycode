#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int datatype;

class sequence_stack
{
public:
	datatype a[MAXSIZE];
	int top;

	/*方法功能：栈（顺序存储）初始化*/
	void init()	{		top = 0;	}

	/*方法功能：判断栈（顺序存储）是否为空*/
	int empty()	{		return(top ? 0 : 1);	}

	/*方法功能：读栈顶（顺序存储）结点值*/
	 datatype read()	{	   if (empty())     		{printf("\n栈是空的!");exit(1);}	   else     		return a[top-1];	 }

	 /*方法功能：栈（顺序存储）的插入（进栈）操作*/
	 void push(datatype x)	 {		 if (top == MAXSIZE)		 {			 printf("\nThe sequence stack is full!"); 			 return;		 }		 a[top] = x;		 top++;	 }

	 /*方法功能：栈（顺序存储）的删除（进栈）操作*/
	 void pop()	 {		 if (top == 0)		 {			 printf("\nThe sequence stack is empty!"); 			 return;		 }		 top--;	 }

};
//这是一行改动的文字