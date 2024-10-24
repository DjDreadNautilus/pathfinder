#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub) {      
        return NULL; 
    }

    int count = mx_count_substr(str, sub);
    char *redacted = mx_strnew((count * (mx_strlen(str) - mx_strlen(sub) + mx_strlen(replace))) + 1);

    if (!redacted) {
        return NULL;
    }

    const char* current = str;
    char* temp = redacted;

    while(count > 0) {
        const char* pos = mx_strstr(current, sub);

        if (!pos) {
            break; 
        }

        mx_memcpy(temp, current, pos - current);

        temp += pos - current;

        mx_memcpy(temp, replace, mx_strlen(replace));

        temp += mx_strlen(replace);
        current = pos + mx_strlen(sub);;
        count--;

    }

    mx_strcpy(temp, current);

    return redacted;
}




