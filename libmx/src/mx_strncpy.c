#include "../inc/libmx.h" 

char *mx_strncpy(char *dst, const char *src, int len) {
    char* temp = dst;

    while (*src != '\0' && len > 0) {
        *dst = *src; 
        dst++;
        src++;
        len--;
    }

    while (len > 0) {
        *dst = '\0';
        dst++;
        len--;
    }

    return temp;
}





