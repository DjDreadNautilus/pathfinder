#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (!s1 && !s2) {
        return NULL;
    }

    if (!s1) {
        return mx_strdup(s2);
    }

    if (!s2) {
        return mx_strdup(s1);
    }
    
    char *join = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    
    if (!join) {
        return NULL;
    }
    
    mx_strcpy(join, s1);
    mx_strcat(join, s2);
    
    return join;
}





