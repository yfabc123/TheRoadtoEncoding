#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef int dataType_t;
typedef struct
{
    dataType_t a[MAX];
    int length; // 既表示当前的长度也表示下次可以插入的位置
} seqList_t;

// 创建
seqList_t *create()
{
    seqList_t *seqList = (seqList_t *)malloc(sizeof(seqList_t));
    memset(seqList, 0, sizeof(seqList_t));
}
// 插入
void inset(seqList_t *seqlist, dataType_t data)
{
    if (seqlist->length < MAX)
    {
        seqlist->a[seqlist->length] = data;
        seqlist->length++;
        printf("已插入数据:%d\n", data);
    }
    else
    {
        printf("满了\n");
    }
}
// 查找
void find(seqList_t *seqList, dataType_t data)
{
    for (int i = 0; i < seqList->length; i++)
    {
        if (data == seqList->a[i])
        {
            printf("找到了索引是:%d\n", i);
            return;
        }
    }

    printf("没找到\n");
}
// 删除指定元素的同时所有元素前移
void del(seqList_t *seqlist, dataType_t data)
{
    int index = -1;
    for (int i = 0; i < seqlist->length; i++)
    {
        if (data != seqlist->a[i])
        {
            index++;
            seqlist->a[index] = seqlist->a[i];
        }
    }
    // 遍历完之后index就是最后的数据所在下标
    seqlist->length = index + 1;
}
void outPut(seqList_t *seqlist)
{
    for (int i = 0; i < seqlist->length; i++)
    {
        printf("%d\n", seqlist->a[i]);
    }
}
int main()
{
    seqList_t *seqlist = create();
    inset(seqlist, 1);
    inset(seqlist, 4);
    inset(seqlist, 3);
    inset(seqlist, 4);
    inset(seqlist, 3);
    inset(seqlist, 4);
    inset(seqlist, 1);
    find(seqlist, 4);
    // outPut(seqlist);

    del(seqlist, 4);
    outPut(seqlist);
    return 0;
}