#ifndef __BITREE_H__
#define __BITREE_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define N 6

typedef char data_t;

typedef struct bitree
{
	int n; //保存编号
	data_t data; //保存字符
	struct bitree *lchild; //保存左孩子的地址
	struct bitree *rchild; //保存右孩子的地址
}bitree_t;


extern bitree_t *create_binatry_tree(int n);
extern void pre_order(bitree_t *root);
extern void in_order(bitree_t *root);
extern void post_order(bitree_t *root);
#endif
