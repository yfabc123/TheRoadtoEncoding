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
} loopnode_t;

extern loopnode_t *create_empty_looplist();
extern void insert_head_looplist(loopnode_t *head, datatype_t data);
extern void printf_data_looplist(loopnode_t *head);
extern int is_empty_looplist(loopnode_t *head);
#endif
