#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int parent;
    struct node *next_sibling;
    struct node *first_child;
} node_t;
typedef node_t tree_t;

typedef struct queuenode {
    struct node *child;
    struct queuenode *next;
} queuenode_t;

typedef struct queue {
  queuenode_t *front;
  queuenode_t *rear;
} queue_t;

tree_t *search_pos(tree_t *t,int node) {
    if (t == NULL || t->value == node)
        return t;
    tree_t *pos = search_pos(t->first_child, node);
    if (pos != NULL) {
        return pos;
    } else {
        return search_pos(t->next_sibling , node);
    }
}


tree_t *attach(tree_t *t,int parent,int child) {
    tree_t *newnode = (tree_t*)malloc(sizeof(tree_t));
    tree_t *pos = search_pos(t,parent);
    newnode->parent = parent;
    newnode->value = child;
    newnode->first_child = NULL;
    newnode->next_sibling = NULL;
    
    if (parent == -1)
    {
      return newnode;
    }
    

    if (pos->first_child == NULL) {
        pos->first_child = newnode;
    } else {
        pos = pos->first_child;
        while (pos->next_sibling != NULL)
        {
            pos = pos->next_sibling;
        }
        pos->next_sibling = newnode;
    }
    
    return t;
}

tree_t *detach(tree_t *t,int node) {
    tree_t *childpos = search_pos(t,node);
    tree_t *parentpos = search_pos(t,childpos->parent);
    tree_t *tmp = parentpos->first_child;
    if (parentpos->first_child == childpos) //immediately found
    {
      parentpos->first_child = childpos->next_sibling;
    } else { //search siblings until found
      while (tmp->next_sibling != childpos)
      {
        tmp = tmp->next_sibling;
      }
      tmp->next_sibling = tmp->next_sibling->next_sibling; // link to next next siling instead
    }

    // try recursive free all children of node
    return t;
}


int search(tree_t *t,int node) {
    if (search_pos(t,node) != NULL) {
        return 1;
    }
    return 0;
}

int degree(tree_t *t,int node) {
    int c = 0;
    tree_t *pos = search_pos(t,node);
    if (pos == NULL)
    {
      return 0;
    }
    
    pos = pos->first_child;
    while (pos != NULL)
    {
      c++;
      pos = pos->next_sibling;
     
    }
    return c;
}

int is_root(tree_t *t,int node) {
    tree_t *pos = search_pos(t,node);
    if (pos->parent == -1)
      {
        return 1;
      }
    return 0;
}

int is_leaf(tree_t *t,int node) {
  tree_t *pos = search_pos(t,node);
  if (pos->first_child == NULL)
    {
      return 1;
    }
  return 0;
}

void siblings(tree_t *t,int node) {  
    tree_t *pos = search_pos(t,node); 
    tree_t *nodepos = pos;
    tree_t *parentpos = search_pos(t,pos->parent); 
    
    if (pos->parent  == -1) {
      printf("\n");
      return;
    }

    pos = parentpos->first_child;
    while (pos != NULL)
    {
      if (pos == nodepos)
      {
        pos = pos->next_sibling;
        if (pos == NULL)
        {
          break;
        }
      }
      printf("%d ",pos->value);
      pos = pos->next_sibling;
    }
    printf("\n");
}

int depth(tree_t *t,int node) {
    int c = 0;
    tree_t *pos = search_pos(t,node);
  while (pos->parent != -1) {
    pos = search_pos(t, pos->parent);
    c++;
  }
    return c;
}

void path(tree_t *t,int start, int end) { //prints the path backwards
    tree_t *pos = search_pos(t,start);
    if (pos == NULL)
    {
      return;
    }
    if (pos->parent == end)
    {
      printf("%d %d ",pos->parent,pos->value);
      return;
    }
    path(t,pos->parent,end);
    printf("%d ",pos->value);

}

void print_path(tree_t *t,int start,int end) {
    
    tree_t *pos = search_pos(t,end);
    if (pos->parent == -1)
    {
      printf("%d",pos->value);
    }   
    path(t,end,start);
    printf("\n");
}



int path_length(tree_t *t,int start,int end) {
    return (depth(t,end) - depth(t,start) + 1);
}

void doancestor(tree_t *t,int node) {
    tree_t *pos = search_pos(t,node);
    if (pos->parent == -1)
      printf("%d ",pos->value);
    if (pos->parent != -1)
    {
      
      doancestor(t,search_pos(t,pos->parent)->value);
      printf("%d ",pos->value);
    
    }
    
    
}

void ancestor(tree_t *t,int node) {
  doancestor(t,node);
  printf("\n");
}




// queue functions ------------------------------------------------------------------
void enqueue(queue_t *q,tree_t *t) {
  queuenode_t *newnode = (queuenode_t *)malloc(sizeof(queuenode_t));
  newnode->next = NULL;
  newnode->child = t;
  if (q->front == NULL) {
    q->front = newnode;
    q->rear = newnode;
  } else {
    q->rear->next = newnode;
    q->rear = newnode;
  }

}                    
tree_t *dequeue(queue_t *q) {
  tree_t *tmp = q->front->child;
  queuenode_t *oldfront = q->front;
  q->front = q->front->next;
  free(oldfront);
  return tmp;
}
// queue functions ------------------------------------------------------------------

void bfs(tree_t *t) {
  tree_t *tmp = t;
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));
  q->front = NULL;
  q->rear = NULL;

  while (t != NULL)
  {
    if (tmp->next_sibling != NULL) //has siblings
    {
      while (tmp !=NULL)
      {
        printf("%d ",tmp->value);
        if (tmp->first_child != NULL)
        {
          enqueue(q,tmp->first_child);
        }
        tmp = tmp->next_sibling;
      }
      
    } else { //no siblings
      printf("%d ",tmp->value);
      if (tmp->first_child != NULL)
      {
        enqueue(q,tmp->first_child);
      }
    }
    if (q->front != NULL) { 
      tmp = dequeue(q);
    } else {
      break;
    }
  }

}
void descendant(tree_t *t,int node) {
    tree_t *pos = search_pos(t,node);
    printf("%d ",node);
    bfs(pos->first_child);
    
}
void dodfs(tree_t *t) {
    tree_t *pos = t;
    if (pos != NULL)
    {
      printf("%d ",pos->value);
    }
    if (pos->first_child != NULL)
    {
      dodfs(pos->first_child);
    }
    if (pos->next_sibling != NULL)
    {
      dodfs(pos->next_sibling);
    }
}
void dfs(tree_t *t) {
  dodfs(t);
  printf("\n");
}

void doprint_tree(tree_t *t , int value) {
    tree_t *pos = search_pos(t,value);
    if (pos != NULL)
    {
      for (int i = 0; i < depth(t,pos->value); i++)
      {
        printf("    ");
      }
      printf("%d\n",pos->value);
    }
    if (pos->first_child != NULL)
    {
      doprint_tree(t,pos->first_child->value);
    }
    if (pos->next_sibling != NULL)
    {
      doprint_tree(t,pos->next_sibling->value);
    }

}

void print_tree(tree_t *t){
  doprint_tree(t,t->value);
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
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}