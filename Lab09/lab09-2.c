#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t avl_t;
#endif

avl_t* insert(avl_t* t, int data);
avl_t* delete(avl_t* t, int data);
avl_t* create(int data);
avl_t* left_rotation(avl_t* t);
avl_t* right_rotation(avl_t* t);
avl_t* balance(avl_t* t, int data);
avl_t* search_left(avl_t* t);
int height(avl_t* t);
int max_value(int left, int right);
int balance_factor(avl_t* t);

int main(void) {
    avl_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
                break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                print_tree(t);
                break;
        }
    }
    return 0;
}

avl_t* insert(avl_t* t, int data)
{
    int bf = 0;

    if (t == NULL)
    {
        return create(data);
    }
    if (data < t->data)
    {
        t->left = insert(t->left, data);
    }
    else if (data > t->data)
    {
        t->right = insert(t->right, data);
    }
    t->height = 1 + max_value(height(t->left), height(t->right));

    bf = balance_factor(t);

    if (bf > 1)
    {
        if (data < t->left->data)
        {
            return right_rotation(t);
        }
        t->left = left_rotation(t->left);
        return right_rotation(t);
    }
    else if (bf < -1)
    {
        if (data > t->right->data)
        {
            return left_rotation(t);
        }
        t->right = right_rotation(t->right);
        return left_rotation(t);
    }

    return t;
}

avl_t* delete(avl_t* t, int data)
{
    node_t* node = NULL;
    int bf = 0;
    if (t == NULL)
    {
        return t;
    }

    if (data > t->data)
    {
        t->right = delete(t->right, data);
    }
    else if (data < t->data)
    {
        t->left = delete(t->left, data);
    }
    else
    {
        if (t->left == NULL)
        {
            node = t->right;
            free(t);
            return node;
        }
        else if (t->right == NULL)
        {
            node = t->left;
            free(t);
            return t;
        }
        node = search_left(t->right);
        t->data = node->data;
        t->right = delete(t->right, node->data);
    }
    t->height = 1 + max_value(height(t->left), height(t->right));

    bf = balance_factor(t);

    if (bf > 1)
    {
        if (balance_factor(t->left) >= 0)
        {
            return right_rotation(t);
        }
        t->left = left_rotation(t->left);
        return right_rotation(t);
    }
    else if (bf < -1)
    {
        if (balance_factor(t->right) <= 0)
        {
            return left_rotation(t);
        }
        t->right = right_rotation(t->right);
        return left_rotation(t);
    }

    return t;
}

avl_t* create(int data)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));

    node->data = data;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
}

avl_t* left_rotation(avl_t* t)
{
    node_t* root = t->right;
    node_t* node = root->left;

    root->left = t;
    t->right = node;

    t->height = height(t);
    root->height = height(root);

    return root;
}

avl_t* right_rotation(avl_t* t)
{
    node_t* root = t->left;
    node_t* node = root->right;

    root->right = t;
    t->left = node;

    t->height = height(t);
    root->height = height(root);

    return root;
}

avl_t* search_left(avl_t* t)
{
    return t->left == NULL ? t : search_left(t->left);
}

int height(avl_t* t)
{
    return t == NULL ? -1 : 1 + max_value(height(t->left), height(t->right));
}

int max_value(int left, int right)
{
    return left > right ? left : right;
}

int balance_factor(avl_t* t)
{
    return t == NULL ? 0 : height(t->left) - height(t->right);
}