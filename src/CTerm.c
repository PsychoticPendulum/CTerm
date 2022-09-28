#include "CTerm.h"

void GetTerminalSize(short unsigned int *width, short unsigned int *height) {
	struct winsize s;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &s);
	*width  = s.ws_col;
    *height = s.ws_row;
}

void Bar(char *left, char *right, char *color) {
    short unsigned int w,h;
    GetTerminalSize(&w, &h);
    SetCursor(0,h);

    printf("%s" FG_BLACK, color == NULL ? BG_GREEN : color);
    int length = w - (strlen(left) + strlen(right) + 0x4);
    printf("  %s", left);
    for (int i = 0; i < length; i++) { printf(" "); }
    printf("%s  ", right);

    printf(UTIL_RESET UTIL_TOP);
}

void Feedback(bool positive) {
    short unsigned int w,h;
    GetTerminalSize(&w,&h);
    printf(UTIL_UP);

    char *txt = " Done! ";
    int length = w - strlen(txt);
    for (int i = 0; i < length; i++) { printf(UTIL_RIGHT); }
    printf(FG_GREEN UTIL_REVERSE "%s" UTIL_RESET, txt);
}

bool Confirm(char *msg) {
    char response[1];
    printf(UTIL_BOLD "%s\t" UTIL_RESET, msg);
    scanf("%c",response);
    bool answer = (response[0] == 'Y' || response[0] == 'y') ? true : false; 
    Feedback(answer);
    return answer;
}