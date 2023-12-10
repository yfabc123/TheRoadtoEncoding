#include <stdio.h>


// 三个数取中间值
int find_avg(int a, int b, int c)
{
    if ((a > b && a <= c) || (a <= b && a >= c))
    {
        return a;
    }
    else if ((b > a && b <= c) || (b <= a && b >= c))
    {
        return b;
    }
    else
        return c;
}

void quick_sort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    // 在三个数里面挑一个中间值
    int right = end;
    int left = start;
    int mid_index = (start + end) / 2;
    int avg = find_avg(arr[start], arr[end], arr[mid_index]);
    if (avg == arr[end])
    {
        int temp = arr[end];
        arr[end] = arr[start];
        arr[start] = temp;
    }
    else if (avg == arr[mid_index])
    {
        int temp = arr[mid_index];
        arr[mid_index] = arr[start];
        arr[start] = temp;
    }
    int mid_val = arr[mid_index];
    while (left < right)
    {
        while (left < right && arr[right] >= mid_val)
        {
            right--;
        }
        if (left < right)
        {

            arr[left] = arr[right];
            left++;
        }
        while (left < right && arr[left] <= arr[right])
        {
            left++;
        }
        if (left < right)
        {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = mid_val;

    quick_sort(arr, start, left - 1);
    quick_sort(arr, left + 1, end);
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
    int a[] = {-74, 48, -20, 2, 10, -84, -5, -9, 11, -24, -91, 2, -71, 64, 63, 80, 28, -30, -58, -11, -44, -87, -22, 54, -74, -10, -55, -28, -46, 29, 10, 50, -72, 34, 26, 25, 8, 51, 13, 30, 35, -8, 50, 65, -6, 16, -2, 21, -78, 35, -13, 14, 23, -3, 26, -90, 86, 25, -56, 91, -13, 92, -25, 37, 57, -20, -69, 98, 95, 45, 47, 29, 86, -28, 73, -44, -46, 65, -84, -96, -24, -12, 72, -68, 93, 57, 92, 52, -45, -2, 85, -63, 56, 55, 12, -85, 77, -39};

    // int a[] = {5, 1, 1, 2, 0, 0};
    int n = sizeof(a) / sizeof(a[0]);
    output_array_info(a, n);

    quick_sort(a, 0, n - 1);
    output_array_info(a, n);

    return 0;
}
