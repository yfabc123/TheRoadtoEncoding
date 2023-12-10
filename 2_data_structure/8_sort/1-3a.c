#include <stdio.h>
#include <stdlib.h>
int main()
{

    int arr[] = {1, 2, 2, 4};
    arr[1] ^= arr[1];
    arr[1] ^= arr[1];
    arr[1] ^= arr[1];

    printf("%d %d", arr[1]);
    return 0;
}