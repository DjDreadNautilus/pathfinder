#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char* str = (const unsigned char*) s;

    for(size_t i = n; i > 0; i--) {
        if(str[i - 1] == (unsigned char) c) {
            return (void*)(str + i - 1);
        }
    }

    return NULL;
}




