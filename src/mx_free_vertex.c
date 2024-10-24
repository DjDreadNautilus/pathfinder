#include "../inc/pathfinder.h"

void mx_free_vertex(t_vertex *vertex) {
    if (vertex) {
        free(vertex->name);  
        free(vertex->connections); 
        free(vertex->distances);   
        free(vertex);               
    }
}

