#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node
{
    int number;
    struct Node *next;
} Node;

typedef struct Stack
{
    int top;
    Node *ptr;
} Stack;
// 创建一个栈开始只有一个节点
Stack *create()
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->number = 0;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = 0;
    stack->ptr = node;
    return stack;
}
// 入栈
void insert(Stack *a, int b)
{
    if (a->ptr->number == 0)
    {
        a->ptr->number = b;
    }
    else
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->number = b;
        new->next = a->ptr;
        a->ptr = new;
        a->top++;
    }
}
// 出栈
void delete(Stack *a)
{

    if (a->top != 0)
    {
        Node *temp = a->ptr;
        a->ptr = a->ptr->next;
        a->top--;
        free(temp);
    }
    else
        printf("删除不了");
}
// 遍历栈
void show(Stack *a)
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->ptr = a->ptr;
    temp->top = a->top;
    while (temp->top >= 0)
    {
        printf("第%d个数是%d\n", temp->top, temp->ptr->number);

        temp->ptr = temp->ptr->next;
        temp->top--;
    }
}

int main()
{
    srand(getpid());
    Stack *s = create();
    // 插入测试
    for (int i = 0; i < 3; i++)
    {
        int n = rand() % 9 + 1;
        printf("随机生成的是：%d\n", n);
        insert(s, n);
    }
    show(s);

    // 删除测试
    delete (s);
    show(s);
    printf("%d", s->top);
    return 0;
}