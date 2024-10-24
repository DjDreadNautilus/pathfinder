#include "../inc/pathfinder.h"

void dfs_find_shortest_paths(t_graph *graph, int src, int dst, bool *visited, int *path, int path_index, t_paths *shortest_paths, int current_distance, int *min_distance) {
    visited[src] = true;
    path[path_index] = src;
    path_index++;

    if (src == dst) {
        if (current_distance < *min_distance) {
            for (int i = 0; i < shortest_paths->num_paths; i++) {
                free(shortest_paths->paths[i]);
            }

            free(shortest_paths->paths);
            free(shortest_paths->path_lengths);

            shortest_paths->paths = malloc(sizeof(int *));
            shortest_paths->path_lengths = malloc(sizeof(int));
            shortest_paths->paths[0] = malloc(sizeof(int) * path_index);
            mx_memcpy(shortest_paths->paths[0], path, sizeof(int) * path_index);
            shortest_paths->path_lengths[0] = path_index;
            shortest_paths->num_paths = 1;
            *min_distance = current_distance;
        } 
        else if (current_distance == *min_distance) {
            int **new_paths = mx_realloc(shortest_paths->paths, sizeof(int *) * (shortest_paths->num_paths + 1));
            int *new_path_lengths = mx_realloc(shortest_paths->path_lengths, sizeof(int) * (shortest_paths->num_paths + 1));

            if (!new_paths || !new_path_lengths) {
                free(new_paths);
                free(new_path_lengths);
                visited[src] = false;

                return;
            }

            shortest_paths->paths = new_paths;
            shortest_paths->path_lengths = new_path_lengths;
            shortest_paths->paths[shortest_paths->num_paths] = malloc(sizeof(int) * path_index);
            mx_memcpy(shortest_paths->paths[shortest_paths->num_paths], path, sizeof(int) * path_index);
            shortest_paths->path_lengths[shortest_paths->num_paths] = path_index;
            shortest_paths->num_paths++;
        }
    } 
    else {
        t_vertex *current_vertex = graph->vertices[src];

        for (int i = 0; i < current_vertex->num_connections; i++) {
            int neighbor_index = -1;

            for (int j = 0; j < graph->V; j++) {
                if (graph->vertices[j] == current_vertex->connections[i]) {
                    neighbor_index = j;
                    
                    break;
                }
            }

            if (!visited[neighbor_index]) {
                int distance_to_neighbor = current_vertex->distances[i];
                dfs_find_shortest_paths(graph, neighbor_index, dst, visited, path, path_index, shortest_paths, current_distance + distance_to_neighbor, min_distance);
            }
        }
    }

    visited[src] = false; 
}


