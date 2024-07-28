#include <sqlite3.h>
#include <stdio.h>
#include "../../../include/commands.h"
#include "../../../include/handler.h"
#include "../../../include/messages.h"

void processComands(sqlite3* db, int argc, char** argv, Command* commands) {
    argc = argc - 1;
    int _j = -1;
    int mostFound = 0;

    if (argc == 0) {
        helpCommand();
        return;
    }
    for (int j = 0; commands[j].arg != NULL; ++j) {
        int argsLen = commands[j].argc;
        int found = 0;
        int i = 1;
        for (int l = 0; l < argsLen; l++) {
            int isArgEqual = strcmp(argv[i], commands[j].arg[l]) == 0;
            if (isArgEqual) {
                found++;
                i++;
                if (found > mostFound) {
                    _j = j;
                    mostFound = found;
                }
                if (found == argc) {
                    // j is what matters, the other values are just injecting information
                    commands[j].func(db, argc, argv);
                    return;
                }
            }
            if (!isArgEqual) break;
        }
    }
    if (_j > -1) {
        commands[_j].func(db, argc, argv);
    }
    if (_j == -1) {
        helpCommand();
    }
}