#include<stdio.h>
#include<math.h>

int doFactorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * doFactorial(n-1);
}

int main(void) 
{
    double x;
    double sine, cosine, tangent;
    int i, j;

    scanf("%lf", &x);
    x = x * 3.14159265358979323846  / 180;
    
    for (i=1, j=0; j<10; i+=2, j++)
    {
        sine += pow((-1), j) * pow(x, i) / doFactorial(i);
    }

    cosine = sqrt(1 - pow(sine, 2));
    tangent = sine / cosine;

    printf("%.14lf %.14lf %.14lf\n", sine, cosine, tangent);
    
    return 0;
}