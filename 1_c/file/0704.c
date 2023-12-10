#include <stdio.h>
#include <malloc.h>
// 链表构成结构-节点
typedef struct Node
{
    int n;
    struct Node *next;
} Node;
// 创建初始有5个节点的链表
Node *create(Node *first)
{
    //first = (Node *)malloc(sizeof(Node)); // 首节点
    printf("%p\n", first);
    first->n = 0;
    Node *last = first; // 不断指向新节点

    // 创建剩下4个节点
    for (int i = 0; i < 4; i++)
    {
        Node *new = (Node *)malloc(sizeof(Node)); // 创建新节点
        new->n = i + 1;
        last->next = new;
        last = new;
    }
    last->next = NULL;
    return first;
}
int main()
{
    Node *a;
    printf("%p\n", a);
    create(a);
    Node *p = a;
    // printf("%p\n", a);
    // printf("%p\n", p);
    // printf("%d\n", a->n);
    //  do
    //  {
    //      int temp = p->n;
    //      printf("%d\n", temp);
    //      p = p->next;
    //  } while (p != NULL);
}
