#include "bst.h"
#include "traversal.h"
#include <stdio.h>
#include <stdlib.h>

void inorderTraverse(Node *root)
{
    if (root)
    {
        inorderTraverse(root->l);
        printf("[%d] ", root->v);
        inorderTraverse(root->r);
    }
}
void preorderTraverse(Node *root)
{
    if (root)
    {
        printf("[%d] ", root->v);
        preorderTraverse(root->l);
        preorderTraverse(root->r);
    }
}
void postorderTraverse(Node *root)
{
    if (root)
    {
        postorderTraverse(root->l);
        postorderTraverse(root->r);
        printf("[%d] ", root->v);
    }
}