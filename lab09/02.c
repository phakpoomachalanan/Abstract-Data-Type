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
  a->height -= 2;
  avl_t *parent = find_parent(t,a->data);
  avl_t *b = a->left;
  b->height -= 1;
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
  a->height -= 2;
  avl_t *parent = find_parent(t,a->data);
  avl_t *b = a->right;
  b->height -= 1;
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
  while (1) {
    if (t->data < v) {
        t = t->right;
      } else if (t->data > v) {
        t = t->left;
      } else {
        return NULL;
      }
  }
  if (t->left == NULL && t->right == NULL) {
    return NULL;
  }
  if (t->right != NULL && t->left != NULL) {
    if ((t->left->height)-(t->right->height) > 1 || (t->left->height)-(t->right->height) < -1) {
      return t;
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
  avl_t *a = check(t,v);
  if (a == NULL) {
    return t;
  } else if (((a->left->height - a->right->height) > 1) || (a->right == NULL)) {
    avl_t *b = a->left;
    if (b->left->height > b->right->height) {
      t = right_Ro(t,a);
    } else if (b->left->height < b->right->height) {
      t = left_Ro(t,b);
      t = right_Ro(t,a);
    }
  } else if (((a->left->height - a->right->height) < -1) || (a->left == NULL)) {
    avl_t *b = a->right;
    if (b->left->height > b->right->height) {
      t = right_Ro(t,b);
      t = left_Ro(t,a);
    } else if (b->left->height < b->right->height) {
      t = left_Ro(t,a);
    }
  } else {
    return t;
  }
  return t;
}

avl_t *find_for_op(avl_t *t, int v,avl_t *temp) {
  if (temp->data < v) {
<<<<<<< Updated upstream
    temp = find_for_op(t,v,temp->right);
    printf("[%d]",temp->data);
    t = optimize(t, temp->data);
  } else if (temp->data > v) {
    temp = find_for_op(t,v,temp->left);
    printf("[%d]",temp->data);
    t = optimize(t, temp->data);
  } else {
    return temp;
=======
    find_for_op(t,v,temp->right);
  } else if (temp->data > v) {
    find_for_op(t,v,temp->left);
  } else {

>>>>>>> Stashed changes
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
avl_t *delete_pre(avl_t *t, int v);
avl_t *delete(avl_t *t, int v) {
  t = delete_pre(t,v);
  avl_t *temp = t;
  return find_for_op(t,v,temp);
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

avl_t *find_min_p(avl_t *t) {
  if (t->left != NULL) {
    find_min_p(t->left);
  } else {
    return t;
  }
}
avl_t *delete_pre(avl_t *t, int v) {
  avl_t *temp = t;
  avl_t *parent = NULL;
  while(1) {//find v parent
 //printf("[%d]",temp->data);
    if (t->data == v) {
      temp = t;
      break;
    }
    if (v < temp->data) {
        parent = temp;
        temp = temp->left;
    } else if (v > temp->data) {
        parent = temp;
        temp = temp->right;
    } else if (temp->data == v) {
        break;
    } 
  }
  if (parent != NULL) {
    //printf("[%dparent]",parent->data);
  }
  //printf("[%dtemp]",temp->data);
  //case parent == NULL
  if (parent == NULL) {
    //printf("NULL");
    if (temp->left == NULL && temp->right == NULL) {
      //printf("[case 1]");
      return NULL;
    } else if (temp->left != NULL && temp->right == NULL) {
      //printf("[case 2]");
      avl_t *temp2 = temp->left;
      free(temp);
      return temp2;
    } else if (temp->left == NULL && temp->right != NULL) {
      //printf("[case 3]");
      avl_t *temp2 = temp->right;
      free(temp);
      return temp2;
    } else if (temp->left != NULL && temp->right != NULL) {
      //printf("[case 4]");
      avl_t *right_min_p = find_min_p(temp->right);
      //printf("[%dmin]",right_min_p->data);
      avl_t *parent_right  = find_parent(t,right_min_p->data);
      if (parent == NULL && parent_right->data == t->data) {
        parent_right->right = right_min_p->right;
      } else {
        //printf("[%dP]",parent_right->data);
        parent_right->left = right_min_p->right;
      }
      right_min_p->right = NULL;
      if (temp->right != right_min_p) {
        right_min_p->right = temp->right;
      }
      //printf("[%dL]",temp->left->data);
      right_min_p->left = temp->left;
      //printf("[%dR]",right_min_p->right->data);
      free(temp);
      return right_min_p;
    }
  }

  //case parent != NULL
  else {
    if (temp->left == NULL && temp->right == NULL && temp->data < parent->data) {
      //printf("[case 1]");
      parent->left = NULL;
      free(temp);
      return t;
    } else if (temp->left == NULL && temp->right == NULL && temp->data > parent->data){
      //printf("[case 2]");
      parent->right = NULL;
      free(temp);
      return t;
    } else if (temp->left != NULL && temp->right == NULL) {
      //printf("[case 3]");
      if (temp->data < parent->data) {
        parent->left = temp->left;
      } else {
        parent->right = temp->left;
      }
      free(temp);
      return t;
    } else if (temp->left == NULL && temp->right != NULL) {
      //printf("[case 4]");
      if (temp->data < parent->data) {
        parent->left = temp->right;
      } else {
        parent->right = temp->right;
      }
      free(temp);
      return t;
    } else if (temp->left != NULL && temp->right != NULL) {
      //printf("[case 5]");
      avl_t *right_min_p = find_min_p(temp->right);
      avl_t *parent_right  = find_parent(t,right_min_p->data);
      //printf("[%dmin]",right_min_p->data);
      if (parent == NULL && parent_right->data == t->data) {
        parent_right->right = right_min_p->right;
      } else {
        //printf("[%dP]",parent_right->data);
        parent_right->left = right_min_p->right;
      }
      right_min_p->right = NULL;
      if (temp->right != right_min_p) {
        right_min_p->right = temp->right;
      }
      //printf("[%dL]",temp->left->data);
      right_min_p->left = temp->left;
      if (right_min_p->data < parent->data) {
        parent->left = right_min_p;
      } else {
        parent->right = right_min_p;
      }
      //printf("[%dR]",right_min_p->right->data);
      free(temp);
      return t;
    }
  }
} 