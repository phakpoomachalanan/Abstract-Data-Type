#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char* word;
    char* sorted_word;
}
node_t;

typedef node_t list_t;

list_t* init_list(int size);
void insertion_sort(char* arr, int size);

int main(void)
{
    int  size, i, j, ask;
    char c;
    char temp[50];
    list_t* list;

    scanf("%d %d", &size, &ask);

    list = init_list(size);

    for (i=0; i<size; i++)
    {
        scanf("%s%c", list[i].word, &c);
        
        strcpy(list[i].sorted_word, list[i].word);
        insertion_sort(list[i].sorted_word, strlen(list[i].word));
    }
    for (i=0; i<ask; i++)
    {
        scanf("%s%c", temp, &c);
        insertion_sort(temp, strlen(temp));

        for (j=0; j<size; j++)
        {
            if (strcmp(temp, list[j].sorted_word) == 0)
            {
                printf("%s ", list[j].word);
            }
        }
        printf("\n");
    }
}

list_t* init_list(int size)
{
    list_t* list = (list_t*)malloc(sizeof(list_t) * size);
    int     i;

    for (i=0; i<size; i++)
    {
        list[i].word = (char*)malloc(sizeof(char) * 50);
        list[i].sorted_word = (char*)malloc(sizeof(char) * 50);
    }

    return list;
}

void insertion_sort(char* arr, int size)
{
    int   i, left;
    char  temp;

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
    }
}