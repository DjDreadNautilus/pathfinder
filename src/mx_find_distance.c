#include "../inc/pathfinder.h"

int mx_find_distance(t_graph *graph, int *path, int path_length) {
    int total_distance = 0;

    for (int i = 0; i < path_length - 1; i++) {
        int current_vertex_index = path[i];
        int next_vertex_index = path[i + 1];
        bool found_distance = false;

        for (int j = 0; j < graph->vertices[current_vertex_index]->num_connections; j++) {
            if (graph->vertices[current_vertex_index]->connections[j] == graph->vertices[next_vertex_index]) {
                total_distance += graph->vertices[current_vertex_index]->distances[j];
                found_distance = true;

                break;
            }
        }

        if (!found_distance) {
            return -1;
        }
    }

    return total_distance; 
}

