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
		printf("请输入：");
		scanf("%d", &number);
		if (number != -1)
		{
			Node *p = (Node *)malloc(sizeof(Node));
			p->value = number;
			p->next = NULL;
			// 分两种情况 之前链表为空 之前链表不为空
			if (head == NULL)
			{
				head = p;
			}
			else
			{
				// 链表不为空时 需要找到链表最后一个元素 让其关联刚创建的Node结构
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
