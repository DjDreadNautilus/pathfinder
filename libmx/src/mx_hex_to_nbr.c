#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (!hex) {
        return 0;
    }

    unsigned long nbr = 0;
    int len = mx_strlen(hex) - 1;
    int i = 0;
    int val = 0;

    while (hex[i] != '\0') { 
        if (hex[i] >= '0' && hex[i] <= '9') { 
            val = hex[i] - '0'; 
        } 
        else if (hex[i] >= 'a' && hex[i] <= 'f') { 
            val = hex[i] - 'a' + 10; 
        } 
        else if (hex[i] >= 'A' && hex[i] <= 'F') { 
            val = hex[i] - 'A' + 10; 
        } 
        else {
            return 0;
        }

        nbr += val * mx_pow(16, len); 
        len--;
        i++; 
    } 

    return nbr;
}





