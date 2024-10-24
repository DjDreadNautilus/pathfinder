#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str) {
        return -1;
    }

    bool flag = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            flag = 0;
        }
        else if (!flag) {
            flag = 1;
            count++;
        }
    }

    return count;
}




