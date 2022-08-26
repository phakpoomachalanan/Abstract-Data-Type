#include <stdio.h>
#include <math.h>

double factorial(int i) {
  if (i == 1) {
    return 1;}
  else {
    return i * factorial(i-1);}
  }

int main(void) {
  double x;
  double sin,cos,tan; sin=0.0;
  scanf("%lf", &x);
  int i = 1; int j = 1;
  x = x*(M_PI/180.0);
  for (i; i <= 19; i+=2) {
    //printf("%d ",i);
    if (j == 1) {
      sin += pow(x,i)/(factorial(i));
      j = 0;
    } else if (j == 0) {
      sin -= pow(x,i)/(factorial(i));
      j = 1;
    }
    //printf("%.14f\n", pow(x,i)/(factorial(i)));
  }
  cos = sqrt(1-(pow(sin,2)));
  tan = sin/cos;
  printf("%.14f %.14f %.14f", sin, cos ,tan);
  return 0;
}