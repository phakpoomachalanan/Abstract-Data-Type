#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  int mem_addr;
} cell_t;

typedef struct hash {
  cell_t *table;
  int cache_size;
} cache_t;

typedef cache_t cache_t;
typedef int memory_t;

memory_t *init_memory(int size) {
  memory_t *memory = (memory_t *)malloc(sizeof(memory_t)*size);
  int i = 0;

  for(i=0;i<size;i++) {
    memory[i] = rand();
  }
  return memory;
}


cache_t *init_cache(int cache_size) {
    cache_t *newcache = (cache_t*)malloc(sizeof(cache_t));
    newcache->cache_size = cache_size;
    newcache->table = (cell_t*)malloc(sizeof(cell_t)*cache_size);
    return newcache;
}

void get_data(int addr , memory_t *memory, cache_t *cache) {
    int index = addr % cache->cache_size;
    cell_t *cell = &cache->table[index];
    if (cell->data != memory[addr]) {   
        
        if (cell->data != 0)
        {
            printf("Index: %d is used\n",index);
        }
        printf("Load from memory\n");
        cell->data = memory[addr];
        cell->mem_addr = addr;
    } else {
        printf("Address %d is loaded\n",addr);
    }
    printf("Data: %d\n",cell->data);

}



int main(void) {
  memory_t *memory = NULL;
  cache_t *cache = NULL;
  int memory_size, cache_size;
  int i, n, addr;

  scanf("%d %d %d",&memory_size, &cache_size, &n);

  memory = init_memory(memory_size);
  cache = init_cache(cache_size);

  for(i=0; i<n; i++) {
    printf("Load address: ");
    scanf("%d", &addr);
    get_data(addr, memory, cache);
  }
  return 0;
}