#include <stdio.h>
#include <stdlib.h>
int find(char *a, char *b)
{
    int i = -1;   // 默认没找到
    int temp = 0; // 遍历字符串a的索引值
    for (char *temp_a = a; *temp_a != '\0'; temp_a++, temp++)
    {
        char *temp_b = b;
        char *temp_aa = temp_a;
        while (*temp_aa == *temp_b && *temp_a != '\0' && *temp_b != '\0')
        {
            temp_aa++;
            temp_b++;
        }
        if (*temp_b == '\0')
        {
            i = temp;
            break;
        }
    }
    return i;
}
int main()
{

    int a = find("abcddfg", "dfg");
    printf("%d", a);
    return 0;
}