#include "../../include/database.h"
#include "../../include/messages.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

void createGroup(sqlite3* db, int argc, char** argv) {
    int err;
    if (argc == 2 || argc >= 4) {
        createArgumentRequired();
        return;
    }
    createTable(db, argv[3]);
}

void insertIntoGroup(sqlite3* db, int argc, char** argv) {
    if (argc < 5) {
        insertArgumentRequired();
        return;
    }
    insertIntoTable(db, argv[3], argv[4], argv[5]);
}

void listGroup(sqlite3* db, int argc, char** argv) {
    listTablesNames(db);
}

void deleteGroup(sqlite3* db) {
    printf("delete ");
}