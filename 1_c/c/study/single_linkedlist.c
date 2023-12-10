#include <stdio.h>
#include <stdlib.h> // Include the necessary header for malloc

typedef struct Node
{
    int n;
    struct Node *next;
} Node;

// 创建初始有5个节点的链表
void create(Node **first)
{
    *first = (Node *)malloc(sizeof(Node)); // 首节点
    (*first)->n = 0;
    Node *new, *last;
    last = *first; // 不断指向新节点
    // 创建剩下4个节点
    for (int i = 0; i < 4; i++)
    {
        new = (Node *)malloc(sizeof(Node)); // 创建新节点
        new->n = i + 1;
        last->next = new;
        last = new;
    }
    last->next = NULL;
}

// GetElem 单链表的读取
Node *GetElem(int i, Node *a)
{
    Node *p = a;
    int n = 0;
    while (p->next != NULL && n < i)
    {
        p = p->next;
        n = n + 1;
    }
    if (n < i)
    {
        printf("i不在范围内");
        // return NULL;
    }
    else if (n == i)
    {
        printf("找到了该节点的值是：%d", p->n);
        return p;
    }
}

// 插入 i：插入的位置  a：原链表首节点  b：要保存的数据
void insert(int i, Node **a, int b)
{
    Node *temp = *a; // 滚动指针
    int n = 0;       // 计数器
    Node *new;
    if (i == 0)
    {

        new = (Node *)malloc(sizeof(Node));
        new->next = *a;

        new->n = b;
        *a = new;
        temp = *a;
    }

    else
    {
        while (n < i - 1 && temp->next != NULL)
        {
            temp = temp->next;
            n++;
        }
        if (temp->next == NULL)
        {
            printf("输入不合理\n");
        }
        else
        {
            new = (Node *)malloc(sizeof(Node));
            new->n = b;

            new->next = temp->next;
            temp->next = new;
        }
    }
}
// 删除指定节点
void Delete(int i, Node **a)
{
    int n = 0;
    Node *p = *a; // 遍历指针
                  // 当删除的是第一个元素时
    if (i == 0)
    {
        *a = (*a)->next;
        free(p);
    }
    else // 删除非第一个元素
    {
        while (n < i - 1 && p->next != NULL)
        {
            p = p->next;
            n++;
        }
        if (p->next == NULL)
        {
            printf("范围不对\n");
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
}

// 遍历链表
void pr(Node *a)
{
    int i = 0;
    Node *p = a;
    while (p != NULL)
    {
        printf("%d\n", p->n);
        p = p->next;
        i++;
    }
}

// 删除单链表
void clear(Node **a)
{
    int i = 0;
    Node *p = *a;
    Node *temp;
    while (p->next != NULL)
    {
        temp = p;
        p = p->next;

        free(temp);
    }
}

int main()
{
    Node *a = NULL; // 指向node指针的指针
    create(&a);

    insert(0, &a, 6);

    // printf("%d",a->n);

    // Delete(1, &a);
    // pr(a);
    clear(&a);
    printf("%d", a->next);
    return 0;
}