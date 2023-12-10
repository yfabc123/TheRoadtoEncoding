#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef int dataType;
typedef struct
{
    dataType buf[MAX];
    int front;
    int rear;
} circularQueue;
// 创建
circularQueue *create()
{
    circularQueue *head = (circularQueue *)malloc(sizeof(circularQueue));
    memset(head, 0, sizeof(circularQueue));
    return head;
}
// 判满
int isFull(circularQueue *head)
{
    if ((head->rear + 1) % MAX == head->front)
    {
        return 1;
    }
    return 0;
}
// 判满
int isEmpty(circularQueue *head)
{
    if (head->rear == head->front)
    {
        return 1;
    }
    return 0;
}
// 插入数据
void insert(circularQueue *head, dataType data)
{
    if (!isFull(head))
    {
        head->buf[head->rear] = data;
        head->rear = (head->rear + 1) % MAX;
    }
}
// 出队列数据
dataType delete(circularQueue *head)
{
    if (!isEmpty(head))
    {
        dataType temp = head->buf[head->front];
        head->front = (head->front + 1) % MAX;
        return temp;
    }
}
int main()
{
    circularQueue *head = create();
    int i = 0;
    while (!isFull(head))
    {
        insert(head, i++);
    }
    while (!isEmpty(head))
    {
        printf("%d\n", delete (head));
    }
    return 0;
}