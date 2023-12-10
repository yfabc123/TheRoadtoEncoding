#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 数据元素的类型
typedef char data_t;
#define MAX 3
// 顺序栈的类型
typedef struct stack
{
    // 数组存储数据元素
    data_t buf[MAX];
    // 记录当前栈顶位置的栈顶指针(下标)
    int top;
} stack;
stack *create()
{
    stack *head = (stack *)malloc(sizeof(stack));
    memset(head->buf, 0, sizeof(head->buf));
    head->top = -1;
    return head;
}
void push(stack *head, data_t data)
{
    // 判满
    if (head->top != MAX-1)
    {
        head->buf[++head->top] = data;
    }
    else
    {
        printf("栈满!\n");
    }
}
data_t pop(stack *head)
{
    if (head->top != -1)
    {
        return head->buf[head->top--];
    }
}
int main()
{
    data_t data[] = {'a', 'n', 'i', 'h', 'c', ' ', 'e', 'v', 'o', 'l', ' ', 'I', 0};
    stack *head = create();
    for (int i = 0; i < strlen(data); i++)
    {
        push(head, data[i]);
    }
    while (head->top != -1)
    {
        printf("%c\n",pop(head));
    }
    return 0;
}