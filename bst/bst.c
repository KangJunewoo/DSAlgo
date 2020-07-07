#include "bst.h"

Node* createNode(int data){
  Node* node = (Node*)malloc(sizeof(node));
  node->left = NULL;
  node->right = NULL;
  node->data = data;
}

void destroyNode(Node* node){
  free(node);
}

void destroyTree(Node* tree){
  if(tree->right != NULL){
    destroyTree(tree->right);
  }

  if(tree->left != NULL){
    destroyTree(tree->left);
  }

  tree->left=NULL;
  tree->right=NULL;

  destroyNode(tree);
}

Node* searchNode(Node* tree, int target){
  if(tree == NULL){
    return NULL;
  }

  if(tree->data == target){
    return tree;
  } else if(tree->data > target){
    return searchNode(tree->left, target);
  } else{
    return searchNode(tree->right, target);
  }
}

Node* searchMinNode(Node* tree){
  if(tree==NULL){
    return NULL;
  }

  if(tree->left) return tree;
  else return searchMinNode(tree->left);
}

void insertNode(Node* tree, Node* node){
  // 루트값이 넣으려는 노드값보다 작으면 오른쪽에 넣어야겠지. vice versa.
  if(tree->data < node->data){
    if(tree->right == NULL){
      tree->right = node;
    } else{
      insertNode(tree->right, node);
    }
  } else if(tree->data > node->data){
    if(tree->left == NULL){
      tree->left = node;
    } else{
      insertNode(tree->left, node);
    }
  }
}

// 구현이 제일 빡세다.
// parent는 tree 루트의 parent를 말하는거임. 처음에 NULL이 들어갈거고,
// target이 담긴 노드를 tree에서 없애고 재배치한다고 생각하면 됨.
// TODO : 분석
Node* removeNode(Node* tree, Node* parent, int target){
  Node* removing = NULL;

  if(tree == NULL) return NULL;

  // 타겟이 더 작다면 왼쪽으로 기기
  if(tree->data > target){
    removing = removeNode(tree->left, tree, target);
  } else if(tree->data < target){
    removing = removeNode(tree->right, tree, target);
  } else{ // 찾은경우
    removing=tree;

    // leaf일경우 유레카!
    if(tree->left == NULL && tree->right == NULL){
      if(parent->left == tree){
        parent->left = NULL;
      } else{
        parent->right = NULL;
      }
    } else{ // leaf가 아니라면...복잡하게 된다.
      // 자식이 두명이면
      if(tree->left != NULL && tree->right != NULL){
        Node* MinNode = searchMinNode(tree->right);
        MinNode = removeNode(tree, NULL, MinNode->data);
        tree->data = MinNode->data;
      } else{ // 자식이 한명이면
        Node* temp = NULL;
        if(tree->left != NULL) temp = tree->left;
        else temp = tree->right;

        if(parent->left == tree) parent->left = temp;
        else parent->right = temp;
      }
    }
  }

  return removing;
}

void inorderPrint(Node* tree){
  if(tree==NULL) return;

  inorderPrint(tree->left);
  printf("%d ", tree->data);
  inorderPrint(tree->right);
}