#include "../../include/database.h"
#include "../../include/messages.h"
#include "../../include/input.h"
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

sqlite3 *openDB(sqlite3 *db) {
    int rc = sqlite3_open("pwclipper.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return NULL;
    }
    return db;
}

int closeDB(sqlite3 *db) {
    sqlite3_close(db);
    return 0;
}

void createTable(sqlite3 *db, char *table) {
    char *err_msg = 0;
    int rc;
    char sql[256];

    sanitizeTableName(table);
    snprintf(sql, sizeof(sql),
             "CREATE TABLE IF NOT EXISTS %s ("
             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
             "name TEXT NOT NULL, code INTEGER NOT NULL);",
             table);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
}

void insertIntoTable(sqlite3 *db, char *table, char *name, char *code) {
    sqlite3_stmt *statement;
    int rc;

    char insertInfo[256];
    sprintf(insertInfo,
            "INSERT INTO %s (name, code) VALUES ('%s', '%s')",
            table, name, code);

    rc = sqlite3_prepare_v2(db, insertInfo, strlen(insertInfo), &statement, NULL);
    rc = sqlite3_step(statement);

    if (rc == SQLITE_OK) {
        printf("Error inserting data: ");
        sqlite3_errmsg(db);
    }

    sqlite3_finalize(statement);
}

void listTablesNames(sqlite3 *db) {
    char *zErrMsg = 0;
    int rc;
    TableResult result = {0};
    const char *sql = "SELECT name FROM sqlite_master WHERE type='table';";

    rc = sqlite3_exec(db, sql, storeResult, &result, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return;
    }

    if (result.rows > 0) {
        int largestWordLength = 0;
        for (int i = 0; i <= result.rows * result.columns; i++) {
            int length = strlen(result.data[i]);
            if (length > largestWordLength) {
                largestWordLength = length;
            }
        }

        int columnWidth = largestWordLength + 2;

        for (int j = 0; j < columnWidth; j++) {
            if (j == 0) {
                printf("+");
            }
            printf("-");
        }
        printf("+\n");
        for (int i = 0; i < result.columns; i++) {
            printf("| %-*s", columnWidth - 1, "Groups ");
        }
        printf("|\n");

        for (int i = 0; i < result.columns; i++) {
            for (int j = 0; j < columnWidth; j++) {
                if (j == 0) {
                    printf("+");
                }
                printf("-");
            }
        }
        printf("+\n");

        for (int row = 1; row <= result.rows; row++) {
            if (!strcmp(result.data[row], "sqlite_sequence")) {
                continue;
            }
            for (int col = 0; col < result.columns; col++) {
                printf("| %-*s ", columnWidth - 2, result.data[row * result.columns + col]);
            }

            printf("|\n");
        }
        for (int j = 0; j < columnWidth; j++) {
            if (j == 0) {
                printf("+");
            }
            printf("-");
        }
        printf("+\n");
    }

    for (int i = 0; i <= result.rows * result.columns; i++) {
        free(result.data[i]);
    }
    free(result.data);
}
