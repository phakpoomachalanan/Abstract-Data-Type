#include <stdio.h>
#include <math.h>

int main(void) {
  double a,b,A,B,LOS;//LOS = lenght of subsection
  double ans = 0.0;
  double n,i;
  scanf("%lf%lf%lf%lf%lf",&a ,&b ,&A ,&B ,&n);
  //printf("%f %f %f %f %f\n",a ,b ,A ,B ,n);
  LOS = (b-a)/n;
  //printf("%f\n",LOS);
  for (i=0; i<n; ++i) {
    ans += (0.5*LOS*((A*sin(M_PI*((i*LOS)+LOS+a)/B))+(A*sin(M_PI*((i*LOS)+a)/B))));
  }
  printf("%.5lf\n", ans);
  return 0;
}