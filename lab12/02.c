#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *bubble_sort(char *str_in) {
  int n = strlen(str_in);
  for (int i=0; i < n; i++) {
    for (int j=0; j < n-1; j++) {
      char temp = str_in[j];
      if ((int)str_in[j] > (int)str_in[j+1]){
        str_in[j] = str_in[j+1];
        str_in[j+1] = temp;
      }
    }
  }
  return str_in;
}

int main(void) {
  int m,n;
  char str_input[50];
  scanf("%d %d",&m,&n);
  char **str;
  char **str_sorted;
  str = (char**)malloc(sizeof(char*)*m);
  str_sorted = (char**)malloc(sizeof(char*)*m);
  for (int i=0; i<m; i++) {
    str[i] = (char*)malloc(sizeof(char)*50);
    str_sorted[i] = (char*)malloc(sizeof(char)*50);
    scanf("%s",str_input);
    strcpy(str[i],str_input);
    strcpy(str_sorted[i],bubble_sort(str_input));

  }
  /*
  for (int i=0; i<m; i++) {
    printf("[%s | %s]\n",str[i],str_sorted[i]);
  }
  */
  for (int i=0; i<n; i++) {
    scanf("%s",str_input);
    strcpy(str_input,bubble_sort(str_input));
    for (int j=0; j<m; j++) {
      if (strcmp(str_sorted[j],str_input) == 0) {
        printf("%s ",str[j]);
      }
    }
    printf("\n");
  }
  return 0;
}