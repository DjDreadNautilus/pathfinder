#include "../inc/pathfinder.h"

int mx_atoi(const char *str) {
    int i = 0;
    int sign = 1;
    int number = 0;

    while (mx_isspace(str[i])) {
        i++;
    }

    if (str[i] == '-') {
        sign = -1;
        i++;
    } 
    else if (str[i] == '+') {
        i++;
    }

    while (str[i] != '\0' && mx_isdigit(str[i])) {
        number = number * 10 + (str[i] - '0');
        i++;
    }

    return number * sign;
}

