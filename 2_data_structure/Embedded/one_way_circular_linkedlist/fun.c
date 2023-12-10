#include "head.h"

List *create()
{

    // 创建一个8节点环形单链表
    List *head = (List *)malloc(sizeof(List));

    head->number = 1;
    List *p = head;
    for (int i = 2; i <= 8; i++)
    {
        List *temp = (List *)malloc(sizeof(List));
        temp->number = i;
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
    p->next = head;

    return head;
}
// 释放
void del(List *l)
{
    List *head = l->next->next; // 第三个个几点作为头结点
    while (head->next)
    {
        int i = 1;
        while (i <= 2) // 循环结束 指针指向要删除的节点的前驱
        {
            head = head->next;
            i++;
        }
        List *temp = head->next;
        head->next = temp->next;

        printf("%d\n", temp->number); // 当输出1的那次循环 8节点指针已经指向自己了
        free(temp);                   //
        if (head->next == head)
        {
            printf("%d\n", head->number);
            free(head);
            head->next = NULL;
        }
        else

            head = head->next; //
    }
}