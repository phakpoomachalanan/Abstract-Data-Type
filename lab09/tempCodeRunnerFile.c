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
avl_t *find_parent(avl_t *t, int v,avl_t *parent) {
  //printf("[%dv][%dt]",v,t->data);
  if (v < t->data) {
      parent = t;
      find_parent(t->left, v,parent);
  } else if (v > t->data) {
      parent = t;
      find_parent(t->right, v,parent);
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
  a->height -= 2;
  avl_t *parent = NULL;
  parent = find_parent(t,a->data,parent);
  avl_t *b = a->left;
  a->left = b->right;
  b->right = a;
  if (parent != NULL) {
    //printf("(%d)",parent->data);
    parent->height -= 1;
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
  a->height -= 2;
  avl_t *parent = NULL;
  parent = find_parent(t,a->data,parent);
  avl_t *b = a->right;
  a->right = b->left;
  b->left = a;
  if (parent != NULL) {
    //printf("(%d)",parent->data);
    parent->height -= 1;
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
  while (1) {
    if (t->data < v) {
        t = t->right;
      } else if (t->data > v) {
        t = t->left;
      } else {

        break;
      }
  }
  t->height = height(t);
  //printf("[%d]",t->data);
  if (t->left == NULL && t->right == NULL) {
    return NULL;
  }
  if (t->right != NULL && t->left != NULL) {
    //printf("{%d}[%dLH][%dLR]",t->height,t->left->height,t->right->height);
    if ((t->left->height)-(t->right->height) > 1 || (t->left->height)-(t->right->height) < -1) {
      return t;
    } else {
      return NULL;
    }
  } else {
    if (t->right == NULL && t->left->height > 0) {
      return t;
    }else if (t->left == NULL && t->right->height > 0) {
      return t;
    } else {
      return NULL;
    }
  }
}
avl_t *optimize(avl_t *t, int v) {
  //printf("[%d]",t->data);
  avl_t *a = check(t,v);
  if (a == NULL) {
    return t;
  } else if ((a->right == NULL)) {
    avl_t *b = a->left;
    int blh;
    int brh;
    if (b->left == NULL) {
      blh = -1;
    } else {
      blh = b->left->height;
    }
    if (b->right == NULL) {
      brh = -1;
    } else {
      brh = b->right->height;
    }
    if (blh > brh) {
      t = right_Ro(t,a);
    } else if (blh < brh) {
      t = left_Ro(t,b);
      b->height+=1;
      t = right_Ro(t,a);
      a->height+=1;
      avl_t *parent = NULL;
      parent = find_parent(t,a->data,parent);
      parent->height+=1;
    }
  } else if ((a->left == NULL)) {
    avl_t *b = a->right;
    int blh;
    int brh;
    if (b->left == NULL) {
      blh = -1;
    } else {
      blh = b->left->height;
    }
    if (b->right == NULL) {
      brh = -1;
    } else {
      brh = b->right->height;
    }
    if (blh > brh) {
      t = right_Ro(t,b);
      b->height+=1;
      t = left_Ro(t,a);
      a->height+=1;
      avl_t *parent = NULL;
      parent = find_parent(t,a->data,parent);
      parent->height+=1;
    } else if (blh < brh) {
      t = left_Ro(t,a);
    }
  } else if (((a->left->height - a->right->height) > 1)) {
    avl_t *b = a->left;
    int blh;
    int brh;
    if (b->left == NULL) {
      blh = -1;
    } else {
      blh = b->left->height;
    }
    if (b->right == NULL) {
      brh = -1;
    } else {
      brh = b->right->height;
    }
    if (blh > brh) {
      t = right_Ro(t,a);
    } else if (blh < brh) {
      t = left_Ro(t,b);
      b->height+=1;
      t = right_Ro(t,a);
      a->height+=1;
      avl_t *parent = NULL;
      parent = find_parent(t,a->data,parent);
      parent->height+=1;
    }
  } else if (((a->left->height - a->right->height) < -1)) {
    avl_t *b = a->right;
    int blh;
    int brh;
    if (b->left == NULL) {
      blh = -1;
    } else {
      blh = b->left->height;
    }
    if (b->right == NULL) {
      brh = -1;
    } else {
      brh = b->right->height;
    }
    if (blh > brh) {
      t = right_Ro(t,b);
      b->height+=1;
      t = left_Ro(t,a);
      a->height+=1;
      avl_t *parent = NULL;
      parent = find_parent(t,a->data,parent);
      parent->height+=1;
    } else if (blh < brh) {
      t = left_Ro(t,a);
    }
  } else {
    return t;
  }
  return t;
}

avl_t *find_for_op(avl_t *t, int v,avl_t *temp) {
  if (temp->data < v) {
    find_for_op(t,v,temp->right);
    //printf("[%d]",temp->data);
    t = optimize(t, temp->data);
  } else if (temp->data > v) {
    find_for_op(t,v,temp->left);
    //printf("[%d]",temp->data);
    t = optimize(t, temp->data);
  } else {
    t = optimize(t, temp->data);
    return temp;
    
  }
}
avl_t *insert(avl_t *t, int v) {
  avl_t *temp = t;
  avl_t *newnode = (avl_t *)malloc(sizeof(avl_t));
  newnode->data = v;
  newnode->right = NULL;
  newnode->left = NULL; 
  newnode->height = 0;
  if (t == NULL) {
    return newnode;
  } else {
    while (1) {
      if (temp->data > v) {
        if (temp->left == NULL) {
          temp->height += 1;
          temp->left = newnode;
          break;
        } else {
          temp->height += 1;
          temp = temp->left;
        }
      } else if (temp->data < v) {
        if (temp->right == NULL) {
          temp->height += 1;
          temp->right = newnode;
          break;
        } else {
          temp->height += 1;
          temp = temp->right;
        }
      }
    }
  }
  temp = t;
  return find_for_op(t,v,temp);
}
avl_t *find_min_p(avl_t *t) {
  if (t->left != NULL) {
    find_min_p(t->left);
  } else {
    return t;
  }
}
avl_t *delete_pre(avl_t *t, int v);
avl_t *delete(avl_t *t, int v) {
  avl_t *parent = find_parent(t,v,NULL);
  if (parent == NULL) {
    avl_t *min = find_min_p(t->right);
    avl_t *parent_right = find_parent(t,min->data,NULL);  
    t = delete_pre(t,v);
    avl_t *temp = t;
    return find_for_op(t,parent_right->data,temp); 
  } else {
    t = delete_pre(t,v);
    avl_t *temp = t;
    //printf("parent%d",parent->data);
    return find_for_op(t,parent->data,temp);
  }
  
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


avl_t *delete_pre(avl_t *t, int v) {
  avl_t *parent = NULL;
  avl_t *node = NULL;
  parent = find_parent(t,v,parent);
  if (parent == NULL) {
    node = t; 
  } else if (parent->data > v) {
    node = parent->left;
  } else {
    node = parent->right;
  }
  if (node->left == NULL && node->right == NULL) {
    if (parent == NULL) {
      return NULL;
    } else if (parent->data > v) {
      parent->left = NULL;
    } else {
      parent->right = NULL;
    }
  } else if (node->left == NULL && node->right != NULL) {
    if (parent == NULL) {
      t = node->right;
    }else if (parent->data > v) {
      parent->left = node->right;
    } else {
      parent->right = node->right;
    }
  } else if (node->left != NULL && node->right == NULL) {
    if (parent == NULL) {
      t = node->left;
    } else if (parent->data > v) {
      parent->left = node->left;
    } else {
      parent->right = node->left;
    }
  } else {
    avl_t *right_min = find_min_p(node->right);
    right_min->height += 1;
    avl_t *parent_right_min = NULL;
    parent_right_min = find_parent(t,right_min->data,parent_right_min);
    if (parent_right_min == node) {
      parent_right_min->right = right_min->right;
    } else {
      parent_right_min->left = right_min->right;
    }
    right_min->left = node->left;
    right_min->right = node->right;
    if (parent == NULL) {
      t = right_min;
    } else if (parent->data > right_min->data) {
      parent->left = right_min;
    } else {
      parent->right = right_min;
    }
  }
  free(node);
  return t;
} 