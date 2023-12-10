#include <stdio.h>
#include <stdlib.h>
typedef struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;
tree_node *create()
{
    int temp;
    scanf("%d", &temp);
    //   getchar();
    if (temp == 0)
    {
        return NULL;
    }
    else
    {
        tree_node *node = (tree_node *)malloc(sizeof(tree_node));
        node->data = temp;
        node->left = create();
        node->right = create();
        return node;
    }
}
// 前序遍历算法
void show(tree_node *v)
{
    if (!v)
    {
        return;
    }
    else
    {
        printf("%d", v->data);
        show(v->left);
        show(v->right);
    }
}

int main()
{
    tree_node *tree_node = create();
    show(tree_node);
    return 0;
}