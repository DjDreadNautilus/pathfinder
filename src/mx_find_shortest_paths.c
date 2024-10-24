#include "../inc/pathfinder.h"

t_paths mx_find_shortest_paths(t_graph *graph, int src, int dst) {
    t_paths shortest_paths;
    shortest_paths.paths = NULL;
    shortest_paths.path_lengths = NULL;
    shortest_paths.num_paths = 0;

    int *path = (int *)malloc(graph->V * sizeof(int));
    bool *visited = (bool *)malloc(graph->V * sizeof(bool));
    int min_distance = INT_MAX;

    if (!path || !visited) {
        free(path);
        free(visited);
        
        return shortest_paths;
    }

    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }

    dfs_find_shortest_paths(graph, src, dst, visited, path, 0, &shortest_paths, 0, &min_distance);
    free(visited);
    free(path);

    return shortest_paths;
}

