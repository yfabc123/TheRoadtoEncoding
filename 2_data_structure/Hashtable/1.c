#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node
{
    datatype number;
    struct node *next;
} hash_node;
// 创建哈希表
hash_node **create()
{
    hash_node **hash_array = (hash_node **)malloc(7 * sizeof(hash_node *));
    memset(hash_array, 0, 7 * sizeof(hash_node *));
    for (int i = 0; i < 7; i++)
    {
        hash_array[i] = NULL; // 初始化数组中的指针为NULL
    }
    return hash_array;
}
// 插入哈希表
hash_node **insert(hash_node **hash_array, int n)
{
    int index = n % 7;
    // 创建 一个节点存放数据
    hash_node *node = (hash_node *)malloc(sizeof(hash_node));
    node->next = NULL;
    node->number = n;
    hash_node **p = NULL; // 遍历指针
    for (p = &hash_array[index]; *p; p = &((*p)->next))
    {
        if (n < (*p)->number)
        {
            break;
        }
    }
    // 当遍历到节点的数据大于插入的数据时
    node->next = *p;
    *p = node;
    return hash_array;
}
// 打印哈希表
void printf_hash(hash_node **hash_array)
{
    for (int i = 0; i < 7; i++)
    {
        printf("index:%d包含的数据", i);
        for (hash_node **p = &hash_array[i]; *p; p = &((*p)->next))
        {
            printf("%d ", (*p)->number);
        }
        printf("\n");
    }
}
// 判断给定数据是否存在哈希表中
int find(hash_node **hash_array, int n)
{
    int index = n % 7;
    for (hash_node **p = &hash_array[index]; *p; p = &((*p)->next))
    {
        if (n == (*p)->number)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    datatype data[7] = {10, 22, 13, 11, 24, 7, 14};
    hash_node **hash_array = create();
    for (int i = 0; i < 7; i++)
    {
        insert(hash_array, data[i]);
    }
    printf_hash(hash_array);
    int result = find(hash_array, 14);
    if (result)
    {
        printf("有");
    }
    else
        printf("没");
    return 0;
}