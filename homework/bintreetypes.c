#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t tree_t;
#endif

int height(tree_t *t) {
    if (t == NULL)
    {
        return -1;
    }
    int hl = 0;
    int hr = 0;
    if (t->left != NULL)
        hl = height(t->left);
    if (t->right != NULL)
        hr = height(t->right);
    if (hl>hr)
    {
        return hl+1;
    } else {
    return hr+1;
    }
}

int countnode(tree_t *t) {
    int c = 0;
    if (t == NULL)
    {
        return 0;
    }
    if (t->left != NULL)
    {
        c = countnode(t->left);
    }
    if (t->right != NULL)
    {
        c = countnode(t->right);
    }
    return c+1;
}

int countleaf(tree_t *t) {
    int c = 0;
    if (t == NULL)
    {
        return 0;
    }
    if (t->left != NULL)
    {
        c = countleaf(t->left);
    }
    if (t->right != NULL)
    {
        c = countleaf(t->right);
    }
    if (t->left == NULL && t->right == NULL)
    {
        return c+1;
    }
    return c;
    
}

int is_full(tree_t *t) {
    /*dfs traverse throuht whole tree
    if left == NULL xor right == NULL then return 0
    else return 1
    */
    if (t == NULL)
    {
        return 0;
    }
    if ((t->left == NULL) != (t->right == NULL))
    {
        return 0;
    }
    
    if (t->left != NULL)
    {
        is_full(t->left);
    }
    if (t->right != NULL)
    {
        is_full(t->right);
    }
    return 1;
}

int is_perfect(tree_t *t) {
    /*dfs traverse through whole tree while counting nodes
    h = height(t)
    if nodecount == (2 pow h)-1 and countleaf(t) = (2 pow h)
        return 1
    else return 0
    */
    if (t == NULL)
    {
        return 0;
    }

}

int is_complete(tree_t *t) {
    /*dfs traverse
    if left == NULL and right != NULL
        return 0

    if (left->left and left->right == NULL) and (right->left and right->right != NULL)
        return 0
    else return 1
    */
    if (t == NULL)
    {
        return 0;
    }
}

int is_degenerate(tree_t *t) {
    /*
    if left != NULL and right != NULL
        return 0
    else return 1
    */
    if (t == NULL)
    {
        return 0;
    }
    if (t->left != NULL && t->right != NULL)
    {
        return 0;
    }
    
    if (t->left != NULL)
    {
        is_degenerate(t->left);
    }
    if (t->right != NULL)
    {
        is_degenerate(t->right);
    }
    return 1;

}

int is_skewed(tree_t *t) {
    
    /*if root has both
        return 0
    if root has left child
        if right != NULL
            return 0
        else return 1

    if root has right child
        if left != NULL
            return 0
        else return 1
    
    */
    if (t == NULL)
    {
        return 0;
    }
    
    
    if (t->left != NULL)
    {
        if (t->right != NULL)
        {
            return 0;
        }
        is_skewed(t->left);
    }
    if (t->right != NULL)
    {
        if (t->left != NULL)
        {
            return 0;
        }
        is_skewed(t->right);
    }
    return 1;
    
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

    printf("%d %d %d %d %d\n",is_full(t),is_perfect(t),is_complete(t),is_degenerate(t),is_skewed(t));
    return 0;
}