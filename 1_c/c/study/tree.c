#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool func(struct TreeNode *l, struct TreeNode *r)
{

    if (!l && !r)
    {
        return true;
    }
    else
    {
        if (l && r && l->val == r->val)
        {
            return func(l->left, r->right) && func(l->right, r->left);
        }
        else
        {
            return false;
        }
    }
}

bool isSymmetric(struct TreeNode *root)
{
    return func(root->left, root->right);
}

int main()
{

    return 0;
}