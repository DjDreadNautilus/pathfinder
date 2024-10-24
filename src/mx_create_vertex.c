#include "../inc/pathfinder.h"

t_vertex *mx_create_vertex(const char *name) {
    t_vertex *vertex = (t_vertex *)malloc(sizeof(t_vertex));
    
    if (!vertex) {
        return NULL;
    }

    vertex->name = mx_strdup(name);
    vertex->num_connections = 0;
    vertex->connections = NULL;
    vertex->distances = NULL;

    return vertex;
}

