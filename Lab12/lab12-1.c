#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* arr, int size);
void print_arr(int* arr, int size);

int main(void)
{
    int  size, i;
    int* arr;

    scanf("%d", &size);

    arr = (int*)malloc(sizeof(int) * size);

    for (i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, size);
}

void insertion_sort(int* arr, int size)
{
    int i, left;
    int temp;

    for (i=1; i<size; i++)
    {
        for (left=0; left<i; left++)
        {
            if (arr[i] < arr[left])
            {
                temp = arr[left];
                arr[left] = arr[i];
                arr[i] = temp;
            }
        }
        print_arr(arr,size);
    }
}

void print_arr(int* arr, int size)
{
    int i;

    for (i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}