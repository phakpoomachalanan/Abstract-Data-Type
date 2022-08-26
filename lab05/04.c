#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int shot;
  int seq;
  struct node *next;
}node_t;

node_t *addNode(node_t **head,int p, node_t *temp,int i) {
  node_t *newnode = (node_t *)(malloc(sizeof (node_t)));
  if (*head == NULL) {
    temp = newnode;
    newnode->shot = p;
    newnode->seq = i;
    *head = newnode;
    newnode->next = *head;
    return temp;
  } else {
    newnode->shot = p;
    newnode->seq = i;
    temp->next = newnode;
    temp = newnode;
    newnode->next = *head;
    return temp;
  }
}
int count(node_t *head,int k,int i){
  node_t *temp;
  i = 1;
  int j;
  while (1) {
    //printf("(%d)",i);
    if (i%k == 0) {
      //printf("[&K]");
      head->shot -= 1;
    } else {
      j = i;
      while (j!=0) {
        if (j%10 == k) {
          //printf("[/10]");
          head->shot -= 1;
          break;
        }
        j = j/10;
      }
    }
    i++;
    //printf("[%d-%d]",head->shot,head->seq);
    if (head->shot == -1) {
      //printf("cut");
      temp->next = head->next;
      head = head->next;
    } else {
      temp = head;
      head = head->next;
    }
    if (head == head->next) {
      printf("%d\n",head->seq);
      return 0;
    }
    //printf("\n");
  }
}

int main(void) {
  node_t *head = NULL, *temp = NULL;
  int n,k,i,p;
  scanf("%d %d",&n,&k);
  for (i=1; i<=n; i++) {
    scanf("%d",&p);
    temp = addNode(&head,p,temp,i);
  }
  count(head,k,i);
  return 0;
}