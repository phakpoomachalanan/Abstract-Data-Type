#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef node_t stack_t;

node_t *push(stack_t *s, int value) {
  node_t *node = (node_t *)(malloc(sizeof (node_t)));
  node->data = value;
  node->next = NULL;
  node->next = s;
  s = node;
  return s;
}

void top(stack_t *s) {
  //printf("[%p]",s);
  if (s == NULL) {
    printf("Stack is empty.\n");
  } else {
    printf("%d\n", s->data);
  }
}

node_t *pop(stack_t *s) {
  if (s == NULL) {
    return NULL;
  }
  node_t *temp = NULL;
  temp = s->next;
  free(s);
  return temp;
}

void empty(stack_t *s) {
  if (s == NULL) {
    printf("Stack is empty.\n");
  } else {
    printf("Stack is not empty.\n");
  }
}

void size(stack_t *s) {
  int count = 0;
  while (s != NULL) {
    s = s->next;
    count++;
  }
  printf("%d\n",count);
}

int main(void) {
  stack_t *s = NULL;
  int n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        //printf("[%p]",s);
        break;
      case 2:
        top(s);
        break;
      case 3:
        s = pop(s);
        break;
      case 4:
        empty(s);
        break;
      case 5:
        size(s);
        break;  
    }
  } 
  return 0;
}