#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int number;
    struct node *next;
};
int iceBreakingGame(int num, int target)
{
    // 创建一个单向循环链表
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->number = num - 1;
    head->next = head;
    for (int i = num - 2; i >= 0; i--)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->number = i;
        temp->next = head->next;
        head->next = temp;
    }

    struct node *p = head->next; // P从0开始
    struct node *a = head;       // temp是p的前驱
    while (a->next != a)
    {
        int i = 1;
        while (i < target)
        {
            a = p;
            p = p->next;
            i++;
        } // 循环结束后p指向需要删除的节点 temp是p的前驱
        a->next = p->next;
        free(p);
        p = a->next;
    }
    return p->number;
}

int main()
{
    printf("%d\n", iceBreakingGame(7, 4));
    return 0;
}
