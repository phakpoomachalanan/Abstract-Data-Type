#include <stdio.h>
#include <math.h>

int c = 0;
int estate(int m,int n) {
  //printf("[%d-%d]\n",m,n);
  int i,p,min,max;
  if (m<=n) {
    max = n;
    min = m;
  } else {
    max = m;
    min = n;
  }
  if (m == 0 || n==0) {
    return 0;
  } else if (min == 1) {
    c += max;
  } else {
    for (i=0;i<=(m+n)/2;i++) {
      if (pow(2,i)>min){
        p=i-1;
        break;
      }
    }
    c+=1;
    estate(m,n-pow(2,p));
    estate(m-pow(2,p),pow(2,p));
  }
}
int main() {
  int m,n;
  scanf("%d %d", &m, &n);
  estate(m,n);
  printf("%d",c);
  return 0;
}
//big o is O((log(n))^2)