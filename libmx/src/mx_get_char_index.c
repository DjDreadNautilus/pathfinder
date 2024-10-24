#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    if (!str) {
        return -2; 
    }

    char *find = mx_memchr(str, c, mx_strlen(str));

    if (find) {
        return find - str; 
    }

    return -1;
}





