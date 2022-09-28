#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int *arr; 
} list_t;

void print_list(list_t *s,int n) {
  for (int i = 0; i<n;i++) {
    printf("%d ",s->arr[i]);
  }
  printf("\n");
}

void insert(list_t *s,int start,int end) {
  int temp1 = s->arr[end];
  int temp2;
  for (int i = start;i<end;i++) {
    temp2 = s->arr[i];
    s->arr[i] = temp1;
    temp1 = temp2;
    temp2 = s->arr[i+1];
  }
  s->arr[end] = temp1;
}


int main(void) {
  int n;
  int num;
  scanf("%d",&n);

  list_t *s = (list_t*)malloc(sizeof(list_t));
  s->arr = (int*)malloc(sizeof(int)*(n));

  for (int i = 0;i<n;i++) {
    if (i == n-1) {
      scanf("%d",&num);
    } else {
      scanf("%d ",&num);
    }
    s->arr[i] = num;
  }
  for (int i = 0;i<n-1;i++) {
    if (s->arr[i+1] > s->arr[i]) {
      print_list(s,n);
      continue;
    } else {
      for (int j = i;j>=-1;j--) {
        if (j == -1) {
          insert(s,0,i+1);
          break;
        }
        if (s->arr[i+1] < s->arr[j]){
          continue;
        } else {
          insert(s,j+1,i+1);
          break;
        }
      }
      print_list(s,n);
    }
  }
}