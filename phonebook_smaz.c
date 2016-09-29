#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_smaz.h"
#include "smaz.h"

entry *findName(char lastName[], entry *pHead)
{
    char string_lastname[MAX_LAST_NAME_SIZE];
    int comprlen = smaz_compress(lastName, strlen(lastName), string_lastname, sizeof(string_lastname));
    while (pHead != NULL) {
        if (strcasecmp(string_lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    char string_lastname[MAX_LAST_NAME_SIZE];
    int comprlen = smaz_compress(lastName, strlen(lastName), string_lastname, sizeof(string_lastname));
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, string_lastname);
    e->pNext = NULL;
    return e;
}
