#include "../include/database.h"
#include "../include/menu.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    const char** arg;
    int argc;
    void (*func)(sqlite3* db, int argc, char** argv);
} CommandMap;

const char* createErrorCMD[] = {"create"};
const char* createHelpCMD[] = {"create", "--help"};

CommandMap commandMap[] = {
    {createErrorCMD, 1, createError},
    {createHelpCMD, 2, createHelp},
    {NULL, 0, NULL}  // Sentinel value
};

void helpCommand() {
    printf("Usage:  pwdb [OPTIONS] COMMAND [ARG...]\n");
    printf("\n");
    printf("Easy way for you to manage your passwords\n");
    printf("\n");
    printf("Common Commands: \n");
    printf("create       Insert information into the database\n");
    printf("delete       Remove information into the database\n");
    printf("\n");
    printf("Global Options:     \n");
    printf("-g, --group         Storage space\n");
    printf("-p, --password      Single line storage space\n");

    printf("\n");
}

void processComands(sqlite3* db, int argc, char** argv) {
    int exitFlag = 0;

    argc = argc - 1;

    while (0 < 1) {
        for (int j = 0; commandMap[j].arg != NULL && !exitFlag; ++j) {
            int argsLen = commandMap[j].argc;
            int found = 0;
            int i = 1;
            for (int l = 0; l < argsLen; ++l) {
                if (argsLen != argc) {
                    break;
                }
                if (strcmp(argv[i], commandMap[j].arg[l]) == 0) {
                    found++;
                    i++;
                    if (found == argc) {
                        commandMap[j].func(db, argc, argv);
                        exitFlag = 1;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        if (!exitFlag) {
            helpCommand();
        }
        break;
    }
}

void createError() {
    printf("\"pwdb create\" requires at least 1 argument and 1 option. \n");
    printf("See \"pwdb create --help\".\n");
    printf("\n");
    printf("Usage:  pwdb create [OPTION] [ARG...]\n");
    printf("\n");
    printf("Create a group in the database allowing you to insert data in them.\n");
}

void createHelp() {
    printf("\n");
    printf("Usage:  pwdb create [OPTION] [ARG...]\n");
    printf("\n");
    printf("Options:\n");
    printf("-g, --group    Create a group\n");
    printf("-p, --password    Insert a password into a group\n");
    printf("\n");
    printf("Example use:\n");
    printf("pwdb create -p <group-name> <password>\n");
    printf("pwdb create -g <group-name>\n");
    printf("\n");
}

void createGroup(sqlite3* db) {
    char groupName[50];
    int res;

    printf("What do you want to call your new storage: ");
    scanf("%49s", groupName);

    res = createTable(db, "bob");
}

void deleteGroup(sqlite3* db) {
    printf("delete ");
}