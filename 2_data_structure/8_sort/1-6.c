#include <stdio.h>
// 插入排序
void direct_insert_sort(int *arr, int len)
{
    int i = 0, j = 0, temp = 0;
    for (i = 1; i <= len - 1; i++)
    {
        temp = arr[i];
        for (j = i; j >= 1 && temp < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}
/* 哈希排序:加强版插入排序 多了个增量概念 把数据按照一定增量分成好几批数据
先对这好几批数据进行排列然后在修改增量 增量/2 直到增量<1循环结束
 */

void insert_sort_strong(int *arr, int len)
{
    for (int increment = len / 6; increment >= 1; increment /= 2)
    {
        int i = 0, j = 0, temp = 0;
        for (i = increment; i <= len - 1; i++)
        {
            temp = arr[i];
            for (j = i; j >= increment && arr[j - 1] > temp; j -= increment)
            {
                arr[j] = arr[j - increment];
            }
            arr[j] = temp;
        }
    }
}

void output_array_info(int *p, int plen)
{
    int i = 0;
    for (i = 0; i < plen; i++)
    {
        printf("%4d", p[i]);
    }
    printf("\n");
}
int main()
{
    int a[] = {8, 14, 5, 2, 19, 1, 13, 4, 10, 12};

    int n = sizeof(a) / sizeof(a[0]);
    output_array_info(a, n);

    insert_sort_strong(a, n);
    output_array_info(a, n);

    return 0;
}
