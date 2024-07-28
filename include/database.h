#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <stdio.h>

void createTable(sqlite3 *db, char *table);
sqlite3 *openDB(sqlite3 *db);
int closeDB(sqlite3 *db);
int sanitizeTableName(char *table);
void listTablesNames(sqlite3 *db);
void insertIntoTable(sqlite3 *db, char *name, char *code, char *table);

#endif