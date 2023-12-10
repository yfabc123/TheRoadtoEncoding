#include "linkList.h"

linknode_t *create_empty_linklist()
{
    linknode_t *head = (linknode_t *)malloc(sizeof(linknode_t));
    head->next = NULL;
    head->data = 0;
    return head;
}
// 头插法
void insert_head_linklist(linknode_t *head, datatype_t data)
{
    linknode_t *temp = (linknode_t *)malloc(sizeof(linknode_t));
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
}
void printf_data_linklist(linknode_t *head)
{

    linknode_t *ptr = head->next;
    while (ptr)
    {

        printf("%d\n", ptr->data);
      //  printf("%d\n", ptr->next);

        ptr = ptr->next;
    }
}
// 尾插法思路:一直遍历到最后一个元素 最后一个元素条件:下一个元素为NULL
void insert_tail_linklist(linknode_t *head, datatype_t data)
{
    linknode_t *ptr = head;

    while (ptr->next)
    {
        ptr = ptr->next;
    }
    linknode_t *temp = (linknode_t *)malloc(sizeof(linknode_t));
    temp->data = data;
    temp->next = NULL;
    ptr->next = temp;
}
// 升序插入
void insert_order_linklist(linknode_t *head, datatype_t data)
{
    linknode_t *ptr = head;
    while (ptr->next && ptr->next->data < data)
    {
        ptr = ptr->next;
    }
    linknode_t *temp = (linknode_t *)malloc(sizeof(linknode_t));
    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
}

void delete_data_linklist(linknode_t *head, datatype_t data)
{
    linknode_t *ptr = head;
    while (ptr->next)
    {
        if (ptr->next->data == data)
        {
            linknode_t *tempNode = ptr->next;
            ptr->next = tempNode->next;
            free(tempNode);
            tempNode = NULL;
            printf("删除了一个\n"); // 出现了一个bug 有的没删除?
        }
        else
        {
            ptr = ptr->next;
        }
    }
}
// 反转链表
void reverse_data_linklist(linknode_t *head)
{
    if (!head->next && !head->next->next)
    {
        return;
    }

    linknode_t *ptr = head->next->next;
    linknode_t *ptrNext = ptr->next;

    head->next->next = NULL;
    while (ptr)
    {
        ptr->next = head->next;
        head->next = ptr;
        ptr = ptrNext; // 最后一次ptrNext变为了NULL
        if (!ptrNext)
        {
            return;
        }
        ptrNext = ptrNext->next;
    }
}
// 为什么传递二级指针?因为最后要把头节点也清空 然后让头节点指针变量变指向NULL
// void clean_up_linklist(linknode_t **head)
// {
//     if ((*head)->next == NULL)
//     {
//         return;
//     }
//     linknode_t *temp = NULL;
//     while ((*head)->next)
//     {
//         temp = (*head)->next;
//         (*head)->next = temp->next;
//         free(temp);
//     }
//     temp = NULL;
//     free(*head);
//     *head = NULL;
// }

void clean_up_linklist(linknode_t *head)
{
    if (head->next == NULL)
    {
        return;
    }
    linknode_t *temp = NULL;
    while (head->next)
    {
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
    temp = NULL;
    free(head);
    head = NULL;
}