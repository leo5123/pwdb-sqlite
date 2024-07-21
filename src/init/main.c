
#include "../include/database.h"
#include "../include/menu.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    sqlite3* db;
    openDB(db);

    if (argc == 1) {
        helpCommand(db);
    }
    if (argc > 1) {
        processComands(db, argc, argv);
    }

    closeDB(db);
    return 0;
}
