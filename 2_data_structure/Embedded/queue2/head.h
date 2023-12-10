#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype_linknode;

//结点
typedef struct node_linkqueue
{
	datatype_linknode data;
	struct node_linkqueue *next;
}linknode_t;


//=========================链式队列==================================
//队列头
typedef struct
{
	linknode_t *front;
	linknode_t *rear;
}linkqueue_t;

extern linkqueue_t *create_empty_linkqueue(); //创建空链式队列
extern int is_empty_linkqueue(linkqueue_t *q); //判断队列是否为空
extern void enter_linkqueue(linkqueue_t *q,datatype_linknode data); //向队列添加数据
extern datatype_linknode out_linkqueue(linkqueue_t *q); //从队列取出数据


//==============================链式栈============================
//栈头
typedef struct 
{
	linknode_t *top;
	int n;
}linkstack_t;

extern linkstack_t *create_empty_linkstack(); //创建空链式栈
extern int is_empty_linkstack(linkstack_t *s); //判断链式栈是否为空
extern void push_linkstack(linkstack_t *s,datatype_linknode data); //压入数据
extern datatype_linknode pop_linkstack(linkstack_t *s); //弹出数据
extern datatype_linknode get_top_data(linkstack_t *s); //取得栈头数据

#endif
