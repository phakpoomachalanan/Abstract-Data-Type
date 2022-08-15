#include <stdio.h>
#include <stdlib.h>

void findStats(double *avg, int *maxi, int *mini, int *nums, int n);

int main(void)
{
    int n, i, maxi, mini;
    double avg;
    int *nums;

    scanf("%d", &n);
    nums = (int *)malloc(sizeof (int) * n);

    for (i=0; i<n; i++)
    {
        scanf("%d", nums+i);
    }
    findStats(&avg, &maxi, &mini, nums, n);
    printf("%.2f %d %d", avg, maxi, mini);
    return 0;
}

void findStats(double *avg, int *maxi, int *mini, int *nums, int n)
{
    *avg = 0.0;
    *mini = 100000;
    *maxi = 0;
    
    for (int i=0; i<n; i++)
    {
        if (nums[i] > *maxi)
        {
            *maxi = nums[i];
        }
        else if (nums[i] < *mini)
        {
            *mini = nums[i];
        }
        *avg += nums[i];
    }
    *avg /= n;
}