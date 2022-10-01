#include "CTerm.h"

// class UNICODE:
// 
//     TOPRIGHT    = ["╮","┓","╗","╮","-"]
//     VERTICAL    = ["│","┃","║","╎","|"]
//     BOTTOMLEFT  = ["╰","┗","╚","╰","-"]
//     TOPLEFT     = ["╭","┏","╔","╭","-"]
//     BOTTOMRIGHT = ["╯","┛","╝","╯","-"]
//     HORIZONTAL  = ["─","━","═","╌","-"]

// Topleft      U+256D
// Topright     U+256E
// Bottomrigh   U+256F
// Bottomleft   U+2570

struct UNICODE {
    char TOPRIGHT[3];
    char VERTICAL[3];
    char BOTTOMLEFT[3];
    char TOPLEFT[3];
    char BOTTOMRIGHT[3];
    char HORIZONTAL[3];
};
// struct UNICODE unicode = {
//     {"╮","┓","╗","╮"}
// };

bool CTerm_Init() {
    printf(UTIL_CLEAR UTIL_TOP);
    while (true) { Prompt(); }
    return true;
}

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
    printf(UTIL_UP UTIL_CLEARLINE "\n");

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

    char *txt = positive ? " Done! " : " Discarded! ";
    char *col = positive ? FG_GREEN : FG_RED;
    int length = w - strlen(txt);
    for (int i = 0; i < length; i++) { printf(UTIL_RIGHT); }
    printf("%s" UTIL_BOLD UTIL_REVERSE "%s" UTIL_RESET, col, txt);
}

bool Confirm(char *msg) {
    char response[1];
    printf(UTIL_BOLD "%s\t" UTIL_RESET, msg);
    scanf("%c",response);
    bool answer = (response[0] == 'Y' || response[0] == 'y') ? true : false; 
    Feedback(answer);
    return answer;
}

void test() {
    printf("\U0000231F\n");
}