#include <stdio.h>
#include <stdlib.h>
int traverseMaze(char **maze,int i,int j) {
  if (maze[i+1][j]=='G' || maze[i-1][j]=='G' || maze[i][j+1]=='G' || maze[i][j-1]=='G') {
    return 0;
    }
  if (maze[i][j+1]==' ') {
    maze[i][j+1]='.';
    traverseMaze(maze,i,j+1);
  } else if (maze[i][j-1]==' ') {
    maze[i][j-1]='.';
    traverseMaze(maze,i,j-1);
  } else if (maze[i+1][j]==' ') {
    maze[i+1][j]='.';
    traverseMaze(maze,i+1,j);
  } else if (maze[i-1][j]==' ') {
    maze[i-1][j]='.';
    traverseMaze(maze,i-1,j);
  } else if (maze[i+1][j]!=' ' && maze[i-1][j]!=' ' && maze[i][j+1]!=' ' && maze[i][j-1]!=' ') {
    if (maze[i+1][j]=='.') {
      maze[i][j]='U';
    traverseMaze(maze,i+1,j);
  } else if (maze[i-1][j]=='.') {
    maze[i][j]='U';
    traverseMaze(maze,i-1,j);
  } else if (maze[i][j+1]=='.') {
    maze[i][j]='U';
    traverseMaze(maze,i,j+1);
  } else if (maze[i][j-1]=='.') {
    maze[i][j]='U';
    traverseMaze(maze,i,j-1);
  }
}}
  
int main(void) {
  int n,i,j;
  scanf("%d\n",&n);
  char **maze = NULL;
  maze = (char **)malloc(sizeof(char *) * n);
  for (i=0; i<n; i++) {
    maze[i] = (char *)malloc(sizeof(char) * n);
    for (j=0; j<n; j++) {
      maze[i][j] = i+j;
    }
  }
  for (i=0; i<n; i++) {
    scanf("\n");
    for (j=0; j<n; j++){
      scanf("%c",&maze[i][j]);
      //printf("(%d)",i);
      //printf("--%d--",j);
    }
    if (i==n-1){break;}
    scanf("\n");
  }
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++){
      if (maze[i][j]=='S') {
        traverseMaze(maze,i,j);
      }
    }
  }
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++){
      if (maze[i][j]=='U') {
        maze[i][j]=' ';
      }
    }
  }
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++){
      printf("%c", maze[i][j]);
    }
  printf("\n");
  }
  for (i=0; i<n; i++) {
    free(maze[i]);
  }
  free(maze);

return 0;
}