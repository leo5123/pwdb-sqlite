#ifndef COMMANDS_H
#define COMMANDS_H

#include "../include/handler.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

void createGroup(sqlite3* db, int argc, char** argv);
void deleteGroup(sqlite3* db, int argc, char** argv);
void insertIntoGroup(sqlite3* db, int argc, char** argv);
void listGroup(sqlite3* db, int argc, char** argv);
void listPassword(sqlite3* db, int argc, char** argv);
void clipPassword(sqlite3* db, int argc, char** argv);

#endif