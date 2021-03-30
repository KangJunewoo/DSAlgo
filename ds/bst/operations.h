#if !defined(_BST_OPERATIONS)
#define _BST_OPERATIONS
#include "bst.h"

Node *createNode(int v);
Node *insertNode(Node *node, int v);
Node *searchNode(Node *root, int v);
Node *deleteNode(Node *root, int v);

Node *getMinNode(Node *node);
Node *getMaxNode(Node *node);

#endif // _BST_OPERATIONS