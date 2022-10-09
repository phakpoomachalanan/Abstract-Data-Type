#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct data{
  int w;
  int visit;
} data;

int find_shortest_path(int s,int t,int **m,data *d,int n) {
  printf("{%d}",s);
  d[s].visit = 1;
  if(d[t].w!=0){
    return d[t].w;
  }
  int i;
  int min = 99999;
  int explor;
  for (int i=0;i<n;i++) {
    if (m[s][i]<min && m[s][i]!=0 && d[i].visit == 0) {
      min = m[s][i];
      explor = i;
    }
    if (m[s][i]!=0) {
      if (d[i].w == 0 && d[i].visit == 0) {
        d[i].w += d[s].w+m[s][i];
      } else if (m[s][i]+d[s].w<d[i].w && d[i].visit == 0) {
        d[i].w = m[s][i]+d[s].w;
      } else if (d[i].visit == 0) {
        d[i].w += d[s].w+m[s][i];
      }
    }
  }

  for (int j=0;j<n;j++) {
    printf("[%d]",d[j]);
    Sleep(100);
  }
  printf("\n");
  i++;
  if (explor!=t){
    find_shortest_path(explor,t,m,d,n);
  } else if (explor == t){
    find_shortest_path(explor,t,m,d,n);
  } 
}

int main(void) {
  int m,n,p,i,j;
  scanf("%d %d %d",&n,&m,&p);
  int **matrix = (int**)malloc(sizeof(int*)*n);
  data *Dijkstra = (data*)malloc(sizeof(data)*n);
  for (i=0; i<n; i++) {
    matrix[i] = (int*)malloc(sizeof(int)*n);
    Dijkstra[i].w = 0;
    Dijkstra[i].visit = 0;
    for (j=0; j<n; j++) {
      matrix[i][j] = 0;
    }
  }
  int u,v,w;
  for (i=0; i<m; i++) {
    scanf("%d %d %d",&u,&v,&w);
    matrix[u][v] = w;
    matrix[v][u] = w;
  }
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("%3d ",matrix[i][j]);
    }
    printf("\n");
  }
  int s,t;
  for (j=0; j<p; j++) {
    scanf("%d %d",&s,&t);
    for (int k=0; k<n; k++) {
      Dijkstra[k].w = 0;
      Dijkstra[k].visit = 0;
    }
    printf("%d",find_shortest_path(s,t,matrix,Dijkstra,n));
  }
  return 0;
}