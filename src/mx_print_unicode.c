#include "libmx.h"

void mx_print_unicode(wchar_t c)
{
    char str[4];
    int bytes = 0;

    if (c <= 0x7F) {
        str[0] = c;
        bytes = 1;
    } else if (c <= 0x7FF) {
        str[0] = (c >> 6) | 0xC0;
        str[1] = (c & 0x3F) | 0x80;
        bytes = 2;
    } else if (c <= 0xFFFF) {
        str[0] = (c >> 12) | 0xE0;
        str[1] = ((c >> 6) & 0x3F) | 0x80;
        str[2] = (c & 0x3F) | 0x80;
        bytes = 3;
    } else if (c <= 0x10FFFF) {
        str[0] = (c >> 18) | 0xF0;
        str[1] = ((c >> 12) & 0x3F) | 0x80;
        str[2] = ((c >> 6) & 0x3F) | 0x80;
        str[3] = (c & 0x3F) | 0x80;
        bytes = 4;
    } else {
        return;
    }

    write(1, str, bytes);
}
