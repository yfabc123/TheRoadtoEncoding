#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head)
{
    struct ListNode *p1, *p2, *p3, *p4; // p1 遍历 p2 保存p1.next p3遍历 p4 保存p3.next
    if (head)
    {
        p1 = head->next;
        if (p1)
        {
            p2 = p1->next;
        }
        head->next = NULL;
        p3 = head;
        p4 = head;
    }

    while (p1)
    {
        if (head->val > p1->val)
        {
            p1->next = head;
            head = p1;
        }
        else
        {
            while (p3 && p1->val > p3->val) // 上来就进入循环 =p1>head
            {
                p4 = p3;
                p3 = p3->next;
            }
            p1->next = p3;
            p4->next = p1;
        }

        p3 = p4 = head;
        p1 = p2;
        if (p1)
        {
            p2 = p2->next;
        }
    }
    return head;
}
int main()
{
    struct ListNode *pa = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pb = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pc = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pd = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *pe = (struct ListNode *)malloc(sizeof(struct ListNode));

    pa->val = 4;
    pb->val = 2;
    pc->val = 1;
    pd->val = 3;
    pe->val = 5;
    pa->next = pb;
    pb->next = pc;
    pc->next = pd;
    pd->next = pe;
    pe->next = NULL;
    struct ListNode *temp = sortList(pa);
    struct ListNode *p = temp;
    while (p)
    {
        printf("%d ", p->val);
        p = p->next;
    }

    return 0;
}