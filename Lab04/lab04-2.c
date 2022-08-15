#include <stdio.h>

int estatePlanner(int x, int y, int *maxSizeX, int *maxSizeY);
void maxSize(int n, int *data);
void toBinary(int n, int *data, int *binaryN);

int main(void)
{
    int x, y, square;
    int dataX[2] = {1, 2};
    int dataY[2] = {1, 2};

    scanf("%d %d", &x, &y);
    maxSize(x, dataX);
    maxSize(y, dataY);
    
    square = estatePlanner(x, y, dataX, dataY);

    printf("%d\n", square);

    return 0;
}

int estatePlanner(int x, int y, int *dataX, int *dataY)
{
    int square = 0;
    int binaryX[dataX[1]];
    int binaryY[dataY[1]];

    toBinary(x, dataX, binaryX);
    toBinary(y, dataY, binaryY);

    for (int i=0; binaryX[i] != 0 && i < dataX[1]; i++)
    {
        for (int j=0; binaryY[j] != 0 && j < dataY[1]; j++)
        {
            square += binaryX[i] > binaryY[j] ? binaryX[i]/binaryY[j] : binaryY[j]/binaryX[i];
        }

    }
    return square;
}

void maxSize(int n, int *data)
{
    while (data[0]*2 <= n)
    {
        data[0] *= 2;
        data[1]++;
    }

}

void toBinary(int n, int *data, int *binaryN)
{
    int i, j;

    for (i=0, j=0; i<data[1]; i++)
    {
        if (n == 0)
        {
            binaryN[j] = 0;
            j++;
            continue;
        }
        if (n-data[0] >= 0)
        {
            n -= data[0];
            binaryN[j] = data[0];
            j++;
        }
        data[0] /= 2;
    }

}

// O(lg^2(n))