#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  char word[50];
  int ascii;
}data_t;


int main(void) {
  int m,n;
  char str_input[50];
  scanf("%d %d",m,n);
  char *str = (char*)malloc(sizeof(char*)*m);
  for (int i=0; i<m; i++) {
    scanf("%s",&str_input);
    str[i] = (char*)malloc(sizeof(char)*50);
    str[i] = str_input;
    printf("[%s]",str[i]);
  }

  return 0;
}