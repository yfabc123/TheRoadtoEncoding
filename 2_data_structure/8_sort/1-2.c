#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[] = "decba";
    int len = strlen(str);
    printf("%s\n", str);

    for (int i = 0; i < len ; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    printf("%s", str);

    return 0;
}