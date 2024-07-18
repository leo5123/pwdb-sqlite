#ifndef MENU_H
#define MENU_H

#include <sqlite3.h>
#include <stdio.h>

int initializeMenu(sqlite3* db);
int createGroup(sqlite3* db);
int deleteGroup(sqlite3* db);

#endif