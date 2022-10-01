#include "Cursor.h"

void SetCursor(int y, int x) {
    printf(UTIL_TOP);
    for (int i = 0; i < y; i++) { printf(UTIL_RIGHT); }
    for (int i = 0; i < x; i++) { printf(UTIL_DOWN); }
}

void SaveCursor() {
    printf(UTIL_SAVE);
}

void RestoreCursor() {
    printf(UTIL_RESTORE);
}