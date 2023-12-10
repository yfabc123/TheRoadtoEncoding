#ifndef a
#define a
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct node
{
  int n;
struct node *next;
} single_linked_list;
extern single_linked_list *create();
extern void insert(single_linked_list *list, int number);
extern void prinf_list(single_linked_list *l);
extern int is_full(single_linked_list *list);
extern void delete(single_linked_list * list, int a);
extern void fun(single_linked_list *l);
extern void rm(single_linked_list *l);
#endif