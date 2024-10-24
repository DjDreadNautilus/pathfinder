#include "../inc/pathfinder.h"

void mx_print_shortest(t_graph *graph, int *path, int length) {
    mx_printstr("========================================");
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(graph->vertices[path[0]]->name);
    mx_printstr(" -> ");
    mx_printstr(graph->vertices[path[length - 1]]->name);
    mx_printstr("\n");
    mx_printstr("Route: ");

    for (int i = 0; i < length; i++) {
        mx_printstr(graph->vertices[path[i]]->name);

        if (i < length - 1) {
            mx_printstr(" -> ");
        }
    }

    mx_printstr("\n");
    mx_printstr("Distance: ");

    for (int i = 0; i < length - 1; i++) {
        int current_vertex_index = path[i];
        int next_vertex_index = path[i + 1];
        
        for (int j = 0; j < graph->vertices[current_vertex_index]->num_connections; j++) {
            if (graph->vertices[current_vertex_index]->connections[j] == graph->vertices[next_vertex_index]) {
                mx_printint(graph->vertices[current_vertex_index]->distances[j]);

                if (i < length - 2) {
                    mx_printstr(" + ");
                }

                break;
            }
        }
    }
    
    int total_distance = mx_find_distance(graph, path, length);

    if(length > 2) {
        mx_printstr(" = ");
        mx_printint(total_distance);
    }
    
    mx_printstr("\n");
    mx_printstr("========================================");
    mx_printstr("\n");
}


