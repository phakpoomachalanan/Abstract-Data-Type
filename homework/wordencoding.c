#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    struct node* left;
    struct node* right;
    char   str[15];
    int    freq;
} 
node_t;
typedef node_t tree_t;

typedef struct heap {
    tree_t **data;
    int last_index;
} heap_t;


heap_t *init_heap(int n) {
    heap_t *h = (heap_t*)malloc(sizeof(heap_t));
    h->data = (tree_t**)malloc(sizeof(tree_t*)*n);
    h->last_index = 0;
    return h;
}

void insert(heap_t *h,tree_t *t,char str[],int freq) {
    //single node bintree
    tree_t *t = (tree_t*)malloc(sizeof(tree_t));
    t->freq = freq;
    strcpy(t->str, str);
    
    //priority queue
    h->last_index++;
    int i = h->last_index;
    h->data[i] = t;
    tree_t* tmp;
    while (i/2 > 0 && t->freq < h->data[i/2]->freq) // compare with parent 
    {
        tmp = h->data[i/2];
        h->data[i/2] = h->data[i];
        h->data[i] = tmp;
        i = i/2;
    }
}

void insertnewtree(heap_t *h,tree_t *newt) {
    //priority queue
    h->last_index++;
    int i = h->last_index;
    h->data[i] = newt;
    tree_t* tmp;
    while (i/2 > 0 && newt->freq < h->data[i/2]->freq) // compare with parent 
    {
        tmp = h->data[i/2];
        h->data[i/2] = h->data[i];
        h->data[i] = tmp;
        i = i/2;
    }
}

tree_t *delete_min(heap_t *h) {
    int i = 1;
    tree_t *deleted = h->data[1];
    h->data[1] = h->data[h->last_index];
    tree_t *tmp;
    
    while (2*i+1 < h->last_index && (h->data[i] > h->data[2*i] || h->data[i] > h->data[2*i+1])) //compare with children
    {
        
        if (h->data[2*i] < h->data[i]) 
        {
            tmp = h->data[i];
            h->data[i] = h->data[2*i];
            h->data[2*i] = tmp;
            i = i*2;
        }
        else if (h->data[2*i+1] < h->data[i])
        {
            tmp = h->data[i];
            h->data[i] = h->data[2*i+1];
            h->data[2*i+1] = tmp;
            i = i*2+1;
        }
    }
    h->last_index--;
    return deleted;
}

int main (void) {
    heap_t *h = NULL;
    tree_t *t = NULL;
    int     data,n,freq;
    char    str[15];
    char    a;

    scanf("%d%c", &n, &a);
    h = init_heap(n);
    
    for (int i=0; i<n; i++)
    {
        scanf("%s %d%c", str, &freq, &a);
        insert(h,t,str,freq);
    }
    
    tree_t *min1;
    tree_t *min2;
    while (h->last_index > 1)
    {
   
        min1 = delete_min(h);
        min2 = delete_min(h);
        
        tree_t *newt = (tree_t*)malloc(sizeof(tree_t));
        newt->freq = min1->freq + min2->freq;
        strcpy(newt->str,"mty");

        newt->left = min1;
        newt->right = min2;
        
        insertnewtree(h,newt);

    }
    
    tree_t *finaltree = h->data[1];
    
    return 0;
}