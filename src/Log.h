#include "ANSI.h"

#define INFO    0x0
#define WARNING 0x1
#define ERROR   0x2

void Log(int lvl, char *msg, char *ref);