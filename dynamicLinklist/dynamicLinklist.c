#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define NULL 0
#define LEN sizeof(struct student)

struct student
{
	long num;
	float score;
	struct student *next;
};

int n;//全局变量定义节点数

/*创建链表总共有三个结构体指针
分别是*head（头标记指针）
*p1 （动态产生内存空间的指针）
*p2 （当前链表的指针最后一个节点）
*/
struct student *creat(void)  //这是一个指针函数，本质是函数，返回值是指针，此处为student类型的指针
{
	struct student *head;
	struct student *p1, *p2;
	n = 0;
	p1 = p2 = (struct student*)malloc(LEN); //malloc 返回的是一个void类型的指针，指向分配空间的首地址，所以要做个强制类型转换以匹配
	scanf_s("%ld,%f", &p1->num, &p1->score);
	head = NULL;
	while (p1->num !=0) //结束标记符数字0作为输入结束的标记
	{
		n=n+1; //n计数器记录输入个数
		if (n==1) //第一个节点
		{
			head = p1; //如果是第一个节点则将head 指向他
		}
		else
		{
			p2->next = p1;  //如果不是第一个择将指针p1赋值给p2->next
		}
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		scanf_s("%ld,%f", &p1->num, &p1->score);

	}
	p2->next = NULL;
	return(head);

};

void printll(struct student *head)
{
	struct student *p;
	printf("\nNow Print %d records list :\n", n);
	p = head;
	if (head != NULL)
	{
		do
		{
			printf("%ld %5.1f\n", p->num, p->score);
			p = p->next;
		} while (p!=NULL);
	}
}

int main()
{
	struct student *head;
	head = creat();
	printll(head);
	return 0;
}