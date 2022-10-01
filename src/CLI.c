#include "CLI.h"

char *Version(char *version) {
    sprintf(version, "v%s.%s.%s",MAJOR,MINOR,PATCH);
    return version;
}

char cmd[0x20] = { 0 };
void Prompt() {
    char *ver = malloc(sizeof(char)*0xf);
    Version(ver);
    SaveCursor();
    Bar(cmd,ver,NULL);
    free(ver);
    RestoreCursor();
    
    printf(UTIL_BOLD ">> " UTIL_RESET);
    fgets(cmd,0x20,stdin);
    printf("Command: " UTIL_REVERSE "%s" UTIL_RESET UTIL_UP, cmd);
}