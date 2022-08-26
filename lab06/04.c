#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  float data;
  struct node *previous;
  struct node *next;
} node_t;

typedef node_t stack_t;

void show(stack_t*s) {
  node_t *temp = NULL;
  temp = s;
  while (temp != NULL)
  {
    printf("[%d]",temp->data);
    temp = temp->next;
  }
  printf("\n");  
}

node_t *push(stack_t *s, char value) {
  //printf("HI");
  if (value == '*') {
    s->next->data = s->next->data * s->data;
    s = s->next;
    //printf("[*]");
    return s;
  } else if (value == '+') {
    s->next->data = s->next->data + s->data;
    s = s->next;
    //printf("[+]");
    return s;
  } else if (value == '-') {
    s->next->data = s->next->data - s->data;
    s = s->next;
    //printf("[-]");
    return s;
  } else if (value == '/') {
    s->next->data = s->next->data / s->data;
    s = s->next;
    //printf("[/]");
    return s;
  }
  if (s == NULL) {
    //printf("[S NULL]");
    node_t *node = (node_t *)(malloc(sizeof (node_t)));
    s = node;
    s->next = NULL;
    s->previous = NULL;
    s->data = value-48;
    return s;
  }
  if (s->previous != NULL) {
    //printf("[have previous]");
    s = s->previous;
    s->data = value-48;
  } else {
    //printf("[newnode]");
    node_t *node = (node_t *)(malloc(sizeof (node_t)));
    s->previous = node;
    node->data = value-48;
    node->next = NULL;
    node->next = s;
    s = node;
    node->previous = NULL;
  }
  return s;
}

int main(void) {
  stack_t *s = NULL;
  int n,i,value;
  scanf("%d\n",&n);
  for (i=0; i<n; i++) {
    scanf("%c",&value);
    s = push(s, value);
    //show(s);
  }
  printf("%.2f",s->data);
  return 0;
}