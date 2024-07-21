#ifndef MENU_H
#define MENU_H

#include <sqlite3.h>
#include <stdio.h>

void helpCommand();
void createGroup(sqlite3* db);
void deleteGroup(sqlite3* db);
void processComands(sqlite3* db, int argc, char** argv);
void handleGroup(sqlite3* db, int argc, char** argv);
void createError();
void createHelp();

#endif