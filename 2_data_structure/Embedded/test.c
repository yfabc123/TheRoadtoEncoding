#include <stdio.h>
#include <stdlib.h>
struct node
{
    int number;
    struct node *next;
};
int lastRemaining(int n, int m)
{
    // ����һ������ѭ������
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->number = n - 1;
    head->next = head;
    for (int i = n-2; i >=0; i--)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->number = i;
        temp->next = head->next;
        head->next = temp;
    }

    struct node *p = head->next; // P��0��ʼ
    struct node *a = head; // temp��p��ǰ��
    while (a->next != a)
    {
        int i = 1;
        while (i < m)
        {
            a = p;
            p = p->next;
            i++;
        } // ѭ��������pָ����Ҫɾ���Ľڵ� temp��p��ǰ��
        a->next = p->next;
        printf("%d\n", p->number);
        free(p);
        p = a->next;
    }
    return p->number;
}

int main()
{
    lastRemaining(5, 2);

    return 0;
}