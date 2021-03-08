#include "bst.h"

int main(){
  // FIXME : 오류찾기(무한루프 걸린듯)
  
  Node* tree = createNode(123);
  Node* node = NULL;

  insertNode(tree, createNode(22));
  insertNode(tree, createNode(9918));
  insertNode(tree, createNode(424));
  insertNode(tree, createNode(17));
  insertNode(tree, createNode(3));
  insertNode(tree, createNode(98));
  insertNode(tree, createNode(34));
  insertNode(tree, createNode(760));
  insertNode(tree, createNode(317));
  insertNode(tree, createNode(1));

  inorderPrint(tree);
  printf("\n");

  node = removeNode(tree, NULL, 98);
  destroyNode(node);

  inorderPrint(tree);
  printf("\n");

  insertNode(tree, createNode(111));
  inorderPrint(tree);
  printf("\n");

  destroyTree(tree);
  return 0;
}
