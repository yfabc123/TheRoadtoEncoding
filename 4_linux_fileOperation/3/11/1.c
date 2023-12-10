#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    float numbers[5] = {1.1, 1.2, 1.3, 1.4, 1.5};
    float result[5];
    size_t witems = 0, ritems = 0;
    if (argc != 2)
    {
        fprintf(stderr, "参数没加!");
        return -1;
    }
    fp = fopen(argv[1], "w+");
    if (NULL == fp)
    {
        perror("fopen:");
        return -1;
    }

    witems = fwrite(numbers, sizeof(float), sizeof(numbers)/sizeof(numbers[0]), fp);
    if (witems < 5)
    {
        perror("fwrite:");
        return -1;
    }
    fseek(fp, 0, SEEK_SET);
    ritems = fread(result, sizeof(float), sizeof(result)/sizeof(result[0]), fp);
    if (ritems != 5)
    {
        perror("fread:");
        return -1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%f\n", result[i]);
    }
    fclose(fp);
    return 0;
}
