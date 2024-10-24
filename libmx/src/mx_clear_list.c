#include "../inc/libmx.h"

void mx_clear_list(t_list **list) {
    if (*list == NULL){
        return;
    }

    t_list *current = *list;
    t_list *free_node;

    while (current != NULL){
        free_node = current;
        current = current->next;
        free(free_node);
    }

    *list = NULL;
}





