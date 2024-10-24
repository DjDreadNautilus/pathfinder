#include "../inc/libmx.h"

char *mx_itoa(int number) {
    if (number == -2147483648) {
        return mx_strdup("-2147483648");
    }

	int is_negative = 0;

	if(number < 0) {
		is_negative = 1;
	}

    if (is_negative) {
        number = -number;
    }

    int len = 1;
    int temp = number;

    while (temp > 9) {
        temp /= 10;
        len++;
    }

    if (is_negative) {
        len++; 
    }

    char *res = mx_strnew(len);

    if (!res) {
        return NULL;
    }

    res[len] = '\0';

    for (int i = len - 1; i >= (is_negative ? 1 : 0); i--) {
        res[i] = (number % 10) + '0';
        number /= 10;
    }

    if (is_negative) {
        res[0] = '-';
    }

    return res;
}




