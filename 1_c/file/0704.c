#include <stdio.h>
#include <malloc.h>
// �����ɽṹ-�ڵ�
typedef struct Node
{
    int n;
    struct Node *next;
} Node;
// ������ʼ��5���ڵ������
Node *create(Node *first)
{
    //first = (Node *)malloc(sizeof(Node)); // �׽ڵ�
    printf("%p\n", first);
    first->n = 0;
    Node *last = first; // ����ָ���½ڵ�

    // ����ʣ��4���ڵ�
    for (int i = 0; i < 4; i++)
    {
        Node *new = (Node *)malloc(sizeof(Node)); // �����½ڵ�
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
