#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "ANSI.h"

void SetCursor(int x, int y);
void SaveCursor();
void RestoreCursor();