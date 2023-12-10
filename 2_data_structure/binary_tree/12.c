#include <stdio.h>
#include <stdlib.h>

// 树节点结构体
typedef struct node_tree
{
    int number; // 节点编号
    struct node_tree *left_child;
    struct node_tree *right_child;
} tree_node;

typedef tree_node *datatype;
// 队列节点
typedef struct node_quue
{
    struct node_quue *next;
    datatype data;

} qnode;

typedef struct ctl
{
    qnode *head;
    qnode *tail;

} qctl;
// 创建队列
qctl *create_queue()
{
    qctl *qctl1 = (qctl *)malloc(sizeof(qctl));
    qnode *qnode1 = (qnode *)malloc(sizeof(qnode));
    qnode1->next = NULL;
    qnode1->data = NULL;
    qctl1->head = qnode1;
    qctl1->tail = qnode1;
    return qctl1;
}
// 入队列
qctl *inquue(qctl *qctl1, datatype root)
{
    qnode *temp = (qnode *)malloc(sizeof(qnode));
    temp->data = root;
    temp->next = NULL;
    qctl1->tail->next = temp;
    qctl1->tail = temp;
    return qctl1;
}
// 出队列
datatype outqueue(qctl *qctl1)
{
    // 队列为空
    if (qctl1->head == qctl1->tail)
    {
        return NULL;
    }
    qnode *qnode_temp = qctl1->head->next; // 要出去的队列节点
    datatype temp = qnode_temp->data;      // 要出去的树节点
    if (qnode_temp->next == NULL)          // 判断是不是最后一个节点
    {
        qctl1->tail = qctl1->head;
        qctl1->head->next = NULL;
    }
    else // 如果不是最后一个节点
    {
        qctl1->head->next = qnode_temp->next;
    }
    qnode_temp->data = NULL;
    qnode_temp->next = NULL;
    free(qnode_temp);
    return temp;
}

// 递归创建完全二叉树
tree_node *create_tree(int n, int max)
{

    tree_node *temp = (tree_node *)malloc(sizeof(tree_node));
    temp->number = n;
    temp->left_child = NULL;
    temp->right_child = NULL;
    if (2 * n <= max)
    {
        temp->left_child = create_tree(2 * n, max);
    }
    if (2 * n + 1 <= max)
    {
        temp->right_child = create_tree(2 * n + 1, max);
    }
    return temp;
}

// 层次遍历方法
void printf1(tree_node *root)
{
    // 创建队列
    qctl *qctl1 = create_queue();
    tree_node *p = NULL; // 用于指向出队列的根节点
    // 树头入队列
    inquue(qctl1, root);
    // 只要队列不为空则循环执行：出队列时打印数据 同时将左右孩子入队列
    while (qctl1->head != qctl1->tail)
    {
        p = outqueue(qctl1);
        printf("%d\n", p->number);
        if (p->left_child)
        {
            inquue(qctl1, p->left_child);
        }
        if (p->right_child)
        {
            inquue(qctl1, p->right_child);
        }
    }
}

int main()
{
    tree_node *root = create_tree(1, 6);
    printf1(root);

    return 0;
}