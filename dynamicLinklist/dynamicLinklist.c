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

int n;//ȫ�ֱ�������ڵ���

/*���������ܹ��������ṹ��ָ��
�ֱ���*head��ͷ���ָ�룩
*p1 ����̬�����ڴ�ռ��ָ�룩
*p2 ����ǰ�����ָ�����һ���ڵ㣩
*/
struct student *creat(void)  //����һ��ָ�뺯���������Ǻ���������ֵ��ָ�룬�˴�Ϊstudent���͵�ָ��
{
	struct student *head;
	struct student *p1, *p2;
	n = 0;
	p1 = p2 = (struct student*)malloc(LEN); //malloc ���ص���һ��void���͵�ָ�룬ָ�����ռ���׵�ַ������Ҫ����ǿ������ת����ƥ��
	scanf_s("%ld,%f", &p1->num, &p1->score);
	head = NULL;
	while (p1->num !=0) //������Ƿ�����0��Ϊ��������ı��
	{
		n=n+1; //n��������¼�������
		if (n==1) //��һ���ڵ�
		{
			head = p1; //����ǵ�һ���ڵ���head ָ����
		}
		else
		{
			p2->next = p1;  //������ǵ�һ����ָ��p1��ֵ��p2->next
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