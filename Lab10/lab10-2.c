#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node* left;
    struct node* right;
    char   word[15];
    int    frequency;
    int    isBranch;
} 
node_t;

typedef struct heap
{
    node_t **data;
    int     last_index;
}
heap_t;

heap_t* init_heap(int m);
node_t* init_node(char word[], int frequency);
node_t* init_tree(node_t* node1, node_t* node2);
void insert(heap_t* h, node_t* data);
node_t* delete(heap_t* h);
void print(node_t* t, int now);
void percolate_up(heap_t* h, node_t* data, int now);
void percolate_down(heap_t* h, int now);
void print_binary(node_t* t, char* path, char bit, int depth);

int main(void)
{
    heap_t* h = NULL;
    node_t* node1 = NULL;
    node_t* node2 = NULL;
    int     data, n, i;
    int     frequency;
    char    word[15];
    char*   path;
    char    c;

    scanf("%d%c", &n, &c);
    h = init_heap(n);
    for (i=0; i<n; i++)
    {
        scanf("%s %d%c", word, &frequency, &c);
        insert(h, init_node(word, frequency));
    }
    for (i=1; i<n; i++)
    {
        if (h->last_index < 2)
        {
            break;
        }
        node1 = delete(h);
        node2 = delete(h);
        insert(h, init_tree(node1, node2));
    }
    path = (char*)malloc(sizeof(char) * n);
    print_binary(h->data[1], path, '0', 0);

    return 0;
}

heap_t* init_heap(int m)
{
    heap_t* h = (heap_t*)malloc(sizeof(heap_t));

    h->data = (node_t**)malloc(sizeof(node_t*) * m);
    h->last_index = 1;

    return h;
}

node_t* init_node(char word[], int frequency)
{
    node_t* n = (node_t*)malloc(sizeof(node_t));

    n->isBranch = 0;
    n->frequency = frequency;
    strcpy(n->word, word);

    return n;
}

node_t* init_tree(node_t* node1, node_t* node2)
{
    node_t* n = (node_t*)malloc(sizeof(node_t));

    n->isBranch = 1;
    n->frequency = node1->frequency + node2->frequency;
    n->left = node1;
    n->right = node2;
    strcpy(n->word, " ");
    
    return n;
}

void insert(heap_t* h, node_t* data)
{
    h->data[h->last_index++] = data;
    percolate_up(h, data, h->last_index-1);
}

node_t* delete(heap_t* h)
{
    node_t* temp;

    temp = h->data[1];
    h->data[1] = h->data[--h->last_index];
    percolate_down(h, 1);

    return temp;
}

void percolate_up(heap_t* h, node_t* data, int now)
{
    node_t* temp;

    while (now/2 > 0 && data->frequency < h->data[now/2]->frequency)
    {
        temp = h->data[now/2];
        h->data[now/2] = h->data[now];
        h->data[now] = temp;

        now /= 2;
    }
}

void percolate_down(heap_t* h, int now)
{
    node_t* temp;
    int index;

    while (now*2 < h->last_index)
    {
        if (h->data[now]->frequency <= h->data[now*2]->frequency && h->data[now]->frequency <= h->data[now*2+1]->frequency)
        {
            break;
        }
        if (h->data[now*2+1]->frequency < h->data[now*2]->frequency)
        {
            index = now*2+1;
        }
        else
        {
            index = now*2;
        }
        temp = h->data[index];
        h->data[index] = h->data[now];
        h->data[now] = temp;

        now = index == now * 2 ? now*2 : now*2+1;
    }
}

void print_binary(node_t* t, char* path, char bit, int depth)
{
    if (t == NULL)
    {
        return;
    }

    path[depth] = bit;

    if (t->isBranch == 0)
    {
        printf("%s: ", t->word);
        for (int i=1; i<=depth; i++)
        {
            printf("%c", path[i]);
        }
        printf("\n");
        return;
    }
    print_binary(t->left, path, '0', depth+1);
    print_binary(t->right, path, '1', depth+1);
}