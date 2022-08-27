#include <stdio.h>
#include <stdlib.h>

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
// typedef struct node {
//    ...
// } node_t;
// typedef node_t tree_t;

// Write your code here
typedef struct node {
  int value;
  int parent;
  struct node *next_sibling;
  struct node *first_child;
} node_t;
typedef node_t tree_t;

typedef struct nodeq {
  struct node *the_child;
  struct nodeq *next;
} node_q;

typedef struct queue {
  node_q *front;
  node_q *rear;
} queue_t;

void enqueue(queue_t *q,tree_t *t) {
  //printf("-%d-", t->value);
  node_q *newnode = (node_q *)malloc(sizeof(node_q));
  //printf("%p",newnode);
  newnode->next = NULL;
  newnode->the_child = t;
  if (q->front == NULL) {
    q->front = newnode;
    q->rear = newnode;
  } else {
    q->rear->next = newnode;
    q->rear =newnode;
  }
  //printf(".%d.", q->rear->the_child->value);
}

node_t *searchf(tree_t *t, int v) {
  node_t *pos;
  //printf("[%d]\n", t->value);
  if (t == NULL || t->value == v) {
    return t;}
  pos = searchf(t->first_child, v);
  if (pos != NULL) {
    return pos;}
  else{
    return searchf(t->next_sibling, v);}
}

int search(tree_t *t, int v) {
  if (searchf(t, v) == NULL) {
    return 0;
  } else {
    return 1;
  }
}

node_t *attach(tree_t *t, int parent, int child) {
  node_t *temp = NULL;
  node_t *newnode = (node_t *)malloc(sizeof (node_t));
  newnode->value = child;
  newnode->first_child = NULL;
  newnode->next_sibling = NULL;
  newnode->parent = parent;
  if (parent == -1) {
    return newnode;
  } else {
    temp = searchf(t, parent);
    if (temp->first_child == NULL) {
      temp->first_child = newnode;
      return t;
    } else {
      temp = temp->first_child;
      while (temp->next_sibling != NULL) {
        temp = temp->next_sibling;
      }
      temp->next_sibling = newnode;
      return t;
    }
  }
}

node_t *detach(tree_t *t, int v) {
  node_t *temp = NULL;
  node_t *temp_t = NULL;
  temp_t = searchf(t,v);
  if (temp_t->parent == -1) {
    free(t);
    return NULL;
  } else {
    temp = searchf(t,temp_t->parent);
    if (temp->first_child->value == v) {
      temp->first_child = NULL;
    } else {
    temp = temp->first_child;
    while (temp->next_sibling->value != v) {
      temp = temp->next_sibling;
    }
    temp->next_sibling = NULL;
    }
    temp = temp_t;
  }
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));
  q->front = NULL; q->rear = NULL;
  while (1) {
    if (temp->next_sibling != NULL) {
      while (temp != NULL) {
        if (temp->first_child != NULL) {
          //printf("[%d]",t->first_child->value);
          enqueue(q,temp->first_child);
        }
        temp_t = temp;
        temp = temp->next_sibling;
        free(temp_t);
      }
    } else {
      if (temp->first_child != NULL) {
          enqueue(q,temp->first_child);
        }
      temp_t = temp;
      free(temp_t);
    }
    
    if (q->front != NULL) {
      temp = q->front->the_child;
      //printf("{%d}", t->value);
      q->front = q->front->next;
    } else {
      return t;
    }
  }
}

int degree(tree_t *t, int v) {
  int count = 0;
  node_t *temp = searchf(t,v);
  if (temp->first_child == NULL) {
    return count;
  } else {
    temp = temp->first_child; count+=1;
    while (temp->next_sibling != NULL) {
      count+=1;
      temp = temp->next_sibling;
    }
    return count;
  }
}

int is_root(tree_t *t, int v){
  if (t->value == v) {
    return 1;
  } else {
    return 0;
  }
}

int is_leaf(tree_t *t, int v) {
  node_t *temp = searchf(t,v);
  if (temp->first_child == NULL) {
    return 1;
  } else {
    return 0;
  }
}

void siblings(tree_t *t, int v) {
  node_t *temp = searchf(t,v);
  temp = searchf(t,temp->parent);
  temp = temp->first_child;
  while (temp != NULL) {
    if (temp->value != v) {
      printf("%d ", temp->value);
    }
    temp = temp->next_sibling;
  }
  printf("\n");
}

int depth(tree_t *t, int v) {
  node_t *temp =searchf(t, v);
  int count = 0;
  while (temp->parent != -1) {
    temp = searchf(t, temp->parent);
    count+=1;
  }
  return count;
}

int print_path(tree_t *t, int start, int end) {
  static int A = 0;
  int B = 0;
  if (end == start) {
    printf("%d ", start);
    return 0;
  }
  node_t *temp = searchf(t, end);
  if (A == 0) {
    B = 1;
  }
  A++;
  print_path(t, start, temp->parent);
  printf("%d ",end);
  if (B == 1) {
    printf("\n");
  }
}

int path_length(tree_t *t, int start, int end) {
  node_t *temp = searchf(t, end);
  int count  = 1;
  while (temp->parent != start) {
    count++;
    temp = searchf(t, temp->parent);
  }
  return count;
}

void ancestor(tree_t *t, int v) {
  print_path(t, t->value, v);
}

int bfs(tree_t *t) {
  if (t == NULL) {
    return 0;
  }
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));
  q->front = NULL; q->rear = NULL;
  while (1) {
    if (t->next_sibling != NULL) {
      while (t != NULL) {
        printf("%d ", t->value);
        if (t->first_child != NULL) {
          //printf("[%d]",t->first_child->value);
          enqueue(q,t->first_child);
        }
        t = t->next_sibling;
      }
    } else {
      printf("%d ", t->value);
      if (t->first_child != NULL) {
          enqueue(q,t->first_child);
        }
    }
    if (q->front != NULL) {
      node_q *temp = q->front;
      t = q->front->the_child;
      //printf("{%d}", t->value);
      q->front = q->front->next;
      free(temp);
    } else {
      printf("\n");
      return 0;
    }
  }
}

void descendant(tree_t *t, int v) {
  tree_t *temp = searchf(t, v);
  printf("%d ",temp->value);
  bfs(temp->first_child);
}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;
  
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;/*
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;*/
    }
  }
  return 0;
}