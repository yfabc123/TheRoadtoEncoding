#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = ",a,b,c";
    char *token;
    // 第一次调用，传入字符串
    token = strtok(str, ","); 
    // token 指向空字符串，原始字符串变成 "\0apple,orange,banana"
    printf("First token: %s\n", token);
    // 后续调用，传入 NULL
    while (token != NULL)
    {
        token = strtok(NULL, ",");
        if (token != NULL)
        {
            printf("Next token: %s\n", token);
        }
    }
    return 0;
}
