#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int datatype;

class sequence_list
{
public:
	datatype a[MAXSIZE];
	int size=0;

	/*方法功能 : 顺序表的初始化—置空表*/
	void init()
	{
		this->size = 0;
	}


	/*方法功能 : 顺序表的初始化—输入数据*/
	void setdate()
	{
		printf("请不断按行输入数据，直到超出表长上限或者输入-10086停止或者输入的不是数字停止:\n");
		while (size <= MAXSIZE)
		{
			int temp=-10086;
			if (scanf("%d", &temp) == 0 || temp == -10086)
			{
				printf("输入结束\n");
				return; 
			}
			this->append(temp);
		}
	}

	/*方法功能 : 在顺序表后部进行插入操作*/
	void append(datatype x)
	{
		if (size == MAXSIZE)
		{
			printf("顺序表是满的!"); 
			return;
		}
		a[size] = x;
		size = size + 1;
	}

	/*方法功能 : 打印顺序表的各结点值*/
	void display()
	{
		int i;
		if (!size) 
			printf("\n顺序表是空的!");
		else
			for (i = 0; i < size; i++)  
				printf("%d\t", a[i]);
		printf("\n");
	}

	/*方法功能 : 判断顺序表是否为空*/
	int empty()
	{
		return	(size == 0 ? 1 : 0);
	}

	/*方法功能 : 查找顺序表中值为x的结点位置*/
	int find(datatype x)
	{
		int i = 0;
		while (i < size&&a[i] != x) i++;
		return i < size ? i : -1;
	}

	/*方法功能 : 取得顺序表中第i个结点的值*/
	datatype get(int i)
	{
		if (i < 0 || i >= size)
		{
			printf("\n指定位置的结点不存在!"); 
			return NULL;
		}
		else
			return a[i];
	}

	/*方法功能 : 在顺序表的position位置插入值为x的结点*/
	void insert(datatype x, int position)
	{
		int i;
		if (size == MAXSIZE)
		{
			printf("\n顺序表是满的!没法插入!"); 
			return;
		}
		if (position<0 || position>size)
		{
			printf("\n指定的插入位置不存在!"); 
			return;
		}
		for (i = size; i > position; i--) a[i] = a[i - 1];
		a[position] = x;   size++;
	}

	/*方法功能 : 删除顺序表中第position位置的结点*/
	void dele(int position)
	{
		int i;
		if (size == 0)
		{
			printf("\n顺序表是空的!"); 
			return;
		}
		if (position < 0 || position >= size)
		{
			printf("\n指定的删除位置不存在!"); 
			return;
		}
		for (i = position; i < size - 1; i++) a[i] = a[i + 1];
		size--;
	}

	/*方法功能 : 将顺序表反转*/
	void reverse()
	{
		datatype temp;
		for (int i = 0; i < size / 2; i++) {
			temp = a[i];
			a[i] = a[size - i - 1];
			a[size - i - 1] = temp;
		}
	}

	/*方法功能 : 将有序顺序表分裂成两个线性表l1与l2，l1由表中所奇数组成，l2由所有偶数组成。*/
	void sprit(sequence_list *l1, sequence_list *l2)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->a[i] % 2 != 0)
				l1->append(this->a[i]);
			else
				l2->append(this->a[i]);
		}
	}

	/*方法功能 : 将有序顺序表L1与L2合并到对象中*/
	void merge(sequence_list *l1, sequence_list *l2)
	{
		for (int i = 0; i < l1->size; i++)
		{
			this->append(l1->a[i]);
		}
		for (int i = 0; i < l2->size; i++)
		{
			this->append(l2->a[i]);
		}
	}
};

int main()
{
	sequence_list list1;
	list1.setdate();
	list1.display();
	sequence_list list2;
	sequence_list list3;
	list1.sprit(&list2,&list3);
	list2.display();
	list3.display();
	list1.merge(&list2, &list3);
	list1.display();
	getchar();
	getchar();
	return 0;
}
