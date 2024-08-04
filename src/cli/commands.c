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
    return;
}

void insertIntoGroup(sqlite3* db, int argc, char** argv) {
    if (argc == 2 || argc < 5 || argc > 5) {
        insertArgumentRequired();
        return;
    }
    insertIntoTable(db, argv[3], argv[4], argv[5]);
    return;
}

void listPassword(sqlite3* db, int argc, char** argv) {
    if (argc == 2) {
        listError();
        return;
    }
    listTable(db, argv[3]);
    return;
}

void listGroup(sqlite3* db, int argc, char** argv) {
    listTablesNames(db);
    return;
}

void clipPassword(sqlite3* db, int argc, char** argv) {
    if (argc == 1) {
        clipError();
        return;
    }
    if (argc == 2) {
        clipError();
        return;
    }

    listEntry(db, argv[2], argv[3]);
    return;
}

void deleteGroup(sqlite3* db) {
    printf("delete ");
}