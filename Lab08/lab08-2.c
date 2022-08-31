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
tree_t* search(tree_t* t, int mode);

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

}

void print_postorder(tree_t* t)
{

}

void print_inorder(tree_t* t)
{

}