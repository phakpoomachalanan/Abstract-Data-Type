#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
    int    data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

void print_preorder(tree_t* t);
void print_postorder(tree_t* t);
void print_inorder(tree_t* t);
void print_order(tree_t* t, int mode);

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }

    print_preorder(t);
    print_postorder(t);
    print_inorder(t);

    return 0;
}

void print_preorder(tree_t* t)
{
    print_order(t, 1);
    printf("\n");
}

void print_postorder(tree_t* t)
{
    print_order(t, 2);
    printf("\n");
}

void print_inorder(tree_t* t)
{
    print_order(t, 3);
    printf("\n");
}

void print_order(tree_t* t, int mode)
{
    if (t == NULL)
    {
        return;
    }

    mode == 1 ? printf("%d ", t->data) : print_order(t->left, mode);
    mode == 1 ? print_order(t->left, mode) : 
    mode == 2 ? print_order(t->right, mode) : printf("%d ", t->data);
    mode == 2 ? printf("%d ", t->data) : print_order(t->right, mode);
}