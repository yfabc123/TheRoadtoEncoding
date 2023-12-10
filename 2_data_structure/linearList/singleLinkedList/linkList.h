// head.h
#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype_t; // 用户自定义数据类型

typedef struct node
{
    datatype_t data;   // 数据域保存有效的数据
    struct node *next; // 保存下一个结点的地址
} linknode_t;

extern linknode_t *create_empty_linklist();
extern void insert_head_linklist(linknode_t *head, datatype_t data);
extern void printf_data_linklist(linknode_t *head);
extern void insert_tail_linklist(linknode_t *head, datatype_t data);
extern void insert_order_linklist(linknode_t *head, datatype_t data);
extern void delete_data_linklist(linknode_t *head, datatype_t data);
extern void reverse_data_linklist(linknode_t *head);
extern void clean_up_linklist(linknode_t *head);
#endif
