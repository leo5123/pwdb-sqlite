#include "../include/database.h"
#include "../include/menu.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

char createStorage[10] = "1";

int initializeMenu(sqlite3* db) {
    int rc;

    printf("+-------------------------------+\n");
    printf("|              Menu             |\n");
    printf("+-------------------------------+\n");
    printf("|  [1] Create password group    |\n");
    printf("+-------------------------------+\n");
    printf("|  [2] Delete password group    |\n");
    printf("+-------------------------------+\n");

    char choice[10];

    printf("Select a number: ");
    scanf("%49s", choice);

    if (strcmp(choice, "1") == 0) {
        createGroup(db);
    }

    return 0;
}

int createGroup(sqlite3* db) {
    char groupName[50];
    int res;

    printf("What do you want to call your new storage: ");
    scanf("%49s", groupName);

    res = createTable(db, "bob");

    return 0;
}

int deleteGroup(sqlite3* db) {
    return 0;
}