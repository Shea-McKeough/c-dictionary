/*
 * File: dict.c
 *
 * Most of the dictionary implementation, command handling,
 * and memory management logic were written by me.
 *
 * The struct definitions and function prototypes were
 * provided by the course instructor and are
 * used with minor integration changes.
 */

#include <stdlib.h>
#include <string.h>
#include "dict.h"

typedef struct dict_list {
    char* key;
    char* val;
    struct dict_list* next;
} dict_list_t;

typedef struct dict {
    dict_list_t* head;
    size_t size;
} dict_t;


// Creates a dictionary
dict_t* dict_create () {
  dict_t* ret = malloc(sizeof(dict_t));
  ret->size = 0;
  ret->head = NULL;
  return ret;
}


void dict_put (dict_t* dict, const char* key, const char* val) {
  // Deletes pair if val is null and then returns
  if (val == NULL) {
    dict_del(dict, key);
    return;
  }

  // Checks dictionary for key. If key exists, val is updated then returns
  dict_list_t* el = dict->head;

  while (el != NULL) {
    if (strcmp(el->key, key) == 0) {
      free(el->val);
      el->val = strdup(val);
      return;
    }
    el = el->next;
  }

  // Puts key/val pair in dictionary if it doesn't already exist
  dict_list_t* newNode = malloc(sizeof(dict_list_t));

  newNode->key = strdup(key);
  newNode->val = strdup(val);

  newNode->next = dict->head;
  dict->head = newNode;
  dict->size++;
}


// Returns the value associated with the key, or NULL if none
char* dict_get (const dict_t* dict, const char* key) {
  dict_list_t* el = dict->head;

  while (el != NULL) {
    if (strcmp(el->key, key) == 0) return el->val;
    el = el->next;
  }
  return NULL;
}



// Deletes the pair associated with key
void dict_del (dict_t* dict, const char* key) {
  // Initializes pointers for current and previous nodes
  dict_list_t* el = dict->head;
  dict_list_t* prev = NULL;

  // Iterates through dictionary to find node to delete
  while (el != NULL) {
    if (strcmp(el->key, key) == 0) {
      if (prev == NULL) {             // Node to delete is head
	dict->head = el->next;        // Replaces head with next node
      } else {
	prev->next = el->next;        // Unlinks current node and reorders list
      }

      // Frees node memory
      free(el->key);
      free(el->val);
      free(el);

      // Decreases count of key/val pairs and return
      dict->size--;
      return;
    }

    prev = el;
    el = el->next;
  }
}


// Returns the size of the dict
size_t dict_size (const dict_t* dict) {
  return dict->size;
}

// Deletes all elements in a dictionary
void dict_clear (dict_t* dict) {
  dict_list_t* el = dict->head;
  dict_list_t* temp = NULL;

  while (el != NULL) {
    temp = el->next;

    free(el->key);
    free(el->val);
    free(el);

    el = temp;
  }

  dict->head = NULL;
  dict->size = 0;
}

// Frees a dictionary
void dict_destroy (dict_t* dict) {
  dict_clear(dict);
  free(dict);
}
