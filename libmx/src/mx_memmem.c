#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const unsigned char* haystack = (const unsigned char*)big;
    const unsigned char* needle = (const unsigned char*)little;

    if (little_len == 0) {
        return (void *)haystack;
    }

    if (big_len < little_len) {
        return NULL;
    }

    if (big_len == 0 && little_len != 0) {
        return NULL;
    }

    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (mx_memcmp(haystack + i, needle, little_len) == 0) {
            return (void *)(haystack + i);
        }
    }
    
    return NULL;
}




