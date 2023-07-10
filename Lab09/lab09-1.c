#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}
node_t;

typedef node_t bst_t;

bst_t* insert(bst_t* t, int data);
bst_t* delete(bst_t* t, int data);
bst_t* create(int data);
bst_t* search_left(bst_t* t);
bst_t* search_right(bst_t* t);
bst_t* search(bst_t* t, int data);
int find(bst_t* , int data);
int find_min(bst_t* t);
int find_max(bst_t* t);

int main(void) {
    bst_t* t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
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
                scanf("%d", &data);
                printf("%d\n", find(t, data));
                break;
            case 4:
                printf("%d\n", find_min(t));
               break;
            case 5:
                printf("%d\n", find_max(t));
                break;
        }
    }
    return 0;
}

bst_t* insert(bst_t* t, int data)
{
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

    return t;
}

bst_t* delete(bst_t* t, int data)
{
    node_t* node = NULL;
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
            return node;
        }
        node = search_left(t->right);
        t->data = node->data;
        t->right = delete(t->right, node->data);
    }

    return t;
}

bst_t* create(int data)
{
    node_t* node = (node_t*)malloc(sizeof(node_t));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bst_t* search_left(bst_t* t)
{
    return t->left == NULL ? t : search_left(t->left);
}

bst_t* search_right(bst_t* t)
{
    return t->right == NULL ? t : search_right(t->right);
}

bst_t* search(bst_t* t, int data)
{
    node_t* node = NULL;

    if (t == NULL || t->data == data)
    {
        return t;
    }

    node = search(t->left, data);
    if (node != NULL)
    {
        return node;
    }
    return search(t->right, data);

    return NULL;
}

int find(bst_t* t, int data)
{
    return search(t, data) == NULL ? 0 : 1;
}

int find_min(bst_t* t)
{
    return t->left == NULL ? t->data : find_min(t->left);
}

int find_max(bst_t* t)
{
    return t->right == NULL ? t->data : find_max(t->right);
}