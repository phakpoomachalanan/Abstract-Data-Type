#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int m,n,p,i,j;
  scanf("%d %d %d",&n,&m,&p);
  int **matrix = (int**)malloc(sizeof(int*)*n);
  for (i=0; i<n; i++) {
    matrix[i] = (int*)malloc(sizeof(int)*n);
    for (j=0; j<n; j++) {
      matrix[i][j] = 0;
    }
  }
  int u,v,w;
  for (int i=0; i>m; i++) {
    scanf("%d %d %d",&u,&v,&w);
    matrix[u][v] = w;
    matrix[v][u] = w;
  }
  
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
  int s,t;
  for (int i=0; i<p; i++) {
    scanf("%d %d",&s,&t);
  }
  return 0;
}