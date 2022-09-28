#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Log.h"

void Log(int lvl, char *msg, char *ref) {
    switch (lvl) {
        case INFO:      printf(UTIL_BOLD FG_GREEN "[INFO]" UTIL_RESET "\t\t");    break;
        case WARNING:   printf(UTIL_BOLD FG_YELLOW "[WARNING]" UTIL_RESET "\t");  break;
        case ERROR:     printf(UTIL_BOLD FG_RED "[ERROR]" UTIL_RESET "\t");       break;
        default:        
            char *buffer = malloc(sizeof(char)*strlen(ref)+0xf);
            sprintf(buffer, "0x%x\n%s", lvl, ref);
            Log(ERROR, "Invalid Logtype", buffer);
            free(buffer);
            return;
    }

    printf("%s\n" UTIL_RESET, msg);
    if (ref) { printf("%s\n",ref); }
}