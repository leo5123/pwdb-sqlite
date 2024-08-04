
#include "../../include/commands.h"
#include "../../include/handler.h"
#include "../../include/messages.h"
#include "../../include/database.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

const char* createErrorCMD[] = {"create"};
const char* createHelpCMD[] = {"create", "--help"};
const char* createGroupShortCMD[] = {"create", "-g"};
const char* createGroupCMD[] = {"create", "--group"};

// const char* listGroupCMD[] = {"ls", "-g"};
const char* insertErrorCMD[] = {"insert"};
const char* insertHelpCMD[] = {"insert", "--help"};
const char* insertIntoGroupShortCMD[] = {"insert", "-g"};
const char* insertIntoGroupCMD[] = {"insert", "--password"};

const char* listErrorCMD[] = {"ls"};
const char* listHelpCMD[] = {"ls", "--help"};
const char* listGroupCMD[] = {"ls", "--group"};
const char* listGroupShortCMD[] = {"ls", "-g"};

const char* clipPasswordCMD[] = {"cp"};
const char* clipHelpCMD[] = {"cp", "--help"};

Command commands[] = {
    {createErrorCMD, 1, createError},
    {createHelpCMD, 2, createHelp},
    {createGroupShortCMD, 2, createGroup},
    {createGroupCMD, 2, createGroup},

    {insertErrorCMD, 1, insertError},
    {insertHelpCMD, 2, insertHelp},
    {insertIntoGroupShortCMD, 2, insertIntoGroup},
    {insertIntoGroupCMD, 2, insertIntoGroup},

    {listErrorCMD, 1, listGroup},
    {listHelpCMD, 2, listHelp},
    {listGroupCMD, 2, listGroup},
    {listGroupShortCMD, 2, listPassword},
    {listGroupShortCMD, 2, listPassword},

    {clipPasswordCMD, 1, clipPassword},
    {clipHelpCMD, 2, clipHelp},

    {NULL, 0, NULL}  // Sentinel value
};

int main(int argc, char** argv) {
    sqlite3* db;
    db = openDB(db);
    processComands(db, argc, argv, commands);
    closeDB(db);
    return 0;
}
