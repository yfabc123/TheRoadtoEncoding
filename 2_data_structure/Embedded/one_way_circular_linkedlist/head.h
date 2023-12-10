#ifndef a
#define a
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node

{
    int number;
    struct node *next;
} List;

extern List *create();
 
extern void del(List *l);

#endif