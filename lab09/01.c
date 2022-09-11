#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;
typedef node_t bst_t;
// Write your code here

bst_t *insert(bst_t *t, int v) {
  bst_t *newnode = (bst_t *)malloc(sizeof(bst_t));
  bst_t *temp = t;
  newnode->data = v;newnode->left =NULL;newnode->right = NULL;
  if (t==NULL) {
    return newnode;
  } else {
    while(1) {
      if (v<temp->data && temp->left == NULL) {
        temp->left = newnode;
        return t;
      } else if (v>temp->data && temp->right == NULL) {
        temp->right = newnode;
        return t;
      } else if (v<temp->data) {
        temp = temp->left;
      } else if (v>temp->data) {
        temp = temp->right;
      } 
    }
  }
}
bst_t *find_min_p(bst_t *t) {
  if (t->left != NULL) {
    find_min_p(t->left);
  } else {
    return t;
  }
}
bst_t *find_parent(bst_t *t, int v,bst_t *parent) {
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

bst_t *delete(bst_t *t, int v) {
  bst_t *parent = NULL;
  bst_t *node = NULL;
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
    bst_t *right_min = find_min_p(node->right);
    bst_t *parent_right_min = NULL;
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

int find(bst_t *t, int v) {
  //printf("[%d]",t->data);
  if (t == NULL) {
    return 0;
  }
  //printf("[%d-%p]",t->data,t->right);
  if ((v < t->data && t->left == NULL) || (v > t->data && t->right == NULL)) {
    return 0;
  } else if (v < t->data) {
      find(t->left, v);
  } else if (v > t->data) {
      find(t->right, v);
  } else if (t->data == v) {
      return 1;
  } 
}

int find_min(bst_t *t) {
  if (t->left != NULL) {
    find_min(t->left);
  } else {
    return t->data;
  }
}

int find_max(bst_t *t) {
  if (t->right != NULL) {
    find_max(t->right);
  } else {
    return t->data;
  }
}
// ...
int main(void) {
  bst_t *t = NULL;
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
        scanf("%d", &data);
        printf("%d\n", find(t, data));
        break;
      case 4:
        printf("%d\n", find_min(t));
        break;
      case 5:
        printf("%d\n", find_max(t));
        break;
    }
  }
  return 0;
}