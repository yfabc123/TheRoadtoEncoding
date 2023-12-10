#include <stdio.h>
#include <stdlib.h>

// 树节点结构体
typedef struct node
{
    int number; // 节点编号
    struct node *left_child;
    struct node *right_child;
} tree_node;

// 栈节点结构体
typedef struct node_stack
{
    struct node_stack *next;
    tree_node *root;

} stack_node;
// 栈头结构体
typedef struct stack_head
{
    stack_node *top;
    int number; // 记录栈节点个数
} stack_head;

// 创建栈
stack_head *creat_stack()
{
    stack_head *stack_head_1 = (stack_head *)malloc(sizeof(stack_head));
    stack_head_1->number = 0;
    stack_head_1->top = NULL;
    return stack_head_1;
}
// 入栈
stack_head *insert(stack_head *stack_head1, tree_node *tree_node1)
{
    stack_node *temp = (stack_node *)malloc(sizeof(stack_node));
    temp->next = stack_head1->top;
    temp->root = tree_node1;
    stack_head1->top = temp;
    stack_head1->number++;
    return stack_head1;
}
// 出栈
tree_node *delete(stack_head *stack_head1)
{
    stack_node *temp = stack_head1->top;
    tree_node *temp1 = temp->root;
    stack_head1->top = temp->next;
    stack_head1->number--;
    free(temp);

    return temp1;
}

// 递归创建完全二叉树
tree_node *create(int n, int max)
{

    tree_node *temp = (tree_node *)malloc(sizeof(tree_node));
    temp->number = n;
    temp->left_child = NULL;
    temp->right_child = NULL;
    if (2 * n <= max)
    {
        temp->left_child = create(2 * n, max);
    }
    if (2 * n + 1 <= max)
    {
        temp->right_child = create(2 * n + 1, max);
    }
    return temp;
}

// 前序递归遍历二叉树
void print_tree(tree_node *root)
{
    if (!root)
    {
        return;
    }
    printf("%d\n", root->number);
    print_tree(root->left_child);
    print_tree(root->right_child);
    return;
}
// 非递归前序遍历
void print_front(tree_node *root)
{
    stack_head *stack1 = creat_stack();
    while (root || stack1->top)
    {
        while (root)
        {
            printf("%d\n", root->number);
            insert(stack1, root);
            root = root->left_child;
        }
        root = delete (stack1);
        root = root->right_child;
    }
}

// 非递归中序遍历
void print_middle(tree_node *root)
{
    stack_head *stack1 = creat_stack();
    while (root || stack1->top)
    {
        while (root)
        {
            insert(stack1, root);
            root = root->left_child;
        }
        root = delete (stack1);
        printf("%d\n", root->number);
        root = root->right_child;
    }
}

// 非递归后序遍历
void print_back(tree_node *root)
{
    stack_head *stack1 = creat_stack();
    tree_node *pre = NULL;

    while (root || stack1->top)
    {
        while (root)
        {
            insert(stack1, root);
            root = root->left_child;
        }

        root = stack1->top->root;

        // 如果当前节点的右子树为空或已经访问过，就可以访问当前节点
        if (root->right_child == NULL || root->right_child == pre)
        {
            printf("%d\n", root->number);
            delete (stack1);
            pre = root;  // 记录上一个访问的节点
            root = NULL; // 标记当前节点已经访问
        }
        else
        {
            // 否则，继续遍历右子树
            root = root->right_child;
        }
    }
}

int main()
{
    tree_node *tree1 = create(1, 6);
    // print_front(tree1);
    print_back(tree1);

    return 0;
}