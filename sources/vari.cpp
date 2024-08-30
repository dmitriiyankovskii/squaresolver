#include <stdio.h>
#include <stdarg.h>

#include "vari.h"

void format_printf(enum color col, enum style sty, const char *ptr, ...) {
    int def = 0;

    va_list arg;
    va_start(arg, ptr);

    printf("\033[%d;%dm", col, sty);
    vprintf(ptr, arg);
    printf("\033[%dm", def);
    
    va_end(arg);
}