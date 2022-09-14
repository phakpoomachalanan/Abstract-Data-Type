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

void insert(heap_t* h, node_t* node);
node_t* delete(heap_t* h);

void percolate_up(heap_t* h, node_t* node, int now);
void percolate_down(heap_t* h, int now);
void bfs(heap_t* h);
void print(node_t* t, int now);

int main(void)
{
    heap_t* h = NULL;
    node_t* node = NULL;
    node_t* node1 = NULL;
    node_t* node2 = NULL;
    int     data, n, i;
    int     frequency;
    char    word[15];
    char    c;

    scanf("%d%c", &n, &c);
    h = init_heap(n);
    for (int i=0; i<n; i++)
    {
        scanf("%s %d%c", word, &frequency, &c);
        insert(h, init_node(word, frequency));
    }
    printf("\n");
    bfs(h);
    for (i=1; i<n-1; i++)
    {
        node1 = delete(h);
        node2 = delete(h);
        node = init_tree(node1, node2);
        insert(h, node);
    }
    //printf("\n");
    //bfs(h);
    print(h->data[1], 1);
    printf("\n");

    return 0;
}

heap_t* init_heap(int n)
{
    heap_t* h = (heap_t*)malloc(sizeof(heap_t));

    h->data = (node_t**)malloc(sizeof(node_t*) * n);
    h->last_index = 0;

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

    printf("%3d = %s%3d + %s%3d\n", n->frequency, node1->word, node1->frequency, node2->word, node2->frequency);
    
    return n;
}

void insert(heap_t* h, node_t* node)
{
    h->data[h->last_index++] = node; //printf("102");
    percolate_up(h, node, h->last_index-1);
}

node_t* delete(heap_t* h)
{
    node_t* min = h->data[1]; 

    h->data[1] = h->data[--h->last_index];
    //printf("111 ");
    percolate_down(h, 1);
    //printf("113 ");
    return min;
}

void percolate_up(heap_t* h, node_t* data, int now)
{
    node_t* temp;    

    while (now/2 > 0 && data < h->data[now/2])
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

    while (now*2+1 < h->last_index)
    {
        if (h->data[now] < h->data[now*2] && h->data[now] < h->data[now*2+1])
        {
            break;
        }
        if (h->data[now*2+1] < h->data[now*2])
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

        now *= 2;
    }
}

void bfs(heap_t* h)
{
    int now = 0;

    while (now < h->last_index)
    {
        printf("%s %d\n", h->data[now]->word, h->data[now]->frequency);
        now++;
    }
    printf("\n");
}

void print(node_t* t, int now)
{
    if (t == NULL)
    {
        return;
    }
    t->isBranch == 0 ? printf("|%s %d |",t->word, t->frequency) : printf("\n%d\n", t->frequency);
    print(t->left, now);
    print(t->right, now);
}