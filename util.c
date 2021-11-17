#include "util.h"

#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void initialize_terminal()
{
    struct termios terminal_interface;
    int fcntl_flags = 0;
    tcgetattr(STDIN_FILENO, &terminal_interface);
    terminal_interface.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal_interface);
    fcntl_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, fcntl_flags | O_NONBLOCK);
}

void finalize_terminal()
{
    struct termios terminal_interface;
    int fcntl_flags = 0;
    tcgetattr(STDIN_FILENO, &terminal_interface);
    terminal_interface.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal_interface);
    fcntl_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, fcntl_flags & ~O_NONBLOCK);
}

int kbhit()
{
    char ch = getchar();
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int randnum(int min, int max)
{
    return ((rand() % max) + min);
}
