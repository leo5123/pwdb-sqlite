
#include "../include/database.h"
#include "../include/menu.h"
#include <sqlite3.h>
#include <stdio.h>

int main(int argc, char** argv) {
    sqlite3* db;
    openDB(db);

    initializeMenu(db);

    closeDB(db);
    return 0;
}
