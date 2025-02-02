#include "../../include/messages.h"

void helpCommand() {
    printf("Usage:  pwdb COMMAND [OPTIONS] [ARG...]\n");
    printf("\n");
    printf("Easy way for you to manage your passwords\n");
    printf("\n");
    printf("Commands: \n");
    printf(" add          Create a group or insert into a group\n");
    printf(" ls           List information\n");
    printf(" cp           Copy to your clipboard\n");
    printf(" rm           Delete information\n");

    printf("\n");
    printf("Global Options:     \n");
    printf(" -g, --group         Storage space\n");
    printf(" -p, --password      Line of information inside of a group\n");
    printf("\n");
    printf("Example routine:\n");
    printf(" pwdb add -g <group-name>\n");
    printf(" pwdb add -p <group-name> <title> <password>\n");
    printf(" pwdb ls -g <group-name>\n");
    printf(" pwdb cp <group-name> <title>\n");
}

void createError() {
    printf("\n");
    printf("See \"pwdb add --help\".\n");
    printf("\n");
    printf("Usage:  pwdb add [OPTION] [ARG...]\n");
    printf("\n");
    printf("Insert something into the database\n");
}

void createHelp() {
    printf("\n");
    printf("Usage:  pwdb add [OPTION] [ARG...]\n");
    printf("\n");
    printf("Options:\n");
    printf(" -g, --group       Create a group\n");
    printf(" -p, --password    Insert into a group\n");
    printf("\n");
    printf("Example use:\n");
    printf(" pwdb add -g <group-name>\n");
    printf("\n");
    printf(" pwdb add -p <group-name> <title> <password>\n");
    printf("\n");
}

void createArgumentRequired() {
    printf("\n");
    printf("Usage:  pwdb add -g [ARG]\n");
    printf("See \"pwdb add --help\".\n");
    printf("\n");
    printf("One argument required\n");
}

void createExample() {
    printf("Usage:  pwdb add -g [ARG]\n");
    printf("\n");
    printf("Only letters, numbers, underscores and hyppens\n");
    printf("        Spaces are not allowed!!\n");
    printf("\n");
    printf("Group name examples:\n");
    printf("myGroup\n");
    printf("my_group\n");
    printf("My-Group10\n");
    printf("\n");
}

void insertArgumentRequired() {
    printf("\n");
    printf("Usage:  pwdb add -p [ARG...]\n");
    printf("See \"pwdb add --help\".\n");
    printf("\n");
    printf("Three arguments required\n");
}

void listError() {
    printf("\n");
    printf("See \"pwdb ls --help\".\n");
    printf("\n");
    printf("Usage:  pwdb ls [OPTION...] [ARG...]\n");
    printf("\n");
    printf("Lists information.\n");
}

void listHelp() {
    printf("\n");
    printf("Usage:  pwdb ls [OPTION...] [ARG...]\n");
    printf("\n");
    printf("Options:\n");
    printf("-g, --group    Show groups\n");
    printf("\n");
    printf("Example use:\n");
    printf("pwdb ls -g <group-name>\n");
    printf("pwdb ls --group <group-name>\n");
    printf("\n");
}

void clipError() {
    printf("\n");
    printf("See \"pwdb cp --help\".\n");
    printf("\n");
    printf("Usage:  pwdb cp [ARG...]\n");
    printf("\n");
    printf("Copies the information\n");
}

void clipHelp() {
    printf("\n");
    printf("Usage:  pwdb cp [ARG...]\n");
    printf("\n");
    printf("Example use:\n");
    printf("pwdb cp <group-name> <title>\n");
    printf("\n");
}

void deleteError() {
    printf("\n");
    printf("See \"pwdb rm --help\"\n");
    printf("\n");
    printf("Usage:  pwdb rm [OPTION] [ARG]\n");
    printf("\n");
    printf("Deletes information\n");
}

void deleteHelp() {
    printf("\n");
    printf("Usage:  pwdb rm [OPTION] [ARG]\n");
    printf("\n");
    printf("Example use:\n");
    printf("pwdb rm -g <group-name>\n");
    printf("pwdb rm -p <group-name> <title>\n");
    printf("\n");
}
