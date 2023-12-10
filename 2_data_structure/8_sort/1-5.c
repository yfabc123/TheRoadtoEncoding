#include <stdio.h>
void direct_insert_sort(int *arr, int n)
{

    int i = 0, j = 0;
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        // i至少从下标1开始
        for (j = i; j >= 1 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
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
    int a[] = {8};
    int n = sizeof(a) / sizeof(a[0]);
    output_array_info(a, n);

    direct_insert_sort(a, n);
    output_array_info(a, n);

    return 0;
}
