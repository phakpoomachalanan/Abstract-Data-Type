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
} hash_t;

hash_t *init_hashtable(int m, int hash_key) {
  hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
  hash->size = m;
  hash->hash_key = hash_key;
  hash->table = (item_t **)malloc(sizeof(item_t *)*m);
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
  char *newtext;
  newtext = (char *)malloc(sizeof(char)*TEXTSIZE);
  printf("[%d]",hash_value);
  item_t *newitem = (item_t *)malloc(sizeof(item_t));
  strcpy(text,*newtext);
  newitem->text = newtext;
  newitem->next = NULL;
  printf("%p",hashtable->table[hash_value]);
  if (hashtable->table[hash_value] == NULL) {
    hashtable->table[hash_value] = newitem; 
  } else {
    newitem->next = hashtable->table[hash_value]->next;
    hashtable->table[hash_value]->next = newitem;
  }
}

int search(hash_t *hashtable, char *text) {
  unsigned int hash_value = find_hash_value(hashtable, text);
  item_t *temp = hashtable->table[hash_value];
  while(temp->text != text) {
    if (temp->next == NULL) {
      return -1;
    }
    temp = temp->next;
  }
  return hash_value;
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
        for(int i=0;i<m;i++) {
          printf("%d",i);
          item_t *temp = hashtable->table[i];
          while (temp != NULL) {
            printf("[%s]",temp->text);
            temp = temp->next;
          }
          printf("\n");
        }
        break;
      case 2:
        printf("%d\n", search(hashtable, text));
        break;
    }
  }
  return 0;
}