#include <stdio.h>

// 定义一个结构 Component 然后定义一个数组 每个元素由Component构成
typedef struct
{
    int data;
    int cur;
} Component, StaticLinkList[5];
// 初始化静态链表
void InitList(StaticLinkList sapce)
{
    for (int i = 0; i < 5; i++)
    {
        sapce[i].cur = i + 1;
    }
    sapce[4].cur = 0;
}
// 找备用元素
int Malloc_SSL(StaticLinkList space)
{
    int i = space[0].cur; // 找到第一个空闲元素的位置
    if (i)
    {
        space[0].cur = space[i].cur; // 该空闲元素的下一个元素成为第一个空闲元素
    }
    return i;
}
// 插入数据逻辑
void Insert(StaticLinkList L, int i)
{
    int index = Malloc_SSL(L); // 找到第一个空闲元素索引
    L[index].data = i;         // 写入数据
    L[index].cur = 0;          // 刚插入的元素属于最后一个元素
}
int main()
{
    // 创建一个单链表 存放四个元素
    StaticLinkList a;
    InitList(a);
    int one;
    one = Malloc_SSL(a); // 找到空闲索引
    a[one].data = 3;

    one = Malloc_SSL(a); // 找到空闲索引
    a[one].data = 14;
    one = Malloc_SSL(a); // 找到空闲索引
    a[one].data = 11;
    one = Malloc_SSL(a); // 找到空闲索引
    a[one].data = 7;

    return 0;
}
