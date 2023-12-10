#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX 10
typedef struct
{
    int *table;
    int len;
} Hash;
Hash *create()
{
    Hash *hash = (Hash *)malloc(sizeof(Hash));
    hash->table = (int *)malloc(sizeof(int) * 10);
    hash->len = 0;
    for (int i = 0; i < MAX; i++)
    {
        hash->table[i] = -1;
    }
    return hash;
}
void insert(Hash *hash, int key)
{
    int index = key % MAX;
    while (hash->table[index] != -1)
    {
        index = (index + 1) % MAX;
    }
    hash->table[index] = key;
    hash->len++;
}
int find(Hash *hash, int key)
{
    int index = key % MAX;
    for (int i = 0; i < MAX; i++) // 找10次数
    {
        if (hash->table[index] != key)
        {
            index = (index + 1) % MAX;
        }
        else
        {
            return index;
        }
    }
    return -1;
}
void show(Hash *hash)
{
    for (int i = 0; i < hash->len; i++)
    {
        printf("%d\n", hash->table[i]);
    }
}
int main()
{
    int data[MAX] = {13, 4, 27, 28, 26, 3, 38, 16, 14, 19};
    Hash *hash = create();
    for (int i = 0; i < MAX; i++)
    {
        insert(hash, data[i]);
    }
    show(hash);
    printf("%d", find(hash, 16));
    free(hash);
    return 0;
}