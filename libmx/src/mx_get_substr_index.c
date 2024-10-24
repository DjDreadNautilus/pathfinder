#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if(!str || !sub) {
        return -2;
    }

    if(mx_strstr(str, sub)) {
        return mx_strstr(str, sub) - str;
    }

    return -1;
}





