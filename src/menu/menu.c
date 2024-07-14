#include "../include/database.h"
#include "../include/menu.h"
#include <sqlite3.h>
#include <stdio.h>

int initializeMenu(sqlite3* db) {
    int rc;

    // if (!tableExists(db, "account")) {
    //     rc = createTable(db);
    //     if (rc != 0) {
    //         fprintf(stderr, "Failed to create table.\n");
    //     }
    // }

    printf("+-------------------------------+\n");
    printf("|              Menu             |\n");
    printf("+-------------------------------+\n");
    printf("|  [1] Create new storage       |\n");
    printf("+-------------------------------+\n");

    char* choice;
    printf("Select a number: ");
    scanf("%d", &choice);
    if (choice == "1") {
        addRow(db);
    }

    return 0;
}

int addRow(sqlite3* db) {
    char* name;
    printf("What do you want to call your new storage?");
    scanf("%d", name);
    return 0;
}