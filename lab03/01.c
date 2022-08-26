#include <stdio.h>
#include <stdlib.h>

void findStats(int *nums, double *avg, int *maxi, int *mini, int n) {
  int i; 
  float total=0;
  *maxi= -100; *mini= 100;
  for (i=0; i<n; i++) {
    total += nums[i];
    if (*maxi<nums[i]) {
      *maxi = nums[i];
    }
    if (*mini>nums[i]) {
      *mini = nums[i];
    }
  }
  //printf("%d\n", n);
  //printf("%d\n", total);
  *avg = total/n;
}

int main(void) {
  int n, i, maxi, mini;
  double avg;
  int *nums;
  
  scanf("%d", &n);
  nums = (int *)malloc(sizeof (int) * n);
  for (i=0; i<n; i++) {
    scanf("%d", nums+i);
  }
  findStats(nums, &avg, &maxi, &mini, n);
  printf("%.2f %d %d", avg, maxi, mini);
  return 0;
}