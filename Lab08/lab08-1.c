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

int is_full(tree_t* t);


int is_degenerate(tree_t* t);


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

    //printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));
    printf("%d - - %d -\n", is_full(t), is_degenerate(t));

    return 0;
}

int is_full(tree_t* t)
{
    if (t == NULL)
    {
        return 1;
    }
    if (t->left == NULL && t->right == NULL)
    {
        return 1;;
    }
    if (t->left != NULL && t->right != NULL)
    {
        return is_full(t->left) && is_full(t->right);
    }
    return 0;
}

int is_degenerate(tree_t* t)
{
    if (t == NULL)
    {
        return 1;
    }
    if (t->left == NULL && t->right == NULL)
    {
        return 1;
    }
    if ((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL))
    {
        return is_degenerate(t->left) && is_degenerate(t->right);
    }
    return 0;
}