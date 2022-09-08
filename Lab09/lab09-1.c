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
                scaanf("%d", &data);
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
    return NULL;
}

bst_t* delete(bst_t* t, int data)
{
    return NULL;
}

int find(bst_t* t, int data)
{
    return 0;
}

int find_min(bst_t* t)
{
    return 0;
}

int find_max(bst_t* t)
{
    return 0;
}