#ifndef HANDLER_H
#define HANDLER_H

#include <sqlite3.h>
#include <stdio.h>
#include "../include/commands.h"

typedef struct {
    const char** arg;
    int argc;
    void (*func)(sqlite3* db, int argc, char** argv);
} Command;

void processComands(sqlite3* db, int argc, char** argv, Command* commandMap);

#endif