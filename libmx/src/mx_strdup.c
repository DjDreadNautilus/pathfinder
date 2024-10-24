#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    if (!s1) {
        return NULL;
    }

    char *dup = mx_strnew(mx_strlen(s1));
    
    if (!dup) {
        return NULL;
    }

    mx_strcpy(dup, s1);

    return dup;
}




