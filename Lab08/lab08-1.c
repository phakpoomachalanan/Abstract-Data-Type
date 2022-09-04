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
int is_perfect(tree_t* t);
int find_max_depth(tree_t* t);
int power(int times);
void check_perfect(tree_t* t, int leaf[], int max_leaf, int depth, int max_depth);
int is_leaf(tree_t* t);
int is_complete(tree_t* t);
int check_complete(tree_t* t, int leaf[], int max_leaf, int depth, int max_depth);
void init(int leaf[], int max_leaf);
int is_degenerate(tree_t* t);
int is_skewed(tree_t* t);

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

    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

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

int is_perfect(tree_t* t)
{
    int max_depth = find_max_depth(t);
    int max_leaf = power(max_depth-1);
    int leaf[max_leaf];
    init(leaf, max_leaf);
    check_perfect(t, leaf, max_leaf, 1, max_depth);
    return leaf[max_leaf-1] == 0 ? 0 : 1;
}

int power(int times)
{
    return times == 0 ? 1 : 2 * power(times-1);
}

int find_max_depth(tree_t* t)
{
    return t == NULL ? 0 : 1 + find_max_depth(t->left);
}

void check_perfect(tree_t* t, int leaf[], int max_leaf, int depth, int max_depth)
{
    static int now = 0;

    if (t == NULL || depth > max_depth || now >= max_leaf)
    {
        leaf[max_leaf-1] = 0;
        return;
    }
    if (is_leaf(t) == 1)
    {
        if (depth == max_depth)
        {
            leaf[now] = t->data;
            now++;
        }
        else
        {
            leaf[max_leaf-1] = 0;
        }
        return;
    }

    check_perfect(t->left, leaf, max_leaf, depth+1, max_depth);
    check_perfect(t->right, leaf, max_leaf, depth+1, max_depth);
}

int is_leaf(tree_t* t)
{
    return t->left == NULL && t->right == NULL ? 1 : 0;
}

int is_complete(tree_t* t)
{
    int max_depth = find_max_depth(t);
    int max_leaf = power(max_depth-1);
    int leaf[max_leaf];
    int now;
    init(leaf, max_leaf);
    if (t->left == NULL && t->right == NULL)
    {
        return 1;
    }
    if (is_degenerate(t) == 1 || is_skewed(t) == 1)
    {
        return 0;
    }
    now = check_complete(t, leaf, max_leaf, 1, max_depth);
    return leaf[now] && now >= 0 == 0 ? 0 : 1;
}

int check_complete(tree_t* t, int leaf[], int max_leaf, int depth, int max_depth)
{
    static int now = -1;
    static int is_right = 0;

    if (t == NULL)
    {
        return now;
    }
    if (now <= -2 || (t->left == NULL && t->right != NULL) || depth > max_depth || now >= max_leaf)
    {
        now = -99;
        return now;
    }

    if (is_leaf(t) == 1)
    {
        if (depth == max_depth)
        {
            if (is_right == 1)
            {
                leaf[now] = 0;
                return now;
            }
            now++;
            leaf[now] = t->data;
        }
        else if (depth == max_depth-1)
        {
            now++;
            leaf[now] = t->data;
            is_right = 1;
        }
        else 
        {
            now = -99;
        }
        return now;
    }

    check_complete(t->left, leaf, max_leaf, depth+1, max_depth);
    check_complete(t->right, leaf, max_leaf, depth+1, max_depth);
    return now;
}

void init(int leaf[], int max_leaf)
{
    for (int i=0; i<max_leaf; i++)
    {
        leaf[i] = 0;
    }
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
    if ((t->left != NULL) != (t->right != NULL))
    {
        return is_degenerate(t->left) && is_degenerate(t->right);
    }
    return 0;
}

int is_skewed(tree_t* t)
{
    static int left = 0;
    static int right = 0;
    if (t == NULL)
    {
        return 1;
    }

    if (t->left != NULL)
    {
        left++;
        is_skewed(t->left);
    }
    if (t->right != NULL)
    {
        right++;
        is_skewed(t->right);
    }
    return (left == 0) != (right == 0);
}