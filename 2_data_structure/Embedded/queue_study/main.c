#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct a
{
    int a;
    struct a *next;

} Node;
typedef struct
{
    Node *front;
    Node *rear;
} queue;

queue *create()
{
    queue *q = (queue *)malloc(sizeof(queue));
    Node *head = (Node *)malloc(sizeof(Node));
    q->front = head;
    q->rear = head;
    head->next = NULL;
    return q;
}

void insert(queue *q, int a)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    q->rear->next = temp;
    q->rear = temp;
    temp->a = a;
    temp->next = NULL;
}
int del(queue *q)
{
    Node *temp = q->front->next;
    int result = temp->a;
    q->front->next = temp->next;
    free(temp);
    temp = NULL;
    if (q->front->next == NULL)
    {
        q->rear = q->front;
    }
    return result;
}

int main()
{
    queue *q = create();
    insert(q, 1);
    insert(q, 2);
    insert(q, 3);
    Node *p = q->front->next;
    while (p)
    {
        printf("%d", p->a);
        p = p->next;
    }
    del(q);
    del(q);
    del(q);
    insert(q, 3);
    insert(q, 2);
    p = q->front->next;
    while (p)
    {
        printf("%d", p->a);
        p = p->next;
    }
    return 0;
}