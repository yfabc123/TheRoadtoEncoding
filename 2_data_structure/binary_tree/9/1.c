#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int number;
    struct node *lchild;
    struct node *rchild;
} tree;

typedef struct stack_list
{
    struct stack_node *top; // 指向栈顶
} stack_list;
typedef struct stack_node
{
    tree *tree_node; // 存放树节点
    struct stack_node *next;
} stack_node;
// 入栈
stack_list *insert_stack_list(stack_list *stack_list, tree *tree_para)
{
    stack_node *node = (stack_node *)malloc(sizeof(stack_node));
    node->next = stack_list->top;
    node->tree_node = tree_para;
    stack_list->top = node;
    return stack_list;
}
// 出栈
tree *delete_stack_list(stack_list *stack_list)
{
    tree *temp = NULL;
    if (stack_list->top)
    {
        temp = stack_list->top->tree_node;
        stack_node *temp_stack_node = stack_list->top;
        stack_list->top = temp_stack_node->next;
        free(temp_stack_node);
    }
    return temp;
}
// 递归创建完全二叉树
tree *create(int n, int max)
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->number = n;
    temp->lchild = NULL; // 初始化左子节点指针
    temp->rchild = NULL; // 初始化右子节点指针

    if (2 * n <= max)
    {
        temp->lchild = create(2 * n, max);
    }

    if (2 * n + 1 <= max)
    {
        temp->rchild = create(2 * n + 1, max);
    }

    return temp;
}

// 用栈实现前序遍历二叉树
void printf_front(tree *tree1)
{
    // 创建一个栈列表
    stack_list *list = (stack_list *)malloc(sizeof(stack_list));
    list->top = NULL;
    // 创建一个遍历指针
    tree *p = tree1;

    while (p || list->top)
    {
        if (p)
        {
            printf("%d", p->number);
            insert_stack_list(list, p);
            p = p->lchild;
        }
        else
        {
            p = delete_stack_list(list);
            p = p->rchild;
        }
    }
}

// 用栈实现中序遍历二叉树
void printf_middle(tree *tree1)
{
    // 创建一个栈列表
    stack_list *list = (stack_list *)malloc(sizeof(stack_list));
    list->top = NULL;
    // 创建一个遍历指针
    tree *p = tree1;

    while (p || list->top)
    {
        if (p)
        {
            insert_stack_list(list, p);
            p = p->lchild;
        }
        else
        {
            p = delete_stack_list(list);
            printf("%d", p->number);
            p = p->rchild;
        }
    }
}

// 用栈实现后序遍历二叉树
void printf_back(tree *tree1)
{
}

int main()
{
    tree *tree_1 = create(1, 2);
    printf_back(tree_1);
    return 0;
}