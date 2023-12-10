#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[] = "gadecbf";
    int len = strlen(str);
    printf("%s\n", str);

    for (int i = 0; i < len; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (str[j] < str[min_index])
                min_index = j;
        }
        if (i != min_index)
        {

            str[i] ^= str[min_index];
            str[min_index] ^= str[i];
            str[i] ^= str[min_index];
        }
    }

    printf("%s\n", str);

    return 0;
}