#include "../inc/libmx.h"

char *mx_strndup(const char *s1, int n) {
    if (!s1 || n < 0) {
    
        return NULL;
    }

    char *dup = NULL;
    int len = mx_strlen(s1);

    if (n < len) {
        len = n;        
    }

    dup = mx_strnew(len);
    
    if (!dup) {
        return NULL; 
    }

    mx_strncpy(dup, s1, len);
    
    return dup;
}





