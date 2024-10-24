#include "../inc/pathfinder.h"

bool mx_validate_dublicates(char **strarr) {
    if (!strarr) {
        return false;
    }

    int i = 1;
    
    while (strarr[i]) {
        int dash_index_i = mx_get_char_index(strarr[i], '-');
        int comma_index_i = mx_get_char_index(strarr[i], ',');

        if (dash_index_i == -1 || comma_index_i == -1) {
            return false;
        }

        char *island1_i = mx_strndup(strarr[i], dash_index_i);
        char *island2_i = mx_strndup(strarr[i] + dash_index_i + 1, comma_index_i - dash_index_i - 1);

        if (!island1_i || !island2_i) {
            free(island1_i);
            free(island2_i);

            return false;
        }

        for (int j = i + 1; strarr[j]; j++) {
            int dash_index_j = mx_get_char_index(strarr[j], '-');
            int comma_index_j = mx_get_char_index(strarr[j], ',');

            if (dash_index_j == -1 || comma_index_j == -1) {
                free(island1_i);
                free(island2_i);

                return false;
            }

            char *island1_j = mx_strndup(strarr[j], dash_index_j);
            char *island2_j = mx_strndup(strarr[j] + dash_index_j + 1, comma_index_j - dash_index_j - 1);

            if (!island1_j || !island2_j) {
                free(island1_i);
                free(island2_i);
                free(island1_j);
                free(island2_j);

                return false;
            }

            if ((mx_strcmp(island1_i, island1_j) == 0 && mx_strcmp(island2_i, island2_j) == 0) ||
                (mx_strcmp(island1_i, island2_j) == 0 && mx_strcmp(island2_i, island1_j) == 0)) {
                free(island1_i);
                free(island2_i);
                free(island1_j);
                free(island2_j);

                return false;
            }

            free(island1_j);
            free(island2_j);
        }

        free(island1_i);
        free(island2_i);
        i++;
    }

    return true;
}

bool is_vertex_in_list(t_list *list, char *vertex) {
    if (!list || !vertex) {
        return false;
    }

    t_list *current = list;

    while (current != NULL) {
        if (mx_strcmp((char *)current->data, vertex) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

int mx_count_real_amount(char **strarr) {
    if (!strarr) {
        return 0;
    }

    int i = 1;
    t_list *unique_vertex = NULL;

    while (strarr[i]) {
        int dash_index = mx_get_char_index(strarr[i], '-');
        int comma_index = mx_get_char_index(strarr[i], ',');

        if (dash_index == -1 || comma_index == -1) {
            i++;
            continue;
        }

        char *vertex1 = mx_strndup(strarr[i], dash_index);
        char *vertex2 = mx_strndup(strarr[i] + dash_index + 1, comma_index - dash_index - 1);

        if (vertex1 && !is_vertex_in_list(unique_vertex, vertex1)) {
            mx_push_front(&unique_vertex, vertex1);
        } 
        else {
            free(vertex1);
        }

        if (vertex2 && !is_vertex_in_list(unique_vertex, vertex2)) {
            mx_push_front(&unique_vertex, vertex2);
        } 
        else {
            free(vertex2);
        }

        i++;
    }

    int count = 0;
    t_list *current = unique_vertex;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    while (unique_vertex != NULL) {
        t_list *temp = unique_vertex;
        unique_vertex = unique_vertex->next;
        free(temp->data);
        free(temp);
    }

    return count;
}

bool mx_validate_line(const char *line) { 
    int dash_index = mx_get_char_index(line, '-');
    int comma_index = mx_get_char_index(line, ',');

    for (int i = 0; i <= comma_index; i++) {
        if ((!mx_isalpha(line[i]) && line[i] != '-' && line[i] != ',') || mx_isdigit(line[i])) {
            return false; 
        }
    }
    
    if (dash_index == -1 || comma_index == -1 || comma_index <= dash_index) {
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
            char* str = mx_itoa(i);
            mx_printerr("error: line ");
            mx_printerr(str);

            if(str) {
                free(str); 
            }

            mx_printerr(" is not valid\n");

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

