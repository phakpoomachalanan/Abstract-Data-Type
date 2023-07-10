#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;

heap_t* init_heap(int m);
void insert(heap_t* h, int data);
void delete_max(heap_t* h);
int find_max(heap_t* h);
void update_key(heap_t* h, int old_key, int new_key);
void bfs(heap_t* h);

void percolate_up(heap_t* h, int data, int now);
void percolate_down(heap_t* h, int now);
int find_index(heap_t* h, int data, int now);

int main (void) {
    heap_t *max_heap = NULL;
    int    m, n, i;
    int    command, data;
    int    old_key, new_key;

    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key, new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}

heap_t* init_heap(int m)
{
    heap_t* h = (heap_t*)malloc(sizeof(heap_t));

    h->data = (int*)malloc(sizeof(int) * m);
    h->last_index = 1;

    return h;
}

void insert(heap_t* h, int data)
{
    h->data[h->last_index++] = data;
    percolate_up(h, data, h->last_index-1);
}

void delete_max(heap_t* h)
{
    h->data[1] = h->data[--h->last_index];
    percolate_down(h, 1);
}

int find_max(heap_t* h)
{
    return h->last_index <= 1 ? -1 : h->data[1];
}

void update_key(heap_t* h, int old_key, int new_key)
{
    int index = find_index(h, old_key, 1);

    h->data[index] = new_key;

    if (new_key > h->data[index/2])
    {
        percolate_up(h, new_key, index);
    }
    else if (index * 2 < h->last_index-1)
    {
        percolate_down(h, index);
    }
}

void bfs(heap_t* h)
{
    int now = 1;

    while (now < h->last_index)
    {
        printf("%d ", h->data[now++]);
    }
    printf("\n");
}

void percolate_up(heap_t* h, int data, int now)
{
    int temp;    

    while (now/2 > 0 && data > h->data[now/2])
    {
        temp = h->data[now/2];
        h->data[now/2] = h->data[now];
        h->data[now] = temp;

        now /= 2;
    }
}

void percolate_down(heap_t* h, int now)
{
    int temp;
    int index;

    while (now*2+1 < h->last_index)
    {
        if (h->data[now] > h->data[now*2] && h->data[now] > h->data[now*2+1])
        {
            break;
        }
        if (h->data[now*2+1] > h->data[now*2])
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

int find_index(heap_t* h, int data, int now)
{
    return h->data[now] == data ? now : find_index(h, data, now+1);
}