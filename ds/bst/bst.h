#if !defined(BST_H)
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  struct Node* left;
  struct Node* right;
  int data;
} Node;

Node* createNode(int data);
void destroyNode(Node* node);
void destroyTree(Node* tree);

Node* searchNode(Node* tree, int target);
Node* searchMinNode(Node* tree);

void insertNode(Node* tree, Node* node);
Node* removeNode(Node* tree, Node* parent, int target);

void inorderPrint(Node* tree);

void bst_test();
#endif // BST_H
