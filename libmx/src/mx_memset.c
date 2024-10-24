#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *str = b; 
    size_t i = 0;

    while(i < len) {
        *str = (unsigned char) c;
        str++;
        i++;
    }

    return b;
}




