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
  char *newtext = (char *)malloc(sizeof(char)*TEXTSIZE);
  item_t *newitem = (item_t *)malloc(sizeof(item_t));
  strcpy(newtext,text);
  newitem->text = newtext;
  newitem->next = NULL;
  if (hashtable->table[hash_value] == NULL) {
    hashtable->table[hash_value] = newitem; 
  } else {
    newitem->next = hashtable->table[hash_value]->next;
    hashtable->table[hash_value]->next = newitem;
  }
}
int count_text(item_t *temp, char *text) {
  if(temp == NULL) {
    return -1;
  }
  int text_countC = 0;
  int text_count = 0;
  for(int i=0;i<strlen(text);i++) {
    text_countC+=(int)text[i];
  }
  for(int i=0;i<strlen(temp->text);i++) {
    text_count+=(int)temp->text[i];
  }
  if (text_count == text_countC) {
    return 1;
  } else {
    count_text(temp->next, text);
  }
}
int search(hash_t *hashtable, char *text) {
  unsigned int hash_value = find_hash_value(hashtable, text);
  item_t *temp = hashtable->table[hash_value];
  if (count_text(temp, text) == 1) {
    return hash_value;
  } else {
    return -1;
  }
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