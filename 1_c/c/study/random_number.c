#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    // 设置随机数种子
    srand(getpid());
    int i=0;
    while (i<3)
    {
         printf("%d\n",rand()%9+1);
         i++;
    }
    int a=3;
    int b=a+NULL;
printf("%d",a+NULL);
    
    return 0;
}
