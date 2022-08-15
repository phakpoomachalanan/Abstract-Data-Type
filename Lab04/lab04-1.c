#include <stdio.h>

int isPrime(int number);

int main(void)
{
    int number;

    scanf("%d", &number);
    printf("%d\n", isPrime(number));
    
    return 0;
}

int isPrime(int number)
{
    int candidate = 2;

    if (number == 0 || number == 1)
    {
        return 0;
    }
    
    while (candidate * candidate <= number)
    {
        if (number%candidate == 0)
        {
            return 0;
        }
        candidate++;
    }
    return 1;
}

// O(n^(1/2))