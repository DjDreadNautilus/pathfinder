#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if(nbr == 0) {    
        char *hex = mx_strnew(1);
        hex[0] = '0';

        return hex;
    }

    int len = 0;
    unsigned long temp = nbr;

    while(temp > 0) {
        temp /= 16;
        len++;
    }

    char *hex = mx_strnew(len +1);
    hex[len] = '\0';
    char *hex_digits = "0123456789abcdef";

    while(nbr > 0) {
        len--;
        hex[len] = hex_digits[nbr % 16];
        nbr /= 16;
    }

    return hex;
}




