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

#endif