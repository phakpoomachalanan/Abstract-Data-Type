#include <stdio.h>
#include <stdlib.h>
#include <week8.h>

#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

void doprint_preorder(tree_t *t) {
    if (t!= NULL)
    {
        printf("%d ",t->data);
        if (t->left != NULL)
        {
            doprint_preorder(t->left);
        }
        if (t->right != NULL)
        {
            doprint_preorder(t->right);
        }
    }
     
}
void print_preorder(tree_t *t) {
    doprint_preorder(t);
    printf("\n");
}
void doprint_postorder(tree_t *t) {
    if (t!=NULL)
    {
        if (t->left != NULL)
        {
            doprint_postorder(t->left);
        }
        
        if (t->right != NULL)
        {
            doprint_postorder(t->right);
        }
        printf("%d ",t->data);
    }
    
}
void print_postorder(tree_t *t) {
    doprint_postorder(t);
    printf("\n");
}
void doprint_inorder(tree_t *t) {
    if (t!=NULL)
    {
        if (t->left != NULL)
        {
            doprint_inorder(t->left);
        }
        printf("%d ",t->data);
        if (t->right != NULL)
        {
            doprint_inorder(t->right);
        }
        
    }
    
}
void print_inorder(tree_t *t) {
    doprint_inorder(t);
    printf("\n");
}

int main(void) {
    tree_t *t = NULL;
    int  n,i;
    int parent,child;
    int branch; //0root 1left 2right

    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d",&parent,&child,&branch);
        t = attach(t,parent,child,branch);
    }

    print_preorder(t);
    print_postorder(t);
    print_inorder(t);

    return 0;
}