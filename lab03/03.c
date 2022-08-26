#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int alp=0,word=0,i=0;
  char s[100000];
  char newS[30000][50];
  scanf("%[^\n]c",s);
  
  while (s[alp]!='\0') {
    if (s[alp] == ' ') {
      word++;
      alp++;
      i=0;
    } else {
      //printf("%c",s[alp]);
      newS[word][i]=s[alp];
      //printf("---%s---\n",newS[word]);
      alp++;
      i++;
      }
  }
  for (i=word;i>=0;i--) {
    printf("%s ",newS[i]);
  }
  return 0;
  }