#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int size = 0;

    t_list *current_node = list;

    while (current_node) {
        current_node = current_node->next;
        size++;
    }

    return size;
}



