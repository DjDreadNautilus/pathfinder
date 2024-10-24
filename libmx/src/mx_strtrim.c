#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) {
        return NULL;
    }   

    while (mx_isspace(*str)) {
    	str++;
    }

    int len = mx_strlen(str);

    if(len == 0) {
        return mx_strnew(0);
    }

    while (len > 0 && mx_isspace(str[len - 1])) {
        len--;
    }

    return mx_strndup(str, len);

}





