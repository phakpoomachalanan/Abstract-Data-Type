#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    int parent;
    int sibling;
    struct node* next_sibling;
    struct node* first_child;
}
node_t;
typedef node_t tree_t;

tree_t* attach(tree_t* t, int parent, int child);
tree_t* detach(tree_t* t, int nodeValue);
node_t* searchNode(tree_t* t, int value);
int search(tree_t* t, int value);
int degree(node_t* t, int value);
int is_root(tree_t* t, int value);
int is_leaf(tree_t *t, int value);
void siblings(tree_t *t, int value);
int depth(tree_t* t, int value);
void print_path(tree_t *t, int start, int end);
void check_path(tree_t* t, int start, int end);
int path_length(tree_t* t, int start, int end);
void ancestor(tree_t* t, int node);
//void descendant(tree_t* t, int node);
//void bfs(tree_t *t);
void dfs(tree_t* t);
node_t* searchDepth(tree_t* t, int depth);
void print_tree(tree_t* t);

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

tree_t* attach(tree_t* t, int parent, int child)
{
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node_t* pos  = searchNode(t, parent);
    int sibling;

    node->value = child;
    node->parent = parent;

    if (t == NULL)
    {
        t = node;
        return t;
    }

    if (pos->first_child == NULL)
    {
        pos->first_child = node;
        pos->sibling = child;
        return t;
    }
    else
    {
        pos = pos->first_child;
        node->sibling = pos->value;
        while (pos->next_sibling != NULL)
        {
            pos = pos->next_sibling;
        }
        pos->next_sibling = node;
    }
    pos->next_sibling->sibling = sibling;

    return t;
}

tree_t* detach(tree_t* t, int nodeValue)
{
    node_t* node = NULL;
    node_t* siblingNode = NULL;
    node_t* parentNode = NULL;

    if (t->value == nodeValue)
    {
        free(t);
        return NULL;
    }

    node = searchNode(t, nodeValue);

    parentNode = searchNode(t, node->parent);
    if (parentNode->first_child == node)
    {
        parentNode->first_child = node->next_sibling;
    }
    else
    {
        siblingNode = parentNode->first_child;
        while (siblingNode->next_sibling->value != nodeValue)
        {
            siblingNode = siblingNode->next_sibling;
        }
        siblingNode->next_sibling = siblingNode->next_sibling->next_sibling;
    }

    return t;
}

node_t* searchNode(tree_t* t, int value)
{
    node_t* pos = NULL;

    if (t == NULL || t->value == value)
    {
        return t;
    }

    pos = searchNode(t->first_child, value);
    if (pos != NULL)
    {
        return pos;
    }

    return searchNode(t->next_sibling, value);
}

int search(node_t* t, int value)
{
    return searchNode(t, value) == NULL ? 0 : 1;
}

int degree(node_t* t, int value)
{
    node_t* node = searchNode(t, value);
    int child = 1;

    node = node->first_child;

    if (node == NULL)
    {
        return 0;
    }

    while (node->next_sibling != NULL)
    {
        child++;
        node = node->next_sibling;
    }

    return child;
}

int is_root(tree_t* t, int value)
{
    return searchNode(t, value)->parent == -1 ? 1 : 0;
}

int is_leaf(tree_t *t, int value)
{
    return searchNode(t, value)->first_child == NULL ? 1 : 0;
}

void siblings(tree_t *t, int value)
{
    node_t* node = searchNode(t, value);
    node = searchNode(t, node->sibling);

    while (node->next_sibling != NULL)
    {
        printf("%d ", node->value);
        node = node->next_sibling;
    }
}

int depth(tree_t* t, int value)
{
    node_t* node = searchNode(t, value);
    if (search(t, node->parent) != 1)
    {
        return 0;
    }
    return 1 + depth(t, node->parent);
}

void print_path(tree_t* t, int start, int end)
{
    if (start == end)
    {
        printf("%d\n",  start);
        return;
    }
    check_path(t, end, start);
    printf("\n");
}

void check_path(tree_t* t, int start, int end)
{
    node_t* node = searchNode(t, start);
    if (node->parent == -1)
    {
        return;
    }
    if (node->parent == end)
    {
        printf("%d %d ", node->parent, node->value);
        return;
    }

    check_path(t, node->parent, end);
    printf("%d ", node->value);
}

int path_length(tree_t* t, int start, int end)
{
    return 1 + depth(t, end) - depth(t, start);
}

void ancestor(tree_t* t, int node)
{
    print_path(t, t->value, node);
}
/*
void descendant(tree_t* t, int value)
{
    bfs(searchNode(t, value));
    printf("\n");
}

void bfs(tree_t* t)
{
    fake_bfs(t, 0);
    printf("\n");
}

void fake_bfs(tree_t* t, int mode)
{
    node_t* pos = NULL;

    if (t == NULL)
    {
        return;
    }

    for (int i=0; i<2; i++)
    {
        pos = t;
        while (pos != NULL)
        {
            i == 0 ? printf("%d ", pos->value) : bfs(pos->first_child);
            pos = pos->next_sibling;
        }
    }

}

void fake_bfs(tree_t* t, int mode)
{
    node_t* pos = NULL;

    if (t == NULL)
    {
        return;
    }

    for (int i=0; i<2; i++)
    {
        pos = t;
        while (pos != NULL)
        {
            i == 0 ? printf("%d ", pos->value) : fake_bfs(pos->first_child, mode+1);
            pos = pos->next_sibling;
        }
    }

}
*/

void dfs(tree_t* t)
{
    node_t* node = searchDepth(t, -1);
    printf("\n");
}

node_t* searchDepth(tree_t* t, int depth)
{
    node_t* pos = NULL;

    if (t == NULL)
    {
        return t;
    }
    if (depth <= -1)
    {
        printf("%d ", t->value);
    }
    else
    {
        for (int i=0; i<depth; i++)
        {
            printf("    ");
        }
        depth++;
        printf("%d\n", t->value);
    }
    pos = searchDepth(t->first_child, depth);
    if (pos != NULL)
    {
        return pos;
    }

    return searchDepth(t->next_sibling, depth-1);
}

void print_tree(tree_t* t)
{
    searchDepth(t, 0);
}