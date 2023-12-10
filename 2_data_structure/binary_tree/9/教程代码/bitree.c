#include "bitree.h" 
#include "linkstack.h"

bitree_t *create_binatry_tree(int n)
{
	bitree_t *root = NULL;

	root = (bitree_t *)malloc(sizeof(bitree_t));
	memset(root,0,sizeof(bitree_t));

	root->n = n;
	root->lchild = root->rchild = NULL;


	printf("Input %d node data : ",n);
	scanf("%c",&(root->data));

	//清除缓冲区数据
	while(getchar() != '\n');
	
	//左孩子存在条件
	if(2 * n <= N)
	{
		root->lchild = create_binatry_tree(2 * n);	
	}

	//左孩子存在条件
	if(2 * n  + 1 <= N)
	{
		root->rchild = create_binatry_tree(2 * n + 1);	
	}

	return root;
}

//前序遍历
void pre_order(bitree_t *root)
{
	if(root == NULL)
		return ;

	linkstack_t *s = create_empty_linkstack();
	bitree_t *temp = root;

	while(temp != NULL || !is_empty_linkstack(s))
	{
		while(temp != NULL)        
		{
			printf("(%d : %c) ",temp->n,temp->data); //根
			push_linkstack(s,temp);
			temp = temp->lchild;
		}

		if(!is_empty_linkstack(s))
		{
			temp = pop_linkstack(s);        
			temp = temp->rchild;
		}
	}

    free(s);
}

//中序遍历
void in_order(bitree_t *root)
{
	if(NULL == root)
		return ;

	in_order(root->lchild); //左
	printf("(%d : %c) ",root->n,root->data); //根
	in_order(root->rchild); //右
}

//后序遍历
void post_order(bitree_t *root)
{
	if(NULL == root)
		return ;

	post_order(root->lchild); //左
	post_order(root->rchild); //右
	printf("(%d : %c) ",root->n,root->data); //根
}
