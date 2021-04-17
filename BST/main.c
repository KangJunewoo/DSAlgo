#include <stdio.h>
#include "bst.h"
#include "operations.h"
#include "traversal.h"

int main()
{
    Node *root = NULL;
    Node *node = NULL;

    root = insertNode(root, 30);
    printf("TREE : ");
    inorderTraverse(root);
    printf("\n");

    root = insertNode(root, 20);
    printf("TREE : ");
    inorderTraverse(root);
    printf("\n");

    root = insertNode(root, 10);
    printf("TREE : ");
    inorderTraverse(root);
    printf("\n");

    root = insertNode(root, 40);
    printf("TREE : ");
    inorderTraverse(root);
    printf("\n");

    root = insertNode(root, 50);
    printf("TREE : ");
    inorderTraverse(root);
    printf("\n");

    root = insertNode(root, 60);
    printf("TREE : ");
    inorderTraverse(root);
    printf("\n");

    if (searchNode(root, 30) != NULL)
        printf("발견!");
    else
    {
        printf("발견 X");
    }
    root = deleteNode(root, 30);

    if (searchNode(root, 30) != NULL)
        printf("발견!");
    else
    {
        printf("발견 X");
    }

    return 0;
}