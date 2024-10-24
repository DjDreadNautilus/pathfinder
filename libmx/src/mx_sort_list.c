#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (!lst || !cmp) {
        return NULL;
    }

    t_list *start = lst;
    t_list *end = NULL;

    while (end != start->next) {
        t_list *current = start;
        t_list *previous = NULL;

        while (current->next != end) {
            t_list *next = current->next;

            if (cmp(current->data, next->data)) {
                current->next = next->next;
                next->next = current;

                if (previous) {
                    previous->next = next;
                } else {
                    start = next;  
                }

                previous = next;

            } else {
                previous = current;
                current = next;
            }
        }
        end = current;
    }

    return start;
}





