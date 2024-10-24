#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if(!list) {
        return;
    }

    if(!*list) {
        *list = mx_create_node(data);

        return;
    }

    t_list *new_node = mx_create_node(data);

    if(!new_node) {
        return;
    }

    t_list *current_node = *list;

    while (current_node->next) {
        current_node = current_node->next;
    }
    
    current_node->next = new_node;
}




