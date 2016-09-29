#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

#define SIZE 9901//prime number

unsigned int hash(hash_table *htable, char *str)
{
    unsigned int hashval = 0;//start hash's value at 0
    unsigned int seed = 31;
    while(*str)
        hashval = hashval * seed + (*str++);
    return hashval % SIZE;//record as remainder
}

hash_table *create_hash_table()
{
    hash_table *new_table;
    if(SIZE<1) return NULL;//invalid size of table

    //allocate memory for hash table
    new_table = malloc(sizeof(hash_table));
    new_table->table = malloc(sizeof(entry *) *SIZE);

    if(new_table == NULL) return NULL;
    if(new_table->table == NULL) return NULL;

    //initialize the elements of the table
    for(int i; i<SIZE; i++)
        new_table->table[i] = NULL;
    return new_table;
}

entry *findName(char *lastName, hash_table *htable)
{
    entry *namelist;
    unsigned int hashval = hash(htable, lastName); //count hash value

    //check string is in the correct list based or not
    for(namelist = htable->table[hashval]; namelist!=NULL; namelist = namelist->pNext)
        if(strcmp(lastName, namelist->lastName) == 0) return namelist;
    return NULL;//if cant find

}

void append(char *lastName, hash_table *htable)
{
    entry *hashed_entry;
    unsigned int hashval = hash(htable, lastName);
    hashed_entry = NULL;
    hashed_entry = (entry*) malloc(sizeof(entry)); //allocate memory for hashed's entry
    memcpy(hashed_entry->lastName, lastName, strlen(lastName)); //copy string
    hashed_entry->pNext = htable->table[hashval];
    htable->table[hashval] = hashed_entry;
}

