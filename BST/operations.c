#include "bst.h"
#include "operations.h"
#include <stdlib.h>

Node *createNode(int v)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->v = v;
    node->l = node->r = NULL;
    return node;
}

Node *insertNode(Node *node, int v)
{
    if (node == NULL) // 맨땅의 상태에서 노드를 생성
        return createNode(v);

    if (v < node->v) // lrllrrrl... 타고 가면서 어딘가의 자식에 들어갈거임.
        node->l = insertNode(node->l, v);
    else if (v > node->v)
        node->r = insertNode(node->r, v);

    return node;
}

Node *searchNode(Node *node, int v)
{
    if (node == NULL)
        return NULL;
    if (v == node->v)
        return node;
    else if (v < node->v)
        return searchNode(node->l, v);
    else
        return searchNode(node->r, v);
}
Node *deleteNode(Node *root, int v)
{
    if (root == NULL)
        return root;

    if (v < root->v)
        root->l = deleteNode(root->l, v);
    else if (v > root->v)
        root->r = deleteNode(root->r, v);
    else
    { // 탐색 성공의 상태. 결국 root를 free할거임.
        if (root->l == NULL)
        { // 자식이 없거나 하나라면 나를 없애고 자식을 위로 올리면 간단.
            Node *node = root->r;
            free(root);
            return node;
        }
        else if (root->r == NULL)
        { // 자식이 하나라면 나를 없애고 자식을 위로 올리면 간단.
            Node *node = root->l;
            free(root);
            return node;
        }

        // 자.. 자식이 두명인 경우엔
        Node *node = getMinNode(root->r);       // 내 오른쪽 자식 중 가장 작은 노드를 후계자로 삼아
        root->v = node->v;                      // 후계자를 내 자리에 앉히고
        root->r = deleteNode(root->r, node->v); // 원래 있던 후계자를 지워버리자.
    }

    return root;
}

Node *getMinNode(Node *node)
{
    Node *traversingNode = node;

    while (traversingNode->l != NULL)
    {
        traversingNode = traversingNode->l;
    }

    return traversingNode;
}

Node *getMaxNode(Node *node)
{
    Node *traversingNode = node;

    while (traversingNode->r != NULL)
    {
        traversingNode = traversingNode->r;
    }

    return traversingNode;
}