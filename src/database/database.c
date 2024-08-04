#include "../../include/database.h"
#include "../../include/messages.h"
#include "../../include/input.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

sqlite3 *openDB(sqlite3 *db) {
    const char *home = getenv("HOME");
    char db_path[1024];

    if (home == NULL) {
        fprintf(stderr, "Cannot find HOME environment variable\n");
        return NULL;
    }

    snprintf(db_path, sizeof(db_path), "%s/.pwdb/pwdb.db", home);

    char dir_path[1024];
    snprintf(dir_path, sizeof(dir_path), "%s/.pwdb", home);
    if (mkdir(dir_path, 0700) != 0 && errno != EEXIST) {
        perror("mkdir");
        return NULL;
    }

    int rc = sqlite3_open(db_path, &db);
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
        fprintf(stderr, "%s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
    }
}

void insertIntoTable(sqlite3 *db, char *table, char *name, char *code) {
    sqlite3_stmt *statement;
    int rc;

    char insertInfo[2000];
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
        fprintf(stderr, "%s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return;
    }
    listSingleColumn(result);
}

void listTable(sqlite3 *db, char *table) {
    char *zErrMsg = 0;
    int rc;
    TableResult result = {0};

    char sql[256];
    sprintf(sql,
            "SELECT name, code FROM ('%s')",
            table);

    rc = sqlite3_exec(db, sql, storeResult, &result, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%s\n", "Table doesn't exist");
        return;
    }
    printTableResult(&result);
    return;
}

void listEntry(sqlite3 *db, char *table, char *name) {
    char *zErrMsg = 0;
    int rc;
    TableResult result = {0};

    int sql_size = snprintf(NULL, 0, "SELECT code FROM %s WHERE name = '%s';", table, name) + 1;
    char *sql = malloc(sql_size);
    if (sql == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    snprintf(sql, sql_size, "SELECT code FROM %s WHERE name = '%s';", table, name);

    rc = sqlite3_exec(db, sql, storeCode, &result, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%s\n", "Not found");
        return;
    }

    char *cmd;
    int cmd_size = snprintf(NULL, 0, "echo -n '%s' | xclip -selection clipboard", result.data[0]) + 1;
    cmd = (char *)malloc(cmd_size);
    if (cmd == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    snprintf(cmd, cmd_size, "echo -n '%s' | xclip -selection clipboard", result.data[0]);
    system(cmd);
    return;
}