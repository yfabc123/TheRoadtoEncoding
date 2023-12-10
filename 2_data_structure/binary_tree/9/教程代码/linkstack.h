#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitree.h"


//结点类型的设计

typedef bitree_t *datatype_t;

typedef struct node
{
	datatype_t data;
	struct node *next;
}linknode_t;

//栈头类型的设计

typedef struct
{
	linknode_t *top;//栈顶指针
	int n; //记录当前栈种元素的个数
}linkstack_t;

extern linkstack_t *create_empty_linkstack();
extern int is_empty_linkstack(linkstack_t *s);
extern void push_linkstack(linkstack_t *s,datatype_t data);
extern datatype_t pop_linkstack(linkstack_t *s);
extern datatype_t get_top_data(linkstack_t *s);
#endif
