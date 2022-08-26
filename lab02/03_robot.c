#include <stdio.h>
#include <math.h>

int main(void) {
  int n,i;
  int x,y; x=0; y=0;
  char input,di; di = 'E';//direction
  scanf("%d\n", &n);
  for (i=1; i<=n; i+=1) {
    scanf("%c", &input);
    //printf("%c", input);
    switch (input)
    {
    case 'L':
      switch (di)
      {
      case 'E': di = 'S'; break;
      case 'W': di = 'N'; break;
      case 'N': di = 'E'; break;
      case 'S': di = 'W'; break;
      }
      break;
    case 'R':
      switch (di)
      {
      case 'E': di = 'N'; break;
      case 'W': di = 'S'; break;
      case 'N': di = 'W'; break;
      case 'S': di = 'E'; break;
      }
      break;
    case 'F':
      switch (di)
      {
      case 'E': x-=1; break;
      case 'W': x+=1; break;
      case 'N': y+=1; break;
      case 'S': y-=1; break;
      }
      break;
    }
  } 
  printf("%.4f", sqrt(pow(x,2)+pow(y,2)));
  return 0;
}