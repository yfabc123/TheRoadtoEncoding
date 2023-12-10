#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char dataType;
typedef struct node
{
    struct node *next;
    dataType data;
} node_t;
typedef struct
{
    node_t *top;
    dataType count;
} stack;
stack *create()
{
    stack *head = (stack *)malloc(sizeof(stack));
    head->top = NULL;
    head->count = 0;
    return head;
}
void insert(stack *head, dataType data)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->data = data;
    temp->next = head->top;
    head->top = temp;
    head->count++;
}
dataType pop(stack *head)
{
    node_t *temp = head->top;
    dataType result = temp->data;
    head->top = temp->next;
    head->count--;
    free(temp);
    return result;
}
int isEmpty(stack *head)
{
    if (head->count == 0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    stack *head = NULL;
    dataType array[] = {'a', 'n', 'i', 'h', 'c'};
    head = create();
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        insert(head, array[i]);
    }
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("%c",pop(head));
    }
    return 0;
}
