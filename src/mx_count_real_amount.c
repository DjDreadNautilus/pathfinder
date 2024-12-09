#include "../inc/pathfinder.h"

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


