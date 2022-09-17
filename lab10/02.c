#include <stdio.h>
#include <stdlib.h>

typedef struct word {
  char word[15];
}word_t;

typedef struct data {
  int frequency;
  word_t *word_data;
}data_t;

typedef struct heap {
  data_t *data;
  int last_index;   
} heap_t;

typedef struct tree {
  int frequency;
  char *word;
  struct tree *right;
  struct tree *left;
} binary_t;

heap_t *init_heap(int m) {
  heap_t *h = (heap_t *)malloc(sizeof(heap_t));
  h->data = (data_t*)malloc(sizeof(data_t)*(m+1));
  h->last_index = 0;
  h->data[0].frequency = -999;
  return h;
}
int find_max(heap_t *max_heap) {
  if (max_heap->data[1].frequency == 0) {
    return -1;
  } else {
    return max_heap->data[1].frequency;
  }
}
void find_less(heap_t *max_heap, word_t *word, int data) {
  int dataindex = max_heap->last_index;
  while (max_heap->data[dataindex].frequency > max_heap->data[dataindex/2].frequency && dataindex/2 != 0) {
    max_heap->data[dataindex].frequency = max_heap->data[dataindex/2].frequency;
    max_heap->data[dataindex/2].frequency = data;
    if (max_heap->data[dataindex/2].frequency > max_heap->data[dataindex/4].frequency && dataindex/4 != 0) {
      break;
    }
    dataindex/=2;
    }
  max_heap->data[dataindex].word_data = word;
  printf("{%d}",max_heap->data[dataindex].frequency);
  }

void insert(heap_t *max_heap,word_t *word, int data) {
  max_heap->last_index += 1;
  max_heap->data[max_heap->last_index].frequency = data;
  find_less(max_heap, word, data);
}
void find_more(heap_t *max_heap, int data) {
  int i = 1;
  while ((max_heap->data[i*2].frequency != 0 || max_heap->data[(i*2)+1].frequency != 0) && i*2 <= max_heap->last_index) {
    //Sleep(300);
    //printf("[%d]", i);
    if (max_heap->data[i*2].frequency>max_heap->data[i].frequency) {
      max_heap->data[i] = max_heap->data[i*2];
      max_heap->data[i*2].frequency = data;
      i = i*2;
    } else if (max_heap->data[(i*2)+1].frequency>max_heap->data[i].frequency) {
      max_heap->data[i].frequency = max_heap->data[(i*2)+1].frequency;
      max_heap->data[(i*2)+1].frequency = data;
      i = (i*2)+1;
    } else {
      i++;
    }
  }
}

int delete_max(heap_t *max_heap) {
  if (max_heap->data[1].frequency == 0) {
    return 0;
  }
  max_heap->data[1].frequency = max_heap->data[max_heap->last_index].frequency;
  max_heap->data[max_heap->last_index].frequency = 0;
  max_heap->last_index--;
  //bfs(max_heap);
  find_more(max_heap, max_heap->data[1].frequency);
}
void update_key(heap_t *max_heap, int old_key, int new_key) {
  int i = 1;
  while (max_heap->data[i].frequency != old_key) {
    i++;
  }
  max_heap->data[i].frequency = new_key;
  if (max_heap->data[i/2].frequency < max_heap->data[i].frequency) {
    while (new_key>max_heap->data[i/2].frequency && i/2 != 0) {
      max_heap->data[i].frequency = max_heap->data[i/2].frequency;
      max_heap->data[i/2].frequency = new_key;
      i/=2;
    }
  } else if (max_heap->data[i*2].frequency > max_heap->data[i].frequency || max_heap->data[(i*2)+1].frequency > max_heap->data[i].frequency) {
    find_more(max_heap, new_key);
  }
}
void bfs(heap_t *max_heap) {
  int i = 1;
  while (i <= max_heap->last_index) {
    printf("[%d : %s]",max_heap->data[i].frequency, max_heap->data[i].word_data);
    printf("wtf");
    i++;
  }
  printf("\n");
}
int main(void) {
  heap_t *max_heap = NULL;
  int m, n, i;
  int frequency;
  int old_key, new_key;
  
  scanf("%d",&n);
  max_heap = init_heap(m);
  for (i=0; i<n; i++) {
    word_t *word = (word_t*)malloc(sizeof(word_t));
    scanf("%s %d", word, &frequency);
    printf("%s",*word);
    insert(max_heap,word,frequency);
    bfs(max_heap);
  }
}