#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int last_index;   
} heap_t;

heap_t *init_heap(int m) {
  heap_t *h = (heap_t *)malloc(sizeof(heap_t));
  h->data = (int*)malloc(sizeof(int)*(m+1));
  h->last_index = 0;
  h->data[0] = -999;
  return h;
}
int find_max(heap_t *max_heap) {
  if (max_heap->data[1] == 0) {
    return -1;
  } else {
    return max_heap->data[1];
  }
}
void find_less(heap_t *max_heap, int data) {
  int dataindex = max_heap->last_index;
  while (max_heap->data[dataindex] > max_heap->data[dataindex/2] && dataindex/2 != 0) {
    max_heap->data[dataindex] = max_heap->data[dataindex/2];
    max_heap->data[dataindex/2] = data;
    dataindex/=2;
    }
  }

void insert(heap_t *max_heap, int data) {
  max_heap->last_index += 1;
  max_heap->data[max_heap->last_index] = data;
  find_less(max_heap, data);
}
void find_more(heap_t *max_heap, int data) {
  int i = 1;
  while ((max_heap->data[i*2] != 0 || max_heap->data[(i*2)+1] != 0) && i*2 <= max_heap->last_index) {
    if (max_heap->data[i*2]>max_heap->data[i]) {
      max_heap->data[i] = max_heap->data[i*2];
      max_heap->data[i*2] = data;
      i = i*2;
    } else if (max_heap->data[(i*2)+1]>max_heap->data[i]) {
      max_heap->data[i] = max_heap->data[(i*2)+1];
      max_heap->data[(i*2)+1] = data;
      i = (i*2)+1;
    } else {
      i++;
    }
  }
}

int delete_max(heap_t *max_heap) {
  if (max_heap->data[1] == 0) {
    return 0;
  }
  max_heap->data[1] = max_heap->data[max_heap->last_index];
  max_heap->data[max_heap->last_index] = 0;
  max_heap->last_index--;
  //bfs(max_heap);
  find_more(max_heap, max_heap->data[1]);
}
void update_key(heap_t *max_heap, int old_key, int new_key) {
  int i = 1;
  while (max_heap->data[i] != old_key) {
    i++;
  }
  max_heap->data[i] = new_key;
  if (max_heap->data[i/2] < max_heap->data[i]) {
    while (new_key>max_heap->data[i/2] && i/2 != 0) {
      max_heap->data[i] = max_heap->data[i/2];
      max_heap->data[i/2] = new_key;
      i/=2;
    }
  } else if (max_heap->data[i*2] > max_heap->data[i] || max_heap->data[(i*2)+1] > max_heap->data[i]) {
    find_more(max_heap, new_key);
  }
}
void bfs(heap_t *max_heap) {
  int i = 1;
  while (i <= max_heap->last_index) {
    printf("%d ",max_heap->data[i]);
    i++;
  }
  printf("\n");
}
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