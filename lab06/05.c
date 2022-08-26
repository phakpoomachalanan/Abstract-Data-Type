#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *next;
} node_t;

typedef node_t stack_t;

node_t *push(stack_t *s, char value) {
  node_t *node = (node_t *)(malloc(sizeof (node_t)));
  node->data = value;
  node->next = NULL;
  node->next = s;
  s = node;
  return s;
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

int main(void) {
  stack_t *s = NULL;
  char c;
  while(1) {
    scanf("%c",&c);
    if (c == 'x') {
      break;
    }
    s = push(s,c);
  }
  //printf("xf");
  while(1) {
    scanf("%c",&c);
    if (c == 'y') {
      break;
    }
    if (c == s->data){
    s = pop(s);}
  }
  //printf("yf");
  if (s == NULL) {
    printf("1");
  } else {
    printf("0");
  }
}