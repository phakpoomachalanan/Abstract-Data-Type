#include <stdio.h>

int main(void) {
  int m,n,p,i,j,c;
  scanf("%d %d %d", &m, &p, &n);
  char str[m];
  char substr[p];
  scanf("%s", str);
  //printf("---%c---", str[0]);
  scanf("%s", substr);
  //printf("%s", substr);
  for (i=0; i<(m); i++) {
    //printf("%d",i);
    //printf("(%c)", str[i]);
    c = 0;
    for (j=0; j<p; j++) {
      if ((i+j)>=m) {
        c+=999;
      }
      //printf("(%c%c)", str[i+j], substr[j]);
      if (str[i+j]!=substr[j]){
        //printf("(Not E)");
        c++;
      }
    }
    if (c<=n) {
      printf("[");
      for (j=0; j<p; j++) {
        if (str[i+j]==substr[j]){
          printf("%c", str[j+i]);
      } else {printf("?");}
      }
      printf("]");
      i += p-1;
    } else {printf("%c",str[i]);}
    //printf("\n");
  }
  //printf("%s", substr);
  return 0;
}