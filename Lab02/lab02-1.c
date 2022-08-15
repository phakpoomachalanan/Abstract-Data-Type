#include<stdio.h>
#include<math.h>

int main(void)
{
    double a, b, A, B;
    double sum, DX;
    int    n;

    scanf("%lf %lf %lf %lf %d", &a, &b, &A, &B, &n);
    DX = (b - a) / n;

    for (int i=0; i<n; i++)
    {
        sum += 1.0 / 2 * A * (sin(M_PI * (i*DX + a) / B) + sin(M_PI * ((i+1)*DX + a) / B)) * DX;
    }
    printf("%.5lf\n", sum);

    return 0;
}