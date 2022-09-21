#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item {
    char   *text;
    struct item *next;
} item_t;

typedef struct hash {
    item_t **table;
    int    size;
    int    hash_key;
} hash_t;

hash_t* init_hashtable(int size, int hash_key);
item_t* init_item(char* text);
void insert(hash_t* hashtable, char* text);
int search(hash_t* hashtable, char* text);
unsigned int hash(hash_t* hashtable, char* text);
unsigned int func(int hash_key, int now, char* text);

int main(void) {
    hash_t *hashtable = NULL;
    char   *text = NULL;
    int    m, n, i, hash_key;
    int    command;

    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char) * TEXTSIZE);

    for (i=0; i<n; i++) {
        scanf("%d %s", &command, text);
        switch (command) {
            case 1:
                insert(hashtable, text);
                break;
            case 2:
                printf("%d\n", search(hashtable, text));
                break;
        }
    }
    return 0;
}

hash_t* init_hashtable(int size, int hash_key)
{
    hash_t* hashtable = (hash_t*)malloc(sizeof(hash_t));

    hashtable->hash_key = hash_key;
    hashtable->size = size;
    hashtable->table = (item_t**)malloc(sizeof(item_t*) * size);

    return hashtable;
}

item_t* init_item(char* text)
{
    item_t* item = (item_t*)malloc(sizeof(item_t));

    item->text = text;
    item->next = NULL;

    return item;
}

void insert(hash_t* hashtable, char* text)
{
    int key = hash(hashtable, text);
    item_t* item = hashtable->table[key];

    if (item == NULL)
    {
        hashtable->table[key] = init_item(text);
        return;
    }
    while(item->next != NULL)
    {
        item = item->next;
    }

    item->next = init_item(text);
}

int search(hash_t* hashtable, char* text)
{
    int key = hash(hashtable, text);
    item_t* item = hashtable->table[key];

    if (item == NULL)
    {
        return  -1;
    }
    do
    {
        if (strcmp(item->text, text) == 0)
        {
            return key;
        }
        item = item->next;
    }
    while(item != NULL);

    return -1;
}

unsigned int hash(hash_t* hashtable, char* text)
{
    return func(hashtable->hash_key, strlen(text)-1, text) % hashtable->size;
}

unsigned int func(int hash_key, int now, char* text)
{
    return now == 0 ? text[0] : hash_key * func(hash_key, now-1, text) + text[now];
}