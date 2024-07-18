#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <stdio.h>

int createTable(sqlite3 *, const char *table);
int tableExists(sqlite3 *db, const char *table);
int openDB(sqlite3 *db);
int closeDB(sqlite3 *db);

#endif