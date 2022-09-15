#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;


heap_t *init_heap(int n) {
    heap_t *h = (heap_t*)malloc(sizeof(heap_t));
    h->data = (int*)malloc(sizeof(int)*n);
    h->last_index = 0;
    return h;
}

void bfs(heap_t *max_heap) {
    for (int i = 1; i <= max_heap->last_index; i++)
    {
        printf("%d ",max_heap->data[i]);
    }
    printf("\n");
}

void insert(heap_t *max_heap,int value) {
    max_heap->last_index++;
    int i = max_heap->last_index;
    max_heap->data[i] = value;
    int tmp;
    while (i/2 > 0 && value > max_heap->data[i/2]) // compare with parent 
    {
        tmp = max_heap->data[i/2];
        max_heap->data[i/2] = max_heap->data[i];
        max_heap->data[i] = tmp;
        i = i/2;
    }
    
}

void delete_max(heap_t *max_heap) {
    int i = 1;
    max_heap->data[1] = max_heap->data[max_heap->last_index];
    int tmp;
    
    while (2*i+1 < max_heap->last_index && (max_heap->data[i] < max_heap->data[2*i] || max_heap->data[i] < max_heap->data[2*i+1])) //compare with children
    {
        
        if (max_heap->data[2*i] > max_heap->data[i]) 
        {
            tmp = max_heap->data[i];
            max_heap->data[i] = max_heap->data[2*i];
            max_heap->data[2*i] = tmp;
            i = i*2;
        }
        else if (max_heap->data[2*i+1] > max_heap->data[i])
        {
            tmp = max_heap->data[i];
            max_heap->data[i] = max_heap->data[2*i+1];
            max_heap->data[2*i+1] = tmp;
            i = i*2+1;
        }
    }
    max_heap->last_index--;
}
int find_pos(heap_t *max_heap, int value) {
    int i = 1;
    while (value != max_heap->data[i])
    {
        i++;
    }
    return i;
}

int find_max(heap_t *max_heap) {
    if (max_heap->last_index<1)
    {
        return -1;
    }
    return max_heap->data[1];
}

void update_key(heap_t *max_heap, int old_key, int new_key) {
    int i = find_pos(max_heap,old_key);
    max_heap->data[i] = new_key;
    int tmp;
    if (new_key > max_heap->data[i/2]) //compare with parent
    {
        while (i/2 > 0 && new_key > max_heap->data[i/2]) // precolate up
        {
            tmp = max_heap->data[i/2];
            max_heap->data[i/2] = max_heap->data[i];
            max_heap->data[i] = tmp;
            i = i/2;
        }
    }
    else if (i*2 < max_heap->last_index-1) //compare with left child
    {
        while (2*i+1 < max_heap->last_index && (max_heap->data[i] < max_heap->data[2*i] || max_heap->data[i] < max_heap->data[2*i+1])) //compare with children
        {
            
            if (max_heap->data[2*i] > max_heap->data[i]) 
            {
                tmp = max_heap->data[i];
                max_heap->data[i] = max_heap->data[2*i];
                max_heap->data[2*i] = tmp;
                i = i*2;
            }
            else if (max_heap->data[2*i+1] > max_heap->data[i])
            {
                tmp = max_heap->data[i];
                max_heap->data[i] = max_heap->data[2*i+1];
                max_heap->data[2*i+1] = tmp;
                i = i*2+1;
            }
        }
    }   
}



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

