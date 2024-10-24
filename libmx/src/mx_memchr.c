#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char* str = (const unsigned char*) s;

    for(size_t i = 0; i < n; i++) {
        if(str[i] == (unsigned char) c) {
            return (void*)(str + i);
        }
    }

    return NULL;
}




