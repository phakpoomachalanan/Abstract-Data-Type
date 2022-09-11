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
bst_t *find_parent(bst_t *t, int v) {
  static bst_t *parent = NULL;
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
bst_t *delete(bst_t *t, int v) {
  bst_t *temp = t;
  bst_t *parent = NULL;
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
      bst_t *temp2 = temp->left;
      free(temp);
      return temp2;
    } else if (temp->left == NULL && temp->right != NULL) {
      //printf("[case 3]");
      bst_t *temp2 = temp->right;
      free(temp);
      return temp2;
    } else if (temp->left != NULL && temp->right != NULL) {
      //printf("[case 4]");
      bst_t *right_min_p = find_min_p(temp->right);
      //printf("[%dmin]",right_min_p->data);
      bst_t *parent_right  = find_parent(t,right_min_p->data);
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
      bst_t *right_min_p = find_min_p(temp->right);
      bst_t *parent_right  = find_parent(t,right_min_p->data);
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