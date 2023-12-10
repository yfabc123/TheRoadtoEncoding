#include <stdio.h>
#include <stdlib.h>
typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct LinkQueue
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void insert(LinkQueue *Q, int e)
{
    QueuePtr s = (QNode *)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}
void del(LinkQueue *Q)
{
    if (Q->front == Q->rear)
    {
        printf("空队列无法删除");
    }

    QueuePtr temp = Q->front->next;
    Q->front->next = temp->next;
    if (temp == Q->rear)
    {
        Q->rear = Q->front;
    }
    free(temp);
}
int main()
{

    return 0;
}