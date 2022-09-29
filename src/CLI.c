#include "CLI.h"

char *Version(char *version) {
    sprintf(version, "v%s.%s.%s",MAJOR,MINOR,PATCH);
    return version;
}

char cmd[0x20] = { 0 };
void Prompt() {
    char *ver = malloc(sizeof(char)*0xf);
    Version(ver);
    Bar(cmd,ver,NULL);
    free(ver);
    
    printf(UTIL_BOLD ">> " UTIL_RESET);
    scanf("%31[^\n]", cmd);

}