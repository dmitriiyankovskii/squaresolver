#ifndef VARI_H
#define VARI_H

enum color {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLO = 33,
    BLUE = 34                               
};

enum style {
    FAT = 1,
    ITALICS = 3,
    SLOW_FLASHING = 5,
    FAST_FLASHING = 6
};

void format_printf(enum color col, enum style sty, const char *ptr, ...);

#endif