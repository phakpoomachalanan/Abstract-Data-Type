#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int *array,int size) {
    int index_sorted,index;
    int first_unsorted = 1;
    int tmp;
    for (int j = 0; j < size-1; j++)
    {
        index_sorted = 0;
        while (array[index_sorted] < array[first_unsorted]) // find slot
        {
            index_sorted++;
        }
        // index_sorted is now at the first number that is more than it
        tmp = array[first_unsorted];
        index = first_unsorted;
        while (index > index_sorted) // move all after 1 right
        {
            array[index] = array[index-1];
            index--;
        }
        array[index_sorted] = tmp;
        first_unsorted++;
        for (int i = 0; i < size; i++)
        {
            printf("%d ",array[i]);
        }
        printf("\n");
    }
}


void main() {
    int size;
    scanf("%d",&size);

    int *array = (int*)malloc(sizeof(int)*size);
    
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }

    insertion_sort(array,size);
}