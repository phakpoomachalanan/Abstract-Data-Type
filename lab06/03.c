#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *next;
} node_t;
typedef node_t stack_t;

node_t *push(stack_t *s, char value) {
  if (s!=NULL) {
    if ((s->data == '(' && value == ')') || (s->data == '[' && value == ']') || (s->data == '{' && value == '}')) {
      //printf("[i am in]");
      node_t *temp = NULL;
      temp = s;
      s = s->next;
      free(temp);
    } else {
      //printf("[not e]");
      node_t *node = (node_t *)(malloc(sizeof (node_t)));
      node->data = value;
      node->next = NULL;
      node->next = s;
      s = node;
    }} else {
      //printf("[first]");
      node_t *node = (node_t *)(malloc(sizeof (node_t)));
      node->data = value;
      node->next = NULL;
      node->next = s;
      s = node;
    }
  return s;
}

int main(void) {
  stack_t *s = NULL;
  int n,i;
  char p;
  scanf("%d\n",&n);
  for (i=0; i<n; i++) {
    scanf("%c",&p);
    s = push(s,p);
    //printf("%d",i);
  }
  if (s == NULL) {
    printf("1");
  } else {
    printf("0");
  }
}