#include <stdio.h>
#include <stdlib.h>

typedef struct data{
  int w;
  int visit;
  int before;
} data;
int count;

int find_shortest_path(int s,int t,int **m,data *d,int n) {
  d[s].visit = 1;
  //printf("{%d}",s);
  if (count >= 2*n && d[t].w!=0) {
    return d[t].w;
  } else if (count >= 2*n){
    return -1;
  }
  
  int min = 9999999;
  int explor;
  for (int j=0;j<n;j++) {
    if (m[s][j]<min && m[s][j]!=0 && d[j].visit == 0) {
      min = m[s][j];
      explor = j;
    }
    if (m[s][j]!=0) {
      if (d[j].w == 0 && d[j].visit == 0) {
        d[j].w += d[s].w+m[s][j];
      } else if (m[s][j]+d[s].w < d[j].w) {
        d[j].w = m[s][j]+d[s].w;
      }
    }
  }
  count++;
  for (int j=0;j<n;j++) {
    //printf("[%d]",d[j].w);
    //Sleep(100);
  }
  //printf("\n");
  if (explor >=n) {
    find_shortest_path(d[s].before,t,m,d,n);
    }else {
    d[explor].before = s;
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
    Dijkstra[i].before = 0;
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
  /*
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("%3d ",matrix[i][j]);
    }
    printf("\n");
  }*/
  int s,t;
  for (j=0; j<p; j++) {
    scanf("%d %d",&s,&t);
    if (s == t) {
      printf("0\n");
      continue;
    }
    for (int k=0; k<n; k++) {
      Dijkstra[k].w = 0;
      Dijkstra[k].visit = 0;
      Dijkstra[k].before = 0;
    }
    count = 0;
    printf("%d\n",find_shortest_path(s,t,matrix,Dijkstra,n));
  }
  return 0;
}