#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TEXTSIZE 21

typedef char* item_t;

typedef struct hash {
  item_t *table;
  int size;
  int hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hash_key) {
  hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
  hash->size = m;
  hash->hash_key = hash_key;
  hash->table = (item_t *)malloc(sizeof(item_t )*m);
  for (int i = 0;i<m;i++) {
    hash->table[i] = NULL;
  }
  return hash;
}

unsigned int find_hash_value(hash_t *hashtable, char *text) {
  unsigned int hash_value = (int)text[0];
  
  for (int i = 1; i < strlen(text); i++) {
    hash_value = (hashtable->hash_key * hash_value) + (int)text[i];
  }
  hash_value %= hashtable->size;
  
  return hash_value;
}
void insert(hash_t *hashtable, char *text) {
  unsigned int hash_value = find_hash_value(hashtable, text);
  //printf("{%d}",hash_value);
  int start_value = hash_value; 
  char *newtext = (char *)malloc(sizeof(char)*TEXTSIZE);
  strcpy(newtext,text);
  newtext;
  int i = 0;
  while (hashtable->table[hash_value] != NULL) {
    hash_value = start_value+(i+pow(i,2))/2;
    if (hash_value > hashtable->size-1) {
      hash_value%=hashtable->size;
    }
    i++;
  }
  //printf("[%d]",hash_value);
  hashtable->table[hash_value] = newtext;
}

int search(hash_t *hashtable, char *text) {
  unsigned int hash_value = find_hash_value(hashtable, text);
  item_t temp = hashtable->table[hash_value];
  int start_value = hash_value;
  int i = 0;
  while (temp != NULL) {
    if (strcmp(temp, text) == 0) {
      return hash_value;
    }
    hash_value = start_value+(i+pow(i,2))/2;
    if (hash_value > hashtable->size-1) {
      hash_value%=hashtable->size;
    }
    i++;
    temp = hashtable->table[hash_value];
    //printf("[%d]",hash_value);
  }
  //printf("[%dnull]",hash_value);
  return -1;
}

int main(void) {
  hash_t *hashtable = NULL;
  char *text = NULL;
  int m, n, i, hash_key;
  int command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char)*TEXTSIZE);

  for (i = 0; i <n ; i++) {
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