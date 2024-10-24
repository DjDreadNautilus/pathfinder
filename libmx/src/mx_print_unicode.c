#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char symbol[4] = {0};

    if (c < 0x80) {
        symbol[0] = (((c >> 0) & 0x7F) | 0x00);
        write(1, symbol, 1);
    }
    else if (c < 0x0800) {
        symbol[0] = (((c >> 6) & 0x1F) | 0xC0);
        symbol[1] = (((c >> 0) & 0x3F) | 0x80);
        write(1, symbol, 2);
    }
    else if (c < 0x010000) {
        symbol[0] = (((c >> 12) & 0x0F) | 0xE0);
        symbol[1] = (((c >> 6) & 0x3F) | 0x80);
        symbol[2] = (((c >> 0) & 0x3F) | 0x80);
        write(1, symbol, 3);
    }
    else if (c < 0x110000) {
        symbol[0] = (((c >> 18) & 0x07) | 0xF0);
        symbol[1] = (((c >> 12) & 0x3F) | 0x80);
        symbol[2] = (((c >> 6) & 0x3F) | 0x80);
        symbol[3] = (((c >> 0) & 0x3F) | 0x80);
        write(1, symbol, 4);
    }
}




