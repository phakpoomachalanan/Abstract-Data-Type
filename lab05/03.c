#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
} node_t;
node_t *temp = NULL;
node_t *findtemp(node_t *startNode) {
  temp = startNode;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  return temp;
}
node_t *append(node_t *startNode) {
  int num;
  scanf("%d",&num);
  node_t *newnode = (node_t *)(malloc(sizeof(node_t)));
  if (startNode == NULL) {
    temp = newnode;
    newnode->data = num;
    startNode = newnode;
    newnode->next = NULL;
    return startNode;
  } else{
    temp = findtemp(startNode);
    newnode->data = num;
    temp->next = newnode;
    temp = newnode;
    newnode->next = NULL;
    return startNode;
    }
}
void get(node_t *startNode) {
  int l,c;
  scanf("%d",&l);
  node_t *tempin = startNode;
  for (c=0; c<l; c++) {
    tempin = tempin->next;
  }
  printf("%d\n",tempin->data);
}
void show(node_t *startNode) {
  temp = startNode;
  while (temp != NULL) {
    printf("%d",temp->data);
    temp = temp->next;
    if (temp != NULL) {
      printf(" ");
    }
  }
  printf("\n");
}
node_t *reverse(node_t *startNode) {
  if (startNode->next == NULL) {
    return startNode;
  }
  node_t *temp = startNode;
  startNode = temp->next;
  temp->next = NULL;
  node_t *nextnode = startNode->next;
  startNode->next = temp;
  temp = startNode;
  while (nextnode->next != NULL) {
    startNode = nextnode;
    nextnode = startNode->next;
    startNode->next = temp;
    temp = startNode;
  }
  startNode = nextnode;
  nextnode->next = temp;
  return startNode;
}
node_t *cut(node_t *startNode) {
  int s,e,c;
  scanf("%d %d",&s,&e);
  for (c=0; c<s; c++) {
    startNode = startNode->next;
  }
  node_t *temp = startNode;
  for (c=0; c<(e-s); c++) {
    temp = temp->next;
  }
  temp->next = NULL;
  return startNode;
}

int main(void) {
  node_t *startNode;
  int n,i;
  char command;
  startNode = NULL;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf(" %c", &command);
    switch (command) {
      case 'A':
        startNode = append(startNode);
        break;
      case 'G':
        get(startNode);
        break;
      case 'S':
        show(startNode);
        break;
      case 'R':
        startNode = reverse(startNode);
        break;
      case 'C':
        startNode = cut(startNode);
        break;
      default:
        break;
    }
  }
  return 0;
}