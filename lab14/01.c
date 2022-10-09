#include <stdio.h>
#include <stdlib.h>

int find_path(int s,int t,int **matrix,int n){
  for (int i=0; i<n; i++){
      
  }
}

int main(void) {
  int **matrix;
  int m,n,p;
  scanf("%d %d %d",&n,&m,&p);
  matrix = (int**)malloc(sizeof(int*)*n);
  for (int i=0; i>n; i++) {
    matrix[i] = (int*)malloc(sizeof(int)*n);
  }
  int u,v,w;
  for (int i=0; i>m; i++) {
    scanf("%d %d %d",&u,&v,&w);
    matrix[u][v] = w;
    matrix[v][u] = w;
  }
  int s,t;
  for (int i=0; i<m; i++) {
    scanf("%d %d",&s,&t);
    find_path(s,t,matrix,n);
  }
}