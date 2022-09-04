#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct  node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif


int height(tree_t *t) {
  static int hl;
  static int hr;
  if (t == NULL) {
    return -1;
  }
  hl = height(t->left);
  hr = height(t->right);
  return (hl>hr)? hl+1 : hr+1;
}
int size(tree_t *t) {
  if (t == NULL) {
    return 0;
  }    
  return size(t->left)
         + size(t->right)
         + 1;
}
int is_full(tree_t *t) {
  static int check = 1;
  if (t->left == NULL & t->right == NULL) {
    return check;
  } else {
    if (t->left != NULL & t->right != NULL) {
      is_full(t->left);
      is_full(t->right);
    } else {
      check = 0;
      return check;
    }
  }
}

int is_prefect(tree_t *t){
  if ((pow(2,(height(t)+1))-1) == size(t)) {
    return 1;
  } else {
    return 0;
  }
}
int is_complete(tree_t *t) {
  int max  = 100;
  int i;
  int count = 2;
  tree_t *bfs [100];
  for (i=0;i<max;i++) {
    bfs[i] = NULL;
  }
  i = 1;
  if (t==NULL) {
    return 0;
  } else {
    bfs[i] = t;
  }
  while (count<max && i<max) {
    if (bfs[i] != NULL) {
      bfs[count] = bfs[i]->left; count++;
      bfs[count] = bfs[i]->right; count++;
    }
    i++;
  }
  int check = 0;
  for (i=1;i<max;i++) {
    if (bfs[i] == NULL && check == 0) {
      check = 1;
    }
    if (bfs[i] != NULL && check == 1) {
      return 0;
    }
  }
  return 1;
}
int is_degenerate(tree_t *t) {
  if (t->left != NULL && t->right != NULL) {
    return 0;
  }
  if (t->left != NULL) {
    is_degenerate(t->left);
  }
  if (t->right != NULL) {
    is_degenerate(t->right);
  }
  return 1;
}
int is_skewed_left(tree_t *t) {
  if (t->right == NULL) {
    if (t->left != NULL) {
      is_skewed_left(t->left);
    } else {
      return 1;
    }
  } else {
    return 0;
  }

}
int is_skewed_right(tree_t *t) {
  if (t->left == NULL) {
    if (t->right != NULL) {
      is_skewed_right(t->right);
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}
int is_skewed(tree_t *t) {
  if (t->left != NULL && t->right != NULL) {
    return 0;
  }
  if (t->left != NULL) {
    return is_skewed_left(t);
  }
  if (t->right != NULL) {
    return is_skewed_right(t);
  }
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

  printf("%d %d %d %d %d\n", is_full(t),
        is_prefect(t), is_complete(t),
        is_degenerate(t), is_skewed(t));

  return 0;
}