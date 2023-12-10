#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int dataType;
typedef struct node
{
    struct node *next;
    dataType data;
} node_t;
typedef struct
{
    node_t *rear;
    node_t *front;
} linkedqueue_t;
// 创建
linkedqueue_t *create()
{
    linkedqueue_t *head = (linkedqueue_t *)malloc(sizeof(linkedqueue_t));
    node_t *virhead = (node_t *)malloc(sizeof(node_t));
    virhead->next = NULL;
    head->rear = virhead;
    head->front = virhead;
    return head;
}
// 插入
void insert(linkedqueue_t *head, dataType data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    head->rear->next = node;
    head->rear = node;
}
// 判空
int isEmpty(linkedqueue_t *head)
{
    if (head->front == head->rear)
    {
        return 1;
    }
    return 0;
}
// 出队列 需要特殊处理下 当只剩最后一个元素时
dataType delete(linkedqueue_t *head)
{
    if (!isEmpty(head))
    {
        node_t *temp = head->front->next; // 待出的节点
        dataType data = temp->data;
        head->front->next = temp->next;
        if (temp->next == NULL) // 如果节点是最后一个节点
        {
            head->rear = head->front; // 尾指针指向虚拟头节点
        }
        temp->next = NULL;
        free(temp);
        temp = NULL;
        return data;
    }
    return -1;
}
int main()
{
    linkedqueue_t *head = create();
    for (int i = 0; i < 5; i++)
    {
        insert(head, i);
    }
    while (!isEmpty(head))
    {
        printf("%d\n", delete (head));
    }
    for (int i = 5; i < 10; i++)
    {
        insert(head, i);
    }
    while (!isEmpty(head))
    {
        printf("%d\n", delete (head));
    }
    return 0;
}