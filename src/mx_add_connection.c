#include "../inc/pathfinder.h"

void mx_add_connection(t_vertex *vertex1, t_vertex *vertex2, int distance) {
    if (!vertex1 || !vertex2) {
        return;
    }

    vertex1->num_connections++;
    t_vertex **new_connections1 = mx_realloc(vertex1->connections, vertex1->num_connections * sizeof(t_vertex *));
    int *new_distances1 = mx_realloc(vertex1->distances, vertex1->num_connections * sizeof(int));

    if (!new_connections1 || !new_distances1) {
        free(new_connections1);
        free(new_distances1);
        vertex1->num_connections--;
        
        return;
    }

    vertex1->connections = new_connections1;
    vertex1->distances = new_distances1;
    vertex1->connections[vertex1->num_connections - 1] = vertex2;
    vertex1->distances[vertex1->num_connections - 1] = distance;
    vertex2->num_connections++;
    t_vertex **new_connections2 = mx_realloc(vertex2->connections, vertex2->num_connections * sizeof(t_vertex *));
    int *new_distances2 = mx_realloc(vertex2->distances, vertex2->num_connections * sizeof(int));

    if (!new_connections2 || !new_distances2) {
        free(new_connections2);
        free(new_distances2);
        vertex2->num_connections--;

        return;
    }

    vertex2->connections = new_connections2;
    vertex2->distances = new_distances2;
    vertex2->connections[vertex2->num_connections - 1] = vertex1;
    vertex2->distances[vertex2->num_connections - 1] = distance;
}


