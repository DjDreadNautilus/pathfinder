#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (!head || !*head) {
        return;
    }

    t_list *current_node = *head;
    t_list *previous_node = current_node;

    while (current_node->next) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node == current_node) {
        free(current_node);
        *head = NULL;
    }
    else {
        free(current_node);
        previous_node->next = NULL;
    }
}




