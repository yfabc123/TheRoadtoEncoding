
#include <stdio.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct 
{
    LinkStackPtr top;
    int count;
}LinkStack;


int main()
{

    return 0;
}