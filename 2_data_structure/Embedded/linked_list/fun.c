#include "head.h"

single_linked_list *create()
{
    single_linked_list *list = (single_linked_list *)malloc(sizeof(single_linked_list));
    if (NULL == list)
    {
        printf("no space!");
    }
 //   memset(list, 0, sizeof(single_linked_list));
    list->n = 0;
    list->next = NULL;

    return list;
}

void insert(single_linked_list *list, int number)
{
    single_linked_list *temp = (single_linked_list *)malloc(sizeof(single_linked_list)); // 存放要插入数据
    temp->n = number;
    temp->next = NULL;
    if (list->next == NULL)
    {
        list->next = temp;
    }
    else
    {
        single_linked_list *p = list->next; // 遍历指针
        single_linked_list *p1 = list;      // p1是遍历指针的前驱
        // 插入前比较大小
        while (p && p->n > number)
        {
            p1 = p;
            p = p->next;
        }
        temp->next = p;
        p1->next = temp;
    }
}

void prinf_list(single_linked_list *l)
{
    if (l==NULL)
    {
        return;
    }
    
    single_linked_list *p = l->next;
    while (p)
    {
        printf("%d\n", p->n);
        p = p->next;
    }
}

int is_full(single_linked_list *list)
{
    return list->next == NULL ? 0 : 1; // 空返回0 非空返回1
}

void delete(single_linked_list *list, int number)
{
    single_linked_list *p = list->next; // 遍历指针
    single_linked_list *p1 = list;      // 遍历指针的前驱
    // 什么条件一直循环？p不为空
    while (p)
    {

        if (number == p->n)
        {
            p1->next = p->next;
            free(p);
            p = p1->next;
        }
        else
        {
            p1 = p;
            p = p->next;
        }
    }
}

// 逆序链表
void fun(single_linked_list *l)
{

    single_linked_list *p1 = l->next->next; // two
    single_linked_list *p2 = p1->next;      // three
    l->next->next = NULL;                   // 头元素 next置空
    if (NULL == p1)
    {
        return;
    }
    else if (NULL == p2)
    {
        p1->next = l->next;
        l->next = p1;
    }
    while (p2)
    {
        p1->next = l->next;
        l->next = p1;
        p1 = p2;
        p2 = p1->next;
    }
}

void rm(single_linked_list *l)
{
    single_linked_list *p = l;
    while (l)
    {

        p = l;
        l = l->next;

        free(p);
    }
    
}