#include <stdio.h>
int main(int argc, char *argv[])
{

    char buf[10]={0};
    
    for (size_t i = 0; i < sizeof(buf)/sizeof(buf[0]); i++)
    {
        buf[i] = '1';
    }
   // buf[99]=0;
    FILE *file = fopen("2.txt", "w+");
    fputs(buf,stdout);
    // fwrite(buf,sizeof(buf),1,file);
    return 0;
}
