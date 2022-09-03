#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct  node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif
void preorder(tree_t *t) {
  printf("%d ",t->data);
  if (t->left != NULL) {
    preorder(t->left);}
  if (t->right != NULL) {
    preorder(t->right);}
}
int print_preorder(tree_t *t) {
  preorder(t);
  printf("\n");
}

void posorder(tree_t *t) {
  if (t->left != NULL) {
    posorder(t->left);
  }
  if (t->right != NULL) {
    posorder(t->right);
  }
  printf("%d ",t->data);
}
void print_posorder(tree_t *t) {
  posorder(t);
  printf("\n");
}

void inorder(tree_t *t) {
  if (t->left != NULL) {
    inorder(t->left);
  }
  printf("%d ",t->data);
  if (t->right != NULL) {
    inorder(t->right);
  }
}
void print_inorder(tree_t *t) {
  inorder(t);
  printf("\n");
}

int main(void) {
  tree_t *t = NULL;
  int n,i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  print_preorder(t);
  print_posorder(t);
  print_inorder(t);

  return 0;
}