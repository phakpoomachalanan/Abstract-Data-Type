#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct anagram //linked list type beat
{
    char *word; 
    char *sorted; //sorted word
    struct anagram *next;
} anagram_t;

char *insertion_sort(char *word,int size);

anagram_t *append(anagram_t *a,char *word) {
    anagram_t *tmp = a;
    anagram_t *newnode = (anagram_t*)malloc(sizeof(anagram_t));
    newnode->word = (char*)malloc(sizeof(char)*99);
    newnode->sorted = (char*)malloc(sizeof(char)*99);
    strcpy(newnode->word,word);
    strcpy(newnode->sorted,insertion_sort(word,strlen(word)-1));
    newnode->next = NULL;
    if (a == NULL)
    {
        return newnode;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
    return a;
}

anagram_t *delete(anagram_t *a,char *word) {
    anagram_t *node = a;
    anagram_t *nodebefore;
    if (a->next == NULL)
    {
        return NULL;
    }
    while (strcmp(node->word,word) != 0 && node->next != NULL)
    {
        nodebefore = node;
        node = node->next;
    }
    printf("%s ",nodebefore->word);
    if (node == a)
    {
        free(node);
        return a->next;
    }
    else if (node->next != NULL)
    {
        nodebefore->next = node->next;
    } else {
        nodebefore->next = NULL;
    }
    free(node);
    return a;
}


char *insertion_sort(char *word,int size) {
    int index_sorted,index;
    int first_unsorted = 1;
    int tmp;
    for (int j = 0; j < size-1; j++)
    {
        index_sorted = 0;
        while (word[index_sorted] < word[first_unsorted]) // find slot
        {
            index_sorted++;
        }
        // index_sorted is now at the first number that is more than it
        tmp = word[first_unsorted];
        index = first_unsorted;
        while (index > index_sorted) // move all after 1 right
        {
            word[index] = word[index-1];
            index--;
        }
        word[index_sorted] = tmp;
        first_unsorted++;
        /*for (int i = 0; i < size; i++)
        {
            printf("%d ",word[i]);
        }
        printf("\n");*/
    }
    return word;
}

void main() {
    anagram_t *a = NULL;
    int input,words;
    scanf("%d %d",&input,&words);
    char *word = (char*)malloc(sizeof(char)*99);
    
    for (int i = 0; i < input; i++)
    {
        //linked list go brr
        scanf("%s",word);
        a = append(a,word);
    }
    char *findword = (char*)malloc(sizeof(char)*99);
    char *findsorted = (char*)malloc(sizeof(char)*99);
    anagram_t *tmp;
    for (int i = 0; i < words; i++)
    {
        tmp = a;
        scanf("%s",findword);
        strcpy(findsorted,insertion_sort(findword,strlen(word)-1));
        while (tmp->next != NULL  && strcmp(findsorted,tmp->sorted)!=0)
        {
            tmp = tmp->next;
        }
        while (tmp != NULL && strcmp(findsorted,tmp->sorted)==0)
        {
            a = delete(a,findword);
            if (tmp->next != NULL)    
                tmp = tmp->next;
            while (tmp->next != NULL && strcmp(findsorted,tmp->sorted)!=0)
            {
                tmp = tmp->next;
            }
        }
        printf("\n");
    }
}