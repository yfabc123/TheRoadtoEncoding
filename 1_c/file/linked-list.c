#include <stdio.h>
#include "node.h"

// typedef struct   node {
//     int value;
//     struct node *next;
// } Node;

int main()
{

	Node *head = NULL;
	int number;
	do
	{
		printf("�����룺");
		scanf("%d", &number);
		if (number != -1)
		{
			Node *p = (Node *)malloc(sizeof(Node));
			p->value = number;
			p->next = NULL;
			// ��������� ֮ǰ����Ϊ�� ֮ǰ����Ϊ��
			if (head == NULL)
			{
				head = p;
			}
			else
			{
				// ����Ϊ��ʱ ��Ҫ�ҵ��������һ��Ԫ�� ��������մ�����Node�ṹ
				Node *last = head;

				while (last->next != NULL)
				{
					last = last->next;
				}
				last->next = p;
			}
		}
	} while (number != -1);
	return 0;
}
