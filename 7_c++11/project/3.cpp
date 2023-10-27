#include <stdio.h>

int main()
{
     //printf("\033[2J");

    for (int i = 0; i < 11; i++)
    {
        fprintf(stderr, "\033[%d;%dH\033[45m*\033[0m", 5 + i, 10 + i);  
        fprintf(stderr, "\033[%d;%dH\033[42m*\033[0m", 10, 10 + i);    
        fprintf(stderr, "\033[%d;%dH\033[44m*\033[0m", 15 - i, 10 + i); 
        fprintf(stderr, "\033[%d;%dH\033[43m*\033[0m", 5 + i, 15);    
        if (i == 5)
        {
            fprintf(stderr, "\033[%d;%dH\033[41m*\033[0m", 10, 15); 
        }
    }

    return 0;
}