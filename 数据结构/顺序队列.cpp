#include <stdio.h>
#include <iostream>
#define MAXSIZE 100
typedef int datatype;

class sequence_queue
{
	public:
		datatype a[MAXSIZE];
		int front;
		int rear;

		/*函数功能 : 队列（顺序存储）初始化 */
		void init()
		{
			front =rear = 0;
		}

		/*函数功能:判断队列（顺序存储）是否为空*/
		int empty()
		{
			return (front == rear ? 1 : 0);
		}

		/*打印队列（顺序存储）的结点值*/
		void display()
		{
			int i;
			if (empty())
			{
				printf("\n顺序队列是空的!");
			}
			else
				for (i = front; i < rear; i++)  printf("%5d", a[i]);
		}

		/*取得队列（顺序存储）的队首结点值 */
		datatype get()
		{
			if (empty())
			{
				printf("\n顺序队列是空的！无法获得队首结点值！");
				exit(1);
			}
			return a[front];
		}

		/*队列（顺序存储）的插入（进队）操作*/
		void insert(datatype x)
		{
			int i;
			if (rear == MAXSIZE)
			{
				printf("\n顺序队列是满的!"); exit(1);
			}
			a[rear] = x;
			rear = rear + 1;
		}

		/*队列（顺序存储）的删除（出队）操作*/
		void dele()
		{
			if (front == rear)
			{
				printf("\n顺序队列是空的！不能做删除操作！");
				exit(1);
			}
			front++;
		}

};
