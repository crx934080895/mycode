#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int datatype;

class sequence_list
{
public:
	datatype a[MAXSIZE];
	int size=0;

	/*�������� : ˳���ĳ�ʼ�����ÿձ�*/
	void init()
	{
		this->size = 0;
	}


	/*�������� : ˳���ĳ�ʼ������������*/
	void setdate()
	{
		printf("�벻�ϰ����������ݣ�ֱ�����������޻�������-10086ֹͣ��������Ĳ�������ֹͣ:\n");
		while (size <= MAXSIZE)
		{
			int temp=-10086;
			if (scanf("%d", &temp) == 0 || temp == -10086)
			{
				printf("�������\n");
				return; 
			}
			this->append(temp);
		}
	}

	/*�������� : ��˳���󲿽��в������*/
	void append(datatype x)
	{
		if (size == MAXSIZE)
		{
			printf("˳���������!"); 
			return;
		}
		a[size] = x;
		size = size + 1;
	}

	/*�������� : ��ӡ˳���ĸ����ֵ*/
	void display()
	{
		int i;
		if (!size) 
			printf("\n˳����ǿյ�!");
		else
			for (i = 0; i < size; i++)  
				printf("%d\t", a[i]);
		printf("\n");
	}

	/*�������� : �ж�˳����Ƿ�Ϊ��*/
	int empty()
	{
		return	(size == 0 ? 1 : 0);
	}

	/*�������� : ����˳�����ֵΪx�Ľ��λ��*/
	int find(datatype x)
	{
		int i = 0;
		while (i < size&&a[i] != x) i++;
		return i < size ? i : -1;
	}

	/*�������� : ȡ��˳����е�i������ֵ*/
	datatype get(int i)
	{
		if (i < 0 || i >= size)
		{
			printf("\nָ��λ�õĽ�㲻����!"); 
			return NULL;
		}
		else
			return a[i];
	}

	/*�������� : ��˳����positionλ�ò���ֵΪx�Ľ��*/
	void insert(datatype x, int position)
	{
		int i;
		if (size == MAXSIZE)
		{
			printf("\n˳���������!û������!"); 
			return;
		}
		if (position<0 || position>size)
		{
			printf("\nָ���Ĳ���λ�ò�����!"); 
			return;
		}
		for (i = size; i > position; i--) a[i] = a[i - 1];
		a[position] = x;   size++;
	}

	/*�������� : ɾ��˳����е�positionλ�õĽ��*/
	void dele(int position)
	{
		int i;
		if (size == 0)
		{
			printf("\n˳����ǿյ�!"); 
			return;
		}
		if (position < 0 || position >= size)
		{
			printf("\nָ����ɾ��λ�ò�����!"); 
			return;
		}
		for (i = position; i < size - 1; i++) a[i] = a[i + 1];
		size--;
	}

	/*�������� : ��˳���ת*/
	void reverse()
	{
		datatype temp;
		for (int i = 0; i < size / 2; i++) {
			temp = a[i];
			a[i] = a[size - i - 1];
			a[size - i - 1] = temp;
		}
	}

	/*�������� : ������˳�����ѳ��������Ա�l1��l2��l1�ɱ�����������ɣ�l2������ż����ɡ�*/
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

	/*�������� : ������˳���L1��L2�ϲ���������*/
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
