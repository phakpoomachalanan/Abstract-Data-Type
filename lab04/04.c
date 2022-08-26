#include <stdio.h>
#include <math.h>
int main(void) {
  int i;
  long long num;
  scanf("%lld",&num);
  for (i=2;i<sqrt(num);i++) {
    if (num%i == 0) {
      printf("0");
      return 0;
    }
  } 
  printf("1");
  return 0;
}
//big o is O(n^(1/2))