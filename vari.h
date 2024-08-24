#ifndef VARI_H
#define VARI_H

enum color {
    BLACK         = 30,
    RED           = 31,
    GREEN         = 32,
    YELLOW        = 33,
    BLUE          = 34,
    MAGENTA       = 35,
    CYAN          = 36,
    LIGHT_GRAY    = 37,
    DARK_GRAY     = 90,
    LIGHT_RED     = 91,
    LIGHT_GREEN   = 92,
    LIGHT_YELLOW  = 93,
    LIGHT_BLUE    = 94,
    LIGHT_MAGENTA = 95
};

enum style {
    FAT           = 1,
    ITALICS       = 3,
    SLOW_FLASHING = 5,
    FAST_FLASHING = 6,
    NEGATIVE      = 7
};

void format_printf(enum color col, enum style sty, const char *ptr, ...);

#endif