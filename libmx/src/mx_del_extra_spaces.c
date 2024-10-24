#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if(!str) {
        return NULL;
    }

    char* buffer = mx_strnew(mx_strlen(str));

    if (!buffer) {
        return NULL; 
    }

    bool spaced = 0;
    int j = 0;

    for(int i = 0; i < mx_strlen(str); i++) {
        if(!mx_isspace(str[i])) {
            buffer[j] = str[i];
            j++;
            spaced = 0;
        } 
        else if(!spaced) {
            buffer[j] = ' ';
            j++;
            spaced = 1;
        }
    }

    buffer[j] = '\0';
    char *res = mx_strtrim(buffer);
    free(buffer);

    return res;
}





