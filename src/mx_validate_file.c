#include "../inc/pathfinder.h"

bool mx_validate_file(char **strarr, const char *filename, char *file_content) {
    if (!strarr || !filename) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");

        return false;
    }

    if (mx_strlen(strarr[0]) == 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");

        return false;
    }

    for (int i = 0; strarr[0][i] != '\0'; i++) {
        if (!mx_isdigit(strarr[0][i])) {
            mx_printerr("error: line 1 is not valid\n");
            return false;
        }
    }

    long long total_sum = 0;
    int i = 1;
    int file_pos = 0;

    for (int i = 0; strarr[i]; i++) {
        int line_len = mx_strlen(strarr[i]);

        if (file_content[file_pos + line_len] == '\n' && file_content[file_pos + line_len + 1] == '\n') {
            char *str = mx_itoa(i + 2);
            mx_printerr("error: line ");
            mx_printerr(str);

            if (str) {
                free(str); 
            }

            mx_printerr(" is not valid\n");

            return false;
        }

        file_pos += line_len + 1; 
    }

    while (strarr[i]) {
        if (!mx_validate_line(strarr[i])) {
            char* str = mx_itoa(i + 1);
            mx_printerr("error: line ");
            mx_printerr(str);

            if(str) {
                free(str); 
            }

            mx_printerr(" is not valid\n");

            return false;
        }

        int comma_index = mx_get_char_index(strarr[i], ',');

        if (!(mx_isdigit(*(strarr[i] + comma_index + 1)))) {
            char* str = mx_itoa(i + 1);
            mx_printerr("error: line ");
            mx_printerr(str);

            if(str) {
                free(str); 
            }

            mx_printerr(" is not valid\n");
            return false;
        }

        total_sum += mx_atoi(strarr[i] + comma_index + 1);
        i++;
    }

    int vertex_count = mx_count_real_amount(strarr);
    int expected_vertex_count = mx_atoi(strarr[0]);

    if (vertex_count != expected_vertex_count) {
        mx_printerr("error: invalid number of islands\n");

        return false;
    }

    if (!mx_validate_dublicates(strarr)) {
        mx_printerr("error: duplicate bridges\n");

        return false;
    }

    if (total_sum > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");

        return false;
    }

    return true;
}

