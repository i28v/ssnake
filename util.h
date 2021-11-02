#ifndef UTIL_H
#define UTIL_H

#include "config.h"

#define CLEAR_SCREEN() printf("\033[2J")

#define RESET_CURSOR_POSITION() printf("\033[0;0H")

#define LOG(msg) \
{ \
    if(debug) \
    { \
        printf(msg); \
    } \
}

#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

void initialize_terminal();
void finalize_terminal();
int kbhit();
int randnum(int min, int max);

#endif /* UTIL_H */
