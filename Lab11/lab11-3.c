#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int data;
    int mem_addr;
} cell_t;

typedef struct hash {
    cell_t *cell;
    int    cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int    memory_t;

memory_t *init_memory(int size) {
    memory_t *memory = (memory_t *)malloc(sizeof(memory_t)*size);
    int      i = 0;

    // Randomly assign integers to memory
    for (i=0; i<size; i++)
        memory[i] = rand();
    return memory;
}

cache_t* init_cache(int size);
cell_t init_cell(int data, int addr);
void get_data(int addr, memory_t* memory, cache_t* cache);
 
int main(void) {
    memory_t *memory = NULL;
    cache_t  *cache = NULL;
    int      memory_size, cache_size;
    int      i, n, addr;

    scanf("%d %d %d", &memory_size, &cache_size, &n);
    memory = init_memory(memory_size);
    cache = init_cache(cache_size);

    for (i=0; i<n; i++) {
        printf("Load address: ");
        scanf("%d", &addr);
        get_data(addr, memory, cache);
    }
    return 0;
}

cache_t* init_cache(int size)
{
    cache_t* cache = (cache_t*)malloc(sizeof(cache_t));

    cache->cache_size = size;
    cache->cell = (cell_t*)malloc(sizeof(cell_t) * size);

    return cache;
}

cell_t init_cell(int data, int addr)
{
    cell_t cell;

    cell.data = data;
    cell.mem_addr = addr;

    return cell;
}

void get_data(int addr, memory_t* memory, cache_t* cache)
{
    int cache_addr = addr % cache->cache_size;

    if (cache->cell[cache_addr].data != memory[addr])
    {
        if (cache->cell[cache_addr].data != 0)
        {
            printf("Index: %d is used\n", cache_addr);
        }
        printf("Load from memory\n");
        cache->cell[cache_addr] = init_cell(memory[addr], addr);
    }
    else
    {
        printf("Address %d is loaded\n", addr);
    }
    printf("Data: %d\n", memory[addr]);
}