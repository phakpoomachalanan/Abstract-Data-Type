#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next_sibling;
    struct node* first_child;
}
node_t;
typedef node_t tree_t;

tree_t* attach(tree_t* t, int parent, int child);
tree_t* detach(tree_t* t, int nodeValue);
node_t* searchNode(tree_t* t, int node);
int search(node_t* t, int node);

int main(void)
{
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &command);
    switch(command)
    {
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
/*      case 4:
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
        next_siblings(t, node);
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
        break;*/
    }
  }
  return 0;
}

tree_t* attach(tree_t* t, int parent, int child)
{
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node_t* pos  = searchNode(t, parent);

    node->value = child;

    if (t == NULL)
    {
        t = node;
        return t;
    }

    if (pos->first_child == NULL)
    {
        pos->first_child = node;
    }
    else
    {
        pos = pos->first_child;
        while (pos->next_sibling != NULL)
        {
            pos = pos->next_sibling;
        }
        pos->next_sibling = node;
    }

    return t;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!
tree_t* detach(tree_t* t, int nodeValue)
{
    node_t* node = NULL;
    node = searchNode(t, nodeValue);

    if (node->next_sibling != NULL)
    {
        node = node->next_sibling;
        printf("130: %p %d\n", node, node->value);
    }
    else
    {
        node->first_child = NULL;
        node->next_sibling = NULL;
    }

    return t;
}

node_t* searchNode(tree_t* t, int node)
{
    node_t* pos = NULL;

    if (t == NULL || t->value == node)
    {
        return t;
    }

    pos = searchNode(t->first_child, node);
    if (pos != NULL)
    {
        return pos;
    }

    return searchNode(t->next_sibling, node);
}

int search(node_t* t, int node)
{
    if (t == NULL)
    {
        return 0;
    }
    else if (t->value == node)
    {
        printf("165: %p %d\n", t, t->value);
        return 1;
    }

    if (search(t->first_child, node))
    {
        printf("173: %p %d\n", t, t->value);
        return 1;
    }
    printf("176: %p %d\n", t, t->value);
    return search(t->next_sibling, node);
}