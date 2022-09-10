#include <stdio.h>
#include <stdlib.h>
#include "week9.h"
#ifndef __avl_tree__
typedef struct node {
  int data;
  int height;
  struct node *left;
  struct node *right;
} node_t;
typedef node_t avl_t;
#endif
// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header
avl_t *find_parent(avl_t *t, int v) {
  static avl_t *parent = NULL;
  if (v < t->data) {
      parent = t;
      find_parent(t->left, v);
  } else if (v > t->data) {
      parent = t;
      find_parent(t->right, v);
  } else if (t->data == v) {
      return parent;
  } 
}
int height(avl_t *t) {
  static int hl;
  static int hr;
  if (t == NULL) {
    return -1;
  }
  hl = height(t->left);
  hr = height(t->right);
  return (hl>hr)? hl+1 : hr+1;
}
avl_t *right_Ro (avl_t *t,avl_t *a) {
  avl_t *parent = find_parent(t,a->data);
  avl_t *b = a->left;
  a->left = b->right;
  b->right = a;
  if (parent != NULL) {
    if (parent->data > a->data) {
      parent->left = b;
    } else {
      parent->right = b;
    }
    return t;
  } else {
    return b;
  }
}
avl_t *left_Ro (avl_t *t,avl_t *a) {
  avl_t *parent = find_parent(t,a->data);
  avl_t *b = a->right;
  a->right = b->left;
  b->left = a;
  if (parent != NULL) {
    if (parent->data > a->data) {
      parent->left = b;
    } else {
      parent->right = b;
    }
    return t;
  } else {
    return b;
  }
}
avl_t *check(avl_t *t, int v) {
  if ((t->left->height)-(t->right->height) > 1 || (t->left->height)-(t->right->height) < -1) {
    return t;
  }
  if (t->data < v) {
    check(t->right,v);
  } else if (t->data > v) {
    check(t->left,v);
  } else {
    return NULL;
  }
}
avl_t *insert(avl_t *t, int v) {
  avl_t *temp = t;
  avl_t *newnode = (avl_t *)malloc(sizeof(avl_t));
  newnode->data = v;
  newnode->left == NULL; newnode->right == NULL;
  newnode->height = 0;
  if (t == NULL) {
    return newnode;
  } else {
    while (1) {
      if (temp > v) {
        if (temp->left == NULL) {
          temp->height += 1;
          temp->left = newnode;
          return t;
        } else {
          temp->height += 1;
          temp = temp->left;
        }
      } else if (temp < v) {
        if (temp->right == NULL) {
          temp->height += 1;
          temp->right = newnode;
          return t;
        } else {
          temp->height += 1;
          temp = temp->right;
        }
      }
    }
    avl_t *a = check(t,v);
  }
}
avl_t *delete(avl_t *t, int data) {

}
// ...
int main(void) {
  avl_t *t = NULL;
  int n, i;
  int command, data;
  scanf("%d", &n);
    for (i=0; i<n; i++) {
    scanf("%d", &command);
      switch (command) {
        case 1:
          scanf("%d", &data);
          t = insert(t, data);
          break;
        case 2:
          scanf("%d", &data);
          t = delete(t, data);
          break;
        case 3:
          print_tree(t);
          break;
      }
  }
  return 0;
}