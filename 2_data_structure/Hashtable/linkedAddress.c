#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX 10
typedef struct node
{
    int data;
    struct node *next;
} HashTable;
HashTable **create()
{
    HashTable **hashTable = (HashTable **)malloc(sizeof(HashTable *) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        hashTable[i] = NULL;
    }
    return hashTable;
}
// 按照顺序插入
void insert(HashTable **hashTable, int tempData)
{
    int index = tempData % MAX;
    HashTable *node = (HashTable *)malloc(sizeof(HashTable));
    node->data = tempData;
    node->next = NULL;
    HashTable *ptr = hashTable[index]; // 迭代器
    HashTable *ptrSlow = NULL;         // 满指针保留上一次的
    while (ptr && tempData > ptr->data)
    {
        ptrSlow = ptr;
        ptr = ptr->next;
    }
    if (ptrSlow)
    {
        node->next = ptrSlow->next;
        ptrSlow->next = node;
    }
    else
    {
        node->next = hashTable[index];
        hashTable[index] = node;
    }
}
int find(HashTable **hashTable, int tempdata)
{
    int index = tempdata % MAX;
    HashTable *ptr = hashTable[index];
    while (ptr && ptr->data != tempdata)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        return -1; // 没找到
    }
    return 1;
}
void show(HashTable **hashTable)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("hashTable[%d]:", i);
        HashTable *ptr = hashTable[i];
        while (ptr)
        {
            printf("%-5d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
int main()
{
    int data[] = {10, 13, 13, 4, 27, 28, 26, 3, 38, 16, 14, 19, 1, 2};
    HashTable **hashTable = create();
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        insert(hashTable, data[i]);
    }
    show(hashTable);
    printf("%d", find(hashTable, 1));
    return 0;
}