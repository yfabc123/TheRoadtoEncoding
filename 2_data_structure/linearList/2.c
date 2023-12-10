#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    for (int i = 0; i < 4; i++)
    {
        if (i >= 0)
        {
            printf("%d\n", i);
            continue; // 我以为会跳过i++ 卧槽
        }
    }
    return 0;
}

