#include <stdio.h>
#include <stdlib.h>
int removeElement(int *nums, int numsSize, int val)
{
    int i = 0, j = 0; // j-1作为最后索引
    for (; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    numsSize = j;
    return numsSize;
}
int main()
{
    int  arr[7]={1,2,3,3,4,3,5};

    int val=0;
    printf("%d",removeElement(arr,7,3));
    return 0;
}