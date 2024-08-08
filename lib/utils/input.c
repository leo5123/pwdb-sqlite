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

int storeCode(void *param, int argc, char **argv, char **azColName) {
    TableResult *result = (TableResult *)param;
    result->data = malloc(sizeof(char **) * argc);
    for (int i = 0; i < argc; i++) {
        if (argv[i]) {
            result->data[i] = (char *)malloc((strlen(argv[i]) + 1) * sizeof(char));
            strncpy(result->data[i], argv[i], strlen(argv[i]) + 1);
        } else {
            result->data[i] = NULL;
        }
    }

    return 0;
}

int storeResult(void *param, int argc, char **argv, char **azColName) {
    TableResult *result = (TableResult *)param;

    if (result->rows == 0 && result->data == NULL) {
        result->columns = argc;
        result->data = malloc(sizeof(char *) * argc);
        for (int i = 0; i < argc; i++) {
            result->data[i] = strdup(azColName[i]);
        }
    }

    result->data = realloc(result->data, sizeof(char *) * (result->rows + 1 + 1) * result->columns);
    for (int i = 0; i < argc; i++) {
        result->data[(result->rows + 1) * result->columns + i] = argv[i] ? strdup(argv[i]) : strdup("NULL");
    }
    result->rows++;
    return 0;
}

void listSingleColumn(TableResult result) {
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
    return;
}

int storeTwoRowResult(void *param, int argc, char **argv, char **azColName) {
    TableResult *result = (TableResult *)param;

    if (result->rows == 0 && result->data == NULL) {
        result->columns = argc;
        result->data = malloc(sizeof(char *) * argc);
        if (!result->data) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        for (int i = 0; i < argc; i++) {
            result->data[i] = strdup(azColName[i]);
            if (!result->data[i]) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
        }
    }

    result->data = realloc(result->data, sizeof(char *) * (result->rows + 2) * result->columns);
    if (!result->data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < argc; i++) {
        result->data[(result->rows + 1) * result->columns + i] = argv[i] ? strdup(argv[i]) : strdup("NULL");
        if (!result->data[(result->rows + 1) * result->columns + i]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }
    result->rows++;
    return 0;
}

void printLineColumn(int columnWidths[], int numColumns) {
    for (int i = 0; i < numColumns; i++) {
        printf("+");
        for (int j = 0; j < columnWidths[i]; j++) {
            printf("-");
        }
    }
    printf("+\n");
}

void printWrappedCell(const char *text, int width) {
    int textLen = strlen(text);
    int start = 0;

    while (start < textLen) {
        if (start > 0) {
            printf("|");
        }

        printf(" %-*.*s ", width - 2, width - 2, &text[start]);
        start += width - 2;
    }
    printf("|");
}

void printTableResult(TableResult *result) {
    if (result->rows == 0) {
        printf("No content in that table\n");
        return;
    }

    const int maxWidth = 100;

    int columnWidths[result->columns];
    for (int i = 0; i < result->columns; i++) {
        columnWidths[i] = strlen(result->data[i]);
        for (int j = 1; j <= result->rows; j++) {
            int cellLength = strlen(result->data[j * result->columns + i]);
            if (cellLength > columnWidths[i]) {
                columnWidths[i] = cellLength;
            }
        }
        columnWidths[i] += 2;

        if (columnWidths[i] > maxWidth) {
            columnWidths[i] = maxWidth;
        }
    }
    printLineColumn(columnWidths, result->columns);
    for (int col = 0; col < result->columns; col++) {
        printf("| %-*s ", columnWidths[col] - 2, result->data[col]);
    }
    printf("|\n");
    printLineColumn(columnWidths, result->columns);
    for (int row = 1; row <= result->rows; row++) {
        int moreLines = 1;
        int line = 0;
        while (moreLines) {
            moreLines = 0;
            for (int col = 0; col < result->columns; col++) {
                const char *cell = result->data[row * result->columns + col];
                int cellLength = strlen(cell);
                int start = line * (columnWidths[col] - 2);
                if (start < cellLength) {
                    moreLines = 1;
                    printf("| %-*.*s ", columnWidths[col] - 2, columnWidths[col] - 2, &cell[start]);
                } else {
                    printf("| %-*s ", columnWidths[col] - 2, "");
                }
            }
            printf("|\n");
            line++;
        }
    }
    printLineColumn(columnWidths, result->columns);
}