#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!haystack && !mx_strlen(needle)) {
        return NULL;
    }

    if (mx_strlen(needle) == 0) {
        return (char*)haystack;
    }

    while (*haystack) {
        if (mx_strlen(haystack) >= mx_strlen(needle) && mx_memcmp(haystack, needle, mx_strlen(needle)) == 0) {
            return (char*)haystack;
        }
        
        haystack++;
    }

    return NULL;
}





