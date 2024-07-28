#include "../../include/input.h"
#include "../../include/messages.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int sanitizeTableName(char *table) {
    char maxLenTableName[52];
    strncpy(maxLenTableName, table, 50);
    for (size_t i = 0; i < strlen(maxLenTableName); i++) {
        if (!isalnum(maxLenTableName[i]) && maxLenTableName[i] != '_' && maxLenTableName[i] != '-') {
            createExample();
            printf("Invalid character: \"%c\"\n", maxLenTableName[i]);
            return 0;
        }
    }
    char quotes[60];
    sprintf(quotes, "\"%s\"", maxLenTableName);
    strncpy(table, quotes, 60);
}

void printLine(int columnWidth, int numColumns) {
    for (int i = 0; i < numColumns; i++) {
        printf("+");
        for (int j = 0; j < columnWidth; j++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

int storeResult(void *param, int argc, char **argv, char **azColName) {
    TableResult *result = (TableResult *)param;

    if (result->rows == 0 && result->data == NULL) {
        result->columns = argc;
        result->data = malloc(sizeof(char *) * argc);  // Allocate memory for the header row
        for (int i = 0; i < argc; i++) {
            result->data[i] = strdup(azColName[i]);
        }
    }

    result->data = realloc(result->data, sizeof(char *) * (result->rows + 1 + 1) * result->columns);  // Allocate memory for the new row
    for (int i = 0; i < argc; i++) {
        result->data[(result->rows + 1) * result->columns + i] = argv[i] ? strdup(argv[i]) : strdup("NULL");
    }
    result->rows++;
    return 0;
}