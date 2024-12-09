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


