#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *previous;
  struct node *next;
} node_t;

typedef struct queue {
  node_t *front;
  node_t *rear;
} queue_t;

void dequeue(node_t *temp,queue_t *q) {
  node_t *temp2 = NULL;
  if (temp == q->front) {
    q->front = q->front->next; 
  } else {
    temp2 = temp->previous;
    //printf("%p",temp->next);
    temp->previous->next = temp->next;
    if (temp->next == NULL) {
      temp = temp->next;
    } else {
      temp = temp->next;
      temp->previous = temp2;
    }
  }
}

void printnode(queue_t *q) {
  node_t *temp = q->front;
  while (temp != NULL)
  {
    printf("%c",temp->data);
    temp = temp->next;
  }
}

int enqueue(queue_t *q,char p) {
  node_t *node = (node_t *)(malloc(sizeof (node_t)));
  node_t *temp = NULL;
  temp = q->front;
  node->next = NULL;
  if (q->front == NULL) {
    node->data = p;
    node->previous = NULL;
    q->front = node;
    q->rear = node;
  } else {
    while (temp != NULL) {
      if (temp->data == '(' && p == ')') {
        dequeue(temp,q);
        //printnode(q);
        //printf(".%c.\n",p);
        return 0;
      } else if (temp->data == '[' && p == ']') {
        dequeue(temp,q);
        //printnode(q);
        //printf(".%c.\n",p);
        return 0;
      } else if (temp->data == '{' && p == '}') {
        dequeue(temp,q);
        //printnode(q);
        //printf(".%c.\n",p);
        return 0;
      } else {
        temp = temp->next;
      }
    }
    node->data = p;
    node->previous = q->rear;
    q->rear->next = node;
    q->rear = node;
  }
  //printnode(q);
  //printf(".%c.\n",p);
}


void empty(queue_t *q) {
  if (q->front == NULL) {
    printf("1");
  } else {
    printf("0");
  }
}

int main(void) {
  queue_t q = {NULL, NULL};
  int n,i;
  char p;
  scanf("%d\n",&n);
  if (n%2 == 1) {
    printf("0");
    return 0;
  }
  for (i=0; i<n; i++) {
    scanf("%c",&p);
    enqueue(&q,p);
  }
  empty(&q);
  return 0;
}