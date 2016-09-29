#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define SMAZ 1

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} entry_all;

//只尋找lastname先就可以了，可以再通過lastname尋找所有的詳細資料
typedef struct __LASTNAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry_all *all;//for finding more detail
    struct __LASTNAME_ENTRY *pNext;
} entry;

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);
#endif

