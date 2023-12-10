#include <stdio.h>
int find(int a, int b[], int length)
{
    int result = -1;
    for (int i = 0; i < length; i++)
    {
        if (b[i] == a)
        {
            result = b[i];
            break;
        }
    }
    return result;
}
int main()
{
    int arr[3] = {1, 2, 3};
    printf("%d", ind(4, arr, 3));

    return 0;
}
