#include <stdio.h>
#include <stdlib.h>

struct node {
  int num;
  struct node *next;
};

struct node *add_node(struct node *temp, char c){
  struct node *newnode = (struct node*)(malloc(sizeof(struct node)));
  newnode->next = temp;
  newnode->num = c;
  temp = newnode;
  return temp;
}

struct node *plus(struct node *hx,struct node *hy,struct node *hAns,struct node *temp) {
  struct node *tempx = hx;
  struct node *tempy = hy;
  int sum, com = 0, x, y;
  while (tempx != NULL || tempy != NULL) {
    //printf("i am in");
    if (tempx == NULL) {
      y = (tempy->num)-48;
      sum = y+com;
      tempy = tempy->next;
    } else if (tempy == NULL) {
      x = (tempx->num)-48;
      sum = x+com;
      tempx = tempx->next;
    } else {
      x = (tempx->num)-48; y = (tempy->num)-48;
      sum = x+y+com;
      tempx = tempx->next;
      tempy = tempy->next;}
    if (sum > 9) {
      com = sum/10;
      sum = sum%10;
    } else {
      com = 0;
    }
    //printf("{%d %d}",x,y);
    //printf("[%d]",sum);
    temp = add_node(temp,sum);
    //printf("%p-%p\n",tempx,tempy);
  }
  if (com != 0) {
    temp = add_node(temp,com);
  }
  //printf("i am out");
  //printf("%p\n",temp);
  return temp;
}

void printnode(struct node *h) {
  struct node *temp = h;
  while (temp->next != NULL) {
    printf("%d",(temp->num));
    temp = temp->next;
  }
  printf("%d",(temp->num));
}

int main(void) {
  char c;
  struct node *hx = NULL, *temp = NULL,*hy = NULL,*hAns = NULL;
  scanf("%c",&c);
  while (c != '\n') {
    temp = add_node(temp,c);
    scanf("%c",&c);
  }
  hx = temp;
  //printnode(hx);
  temp = NULL;
  scanf("%c",&c);
  while (c != '\n') {
    temp = add_node(temp,c);
    scanf("%c",&c);
  }
  hy = temp; 
  temp = NULL;
  //printnode(hy);
  hAns = plus(hx,hy,hAns,temp);
  printnode(hAns);
  return 0;
}