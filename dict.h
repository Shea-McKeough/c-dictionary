#pragma once

// THIS FILE CONTAINS THE FORWARD DECLARATIONS OF THE DICTIONARY TYPE dict_t AND
// THE LIBRARY FUNCTIONS THAT MANIPULATE DICTIONARIES.

#include <unistd.h>

/*
 * struct dict is defined in dict.c.
 */
typedef struct dict dict_t;

/*
 * Returns a new empty dictionary. It should be destroyed when not used anymore.
 */
dict_t* dict_create ();

/*
 * Frees a dictionary.
 */
void    dict_destroy (dict_t* dic);

/*
 * Put an element in a dictionary.  key is case sensitive, val is a string.
 *   If the key already exists, its value is updated.  If val is NULL, the pair
 *   is deleted.
 */
void    dict_put (dict_t* dic, const char* key, const char* val);

/*
 * Returns the value associated with key, or NULL if none.
 */
char*   dict_get (const dict_t* dic, const char* key);

/*
 * Delete the pair associated with key.
 */
void    dict_del (dict_t* dic, const char* key);

/*
 * Returns the size of the dict.
 */
size_t  dict_size (const dict_t* dic);

void    dict_clear (dict_t* dic);
