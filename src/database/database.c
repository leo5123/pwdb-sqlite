#include "../include/database.h"
#include <sqlite3.h>
#include <stdio.h>

int openDB(sqlite3 *db) {
    int rc = sqlite3_open("pwdatabase.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }
}

int closeDB(sqlite3 *db) {
    sqlite3_close(db);
    return 0;
}

int tableExists(sqlite3 *db, const char *table) {
    const char *sql = "SELECT name FROM sqlite_master WHERE type='table' AND name=?;";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    sqlite3_bind_text(stmt, 1, table, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        sqlite3_finalize(stmt);
        fprintf(stderr, "Table already exists: %s\n", table);
        return 1;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_finalize(stmt);
    return 0;
}

int createTable(sqlite3 *db, const char *table) {
    int rc;
    char *err_msg = 0;
    char sql[100];

    if (tableExists(db, table) == 1) {
        fprintf(stderr, "Table already exists.\n");
        return 1;
    }

    snprintf(sql, sizeof(sql), "CREATE TABLE %s (ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Password TEXT);", table);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        return 1;
    }

    printf("Table created successfully.\n");
    return 0;
}