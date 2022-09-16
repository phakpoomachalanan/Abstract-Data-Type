#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;   
} heap_t;



int main(void) {
  heap_t *max_heap = NULL;
  int m, n, i;
  int command, data;
  int old_key, new_key;

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
    default:
      break;
    }
  }
}