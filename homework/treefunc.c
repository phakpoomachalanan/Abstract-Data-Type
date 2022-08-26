#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    int parent;
    struct node *next_sibling;
    struct node *first_child;
    } node_t;
typedef node_t tree_t;

tree_t *attach(tree_t *t,int parent,int child) {
    tree_t *newnode = (tree_t*)malloc(sizeof(tree_t));
    tree_t *pos = search_pos(t,parent);
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
    pos->parent = parent;
    return t;
}

tree_t *detach(tree_t *t,int node) {
    tree_t *childpos = search_pos(t,node);
    tree_t *parentpos = search_pos(t,childpos->parent);
    parentpos->first_child = NULL;
    /* make an array
    append all children to array
    searchpos for each child
    free every children*/
    return t;
}

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

int search(tree_t *t,int node) {
    if (search_pos(t,node) != NULL) {
        return 1;
    }
    return 0;
}

int degree(tree_t *t,int node) {
    int c = 0;
    tree_t *pos = search_pos(t,node);
    pos = pos->first_child;
    while (pos != NULL)
    {
      pos = pos->next_sibling;
      c++;
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
    pos = pos->first_child;
    while (pos != NULL)
    {
      printf("%d ",pos->value);
      pos = pos->next_sibling;     
    }
    printf("\n");
}

int depth(tree_t *t,int node) {
    int c =0;
    tree_t *tmp = t;
    tree_t *pos = search_pos(t,node);
    while (tmp != pos)
    {
      tmp = tmp->first_child;
      c++;
    }
    return c;
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

void path(tree_t *t,int start, int end) {
    tree_t *pos = search_pos(t,start);


    if (pos->parent == end)
    {
      printf("%d %d",pos->parent,pos->value);
    }
    path(t,pos->parent,end);
    printf("%d ",pos->value);

}


int path_length(tree_t *t,int start,int end) {

}

void ancestor(tree_t *t,int node) {
    tree_t *pos = search_pos(t,node);
    
    while (pos->parent != -1)
    {
      printf("%d ",pos->value);
      pos = search_pos(t,pos->parent);
    }
    
    printf("%d",pos->value);
    
}

void descendant(tree_t *t,int node) {
    tree_t *pos = search_pos(t,node);
    int temp = depth(t,node);
    
    

    
}

void bfs(tree_t *t) {

}

void dfs(tree_t *t) {

}

void print_tree(tree_t *t) {

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