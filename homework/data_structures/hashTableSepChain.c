#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item {
    char *text;
    struct item *next;
} item_t;

typedef struct hash {
    item_t **table;
    int size;
    int hash_key;
} cache_t;


cache_t *init_hashtable(int m,int hash_key) {
    cache_t *h = (cache_t*)malloc(sizeof(cache_t));
    h->hash_key = hash_key;
    h->size = m;
    h->table = (item_t**)malloc(sizeof(item_t*)*m);
    for (int i = 0; i < m; i++)
    {
        h->table[i] = NULL;
    }
    
    return h;
}

unsigned int f(int key ,int n ,char *text) {
    if (n == 0)
    {
        return text[0];
    }
    return key*f(key,n-1,text)+text[n];
}

unsigned int hash(cache_t *hashtable , char *text) {
    int key = hashtable->hash_key;
    int n = strlen(text)-1;
    return(f(key,n,text) % hashtable->size);
}

void insert(cache_t *hashtable , char *text) {
    item_t *i = (item_t*)malloc(sizeof(item_t));
    char *tmp = (char*)malloc(sizeof(char)*TEXTSIZE);
    strcpy(tmp, text);
    i->text = tmp;
    i->next = NULL;
    unsigned int index = hash(hashtable,text); // hash
    item_t *curr_item = hashtable->table[index];
    //printf("%p",curr_item);
    if (curr_item == NULL)
    {
        hashtable->table[index] = i;
        return;
    } 
    while (curr_item->next != NULL)
    {       
        curr_item = curr_item->next;
    }
    curr_item->next = i;
}

int search(cache_t *hashtable, char *text) {
    unsigned int index = hash(hashtable,text);
    if (hashtable->table[index] == NULL)
    {
        return -1;
    }
    
    item_t *curr_item = hashtable->table[index];
    while (curr_item != NULL)
    {
        if (strcmp(curr_item->text , text) == 0)
        {
            return index;
        }
        curr_item = curr_item->next;
    }
    return -1;

}



int main(void) {
    cache_t *hashtable = NULL;
    char *text = NULL;
    int m,n,i,hash_key;
    int command;

    scanf("%d %d %d", &m,&n,&hash_key);
    hashtable = init_hashtable(m,hash_key);
    text  = (char *)malloc(sizeof(char)*TEXTSIZE);

    for ( i = 0; i < n; i++)
    {
        scanf("%d %s",&command,text);
        switch (command)
        {
        case 1:
            insert(hashtable,text);
            break;
        case 2:
            printf("%d\n",search(hashtable,text));
            break;
        }
    }
    return 0;
}

