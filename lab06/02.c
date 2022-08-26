#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef node_t queue_t;

node_t *enqueue(queue_t *q, int value) {
  node_t *node = (node_t *)(malloc(sizeof (node_t)));
  node->next = NULL;
  node->data = value;
  if (q == NULL) {
    node->next = node;
    q = node;
    return q;
  } else {
    node->next = q->next;
    q->next = node;
    q = node;
    return q;
  }
}

node_t *dequeue(queue_t *q) {
  if (q == NULL) {
    printf("Queue is empty.\n");
    return NULL;
  } else if (q->next == q) {
    printf("%d\n",q->data);
    free(q);
    return NULL;
  } else {
    printf("%d\n",(q->next)->data);
    q->next = q->next->next;
    return q;
  }
}

void show(queue_t *q) {
  node_t *temp = NULL;
  if (q == NULL) {
    printf("Queue is empty.\n");
  } else {
    temp = q->next;
    while (temp != q) {
      printf("%d ",temp->data);
      temp = temp->next;
    }
    printf("%d",q->data);
    printf("\n");
  }
  
}

void empty(queue_t *q) {
  if (q == NULL) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue is not empty.\n");
  }
}

int size(queue_t *q) {
  int count = 0;
  node_t *temp = NULL;
  if (q == NULL) {
    printf("0\n");
    return -1;
  }
  temp = q->next;
  count++;
  while (temp != q) {
    temp = temp->next;
    count++;
  }
  printf("%d\n",count);
}

int main(void) {
  queue_t *q = NULL;
  int n, i, command, value;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d", &value);
        q = enqueue(q, value);
        break;
      case 2:
        q = dequeue(q);
        break;
      case 3:
        show(q);
        break;
      case 4:
        empty(q);
        break;
      case 5:
        size(q);
        break;  
    }
  } 
  return 0;
}