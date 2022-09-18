#include <stdio.h>
#include <stdlib.h>


typedef struct tree {
  int data;
  char *word;
  struct tree *right;
  struct tree *left;
} binary_t;

typedef struct heap {
  binary_t *tree;
  int last_index;   
} heap_t;



heap_t *init_heap(int m) {
  heap_t *h = (heap_t *)malloc(sizeof(heap_t));
  h->tree = (binary_t *)malloc(sizeof(binary_t)*(m+1));
  for (int i = 1;i<=m;i++) {
    h->tree[i].word = (char *)malloc(sizeof(char)*15);
    h->tree[i].right = NULL;
    h->tree[i].left = NULL;
  }
  h->last_index = 0;
  h->tree[0].data = -999;
  h->tree[0].word = "\0";
  return h;
}
void bfs(heap_t *max_heap);
void find_less(heap_t *max_heap, char *word, int data) {
  int dataindex = max_heap->last_index;
  while (max_heap->tree[dataindex].data < max_heap->tree[dataindex/2].data && dataindex/2 != 0) {
    bfs(max_heap);
    max_heap->tree[dataindex].data = max_heap->tree[dataindex/2].data;
    max_heap->tree[dataindex].word = max_heap->tree[dataindex/2].word;
    max_heap->tree[dataindex/2].data = data;
    max_heap->tree[dataindex/2].word = word;
    dataindex/=2;
  }
}
binary_t delete_min1(heap_t *max_heap) {
  binary_t temp = max_heap->tree[1];
  max_heap->tree[1].word = "\0";
  max_heap->tree[1].data = 0;
  max_heap->tree[1].right = NULL;
  max_heap->tree[1].left = NULL;
  
  max_heap->tree[1] = max_heap->tree[max_heap->last_index];

  max_heap->tree[max_heap->last_index].word = "\0";
  max_heap->tree[max_heap->last_index].data = 0;
  max_heap->tree[max_heap->last_index].right = NULL;
  max_heap->tree[max_heap->last_index].left = NULL;
  max_heap->last_index--;
  binary_t data = max_heap->tree[1];
  int i = 1;
  
  while ((max_heap->tree[i*2].data != 0 || max_heap->tree[(i*2)+1].data != 0) && i*2 <= max_heap->last_index) {
    if (max_heap->tree[(i*2)+1].data == 0 && max_heap->tree[(i*2)].data == 0) {
      break;
    }
    if (max_heap->tree[(i*2)+1].data < max_heap->tree[i*2].data && i*2 != max_heap->last_index) {
      if (max_heap->tree[(i*2)+1].data<max_heap->tree[i].data && max_heap->tree[(i*2)+1].data != 0) {
      max_heap->tree[i] = max_heap->tree[(i*2)+1];
      max_heap->tree[(i*2)+1] = data;
      i = (i*2)+1;
      } else if (max_heap->tree[(i*2)].data<max_heap->tree[i].data && max_heap->tree[(i*2)].data != 0) {
        max_heap->tree[i] = max_heap->tree[(i*2)];
        max_heap->tree[(i*2)] = data;
        i = (i*2);
      } else {
        i++;
      }
    } else {
      if (max_heap->tree[i*2].data<max_heap->tree[i].data && max_heap->tree[(i*2)].data != 0) {
      max_heap->tree[i] = max_heap->tree[i*2];
      max_heap->tree[i*2] = data;
      i = i*2;
    } else if (max_heap->tree[(i*2)+1].data<max_heap->tree[i].data && max_heap->tree[(i*2)+1].data != 0) {
      max_heap->tree[i] = max_heap->tree[(i*2)+1];
      max_heap->tree[(i*2)+1] = data;
      i = (i*2)+1;
    } else {
      i++;
    }
    }
  } 
  return temp;
}
void insert(heap_t *max_heap,char *word, int data) {
  max_heap->last_index += 1;
  max_heap->tree[max_heap->last_index].data = data;
  find_less(max_heap, word, data);
}
void add_tree(heap_t *max_heap,binary_t left,binary_t right) {
  max_heap->last_index++;
  max_heap->tree[max_heap->last_index].left = &left;
  max_heap->tree[max_heap->last_index].right = &right;
  max_heap->tree[max_heap->last_index].word = "\0";
  max_heap->tree[max_heap->last_index].data = max_heap->tree[max_heap->last_index].left->data + max_heap->tree[max_heap->last_index].right->data;
}

void bfs(heap_t *max_heap) {
  int i = 1;
  while (i <= max_heap->last_index) {
    printf("[%d : %s]",max_heap->tree[i].data, max_heap->tree[i].word);
    i++;
  }
  printf("\n");
}
int main(void) {
  heap_t *max_heap = NULL;
  int  n, i;
  int frequency;
  int old_key, new_key;
  binary_t right;
  binary_t left;
  scanf("%d",&n);
  max_heap = init_heap(n);
  for (i=0; i<n; i++) {
    scanf("%s %d", max_heap->tree[max_heap->last_index+1].word, &frequency);
    insert(max_heap,max_heap->tree[max_heap->last_index+1].word,frequency);
    bfs(max_heap);
  }
  while (max_heap->tree[2].data != 0) {
      left = delete_min1(max_heap);
      printf("de1");
      bfs(max_heap);
      right = delete_min1(max_heap);
      printf("de2");
      bfs(max_heap);
      add_tree(max_heap, left, right);
      printf("add");
    bfs(max_heap);
  }
  printf("end");
}