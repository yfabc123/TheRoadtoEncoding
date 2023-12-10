#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} List, *LIST;

int main(int argc, char const *argv[])
{
    // List a;
    // a.data = 1;
    // LIST b=(LIST)malloc(sizeof(LIST));
    // printf("%ld\n",sizeof(LIST));
    // b->data=3;
    // printf("%d", b->data);
    LIST a;
 //   a.data=3;

    int *p;
    printf("%d",sizeof(a));
    return 0;
}
