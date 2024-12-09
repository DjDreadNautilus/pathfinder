#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        
        return -1;
    }

    t_graph *graph = mx_read_graph(argv[1]);

    if (graph == NULL) {
        return -1;
    }

    for (int i = 0; i < graph->V; i++) {
        for (int j = i + 1; j < graph->V; j++) {
            if (i != j) {
                t_paths shortest_paths = mx_find_shortest_paths(graph, i, j);

                for (int k = 0; k < shortest_paths.num_paths; k++) {
                    mx_print_shortest(graph, shortest_paths.paths[k], shortest_paths.path_lengths[k]);
                }

                mx_free_paths(&shortest_paths);
            }
        }
    }

    for (int i = 0; i < graph->V; i++) {
        mx_free_vertex(graph->vertices[i]);
    }

    free(graph->vertices);
    free(graph);

    return 0;
}


