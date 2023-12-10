#include "SinglyLinkedCircularList.h"

loopnode_t *create_empty_looplist()
{
    loopnode_t *head = (loopnode_t *)malloc(sizeof(loopnode_t));
    head->data = 0;
    head->next = head;
    return head;
}
void insert_head_looplist(loopnode_t *head, datatype_t data)
{
    loopnode_t *temp = (loopnode_t *)malloc(sizeof(loopnode_t));
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
}
void printf_data_looplist(loopnode_t *head)
{
    loopnode_t *ptr = head->next;

    while (ptr != head)
    {

        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int is_empty_looplist(loopnode_t *head)
{
    if (head->next == head)
    {
        return 1;
    }
    return 0;
}