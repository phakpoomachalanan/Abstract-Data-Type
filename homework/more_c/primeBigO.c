#include <stdio.h>

int isPrime(int num) {
    int try = 2;
    while (try*try<=num)
    {
        if (num%try == 0)
        return 0;
        try++;
    }
    if (num>1)
        return 1;
    else
        return 0;
}


int main() {
    int num;
    scanf("%d",&num);
    printf("%d",isPrime(num));
}
//big oh notation is O(√n)