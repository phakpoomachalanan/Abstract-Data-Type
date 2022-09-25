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


hash_t *init_hashtable(int m,int hash_key) {
    
    hash_t *h = (hash_t*)malloc(sizeof(hash_t));
    h->hash_key = hash_key;
    h->size = m;
    h->table = (item_t*)malloc(sizeof(item_t)*m);
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

unsigned int hash(hash_t *hashtable , char *text) {
    int key = hashtable->hash_key;
    int n = strlen(text)-1;
    return(f(key,n,text) % hashtable->size);
}

int F(int c) {
    return (c+c*c)/2;
}

void insert(hash_t *hashtable , char *text) {
    item_t i = (item_t)malloc(sizeof(char)*TEXTSIZE);
    strcpy(i,text);
    unsigned int index = hash(hashtable,text);
    int probe = index;
    int c = 0;
    while (hashtable->table[probe] != NULL)
    {
       probe = (index + F(c)) % hashtable->size;
       c++;
    }
    
    hashtable->table[probe] = i;
}

int search(hash_t *hashtable, char *text) {
    unsigned int index = hash(hashtable,text);
    int probe = index;
    int c = 0;
    while (hashtable->table[probe] != NULL)
    {
       if (strcmp(hashtable->table[probe],text) == 0)
       {
            return probe;
       }       
       probe = (index + F(c)) % hashtable->size;
       c++;
    }
    return -1;

}






int main(void) {
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m,n,i,hash_key;
    int command;

    scanf("%d %d %d", &m,&n,&hash_key);
    hashtable = init_hashtable(m,hash_key);
    text  = (char *)malloc(sizeof(char)*TEXTSIZE);

    for ( i = 0; i < n; i++)
    {
        scanf("%d %s",&command,text);\
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

