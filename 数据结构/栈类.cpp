#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int datatype;

class sequence_stack
{
public:
	datatype a[MAXSIZE];
	int top;

	/*�������ܣ�ջ��˳��洢����ʼ��*/
	void init()	{		top = 0;	}

	/*�������ܣ��ж�ջ��˳��洢���Ƿ�Ϊ��*/
	int empty()	{		return(top ? 0 : 1);	}

	/*�������ܣ���ջ����˳��洢�����ֵ*/
	 datatype read()	{	   if (empty())     		{printf("\nջ�ǿյ�!");exit(1);}	   else     		return a[top-1];	 }

	 /*�������ܣ�ջ��˳��洢���Ĳ��루��ջ������*/
	 void push(datatype x)	 {		 if (top == MAXSIZE)		 {			 printf("\nThe sequence stack is full!"); 			 return;		 }		 a[top] = x;		 top++;	 }

	 /*�������ܣ�ջ��˳��洢����ɾ������ջ������*/
	 void pop()	 {		 if (top == 0)		 {			 printf("\nThe sequence stack is empty!"); 			 return;		 }		 top--;	 }

};
//����һ�иĶ�������