#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int minute = 0; // 记录分钟数 队列每删除一次数据+1

typedef struct
{
    int ball_queue[28];
    int head;
    int tail;
} queue1;

typedef struct
{
    int ball_stack_1[4];
    int ball_stack_2[11];
    int ball_stack_3[11];
    int top1;
    int top2;
    int top3;
} stack;
queue1 *create_queue();
int is_empty(queue1 *q);
int is_full(queue1 *q);
void insert_queue(queue1 *q, int i);
void delete_queue(queue1 *q, stack *stack);
int status_queue(queue1 *q);
stack *create_stack();
void stack_insert(stack *s, int i, queue1 *q);

// 创建队列
queue1 *create_queue()
{
    queue1 *q = (queue1 *)malloc(sizeof(queue1));
    memset(q, 0, sizeof(queue1));
    q->head = 0;
    q->tail = 0;
}

// 队列判空逻辑
int is_empty(queue1 *q)
{
    return q->head == q->tail ? 1 : 0;
}

// 队列判满逻辑
int is_full(queue1 *q)
{
    return (q->tail + 1) % 28 == q->head ? 1 : 0;
}

// 队列插入数据逻辑
void insert_queue(queue1 *q, int i)
{

    q->ball_queue[q->tail] = i;
    q->tail = (q->tail + 1) % 28;
}
// 队列删除数据逻辑 删除同时将数据给栈
void delete_queue(queue1 *q, stack *stack)
{
    minute++;
    int temp = q->ball_queue[q->head];
    q->head = (q->head + 1) % 28;
    stack_insert(stack, temp, q);
}

// 创建栈
stack *create_stack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    memset(s, 0, sizeof(stack));
    s->top1 = s->top2 = s->top3 = -1;
}
// 入栈处理逻辑
void stack_insert(stack *s, int i, queue1 *q)
{
    if (s->top1 < 3)
    {
        s->top1++;
        s->ball_stack_1[s->top1] = i;
    }
    else
    { // 栈1满需清数据同时返回给队列
        while (s->top1 > -1)
        {
            insert_queue(q, s->ball_stack_1[s->top1--]);
        }
        // 栈2不满时接受i
        if (s->top2 < 10)
        {
            s->top2++;
            s->ball_stack_2[s->top2] = i;
        }
        else
        { // 栈2满了清数据同时返回给队列
            while (s->top2 > -1)
            {
                insert_queue(q, s->ball_stack_2[s->top2--]);
            }
            // 栈3不满接收i
            if (s->top3 < 10)
            {
                s->top3++;
                s->ball_stack_3[s->top3] = i;
            }
            else // 栈3满了的话清数据同时返回给队列
            {
                while (s->top3 > -1)
                {
                    insert_queue(q, s->ball_stack_3[s->top3--]);
                }
                insert_queue(q, i);
            }
        }
    }
}

// 判断队列是否是原状态
int status_queue(queue1 *q)
{
    for (int i = q->head, j = 1; j <= 27; i = (i + 1) % 28, j++)
    {
        if (q->ball_queue[i] != j)
        {

            return 0;
        }
    }

    return 1;
}

int main()
{

    queue1 *q = create_queue();

    for (int i = 1; i <= 27; i++)
    {
        insert_queue(q, i);
    }
    stack *s = create_stack();
    minute = 0;

    do
    {
        delete_queue(q, s);
    } while (!status_queue(q));
    printf("%d", minute);

    return 0;
}