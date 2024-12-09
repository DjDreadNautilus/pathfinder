#include "../inc/pathfinder.h"

bool mx_validate_line(const char *line) { 
    int dash_index = mx_get_char_index(line, '-');
    int comma_index = mx_get_char_index(line, ',');

    for (int i = 0; i <= comma_index; i++) {
        if ((!mx_isalpha(line[i]) && line[i] != '-' && line[i] != ',') || mx_isdigit(line[i])) {
            return false; 
        }
    }
    
    if (dash_index == -1 || comma_index == -1 || comma_index <= dash_index || (dash_index + 1) == comma_index) {
        return false;
    }

    if (dash_index == 0 || mx_get_char_index(line + dash_index + 1, '-') != -1) {
        return false;
    }

    char *distance_str = mx_strdup(line + comma_index + 1);

    if (!distance_str) {
        return false;
    }

    for (int i = 0; distance_str[i] != '\0'; i++) {
        if (!mx_isdigit(distance_str[i])) {
            free(distance_str);

            return false;
        }
    }

    int distance = mx_atoi(distance_str);

    if (distance <= 0) {
        free(distance_str);

        return false;
    }
    
    char *before_dash = mx_strndup(line, dash_index);
    char *after_dash = mx_strndup(line + dash_index + 1, comma_index - dash_index - 1); 

    if (mx_strcmp(before_dash, after_dash) == 0) {
        free(distance_str);
        free(before_dash);
        free(after_dash);

        return false;
    }

    free(distance_str);
    free(before_dash);
    free(after_dash);

    return true;
}

