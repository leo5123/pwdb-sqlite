#ifndef INPUT_H
#define INPUT_H

typedef struct {
    char **data;
    int rows;
    int columns;
} TableResult;

int sanitizeTableName(char *table);
void printLine(int column_width, int num_columns);
int storeResult(void *param, int argc, char **argv, char **azColName);
void listSingleColumn(TableResult result);
int storeTwoRowResult(void *param, int argc, char **argv, char **azColName);
void printTableResult(TableResult *result);
int storeCode(void *param, int argc, char **argv, char **azColName);

#endif