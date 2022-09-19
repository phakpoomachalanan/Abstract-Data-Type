#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int data;
  char *word;
  int order;
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
int order = 1;
void bfs(heap_t *max_heap);
void find_less(heap_t *max_heap, char *word, int data ) {
  int dataindex = max_heap->last_index;
  while (max_heap->tree[dataindex].data < max_heap->tree[dataindex/2].data && dataindex/2 != 0) {
    max_heap->tree[dataindex].data = max_heap->tree[dataindex/2].data;
    max_heap->tree[dataindex].word = max_heap->tree[dataindex/2].word;
    max_heap->tree[dataindex/2].data = data;
    max_heap->tree[dataindex/2].word = word;
    dataindex/=2;
  }
  order++;
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
  //printf("subD");
  //bfs(max_heap);
  } 
  
  return temp;
}
void insert(heap_t *max_heap,char *word, int data) {
  max_heap->last_index += 1;
  max_heap->tree[max_heap->last_index].data = data;
  find_less(max_heap, word, data);
}
void add_tree(heap_t *max_heap,binary_t *left,binary_t *right) {
  max_heap->last_index++;
  //if (right->order > left->order || right->data != left->data) {
    max_heap->tree[max_heap->last_index].left = left;
    max_heap->tree[max_heap->last_index].right = right;
  //} else {
    //max_heap->tree[max_heap->last_index].right = left;
    //max_heap->tree[max_heap->last_index].left = right;
  //}
  max_heap->tree[max_heap->last_index].word = "\0";
  max_heap->tree[max_heap->last_index].data = max_heap->tree[max_heap->last_index].left->data + max_heap->tree[max_heap->last_index].right->data;
}
int dfs(binary_t *t) {
  //Sleep(0);
  if (t == NULL) {
    return 0;
  }
  printf("{%d:%s:%d}",t->data,t->word,t->order);
  dfs(t->left);
  dfs(t->right);
  //printf("[%s]",t->word);
} 
void bfs(heap_t *max_heap) {
  int i = 1;
  printf("----------------\n");
  while (i <= max_heap->last_index) {
    printf("[%d : %s]",max_heap->tree[i].data, max_heap->tree[i].word);
    i++;
  }printf("\n");
  i = 1;
  while (i <= max_heap->last_index) {
    dfs(&max_heap->tree[i]);
    i++;
  }
  printf("\n");
  printf("----------------\n");
}
int count;
char bi[15];
int sy = 0;
binary_t *temp_recu;
binary_t *recur;

int dfs_end(binary_t *t) {
  if (t==NULL) {
    return 0;
  }
  bi[count] = '0';
  count++;
  dfs_end(t->left);
  bi[count] = '\0';
  count--;
  bi[count] = '1';
  count++;
  dfs_end(t->right);
  bi[count] = '\0';
  count--;
  if (t->word != "\0") {
    printf("%s: ",t->word);
      for (int i = 0;i<count;i++) {
        printf("%c",bi[i]);
      }
      printf("\n");
  }
} 
int main(void) {
  heap_t *max_heap = NULL;
  int  n, i;
  int frequency;
  int old_key, new_key;
  scanf("%d",&n);
  max_heap = init_heap(n);
  for (i=0; i<n; i++) {
    scanf("%s %d", max_heap->tree[max_heap->last_index+1].word, &frequency);
    insert(max_heap,max_heap->tree[max_heap->last_index+1].word,frequency);
  }
  //printf("start");
  //bfs(max_heap);  
  while (max_heap->tree[2].data != 0) {
    binary_t *right = (binary_t *)malloc(sizeof(binary_t));
    binary_t *left = (binary_t *)malloc(sizeof(binary_t));
    *left = delete_min1(max_heap);
    //printf("de1");
    //bfs(max_heap);
    *right = delete_min1(max_heap);
    //printf("de2");
    //bfs(max_heap);
    add_tree(max_heap, left, right);
    //printf("add");
    //bfs(max_heap);
  }
  dfs_end(&max_heap->tree[1]);
  
}