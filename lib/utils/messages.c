#include "../../include/messages.h"

void helpCommand() {
    printf("Usage:  pwdb COMMAND [OPTIONS] [ARG...]\n");
    printf("\n");
    printf("Easy way for you to manage your passwords\n");
    printf("\n");
    printf("Common Commands: \n");
    printf("create       Insert information into the database\n");
    printf("delete       Remove information into the database\n");
    printf("\n");
    printf("Global Options:     \n");
    printf("-g, --group         Storage space\n");
    printf("-p, --password      Line of information inside of a group\n");
    printf("\n");
}

void createError() {
    printf("\"pwdb create\" requires at least 1 argument and 1 option. \n");
    printf("See \"pwdb create --help\".\n");
    printf("\n");
    printf("Usage:  pwdb create [OPTION] [ARG]\n");
    printf("\n");
    printf("Create a group in the database allowing you to insert data in them.\n");
}

void createHelp() {
    printf("\n");
    printf("Usage:  pwdb create [OPTION] [ARG]\n");
    printf("\n");
    printf("Options:\n");
    printf("-g, --group    Create a group\n");
    printf("-p, --password    Insert a password into a group\n");
    printf("\n");
    printf("Example use:\n");
    printf("pwdb create -g <group-name>\n");
    printf("pwdb create --group <group-name>\n");
    printf("\n");
}

void createArgumentRequired() {
    printf("\n");
    printf("Usage:  pwdb create [OPTION] [ARG]\n");
    printf("See \"pwdb create --help\".\n");
    printf("\n");
    printf("One argument required\n");
}

void createExample() {
    printf("Usage:  pwdb create [OPTION] [ARG]\n");
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
    printf("Usage:  pwdb insert [OPTION] [ARG...]\n");
    printf("See \"pwdb insert --help\".\n");
    printf("\n");
    printf("Three arguments required\n");
}

void insertError() {
    printf("\"pwdb insert\" requires at least 2 arguments and 1 option. \n");
    printf("See \"pwdb insert --help\".\n");
    printf("\n");
    printf("Usage:  pwdb insert [OPTION] [ARG...]\n");
    printf("\n");
    printf("Insert information into a group\n");
}

void insertHelp() {
    printf("\n");
    printf("Usage:  pwdb insert [OPTION] [ARG...]\n");
    printf("\n");
    printf("Options:\n");
    printf("-g, --group    Create a group\n");
    printf("\n");
    printf("Example use:\n");
    printf("pwdb insert -g <group-name> <password>\n");
    printf("pwdb insert --group <group-name> <password>\n");
    printf("\n");
}

void listError() {
    printf("\"pwdb list\" requires at least 1 option. \n");
    printf("See \"pwdb list --help\".\n");
    printf("\n");
    printf("Usage:  pwdb list [OPTION]\n");
    printf("\n");
    printf("Lists information.\n");
}

void listHelp() {
    printf("\n");
    printf("Usage:  pwdb list [OPTION]\n");
    printf("\n");
    printf("Options:\n");
    printf("-g, --group    Show groups\n");
    printf("--all          Show groups and information\n");
    printf("\n");
    printf("Example use:\n");
    printf("pwdb list -g <group-name>\n");
    printf("pwdb list --group <group-name>\n");
    printf("pwdb list --all <group-name>\n");
    printf("\n");
}
