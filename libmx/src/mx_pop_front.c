#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    if(!*head) {    
        return;
    }

	t_list *current = (*head)->next;
	free(*head);
	*head = current;
}




