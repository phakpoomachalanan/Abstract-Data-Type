#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
    item_t *table;
    int size;
    int hash_key;
} hash_t;

hash_t* init_hashtable(int size, int hash_key);
item_t init_item(char* text);
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
    hashtable->table = (item_t*)malloc(sizeof(item_t) * size);

    return hashtable;
}

item_t init_item(char* text)
{
    item_t ptr = (item_t)malloc(sizeof(char) * TEXTSIZE);

    strcpy(ptr, text);

    return ptr;
}

void insert(hash_t* hashtable, char* text)
{
    int key = hash(hashtable, text);
    int probe = key, i;

    for (i=0; hashtable->table[probe]!=NULL; i++)
    {
        probe = (key+(i*i+i)/2)%hashtable->size;
    }

    hashtable->table[probe] = init_item(text);
}

int search(hash_t* hashtable, char* text)
{
    int key = hash(hashtable, text);
    int probe, i;

    for (i=0; i<=hashtable->size; i++)
    {
        probe = (key+(i+i*i)/2)%hashtable->size;

        if (hashtable->table[probe] == NULL)
        {
            if (i == 0)
            {
                return -1;
            }
            continue;
        }
        if (strcmp(hashtable->table[probe], text) == 0)
        {
            return probe;
        }
    }

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