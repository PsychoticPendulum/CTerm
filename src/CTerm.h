#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include <unistd.h>
#include <sys/ioctl.h>

#include "Log.h"
#include "Cursor.h"

#define AUTHOR  "PsychicPenguin"
#define MAJOR   0
#define MINOR   1
#define PATCH   0

void test();

void GetTerminalSize(short unsigned int *width, short unsigned int *height);
void Bar(char *left, char *right, char *color);
bool Confirm(char *msg);